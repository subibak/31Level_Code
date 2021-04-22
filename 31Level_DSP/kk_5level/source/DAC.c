// Slave DAC

#define DAC8420					0
#define DAC8803					TARGET

#include "Define_Header.h"
#include "Define_DAC.h"

S_DA da1, da2, da3, da4, da5, da6, da7, da8;

Uint16 da1_tmp = 0, da2_tmp = 0, da3_tmp = 0, da4_tmp = 0;
Uint16 da5_tmp = 0, da6_tmp = 0, da7_tmp = 0, da8_tmp = 0;

int switch_case = 1, da_sel = 1;
int Vref_U = 0,  Vref_V = 0,  Vref_W = 0;

float da_rng = 5;
float V_sub_rng = 20;
float I_cir_rng = 10;
float DAC_A_CS = 0, DAC_B_CS = 0;
float theta_M1_vf = 0;
float theta_Ma_vf=0, theta_Mb_vf = PI2_2THIRD, theta_Mc_vf = PI2_1THIRD, freq_M1_vf = 2;
//float VM1de_ref_vf = 0, VM1qe_ref_vf = 5;
float theta_M1 = 0, Init_theta_M1 = 0;
float cos_theta_M1 = 0, sin_theta_M1 = 0;
float sin_theta_Mu = 0, sin_theta_Mv = 0, sin_theta_Mw = 0;
float DAC_MMC_A1_OFFSET_1 = -1.3, DAC_MMC_A2_OFFSET_1 = -0.9;
float DAC_MMC_A3_OFFSET_1 = -1.3, DAC_MMC_A4_OFFSET_1 = -0.2;
float DAC_MMC_A5_OFFSET_1 = -1.0, DAC_MMC_A6_OFFSET_1 = -1.4;
float DAC_MMC_A7_OFFSET_1 = -1.4, DAC_MMC_A8_OFFSET_1 = -1.4;

