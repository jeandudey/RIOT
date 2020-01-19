/*
 * Copyright (C) 2015 - 2017, Texas Instruments Incorporated
 * Copyright (C) 2020 Locha Inc
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup         cpu_cc26xx_cc13xx_intrinsics
 * @{
 *
 * @file
 * @brief           CC26xx/CC13xx CPU intrinsics
 */

#ifndef CC26XX_CC13XX_CPU_H
#define CC26XX_CC13XX_CPU_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief           Enable external interrupts.
 * @return          The saved valueo of PRIMASk.
 */
uint32_t __cpu_cpsie(void);

/**
 * @brief           Disable external interrupts.
 * @return          The saved valueo of PRIMASk.
 */
uint32_t __cpu_cpsid(void);

#ifdef __cplusplus
} /* end extern "C" */
#endif

#endif /* CC26XX_CC13XX_CPU_H */

/*@}*/
