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
 */

#ifndef CC26XX_CC13XX_IRQ_H
#define CC26XX_CC13XX_IRQ_H

#include "cc26xx_cc13xx.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief           Disable IRQs.
 *
 * @return          the saved value of PRIMASK.
 */
uint32_t irq_disable_all(void);

/**
 * @brief           Restore (enable) IRQs depending on the PRIMASK value.
 */
void irq_restore_all(uint32_t primask);

#ifdef __cplusplus
} /* end extern "C" */
#endif

#endif /* CC26XX_CC13XX_IRQ_H */
/** @} */
