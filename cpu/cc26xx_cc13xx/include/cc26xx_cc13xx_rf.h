/*
 * Copyright (C) 2020 Locha Inc
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup         cpu_cc26xx_cc13xx_radio
 * @{
 *
 * @file
 * @brief           CC26xx/CC13xx Radio.
 *
 * @author          Jean Pierre Dudey <jeandudey@hotmail.com>
 */

#ifndef CC26XX_CC13XX_RF_H
#define CC26XX_CC13XX_RF_H

#include <stdbool.h>

#include "net/ieee802154.h"
#include "net/netdev.h"
#include "net/netdev/ieee802154.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   CC26XX/CC13XX Radio device interface.
 */
typedef struct {
    netdev_ieee802154_t netdev;   /**< netdev parent struct */
    uint8_t state;                /**< current state of the radio */
} cc26xx_cc13xx_rf_t;

/**
 * @brief   Setup the CC26XX/CC13XX radio.
 */
void cc26xx_cc13xx_setup(cc26xx_cc13xx_rf_t *dev);

/**
 * @brief   Get the configured short address of the device
 *
 * @return  The currently set (2-byte) short address
 */
uint16_t cc26xx_cc13xx_get_addr_short(void);

/**
 * @brief   Get the configured long address of the device
 *
 * @return  The currently set (8-byte) long address
 */
uint64_t cc26xx_cc13xx_get_addr_long(void);

#ifdef __cplusplus

} /* extern "C" */
#endif

#endif /* CC26XX_CC13XX_RF_H */
