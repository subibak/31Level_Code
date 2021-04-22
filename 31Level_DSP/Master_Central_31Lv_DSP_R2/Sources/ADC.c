/*
 * ADC.c
 *
 *  Created on: 2018. 12. 13.
 *      Author: subi
 */

#include "Define_Header.h"

int32 AIN0_CH1        = 0, AIN0_CH2        = 0, AIN0_CH3        = 0, AIN0_CH4       = 0;
int32 AIN1_CH1        = 0, AIN1_CH2        = 0, AIN1_CH3        = 0, AIN1_CH4       = 0;
int32 AIN2_CH1        = 0, AIN2_CH2        = 0, AIN2_CH3        = 0, AIN2_CH4       = 0;
int32 AIN3_CH1        = 0, AIN3_CH2        = 0, AIN3_CH3        = 0, AIN3_CH4       = 0;

float V_AB_offset     = 0, V_BC_offset     = 0, V_CA_offset     = 0;
float V_DC_offset     = 0;
float I_DC_offset     = 0;
float I_AS_offset     = 0, I_BS_offset     = 0, I_CS_offset     = 0;
float I_AU_offset     = 0, I_BU_offset     = 0, I_CU_offset     = 0;
float I_AL_offset     = 0, I_BL_offset     = 0, I_CL_offset     = 0;

float offset_sum_V_AB = 0, offset_sum_V_BC = 0, offset_sum_V_CA = 0;
float offset_sum_V_DC = 0;
float offset_sum_I_DC = 0;
float offset_sum_I_AS = 0, offset_sum_I_BS = 0, offset_sum_I_CS = 0;
float offset_sum_I_AU = 0, offset_sum_I_BU = 0, offset_sum_I_CU = 0;
float offset_sum_I_AL = 0, offset_sum_I_BL = 0, offset_sum_I_CL = 0;

// ADC7864
void ADC_OP(void)
{
    ADC();
    cycleDelay(5250);   //
    ADC_Read();
}

void Init_ADC(void)
{

    ADC_ALL_CSn_ON = 0XF;
    ADC_ALL_WRn_ON = 0xF;
//    cycleDelay(416);
    ADC_ALL_WRn_OFF = 0xF;
    ADC_ALL_CSn_OFF = 0xF;

    return;
}

void ADC(void)
{
    // conversion start
    ADC_ALL_CVn_ON = 0x0000;
    cycleDelay(416);
    ADC_ALL_CVn_OFF= 0x0000;

    return;
}

void ADC_Read(void)
{
    // ADC0 Data Read
    ADC0_CSn_ON = 0x00;
    ADC0_RDn_ON = 0x00;
    AIN0_CH1 = ADC0_RDn;
    ADC0_RDn_OFF = 0x00;
    ADC0_RDn_ON = 0x00;
    AIN0_CH2 = ADC0_RDn;
    ADC0_RDn_OFF = 0x00;
    ADC0_RDn_ON = 0x00;
    AIN0_CH3 = ADC0_RDn;
    ADC0_RDn_OFF = 0x00;
    ADC0_RDn_ON = 0x00;
    AIN0_CH4 = ADC0_RDn;
    ADC0_RDn_OFF = 0x00;
    ADC0_CSn_OFF = 0x00;
    // ADC1 Data Read
    ADC1_CSn_ON = 0x00;
    ADC1_RDn_ON = 0x00;
    AIN1_CH1 = ADC1_RDn;
    ADC1_RDn_OFF = 0x00;
    ADC1_RDn_ON = 0x00;
    AIN1_CH2 = ADC1_RDn;
    ADC1_RDn_OFF = 0x00;
    ADC1_RDn_ON = 0x00;
    AIN1_CH3 = ADC1_RDn;
    ADC1_RDn_OFF = 0x00;
    ADC1_RDn_ON = 0x00;
    AIN1_CH4 = ADC1_RDn;
    ADC1_RDn_OFF = 0x00;
    ADC1_CSn_OFF = 0x00;
    // ADC2 Data Read
    ADC2_CSn_ON = 0x00;
    ADC2_RDn_ON = 0x00;
    AIN2_CH1 = ADC2_RDn;
    ADC2_RDn_OFF = 0x00;
    ADC2_RDn_ON = 0x00;
    AIN2_CH2 = ADC2_RDn;
    ADC2_RDn_OFF = 0x00;
    ADC2_RDn_ON = 0x00;
    AIN2_CH3 = ADC2_RDn;
    ADC2_RDn_OFF = 0x00;
    ADC2_RDn_ON = 0x00;
    AIN2_CH4 = ADC2_RDn;
    ADC2_RDn_OFF = 0x00;
    ADC2_CSn_OFF = 0x00;
    // ADC3 Data Read
    ADC3_CSn_ON = 0x00;
    ADC3_RDn_ON = 0x00;
    AIN3_CH1 = ADC3_RDn;
    ADC3_RDn_OFF = 0x00;
    ADC3_RDn_ON = 0x00;
    AIN3_CH2 = ADC3_RDn;
    ADC3_RDn_OFF = 0x00;
    ADC3_RDn_ON = 0x00;
    AIN3_CH3 = ADC3_RDn;
    ADC3_RDn_OFF = 0x00;
    ADC3_RDn_ON = 0x00;
    AIN3_CH4 = ADC3_RDn;
    ADC3_RDn_OFF = 0x00;
    ADC3_CSn_OFF = 0x00;

    return;
}

