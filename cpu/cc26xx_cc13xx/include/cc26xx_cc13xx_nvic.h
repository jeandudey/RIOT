/*
 * Copyright (C) 2020 Jean Pierre Dudey
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup         cpu_cc26xx_cc13xx_definitions
 * @{
 *
 * @file
 * @brief           CC26xx/CC13xx MCU I/O register definitions
 *
 * @author          Jean Pierre Dudey <leon@georgemail.eu>
 */

#ifndef CC26XX_CC13XX_NVIC_H
#define CC26XX_CC13XX_NVIC_H

#include "cc26xx_cc13xx.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    reg32_t _reserved0;
    reg32_t INT_TYPE; /**< Interrupt Controller Type Reg */
    reg32_t ACTLR; /**< Auxiliary Control */
    reg32_t ST_CTRL; /**< SysTick Control and Status Register */
    reg32_t ST_RELOAD; /**< SysTick Reload Value Register */
    reg32_t ST_CURRENT; /**< SysTick Current Value Register */
    reg32_t ST_CAL; /**< SysTick Calibration Value Reg */
    reg32_t EN0; /**< Interrupt 0-31 Set Enable */
    reg32_t EN1; /**< Interrupt 32-54 Set Enable */
    reg8_t _reserved1[0x78]; /**< Reserved, offset 108h, size 78h */
    reg32_t DIS0; /**< Interrupt 0-31 Clear Enable */
    reg32_t DIS1; /**< Interrupt 32-54 Clear Enable */
    reg8_t _reserved2[0x78]; /**< Reserved, offset 188h, size 78h */
    reg32_t PEND0; /**< Interrupt 0-31 Set Pending */
    reg32_t PEND1; /**< Interrupt 32-54 Set Pending */
    reg8_t _reserved3[0x78]; /**< Reserved, offset 208h, size 78h */
    reg32_t UNPEND0; /**< Interrupt 0-31 Clear Pending */
    reg32_t UNPEND1; /**< Interrupt 32-54 Clear Pending */
    reg8_t _reserved4[0x78]; /**< Reserved, offset 288h, size 78h */
    reg32_t ACTIVE0; /**< Interrupt 0-31 Active Bit */
    reg32_t ACTIVE1; /**< Interrupt 32-54 Active Bit */
    reg8_t _reserved5[0xF8]; /**< Reserved, offset 308h, size F8h */
    reg32_t PRI0; /**< Interrupt 0-3 Priority */
    reg32_t PRI1; /**< Interrupt 4-7 Priority */
    reg32_t PRI2; /**< Interrupt 8-11 Priority */
    reg32_t PRI3; /**< Interrupt 12-15 Priority */
    reg32_t PRI4; /**< Interrupt 16-19 Priority */
    reg32_t PRI5; /**< Interrupt 20-23 Priority */
    reg32_t PRI6; /**< Interrupt 24-27 Priority */
    reg32_t PRI7; /**< Interrupt 28-31 Priority */
    reg32_t PRI8; /**< Interrupt 32-35 Priority */
    reg32_t PRI9; /**< Interrupt 36-39 Priority */
    reg32_t PRI10; /**< Interrupt 40-43 Priority */
    reg32_t PRI11; /**< Interrupt 44-47 Priority */
    reg32_t PRI12; /**< Interrupt 48-51 Priority */
    reg32_t PRI13; /**< Interrupt 52-55 Priority */
    reg8_t _reserved6[0x8C8]; /**< Reserved, offset 438h, size 8C8h */
    reg32_t CPUID; /**< CPU ID Base */
    reg32_t INT_CTRL; /**< Interrupt Control and State */
    reg32_t VTABLE; /**< Vector Table Offset */
    reg32_t APINT; /**< Application Interrupt and Reset Control */
    reg32_t SYS_CTRL; /**< System Control */
    reg32_t CFG_CTRL; /**< Configuration and Control */
    reg32_t SYS_PRI1; /**< System Handler Priority 1 */
    reg32_t SYS_PRI2; /**< System Handler Priority 2 */
    reg32_t SYS_PRI3; /**< System Handler Priority 3 */
    reg32_t SYS_HND_CTRL; /**< System Handler Control and State */
    reg32_t FAULT_STAT; /**< Configurable Fault Status */
    reg32_t HFAULT_STAT; /**< Hard Fault Status */
    reg32_t DEBUG_STAT; /**< Debug Status Register */
    reg32_t MM_ADDR; /**< Memory Management Fault Address */
    reg32_t FAULT_ADDR; /**< Bus Fault Address */
    reg8_t _reserved7[0x54]; /**< Reserved, offset D3Ch, size 54h */
    reg32_t MPU_TYPE; /**< MPU Type */
    reg32_t MPU_CTRL; /**< MPU Control */
    reg32_t MPU_NUMBER; /**< MPU Region Number */
    reg32_t _MPU_BASE; /**< MPU Region Base Address */
    reg32_t MPU_ATTR; /**< MPU Region Attribute and Size */
    reg32_t MPU_BASE1; /**< MPU Region Base Address Alias 1 */
    reg32_t MPU_ATTR1; /**< MPU Region Attribute and Size Alias 1 */
    reg32_t MPU_BASE2; /**< MPU Region Base Address Alias 2 */
    reg32_t MPU_ATTR2; /**< MPU Region Attribute and Size Alias 2 */
    reg32_t MPU_BASE3; /**< MPU Region Base Address Alias 3 */
    reg32_t MPU_ATTR3; /**< MPU Region Attribute and Size Alias 3 */
    reg8_t _reserved8[0x34]; /**< Reserved, offset DBCh, size 34h */
    reg32_t DBG_CTRL;/**< Debug Control and Status Reg */
    reg32_t DBG_XFER; /**< Debug Core Reg. Transfer Select */
    reg32_t DBG_DATA; /**< Debug Core Register Data */
    reg32_t DBG_INT; /**< Debug Reset Interrupt Control */
    reg32_t SW_TRIG; /**< Software Trigger Interrupt */
} cc26xx_cc13xx_nvic_t;

