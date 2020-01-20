/*
 * Copyright (C) 2020 Locha Inc
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup         cpu_cc13x2
 * @{
 *
 * @file
 * @brief           CC13x2 radio
 *
 * @author          Jean Pierre Dudey <jeandudey@hotmail.com>
 * @}
 */

#include "cc13x2_rf_netdev.h"

int _send(netdev_t *dev, const iolist_t *iolist)
{
    (void)dev;
    (void)iolist;

    return -1;
}

int _recv(netdev_t *dev, void *buf, size_t len, void *info)
{
    (void)dev;
    (void)buf;
    (void)len;
    (void)info;

    return -1;
}

int _init(netdev_t *dev)
{
    (void)dev;

    return -1;
}

void _isr(netdev_t *dev)
{
    (void)dev;
}

int _get(netdev_t *dev, netopt_t opt, void *value, size_t max_len)
{
    (void)dev;
    (void)opt;
    (void)value;
    (void)max_len;

    return -1;
}

int _set(netdev_t *dev, netopt_t opt, const void *value, size_t value_len)
{
    (void)dev;
    (void)opt;
    (void)value;
    (void)value_len;

    return -1;
}

netdev_driver_t cc13x2_radio_driver = {
    .send = _send,
    .recv = _recv,
    .init = _init,
    .isr = _isr,
    .get = _get,
    .set = _set,
};
