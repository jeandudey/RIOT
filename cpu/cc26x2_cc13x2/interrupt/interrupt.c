/*
 * Copyright (C) 2015 - 2017, Texas Instruments Incorporated
 * Copyright (C) 2020 Locha Inc
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup         cpu_cc26x2_cc13x2_interrupt
 * @{
 *
 * @file
 * @brief           CC26x2/CC13x2 Interrupt interface.
 *
 * @author          Jean Pierre Dudey <jeandudey@hotmail.com>
 */

#include "cpu_conf.h"

#include <stddef.h>
#include <assert.h>

static const uint32_t _priority[] =
{
    NVIC_APINT_PRIGROUP_0_8, NVIC_APINT_PRIGROUP_1_7, NVIC_APINT_PRIGROUP_2_6,
    NVIC_APINT_PRIGROUP_3_5, NVIC_APINT_PRIGROUP_4_4, NVIC_APINT_PRIGROUP_5_3,
    NVIC_APINT_PRIGROUP_6_2, NVIC_APINT_PRIGROUP_7_1
};

#define NVIC_REG_ADDR(reg) \
    (reg32_t*)((uint32_t)offsetof(cc26xx_cc13xx_nvic_t, reg) + \
               (uint32_t)CC26XX_CC13XX_NVIC_BASE)

static reg32_t* _regs[] =
{
    NULL, NVIC_REG_ADDR(SYS_PRI1), NVIC_REG_ADDR(SYS_PRI2),
    NVIC_REG_ADDR(SYS_PRI3), NVIC_REG_ADDR(PRI0), NVIC_REG_ADDR(PRI1),
    NVIC_REG_ADDR(PRI2), NVIC_REG_ADDR(PRI3), NVIC_REG_ADDR(PRI4),
    NVIC_REG_ADDR(PRI5), NVIC_REG_ADDR(PRI6), NVIC_REG_ADDR(PRI7),
    NVIC_REG_ADDR(PRI8), NVIC_REG_ADDR(PRI9), NVIC_REG_ADDR(PRI10),
    NVIC_REG_ADDR(PRI11), NVIC_REG_ADDR(PRI12), NVIC_REG_ADDR(PRI13)
};

static __attribute__((section("vtable_ram")))
interrupt_handler_t _vectors[NUM_INTERRUPTS] __attribute__((aligned(256)));

static void interrupt_default_handler(void)
{
    /* Go into an infinite loop. */
    while(1)
    {
    }
}

static interrupt_handler_t read_vector_table_entry(uint32_t address)
{
    /* Cast address to a pointer and dereference that pointer and cast the
     * value to get the address to the handler
     */
    return (interrupt_handler_t)(*(uint32_t*)address);
}

void interrupt_register(uint32_t interrupt, interrupt_handler_t handler)
{
    uint32_t i = 0;
    uint32_t original_vtable = 0;

    assert(interrupt < NUM_INTERRUPTS);

    /* Make sure that the RAM vector table is correctly aligned. */
    assert(((uint32_t)_vectors & 0x000000ff) == 0);

    /* See if the RAM vector table has been initialized. */
    if(CC26XX_CC13XX_NVIC->VTABLE != (reg32_t)_vectors)
    {
        /*
         * Copy the vector table from the beginning of FLASH to the RAM vector
         * table.
         */
        original_vtable = CC26XX_CC13XX_NVIC->VTABLE;
        for(i = 0; i < NUM_INTERRUPTS; i++)
        {
            _vectors[i] = read_vector_table_entry(original_vtable + (i * 4));
        }

        /* Point NVIC at the RAM vector table. */
        CC26XX_CC13XX_NVIC->VTABLE = (reg32_t)_vectors;
    }

    /* Save the interrupt handler. */
    _vectors[interrupt] = handler;
}

void interrupt_unregister(uint32_t interrupt)
{
    assert(interrupt < NUM_INTERRUPTS);

    /* Reset the interrupt handler. */
    _vectors[interrupt] = interrupt_default_handler;
}

