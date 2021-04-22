/*
 * GPMC.c
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#include "Define_Header.h"

struct CENTRAL_LEG_COMMON_DATA  CenLegComm;

union  CENTRAL_LEG_Operation_DATA CenLegOpData_Aupper;
union  CENTRAL_LEG_Operation_DATA CenLegOpData_Alower;
union  CENTRAL_LEG_Operation_DATA CenLegOpData_Bupper;
union  CENTRAL_LEG_Operation_DATA CenLegOpData_Blower;
union  CENTRAL_LEG_Operation_DATA CenLegOpData_Cupper;
union  CENTRAL_LEG_Operation_DATA CenLegOpData_Clower;

struct CENTRAL_LEG_Bypass CenLegBypass_A;
struct CENTRAL_LEG_Bypass CenLegBypass_B;
struct CENTRAL_LEG_Bypass CenLegBypass_C;

union SM_SUM_DATA    SmSumAU;
union SM_SUM_DATA    SmSumAL;
union SM_SUM_DATA    SmSumBU;
union SM_SUM_DATA    SmSumBL;
union SM_SUM_DATA    SmSumCU;
union SM_SUM_DATA    SmSumCL;

union SM_FAULT_DATA  SmFaultA;
union SM_FAULT_DATA  SmFaultB;
union SM_FAULT_DATA  SmFaultC;

int Flag_Ecat_EN = 0, Flag_DAQ_EN = 0;

void Init_GPMC(void)
{
	// GPMC Reset.
	GPMCRegs.GPMC_SYSCONFIG.bit.SOFTRESET = 1;
	while (GPMCRegs.GPMC_SYSSTATUS.bit.RESETDONE == 0);


    GPMCRegs.GPMC_CONFIG7_0.bit.CSVALID = 0;                    // 0(CS Disable), 1(CS Enable).
    GPMCRegs.GPMC_CONFIG7_1.bit.CSVALID = 0;                    // 0(CS Disable), 1(CS Enable).
    GPMCRegs.GPMC_CONFIG7_2.bit.CSVALID = 0;                    // 0(CS Disable), 1(CS Enable).
    GPMCRegs.GPMC_CONFIG7_3.bit.CSVALID = 0;                    // 0(CS Disable), 1(CS Enable).
    GPMCRegs.GPMC_CONFIG7_4.bit.CSVALID = 0;                    // 0(CS Disable), 1(CS Enable).
    GPMCRegs.GPMC_CONFIG7_5.bit.CSVALID = 0;                    // 0(CS Disable), 1(CS Enable).
    GPMCRegs.GPMC_CONFIG7_6.bit.CSVALID = 0;                    // 0(CS Disable), 1(CS Enable).
    GPMCRegs.GPMC_CONFIG7_7.bit.CSVALID = 0;                    // 0(CS Disable), 1(CS Enable).

	// CS0 Initialization.

    //Memory Type
    GPMCRegs.GPMC_CONFIG1_0.bit.DEVICETYPE = 0;                 // 0(NOR, Async, Sync), 2(NAND, Stream).
    GPMCRegs.GPMC_CONFIG1_0.bit.DEVICESIZE = 1;                 // 0(8-bit), 1(16-bit).
    GPMCRegs.GPMC_CONFIG1_0.bit.MUXADDATA = 0;                  // 0(Non-Multiplex), 1(AAD-Multiplex), 2(Add and Data Multiplex).
    GPMCRegs.GPMC_CONFIG1_0.bit.ATTACHEDDEVICEPAGELENGTH = 0;   // 0(4-Words), 1(8-Words), 2(16-Words).
    GPMCRegs.GPMC_CONFIG1_0.bit.WRAPBURST = 0;                  // 0(Sync Wrapping Burst not Support), 1(Sync Wrapping Burst Support).
    GPMCRegs.GPMC_CONFIG1_0.bit.TIMEPARAGRANULARITY = 0;        // 0(x1 Latencies), 1(x2 Latencies).
    GPMCRegs.GPMC_CONFIG1_0.bit.GPMCFCLKDIVIDER = 0;            // 0(/1), 1(/2), 2(/3), 3(/4) - GPMC_CLK = GPMC_FCLK / x.
    GPMCRegs.GPMC_CONFIG1_0.bit.CLKACTIVATIONTIME = 0;          // 0(0 Delay Start), 1(1 Delay Start), 2(2 Delay Start).
    GPMCRegs.GPMC_CONFIG1_0.bit.READMULTIPLE = 0;               // 0(Single Access), 1(Multiple Access).
    GPMCRegs.GPMC_CONFIG1_0.bit.READTYPE = 0;                   // 0(RD Async), 1(RD Sync).
    GPMCRegs.GPMC_CONFIG1_0.bit.WRITEMULTIPLE = 0;              // 0(Single Access), 1(Multiple Access).
    GPMCRegs.GPMC_CONFIG1_0.bit.WRITETYPE = 0;                  // 0(WR Async), 1(WR Sync).

    //Timing configuration
    GPMCRegs.GPMC_CONFIG1_0.bit.WAITMONITORINGTIME = 0;         // 0(Wait Signal with Valid Data), 1(Wait Signal 1 CLK before Valid Data), 2(Wait Signal 2 CLK before Valid Data)
    GPMCRegs.GPMC_CONFIG2_0.bit.CSWROFFTIME = 14;               // 0 ~ 31.
    GPMCRegs.GPMC_CONFIG2_0.bit.CSRDOFFTIME = 14;
    GPMCRegs.GPMC_CONFIG2_0.bit.CSEXTRADELAY = 0;               // 0(Not Delay), 1(0.5 Delay).
    GPMCRegs.GPMC_CONFIG2_0.bit.CSONTIME = 0;                   // 0 ~ 15(0 ~ 15 Delay CS Start).
    GPMCRegs.GPMC_CONFIG3_0.bit.ADVWROFFTIME = 3;               // 0 ~ 31.
    GPMCRegs.GPMC_CONFIG3_0.bit.ADVRDOFFTIME = 3;
    GPMCRegs.GPMC_CONFIG3_0.bit.ADVONTIME = 0;                  // 0 ~ 15(0 ~ 15 Delay ADV Start).
    GPMCRegs.GPMC_CONFIG3_0.bit.ADVEXTRADELAY = 0;              // 0(Not Delay), 1(0.5 Delay).
    GPMCRegs.GPMC_CONFIG4_0.bit.WEEXTRADELAY = 0;               // 0(Not Delay), 1(0.5 Delay).
    GPMCRegs.GPMC_CONFIG4_0.bit.WEONTIME = 4;                   // 0 ~ 31.
    GPMCRegs.GPMC_CONFIG4_0.bit.WEOFFTIME = 13;                 // 0 ~ 31.
    GPMCRegs.GPMC_CONFIG4_0.bit.OEEXTRADELAY = 0;
    GPMCRegs.GPMC_CONFIG4_0.bit.OEONTIME = 4;
    GPMCRegs.GPMC_CONFIG4_0.bit.OEOFFTIME = 13;
    GPMCRegs.GPMC_CONFIG5_0.bit.RDACCESSTIME = 14;
    GPMCRegs.GPMC_CONFIG5_0.bit.WRCYCLETIME = 15;               // 0 ~ 31.
    GPMCRegs.GPMC_CONFIG5_0.bit.RDCYCLETIME = 15;
    GPMCRegs.GPMC_CONFIG6_0.bit.WRACCESSTIME = 14;               // 0 ~ 31.
    GPMCRegs.GPMC_CONFIG6_0.bit.CYCLE2CYCLEDIFFCSEN = 1;        // 0(No Delay), 1(Add Delay).
    GPMCRegs.GPMC_CONFIG6_0.bit.CYCLE2CYCLESAMECSEN = 1;        // 0(No Delay), 1(Add Delay).
    GPMCRegs.GPMC_CONFIG6_0.bit.CYCLE2CYCLEDELAY = 1;           // 0 ~ 15.
    GPMCRegs.GPMC_CONFIG6_0.bit.BUSTURNAROUND = 2;              // 0 ~ 15.


	// CS3 Initialization.

	//Memory Type
	GPMCRegs.GPMC_CONFIG1_3.bit.DEVICETYPE = 0;                 // 0(NOR, Async, Sync), 2(NAND, Stream).
	GPMCRegs.GPMC_CONFIG1_3.bit.DEVICESIZE = 1;                 // 0(8-bit), 1(16-bit).
	GPMCRegs.GPMC_CONFIG1_3.bit.MUXADDATA = 0;                  // 0(Non-Multiplex), 1(AAD-Multiplex), 2(Add and Data Multiplex).
    GPMCRegs.GPMC_CONFIG1_3.bit.ATTACHEDDEVICEPAGELENGTH = 0;   // 0(4-Words), 1(8-Words), 2(16-Words).
    GPMCRegs.GPMC_CONFIG1_3.bit.WRAPBURST = 0;                  // 0(Sync Wrapping Burst not Support), 1(Sync Wrapping Burst Support).
    GPMCRegs.GPMC_CONFIG1_3.bit.TIMEPARAGRANULARITY = 0;        // 0(x1 Latencies), 1(x2 Latencies).
    GPMCRegs.GPMC_CONFIG1_3.bit.GPMCFCLKDIVIDER = 1;            // 0(/1), 1(/2), 2(/3), 3(/4) - GPMC_CLK = GPMC_FCLK / x.
    GPMCRegs.GPMC_CONFIG1_3.bit.CLKACTIVATIONTIME = 0;          // 0(0 Delay Start), 1(1 Delay Start), 2(2 Delay Start).
    GPMCRegs.GPMC_CONFIG1_3.bit.READMULTIPLE = 0;               // 0(Single Access), 1(Multiple Access).
    GPMCRegs.GPMC_CONFIG1_3.bit.READTYPE = 0;                   // 0(RD Async), 1(RD Sync).
    GPMCRegs.GPMC_CONFIG1_3.bit.WRITEMULTIPLE = 0;              // 0(Single Access), 1(Multiple Access).
    GPMCRegs.GPMC_CONFIG1_3.bit.WRITETYPE = 0;                  // 0(WR Async), 1(WR Sync).

    //Timing configuration
    GPMCRegs.GPMC_CONFIG1_3.bit.WAITMONITORINGTIME = 0;         // 0(Wait Signal with Valid Data), 1(Wait Signal 1 CLK before Valid Data), 2(Wait Signal 2 CLK before Valid Data)
    GPMCRegs.GPMC_CONFIG2_3.bit.CSWROFFTIME = 30;               // 0 ~ 31.
    GPMCRegs.GPMC_CONFIG2_3.bit.CSRDOFFTIME = 30;
    GPMCRegs.GPMC_CONFIG2_3.bit.CSEXTRADELAY = 0;               // 0(Not Delay), 1(0.5 Delay).
    GPMCRegs.GPMC_CONFIG2_3.bit.CSONTIME = 0;                   // 0 ~ 15(0 ~ 15 Delay CS Start).
    GPMCRegs.GPMC_CONFIG3_3.bit.ADVWROFFTIME = 3;               // 0 ~ 31.
    GPMCRegs.GPMC_CONFIG3_3.bit.ADVRDOFFTIME = 3;
    GPMCRegs.GPMC_CONFIG3_3.bit.ADVONTIME = 0;                  // 0 ~ 15(0 ~ 15 Delay ADV Start).
    GPMCRegs.GPMC_CONFIG3_3.bit.ADVEXTRADELAY = 0;              // 0(Not Delay), 1(0.5 Delay).
    GPMCRegs.GPMC_CONFIG4_3.bit.WEEXTRADELAY = 0;               // 0(Not Delay), 1(0.5 Delay).
    GPMCRegs.GPMC_CONFIG4_3.bit.WEONTIME = 4;                   // 0 ~ 31.
    GPMCRegs.GPMC_CONFIG4_3.bit.WEOFFTIME = 28;                 // 0 ~ 31.
    GPMCRegs.GPMC_CONFIG4_3.bit.OEEXTRADELAY = 0;
    GPMCRegs.GPMC_CONFIG4_3.bit.OEONTIME = 4;
    GPMCRegs.GPMC_CONFIG4_3.bit.OEOFFTIME = 28;
    GPMCRegs.GPMC_CONFIG5_3.bit.RDACCESSTIME = 25;
    GPMCRegs.GPMC_CONFIG5_3.bit.WRCYCLETIME = 31;               // 0 ~ 31.
    GPMCRegs.GPMC_CONFIG5_3.bit.RDCYCLETIME = 31;
    GPMCRegs.GPMC_CONFIG6_3.bit.WRACCESSTIME = 25;              // 0 ~ 31.
    GPMCRegs.GPMC_CONFIG6_3.bit.CYCLE2CYCLEDIFFCSEN = 1;        // 0(No Delay), 1(Add Delay).
    GPMCRegs.GPMC_CONFIG6_3.bit.CYCLE2CYCLESAMECSEN = 1;        // 0(No Delay), 1(Add Delay).
    GPMCRegs.GPMC_CONFIG6_3.bit.CYCLE2CYCLEDELAY = 2;           // 0 ~ 15.
    GPMCRegs.GPMC_CONFIG6_3.bit.BUSTURNAROUND = 2;              // 0 ~ 15.


    //Chip-Select Configuration
    GPMCRegs.GPMC_CONFIG7_0.bit.BASEADDRESS = 0b010100;         // A29 ~ A24 Address.  0x1400 0000
    GPMCRegs.GPMC_CONFIG7_0.bit.MASKADDRESS = 0b1111;           // A27 ~ A24 Mask. 0(256MB Mode), 8(128MB Mode), 12(64MB Mode), 14(32MB Mode), 15(16MB Mode).
    GPMCRegs.GPMC_CONFIG7_1.bit.BASEADDRESS = 0b010101;         // A29 ~ A24 Address.  0x1500 0000
    GPMCRegs.GPMC_CONFIG7_1.bit.MASKADDRESS = 0b1111;           // A27 ~ A24 Mask. 0(256MB Mode), 8(128MB Mode), 12(64MB Mode), 14(32MB Mode), 15(16MB Mode).
    GPMCRegs.GPMC_CONFIG7_2.bit.BASEADDRESS = 0b010110;         // A29 ~ A24 Address.  0x1600 0000
    GPMCRegs.GPMC_CONFIG7_2.bit.MASKADDRESS = 0b1111;           // A27 ~ A24 Mask. 0(256MB Mode), 8(128MB Mode), 12(64MB Mode), 14(32MB Mode), 15(16MB Mode).
    GPMCRegs.GPMC_CONFIG7_3.bit.BASEADDRESS = 0b010111;         // A29 ~ A24 Address.  0x1700 0000
    GPMCRegs.GPMC_CONFIG7_3.bit.MASKADDRESS = 0b1111;           // A27 ~ A24 Mask. 0(256MB Mode), 8(128MB Mode), 12(64MB Mode), 14(32MB Mode), 15(16MB Mode).
    GPMCRegs.GPMC_CONFIG7_4.bit.BASEADDRESS = 0b011000;         // A29 ~ A24 Address.  0x1800 0000
    GPMCRegs.GPMC_CONFIG7_4.bit.MASKADDRESS = 0b1111;           // A27 ~ A24 Mask. 0(256MB Mode), 8(128MB Mode), 12(64MB Mode), 14(32MB Mode), 15(16MB Mode).
    GPMCRegs.GPMC_CONFIG7_5.bit.BASEADDRESS = 0b011001;         // A29 ~ A24 Address.  0x1900 0000
    GPMCRegs.GPMC_CONFIG7_5.bit.MASKADDRESS = 0b1111;           // A27 ~ A24 Mask. 0(256MB Mode), 8(128MB Mode), 12(64MB Mode), 14(32MB Mode), 15(16MB Mode).
    GPMCRegs.GPMC_CONFIG7_6.bit.BASEADDRESS = 0b011010;         // A29 ~ A24 Address.  0x1A00 0000
    GPMCRegs.GPMC_CONFIG7_6.bit.MASKADDRESS = 0b1111;           // A27 ~ A24 Mask. 0(256MB Mode), 8(128MB Mode), 12(64MB Mode), 14(32MB Mode), 15(16MB Mode).
    GPMCRegs.GPMC_CONFIG7_7.bit.BASEADDRESS = 0b011011;         // A29 ~ A24 Address.  0x1B00 0000
    GPMCRegs.GPMC_CONFIG7_7.bit.MASKADDRESS = 0b1111;           // A27 ~ A24 Mask. 0(256MB Mode), 8(128MB Mode), 12(64MB Mode), 14(32MB Mode), 15(16MB Mode).

    //Enable Chip-Select
    GPMCRegs.GPMC_CONFIG7_0.bit.CSVALID = 1;                    // 0(CS Disable), 1(CS Enable).
    GPMCRegs.GPMC_CONFIG7_1.bit.CSVALID = 0;                    // 0(CS Disable), 1(CS Enable).
    GPMCRegs.GPMC_CONFIG7_3.bit.CSVALID = 1;                    // 0(CS Disable), 1(CS Enable).
    GPMCRegs.GPMC_CONFIG7_2.bit.CSVALID = 0;                    // 0(CS Disable), 1(CS Enable).
    GPMCRegs.GPMC_CONFIG7_4.bit.CSVALID = 0;                    // 0(CS Disable), 1(CS Enable).
    GPMCRegs.GPMC_CONFIG7_5.bit.CSVALID = 0;                    // 0(CS Disable), 1(CS Enable).
    GPMCRegs.GPMC_CONFIG7_6.bit.CSVALID = 0;                    // 0(CS Disable), 1(CS Enable).
    GPMCRegs.GPMC_CONFIG7_7.bit.CSVALID = 0;                    // 0(CS Disable), 1(CS Enable).

    return;
}

void GPMC_EtherCAT(void){

    STATUS_ECAT_READY_L1 = ECAT_READY_L1;
    STATUS_ECAT_READY_L2 = ECAT_READY_L2;
    STATUS_ECAT_READY_L3 = ECAT_READY_L3;

    if((STATUS_ECAT_READY_L1 == 0x3FFF) & (STATUS_ECAT_READY_L2 == 0x3FFF) & (STATUS_ECAT_READY_L3 == 0x3FFF)) Flag_EcatReady = 1;
    else Flag_EcatReady = 0;

    if(Flag_EcatReady == 1)
    {
        CenLeg_Com_ECAT_START = 0x3FFF;

        if(Flag_Ecat_DAQ_EN_CNT++ > ECAT_DAQ_EN_MAX)
        {
           CenLegOpData_Aupper.bit.EtherCAT_Ready = 1;             // EtherCAT Ready
           CenLegOpData_Aupper.bit.DAQ_READY = 1;                  // DAQ_TX Enable
           CenLegOpData_Alower.bit.EtherCAT_Ready = 1;             // EtherCAT Ready
           CenLegOpData_Alower.bit.DAQ_READY = 1;                  // DAQ_TX Enable

           CenLegOpData_Bupper.bit.EtherCAT_Ready = 1;             // EtherCAT Ready
           CenLegOpData_Bupper.bit.DAQ_READY = 1;                  // DAQ_TX Enable
           CenLegOpData_Blower.bit.EtherCAT_Ready = 1;             // EtherCAT Ready
           CenLegOpData_Blower.bit.DAQ_READY = 1;                  // DAQ_TX Enable

           CenLegOpData_Cupper.bit.EtherCAT_Ready = 1;             // EtherCAT Ready
           CenLegOpData_Cupper.bit.DAQ_READY = 1;                  // DAQ_TX Enable
           CenLegOpData_Clower.bit.EtherCAT_Ready = 1;             // EtherCAT Ready
           CenLegOpData_Clower.bit.DAQ_READY = 1;                  // DAQ_TX Enable
        }
    }

    return;
}


Uint16 Flag_Ecat_TEST = 0;
Uint16 REF_t[40];

void GPMC_Central_Leg(void)
{
    //DATA Arrangement. Now it's for test
    CenLegOpData_Aupper.bit.Flag_Operation = Flag_gating;
    CenLegOpData_Alower.bit.Flag_Operation = Flag_gating;
    CenLegOpData_Bupper.bit.Flag_Operation = Flag_gating;
    CenLegOpData_Blower.bit.Flag_Operation = Flag_gating;
    CenLegOpData_Cupper.bit.Flag_Operation = Flag_gating;
    CenLegOpData_Clower.bit.Flag_Operation = Flag_gating;

    CenLeg_Com_STATUS = CenLegComm.STATUS.all;
    CenLeg_Com_SM_VOL_UNDER_LIMIT = CenLegComm.SM_Vol_Under_Limit;
    CenLeg_Com_SM_VOL_OVER_LIMIT = CenLegComm.SM_Vol_Over_Limit;
    CenLeg_Com_SM_TEMP_LIMIT = CenLegComm.SM_Temp_Limit;
    CenLeg_Com_SLAVE_OP_MODE = CenLegComm.Slave_OP_Mode.all;
    CenLeg_Com_FLASH_MSB = CenLegComm.FLASH_MSB;
    CenLeg_Com_FLASH_LSB = CenLegComm.FLASH_LSB;

    CenLeg_Com_DIFF_TIME_LSB = DiffTime.bit.LSB;
    CenLeg_Com_DIFF_TIME_MSB = DiffTime.bit.MSB;

    CenLeg_OP_DATA_A_UPPER = CenLegOpData_Aupper.all;
    CenLeg_OP_DATA_A_LOWER = CenLegOpData_Alower.all;

    CenLeg_OP_DATA_B_UPPER = CenLegOpData_Bupper.all;
    CenLeg_OP_DATA_B_LOWER = CenLegOpData_Blower.all;

    CenLeg_OP_DATA_C_UPPER = CenLegOpData_Cupper.all;
    CenLeg_OP_DATA_C_LOWER = CenLegOpData_Clower.all;

//    CenLeg_REF_Group_AU1 = SMua_g[0];//REF_t[0];
//    CenLeg_REF_Group_AU2 = SMua_g[1];//REF_t[1];
//    CenLeg_REF_Group_AU3 = SMua_g[2];//REF_t[2];
//    CenLeg_REF_Group_AU4 = SMua_g[3];//REF_t[3];
//    CenLeg_REF_Group_AU5 = SMua_g[4];//REF_t[4];
//    CenLeg_REF_Group_AL1 = SMla_g[0];//REF_t[5];
//    CenLeg_REF_Group_AL2 = SMla_g[1];//REF_t[6];
//    CenLeg_REF_Group_AL3 = SMla_g[2];//REF_t[7];
//    CenLeg_REF_Group_AL4 = SMla_g[3];//REF_t[8];
//    CenLeg_REF_Group_AL5 = SMla_g[4];//REF_t[9];

//    CenLeg_REF_Group_BU1 = SMub_g[0];//REF_t[0];
//    CenLeg_REF_Group_BU2 = SMub_g[1];//REF_t[1];
//    CenLeg_REF_Group_BU3 = SMub_g[2];//REF_t[2];
//    CenLeg_REF_Group_BU4 = SMub_g[3];//REF_t[3];
//    CenLeg_REF_Group_BU5 = SMub_g[4];//REF_t[4];
//    CenLeg_REF_Group_BL1 = SMlb_g[0];//REF_t[5];
//    CenLeg_REF_Group_BL2 = SMlb_g[1];//REF_t[6];
//    CenLeg_REF_Group_BL3 = SMlb_g[2];//REF_t[7];
//    CenLeg_REF_Group_BL4 = SMlb_g[3];//REF_t[8];
//    CenLeg_REF_Group_BL5 = SMlb_g[4];//REF_t[9];

//    CenLeg_REF_Group_CU1 = SMuc_g[0];//REF_t[0];
//    CenLeg_REF_Group_CU2 = SMuc_g[1];//REF_t[1];
//    CenLeg_REF_Group_CU3 = SMuc_g[2];//REF_t[2];
//    CenLeg_REF_Group_CU4 = SMuc_g[3];//REF_t[3];
//    CenLeg_REF_Group_CU5 = SMuc_g[4];//REF_t[4];
//    CenLeg_REF_Group_CL1 = SMlc_g[0];//REF_t[5];
//    CenLeg_REF_Group_CL2 = SMlc_g[1];//REF_t[6];
//    CenLeg_REF_Group_CL3 = SMlc_g[2];//REF_t[7];
//    CenLeg_REF_Group_CL4 = SMlc_g[3];//REF_t[8];
//    CenLeg_REF_Group_CL5 = SMlc_g[4];//REF_t[9];

//    CenLeg_REF_AU_LSB = NLC_REF_AU.bit.LSB;
//    CenLeg_REF_AU_MSB = NLC_REF_AU.bit.MSB;
//    CenLeg_REF_AL_LSB = NLC_REF_AL.bit.LSB;
//    CenLeg_REF_AL_MSB = NLC_REF_AL.bit.MSB;
//
//    CenLeg_REF_BU_LSB = NLC_REF_BU.bit.LSB;
//    CenLeg_REF_BU_MSB = NLC_REF_BU.bit.MSB;
//    CenLeg_REF_BL_LSB = NLC_REF_BL.bit.LSB;
//    CenLeg_REF_BL_MSB = NLC_REF_BL.bit.MSB;
//
//    CenLeg_REF_CU_LSB = NLC_REF_CU.bit.LSB;
//    CenLeg_REF_CU_MSB = NLC_REF_CU.bit.MSB;
//    CenLeg_REF_CL_LSB = NLC_REF_CL.bit.LSB;
//    CenLeg_REF_CL_MSB = NLC_REF_CL.bit.MSB;

    CenLeg_REF_AU_LSB = NLC_REF_AU.bit.LSB;
    CenLeg_REF_AL_LSB = NLC_REF_AL.bit.LSB;

    CenLeg_REF_BU_LSB = NLC_REF_BU.bit.LSB;
    CenLeg_REF_BL_LSB = NLC_REF_BL.bit.LSB;

    CenLeg_REF_CU_LSB = NLC_REF_CU.bit.LSB;
    CenLeg_REF_CL_LSB = NLC_REF_CL.bit.LSB;

    CenLeg_BYPASS_Group_AU1 = CenLegBypass_A.Upper1.all;
    CenLeg_BYPASS_Group_AU2 = CenLegBypass_A.Upper2.all;
    CenLeg_BYPASS_Group_AU3 = CenLegBypass_A.Upper3.all;
    CenLeg_BYPASS_Group_AU4 = CenLegBypass_A.Upper4.all;
    CenLeg_BYPASS_Group_AU5 = CenLegBypass_A.Upper5.all;
    CenLeg_BYPASS_Group_AL1 = CenLegBypass_A.Lower1.all;
    CenLeg_BYPASS_Group_AL2 = CenLegBypass_A.Lower2.all;
    CenLeg_BYPASS_Group_AL3 = CenLegBypass_A.Lower3.all;
    CenLeg_BYPASS_Group_AL4 = CenLegBypass_A.Lower4.all;
    CenLeg_BYPASS_Group_AL5 = CenLegBypass_A.Lower5.all;

    CenLeg_BYPASS_Group_AU1 = CenLegBypass_B.Upper1.all;
    CenLeg_BYPASS_Group_AU2 = CenLegBypass_B.Upper2.all;
    CenLeg_BYPASS_Group_AU3 = CenLegBypass_B.Upper3.all;
    CenLeg_BYPASS_Group_AU4 = CenLegBypass_B.Upper4.all;
    CenLeg_BYPASS_Group_AU5 = CenLegBypass_B.Upper5.all;
    CenLeg_BYPASS_Group_AL1 = CenLegBypass_B.Lower1.all;
    CenLeg_BYPASS_Group_AL2 = CenLegBypass_B.Lower2.all;
    CenLeg_BYPASS_Group_AL3 = CenLegBypass_B.Lower3.all;
    CenLeg_BYPASS_Group_AL4 = CenLegBypass_B.Lower4.all;
    CenLeg_BYPASS_Group_AL5 = CenLegBypass_B.Lower5.all;

    CenLeg_BYPASS_Group_AU1 = CenLegBypass_C.Upper1.all;
    CenLeg_BYPASS_Group_AU2 = CenLegBypass_C.Upper2.all;
    CenLeg_BYPASS_Group_AU3 = CenLegBypass_C.Upper3.all;
    CenLeg_BYPASS_Group_AU4 = CenLegBypass_C.Upper4.all;
    CenLeg_BYPASS_Group_AU5 = CenLegBypass_C.Upper5.all;
    CenLeg_BYPASS_Group_AL1 = CenLegBypass_C.Lower1.all;
    CenLeg_BYPASS_Group_AL2 = CenLegBypass_C.Lower2.all;
    CenLeg_BYPASS_Group_AL3 = CenLegBypass_C.Lower3.all;
    CenLeg_BYPASS_Group_AL4 = CenLegBypass_C.Lower4.all;
    CenLeg_BYPASS_Group_AL5 = CenLegBypass_C.Lower5.all;

    GPMC_BE0n_ON;
}

void GPMC_Leg_Central(void)
{
//    static Uint16 k = 0;
    static Uint16 GPMC_START_CNT = 0;

    XF2_ON;
    if(GPMC_START_CNT++ > GPMC_START_TIMER)  while(GPMC_BE1n == 0);
    XF2_OFF;
//    SmSumAU[0].bit.LSB = SM_SUM_GROUP_AU1_LSB;
//    SmSumAU[0].bit.MSB = SM_SUM_GROUP_AU1_MSB;
//    SmSumAU[1].bit.LSB = SM_SUM_GROUP_AU2_LSB;
//    SmSumAU[1].bit.MSB = SM_SUM_GROUP_AU2_MSB;
//    SmSumAU[2].bit.LSB = SM_SUM_GROUP_AU3_LSB;
//    SmSumAU[2].bit.MSB = SM_SUM_GROUP_AU3_MSB;
//    SmSumAU[3].bit.LSB = SM_SUM_GROUP_AU4_LSB;
//    SmSumAU[3].bit.MSB = SM_SUM_GROUP_AU4_MSB;
//    SmSumAU[4].bit.LSB = SM_SUM_GROUP_AU5_LSB;
//    SmSumAU[4].bit.MSB = SM_SUM_GROUP_AU5_MSB;
//
//    SmSumAL[0].bit.LSB = SM_SUM_GROUP_AL1_LSB;
//    SmSumAL[0].bit.MSB = SM_SUM_GROUP_AL1_MSB;
//    SmSumAL[1].bit.LSB = SM_SUM_GROUP_AL2_LSB;
//    SmSumAL[1].bit.MSB = SM_SUM_GROUP_AL2_MSB;
//    SmSumAL[2].bit.LSB = SM_SUM_GROUP_AL3_LSB;
//    SmSumAL[2].bit.MSB = SM_SUM_GROUP_AL3_MSB;
//    SmSumAL[3].bit.LSB = SM_SUM_GROUP_AL4_LSB;
//    SmSumAL[3].bit.MSB = SM_SUM_GROUP_AL4_MSB;
//    SmSumAL[4].bit.LSB = SM_SUM_GROUP_AL5_LSB;
//    SmSumAL[4].bit.MSB = SM_SUM_GROUP_AL5_MSB;
//
//    SmSumBU[0].bit.LSB = SM_SUM_GROUP_BU1_LSB;
//    SmSumBU[0].bit.MSB = SM_SUM_GROUP_BU1_MSB;
//    SmSumBU[1].bit.LSB = SM_SUM_GROUP_BU2_LSB;
//    SmSumBU[1].bit.MSB = SM_SUM_GROUP_BU2_MSB;
//    SmSumBU[2].bit.LSB = SM_SUM_GROUP_BU3_LSB;
//    SmSumBU[2].bit.MSB = SM_SUM_GROUP_BU3_MSB;
//    SmSumBU[3].bit.LSB = SM_SUM_GROUP_BU4_LSB;
//    SmSumBU[3].bit.MSB = SM_SUM_GROUP_BU4_MSB;
//    SmSumBU[4].bit.LSB = SM_SUM_GROUP_BU5_LSB;
//    SmSumBU[4].bit.MSB = SM_SUM_GROUP_BU5_MSB;
//
//    SmSumBL[0].bit.LSB = SM_SUM_GROUP_BL1_LSB;
//    SmSumBL[0].bit.MSB = SM_SUM_GROUP_BL1_MSB;
//    SmSumBL[1].bit.LSB = SM_SUM_GROUP_BL2_LSB;
//    SmSumBL[1].bit.MSB = SM_SUM_GROUP_BL2_MSB;
//    SmSumBL[2].bit.LSB = SM_SUM_GROUP_BL3_LSB;
//    SmSumBL[2].bit.MSB = SM_SUM_GROUP_BL3_MSB;
//    SmSumBL[3].bit.LSB = SM_SUM_GROUP_BL4_LSB;
//    SmSumBL[3].bit.MSB = SM_SUM_GROUP_BL4_MSB;
//    SmSumBL[4].bit.LSB = SM_SUM_GROUP_BL5_LSB;
//    SmSumBL[4].bit.MSB = SM_SUM_GROUP_BL5_MSB;
//
//    SmSumCU[0].bit.LSB = SM_SUM_GROUP_CU1_LSB;
//    SmSumCU[0].bit.MSB = SM_SUM_GROUP_CU1_MSB;
//    SmSumCU[1].bit.LSB = SM_SUM_GROUP_CU2_LSB;
//    SmSumCU[1].bit.MSB = SM_SUM_GROUP_CU2_MSB;
//    SmSumCU[2].bit.LSB = SM_SUM_GROUP_CU3_LSB;
//    SmSumCU[2].bit.MSB = SM_SUM_GROUP_CU3_MSB;
//    SmSumCU[3].bit.LSB = SM_SUM_GROUP_CU4_LSB;
//    SmSumCU[3].bit.MSB = SM_SUM_GROUP_CU4_MSB;
//    SmSumCU[4].bit.LSB = SM_SUM_GROUP_CU5_LSB;
//    SmSumCU[4].bit.MSB = SM_SUM_GROUP_CU5_MSB;
//
//    SmSumCL[0].bit.LSB = SM_SUM_GROUP_CL1_LSB;
//    SmSumCL[0].bit.MSB = SM_SUM_GROUP_CL1_MSB;
//    SmSumCL[1].bit.LSB = SM_SUM_GROUP_CL2_LSB;
//    SmSumCL[1].bit.MSB = SM_SUM_GROUP_CL2_MSB;
//    SmSumCL[2].bit.LSB = SM_SUM_GROUP_CL3_LSB;
//    SmSumCL[2].bit.MSB = SM_SUM_GROUP_CL3_MSB;
//    SmSumCL[3].bit.LSB = SM_SUM_GROUP_CL4_LSB;
//    SmSumCL[3].bit.MSB = SM_SUM_GROUP_CL4_MSB;
//    SmSumCL[4].bit.LSB = SM_SUM_GROUP_CL5_LSB;
//    SmSumCL[4].bit.MSB = SM_SUM_GROUP_CL5_MSB;

    SmSumAU.bit.LSB = SM_SUM_GROUP_AU_LSB;
    SmSumAU.bit.MSB = SM_SUM_GROUP_AU_MSB;
    SmSumAL.bit.LSB = SM_SUM_GROUP_AL_LSB;
    SmSumAL.bit.MSB = SM_SUM_GROUP_AL_MSB;

    SmSumBU.bit.LSB = SM_SUM_GROUP_BU_LSB;
    SmSumBU.bit.MSB = SM_SUM_GROUP_BU_MSB;
    SmSumBL.bit.LSB = SM_SUM_GROUP_BL_LSB;
    SmSumBL.bit.MSB = SM_SUM_GROUP_BL_MSB;

    SmSumCU.bit.LSB = SM_SUM_GROUP_CU_LSB;
    SmSumCU.bit.MSB = SM_SUM_GROUP_CU_MSB;
    SmSumCL.bit.LSB = SM_SUM_GROUP_CL_LSB;
    SmSumCL.bit.MSB = SM_SUM_GROUP_CL_MSB;

    SmFaultA.bit.COM_VOL.bit.Communication = SM_FAULT_A_COM;
    SmFaultA.bit.COM_VOL.bit.SM_VOLATGE    = SM_FAULT_A_VOL;
    SmFaultA.bit.COM_VOL.all               = SM_FAULT_A_TEM;

    SmFaultB.bit.COM_VOL.bit.Communication = SM_FAULT_B_COM;
    SmFaultB.bit.COM_VOL.bit.SM_VOLATGE    = SM_FAULT_B_VOL;
    SmFaultB.bit.COM_VOL.all               = SM_FAULT_B_TEM;

    SmFaultC.bit.COM_VOL.bit.Communication = SM_FAULT_C_COM;
    SmFaultC.bit.COM_VOL.bit.SM_VOLATGE    = SM_FAULT_C_VOL;
    SmFaultC.bit.TEMPERATURE               = SM_FAULT_C_TEM;

//    for(k = 0; k < 5; k++){
//        V_AU[k] =(float)(SmSumAU[k].all_F);
//        V_AL[k] =(float)(SmSumAL[k].all_F);
//        V_BU[k] =(float)(SmSumBU[k].all_F);
//        V_BL[k] =(float)(SmSumBL[k].all_F);
//        V_CU[k] =(float)(SmSumCU[k].all_F);
//        V_CL[k] =(float)(SmSumCL[k].all_F);
//    }
}

void Para_Init(void)
{
    CenLegComm.SM_Vol_Over_Limit =70;
    CenLegComm.SM_Temp_Limit = 20;

 //   CenLegComm.Slave_OP_Mode.bit.OP_Mode = 1;

    Mode_Info.bit.Valve_type = 1;                   // Inverter or Converter
    Mode_Info.bit.Control_Method = 1;               // Direct or Indirect

//    Flag_CCSC = 1;
}
