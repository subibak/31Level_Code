/*
 * Group_sorting.c
 *
 *  Created on: Jan 2, 2019
 *      Author: Belete
 */

#include "Define_Header.h"
#include "Define_MMC_controller.h"

float VM1an_refu=0, VM1an_refl =0, VM1bn_refu =0, VM1bn_refl =0, VM1cn_refu =0, VM1cn_refl =0;
float V_AU_arm =0, V_AL_arm =0, V_BU_arm =0, V_BL_arm =0, V_CU_arm =0, V_CL_arm =0;
float Inv_V_AU, Inv_V_AL, Inv_V_BU, Inv_V_BL, Inv_V_CU, Inv_V_CU, Inv_V_CL;
Uint16 NUM_SM =30;
Uint16 NUM_group =5;
Uint16 i, j, k;

float Inv_Vdc;

float VM1an_refu_norm =0, VM1an_refl_norm =0, VM1bn_refu_norm =0, VM1bn_refl_norm =0, VM1cn_refu_norm =0, VM1cn_refl_norm =0;
float SMua_on =0, SMla_on =0, SMub_on =0, SMlb_on =0, SMuc_on =0, SMlc_on =0;

float V_AU[5] = {0, 0, 0, 0, 0};
float V_AL[5] = {0, 0, 0, 0, 0};
float V_BU[5] = {0, 0, 0, 0, 0};
float V_BL[5] = {0, 0, 0, 0, 0};
float V_CU[5] = {0, 0, 0, 0, 0};
float V_CL[5] = {0, 0, 0, 0, 0};

union REF_DATA    NLC_REF_AU;
union REF_DATA    NLC_REF_AL;
union REF_DATA    NLC_REF_BU;
union REF_DATA    NLC_REF_BL;
union REF_DATA    NLC_REF_CU;
union REF_DATA    NLC_REF_CL;

float NLC_test[6] = {0,0,0,0,0,0};

Uint32 DC_CHARGE_cnt = 0;
float DC_CHARGE_RAMP  =  1e-4;      // 1 sec  5000 count (in 200us)(DC_CHARGE) => 1/5000
float Vdc_char_ref = 850;

