/*
 * Group_module_test.c
 *
 *  Created on: 2018. 8. 28.
 *      Author: subi
 */

#include "Define_Header.h"

int a = 0;
int OPENLOOP = 0;

float Ref_sine_t = 0;
float amp_sine_t = 5;
float Vdc_t = 60, Vdc_half_t = 30;
float Upper_ref_t_norm = 0, Lower_ref_t_norm = 0;
float NUM_SM_t = 3;
float theta_t = 0, freq_t = 0;
int SEQ_1st_norm = 3, SEQ_2st_norm = 2;

Uint16 Ref_t_U[3] = {0,0,0};
Uint16 Ref_t_L[3] = {0,0,0};

float SM_U_VOLTAGE_NEW_t[3] = {0, 0, 0};
float SM_L_VOLTAGE_NEW_t[3] = {0, 0, 0};

int SM_U_INDEX_NEW_t[3] = {1, 2, 3};
int SM_L_INDEX_NEW_t[3] = {1, 2, 3};

float U_voltage_temp=0,  L_voltage_temp =0;
int U_index_temp=0, L_index_temp=0;

int V_upper_ref_NLC = 0, V_lower_ref_NLC = 0;
Uint16 V_upper_ref_PWM = 0, V_lower_ref_PWM = 0;

int Half_NUM_SM = 0;

void Bubble_t_sort(int NUM_SM, float VSM[])
{
    //NUM_SM 결정할 것
    Half_NUM_SM = 0.5 * NUM_SM;
    for(k = 0; k < NUM_SM; k++)
    {
        SM_U_VOLTAGE_NEW_t[k] = VSM[k];
        SM_L_VOLTAGE_NEW_t[k] = VSM[k + 3];
        SM_U_INDEX_NEW_t[k] = k + 1;
        SM_L_INDEX_NEW_t[k] = k + 1;
    }

    // Ascending order
    for(i = 0; i < NUM_SM - 1; i++)

    {
        for(j = 0; j < NUM_SM - 1 - i; j++)

        {
            //upper phase submodule sorting
            if(SM_U_VOLTAGE_NEW_t[j] > SM_U_VOLTAGE_NEW_t[j+1])
            {
                U_voltage_temp = SM_U_VOLTAGE_NEW_t[j];
                SM_U_VOLTAGE_NEW_t[j] =SM_U_VOLTAGE_NEW_t[j+1];
                SM_U_VOLTAGE_NEW_t[j+1] = U_voltage_temp;

                U_index_temp =  SM_U_INDEX_NEW_t[j];
                SM_U_INDEX_NEW_t[j] = SM_U_INDEX_NEW_t[j+1];
                SM_U_INDEX_NEW_t[j+1] = U_index_temp;

            }

            //lower phase submodule sorting
            if(SM_L_VOLTAGE_NEW_t[j] > SM_L_VOLTAGE_NEW_t[j+1])
            {
                L_voltage_temp = SM_L_VOLTAGE_NEW_t[j];
                SM_L_VOLTAGE_NEW_t[j] = SM_L_VOLTAGE_NEW_t[j+1];
                SM_L_VOLTAGE_NEW_t[j+1] = L_voltage_temp ;

                L_index_temp = SM_L_INDEX_NEW_t[j];
                SM_L_INDEX_NEW_t[j] = SM_L_INDEX_NEW_t[j+1];
                SM_L_INDEX_NEW_t[j+1] = L_index_temp;
            }
        }
    }

    return;

}

void Open_Loop(void)
{
    theta_t += TIMEBASE1_SAMPLING_TIME * freq_t * PI2;
    if (theta_t > PI2)         theta_t -= PI2;
    else if (theta_t < 0)      theta_t += PI2;

    Ref_sine_t = amp_sine_t * sin(theta_t);
    Vdc_half_t = Vdc_t * 0.5;
    Upper_ref_t_norm = (Vdc_half_t - Ref_sine_t) / Vdc_t * NUM_SM_t;
    Lower_ref_t_norm = (Vdc_half_t + Ref_sine_t) / Vdc_t * NUM_SM_t;

    // NLC_PWM
    if(Upper_ref_t_norm < 0)        Upper_ref_t_norm = 0;
    else if(Upper_ref_t_norm > 3)   Upper_ref_t_norm = 3;

    V_upper_ref_NLC = floor(Upper_ref_t_norm);
    V_upper_ref_PWM = (Uint16)((Upper_ref_t_norm - (float)V_upper_ref_NLC)*MAX_CNT_CARRIER);

    if(Lower_ref_t_norm < 0)        Lower_ref_t_norm = 0;
    else if(Lower_ref_t_norm > 3)   Lower_ref_t_norm = 3;

    V_lower_ref_NLC = floor(Lower_ref_t_norm);
    V_lower_ref_PWM = (Uint16)((Lower_ref_t_norm - (float)V_lower_ref_NLC)*MAX_CNT_CARRIER);

    for(a = 0; a < 3; a++)
    {
       Ref_t_U[a] = 0;
       Ref_t_L[a] = 0;
    }

    switch(OPENLOOP)
    {
    case 1:
        NLC(3, Upper_Arm_Cur_Sign, SEQ_1st_norm, SM_U_INDEX_NEW_t, Ref_t_U);
        NLC(3, Lower_Arm_Cur_Sign, SEQ_1st_norm, SM_L_INDEX_NEW_t, Ref_t_L);
        break;
    case 2 :
        NLC(3, Upper_Arm_Cur_Sign, SEQ_2st_norm, SM_U_INDEX_NEW_t, Ref_t_U);
        NLC(3, Lower_Arm_Cur_Sign, SEQ_2st_norm, SM_L_INDEX_NEW_t, Ref_t_L);
        break;
    case 3 :
        PD(3, Upper_Arm_Cur_Sign, V_upper_ref_NLC, V_upper_ref_PWM, SM_U_INDEX_NEW_t, Ref_t_U);
        PD(3, Lower_Arm_Cur_Sign, V_lower_ref_NLC, V_lower_ref_PWM, SM_L_INDEX_NEW_t, Ref_t_L);
        break;
    default : break;
    }

    for(a = 0; a < 3; a++)
    {
       REFERENCE[a] = Ref_t_U[a];
       REFERENCE[a+3] = Ref_t_L[a];
    }

    return;
}