interrupt void ADC_Offset(void)
{
    static int offset_cnt = 0;

    ADC_OP();
    Sensor_Outside();
    Sensor_Inside();

    //AC voltage offset sum
    offset_sum_V_AB += V_AB;
    offset_sum_V_BC += V_BC;
    offset_sum_V_CA += V_CA;
    //DC Voltage offset sum
    offset_sum_V_DC += V_DC;
    //AC current offset sum
    offset_sum_I_AS += I_AS;
    offset_sum_I_BS += I_BS;
    offset_sum_I_CS += I_CS;
    //DC Current offset sum
    offset_sum_I_DC += I_DC;
    //Arm curren offset sum
    offset_sum_I_AU += I_AU;
    offset_sum_I_BU += I_BU;
    offset_sum_I_CU += I_CU;
    offset_sum_I_AL += I_AL;
    offset_sum_I_BL += I_BL;
    offset_sum_I_CL += I_CL;

    if (offset_cnt++ >= ADC_OFFSET_COUNT)
    {
          //AC voltage offset
          V_AB_offset = offset_sum_V_AB * ADC_INV_OFFSET_COUNT;
          V_BC_offset = offset_sum_V_BC * ADC_INV_OFFSET_COUNT;
          V_CA_offset = offset_sum_V_CA * ADC_INV_OFFSET_COUNT;
          //DC voltage offset
          V_DC_offset = offset_sum_V_DC * ADC_INV_OFFSET_COUNT;
          //AC current offset
          I_AS_offset = offset_sum_I_AS * ADC_INV_OFFSET_COUNT;
          I_BS_offset = offset_sum_I_BS * ADC_INV_OFFSET_COUNT;
          I_CS_offset = offset_sum_I_CS * ADC_INV_OFFSET_COUNT;
          //DC current offset
          I_DC_offset = offset_sum_I_DC * ADC_INV_OFFSET_COUNT;
          //Arm current offset
          I_AU_offset = offset_sum_I_AU * ADC_INV_OFFSET_COUNT;
          I_BU_offset = offset_sum_I_BU * ADC_INV_OFFSET_COUNT;
          I_CU_offset = offset_sum_I_CU * ADC_INV_OFFSET_COUNT;
          I_AL_offset = offset_sum_I_AL * ADC_INV_OFFSET_COUNT;
          I_BL_offset = offset_sum_I_BL * ADC_INV_OFFSET_COUNT;
          I_CL_offset = offset_sum_I_CL * ADC_INV_OFFSET_COUNT;

          // Interrupt Clear.
          Timer5Regs.IRQSTATUS.all = IRQSTATUS_OVF_INT;
          DSP_ICFGRegs.EVTCLR2.bit.EVT67 = 1;
          ICR = M_INT4;
          // Interrupt Selector change to 5 from 4
          IER = 0x00000022;
    }
    else
    {
          // Interrupt Clear.
          Timer5Regs.IRQSTATUS.all = IRQSTATUS_OVF_INT;
          DSP_ICFGRegs.EVTCLR2.bit.EVT67 = 1;
          ICR = M_INT4;
    }


}