/**
 * @brief           Vector key.
 */
#define NVIC_APINT_VECTKEY (0x05FA0000)

/**
 * @brief           Data Endianess.
 */
#define NVIC_APINT_ENDIANESS (0x00008000)

/**
 * @brief           Interrupt Priority Grouping.
 */
#define NVIC_APINT_PRIGROUP_M (0x00000700)

/**
 * @brief           Priority group 7.1 split.
 */
#define NVIC_APINT_PRIGROUP_7_1 (0x00000000)

/**
 * @brief           Priority group 6.2 split.
 */
#define NVIC_APINT_PRIGROUP_6_2 (0x00000100)

/**
 * @brief           Priority group 5.3 split.
 */
#define NVIC_APINT_PRIGROUP_5_3 (0x00000200)

/**
 * @brief           Priority group 4.4 split.
 */
#define NVIC_APINT_PRIGROUP_4_4 (0x00000300)

/**
 * @brief           Priority group 3.5 split.
 */
#define NVIC_APINT_PRIGROUP_3_5 (0x00000400)

/**
 * @brief           Priority group 2.6 split.
 */
#define NVIC_APINT_PRIGROUP_2_6 (0x00000500)

/**
 * @brief           Priority group 1.7 split.
 */
#define NVIC_APINT_PRIGROUP_1_7 (0x00000600)

/**
 * @brief           Priority group 0.8 split.
 */
#define NVIC_APINT_PRIGROUP_0_8 (0x00000700)

/**
 * @brief           System Reset Request.
 */
#define NVIC_APINT_SYSRESETREQ  (0x00000004)

/**
 * @brief           Clear Active NMI / Fault.
 */
#define NVIC_APINT_VECT_CLR_ACT (0x00000002)

/**
 * @brief           System Reset.
 */
#define NVIC_APINT_VECT_RESET (0x00000001)

/**
 * @brief           Usage Fault Enable.
 */
#define NVIC_SYS_HND_CTRL_USAGE (0x00040000)
/**
 * @brief           Bus Fault Enable.
 */
#define NVIC_SYS_HND_CTRL_BUS (0x00020000)
/**
 * @brief           Memory Management Fault Enable.
 */
#define NVIC_SYS_HND_CTRL_MEM (0x00010000)
/**
 * @brief           SVC Call Pending.
 */
#define NVIC_SYS_HND_CTRL_SVC (0x00008000)
/**
 * @brief           Bus Fault Pending.
 */
#define NVIC_SYS_HND_CTRL_BUSP (0x00004000)
/**
 * @brief           Memory Management Fault Pending.
 */
#define NVIC_SYS_HND_CTRL_MEMP (0x00002000)
/**
 * @brief           Usage Fault Pending.
 */
#define NVIC_SYS_HND_CTRL_USAGEP (0x00001000)
/**
 * @brief           SysTick Exception Active.
 */
