/*
 * Mailbox.c
 *
 *  Created on: 2019. 1. 9.
 *      Author: subi
 */

#include "Define_Header.h"

struct HMI_TO_CENTRAL_MASTER HmiCen;

Uint32 MAILBOX_EX_RD[12];
Uint32 MAILBOX_EX_WR[12];

//HMI to Central Master
void Mailbox_RD(void)
{
    //Reference : EtherCAT Packet Configuration (190207).xls HMI_MASTER sheet

    // while(MAILBOX5Regs.MAILBOX_MSGSTATUS_11.bit.NBOFMSGMBM == 0);
    HmiCen.STATUS.all        = MAILBOX2Regs.MAILBOX_MESSAGE_0.MESSAGEVALUEMBM;
    HmiCen.kpll_p            = (float)MAILBOX2Regs.MAILBOX_MESSAGE_1.MESSAGEVALUEMBM;                    //pll_p
    HmiCen.kpll_i            = (float)MAILBOX2Regs.MAILBOX_MESSAGE_2.MESSAGEVALUEMBM;                    //pll_i
    HmiCen.kcur_p            = (float)MAILBOX2Regs.MAILBOX_MESSAGE_3.MESSAGEVALUEMBM;                    //current p
    HmiCen.kcur_i            = (float)MAILBOX2Regs.MAILBOX_MESSAGE_4.MESSAGEVALUEMBM;                    //current i
    HmiCen.kcur_a            = (float)MAILBOX2Regs.MAILBOX_MESSAGE_5.MESSAGEVALUEMBM;                    //current a
    HmiCen.kccsc_p           = (float)MAILBOX2Regs.MAILBOX_MESSAGE_6.MESSAGEVALUEMBM;                    //ccsc p
    HmiCen.kccsc_i           = (float)MAILBOX2Regs.MAILBOX_MESSAGE_7.MESSAGEVALUEMBM;                    //ccsc i
    HmiCen.kv_p              = (float)MAILBOX2Regs.MAILBOX_MESSAGE_8.MESSAGEVALUEMBM;                    //Vdc p
    HmiCen.kv_i              = (float)MAILBOX2Regs.MAILBOX_MESSAGE_9.MESSAGEVALUEMBM;                    //Vdc i
    HmiCen.ktotal_p          = (float)MAILBOX2Regs.MAILBOX_MESSAGE_10.MESSAGEVALUEMBM;                   //total energy p
    HmiCen.ktotal_i          = (float)MAILBOX2Regs.MAILBOX_MESSAGE_11.MESSAGEVALUEMBM;                   //total energy i

    HmiCen.ktotal_p          = (float)MAILBOX3Regs.MAILBOX_MESSAGE_0.MESSAGEVALUEMBM;                    //leg energy p
    HmiCen.ktotal_i          = (float)MAILBOX3Regs.MAILBOX_MESSAGE_1.MESSAGEVALUEMBM;                    //leg energy i
    HmiCen.kdiffc_p          = (float)MAILBOX3Regs.MAILBOX_MESSAGE_2.MESSAGEVALUEMBM;                    //diff common energy p
    HmiCen.kdiffc_i          = (float)MAILBOX3Regs.MAILBOX_MESSAGE_3.MESSAGEVALUEMBM;                    //diff common energy i
    HmiCen.kdiffd_p          = (float)MAILBOX3Regs.MAILBOX_MESSAGE_4.MESSAGEVALUEMBM;                    //diff diff energy p
    HmiCen.kdiffd_i          = (float)MAILBOX3Regs.MAILBOX_MESSAGE_5.MESSAGEVALUEMBM;                    //diff diff energy i
    HmiCen.Vdc_ref           = (float)MAILBOX3Regs.MAILBOX_MESSAGE_6.MESSAGEVALUEMBM;                    //Vdc ref
    HmiCen.pf_ref            = (float)MAILBOX3Regs.MAILBOX_MESSAGE_7.MESSAGEVALUEMBM;                    //pf ref
    HmiCen.P_ref             = (float)MAILBOX3Regs.MAILBOX_MESSAGE_8.MESSAGEVALUEMBM;                    //Active power ref
    HmiCen.Q_ref             = (float)MAILBOX3Regs.MAILBOX_MESSAGE_9.MESSAGEVALUEMBM;                    //Reactive power ref
    HmiCen.Etotal_ref        = (float)MAILBOX3Regs.MAILBOX_MESSAGE_10.MESSAGEVALUEMBM;                   //total energy ref
    HmiCen.Ediffc_ref        = (float)MAILBOX3Regs.MAILBOX_MESSAGE_11.MESSAGEVALUEMBM;                   //diff common ref

    HmiCen.Ediffd_ref        = (float)MAILBOX4Regs.MAILBOX_MESSAGE_0.MESSAGEVALUEMBM;                    //diff diff ref
    HmiCen.ref_method        = (float)MAILBOX4Regs.MAILBOX_MESSAGE_1.MESSAGEVALUEMBM;                    //ref method(ramp, step)
    HmiCen.ramp_time         = MAILBOX4Regs.MAILBOX_MESSAGE_2.MESSAGEVALUEMBM;                           //ramp time
    HmiCen.Vphase_limit      = MAILBOX4Regs.MAILBOX_MESSAGE_3.MESSAGEVALUEMBM;                           //phase voltage limit
    HmiCen.Iphase_limit      = MAILBOX4Regs.MAILBOX_MESSAGE_4.MESSAGEVALUEMBM;                           //phase current limit
    HmiCen.Iarm_limit        = MAILBOX4Regs.MAILBOX_MESSAGE_5.MESSAGEVALUEMBM;                           //arm current limit
    HmiCen.Vdc_under_limit   = MAILBOX4Regs.MAILBOX_MESSAGE_6.MESSAGEVALUEMBM;                           //dc under voltage limit
    HmiCen.Vdc_over_limit    = MAILBOX4Regs.MAILBOX_MESSAGE_7.MESSAGEVALUEMBM;                           //dc over voltage limit
    HmiCen.Idc_limit         = MAILBOX4Regs.MAILBOX_MESSAGE_8.MESSAGEVALUEMBM;                           //dc current limit
    HmiCen.Vsm_under_limit   = MAILBOX4Regs.MAILBOX_MESSAGE_9.MESSAGEVALUEMBM;                           //submodule under voltage limit
    HmiCen.Vsm_over_limit    = MAILBOX4Regs.MAILBOX_MESSAGE_10.MESSAGEVALUEMBM;                          //submodule over voltage limit
    HmiCen.Temp_limit        = MAILBOX4Regs.MAILBOX_MESSAGE_11.MESSAGEVALUEMBM;                          //submodule temp limit

    MAILBOX_EX_RD[0] = MAILBOX5Regs.MAILBOX_MESSAGE_0.MESSAGEVALUEMBM;                                   //Ex_data1
    MAILBOX_EX_RD[1] = MAILBOX5Regs.MAILBOX_MESSAGE_1.MESSAGEVALUEMBM;                                   //Ex_data2
    MAILBOX_EX_RD[2] = MAILBOX5Regs.MAILBOX_MESSAGE_2.MESSAGEVALUEMBM;                                   //Ex_data3
    MAILBOX_EX_RD[3] = MAILBOX5Regs.MAILBOX_MESSAGE_3.MESSAGEVALUEMBM;                                   //Ex_data4
    MAILBOX_EX_RD[4] = MAILBOX5Regs.MAILBOX_MESSAGE_4.MESSAGEVALUEMBM;                                   //Ex_data5
    MAILBOX_EX_RD[5] = MAILBOX5Regs.MAILBOX_MESSAGE_5.MESSAGEVALUEMBM;                                   //Ex_data6
    MAILBOX_EX_RD[6] = MAILBOX5Regs.MAILBOX_MESSAGE_6.MESSAGEVALUEMBM;                                   //Ex_data7
    MAILBOX_EX_RD[7] = MAILBOX5Regs.MAILBOX_MESSAGE_7.MESSAGEVALUEMBM;                                   //Ex_data8
    MAILBOX_EX_RD[8] = MAILBOX5Regs.MAILBOX_MESSAGE_8.MESSAGEVALUEMBM;                                   //Ex_data9
    MAILBOX_EX_RD[9] = MAILBOX5Regs.MAILBOX_MESSAGE_9.MESSAGEVALUEMBM;                                   //Ex_data10
    MAILBOX_EX_RD[10] = MAILBOX5Regs.MAILBOX_MESSAGE_10.MESSAGEVALUEMBM;                                 //Ex_data11 = 0 (USE x)
    MAILBOX_EX_RD[11] = MAILBOX5Regs.MAILBOX_MESSAGE_11.MESSAGEVALUEMBM;                                 //Ex_data12 = 0 (USE x_

}