void interrupt_set_priority_grouping(uint32_t bits)
{
    assert(bits < NUM_PRIORITY);

    /* Set the priority grouping. */
    CC26XX_CC13XX_NVIC->APINT = NVIC_APINT_VECTKEY | _priority[bits];
}

uint32_t interrupt_get_priority_grouping(void)
{
    int_fast32_t i = 0;
    uint32_t value = 0;

    /* Read the priority grouping. */
    value = CC26XX_CC13XX_NVIC->APINT & NVIC_APINT_PRIGROUP_M;

    /* Loop through the priority grouping values. */
    for(i = 0; i < NUM_PRIORITY; i++)
    {
        if(value == _priority[i]) {
            break;
        }
    }

    /* Return the number of priority bits. */
    return i;
}

void interrupt_set_priority(uint32_t interrupt, uint8_t priority)
{
    reg32_t temp = 0;

    assert((interrupt >= 4) && (interrupt < NUM_INTERRUPTS));
    assert(priority <= INT_PRI_LEVEL7);

    /* Set the interrupt priority. */
    temp = *(_regs[interrupt >> 2]);
    temp &= ~(0xFF << (8 * (interrupt & 3)));
    temp |= priority << (8 * (interrupt & 3));
    *(_regs[interrupt >> 2]) = temp;
}

int32_t interrupt_get_priority(uint32_t interrupt)
{
    assert((interrupt >= 4) && (interrupt < NUM_INTERRUPTS));

    /* Return the interrupt priority. */
    return ((*(_regs[interrupt >> 2]) >> (8 * (interrupt & 3))) & 0xFF);
}

void interrupt_enable(uint32_t interrupt)
{
    assert(interrupt < NUM_INTERRUPTS);

    /* Determine the interrupt to enable. */
    if(interrupt == INT_MEMMANAGE_FAULT)
    {
        /* Enable the MemManage interrupt. */
        CC26XX_CC13XX_NVIC->SYS_HND_CTRL |= NVIC_SYS_HND_CTRL_MEM;
    }
    else if(interrupt == INT_BUS_FAULT)
    {
        /* Enable the bus fault interrupt. */
        CC26XX_CC13XX_NVIC->SYS_HND_CTRL |= NVIC_SYS_HND_CTRL_BUS;
    }
    else if(interrupt == INT_USAGE_FAULT)
    {
        /* Enable the usage fault interrupt. */
        CC26XX_CC13XX_NVIC->SYS_HND_CTRL |= NVIC_SYS_HND_CTRL_USAGE;
    }
    else if(interrupt == INT_SYSTICK)
    {
        /* Enable the System Tick interrupt. */
        CC26XX_CC13XX_NVIC->ST_CTRL |= NVIC_ST_CTRL_INTEN;
    }
    else if((interrupt >= 16) && (interrupt <= 47))
    {
        /* Enable the general interrupt. */
        CC26XX_CC13XX_NVIC->EN0 = 1 << (interrupt - 16);
    }
    else if(interrupt >= 48)
    {
        /* Enable the general interrupt. */
        CC26XX_CC13XX_NVIC->EN1 = 1 << (interrupt - 48);
    }
}

