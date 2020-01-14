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

#include "cc26xx_cc13xx_rf.h"
#include "cc26xx_cc13xx_rf_netdev.h"

void cc26xx_cc13xx_init(void)
{
}

void cc26xx_cc13xx_setup(cc26xx_cc13xx_rf_t *dev)
{
    netdev_t *netdev = (netdev_t *)dev;

    netdev->driver = &cc26xx_cc13xx_rf_driver;

    cc26xx_cc13xx_init();
}
