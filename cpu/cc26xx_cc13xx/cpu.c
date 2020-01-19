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

#include "cc26xx_cc13xx_cpu.h"

uint32_t __attribute__((naked)) __cpu_cpsie(void)
{
    uint32_t ret;

    /* Read PRIMASK and enable interrupts. */
    __asm volatile ("    mrs     %0, PRIMASK\n"
                    "    cpsie   i\n"
                    "    bx      lr\n"
                    : "=r"(ret)
                   );

    /* The return is handled in the inline assembly, but the compiler will
     * still complain if there is not an explicit return here (despite the fact
     * that this does not result in any code being produced because of the
     * naked attribute).
     */
    return ret;
}

uint32_t __attribute__((naked)) __cpu_cpsid(void)
{
    uint32_t ret;

    /* Read PRIMASK and disable interrupts */
    __asm volatile ("    mrs     %0, PRIMASK\n"
                    "    cpsid   i\n"
                    "    bx      lr\n"
                    : "=r"(ret)
                   );

    /* The return is handled in the inline assembly, but the compiler will
     * still complain if there is not an explicit return here (despite the fact
     * that this does not result in any code being produced because of the
     * naked attribute).
     */
    return ret;
}

/** @} */
