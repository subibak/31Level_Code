/*
 * Interrupt.c
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
*   Revised on:
*       author: subi
 */

#include "Define_Header.h"

Uint16 Flag_DO1 = 0, Flag_DO2 = 0, Flag_DO3 = 0, Flag_DO4 = 0;
Uint16 Flag_GPMC_BE1n = 0;
Uint16 Flag_EcatReady = 0;
Uint32 Flag_Ecat_DAQ_EN_CNT = 0;
Uint16 STATUS_ECAT_READY_L1 = 0;
Uint16 STATUS_ECAT_READY_L2 = 0;
Uint16 STATUS_ECAT_READY_L3 = 0;
Uint16 Flag_BE0n_test = 0;

int16 INT_carrier_loop_cnt1 = 0;
Uint16 Flag_Out_Loop = 0;
Uint32 CNT_BEn0 = 0;
#define CNT_BEn0_Timer  300000

interrupt void ISR_DSPTimer(void)
{
//    AL_test();
//    if(Measure_case == 1) XF1_ON;
//    GPMC_BE0n_OFF;
////    CenLeg_WR_READY = 0x0000;
//
//    ADC_OP();
//    if(Measure_case == 1) XF1_OFF;
//
//    if(Measure_case == 3) XF1_ON;
//    Sensor_Outside();
//    if(Measure_case == 3) XF1_OFF;
//
//    if(Measure_case == 4) XF1_ON;
//    Sensor_Inside();
//    if(Measure_case == 4) XF1_OFF;
//
//    if(Measure_case == 5) XF1_ON;
//    MC_OP();
//    if(Measure_case == 5) XF1_OFF;
//
//    if(Measure_case == 6) XF1_ON;
//    fault();
//    if(Measure_case == 6) XF1_OFF;
//
//
//    if(++INT_carrier_loop_cnt1 >= 5)
//    {
//        Flag_Out_Loop = 1;
//        INT_carrier_loop_cnt1 =0;
//    }
//    else
//        Flag_Out_Loop = 0;
//
//    if(Measure_case == 7) XF1_ON;
//    Mailbox_WR();
//    if(Measure_case == 7) XF1_OFF;
//
//    if(Measure_case == 8) XF1_ON;
//    Mailbox_RD();
//    if(Measure_case == 8) XF1_OFF;
//
////    if(Flag_EcatReady == 1)
////    {
//    if(Measure_case == 9) XF1_ON;
//        GPMC_Leg_Central();
//    if(Measure_case == 9) XF1_OFF;
//
////    }
//
//    if(Measure_case == 10) XF1_ON;
//    GPMC_EtherCAT();
//    if(Measure_case == 10) XF1_OFF;


    Operation();

//    if(Measure_case == 11) XF1_ON;
//    Ecat_Time_Compen();
//    if(Measure_case == 11) XF1_OFF;
//
////    if(Flag_EcatReady == 1)
////    {
//    if(Measure_case == 12) XF1_ON;
//        GPMC_BE0n_ON;
//        GPMC_Central_Leg();
//    if(Measure_case == 12) XF1_OFF;
//
////    }
//    if(Measure_case == 13) XF1_ON;
//    Mode_Info_old.all = Mode_Info.all;
//
//    HMI_CenMa_Matching();
//    if(Measure_case == 13) XF1_OFF;
//
//    if(Measure_case == 14) XF1_ON;
//    LED();
//    if(Measure_case == 14) XF1_OFF;
//
//    if(Measure_case == 15) XF1_ON;
//    DAC();
//    if(Measure_case == 15) XF1_OFF;


	// Interrupt Clear.
    Timer5Regs.IRQSTATUS.all = IRQSTATUS_OVF_INT;
	DSP_ICFGRegs.EVTCLR2.bit.EVT67 = 1;
	ICR = M_INT5;
}
