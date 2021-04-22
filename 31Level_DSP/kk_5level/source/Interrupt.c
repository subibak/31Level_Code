// Slave Interrupt Code
#include "Define_Header.h"

int INT_carrier_loop_cnt1 = 0;
Uint16 Flag_Out_Loop = 0;

Uint16 Flag_M1_Sensorless = 0;
Uint16 A = 0, B = 0;
//float Vdc=0, Vdc_test=0, Inv_Vdc=0;
float Vol_SM = 0, Num_SM = 4;

interrupt void Interrupt(void)
{
	XF1_ON;									// XF1 Pin ON
	// 100us Carrier 초기화  & Count set up
	*CONVERTER_EN = 0x0;

     if(++INT_carrier_loop_cnt1 >= 10)
     {
    	 Flag_Out_Loop = 1;
    	 INT_carrier_loop_cnt1 =0;
     }
     else
    	 Flag_Out_Loop = 0;

    ADC();									// Start of Conversion
	DELAY_US(7);							// Time for Data Conversion

	// ADC Data Conversion
	ADC_Read();								// ADC Data Read
	Current_Sensor();                   // Current Sensing
	Voltage_Sensor();                   // Voltage Sensing

	// 각 Sub-Module Over Voltage 감지 및 조치
	Fault();
	Balance();

	// PWM
	//PWM();
//	Vdc=Vdc_test;
//	Inv_Vdc=1/Vdc;
//	Vol_SM = Vdc/NUM_SM;
	MMC();

	// Additional Operation
	LED1();
	LED();

	DAC();

	XF1_OFF;									// XF1 Pin OFF
	EPwm1Regs.ETCLR.bit.INT = 1;			// ePWM1 Interrupt Clear
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;	// ePWM1 PIE Interrupt Clear
}
