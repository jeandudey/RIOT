/*
 * Copyright (C) 2020 Locha Inc
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 *
 */

/*
 * @ingroup sys_auto_init_gnrc_netif
 * @{
 *
 * @file
 * @brief   Auto initialization for the cc26xx/cc13xx network interface
 *
 * @author  Aaron Sowry <aaron@mutex.nz>
 */

#ifdef MODULE_CC26XX_CC13XX_RF

#include "log.h"
#include "net/gnrc/netif/ieee802154.h"

#include "cc26xx_cc13xx_rf.h"

/**
 * @brief   Define stack parameters for the MAC layer thread
 * @{
 */
#define CC26XX_CC13XX_MAC_STACKSIZE       (THREAD_STACKSIZE_DEFAULT)
#ifndef CC26XX_CC13XX_MAC_PRIO
#define CC26XX_CC13XX_MAC_PRIO            (GNRC_NETIF_PRIO)
#endif

static cc26xx_cc13xx_rf_t cc26xx_cc13xx_rf_dev;
static char _cc26xx_cc13xx_rf_stack[CC26XX_CC13XX_MAC_STACKSIZE];

void auto_init_cc26xx_cc13xx_rf(void)
{
    LOG_DEBUG("[auto_init_netif] initializing cc26xx/cc13xx radio\n");

    cc26xx_cc13xx_setup(&cc26xx_cc13xx_rf_dev);
    gnrc_netif_ieee802154_create(_cc26xx_cc13xx_rf_stack,
                                 CC26XX_CC13XX_MAC_STACKSIZE,
                                 CC26XX_CC13XX_MAC_PRIO, "cc26xx_cc13xx_rf",
                                 (netdev_t *)&cc26xx_cc13xx_rf_dev);
}

#else
typedef int dont_be_pedantic;
#endif /* MODULE_CC26XX_CC13XX_RF */
/** @} */
