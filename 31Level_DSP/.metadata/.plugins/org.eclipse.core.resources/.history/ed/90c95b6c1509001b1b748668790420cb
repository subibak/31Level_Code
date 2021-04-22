#include "Define_Header.h"
#include "Define_GSxRAM.h"

int l = 0, m=0, k = 0, i = 0, j = 0, t = 0;

int Number_SM = 6;
int D_Number_SM = 12;
int H_Number_SM = 3;

//0xab a = U,V,W or R,S,T  b = 1~10
Uint16 Group_number = 0x13;

Uint16 REF_MIN =0, REF_MAX = 0;
Uint16 HALF_CNT = 0;

int Flag_PWM_INIT = 0;

interrupt void Interrupt(void)
{
	//static Uint16 INT_loop_cnt = 0;
    XF1_ON;                                 // XF1 Pin ON
    *CARRIER_INIT_LOAD = 0x00;
    EtherCAT1;
    EtherCAT3;
	ADC();
	DELAY_US(7);
	ADC_Read();

	SM_Vol_Sensor();
	Temp_Sensor();
	Arm_Current_Sensor();

    Temp_Calc(Vol_Temp, Temp, D_Number_SM);

	OPERATION();

	GATING(REFERENCE);

	FAN();
	DAQ_RS422(V_SM, Temp, Group_number, fault);

	DAC();
	LED_DSP();
	LED_FPGA();

	XF1_OFF;						        // XF1 Pin OFF
	EPwm1Regs.ETCLR.bit.INT = 1;			// ePWM1 Interrupt Clear
	PieCtrlRegs.PIEACK.bit.ACK3 = 1;		// ePWM1 PIE Interrupt Clear
}
