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

interrupt void Interrupt(void)
{
	//static Uint16 INT_loop_cnt = 0;
    XF1_ON;                                 // XF1 Pin ON

	LED_DSP();
//    Temp_Calc();
//	CPU_Msg_Read(msg_test_rd);

//	CPU_Msg_Write(msg_test_wr);

	EtherCAT1_OFF;
    EtherCAT2_OFF;
	XF1_OFF;						        // XF1 Pin OFF

	EPwm1Regs.ETCLR.bit.INT = 1;			// ePWM1 Interrupt Clear
	PieCtrlRegs.PIEACK.bit.ACK3 = 1;		// ePWM1 PIE Interrupt Clear
}
