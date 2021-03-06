/*
 * PRCM.c
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
*   Revised on: 2018. 11. 25.
*       Author: subi
 */

#include "Define_Header.h"
#include "Define_PRCM.h"

void Init_PRCM(void)
{

    // DSP.
	CM_CORE_AON__DSP1Regs.CM_DSP1_CLKSTCTRL.bit.CLKTRCTRL = 0x2;
	CM_CORE_AON__DSP1Regs.CM_DSP1_DSP1_CLKCTRL.bit.MODULEMODE = 0x1;
	while (CM_CORE_AON__DSP1Regs.CM_DSP1_DSP1_CLKCTRL.bit.IDLEST != 0);

	//GPMC
	CM_CORE__CORERegs.CM_L3MAIN1_GPMC_CLKCTRL.bit.MODULEMODE = 0x1;
	while (CM_CORE__CORERegs.CM_L3MAIN1_GPMC_CLKCTRL.bit.IDLEST != 0);

	// GPIO Clock.
	CM_CORE__L4PERRegs.CM_L4PER_GPIO2_CLKCTRL.all = CM_L4PER_GPIO_CLKCTRL_OPTFCLKEN_DBCLK_OptClkEn
                                                    | CM_L4PER_GPIO_CLKCTRL_MODULEMODE_ModuleEn;
	CM_CORE__L4PERRegs.CM_L4PER_GPIO3_CLKCTRL.all = CM_L4PER_GPIO_CLKCTRL_OPTFCLKEN_DBCLK_OptClkEn
													| CM_L4PER_GPIO_CLKCTRL_MODULEMODE_ModuleEn;
    CM_CORE__L4PERRegs.CM_L4PER_GPIO4_CLKCTRL.all = CM_L4PER_GPIO_CLKCTRL_OPTFCLKEN_DBCLK_OptClkEn
                                                    | CM_L4PER_GPIO_CLKCTRL_MODULEMODE_ModuleEn;
    CM_CORE__L4PERRegs.CM_L4PER_GPIO6_CLKCTRL.all = CM_L4PER_GPIO_CLKCTRL_OPTFCLKEN_DBCLK_OptClkEn
                                                    | CM_L4PER_GPIO_CLKCTRL_MODULEMODE_ModuleEn;
	CM_CORE__L4PERRegs.CM_L4PER_GPIO7_CLKCTRL.all = CM_L4PER_GPIO_CLKCTRL_OPTFCLKEN_DBCLK_OptClkEn
													| CM_L4PER_GPIO_CLKCTRL_MODULEMODE_ModuleEn;

	// Timer5 Clock.
	CM_CORE_AON__IPURegs.CM_IPU_TIMER5_CLKCTRL.all = CM_IPU_TIMER_CLKCTRL_CLKSEL_SYSCLK1
	                                                | CM_IPU_TIMER_CLKCTRL_MODULEMODE_ModuleEn;
	while (CM_CORE_AON__IPURegs.CM_IPU_TIMER5_CLKCTRL.bit.IDLEST != 0);


	//McSPI2 Clock.
	CM_CORE__L4PERRegs.CM_L4PER_MCSPI2_CLKCTRL.all = CM_L4PER_MCSPI_CLKCTRL_MODULEMODE_ModuleEn;
	while (CM_CORE__L4PERRegs.CM_L4PER_MCSPI2_CLKCTRL.bit.IDLEST != 0);


//	//Mailbox
	MAILBOX2Regs.MAILBOX_SYSCONFIG.bit.SOFTRESET = 0x1;
	while (MAILBOX2Regs.MAILBOX_SYSCONFIG.bit.SOFTRESET != 0x0);
	MAILBOX2Regs.MAILBOX_SYSCONFIG.bit.SIDLEMODE = 0x1;

    MAILBOX3Regs.MAILBOX_SYSCONFIG.bit.SOFTRESET = 0x1;
    while (MAILBOX3Regs.MAILBOX_SYSCONFIG.bit.SOFTRESET != 0x0);
    MAILBOX3Regs.MAILBOX_SYSCONFIG.bit.SIDLEMODE = 0x1;

    MAILBOX4Regs.MAILBOX_SYSCONFIG.bit.SOFTRESET = 0x1;
    while (MAILBOX4Regs.MAILBOX_SYSCONFIG.bit.SOFTRESET != 0x0);
    MAILBOX4Regs.MAILBOX_SYSCONFIG.bit.SIDLEMODE = 0x1;

	MAILBOX5Regs.MAILBOX_SYSCONFIG.bit.SOFTRESET = 0x1;
    while (MAILBOX5Regs.MAILBOX_SYSCONFIG.bit.SOFTRESET != 0x0);
    MAILBOX5Regs.MAILBOX_SYSCONFIG.bit.SIDLEMODE = 0x1;

    MAILBOX6Regs.MAILBOX_SYSCONFIG.bit.SOFTRESET = 0x1;
    while (MAILBOX6Regs.MAILBOX_SYSCONFIG.bit.SOFTRESET != 0x0);
    MAILBOX6Regs.MAILBOX_SYSCONFIG.bit.SIDLEMODE = 0x1;

    MAILBOX7Regs.MAILBOX_SYSCONFIG.bit.SOFTRESET = 0x1;
    while (MAILBOX7Regs.MAILBOX_SYSCONFIG.bit.SOFTRESET != 0x0);
    MAILBOX7Regs.MAILBOX_SYSCONFIG.bit.SIDLEMODE = 0x1;

	return;

}