void NLC(void)
{
    if (Mode_Info.bit.Control_Method == 2)                     //Indirect modulation method
    {
        //upper and lower arm reference voltage generation
        VM1an_refu = Vdc_ref*0.5 - VM1as_ref - Va0_ref;
        VM1an_refl = Vdc_ref*0.5 + VM1as_ref - Va0_ref;

        VM1bn_refu = Vdc_ref*0.5 - VM1bs_ref - Vb0_ref;
        VM1bn_refl = Vdc_ref*0.5 + VM1bs_ref - Vb0_ref;

        VM1cn_refu = Vdc_ref*0.5 - VM1cs_ref - Vc0_ref;
        VM1cn_refl = Vdc_ref*0.5 + VM1cs_ref - Vc0_ref;

        //calculation of the real arm voltage from Group submodule voltages
        V_AU_arm = V_AU[0] + V_AU[1] + V_AU[2] + V_AU[3] + V_AU[4];
        V_AL_arm = V_AL[0] + V_AL[1] + V_AL[2] + V_AL[3] + V_AL[4];

        V_BU_arm = V_BU[0] + V_BU[1] + V_BU[2] + V_BU[3] + V_BU[4];
        V_BL_arm = V_BL[0] + V_BL[1] + V_BL[2] + V_BL[3] + V_BL[4];

        V_CU_arm = V_CU[0] + V_CU[1] + V_CU[2] + V_CU[3] + V_CU[4];
        V_CL_arm = V_CL[0] + V_CL[1] + V_CL[2] + V_CL[3] + V_CL[4];

        Inv_V_AU = 1/V_AU_arm;
        Inv_V_AL = 1/V_AL_arm;

        Inv_V_BU = 1/V_BU_arm;
        Inv_V_BL = 1/V_BL_arm;

        Inv_V_CU = 1/V_CU_arm;
        Inv_V_CL = 1/V_CL_arm;

        //Normalizing the arm reference by the actual arm voltage(Indirect modulation)
        VM1an_refu_norm = VM1an_refu * Inv_V_AU * NUM_SM;
        VM1an_refl_norm = VM1an_refl * Inv_V_AL * NUM_SM;

        VM1bn_refu_norm = VM1bn_refu * Inv_V_BU * NUM_SM;
        VM1bn_refl_norm = VM1bn_refl * Inv_V_BL * NUM_SM;

        VM1cn_refu_norm = VM1cn_refu * Inv_V_CU * NUM_SM;
        VM1cn_refl_norm = VM1cn_refl * Inv_V_CL * NUM_SM;

    }
    else if(Mode_Info.bit.Control_Method == 1)                            //Direct modulation method
    {
        Inv_Vdc=1/Vdc_rated;
//        Inv_Vdc=1/Vdc_low;
        //upper and lower arm reference voltage generation
        VM1an_refu = Vdc_rated * 0.5 - VM1as_ref - Va0_ref - Vxo_ref + Vdc_char_ref;
        VM1an_refl = Vdc_rated * 0.5 + VM1as_ref - Va0_ref - Vxo_ref + Vdc_char_ref;

        VM1bn_refu = Vdc_rated * 0.5 - VM1bs_ref - Vb0_ref - Vxo_ref + Vdc_char_ref;
        VM1bn_refl = Vdc_rated * 0.5 + VM1bs_ref - Vb0_ref - Vxo_ref + Vdc_char_ref;

        VM1cn_refu = Vdc_rated * 0.5 - VM1cs_ref - Vc0_ref - Vxo_ref + Vdc_char_ref;
        VM1cn_refl = Vdc_rated * 0.5 + VM1cs_ref - Vc0_ref - Vxo_ref + Vdc_char_ref;

        VM1an_refu= BOUND1(VM1an_refu, Vdc_rated);
        VM1an_refl= BOUND1(VM1an_refl, Vdc_rated);
        VM1bn_refu= BOUND1(VM1bn_refu, Vdc_rated);
        VM1bn_refl= BOUND1(VM1bn_refl, Vdc_rated);
        VM1cn_refu= BOUND1(VM1cn_refu, Vdc_rated);
        VM1cn_refl= BOUND1(VM1cn_refl, Vdc_rated);

        VM1as_sat =(VM1an_refl-VM1an_refu) * 0.5;
        VM1bs_sat =(VM1bn_refl-VM1bn_refu) * 0.5;
        VM1cs_sat =(VM1cn_refl-VM1cn_refu) * 0.5;

        //Normalizing the arm reference by the rated DC voltage(Direct modulation)
        VM1an_refu_norm = VM1an_refu * Inv_Vdc * NUM_SM;
        VM1an_refl_norm = VM1an_refl * Inv_Vdc * NUM_SM;

        VM1bn_refu_norm = VM1bn_refu * Inv_Vdc * NUM_SM;
        VM1bn_refl_norm = VM1bn_refl * Inv_Vdc * NUM_SM;

        VM1cn_refu_norm = VM1cn_refu * Inv_Vdc * NUM_SM;
        VM1cn_refl_norm = VM1cn_refl * Inv_Vdc * NUM_SM;
    }

    //rounding the resulting number of on submodule to the nearest integer
    if(VM1an_refu_norm - floor(VM1an_refu_norm) >=0.5)  SMua_on = ceil(VM1an_refu_norm);
    else                                                SMua_on = floor(VM1an_refu_norm);

    if(VM1an_refl_norm - floor(VM1an_refl_norm) >=0.5)  SMla_on = ceil(VM1an_refl_norm);
    else                                                SMla_on = floor(VM1an_refl_norm);

    if(VM1bn_refu_norm - floor(VM1bn_refu_norm) >=0.5)  SMub_on = ceil(VM1bn_refu_norm);
    else                                                SMub_on = floor(VM1bn_refu_norm);

    if(VM1bn_refl_norm - floor(VM1bn_refl_norm) >=0.5)  SMlb_on = ceil(VM1bn_refl_norm);
    else                                                SMlb_on = floor(VM1bn_refl_norm);

    if(VM1cn_refu_norm - floor(VM1cn_refu_norm) >=0.5)  SMuc_on = ceil(VM1cn_refu_norm);
    else                                                SMuc_on = floor(VM1cn_refu_norm);

    if(VM1cn_refl_norm - floor(VM1cn_refl_norm) >=0.5)  SMlc_on = ceil(VM1cn_refl_norm);
    else                                                SMlc_on = floor(VM1cn_refl_norm);

    NLC_REF_AU.all_U = SMua_on;
    NLC_REF_AL.all_U = SMla_on;
    NLC_REF_BU.all_U = SMub_on;
    NLC_REF_BL.all_U = SMlb_on;
    NLC_REF_CU.all_U = SMuc_on;
    NLC_REF_CL.all_U = SMlc_on;

//    NLC_REF_AU.all_U = NLC_test[0];
//    NLC_REF_AL.all_U = NLC_test[1];
//    NLC_REF_BU.all_U = NLC_test[2];
//    NLC_REF_BL.all_U = NLC_test[3];
//    NLC_REF_CU.all_U = NLC_test[4];
//    NLC_REF_CL.all_U = NLC_test[5];
}

void DC_CHRAGING_SEQ(void)
{
    if(Vdc_char_ref <= 0)
    {
        Vdc_char_ref = 0;
        Flag_gating = 0;
    }
    else
    {
        Flag_gating = 1;
        Vdc_char_ref -= Vdc_rated*DC_CHARGE_RAMP;
    }

    VM1as_ref = 0;
    VM1bs_ref = 0;
    VM1cs_ref = 0;

    Va0_ref = 0;
    Vb0_ref = 0;
    Vc0_ref = 0;

    Vxo_ref = 0;
}
