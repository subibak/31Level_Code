#include "Define_Header.h"


int l = 0;

float VM1an_refu_norm = 0, VM1an_refl_norm = 0;
float VM1bn_refu_norm = 0, VM1bn_refl_norm = 0;
float VM1cn_refu_norm = 0, VM1cn_refl_norm = 0;

float Vxn_ref_NLC = 0;
float Vxn_ref_PWM = 0;
Uint16 PWM_x = 0, NLC_x = 0;
Uint16 Count_x = 0;

Uint16 SM_aU_REF[4] = {0, 0, 0, 0};
Uint16 SM_aL_REF[4] = {0, 0, 0, 0};
Uint16 SM_bU_REF[4] = {0, 0, 0, 0};
Uint16 SM_bL_REF[4] = {0, 0, 0, 0};
Uint16 SM_cU_REF[4] = {0, 0, 0, 0};
Uint16 SM_cL_REF[4] = {0, 0, 0, 0};

Uint16 Ref_test = 0;
Uint16 PWM_testa = 0, NLC_test = 0;

Uint16 PWM_testb = 0;
Uint16 PWM_testc = 0;
Uint16 PWM_testd = 0;

int test_flag = 0;

void PD_MOD(void)
{

	if (Flag_Indirectmodu ==1)
	{
		///////////////Reference Generation
		VM1an_refu = Vdc_ref*0.5 - VM1as_ref - Va0_ref;
		VM1an_refl = Vdc_ref*0.5 + VM1as_ref - Va0_ref;

		VM1bn_refu = Vdc_ref*0.5 - VM1bs_ref - Vb0_ref;
		VM1bn_refl = Vdc_ref*0.5 + VM1bs_ref - Vb0_ref;

		VM1cn_refu = Vdc_ref*0.5 - VM1cs_ref - Vc0_ref;
		VM1cn_refl = Vdc_ref*0.5 + VM1cs_ref - Vc0_ref;

		///////////////Normalize
		VM1an_refu_norm = VM1an_refu * Inv_V_AU * NUM_SM;
		VM1an_refl_norm = VM1an_refl * Inv_V_AL * NUM_SM;

		VM1bn_refu_norm = VM1bn_refu * Inv_V_BU * NUM_SM;
		VM1bn_refl_norm = VM1bn_refl * Inv_V_BL * NUM_SM;

		VM1cn_refu_norm = VM1cn_refu * Inv_V_CU * NUM_SM;
		VM1cn_refl_norm = VM1cn_refl * Inv_V_CL * NUM_SM;
	}
	else
	{
	    Inv_Vdc=1/Vdc_low;
	    ///////////////Reference Generation
		VM1an_refu = Vdc_ref*0.5 - VM1as_ref - Va0_ref;
		VM1an_refl = Vdc_ref*0.5 + VM1as_ref - Va0_ref;

		VM1bn_refu = Vdc_ref*0.5 - VM1bs_ref - Vb0_ref;
		VM1bn_refl = Vdc_ref*0.5 + VM1bs_ref - Vb0_ref;

		VM1cn_refu = Vdc_ref*0.5 - VM1cs_ref - Vc0_ref;
		VM1cn_refl = Vdc_ref*0.5 + VM1cs_ref - Vc0_ref;

		///////////////Normalize
		VM1an_refu_norm = VM1an_refu * Inv_Vdc * NUM_SM;
		VM1an_refl_norm = VM1an_refl * Inv_Vdc * NUM_SM;

		VM1bn_refu_norm = VM1bn_refu * Inv_Vdc * NUM_SM;
		VM1bn_refl_norm = VM1bn_refl * Inv_Vdc * NUM_SM;

		VM1cn_refu_norm = VM1cn_refu * Inv_Vdc * NUM_SM;
		VM1cn_refl_norm = VM1cn_refl * Inv_Vdc * NUM_SM;
	}


	Gating_Allocation(I_au, VM1an_refu_norm, SM_aU_INDEX_NEW, SM_aU_REF);
	Gating_Allocation(I_al, VM1an_refl_norm, SM_aL_INDEX_NEW, SM_aL_REF);
	Gating_Allocation(I_bu, VM1bn_refu_norm, SM_bU_INDEX_NEW, SM_bU_REF);
	Gating_Allocation(I_bl, VM1bn_refl_norm, SM_bL_INDEX_NEW, SM_bL_REF);
	Gating_Allocation(I_cu, VM1cn_refu_norm, SM_cU_INDEX_NEW, SM_cU_REF);
	Gating_Allocation(I_cl, VM1cn_refl_norm, SM_cL_INDEX_NEW, SM_cL_REF);

	if(test_flag == 1)
	{
        *FPGA_upper_ref_A1 =  PWM_testa;
        DELAY_US(0.1);
        *FPGA_upper_ref_A2 =  PWM_testb;
        DELAY_US(0.1);
        *FPGA_upper_ref_A3 =  PWM_testc;
        DELAY_US(0.1);
        *FPGA_upper_ref_A4 =  PWM_testd;
        DELAY_US(0.1);

        *FPGA_lower_ref_A1 =  PWM_testa;
        DELAY_US(0.1);
        *FPGA_lower_ref_A2 =  PWM_testb;
        DELAY_US(0.1);
        *FPGA_lower_ref_A3 =  PWM_testc;
        DELAY_US(0.1);
        *FPGA_lower_ref_A4 =  PWM_testd;
        DELAY_US(0.1);

        *FPGA_upper_ref_B1 =  PWM_testa;
        DELAY_US(0.1);
        *FPGA_upper_ref_B2 =  PWM_testb;
        DELAY_US(0.1);
        *FPGA_upper_ref_B3 =  PWM_testc;
        DELAY_US(0.1);
        *FPGA_upper_ref_B4 =  PWM_testd;
        DELAY_US(0.1);

        *FPGA_lower_ref_B1 = PWM_testa;
        DELAY_US(0.1);
        *FPGA_lower_ref_B2 = PWM_testb;
        DELAY_US(0.1);
        *FPGA_lower_ref_B3 = PWM_testc;
        DELAY_US(0.1);
        *FPGA_lower_ref_B4 =  PWM_testd;
        DELAY_US(0.1);

        *FPGA_upper_ref_C1 =  PWM_testa;
        DELAY_US(0.1);
        *FPGA_upper_ref_C2 = PWM_testb;
        DELAY_US(0.1);
        *FPGA_upper_ref_C3 =  PWM_testc;
        DELAY_US(0.1);
        *FPGA_upper_ref_C4 =  PWM_testd;
        DELAY_US(0.1);

        *FPGA_lower_ref_C1 =  PWM_testa;
        DELAY_US(0.1);
        *FPGA_lower_ref_C2 =  PWM_testb;
        DELAY_US(0.1);
        *FPGA_lower_ref_C3 =  PWM_testc;
        DELAY_US(0.1);
        *FPGA_lower_ref_C4 =  PWM_testd;
        DELAY_US(0.1);
	}
	else
	{
        *FPGA_upper_ref_A1 =  SM_aU_REF[0];
        DELAY_US(0.1);
        *FPGA_upper_ref_A2 =  SM_aU_REF[1];
        DELAY_US(0.1);
        *FPGA_upper_ref_A3 =  SM_aU_REF[2];
        DELAY_US(0.1);
        *FPGA_upper_ref_A4 =  SM_aU_REF[3];
        DELAY_US(0.1);

        *FPGA_lower_ref_A1 =  SM_aL_REF[0];
        DELAY_US(0.1);
        *FPGA_lower_ref_A2 =  SM_aL_REF[1];
        DELAY_US(0.1);
        *FPGA_lower_ref_A3 =  SM_aL_REF[2];
        DELAY_US(0.1);
        *FPGA_lower_ref_A4 =  SM_aL_REF[3];
        DELAY_US(0.1);

        *FPGA_upper_ref_B1 =  SM_bU_REF[0];
        DELAY_US(0.1);
        *FPGA_upper_ref_B2 =  SM_bU_REF[1];
        DELAY_US(0.1);
        *FPGA_upper_ref_B3 =  SM_bU_REF[2];
        DELAY_US(0.1);
        *FPGA_upper_ref_B4 =  SM_bU_REF[3];
        DELAY_US(0.1);

        *FPGA_lower_ref_B1 =  SM_bL_REF[0];
        DELAY_US(0.1);
        *FPGA_lower_ref_B2 =  SM_bL_REF[1];
        DELAY_US(0.1);
        *FPGA_lower_ref_B3 =  SM_bL_REF[2];
        DELAY_US(0.1);
        *FPGA_lower_ref_B4 =  SM_bL_REF[3];
        DELAY_US(0.1);

        *FPGA_upper_ref_C1 =  SM_cU_REF[0];
        DELAY_US(0.1);
        *FPGA_upper_ref_C2 =  SM_cU_REF[1];
        DELAY_US(0.1);
        *FPGA_upper_ref_C3 =  SM_cU_REF[2];
        DELAY_US(0.1);
        *FPGA_upper_ref_C4 =  SM_cU_REF[3];
        DELAY_US(0.1);

        *FPGA_lower_ref_C1 =  SM_cL_REF[0];
        DELAY_US(0.1);
        *FPGA_lower_ref_C2 =  SM_cL_REF[1];
        DELAY_US(0.1);
        *FPGA_lower_ref_C3 =  SM_cL_REF[2];
        DELAY_US(0.1);
        *FPGA_lower_ref_C4 =  SM_cL_REF[3];
        DELAY_US(0.1);
	}

//////////////////////////////////////////////////////////////////////////
//////Initialization of Reference//////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

    for(l = 0; l < NUM_SM; l++)
    {
        SM_aU_REF[l] = 0;
        SM_aL_REF[l] = 0;
        SM_bU_REF[l] = 0;
        SM_bL_REF[l] = 0;
        SM_cU_REF[l] = 0;
        SM_cL_REF[l] = 0;
    }

	return;
}


