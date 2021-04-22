/*
 * PWM.c
 *
 *  Created on: 2018. 8. 29.
 *      Author: subi
 */

#include "Define_Header.h"
#include "Define_Header.h"

int Flag_Buffer_HW[4] = {0,0,0,0};
int Flag_Buffer_SW[6] = {0,0,0,0,0,0};

Uint16 BUFFER_HW = 0;
Uint16 BUFFER_SW = 0;

Uint16 V_ref_NLC = 0;
Uint16 V_ref_PWM = 0;
Uint16 PWM_x = 0, NLC_x = 0;

Uint16 REFERENCE[6] = {0,0,0,0,0,0};
Uint16 REFERENCE_t[6] = {0,0,0,0,0,0};

void PMW_INIT(void)
{
    *CARRIER_INIT_A1 =0x00;
    *CARRIER_INIT_A2 =0x00;
    *CARRIER_INIT_A3 =0x00;
    *CARRIER_INIT_B1 =0x00;
    *CARRIER_INIT_B2 =0x00;
    *CARRIER_INIT_B3 =0x00;
    *CARRIER_INIT_HALF = 0x00;

    *COMPARATOR_INIT_MAX = 0x00;
    *COMPARATOR_INIT_MIN = 0x00;
}

void GATING(Uint16 Ref[])
{
    *COMPARATOR_REF_A1 = Ref[0];
    *COMPARATOR_REF_A2 = Ref[1];
    *COMPARATOR_REF_A3 = Ref[2];
    *COMPARATOR_REF_B1 = Ref[3];
    *COMPARATOR_REF_B2 = Ref[4];
    *COMPARATOR_REF_B3 = Ref[5];
}

void PD(int NUM_SM, Uint16 Cur_dir, Uint16 Vxn_ref_NLC, Uint16 Vxn_ref_PWM, int SM_INDEX[], Uint16 SM_REF[])
{
    PWM_x = (Vxn_ref_PWM > MAX_CNT_CARRIER)? MAX_CNT_CARRIER : Vxn_ref_PWM;

    if(Cur_dir > 0)
    {
        if(Vxn_ref_NLC >= NUM_SM)
        {
            for(l = 0; l < NUM_SM; l++)
            {
                SM_REF[SM_INDEX[l]-1] =  MAX_CNT_CARRIER;
            }
        }
        else if(Vxn_ref_NLC <= 0)
        {
            for(l = 0; l < NUM_SM; l++)
            {
                SM_REF[SM_INDEX[l]-1] = 0;
            }
            SM_REF[SM_INDEX[0]-1] = PWM_x;
        }
        else
        {
            for(l = 0; l < Vxn_ref_NLC; l++)
            {
                SM_REF[SM_INDEX[l]-1] = MAX_CNT_CARRIER;
            }
            SM_REF[SM_INDEX[Vxn_ref_NLC]-1] = PWM_x;
        }
    }
    else
    {
        if(Vxn_ref_NLC >= NUM_SM)
        {
            for(l = 0; l < NUM_SM; l++)
            {
                SM_REF[SM_INDEX[l]-1] =  MAX_CNT_CARRIER;
            }
        }
        else if(Vxn_ref_NLC <= 0)
        {
            for(l = 0; l < NUM_SM; l++)
            {
                SM_REF[SM_INDEX[l]-1] = 0;
            }
            SM_REF[SM_INDEX[NUM_SM-1]-1] = PWM_x;
        }
        else
        {
            for(l = 0; l < Vxn_ref_NLC; l++)
            {
                SM_REF[SM_INDEX[NUM_SM - l - 1]-1] = MAX_CNT_CARRIER;
            }
            SM_REF[SM_INDEX[NUM_SM-Vxn_ref_NLC-1]-1] = PWM_x;
        }
    }
}


void NLC(int NUM_SM, Uint16 Cur_dir, Uint16 Vxn_ref_NLC, int SM_INDEX[], Uint16 SM_REF[])
{

    if(Cur_dir > 0)
    {
        if(Vxn_ref_NLC >= NUM_SM)
        {
            for(l = 0; l < NUM_SM; l++)
            {
                SM_REF[SM_INDEX[l]-1] =  MAX_CNT_CARRIER;
            }
        }
        else if(Vxn_ref_NLC <= 0)
        {
            for(l = 0; l < NUM_SM; l++)
            {
                SM_REF[SM_INDEX[l]-1] = 0;
            }
        }
        else
        {
            for(l = 0; l < Vxn_ref_NLC; l++)
            {
                SM_REF[SM_INDEX[l]-1] = MAX_CNT_CARRIER;
            }
        }
    }
    else
    {
        if(Vxn_ref_NLC >= NUM_SM)
        {
            for(l = 0; l < NUM_SM; l++)
            {
                SM_REF[SM_INDEX[l]-1] =  MAX_CNT_CARRIER;
            }
        }
        else if(Vxn_ref_NLC <= 0)
        {
            for(l = 0; l < NUM_SM; l++)
            {
                SM_REF[SM_INDEX[l]-1] = 0;
            }
        }
        else
        {
            for(l = 0; l < Vxn_ref_NLC; l++)
            {
                SM_REF[SM_INDEX[NUM_SM - l - 1]-1] = MAX_CNT_CARRIER;
            }
        }
    }
}

void PSC(void)
{

}
