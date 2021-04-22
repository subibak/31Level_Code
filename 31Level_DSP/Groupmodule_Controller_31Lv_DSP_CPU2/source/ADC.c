/*
 * ADC.c
 *
 *  Created on: 2018. 06. 19.
 *      Author: Subi
 */

#include "Define_Header.h"

int AIN0_CH1 = 0, AIN0_CH2 = 0, AIN0_CH3 = 0, AIN0_CH4 = 0;
int AIN1_CH1 = 0, AIN1_CH2 = 0, AIN1_CH3 = 0, AIN1_CH4 = 0;
int AIN2_CH1 = 0, AIN2_CH2 = 0, AIN2_CH3 = 0, AIN2_CH4 = 0;
int AIN3_CH1 = 0, AIN3_CH2 = 0, AIN3_CH3 = 0, AIN3_CH4 = 0;
int AIN4_CH1 = 0, AIN4_CH2 = 0, AIN4_CH3 = 0, AIN4_CH4 = 0;

// ADC7864
void Init_ADC(void)
{

    *ADC_ALL_CSn_ON = 0Xf;
    *ADC_ALL_WRn_ON = 0xf;
    *ADC_ALL_WRn_OFF = 0xf;
    *ADC_ALL_CSn_OFF = 0xf;

    return;
}

void ADC(void)
{
	// conversion start
    *ADC_ALL_CVn_ON = 0x00;
	DELAY_US(1);
	*ADC_ALL_CVn_OFF= 0x00;

	return;
}

void ADC_Read(void)
{
	// ADC0 Data Read
    *ADC0_CSn_ON = 0x00;
	DELAY_US(0.05);
	AIN0_CH1 = *ADC0_RDn;
	AIN0_CH2 = *ADC0_RDn;
	AIN0_CH3 = *ADC0_RDn;
	AIN0_CH4 = *ADC0_RDn;
	*ADC0_CSn_OFF = 0x00;
    // ADC1 Data Read
    *ADC1_CSn_ON = 0x00;
    DELAY_US(0.05);
    AIN1_CH1 = *ADC1_RDn;
    AIN1_CH2 = *ADC1_RDn;
    AIN1_CH3 = *ADC1_RDn;
    AIN1_CH4 = *ADC1_RDn;
    *ADC1_CSn_OFF = 0x00;
    // ADC2 Data Read
    *ADC2_CSn_ON = 0x00;
    DELAY_US(0.05);
    AIN2_CH1 = *ADC2_RDn;
    AIN2_CH2 = *ADC2_RDn;
    AIN2_CH3 = *ADC2_RDn;
    AIN2_CH4 = *ADC2_RDn;
    *ADC2_CSn_OFF = 0x00;
    // ADC3 Data Read
    *ADC3_CSn_ON = 0x00;
    DELAY_US(0.05);
    AIN3_CH1 = *ADC3_RDn;
    AIN3_CH2 = *ADC3_RDn;
    AIN3_CH3 = *ADC3_RDn;
    AIN3_CH4 = *ADC3_RDn;
    *ADC3_CSn_OFF = 0x00;;
    // ADC4 Data Read
    *ADC4_CSn_ON = 0x00;
    DELAY_US(0.05);
    AIN4_CH1 = *ADC4_RDn;
    AIN4_CH2 = *ADC4_RDn;
    AIN4_CH3 = *ADC4_RDn;
    AIN4_CH4 = *ADC4_RDn;
    *ADC4_CSn_OFF = 0x00;

	return;
}

interrupt void ADC_Offset(void)
{
	static int offset_cnt = 0;
	Init_ADC();
	ADC();

	DELAY_US(7);

	ADC_Read();

	SM_Vol_Sensor();
	Arm_Current_Sensor();

	offset_sum_SM_Vol[0] += V_SM[0];
	offset_sum_SM_Vol[1] += V_SM[1];
	offset_sum_SM_Vol[2] += V_SM[2];
	offset_sum_SM_Vol[3] += V_SM[3];
	offset_sum_SM_Vol[4] += V_SM[4];
	offset_sum_SM_Vol[5] += V_SM[5];
    offset_sum_Arm_Cur_A += Arm_Cur_A;
    offset_sum_Arm_Cur_B += Arm_Cur_B;

	if (offset_cnt++ >= ADC_OFFSET_COUNT)
	{

	    SM_Vol_offset[0] = offset_sum_SM_Vol[0] * ADC_INV_OFFSET_COUNT;
	    SM_Vol_offset[1] = offset_sum_SM_Vol[1] * ADC_INV_OFFSET_COUNT;
	    SM_Vol_offset[2] = offset_sum_SM_Vol[2] * ADC_INV_OFFSET_COUNT;
        SM_Vol_offset[3] = offset_sum_SM_Vol[3] * ADC_INV_OFFSET_COUNT;
        SM_Vol_offset[4] = offset_sum_SM_Vol[4] * ADC_INV_OFFSET_COUNT;
        SM_Vol_offset[5] = offset_sum_SM_Vol[5] * ADC_INV_OFFSET_COUNT;

        Arm_Cur_A_offset = offset_sum_Arm_Cur_A * ADC_INV_OFFSET_COUNT;
        Arm_Cur_B_offset = offset_sum_Arm_Cur_B * ADC_INV_OFFSET_COUNT;

        Arm_Cur_A_offset_origin = Arm_Cur_A_offset;
        Arm_Cur_B_offset_origin = Arm_Cur_B_offset;

		EALLOW;
		PieVectTable.XINT5_INT = &Interrupt;
		EDIS;
	}

    PieCtrlRegs.PIEACK.bit.ACK12 = 1;        // XINT5 PIE Interrupt Clear

}