#define NVIC_SYS_HND_CTRL_TICK (0x00000800)
/**
 * @brief           PendSV Exception Active.
 */
#define NVIC_SYS_HND_CTRL_PNDSV (0x00000400)
/**
 * @brief           Debug Monitor Active.
 */
#define NVIC_SYS_HND_CTRL_MON (0x00000100)
/**
 * @brief           SVC Call Active.
 */
#define NVIC_SYS_HND_CTRL_SVCA (0x00000080)
/**
 * @brief           Usage Fault Active.
 */
#define NVIC_SYS_HND_CTRL_USGA (0x00000008)
/**
 * @brief           Bus Fault Active.
 */
#define NVIC_SYS_HND_CTRL_BUSA (0x00000002)
/**
 * @brief           Memory Management Fault Actie.
 */
#define NVIC_SYS_HND_CTRL_MEMA (0x00000001)

/**
 * @brief           Count Flag.
 */
#define NVIC_ST_CTRL_COUNT (0x00010000)
/**
 * @brief           Clock Source.
 */
#define NVIC_ST_CTRL_CLK_SRC (0x00000004)
/**
 * @brief           Interrupt Enable.
 */
#define NVIC_ST_CTRL_INTEN (0x00000002)
/**
 * @brief           Enable.
 */
#define NVIC_ST_CTRL_ENABLE (0x00000001)

/**
 * @brief           NMI Set Pending
 */
#define NVIC_INT_CTRL_NMI_SET (0x80000000)

/**
 * @brief           PendSV Set Pending
 */
#define NVIC_INT_CTRL_PEND_SV (0x10000000)

/**
 * @brief           PendSV Clear Pending
 */
#define NVIC_INT_CTRL_UNPEND_SV (0x08000000)

/**
 * @brief           SysTick Set Pending
 */
#define NVIC_INT_CTRL_PENDSTSET (0x04000000)

/**
 * @brief           SysTick Clear Pending
 */
#define NVIC_INT_CTRL_PENDSTCLR (0x02000000)

/**
 * @brief           Debug Interrupt Handling
 */
#define NVIC_INT_CTRL_ISR_PRE (0x00800000)

/**
 * @brief           Interrupt Pending
 */
#define NVIC_INT_CTRL_ISR_PEND (0x00400000)

/**
 * @brief           Interrupt Pending Vector Number
 */
#define NVIC_INT_CTRL_VEC_PEN_M (0x000FF000)

/**
 * @brief           NMI
 */
#define NVIC_INT_CTRL_VEC_PEN_NMI (0x00002000)

/**
 * @brief           Hard fault
 */
#define NVIC_INT_CTRL_VEC_PEN_HARD (0x00003000)

/**
 * @brief           Memory management fault
 */
#define NVIC_INT_CTRL_VEC_PEN_MEM (0x00004000)

/**
 * @brief           Bus fault
 */
#define NVIC_INT_CTRL_VEC_PEN_BUS (0x00005000)


/**
 * @brief           Usage fault
 */
#define NVIC_INT_CTRL_VEC_PEN_USG (0x00006000)

/**
 * @brief           SVCall
 */
#define NVIC_INT_CTRL_VEC_PEN_SVC (0x0000B000)

/**
 * @brief           PendSV
 */
#define NVIC_INT_CTRL_VEC_PEN_PNDSV (0x0000E000)

/**
 * @brief           SysTick
 */
#define NVIC_INT_CTRL_VEC_PEN_TICK (0x0000F000)

/**
 * @brief           Return to Base
 */
#define NVIC_INT_CTRL_RET_BASE  (0x00000800)

/**
 * @brief           Interrupt Pending Vector Number
 */
#define NVIC_INT_CTRL_VEC_ACT_M (0x000000FF)

/**
 * @brief           Number of prority bits. It's the same for all the family of
 *                  processors.
 */
#define NUM_PRIORITY_BITS (3)

/**
 * @brief           Priority number. It's the same for all the family of
 *                  processors.
 */
#define NUM_PRIORITY (8)

/** @ingroup cpu_specific_peripheral_memory_map
  * @{
  */
/**
  * @brief NVIC base address
  */
#define CC26XX_CC13XX_NVIC_BASE (0xE000E000)
/** @} */

/**
 * @brief NVIC memory bank
 */
#define CC26XX_CC13XX_NVIC ((cc26xx_cc13xx_nvic_t *) (CC26XX_CC13XX_NVIC_BASE))

#ifdef __cplusplus
}
#endif

#endif /* CC26XX_CC13XX_NVIC_H */

/*@}*/
