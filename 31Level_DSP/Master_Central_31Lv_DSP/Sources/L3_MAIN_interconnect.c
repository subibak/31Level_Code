/*
 * L3_MAIN_interconnect.c
 *
 *  Created on: 2018. 12. 2.
 *      Author: subi
 */

#include "Define_Header.h"

#define L3_MAIN_Firewall_DSP1_SDMA_FW_ERROR_LOG                      *(Uint32 *)(0x4A171000)
#define L3_MAIN_Firewall_DSP1_SDMA_FW_LOGICAL_ADDR_ERROR_LOG         *(Uint32 *)(0x4A171004)
#define L3_MAIN_Firewall_DSP1_SDMA_FW_REGUPDATE_CONTROL              *(Uint32 *)(0x4A171040)
#define L3_MAIN_Firewall_DSP1_SDMA_FW_START_REGION_1                 *(Uint32 *)(0x4A171080)
#define L3_MAIN_Firewall_DSP1_SDMA_FW_END_REGION_1                   *(Uint32 *)(0x4A171084)
#define L3_MAIN_Firewall_DSP1_SDMA_FW_MRM_PERMISSION_REGION_HIHG_1   *(Uint32 *)(0x4A17108C)
#define L3_MAIN_Firewall_DSP1_SDMA_FW_MRM_PERMISSION_REGION_LOW_1    *(Uint32 *)(0x4A171088)

#define L3_MAIN_Firewall_GPMC_FW_ERROR_LOG                           *(Uint32 *)(0x4A210000)
#define L3_MAIN_Firewall_GPMC_FW_LOGICAL_ADDR_ERROR_LOG              *(Uint32 *)(0x4A210004)
#define L3_MAIN_Firewall_GPMC_FW_REGUPDATE_CONTROL                   *(Uint32 *)(0x4A210040)
#define L3_MAIN_Firewall_GPMC_FW_START_REGION_1                      *(Uint32 *)(0x4A210080)
#define L3_MAIN_Firewall_GPMC_FW_END_REGION_1                        *(Uint32 *)(0x4A210084)
#define L3_MAIN_Firewall_GPMC_FW_MRM_PERMISSION_REGION_HIHG_1        *(Uint32 *)(0x4A21008C)
#define L3_MAIN_Firewall_GPMC_FW_MRM_PERMISSION_REGION_LOW_1         *(Uint32 *)(0x4A210088)

void Init_L3_MAIN(void)
{



    return ;
}
