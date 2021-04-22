/*
 * OP_MODE.c
 *
 *  Created on: 2018. 9. 5.
 *      Author: subi
 */

#include "Define_Header.h"

Uint16 OP_MODE = 0;

int Flag_Normal = 0;
int Flag_VF = 0;
int Flag_OP_OL = 0;
int Flag_DT = 0;
int Flag_Gating = 0;

int PWM_MODE = 1;

//TEST MODE
float V_SM_t[6] = {10,20,30,40,50,60};
float Temp_t[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
float sine_t[6] = {0,0,0,0,0,0};
Uint16 Group_number_t = 0;
Uint16 fault_t = 0;
int Flag_Buffer_HW_t[4] = {0,0,0,0};
int Flag_Buffer_SW_t[6] = {0,0,0,0,0,0};
int Flag_FAN_t[6] = {0,0,0,0,0,0};
int Flag_Relay_t[6] = {0,0,0,0,0,0};
int Flag_IGBT_t[6] = {0,0,0,0,0,0};
Uint16 REFERENCE_t[6] = {0,0,0,0,0,0};

void OPERATION(void)
{
    /*
     *1. Normal Operation(Flag_Normal)
     *2. V/F(Flag_VF)
     *3. One phase open loop test(Flag_OP_OL)
     *4. Device test(Flag_DT)
     *
     */
    Flag_Buffer_HW[0] = Flag_Gating;
    Flag_Buffer_HW[3] = Flag_Gating;
    for(k = 0; k < 6; k++)
    {
        Flag_Buffer_SW[k] = Flag_Gating;
        REFERENCE[k] = 0;
    }
    //Fault();

    OP_MODE = (Uint16)((Flag_Normal & 0x1) | (Flag_VF & 0x1) << 1 | (Flag_OP_OL & 0x1) << 2 | (Flag_DT & 0x1) << 3 | (Flag_Gating & 0x1) << 15);
    switch(OP_MODE)
    {
    case 0x0001 ://1. Normal Operation(Flag_Normal) in gating
        Bubble_sort(Number_SM, V_SM);
        break;
    case 0x8001 ://1. Normal Operation(Flag_Normal) in gating
        Bubble_sort(Number_SM, V_SM);
        break;
    case 0x0002 ://2. V/F(Flag_VF)
        Bubble_sort(Number_SM, V_SM);
        break;
    case 0x8002 ://2. V/F(Flag_VF) in gating
        Bubble_sort(Number_SM, V_SM);
        break;
    case 0x0004 ://3. One phase open loop test(Flag_OP_OL)
        OPENLOOP = 1;
        Bubble_t_sort(3, V_SM);
        Open_Loop();
        PWM_MODE = 4;
        break;
    case 0x8004 ://3. One phase open loop test(Flag_OP_OL) in gating
        Bubble_t_sort(3, V_SM);
        Open_Loop();
        PWM_MODE = 4;
        break;
    case 0x0008 ://4. Device test(Flag_DT)
        theta_t += TIMEBASE1_SAMPLING_TIME * freq_t * PI2;
        if (theta_t > PI2)         theta_t -= PI2;
        else if (theta_t < 0)      theta_t += PI2;

        Bubble_sort(Number_SM, V_SM_t);
        for(k = 0; k < 6; k++){
            sine_t[k] = (k+1) * 20 * sin(theta_t);
            V_SM[k] = V_SM_t[k];
            Temp[k] = Temp_t[k];
            Temp[k+6] = Temp_t[k+6];

            if(k <= 3)  Flag_Buffer_HW[k] = Flag_Buffer_HW_t[k];
            Flag_Buffer_SW[k] = Flag_Buffer_SW_t[k];
            Flag_FAN[k] = Flag_FAN_t[k];
            Flag_Relay[k] = Flag_Relay_t[k];
            Flag_IGBT[k] = Flag_IGBT_t[k];
            REFERENCE[k] = REFERENCE_t[k];
        }
        Group_number = Group_number_t;
        fault = fault_t;
        PWM_MODE = 4;
        break;
    default :
        for(k = 0; k < 6; k++){
            if(k <= 3)  Flag_Buffer_HW[k] = 0;
            Flag_Buffer_SW[k] = 0;
        }
        Reset();
        break;
    }

    BYPASSING();

    BUFFER_HW = 0;
    BUFFER_SW = 0;
    for(k = 0; k < 6; k++){
        if(k <= 3)  BUFFER_HW = BUFFER_HW | (((Uint16)Flag_Buffer_HW[k]) << k);
        BUFFER_SW = BUFFER_SW | (((Uint16)Flag_Buffer_SW[k]) << k);
        BUFFER_SW = BUFFER_SW | (((Uint16)Flag_Buffer_SW[k+3]) << (k+3));
    }
    *GATE_BUFFER_HW = BUFFER_HW;                  //74F240SC/SOIC buffer
    *GATE_BUFFER_SW = BUFFER_SW;                  //S/W buffer

   PWM_METHOD();

   return;
}

void PWM_METHOD(void)
{
    switch (PWM_MODE)// 1. NLC, 2. PD 3. PSC 4. default : NLC
    {
    case 1 :  NLC(Number_SM, Arm_Cur_Sign, V_ref_NLC, SM_INDEX_NEW, REFERENCE);              break;
    case 2 :  PD(Number_SM, Arm_Cur_Sign, V_ref_NLC, V_ref_PWM, SM_INDEX_NEW, REFERENCE);    break;
    case 3 :  PSC();                                                                         break;
    case 4 :  break;
    default:  NLC(Number_SM, Arm_Cur_Sign, V_ref_NLC, SM_INDEX_NEW, REFERENCE);              break;
    }

    return;
}

void Reset(void)
{
    //OPERATION_MODE FLAG
    Flag_Normal = 0;
    Flag_VF = 0;
    Flag_OP_OL = 0;
    Flag_DT = 0;
    Flag_Gating = 0;
    //PD_method
    PWM_x = 0;
    NLC_x = 0;
    //Final Reference
    for(k = 0; k < Number_SM; k++)
    {
       REFERENCE[k] = 0;
       //test value
       Ref_t_U[k] = 0;
       Ref_t_L[k] = 0;
    }
    //OPENLOOP
    OPENLOOP = 1;
    //PWM_MODE
    PWM_MODE = 1;
    return;

}
