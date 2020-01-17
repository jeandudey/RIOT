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

#ifndef CC26XX_CC13XX_RF_NETSTACK_H
#define CC26XX_CC13XX_RF_NETSTACK_H

#include <ti/drivers/rf/RF.h>

#ifdef __cplusplus
extern "C" {
#endif

RF_Handle cc26xx_cc13xx_netstack_open(RF_Params *params);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CC26XX_CC13XX_RF_NETSTACK_H */
