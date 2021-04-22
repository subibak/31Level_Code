/*
 * Timer.c
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_Timer.h"

Uint32 Start_CNT = 4294963295, End_CNT = 0, Diff_CNT = 0;
Uint32 Compen_CNT = 0;
Uint16 Flag_Mode_Info = 0;

#define COMPEN_MAX          100
#define INV_COMPEN_MAX      0.01;

union CNT_DATA   DiffTime;
union CNT_DATA   DiffTimeSum;
union CNT_DATA   DiffTimeSumOffset;

void Init_Timer(void)
{
	// Timer Reset for Initializing.
    Timer5Regs.TIOCP_CFG.all = TIOCP_CFG_SOFTRESET_SWReset;
	while (Timer5Regs.TIOCP_CFG.bit.SOFTRESET == 1);


	// Timer Module Operation Mode.
	Timer5Regs.TIOCP_CFG.all = TIOCP_CFG_IDLEMODE_NoIDLE
								| TIOCP_CFG_EMUFREE_Free
								| TIOCP_CFG_SOFTRESET_Normal;

	// Timer Wake-Up Interrupt Event.

	// Timer Module Post Mode.
	Timer5Regs.TSICR.all = TSICR_READ_MODE_RDNonPostedMode
						| TSICR_POSTED_WRRDNonPostedMode;

	// Timer.
	//// Timer : Mode.
	while((Timer5Regs.TSICR.bit.POSTED == 1) && (Timer5Regs.TWPS.bit.W_PEND_TCLR == 1));
	Timer5Regs.TCLR.all = TCLR_CE_COMPDis
						| TCLR_PRE_PRESCALEDis
						| TCLR_PTV_PREDIV2
						| TCLR_AR_AutoReloadMode
						| TCLR_ST_TimerStop;

	//// Timer : Count Value.
	while((Timer5Regs.TSICR.bit.POSTED == 1) && (Timer5Regs.TWPS.bit.W_PEND_TCRR == 1));
	Timer5Regs.TCRR.all = 0xFFFFFFFF - 4000;

	//// Timer : Period Value.
	while((Timer5Regs.TSICR.bit.POSTED == 1) && (Timer5Regs.TWPS.bit.W_PEND_TLDR == 1));
	Timer5Regs.TLDR.all = 0xFFFFFFFF - 4000U;

	//// Timer : Interrupt.
	Timer5Regs.IRQENABLE_SET.all = IRQENABLE_OVF_INT;

	return;
}

void Start_Timer(void)
{
    Timer5Regs.TCLR.all |= TCLR_ST_TimerStart;

	return;
}

void Ecat_Time_Compen(void){

//    static Uint16 Compen_First = 0;

    End_CNT = Timer5Regs.TCRR.all;

    Diff_CNT = End_CNT - Start_CNT;

    if(Flag_EcatReady == 1) DiffTime.all_U = Diff_CNT * TIMER_NS_CLK;
    else                    DiffTime.all_U = 0;
//    if(Flag_EcatReady == 1)
//    {
//        if (Compen_First == 0)
//        {
//            if(Compen_CNT < COMPEN_MAX)
//            {
//                DiffTime.all_U = Diff_CNT * TIMER_NS_CLK;
//                DiffTimeSum.all_U += DiffTime.all_U;
//                Compen_CNT += 1;
//                DiffTimeSumOffset.all_U = 0;
//            }
//            else if(Compen_CNT == COMPEN_MAX)
//            {
//                DiffTimeSumOffset.all_U = DiffTimeSum.all_U * INV_COMPEN_MAX;
//                DiffTime.all_U = DiffTimeSumOffset.all_U;
//                DiffTimeSum.all_U = 0;
//                Compen_CNT = 0;
//                Compen_First = 1;
//            }
//        }
//        else
//        {
//            if(Mode_Info.all != Mode_Info_old.all) Flag_Mode_Info = 1;
//
//            if(Flag_Mode_Info == 0) DiffTime.all_U = DiffTimeSumOffset.all_U;
//            else
//            {
//                if(Compen_CNT < COMPEN_MAX)
//                {
//                    DiffTime.all_U = Diff_CNT * TIMER_NS_CLK;
//                    DiffTimeSum.all_U += DiffTime.all_U;
//                    Compen_CNT += 1;
//                    DiffTimeSumOffset.all_U = 0;
//                }
//                else if(Compen_CNT == COMPEN_MAX)
//                {
//                    DiffTimeSumOffset.all_U = DiffTimeSum.all_U * INV_COMPEN_MAX;
//                    DiffTime.all_U = DiffTimeSumOffset.all_U;
//                    DiffTimeSum.all_U = 0;
//                    Compen_CNT = 0;
//                    Flag_Mode_Info = 0;
//                }
//            }
//        }
//     }
//    else
//    {
//        DiffTime.all_U = 0;
//        DiffTimeSum.all_U = 0;
//        DiffTimeSumOffset.all_U = 0;
//    }
}
