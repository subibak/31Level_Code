/*
 * AM572x_C66_GlobarVariableDefs.c
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#include "AM572x_C66_device.h"

#ifdef __cplusplus
#pragma DATA_SECTION("IntCtrlRegsFile");
#else
#pragma DATA_SECTION(DSP_ICFGRegs, "DSP_ICFGRegsFile");
#endif
volatile struct DSP_ICFG_REGS			DSP_ICFGRegs;

#ifdef __cplusplus
#pragma DATA_SETCTION("Timer5RegsFile");
#else
#pragma DATA_SECTION(Timer5Regs, "Timer5RegsFile");
#endif
volatile struct TIMER_REGS              Timer5Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("GPIO1RegsFile");
#else
#pragma DATA_SECTION(GPIO1Regs, "GPIO1RegsFile");
#endif
volatile struct GPIO_REGS				GPIO1Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("GPIO2RegsFile");
#else
#pragma DATA_SECTION(GPIO2Regs, "GPIO2RegsFile");
#endif
volatile struct GPIO_REGS				GPIO2Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("GPIO3RegsFile");
#else
#pragma DATA_SECTION(GPIO3Regs, "GPIO3RegsFile");
#endif
volatile struct GPIO_REGS				GPIO3Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("GPIO4RegsFile");
#else
#pragma DATA_SECTION(GPIO4Regs, "GPIO4RegsFile");
#endif
volatile struct GPIO_REGS				GPIO4Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("GPIO5RegsFile");
#else
#pragma DATA_SECTION(GPIO5Regs, "GPIO5RegsFile");
#endif
volatile struct GPIO_REGS				GPIO5Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("GPIO6RegsFile");
#else
#pragma DATA_SECTION(GPIO6Regs, "GPIO6RegsFile");
#endif
volatile struct GPIO_REGS				GPIO6Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("GPIO7RegsFile");
#else
#pragma DATA_SECTION(GPIO7Regs, "GPIO7RegsFile");
#endif
volatile struct GPIO_REGS				GPIO7Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("GPIO8RegsFile");
#else
#pragma DATA_SECTION(GPIO8Regs, "GPIO8RegsFile");
#endif
volatile struct GPIO_REGS				GPIO8Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("CM_CORE_AON__DSP1RegsFile");
#else
#pragma DATA_SECTION(CM_CORE_AON__DSP1Regs, "CM_CORE_AON__DSP1RegsFile");
#endif
volatile struct CM_CORE_AON__DSP1_REGS	CM_CORE_AON__DSP1Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("CM_CORE__CORERegsFile");
#else
#pragma DATA_SECTION(CM_CORE__CORERegs, "CM_CORE__CORERegsFile");
#endif
volatile struct CM_CORE__CORE_REGS		CM_CORE__CORERegs;

#ifdef __cplusplus
#pragma DATA_SECTION("CM_CORE_L4PERRegsFile");
#else
#pragma DATA_SECTION(CM_CORE__L4PERRegs, "CM_CORE__L4PERRegsFile");
#endif
volatile struct CM_CORE__L4PER_REGS		CM_CORE__L4PERRegs;

#ifdef __cplusplus
#pragma DATA_SECTION("CM_CORE_AON__IPURegsFile");
#else
#pragma DATA_SECTION(CM_CORE_AON__IPURegs, "CM_CORE_AON__IPURegsFile");
#endif

volatile struct CM_CORE_AON__IPU_REGS    CM_CORE_AON__IPURegs;

#ifdef __cplusplus
#pragma DATA_SECTION("GPMCRegsFile");
#else
#pragma DATA_SECTION(GPMCRegs, "GPMCRegsFile");
#endif
volatile struct GPMC_REGS	GPMCRegs;

#ifdef __cpluscplus
#pragma DATA_SECTION("McSPI2RegsFile");
#else
#pragma DATA_SECTION(McSPI2Regs, "McSPI2RegsFile");
#endif
volatile struct McSPI_REG   McSPI2Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("MAILBOX2RegsFile");
#else
#pragma DATA_SECTION(MAILBOX2Regs, "MAILBOX2RegsFile");
#endif
volatile struct MAILBOX_REGS    MAILBOX2Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("MAILBOX3RegsFile");
#else
#pragma DATA_SECTION(MAILBOX3Regs, "MAILBOX3RegsFile");
#endif
volatile struct MAILBOX_REGS    MAILBOX3Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("MAILBOX4RegsFile");
#else
#pragma DATA_SECTION(MAILBOX4Regs, "MAILBOX4RegsFile");
#endif
volatile struct MAILBOX_REGS    MAILBOX4Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("MAILBOX5RegsFile");
#else
#pragma DATA_SECTION(MAILBOX5Regs, "MAILBOX5RegsFile");
#endif
volatile struct MAILBOX_REGS    MAILBOX5Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("MAILBOX6RegsFile");
#else
#pragma DATA_SECTION(MAILBOX6Regs, "MAILBOX6RegsFile");
#endif
volatile struct MAILBOX_REGS    MAILBOX6Regs;

#ifdef __cplusplus
#pragma DATA_SECTION("MAILBOX7RegsFile");
#else
#pragma DATA_SECTION(MAILBOX7Regs, "MAILBOX7RegsFile");
#endif
volatile struct MAILBOX_REGS    MAILBOX7Regs;

//#ifdef __cplusplus
//#pragma DATA_SECTION("CenLegCommFile");
//#else
//#pragma DATA_SECTION(CenLegComm, "CenLegCommFile");
//#endif
//volatile struct CENTRAL_LEG_COMMON_DATA  CenLegComm;
//
//#ifdef __cplusplus
//#pragma DATA_SECTION("LegCentralMasterFile");
//#else
//#pragma DATA_SECTION(LegCentralMaster, "LegCentralMasterFile");
//#endif
//volatile struct LEG_TO_CENTRAL_MASTER LegCentralMaster;

