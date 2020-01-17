/*
 * Copyright (C) 2020 Locha Inc
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     cpu_cc26xx_cc13xx_radio
 * @{
 *
 * @file
 * @brief       CC26xx/CC13xxx radio driver network stack.
 *
 * @author      Jean Pierre Dudey <jeandudey@hotmail.com>
 *
 * @}
 */

#include "cc26xx_cc13xx_rf_netstack.h"

#undef UART0_BASE
#undef UART1_BASE
#undef GPT0_BASE
#undef GPT1_BASE
#undef GPT2_BASE
#undef GPT3_BASE
#undef FLASH_BASE
#undef GPIO_BASE
#undef AON_IOC_BASE

#define ENABLE_DEBUG (1)
#include "debug.h"

static RF_Object rf_netstack;

extern RF_Mode rf_prop_mode;
extern rfc_CMD_PROP_RADIO_DIV_SETUP_t rf_cmd_prop_radio_div_setup;

RF_Handle cc26xx_cc13xx_netstack_open(RF_Params *params)
{
    DEBUG("cc26xx_cc13xx_netstack_open\n");
    return RF_open(&rf_netstack, &rf_prop_mode, (RF_RadioSetup *)&rf_cmd_prop_radio_div_setup, params);
}
