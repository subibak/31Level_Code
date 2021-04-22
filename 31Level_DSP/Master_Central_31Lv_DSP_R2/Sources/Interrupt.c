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

/*
#define SUM     1
#define SUB     2
#define MUL     3
#define DIV     4

float   mSum = 0.0, mSub, mMul = 0.0, mDiv = 0.0;
float   mA = 1.0, mB = 1.0;
Uint32  M_CASE = 0;
*/

interrupt void ISR_DSPTimer(void)
{
//    XF1_ON;
/*
    switch(M_CASE)
    {
        case SUM : XF1_ON; mSum = mA + mB; XF1_OFF; break;
        case SUB : XF1_ON; mSub = mA - mB; XF1_OFF; break;
        case MUL : XF1_ON; mMul = mA * mB; XF1_OFF; break;
        case DIV : XF1_ON; mDiv = mA / mB; XF1_OFF; break;
        default  : break;
    }
*/
//    XF1_OFF;
/*
    GPMC_BE0n_OFF;
//    CenLeg_WR_READY = 0x0000;

    ADC_OP();
    Sensor_Outside();
    Sensor_Inside();

//    MC_OP();
    fault();

    if(++INT_carrier_loop_cnt1 >= 5)
    {
        Flag_Out_Loop = 1;
        INT_carrier_loop_cnt1 =0;
    }
    else
        Flag_Out_Loop = 0;

    Mailbox_WR();
    Mailbox_RD();

    if(Flag_EcatReady == 1)
    {
//        GPMC_Leg_Central();
    }

//    GPMC_EtherCAT();

//    Operation();

    Ecat_Time_Compen();

    if(Flag_EcatReady == 1)
    {
        GPMC_BE0n_ON;
//        GPMC_Central_Leg();
    }

 //   Mode_Info_old.all = Mode_Info.all;
*/

    LED();
//    DAC();

    XF1_OFF;
	// Interrupt Clear.
    Timer5Regs.IRQSTATUS.all = IRQSTATUS_OVF_INT;
	DSP_ICFGRegs.EVTCLR2.bit.EVT67 = 1;
	ICR = M_INT5;
}
