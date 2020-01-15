/*
 * Copyright (C) 2020 Locha Inc
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     cpu_cc26xx_13xx_radio
 * @{
 *
 * @file
 * @brief       Getter and setter functions for the cc26xx_cc13xx_rf driver.
 *
 * @author      Jean Pierre Dudey <jeandudey@hotmail.com>
 *
 * @}
 */

#include "cc26xx_cc13xx_rf.h"

#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(inc/hw_memmap.h)
#include DeviceFamily_constructPath(inc/hw_fcfg1.h)
#include DeviceFamily_constructPath(inc/hw_ccfg.h)

#define IEEE_MAC_PRIMARY_ADDRESS    (FCFG1_BASE + FCFG1_O_MAC_15_4_0)
#define IEEE_MAC_SECONDARY_ADDRESS  (CCFG_BASE + CCFG_O_IEEE_MAC_0)
#define IEEE_LONG_ADDR_SIZE         8

uint16_t cc26xx_cc13xx_get_addr_short(void)
{
    /* TODO: performance? do we really need to get ALL of the address to just
     * get the short address? */
    return (uint16_t)((cc26xx_cc13xx_get_addr_short() & 0xFFFF0000) >> 16);
}

uint64_t cc26xx_cc13xx_get_addr_long(void)
{
    int i = 0;
    uint8_t dst[IEEE_LONG_ADDR_SIZE] = {0};
    uint64_t res = 0;

    volatile const uint8_t *const primary = (uint8_t *)IEEE_MAC_PRIMARY_ADDRESS;
    volatile const uint8_t *const secondary = (uint8_t *)IEEE_MAC_SECONDARY_ADDRESS;

    /* Reading from primary location... */
    volatile const uint8_t *ieee_addr = primary;

    /*
     * ...unless we can find a byte != 0xFF in secondary.
     *
     * Intentionally checking all 8 bytes here instead of len, because we
     * are checking validity of the entire address respective of the
     * actual number of bytes the caller wants to copy over.
     */
    for(i = 0; i < IEEE_LONG_ADDR_SIZE; i++) {
        if(secondary[i] != 0xFF) {
            /* A byte in the secondary location is not 0xFF. Use the secondary */
            ieee_addr = secondary;
            break;
        }
    }

    /*
     * We have chosen what address to read the address from. Do so,
     * in inverted byte order.
     */
    for(i = 0; i < IEEE_LONG_ADDR_SIZE; i++) {
        dst[i] = ieee_addr[IEEE_LONG_ADDR_SIZE - 1 - i];
    }

    res = ((uint64_t)dst[7] << 0) |
          ((uint64_t)dst[6] << 8) |
          ((uint64_t)dst[5] << 16) |
          ((uint64_t)dst[4] << 24) |
          ((uint64_t)dst[3] << 32) |
          ((uint64_t)dst[2] << 40) |
          ((uint64_t)dst[1] << 48) |
          ((uint64_t)dst[0] << 56);

    return res;
}
