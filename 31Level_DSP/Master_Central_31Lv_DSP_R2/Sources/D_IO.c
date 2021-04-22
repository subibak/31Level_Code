/*
 * D_IO.c
 *
 *  Created on: 2019. 1. 12.
 *      Author: subi
 */

#include "Define_Header.h"
float PRE_MC_TIME = 0;
float Timer_Set_Value =100e6;             ///MAIN_MC can be operated after the PRE_MC is 0.5 second
Uint32 PRE_MC_CNT_MAX = 30000;
Uint32 Pre_MC_cnt = 0;

/*
void MC_OP(void)
{
    if(Mode_Info.bit.Flag_Pre_MC== 1)
    {
        PRE_MC_ON;
        Pre_MC_cnt++;
    }


    if((Mode_Info.bit.Flag_Main_MC== 1) && (Pre_MC_cnt > PRE_MC_CNT_MAX))
    {
        MAIN_MC_ON;
        Mode_Info.bit.Flag_Pre_MC =0;

    }

    if((Mode_Info.bit.Flag_Main_MC== 0) && (Mode_Info.bit.Flag_Pre_MC== 0))
    {
       MAIN_MC_OFF;
       PRE_MC_OFF;
    }

    if(Flag_fault == 1)
    {
        Mode_Info.bit.Flag_Pre_MC =0;
        MAIN_MC_OFF;
        PRE_MC_OFF;
        Pre_MC_cnt = 0;
    }

}


void MC_OP_Inv(void)
{
    PRE_MC_ON;

    if(++ PRE_MC_TIME >= Timer_Set_Value)
    MAIN_MC_ON;

    if(Flag_fault == 1)
    {
        Mode_Info.bit.Flag_Pre_MC =0;
        MAIN_MC_OFF;
        PRE_MC_OFF;
        Pre_MC_cnt = 0;
    }

    return ;
}
*/

