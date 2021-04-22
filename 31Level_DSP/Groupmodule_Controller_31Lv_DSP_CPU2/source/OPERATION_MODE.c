/*
 * OP_MODE.c
 *
 *  Created on: 2018. 9. 5.
 *      Author: subi
 */

#include "Define_Header.h"

Uint16 OP_MODE = 0;

Uint16 Flag_Normal_DT = 0;
Uint16 Flag_Gating = 0;
Uint16 PWM_MODE = 1;

//TEST MODE
float V_SM_t[6] = {10,20,30,40,50,60};
float V_SMt[6] = {0,0,0,0,0,0};
float Temp_t[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
float sine_t[6] = {0,0,0,0,0,0};
float sine_t2[6] = {0,0,0,0,0,0};
float NUM_SM_t = 3;
float theta_t = 0, freq_t = 60;
float theta_t2 = 0, freq_t2 = 120;

float sine_offset_t[6] = {10,10,10,10,10,10};
Uint16 Group_number_t = 0;
Uint16 fault_t = 0;
float Arm_Cur_A_offset_t = 0, Arm_Cur_B_offset_t = 0;
int Flag_Buffer_HW_t[4] = {0,0,0,0};
int Flag_Buffer_SW_t[6] = {0,0,0,0,0,0};
int Flag_FAN_t[6] = {0,0,0,0,0,0};
int Flag_Relay_t[6] = {0,0,0,0,0,0};
int Flag_IGBT_t[6] = {0,0,0,0,0,0};


void OPERATION(void)
{
    /*
     *1. Normal Operation(Flag_Normal)
     *2. V/F(Flag_VF)
     *3. One phase open loop test(Flag_OP_OL)
     *4. Device test(Flag_DT)
     *
     */
    Flag_Gating = Dsp2EcatMaster.Operation.bit.Flag_Operation;
    Flag_Normal_DT = Dsp2EcatMaster.Slave_OP_Mode.bit.OP_Mode;

    Flag_Buffer_HW[0] = Flag_Gating;                // one part MOSFET
    Flag_Buffer_HW[3] = Flag_Gating;                // one part MOSFET
    for(k = 0; k < 6; k++)
    {
        Flag_Buffer_SW[k] = Flag_Gating;
        REFERENCE[k] = 0;
    }

    OP_MODE = (Uint16)((Flag_Normal_DT & 0xF) | (Flag_Gating & 0x1) << 15);
    switch(OP_MODE)
    {
    case 0x0001 ://1. Normal Operation(Flag_Normal) in gating
        Bubble_sort(Number_SM, V_SM);
        break;
    case 0x8001 ://1. Normal Operation(Flag_Normal) in gating
        Bubble_sort(Number_SM, V_SM);
        break;
    case 0x8008 ://4. Device test(Flag_DT)
    case 0x0008 ://4. Device test(Flag_DT)
        theta_t += TIMEBASE1_SAMPLING_TIME * freq_t * PI2;
        if (theta_t > PI2)         theta_t -= PI2;
        else if (theta_t < 0)      theta_t += PI2;

        theta_t2 += TIMEBASE1_SAMPLING_TIME * freq_t2 * PI2;
        if (theta_t2 > PI2)         theta_t2 -= PI2;
        else if (theta_t2 < 0)      theta_t2 += PI2;

        for(k = 0; k < 6; k++){
            sine_t[k] = (k+1) * 10 * sin(theta_t) + sine_offset_t[k];
            V_SM[k] = sine_t[k];
            Temp[k] = (k+1)*5;
            Temp[k+6] = (k+7)*5;
            if(k <= 3)  Flag_Buffer_HW[k] = 1;
            Flag_Buffer_SW[k] = 1;
        }

        switch(Dsp2EcatMaster.Slave_OP_Mode.bit.TEST_value)
        {
            case 0x1: //RELAY TEST
                for(k = 0; k < 6; k++) Flag_Relay[k] = 1;
                break;
            case 0x2: //IGBT TEST
                for(k = 0; k < 6; k++) Flag_IGBT[k] = 1;
                break;
            case 0x4: //FAN TEST
                for(k = 0; k < 6; k++) Flag_FAN[k] = 1;
                break;
            case 0x6: //Switching Duty : 1
                for(k = 0; k < 6; k++) REFERENCE_t[k] = 10000;
                break;
            case 0x8: //Switching Duty : 0
                for(k = 0; k < 6; k++) REFERENCE_t[k] = 0;
                break;
            case 0xA: //Switching Duty : 0.5
                for(k = 0; k < 6; k++) REFERENCE_t[k] = 5000;
                break;
            case 0xB: //Switching Duty : 0.5
                for(k = 0; k < 6; k++) REFERENCE_t[k] = 2500;
                break;
            case 0xC: //Switching Duty : 0.5
                for(k = 0; k < 6; k++) REFERENCE_t[k] = 1250;
                break;
            default :
                for(k = 0; k < 6; k++){
                    Flag_Relay[k] = 0;
                    Flag_IGBT[k] = 0;
                    Flag_FAN[k] = 0;
                    REFERENCE_t[k] =0;
                }
                break;
        }
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

    if(Dsp2EcatMaster.Operation.bit.EtherCAT_Ready == 1)
    {
        for(k = 0; k < 6; k++){
            if(k <= 3)  BUFFER_HW = BUFFER_HW | (((Uint16)Flag_Buffer_HW[k]) << k);
            BUFFER_SW = BUFFER_SW | (((Uint16)Flag_Buffer_SW[k]) << k);
            BUFFER_SW = BUFFER_SW | (((Uint16)Flag_Buffer_SW[k+3]) << (k+3));
        }
    }
    else
    {
        BUFFER_HW = 0x0000;
        BUFFER_SW = 0x0000;
    }

    if(Dsp2EcatMaster.SlaveStatus != 8){          //DSP1 send 0x8 to DSP 2 when it is in OP mode
        BUFFER_HW = 0x0000;
        BUFFER_SW = 0x0000;
    }

    *GATE_BUFFER_HW = BUFFER_HW;                  //74F240SC/SOIC buffer
    *GATE_BUFFER_SW = BUFFER_SW;                  //S/W buffer

   PWM_METHOD();

   return;
}

void PWM_METHOD(void)
{
    //Arm Current Direction
    Arm_Cur_Sign = Dsp2EcatMaster.Operation.bit.Arm_current_Dir;
    V_ref_NLC = Dsp2EcatMaster.REF;

    switch (PWM_MODE)// 1. NLC, 2. PD 3. PSC 4. default : NLC
    {
    case 1 :  NLC(Number_SM, Arm_Cur_Sign, V_ref_NLC, SM_INDEX_NEW, REFERENCE);              break;
    case 2 :  PD(Number_SM, Arm_Cur_Sign, V_ref_NLC, V_ref_PWM, SM_INDEX_NEW, REFERENCE);    break;
    case 3 :  PSC();                                                                         break;
    case 4 :  break;
    default:  NLC(Number_SM, Arm_Cur_Sign, V_ref_NLC, SM_INDEX_NEW, REFERENCE);              break;
    }

    if (Flag_Normal_DT == 8){
        for(k = 0; k < 6; k++) REFERENCE[k] = REFERENCE_t[k];
    }
    return;
}

void Reset(void)
{
    //Fault limit Setting
    SM_VOL_UNDER_Limit = Dsp2EcatMaster.SM_Vol_Under_Limit;
    SM_VOL_OVER_LIMIT = Dsp2EcatMaster.SM_Vol_Over_Limit;
    TEMP_LIMIT = Dsp2EcatMaster.SM_Temp_Limit;

    //Sensor MAX
    SM_VOL_MAX = 200;
    TEMP_MAX = 10.55;
    CUR_MAX = 207.5;

    //OPERATION_MODE FLAG
    Flag_Normal_DT = 0;
    Flag_Gating = 0;
    //PD_method
    PWM_x = 0;
    NLC_x = 0;
    //Final Reference, Device
    for(k = 0; k < Number_SM; k++){
        Flag_Relay[k] = 0;
        Flag_IGBT[k] = 0;
        Flag_FAN[k] = 0;
        REFERENCE_t[k] = 0;
        REFERENCE[k] = 0;
    }

    //PWM_MODE
    PWM_MODE = 0;
    return;

}