//HMI to Central Master
void Mailbox_WR(void)
{
    //Reference : EtherCAT Packet Configuration (190207).xls HMI_MASTER sheet

    //while(MAILBOX6Regs.MAILBOX_FIFOSTATUS_0.bit.FIFOFULLMBM == 1);
    MAILBOX6Regs.MAILBOX_MESSAGE_0.MESSAGEVALUEMBM = V_AS_sec_T.all_U;
    MAILBOX6Regs.MAILBOX_MESSAGE_1.MESSAGEVALUEMBM = V_BS_sec_T.all_U;
    MAILBOX6Regs.MAILBOX_MESSAGE_2.MESSAGEVALUEMBM = V_CS_sec_T.all_U;
    MAILBOX6Regs.MAILBOX_MESSAGE_3.MESSAGEVALUEMBM = I_AS_T.all_U;
    MAILBOX6Regs.MAILBOX_MESSAGE_4.MESSAGEVALUEMBM = I_BS_T.all_U;
    MAILBOX6Regs.MAILBOX_MESSAGE_5.MESSAGEVALUEMBM = I_CS_T.all_U;
    MAILBOX6Regs.MAILBOX_MESSAGE_6.MESSAGEVALUEMBM = I_AU_T.all_U;
    MAILBOX6Regs.MAILBOX_MESSAGE_7.MESSAGEVALUEMBM = I_AL_T.all_U;
    MAILBOX6Regs.MAILBOX_MESSAGE_8.MESSAGEVALUEMBM = I_BU_T.all_U;
    MAILBOX6Regs.MAILBOX_MESSAGE_9.MESSAGEVALUEMBM = I_BL_T.all_U;
    MAILBOX6Regs.MAILBOX_MESSAGE_10.MESSAGEVALUEMBM = I_CU_T.all_U;
    MAILBOX6Regs.MAILBOX_MESSAGE_11.MESSAGEVALUEMBM = I_CL_T.all_U;

    MAILBOX7Regs.MAILBOX_MESSAGE_0.MESSAGEVALUEMBM = P.all_U;
    MAILBOX7Regs.MAILBOX_MESSAGE_1.MESSAGEVALUEMBM = Q.all_U;
    MAILBOX7Regs.MAILBOX_MESSAGE_2.MESSAGEVALUEMBM = V_DC_T.all_U;
    MAILBOX7Regs.MAILBOX_MESSAGE_3.MESSAGEVALUEMBM = I_DC_T.all_U;
    MAILBOX7Regs.MAILBOX_MESSAGE_4.MESSAGEVALUEMBM = pf.all_U;                                             //Pf
    MAILBOX7Regs.MAILBOX_MESSAGE_5.MESSAGEVALUEMBM = CenHmi_Fault_Req.all;                                             //Fault
    MAILBOX7Regs.MAILBOX_MESSAGE_6.MESSAGEVALUEMBM = CenHmi_Status.all;                                             //device status(MC, EtherCAT)

    MAILBOX7Regs.MAILBOX_MESSAGE_7.MESSAGEVALUEMBM = MAILBOX_EX_WR[0];
    MAILBOX7Regs.MAILBOX_MESSAGE_8.MESSAGEVALUEMBM = MAILBOX_EX_WR[1];
    MAILBOX7Regs.MAILBOX_MESSAGE_9.MESSAGEVALUEMBM = MAILBOX_EX_WR[2];
    MAILBOX7Regs.MAILBOX_MESSAGE_10.MESSAGEVALUEMBM = MAILBOX_EX_WR[3];
    MAILBOX7Regs.MAILBOX_MESSAGE_11.MESSAGEVALUEMBM = MAILBOX_EX_WR[4];
}


