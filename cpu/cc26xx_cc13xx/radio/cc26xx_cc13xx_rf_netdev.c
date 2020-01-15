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

#include <errno.h>

#include "net/gnrc.h"
#include "net/netdev.h"

#include "cc26xx_cc13xx_rf.h"
#include "cc26xx_cc13xx_rf_netdev.h"

/* Reference pointer for the IRQ handler */
static netdev_t *_dev;

void _irq_handler(void)
{
    if (_dev->event_callback) {
        _dev->event_callback(_dev, NETDEV_EVENT_ISR);
    }
}

static int _get(netdev_t *netdev, netopt_t opt, void *value, size_t max_len)
{
    cc26xx_cc13xx_rf_t *dev = (cc26xx_cc13xx_rf_t *) netdev;

    if (dev == NULL) {
        return -ENODEV;
    }

    switch (opt) {
        case NETOPT_ADDRESS:
            if (max_len < sizeof(uint16_t)) {
                return -EOVERFLOW;
            }
            else {
                *(uint16_t*)value = cc26xx_cc13xx_get_addr_short();
            }
            return sizeof(uint16_t);

        case NETOPT_ADDRESS_LONG:
            if (max_len < sizeof(uint64_t)) {
                return -EOVERFLOW;
            }
            else {
                *(uint64_t*)value = cc26xx_cc13xx_get_addr_long();
            }
            return sizeof(uint64_t);

        case NETOPT_AUTOACK:
            return -ENOTSUP;

        case NETOPT_CHANNEL:
            if (max_len < sizeof(uint16_t)) {
                return -EOVERFLOW;
            }
            /**((uint16_t *)value) = (uint16_t)xx;*/
            return sizeof(uint16_t);

        case NETOPT_CHANNEL_PAGE:
            if (max_len < sizeof(uint16_t)) {
                return -EOVERFLOW;
            }
            /**((uint16_t *)value) = xxx; */
            return sizeof(uint16_t);

        case NETOPT_DEVICE_TYPE:
            if (max_len < sizeof(uint16_t)) {
                return -EOVERFLOW;
            }
            *((uint16_t *) value) = NETDEV_TYPE_IEEE802154;
            return sizeof(uint16_t);

        case NETOPT_IS_CHANNEL_CLR:
            return -ENOTSUP;

        case NETOPT_IS_WIRED:
            return -ENOTSUP;

        case NETOPT_PROMISCUOUSMODE:
            return -ENOTSUP;

        case NETOPT_STATE:
            if (max_len < sizeof(netopt_state_t)) {
                return -EOVERFLOW;
            }
            /**((netopt_state_t *)value) = xxxx;*/
            return sizeof(netopt_state_t);

        case NETOPT_TX_POWER:
            if (max_len < sizeof(int16_t)) {
                return -EOVERFLOW;
            }
            /**((uint16_t *)value) = xxxx;*/
            return sizeof(uint16_t);

        default:
            break;
    }

    int res;

    if (((res = netdev_ieee802154_get((netdev_ieee802154_t *)netdev, opt, value,
                                      max_len)) >= 0) || (res != -ENOTSUP)) {
        return res;
    }

    return -ENOTSUP;
}

static int _set(netdev_t *netdev, netopt_t opt, const void *value, size_t value_len)
{
    (void)netdev;
    (void)opt;
    (void)value;
    (void)value_len;

    return 0;
}

static int _send(netdev_t *netdev, const iolist_t *iolist)
{
    (void)netdev;
    (void)iolist;

    return 0;
}

static int _recv(netdev_t *netdev, void *buf, size_t len, void *info)
{
    (void)netdev;
    (void)buf;
    (void)len;
    (void)info;

    return 0;
}

static void _isr(netdev_t *netdev)
{
    netdev->event_callback(netdev, NETDEV_EVENT_RX_COMPLETE);
}

static int _init(netdev_t *netdev)
{
    cc26xx_cc13xx_rf_t *dev = (cc26xx_cc13xx_rf_t *) netdev;
    _dev = netdev;

    uint64_t addr_long = cc26xx_cc13xx_get_addr_long();

    netdev_ieee802154_reset(&dev->netdev);

    netdev_ieee802154_set(&dev->netdev, NETOPT_ADDRESS_LONG,
                          &addr_long, sizeof(addr_long));

    return 0;
}

const netdev_driver_t cc26xx_cc13xx_rf_driver = {
    .get  = _get,
    .set  = _set,
    .send = _send,
    .recv = _recv,
    .isr  = _isr,
    .init = _init,
};
