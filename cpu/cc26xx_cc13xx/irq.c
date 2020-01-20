/*
 * Copyright (C) 2020 Locha Inc
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @addtogroup      cpu_cc26xx_cc13xx
 * @{
 *
 * @file
 * @brief           IRQ interface.
 *
 * @author          Jean Pierre Dudey <jeandudey@hotmail.com>
 * @}
 */

#include "cpu.h"

uint32_t irq_disable_all(void)
{
    uint32_t primask = __get_PRIMASK();
    __disable_irq();
    return primask;
}

void irq_restore_all(uint32_t primask)
{
    int should_enable = primask;
    if (should_enable) {
        __enable_irq();
    }
}
