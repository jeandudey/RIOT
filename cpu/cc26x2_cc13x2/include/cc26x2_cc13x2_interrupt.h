/*
 * Copyright (C) 2020 Jean Pierre Dudey
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#ifndef CC26XX_CC13XX_INTERRUPT_H
#define CC26XX_CC13XX_INTERRUPT_H

#include "cc26xx_cc13xx_nvic.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *hw_interrupt_t; /**< A pointer to a interrupt */

/*hw_interrupt_t hw_interrupt_new(uint32_t interrupt_number,
                                void (*callback)(void*),
                                void* argument);*/

typedef void (*interrupt_handler_t)(void);

/**
 * @brief           Register an interrupt.
 */
void interrupt_register(uint32_t interrupt, interrupt_handler_t handler);

/**
 * @brief           Unregister an interrupt.
 */
void interrupt_unregister(uint32_t interrupt);

/**
 * @brief           Set interrupts priority grouping.
 */
void interrupt_set_priority_grouping(uint32_t bits);

/**
 * @brief           Get interrupts priority grouping.
 */
uint32_t interrupt_get_priority_grouping(void);

/**
 * @brief           Set interrupt priority.
 */
void interrupt_set_priority(uint32_t interrupt, uint8_t priority);

/**
 * @brief           Get interrupt priority.
 */
int32_t interrupt_get_priority(uint32_t interrupt);

/**
 * @brief           Enable interrupt.
 */
void interrupt_enable(uint32_t interrupt);

/**
 * @brief           Disable interrupt.
 */
void interrupt_disable(uint32_t interrupt);

/**
 * @brief           Set interrupt "pending".
 */
void interrupt_set_pend(uint32_t interrupt);

/**
 * @brief           Get interrupt "pending".
 */
int_fast32_t interrupt_get_pend(uint32_t interrupt);

/**
 * @brief           "Unpend" interrupt.
 */
void interrupt_unpend(uint32_t interrupt);

#define INT_NMI_FAULT (2) /**< NMI Fault */
#define INT_HARD_FAULT (3) /**< Hard Fault */
#define INT_MEMMANAGE_FAULT (4) /**< Memory Management
                                                 (MemManage) Fault */
#define INT_BUS_FAULT (5) /**< Bus Fault */
#define INT_USAGE_FAULT (6) /**< Usage Fault */
#define INT_SVCALL (11) /**< Supervisor Call (SVCall) */
#define INT_DEBUG (12) /**< Debug Monitor */
#define INT_PENDSV (14) /**< Pending Service Call (PendSV) */
#define INT_SYSTICK (15) /**< SysTick Interrupt from the System Timer in
                              NVIC. */
#define INT_AON_GPIO_EDGE (16) /**< Edge detect event from IOC */
#define INT_I2C_IRQ (17) /**< Interrupt event from I2C */
#define INT_RFC_CPE_1 (18) /**< Combined Interrupt for CPE Generated events */
#define INT_PKA_IRQ (19) /**< PKA Interrupt event */
#define INT_AON_RTC_COMB (20) /**< Event from AON_RTC */
#define INT_UART0_COMB (21) /**< UART0 combined interrupt */
#define INT_AUX_SWEV0 (22) /**< AUX software event 0 */
#define INT_SSI0_COMB (23) /**< SSI0 combined interrupt */
#define INT_SSI1_COMB (24) /**< SSI1 combined interrupt */
#define INT_RFC_CPE_0 (25) /**< Combined Interrupt for CPE Generated events */
#define INT_RFC_HW_COMB (26) /**< Combined RFC hardware interrupt */
#define INT_RFC_CMD_ACK (27) /**< RFC Doorbell Command Acknowledgement
                                  Interrupt */
#define INT_I2S_IRQ (28) /**< Interrupt event from I2S */
#define INT_AUX_SWEV1 (29) /**< AUX software event 1 */
#define INT_WDT_IRQ (30) /**< Watchdog interrupt event */
#define INT_GPT0A (31) /**< GPT0A interrupt event */
#define INT_GPT0B (32) /**< GPT0B interrupt event */
#define INT_GPT1A (33) /**< GPT1A interrupt event */
#define INT_GPT1B (34) /**< GPT1B interrupt event */
#define INT_GPT2A (35) /**< GPT2A interrupt event */
#define INT_GPT2B (36) /**< GPT2B interrupt event */
#define INT_GPT3A (37) /**< GPT3A interrupt event */
#define INT_GPT3B (38) /**< GPT3B interrupt event */
#define INT_CRYPTO_RESULT_AVAIL_IRQ (39) /**< CRYPTO result available interrupt
                                              event */
#define INT_DMA_DONE_COMB (40) /**< Combined DMA done */
#define INT_DMA_ERR (41) /**< DMA bus error */
#define INT_FLASH (42) /**< FLASH controller error event */
#define INT_SWEV0 (43) /**< Software event 0 */
#define INT_AUX_COMB (44) /**< AUX combined event */
#define INT_AON_PROG0 (45) /**< AON programmable event 0 */
#define INT_PROG0 (46) /**< Programmable Interrupt 0 */
#define INT_AUX_COMPA (47) /**< AUX Compare A event */
#define INT_AUX_ADC_IRQ (48) /**< AUX ADC interrupt event */
#define INT_TRNG_IRQ (49) /**< TRNG Interrupt event */
#define INT_OSC_COMB (50) /**< Combined event from Oscillator control */
#define INT_AUX_TIMER2_EV0 (51) /**< AUX Timer2 event 0 */
#define INT_UART1_COMB (52) /**< UART1 combined interrupt */
#define INT_BATMON_COMB (53) /**< Combined event from battery monitor */

#define INT_PRI_LEVEL0 (0x00000000)
#define INT_PRI_LEVEL1 (0x00000020)
#define INT_PRI_LEVEL2 (0x00000040)
#define INT_PRI_LEVEL3 (0x00000060)
#define INT_PRI_LEVEL4 (0x00000080)
#define INT_PRI_LEVEL5 (0x000000A0)
#define INT_PRI_LEVEL6 (0x000000C0)
#define INT_PRI_LEVEL7 (0x000000E0)

#define NUM_INTERRUPTS (54)

#ifdef __cplusplus
}
#endif

#endif /* CC26XX_CC13XX_INTERRUPT_H */
