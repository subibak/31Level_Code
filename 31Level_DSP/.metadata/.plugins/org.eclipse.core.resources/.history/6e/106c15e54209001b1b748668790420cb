/*
 * Sensor.c
 *
 *  Created on: 2018. 06. 19.
 *      Author: Subi
 */


#include "Define_Header.h"

float Vol_Temp[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
float Temp[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
float Rt_denum[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
float Rt_num[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
float Rt[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
float Rt_R25C[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

float Arm_Cur_A = 0, Arm_Cur_B = 0;
float V_SM[6] = {0,0,0,0,0,0};
float V_SM_SUM = 0;

float SM_Vol_offset[6] = {0,0,0,0,0,0};
float Arm_Cur_A_offset = 0, Arm_Cur_B_offset = 0;

float offset_sum_SM_Vol[6] = {0,0,0,0,0,0};
float offset_sum_Arm_Cur_A = 0, offset_sum_Arm_Cur_B = 0;

float SM_MAX = 0, Vdc_test = 12;//128;
float Inv_Vdc = 0;

float SM_VOL_MAX = 200;
float TEMP_MAX = 10.55;
float CUR_MAX = 207.5;

int Arm_Cur_Sign = 0;
int Upper_Arm_Cur_Sign = 0;
int Lower_Arm_Cur_Sign = 0;

void SM_Vol_Sensor(void)
{
    //From SM_Vol_A1 to SM_Vol_A3
    V_SM[0] = (float)(AIN0_CH1 << 4 >> 4) * ADC_RESOLUTION * SM_VOL_MAX - SM_Vol_offset[0];
    V_SM[1] = (float)(AIN0_CH2 << 4 >> 4) * ADC_RESOLUTION * SM_VOL_MAX - SM_Vol_offset[1];
    V_SM[2] = (float)(AIN0_CH3 << 4 >> 4) * ADC_RESOLUTION * SM_VOL_MAX - SM_Vol_offset[2];
    //From SM_Vol_B1 to SM_Vol_B3
    V_SM[3] = (float)(AIN4_CH4 << 4 >> 4) * ADC_RESOLUTION * SM_VOL_MAX - SM_Vol_offset[3];
    V_SM[4] = (float)(AIN4_CH3 << 4 >> 4) * ADC_RESOLUTION * SM_VOL_MAX - SM_Vol_offset[4];
    V_SM[5] = (float)(AIN4_CH2 << 4 >> 4) * ADC_RESOLUTION * SM_VOL_MAX - SM_Vol_offset[5];

    V_SM_SUM = 0;

    for(k = 0 ; k < Number_SM; k++)  V_SM_SUM += V_SM[k];

    return;
}

void Temp_Sensor(void)
{
    Vol_Temp[0] = (float)(AIN1_CH1 << 4 >> 4) * ADC_RESOLUTION * TEMP_MAX;
    Vol_Temp[1] = (float)(AIN1_CH2 << 4 >> 4) * ADC_RESOLUTION * TEMP_MAX;
    Vol_Temp[2] = (float)(AIN1_CH3 << 4 >> 4) * ADC_RESOLUTION * TEMP_MAX;
    Vol_Temp[3] = (float)(AIN1_CH4 << 4 >> 4) * ADC_RESOLUTION * TEMP_MAX;
    Vol_Temp[4] = (float)(AIN2_CH1 << 4 >> 4) * ADC_RESOLUTION * TEMP_MAX;
    Vol_Temp[5] = (float)(AIN2_CH2 << 4 >> 4) * ADC_RESOLUTION * TEMP_MAX;

    Vol_Temp[6] = (float)(AIN3_CH4 << 4 >> 4) * ADC_RESOLUTION * TEMP_MAX;
    Vol_Temp[7] = (float)(AIN3_CH3 << 4 >> 4) * ADC_RESOLUTION * TEMP_MAX;
    Vol_Temp[8] = (float)(AIN3_CH2 << 4 >> 4) * ADC_RESOLUTION * TEMP_MAX;
    Vol_Temp[9] = (float)(AIN3_CH1 << 4 >> 4) * ADC_RESOLUTION * TEMP_MAX;
    Vol_Temp[10] = (float)(AIN2_CH4 << 4 >> 4) * ADC_RESOLUTION * TEMP_MAX;
    Vol_Temp[11] = (float)(AIN2_CH3 << 4 >> 4) * ADC_RESOLUTION * TEMP_MAX;

    return;
}

void Arm_Current_Sensor(void)
{
    Arm_Cur_A = (float)(AIN0_CH4 << 4 >> 4) * ADC_RESOLUTION * CUR_MAX - Arm_Cur_A_offset;
    Arm_Cur_B = (float)(AIN4_CH1 << 4 >> 4) * ADC_RESOLUTION * CUR_MAX - Arm_Cur_B_offset;

    if (Arm_Cur_A > 0)  Upper_Arm_Cur_Sign = 1;
    else                Upper_Arm_Cur_Sign = 0;

    if (Arm_Cur_B > 0)  Lower_Arm_Cur_Sign = 1;
    else                Lower_Arm_Cur_Sign = 0;

    return;
}


void Temp_Calc(float Vol_Temp[], float Temperature[], int NUM)
{
    //NTCS0805E3153JMT model ---> -20 Celsius => 123,815 ohm   <=> This is the maximum value.
    //So the maximum voltage, which would be measured by ADC, is 5V * 123815 / (1000 + 123815) = 4.9599 V
    for(t = 0; t < NUM; t++)
    {
        //Calculation of NTC resistor from the measured voltage(Vol_Temp) - Voltage distribution
        Rt_num[t] = Vol_Temp[t] * 1000;             // 1000 = 1kohm
        Rt_denum[t] = (5 - Vol_Temp[t]);         // 5 = 5V_analog
        Rt[t] = Rt_num[t] / Rt_denum[t];
        //Calculation of the ration Rt / R25
        Rt_R25C[t] = Rt[t] * Inv_R25;
        //Calculation of the temperature in celsius
        Temperature[t] = 1 / (INV_TEMP_K_25C + INV_B_CONST * log(Rt_R25C[t])) - TEMP_K_0C;
    }

}