void interrupt_disable(uint32_t interrupt)
{
    assert(interrupt < NUM_INTERRUPTS);

    /* Determine the interrupt to disable. */
    if(interrupt == INT_MEMMANAGE_FAULT)
    {
        /* Disable the MemManage interrupt. */
        CC26XX_CC13XX_NVIC->SYS_HND_CTRL &= ~(NVIC_SYS_HND_CTRL_MEM);
    }
    else if(interrupt == INT_BUS_FAULT)
    {
        /* Disable the bus fault interrupt. */
        CC26XX_CC13XX_NVIC->SYS_HND_CTRL &= ~(NVIC_SYS_HND_CTRL_BUS);
    }
    else if(interrupt == INT_USAGE_FAULT)
    {
        /* Disable the usage fault interrupt. */
        CC26XX_CC13XX_NVIC->SYS_HND_CTRL &= ~(NVIC_SYS_HND_CTRL_USAGE);
    }
    else if(interrupt == INT_SYSTICK)
    {
        /* Disable the System Tick interrupt. */
        CC26XX_CC13XX_NVIC->ST_CTRL &= ~(NVIC_ST_CTRL_INTEN);
    }
    else if((interrupt >= 16) && (interrupt <= 47))
    {
        /* Disable the general interrupt. */
        CC26XX_CC13XX_NVIC->DIS0 = 1 << (interrupt - 16);
    }
    else if(interrupt >= 48)
    {
        /* Disable the general interrupt. */
        CC26XX_CC13XX_NVIC->DIS1 = 1 << (interrupt - 48);
    }
}

void interrupt_set_pend(uint32_t interrupt)
{
    assert(interrupt < NUM_INTERRUPTS);

    /* Determine the interrupt to pend. */
    if(interrupt == INT_NMI_FAULT)
    {
        /* Pend the NMI interrupt. */
        CC26XX_CC13XX_NVIC->INT_CTRL |= NVIC_INT_CTRL_NMI_SET;
    }
    else if(interrupt == INT_PENDSV)
    {
        /* Pend the PendSV interrupt. */
        CC26XX_CC13XX_NVIC->INT_CTRL |= NVIC_INT_CTRL_PEND_SV;
    }
    else if(interrupt == INT_SYSTICK)
    {
        /* Pend the SysTick interrupt. */
        CC26XX_CC13XX_NVIC->INT_CTRL |= NVIC_INT_CTRL_PENDSTSET;
    }
    else if((interrupt >= 16) && (interrupt <= 47))
    {
        /* Pend the general interrupt. */
        CC26XX_CC13XX_NVIC->PEND0 = 1 << (interrupt - 16);
    }
    else if(interrupt >= 48)
    {
        /* Pend the general interrupt. */
        CC26XX_CC13XX_NVIC->PEND1 = 1 << (interrupt - 48);
    }
}

int_fast32_t interrupt_get_pend(uint32_t interrupt)
{
    uint32_t interrupt_pending;

    assert(interrupt < NUM_INTERRUPTS);

    /* Assume no interrupts are pending. */
    interrupt_pending = 0;

    /* The lower 16 IRQ vectors are unsupported by this function */
    if (interrupt < 16)
    {
       return 0;
    }

    /* Subtract lower 16 irq vectors */
    interrupt -= 16;

    /* Check if the interrupt is pending */
    interrupt_pending = CC26XX_CC13XX_NVIC->PEND0 + (interrupt / 32);
    interrupt_pending &= (1 << (interrupt & 31));

    return interrupt_pending ? 1 : 0;
}

void interrupt_unpend(uint32_t interrupt)
{
    assert(interrupt < NUM_INTERRUPTS);

    /* Determine the interrupt to unpend. */
    if(interrupt == INT_PENDSV)
    {
        /* Unpend the PendSV interrupt. */
        CC26XX_CC13XX_NVIC->INT_CTRL |= NVIC_INT_CTRL_UNPEND_SV;
    }
    else if(interrupt == INT_SYSTICK)
    {
        /* Unpend the SysTick interrupt. */
        CC26XX_CC13XX_NVIC->INT_CTRL |= NVIC_INT_CTRL_PENDSTCLR;
    }
    else if((interrupt >= 16) && (interrupt <= 47))
    {
        /* Unpend the general interrupt. */
        CC26XX_CC13XX_NVIC->UNPEND0 = 1 << (interrupt - 16);
    }
    else if(interrupt >= 48)
    {
        /* Unpend the general interrupt. */
        CC26XX_CC13XX_NVIC->UNPEND1 = 1 << (interrupt - 48);
    }
}

/** @} */