#define STOP_TIME  30000

union CEN_HMI_FAULT_FLAG_REQ CenHmi_Fault_Req;
union CEN_HMI_STATUS CenHmi_Status;

Uint16 Stop_cnt = 0;
Uint16 Vdc_test = 0;

void HMI_CenMa_Matching(void)
{
    //Receiving
    //Gating
    if(HmiCen.STATUS.bit.Flag_Controller > 0)
    {
        if(Mode_Info.bit.Valve_type == 1)        Inv_start = 1;
        else if(Mode_Info.bit.Valve_type == 2)   Conv_start = 1;

        Stop_cnt = 0;
    }
    else
    {
        if(Stop_cnt++ <= STOP_TIME)
            Inv_start = 0;
        else
        {
            Conv_start = 0;
            Stop_cnt = 0;
        }
    }

    if(Vdc_low >= Vdc_rated)
        CenHmi_Fault_Req.bit.LEFT_START_REQ = 1;
    else
        CenHmi_Fault_Req.bit.LEFT_START_REQ = 0;
    //Sending
    CenHmi_Fault_Req.bit.I_AL = Flag_fault;
    CenHmi_Fault_Req.bit.STOP_REQ = Flag_fault;

    CenHmi_Status.bit.ECAT_ERROR = Flag_EcatReady;

    if (GPIO3Regs.GPIO_DATAIN.bit.IO22 == 1)  CenHmi_Status.bit.Pre_MC = 0;
    else                                      CenHmi_Status.bit.Pre_MC = 1;

    if (GPIO3Regs.GPIO_DATAIN.bit.IO20 == 1)  CenHmi_Status.bit.Main_MC = 0;
    else                                      CenHmi_Status.bit.Main_MC = 1;

    if (GPIO3Regs.GPIO_DATAIN.bit.IO24 == 1)  CenHmi_Status.bit.Valve_UPS = 0;
    else                                      CenHmi_Status.bit.Valve_UPS = 1;
 //   CenHmi.
}
