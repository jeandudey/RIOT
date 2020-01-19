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

#define ENABLE_DEBUG (1)
#include "debug.h"

typedef struct {
    uint8_t used;
    uint32_t interrupt_number; /**< interrupt number */
    hw_interrupt_handler_t callback; /**< interrupt callback */
    uintptr_t argument; /**< callback argument */
} hw_internal_interrupt_t;

static hw_internal_interrupt_t _interrupt_dispatch_table[NUM_INTERRUPTS] = {{0}};

static uint32_t SW_INTERRUPT_NUMBER = INT_PENDSV;

static void hw_interrupt_dispatch(void)
{
    /* Determine which interrupt has fired */
    uint32_t interrupt_number = (CC26XX_CC13XX_NVIC->INT_CTRL & 0x000000FF);
    hw_internal_interrupt_t* interrupt = &_interrupt_dispatch_table[interrupt_number];
    if (interrupt) {
        (interrupt->callback)((void*)interrupt->argument);
    }
}

hw_interrupt_t hw_interrupt_new(uint32_t interrupt_number,
                                uint8_t priority,
                                hw_interrupt_handler_t callback,
                                void* argument,
                                uint8_t enable_on_creation)
{
    assert(interrupt_number < NUM_INTERRUPTS);

    hw_internal_interrupt_t* interrupt
        = &_interrupt_dispatch_table[interrupt_number];

    /* Interrupt is already being used, must the interrupt first created must
     * be freed first.
     */
    if (interrupt->used == 1) {
        return (hw_interrupt_t)interrupt;
    }

    if (interrupt_number != SW_INTERRUPT_NUMBER && priority == INT_PRI_LEVEL7) {
        DEBUG("hw_interrupt_new: can't use reserved INT_PRI_LEVEL7\n");
        return NULL;
    }

    if ((priority & 0xFF) == 0xFF) {
        /* software.c interrupts uses INT_PRI_LEVEL7 as its scheduler. */
        priority = INT_PRI_LEVEL6;
    }

    interrupt->used = 1;
    interrupt->interrupt_number = interrupt_number;
    interrupt->callback = callback;
    interrupt->argument = (uintptr_t)argument;

    interrupt_register(interrupt->interrupt_number, hw_interrupt_dispatch);
    interrupt_set_priority(interrupt->interrupt_number, priority);

    if (enable_on_creation == 1) {
        interrupt_enable(interrupt->interrupt_number);
    }

    return (hw_interrupt_t)interrupt;
}

void hw_interrupt_free(hw_interrupt_t interrupt)
{
    hw_internal_interrupt_t *int_interrupt =
        (hw_internal_interrupt_t *)interrupt;

    interrupt_disable(int_interrupt->interrupt_number);
    interrupt_unregister(int_interrupt->interrupt_number);

    int_interrupt->used = 0;
    int_interrupt->interrupt_number = 0;
    int_interrupt->callback = NULL;
    int_interrupt->argument = 0;
}


void hw_interrupt_enable_all(void)
{
    interrupt_master_enable();
}

uintptr_t hw_interrupt_disable_all(void)
{
    return interrupt_master_disable();
}

void hw_interrupt_clear(uint32_t interrupt_num)
{
    interrupt_unpend(interrupt_num);
}


void hw_interrupt_disable(uint32_t interrupt_number)
{
    interrupt_disable(interrupt_number);
}

void hw_interrupt_enable(uint32_t interrupt_number)
{
    interrupt_enable(interrupt_number);
}

void hw_interrupt_post(uint32_t interrupt_number)
{
    interrupt_set_pend(interrupt_number);
}

void hw_interrupt_set_priority(uint32_t interrupt_number, uint8_t priority)
{
    interrupt_set_priority(interrupt_number, priority);
}

int_fast32_t hw_interrupt_in_isr(void)
{
    /* Check if we aren't in a ISR */
    if ((CC26XX_CC13XX_NVIC->INT_CTRL & CPU_SCS_ICSR_VECTACTIVE_M) == 0) {
        return 0;
    }

    return 1;
}

/** @} */