void DAC(void)
{
	switch (da_sel)
	{
	case 1:
		da1.out = &Va_SM_U[0];	da1.rng = V_sub_rng;	da1.mid = 0;	 da1.type = 0;
		da2.out = &Va_SM_U[1];	da2.rng = V_sub_rng;	da2.mid = 0;	 da2.type = 0;
		da3.out = &Va_SM_U[2];	da3.rng = V_sub_rng;	da3.mid = 0;	 da3.type = 0;
		da4.out = &Va_SM_U[3];	da4.rng = V_sub_rng;	da4.mid = 0;	 da4.type = 0;
		da_sel =  0;
		break;
	case 2:
		da1.out = &Va_SM_L[0];	da1.rng = V_sub_rng;	da1.mid = 0;	 da1.type = 0;
		da2.out = &Va_SM_L[1];	da2.rng = V_sub_rng;	da2.mid = 0;	 da2.type = 0;
		da3.out = &Va_SM_L[2];	da3.rng = V_sub_rng;	da3.mid = 0;	 da3.type = 0;
		da4.out = &Va_SM_L[3];	da4.rng = V_sub_rng;	da4.mid = 0;	 da4.type = 0;
		da_sel =  0;
		break;
    case 3:
        da1.out = &Vb_SM_U[0];  da1.rng = V_sub_rng;    da1.mid = 0;     da1.type = 0;
        da2.out = &Vb_SM_U[1];  da2.rng = V_sub_rng;    da2.mid = 0;     da2.type = 0;
        da3.out = &Vb_SM_U[2];  da3.rng = V_sub_rng;    da3.mid = 0;     da3.type = 0;
        da4.out = &Vb_SM_U[3];  da4.rng = V_sub_rng;    da4.mid = 0;     da4.type = 0;
        da_sel =  0;
        break;
    case 4:
        da1.out = &Vb_SM_L[0];  da1.rng = V_sub_rng;    da1.mid = 0;     da1.type = 0;
        da2.out = &Vb_SM_L[1];  da2.rng = V_sub_rng;    da2.mid = 0;     da2.type = 0;
        da3.out = &Vb_SM_L[2];  da3.rng = V_sub_rng;    da3.mid = 0;     da3.type = 0;
        da4.out = &Vb_SM_L[3];  da4.rng = V_sub_rng;    da4.mid = 0;     da4.type = 0;
        da_sel =  0;
        break;
    case 5:
         da1.out = &Vc_SM_U[0];  da1.rng = V_sub_rng;    da1.mid = 0;     da1.type = 0;
         da2.out = &Vc_SM_U[1];  da2.rng = V_sub_rng;    da2.mid = 0;     da2.type = 0;
         da3.out = &Vc_SM_U[2];  da3.rng = V_sub_rng;    da3.mid = 0;     da3.type = 0;
         da4.out = &Vc_SM_U[3];  da4.rng = V_sub_rng;    da4.mid = 0;     da4.type = 0;
         da_sel =  0;
         break;
    case 6:
         da1.out = &Vc_SM_L[0];  da1.rng = V_sub_rng;    da1.mid = 0;     da1.type = 0;
         da2.out = &Vc_SM_L[1];  da2.rng = V_sub_rng;    da2.mid = 0;     da2.type = 0;
         da3.out = &Vc_SM_L[2];  da3.rng = V_sub_rng;    da3.mid = 0;     da3.type = 0;
         da4.out = &Vc_SM_L[3];  da4.rng = V_sub_rng;    da4.mid = 0;     da4.type = 0;
         da_sel =  0;
         break;
    case 7:
         da1.out = &I_rs;   da1.rng = 2;    da1.mid = 0;     da1.type = 0;
         da2.out = &I_ss;   da2.rng = 2;    da2.mid = 0;     da2.type = 0;
         da3.out = &I_ts;   da3.rng = 2;    da3.mid = 0;     da3.type = 0;
         da4.out = &theta_grid;  da4.rng = 7;    da4.mid = 0;     da4.type = 0;
         da_sel =  0;
         break;
    case 8:
         da1.out = &I_au;   da1.rng = 2;    da1.mid = 0;     da1.type = 0;
         da2.out = &I_al;   da2.rng = 2;    da2.mid = 0;     da2.type = 0;
         da3.out = &I_as;   da3.rng = 2;    da3.mid = 0;     da3.type = 0;
         da4.out = &theta;  da4.rng = 7;    da4.mid = 0;     da4.type = 0;
         da_sel =  0;
         break;
    case 9:
         da1.out = &I_bu;   da1.rng = 2;    da1.mid = 0;     da1.type = 0;
         da2.out = &I_bl;   da2.rng = 2;    da2.mid = 0;     da2.type = 0;
         da3.out = &I_bs;   da3.rng = 2;    da3.mid = 0;     da3.type = 0;
         da4.out = &theta;  da4.rng = 7;    da4.mid = 0;     da4.type = 0;
         da_sel =  0;
         break;
    case 10:
         da1.out = &I_cu;   da1.rng = 2;    da1.mid = 0;     da1.type = 0;
         da2.out = &I_cl;   da2.rng = 2;    da2.mid = 0;     da2.type = 0;
         da3.out = &I_cs;   da3.rng = 2;    da3.mid = 0;     da3.type = 0;
         da4.out = &theta;  da4.rng = 7;    da4.mid = 0;     da4.type = 0;
         da_sel =  0;
         break;
    case 11:
         da1.out = &W_total_ref;   da1.rng = 2;    da1.mid = 0;     da1.type = 0;
         da2.out = &W_total;   da2.rng = 2;    da2.mid = 0;     da2.type = 0;
         da3.out = &iDC_ref;   da3.rng = 2;    da3.mid = 0;     da3.type = 0;
         da4.out = &Idc_sensor;  da4.rng = 7;    da4.mid = 0;     da4.type = 0;
         da_sel =  0;
         break;
    case 12:
         da1.out = &W_leg;   da1.rng = 2;    da1.mid = 0;     da1.type = 0;
         da2.out = &W_suma_low;   da2.rng = 2;    da2.mid = 0;     da2.type = 0;
         da3.out = &W_sumb_low;   da3.rng = 2;    da3.mid = 0;     da3.type = 0;
         da4.out = &W_sumc_low;  da4.rng = 7;    da4.mid = 0;     da4.type = 0;
         da_sel =  0;
         break;
    case 13:
         da1.out = &W_diff_com;   da1.rng = 2;    da1.mid = 0;     da1.type = 0;
         da2.out = &W_diffa_low;   da2.rng = 2;    da2.mid = 0;     da2.type = 0;
         da3.out = &W_diffb_low;   da3.rng = 2;    da3.mid = 0;     da3.type = 0;
         da4.out = &W_diffc_low;  da4.rng = 7;    da4.mid = 0;     da4.type = 0;
         da_sel =  0;
         break;
    case 14:
         da1.out = &Pdiff_theta;   da1.rng = 2;    da1.mid = 0;     da1.type = 0;
         da2.out = &theta_phase;   da2.rng = 2;    da2.mid = 0;     da2.type = 0;
         da3.out = &I_cs;   da3.rng = 2;    da3.mid = 0;     da3.type = 0;
         da4.out = &theta;  da4.rng = 7;    da4.mid = 0;     da4.type = 0;
         da_sel =  0;
         break;
    case 15:
         da1.out = &ia_cir_err;   da1.rng = 2;    da1.mid = 0;     da1.type = 0;
         da2.out = &ib_cir_err;   da2.rng = 2;    da2.mid = 0;     da2.type = 0;
         da3.out = &ic_cir_err;   da3.rng = 2;    da3.mid = 0;     da3.type = 0;
         da4.out = &theta;  da4.rng = 7;    da4.mid = 0;     da4.type = 0;
         da_sel =  0;
         break;
    case 16:
         da1.out = &Va0_ref;   da1.rng = 2;    da1.mid = 0;     da1.type = 0;
         da2.out = &Vb0_ref;   da2.rng = 2;    da2.mid = 0;     da2.type = 0;
         da3.out = &Vc0_ref;   da3.rng = 2;    da3.mid = 0;     da3.type = 0;
         da4.out = &theta;  da4.rng = 7;    da4.mid = 0;     da4.type = 0;
         da_sel =  0;
         break;
    case 17:
         da1.out = &Pdiff_theta;   da1.rng = 2;    da1.mid = 0;     da1.type = 0;
         da2.out = &theta_phase;   da2.rng = 2;    da2.mid = 0;     da2.type = 0;
         da3.out = &I_cs;   da3.rng = 2;    da3.mid = 0;     da3.type = 0;
         da4.out = &theta;  da4.rng = 7;    da4.mid = 0;     da4.type = 0;
         da_sel =  0;
         break;
    case 18:
         da1.out = &Er;   da1.rng = 150;    da1.mid = 0;     da1.type = 0;
         da2.out = &Es;   da2.rng = 150;    da2.mid = 0;     da2.type = 0;
         da3.out = &Et;   da3.rng = 150;    da3.mid = 0;     da3.type = 0;
         da4.out = &theta_grid;  da4.rng = 7;    da4.mid = 0;     da4.type = 0;
         da_sel =  0;
         break;

    default: break;
	}

	da1_tmp = (Uint16)((int)((DA(1) - da1.mid) * DAC_RNG / da1.rng) + DAC_MID);
	da2_tmp = (Uint16)((int)((DA(2) - da2.mid) * DAC_RNG / da2.rng) + DAC_MID);
	da3_tmp = (Uint16)((int)((DA(3) - da3.mid) * DAC_RNG / da3.rng) + DAC_MID);
	da4_tmp = (Uint16)((int)((DA(4) - da4.mid) * DAC_RNG / da4.rng) + DAC_MID);

	da5_tmp = (Uint16)((int)((DA(5) - da5.mid) * DAC_RNG / da5.rng) + DAC_MID);
	da6_tmp = (Uint16)((int)((DA(6) - da6.mid) * DAC_RNG / da6.rng) + DAC_MID);
	da7_tmp = (Uint16)((int)((DA(7) - da7.mid) * DAC_RNG / da7.rng) + DAC_MID);
	da8_tmp = (Uint16)((int)((DA(8) - da8.mid) * DAC_RNG / da8.rng) + DAC_MID);

	DAC_out(1, da1_tmp);
	DAC_out(2, da2_tmp);
	DAC_out(3, da3_tmp);
	DAC_out(4, da4_tmp);
	DAC_out(5, da5_tmp);
	DAC_out(6, da6_tmp);
	DAC_out(7, da7_tmp);
	DAC_out(8, da8_tmp);
	*DAC_GEN = 0x0;

	return;
}

void DAC_out(Uint16 ch, Uint16 data)
{

	switch(ch)	// DA Out.
	{
		case 1:
			*DAC_A1_WR = (0x0000 | (data & DAC_EFF));
			break;
		case 2:
			*DAC_A2_WR = (0x4000 | (data & DAC_EFF));
			break;
		case 3:
			*DAC_A3_WR = (0x8000 | (data & DAC_EFF));
			break;
		case 4:
			*DAC_A4_WR = (0xC000 | (data & DAC_EFF));
			break;
		case 5:
			*DAC_A5_WR = (0x0000 | (data & DAC_EFF));
			break;
		case 6:
			*DAC_A6_WR = (0x4000 | (data & DAC_EFF));
			break;
		case 7:
			*DAC_A7_WR = (0x8000 | (data & DAC_EFF));
			break;
		case 8:
			*DAC_A8_WR = (0xC000 | (data & DAC_EFF));
			break;
		default: break;
	}

	return;
}
