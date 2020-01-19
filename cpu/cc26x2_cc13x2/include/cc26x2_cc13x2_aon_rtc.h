/*
 * Copyright (C) 2015 - 2017, Texas Instruments Incorporated
 * Copyright (C) 2020 Locha Inc
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup         cpu_cc26x2_cc13x2_definitions
 * @{
 *
 * @file
 * @brief           CC26x2/CC13x2 Always-On RTC register definitions
 *
 * @author          Jean Pierre Dudey <jeandudey@hotmail.com>
 */

#ifndef CC26XX_CC13XX_AON_RTC_H
#define CC26XX_CC13XX_AON_RTC_H

#include "cc26xx_cc13xx.h"

/**
 * @ingroup         cpu_cc26x2_cc13x2_definitions
 * @{
 *
 * @file
 * @brief           CC26x2/CC13x2 Always-On RTC register definitions
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Always-On RTC registers
 */
typedef struct {
    reg32_t CTL; /**< Control */
    reg32_t EVFLAGS; /**< Event Flags; RTC Status */ 
    reg32_t SEC; /**< Second Counter Value; Integer Part */ 
    reg32_t SUBSEC; /**< Second Counter Value; Fractional Part */ 
    reg32_t SUBSECINC; /**< Subseconds Increment */ 
    reg32_t CHCTL;  /**< Channel Configuration */ 
    reg32_t CH0CMP; /**< Channel 0 Compare Value */ 
    reg32_t CH1CMP; /**< Channel 1 Compare Value */ 
    reg32_t CH2CMP; /**< Channel 2 Compare Value */ 
    reg32_t CH2CMPINC; /**< Channel 2 Compare Value Auto-increment */ 
    reg32_t CH1CAPT; /**< Channel 1 Capture Value */ 
    reg32_t SYNC; /**< AON Synchronization */ 
    reg32_t TIME; /**< Current Counter Value */ 
    reg32_t SYNCLF; /**< Synchronization to SCLK_LF */
} aon_rtc_regs_t;

/**
 * @brief        RTC_UPD is a 16 KHz signal used to sync up the radio timer.
 *               The 16 Khz is SCLK_LF divided by 2.
 * @details      0h = RTC_UPD signal is forced to 0.
 *               1h = RTC_UPD signal is toggling @16 kHz
 */
#define CTL_UPD_EN                                      0x00000002

/** @ingroup cpu_specific_peripheral_memory_map
  * @{
  */
#define AON_RTC_BASE           (PERIPH_BASE + 0x92000) /**< AON_RTC base address */
/** @} */

#define AON_RTC ((aon_rtc_regs_t *) (AON_RTC_BASE)) /**< AON_RTC register bank */

#ifdef __cplusplus
}
#endif

#endif /* CC26XX_CC13XX_AON_RTC_H */

/*@}*/
