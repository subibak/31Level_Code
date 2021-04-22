/*
 * Interrupt.c
 *
 *  Created on: 2018. 9. 29.
 *      Author: subi
 */


#include "Define_Header.h"

int l = 0, m=0, k = 0, i = 0, j = 0, t = 0;

int Number_SM = 6;
int D_Number_SM = 12;
int H_Number_SM = 3;

//0xab a = U,V,W or R,S,T  b = 1~10
Uint16 Group_number = 0x13;

Uint16 REF_MIN =0, REF_MAX = 0;
Uint16 HALF_CNT = 0;

int Flag_PWM_INIT = 0;

Uint16 msg_test_wr[10];
Uint16 msg_test_rd[10];

float Temp_old = 0;
int Flag_ADC_init  = 0;

interrupt void Interrupt(void)
{
	//static Uint16 INT_loop_cnt = 0
    XF2_ON;                                 // XF2 Pin ON

    *CARRIER_INIT_LOAD = 0x00;
    IpcRegs.IPCSET.bit.IPC5 = 1;

    ADC();
	DELAY_US(7);
	ADC_Read();

	IPC_DSP2_EtherCAT_RX();

	Temp_Sensor();
	SM_Vol_Sensor();
//	Arm_Current_Sensor();

//	IPC_DSP2_Temp_TX();
//    IPC_DSP2_Temp_RX();

    Fault();

    IPC_DSP2_EtherCAT_TX();


//    if(Dsp2EcatMaster.STATUS.bit.Slave_Num == 1) XF2_ON;
//    else                                         XF2_OFF;

    OPERATION();
    GATING(REFERENCE);

	FAN();

	DAQ_RS422(V_SM, Temp, Group_number, fault);

	DAC();

	Temp_Calc();

    LED_DSP();
    LED_FPGA();
    Init_ADC();                               // ADC Initializing.

    XF2_OFF;                                 // XF2 Pin OFF

    PieCtrlRegs.PIEACK.bit.ACK12 = 1;        // XINT5 PIE Interrupt Clear

}