/////Gating_Allocation(arm current, normalized reference, voltage balance index, output reference)
void Gating_Allocation(float I_arm, float Vxn_ref_norm, int SM_INDEX[], Uint16 SM_REF[])
{

    if(Vxn_ref_norm < 0)
        Vxn_ref_norm = 0;

    Vxn_ref_NLC = floor(Vxn_ref_norm);
    Vxn_ref_PWM = Vxn_ref_norm - Vxn_ref_NLC;

    Count_x = Vxn_ref_PWM * MAX_CNT_CARRRIER1;

    PWM_x = (Uint16)((Count_x > MAX_CNT_CARRRIER1)? MAX_CNT_CARRRIER1 : Count_x);
    NLC_x = (Uint16)(Vxn_ref_NLC);

    if(I_arm > 0)
    {
        if(NLC_x >= NUM_SM)
        {
            for(l = 0; l < NUM_SM; l++)
            {
                SM_REF[SM_INDEX[l]-1] =  MAX_CNT_CARRRIER1;
            }
        }
        else if(NLC_x <= 0)
        {
            for(l = 0; l < NUM_SM; l++)
            {
                SM_REF[SM_INDEX[l]-1] = 0;
            }
            SM_REF[SM_INDEX[0]-1] = PWM_x;
        }
        else
        {
            for(l = 0; l < NLC_x; l++)
            {
                SM_REF[SM_INDEX[l]-1] = MAX_CNT_CARRRIER1;
            }
            SM_REF[SM_INDEX[NLC_x]-1] = PWM_x;
        }
    }
    else
    {
        if(NLC_x >= NUM_SM)
        {
            for(l = 0; l < NUM_SM; l++)
            {
                SM_REF[SM_INDEX[l]-1] =  MAX_CNT_CARRRIER1;
            }
        }
        else if(NLC_x <= 0)
        {
            for(l = 0; l < NUM_SM; l++)
            {
                SM_REF[SM_INDEX[l]-1] = 0;
            }
            SM_REF[SM_INDEX[NUM_SM-1]-1] = PWM_x;
        }
        else
        {
            for(l = 0; l < NLC_x; l++)
            {
                SM_REF[SM_INDEX[NUM_SM - l - 1]-1] = MAX_CNT_CARRRIER1;
            }
            SM_REF[SM_INDEX[NUM_SM-NLC_x-1]-1] = PWM_x;
        }
    }
}



