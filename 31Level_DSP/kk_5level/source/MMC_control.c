
#include "Define_Header.h"


//direct kp = 25
float Ls_M1 = 7.5e-3F;
float Rs_M1 = 20, Ke_M1 = 0;
float KM1_pc = 25;//141;
float KM1_ic = 22000.0F;//188;
float KM1_ac = 0.133333F;
float KM1_ps = 0.005F, KM1_is = 0.08F, KM1_as = 240.0F;
float Kcir_ic = 40, Kcir_pc = 5; float Ks1_i = 0;
float La_M1 = 5e-3F;
float K_tran = 1;
float IM1_max = 10;


Uint16 Mode = 0;
Uint16 Flag_MMC = 0;
Uint16 Flag_OM = 0;
Uint16 Flag_VF = 0;
Uint16 Flag_Align = 0;
Uint16 Flag_Current = 0;
Uint16 Flag_Voltage = 0;
Uint16 Flag_SupCirCur = 0;
Uint16 Flag_cir_en = 0;
Uint16 Flag_Indirectmodu = 0;
Uint16 Flag_comm_Energy=0;
Uint16 Flag_diff_Energy=0;
Uint16 Flag_Energy_balance=0;
Uint16 Flag_total_Energy=0;
Uint16 Flag_Con = 0;
Uint16 Flag_Inv = 0;
Uint16 Flag_Rev_Tran_P = 0, Flag_Rev_Tran_N = 0;

float I_ref_MAX = 1.5;

float Kpll_d = 0.01, Kpll_p = 20;
float Krst_pc = 5, Krst_ic = 100, Krst_ac = 0.1;
float Krst_pv = 0.15, Krst_iv = 2.5, Krst_av = 2.4;
float Lrst_s = 0.005, Rrst_s = 0.1;

float Erst_ds = 0, Erst_qs = 0;
float Erst_de = 0, Erst_qe = 0;
float Erst_de_low = 0, Erst_qe_low = 0;
float Erst_de_old = 0, Erst_qe_old = 0;

float Erst_de_err = 0, Erst_de_err_low = 0;
float Erst_de_err_old = 0, Erst_de_err_low_old = 0;
float theta_grid_ff = 2 * PI * FREQ_GRID * TIMEBASE1_SAMPLING_TIME;
float TWc_Erst_de_err = 0.5024;
float TWc_Erst_dqe = 0.09;
//float TWc_Erst_dqe= 5.024;
float theta_grid = 0;
float freq_grid = 0;
float sin_theta_grid = 0, cos_theta_grid = 0;
float cos_theta2 = 0, sin_theta2 = 0;
float theta2 = 0;

float Inv_V_AU=0, Inv_V_AL=0, Inv_V_BU=0, Inv_V_BL=0, Inv_V_CU=0, Inv_V_CL=0;

float P_out = 0;

float theta_vf = 0, freq = 60;
float theta = 0, Init_theta = 0;
float theta_old = 0;
float cos_theta = 0, sin_theta = 0;

float VM1de_ref_vf = 0, VM1qe_ref_vf = 5;
float We_M1 = PI2 * 60;
float IM1qe_ref_cc = 0.2;
float IM1de_ref_cc = 0;

float Vdc_ref =0, Vdc_rated =0;
float Vdc_err = 0;
float IM1qe_ref_anti = 0;
float IM1qe_ref_prop = 0;
float IM1qe_ref_integ = 0;
float IM1qe_ref_fb = 0;
float IM1qe_ref_ff = 0;
float IM1qe_ref_tmp = 0;

float IM1de_ref = 0, IM1qe_ref = 0;
float IM1ds = 0, IM1qs = 0;
float IM1de = 0, IM1qe = 0;
float IM1de_err = 0, IM1qe_err = 0;

float Vdc_ref_vc = 0, pf_ref = 1;                           // Voltage Control

float VM1de_ref_anti = 0, VM1qe_ref_anti = 0;
float VM1de_ref_prop = 0, VM1qe_ref_prop = 0;
float VM1de_ref_integ = 0, VM1qe_ref_integ = 0;
float VM1de_ref_fb = 0, VM1qe_ref_fb = 0;
float VM1de_ref_ff = 0, VM1qe_ref_ff = 0;
float VM1de_ref = 0, VM1qe_ref = 0;
float VM1ds_ref = 0, VM1qs_ref = 0;
float VM1as_ref = 0, VM1bs_ref = 0, VM1cs_ref = 0;
float VM1an_ref = 0, VM1bn_ref = 0, VM1cn_ref = 0, VM1sn_ref;
float NM1an_refu = 0, NM1bn_refu = 0, NM1cn_refu = 0;
float NM1an_refl = 0, NM1bn_refl = 0, NM1cn_refl = 0;
float VM1as_refu = 0,  VM1bs_refu = 0,  VM1cs_refu = 0;
float VM1as_refl = 0, VM1bs_refl = 0, VM1cs_refl = 0;
float VM1an_refu = 0, VM1bn_refu = 0, VM1cn_refu = 0;
float VM1an_refl = 0, VM1bn_refl = 0, VM1cn_refl = 0;
float VM1ds = 0, VM1qs = 0;
float VM1de = 0, VM1qe = 0;

float Icirds = 0, Icirqs = 0;
float Icirde_err = 0, Icirde_ref = 0, Icirde = 0;
float Icirde_3 = 0, Icirqe_3 = 0;
float Icirqe_err = 0, Icirqe_ref = 0, Icirqe = 0;

float Vcirde_ref_integ = 0, Vcirde_ref_prop = 0, Vcirde_ref_fb = 0, Vcirde_ref_ff = 0;
float Vcirde_ref = 0, Vcirds_ref = 0;
float Vcirqe_ref_integ = 0, Vcirqe_ref_prop = 0, Vcirqe_ref_fb = 0, Vcirqe_ref_ff = 0;
float Vcirqe_ref = 0, Vcirqs_ref = 0;
float Vciras_ref = 0, Vcirbs_ref = 0, Vcircs_ref = 0;
float  A_scale=0,  B_scale=0,  C_scale=0;
float integ1=0, integ2=0, integ3=0;
float I_ao_ext=0, I_bo_ext=0, I_co_ext=0;
float  I_a_scale=0,  I_b_scale=0, I_c_scale=0;
float  Kcom1=0,  Kcom2=0,  Kcom3=0;
float Ks1_offset=0, A_offset=0,B_offset=0,C_offset=0,D_offset=0,E_offset=0,F_offset=0;

float V_AU_sum =0, V_AL_sum = 0, V_BU_sum = 0, V_BL_sum = 0, V_CU_sum = 0, V_CL_sum = 0;
float W_au=0, W_al=0, W_bu=0, W_bl =0, W_cu =0, W_cl=0;
float W_suma =0, W_sumb =0, W_sumc =0, W_diffa =0, W_diffb =0, W_diff =0, W_suma_err =0, W_diffa_err=0, W_diffa_ref =0, W_suma_ref =0, W_diffc=0;
float Vtotala_ref_integ=0,  Vtotala_ref_prop=0, Vtotala_ref=0, Vdiffa_ref_integ=0, Vdiffa_ref_prop=0, Vdiffa_ref=0, Udiffa_ref=0;
float W_sumb_err=0,  Vtotalb_ref_integ =0,  Vtotalb_ref_prop =0,  Vtotalb_ref =0,  W_diffb_err  =0, Vdiffb_ref_integ =0, Vdiffb_ref_prop =0,  Vdiffb_ref=0, Udiffb_ref =0;
float W_sumc_err =0, Vtotalc_ref_integ =0, Vtotalc_ref_prop =0, Vtotalc_ref =0,  W_diffc_err =0, Vdiffc_ref_integ  =0, Vdiffc_ref_prop =0, Vdiffc_ref =0, Udiffc_ref =0;

float W_leg=0, W_diff_com=0, W_total_err=0, W_total=0, Wtotal_ref_integ=0, Wtotal_ref_prop=0, PDC_ref=0, iDC_ref=0, p_total=0,Ki_total=250;//2000;
float Wtotal_ref_fb = 0, Wtotal_ref_ff = 0;
float W_lega_err=0, Plega_ref_integ =0, Plega_ref_prop =0, Ki_leg =10, Kp_leg =8, i_ao_cirDC_ref =0,  W_legb_err =0, Plegb_ref_integ =0;
float Plegb_ref_prop =0, i_bo_cirDC_ref =0, W_legc_err =0, Plegc_ref_integ =0, Plegc_ref_prop =0, i_co_cirDC_ref =0;
float W_diff_com_err =0, Pdiff_com_ref_prop =0, Kp_com =20, i_cirAC_ref_pos =0, ia_cirAC_ref_pos =0, ib_cirAC_ref_pos =0, ic_cirAC_ref_pos =0, Ki_com = 200;//400;
float W_diff_diffa_err =0, Pdiff_diffa_ref_integ =0, Pdiff_diffa_ref_prop =0, Pdiff_diffa_ref =0, Ki_diff =0.1;//1,
float Pdiff_diffb_ref_integ =0, Pdiff_diffb_ref_prop =0, Pdiff_diffb_ref =0, W_diff_diffc_err =0, Pdiff_diffc_ref_integ =0, Pdiff_diffc_ref_prop =0, Pdiff_diffc_ref =0, Kp_diff =60;//50;//16;//2;//20;
float P_diffde_ref =0, P_diffqe_ref =0, P_diffds_ref =0,  P_diffqs_ref =0, id_cirAC_ref_neg =0, iq_cirAC_ref_neg =0, ia_cirAC_ref_neg =0, ib_cirAC_ref_neg =0, ic_cirAC_ref_neg =0, Kp_dc =1.5;//2;//10;//40;
float  iDC_err =0, Vdc_ref_integ =0, Vdc_ref_prop =0,ia_cir_ref =0, ib_cir_ref =0, ic_cir_ref =0, ia_cir_err_n2 =0, ib_cir_err_n2 =0, ic_cir_err_n2 =0, Ki_dc =100;//700;//100,;
float ia_cir_err_n1 =0, ib_cir_err_n1 =0, ic_cir_err_n1 =0, ia_cir_err =0, ib_cir_err =0, ic_cir_err =0, Va0_ref_integ =0, Ki_Pi =0, Va0_ref_prop  =0, Va0_ref_delay =0, inter =0, Kp_Pir = 4;//26;//2;//7;//10;//99;
float Va0_ref_res =0, Va0_ref =0, Vb0_ref_integ =0, Vb0_ref_prop =0, Vb0_ref_delay =0, Vb0_ref_res =0,  Vb0_ref =0, Vc0_ref_integ =0, Vc0_ref_prop =0, Vc0_ref_delay =0, Kres_Pir =30;//3;//600;
float Vc0_ref_res =0, Vc0_ref  =0;
float ib_cir_errr =0, Ki_Pir =10, Pdiff_com_ref_integ =0,   W_diff_diffb_err =0, W_total_ref =0, Kp_total = 2;//200;
float Va0_ref_res_n1 =0, Vb0_ref_res_n1 =0,  Vc0_ref_res_n1 =0;
float Va0_ref_res_n2 =0, Vb0_ref_res_n2 =0,  Vc0_ref_res_n2 =0;
float Wc = 10;
float TWc_Etotal = 0.075398, TWc_Ediff = 0.037699, Q_60= 2, Q_120= 2;//0.5,
float Tcl =0.00628318;

float theta_phase=0,  theta_shift=0,  Pdiff_theta=0,  Pdiffc_theta_ref=0,  Pdiffb_theta_ref=0,  Pdiffa_theta_ref=0, cos_theta1=0;
float Pdiffc_theta_prop=0, Pdiffc_theta_integ=0,  Kp_theta=0.1, Ki_theta =10;
float Pdiffb_theta_prop=0, Pdiffb_theta_integ=0, Pdiffa_theta_prop =0, Pdiffa_theta_integ=0;

float W_suma_low=0, W_sumb_low=0, W_sumc_low =0, W_diffa_low =0, W_diffb_low =0, W_diffc_low =0;
float W_suma_low_old =0, W_sumb_low_old =0, W_sumc_low_old =0, W_diffa_low_old =0,  W_diffb_low_old=0, W_diffc_low_old =0;
float W_suma_low_old_old =0, W_sumb_low_old_old =0, W_sumc_low_old_old =0, W_diffa_low_old_old =0, W_diffb_low_old_old =0, W_diffc_low_old_old =0;
float W_suma_old =0, W_sumb_old =0, W_sumc_old =0, W_diffa_old =0, W_diffb_old =0, W_diffc_old =0;
float W_suma_old_old =0, W_sumb_old_old =0, W_sumc_old_old =0, W_diffa_old_old =0, W_diffb_old_old =0, W_diffc_old_old =0;


float Vdc_rated_ref =100;
float I_com = 0;
float V_grid = 48.9898;

void MMC(void)
{
	if (Flag_MMC == 1)
		PWM_ON;
	else
		PWM_OFF;

    PLL();

    sin_theta_grid = sin(theta_grid);
    cos_theta_grid = cos(theta_grid);

	// dq Transform(abcs to dqs)
	IM1ds = I_as;
	IM1qs = (I_bs - I_cs) * INV_SQRT3;

	// dq Transform(dqs to dqe)
	IM1de =  cos_theta_grid  * IM1ds + sin_theta_grid  * IM1qs;
	IM1qe = -sin_theta_grid  * IM1ds + cos_theta_grid  * IM1qs;

	// dq Transform(abcs to dqs)
    Erst_ds = Er;
    Erst_qs = (Es - Et) * INV_SQRT3;

    Erst_de = cos_theta_grid * Erst_ds + sin_theta_grid * Erst_qs;
    Erst_qe = -sin_theta_grid * Erst_ds + cos_theta_grid * Erst_qs;

    Erst_de_low = LPF1(Erst_de_low, Erst_de, Erst_de_old, TWc_Erst_dqe);
    Erst_qe_low = LPF1(Erst_qe_low, Erst_qe, Erst_qe_old, TWc_Erst_dqe);

/*   // dq Transform(abcs to dqs)
    VM1ds = VM1as_ref;
    VM1qs = (VM1bs_ref - VM1cs_ref) * INV_SQRT3;

    // dq Transform(dqs to dqe)
    VM1de =  cos_theta * VM1ds + sin_theta * VM1qs;
    VM1qe = -sin_theta * VM1ds + cos_theta * VM1qs;
*/

    if(Flag_Rev_Tran_P)
    {
        if(IM1qe_ref_cc >= I_ref_MAX)
            IM1qe_ref_cc = I_ref_MAX;
        else
            IM1qe_ref_cc += TIMEBASE1_SAMPLING_TIME*K_tran;
    }

    if(Flag_Rev_Tran_N)
    {
        if(IM1qe_ref_cc <= -I_ref_MAX)
            IM1qe_ref_cc = -I_ref_MAX;
        else
            IM1qe_ref_cc -= TIMEBASE1_SAMPLING_TIME*K_tran;
    }


    if(Flag_Con & Flag_Inv)
    {
        Flag_MMC = 0;
        Flag_Con= 0;
        Flag_Inv = 0;
    }
    // Control
	Mode = (Flag_VF & 0x1) | (Flag_Align & 0x1) << 1 | (Flag_Current & 0x1) << 2 | (Flag_Voltage & 0x1) << 3 | (Flag_SupCirCur & 0x1) << 4 |(Flag_Indirectmodu & 0x1) << 6 | (Flag_MMC & 0x1) << 15;
	switch (Mode)
	{
        case 0x8010: // Direct Modulation Suppress Circulating Current
            Vdc_ref = Vdc_ref_vc;
            IM1de_ref = 0;
            IM1qe_ref = IM1qe_ref_cc;
            Icirde_ref = 0;
            Icirqe_ref = 0;

            if(Flag_Con)
            {
                Current_Con();
            }
            if(Flag_Inv)
            {
                Current_Inv();
            }

            SuppCirCurrent();

            break;

        case 0x8008:                // Direct Modulation Voltage Controller
            Vdc_ref = Vdc_ref_vc;
            Icirde_ref = 0;
            Icirqe_ref = 0;

            Converter_voltage();
            if(Flag_Con)
            {
                Current_Con();
            }
            if(Flag_Inv)
            {
                Current_Inv();
            }
            SuppCirCurrent();

            break;

        case 0x8040: // Indirect Modulation MMC controller
            if(Flag_Con)
            {
                IM1de_ref = IM1de_ref_cc;
                Vdc_rated = Vdc_ref_vc;            // For calculation
                Vdc_ref = Vdc_ref_vc;             // Modulation

                Indirect_Modu_Con();
            }

            if(Flag_Inv)
            {
                IM1de_ref = 0;
                IM1qe_ref = IM1qe_ref_cc;
                Vdc_rated = Vdc_ref_vc;           // For calculation

                Indirect_Modu_Inv();
            }

            break;

        case 0x8004: // Current Control
            // Reference Input
            Vdc_ref = Vdc_ref_vc;
            IM1de_ref = 0;
            IM1qe_ref = IM1qe_ref_cc;

            if(Flag_Con)
            {
                Current_Con();
            }
            if(Flag_Inv)
            {
                Current_Inv();
            }
            break;

        /*case 0x8002: // Align
            Align();
            break;
       */
        case 0x8001:
        case 0x0001:// V/F Control
            Vdc_ref = Vdc_ref_vc;
            MMC_open();
            break;

        default:
            Flag_MMC = 0;
            Reset();
            break;
	}

	PD_MOD();

	return;
}

void PLL(void)
{
    Erst_de_err = -(cos_theta_grid * Erst_ds + sin_theta_grid * Erst_qs);
    Erst_de_err_low = LPF1(Erst_de_err_low, Erst_de_err, Erst_de_err_old, TWc_Erst_de_err);

    theta_grid += Kpll_d * (Erst_de_err - Erst_de_err_old) + Kpll_p * Erst_de_err * TIMEBASE1_SAMPLING_TIME;
    theta_grid += theta_grid_ff;

    Erst_de_err_low_old = Erst_de_err_low;

    if (theta_grid >= 2*PI)
        theta_grid -= 2*PI;
    else if (theta_grid < 0)
        theta_grid += 2*PI;

    return;
}

void MMC_open(void)
{
    // Reference Input
    VM1de_ref = -VM1de_ref_vf;            //+ Erst_de_low;
    VM1qe_ref = -VM1qe_ref_vf + Erst_qe_low;

    // Inverse Transform(dqe to dqs)
    VM1ds_ref = cos_theta_grid * VM1de_ref - sin_theta_grid * VM1qe_ref;
    VM1qs_ref = sin_theta_grid * VM1de_ref + cos_theta_grid * VM1qe_ref;

    // Inverse Transform(dqs to abc)
    VM1as_ref = VM1ds_ref;
    VM1bs_ref = -0.5 * (VM1ds_ref - SQRT3 * VM1qs_ref);
    VM1cs_ref = -0.5 * (VM1ds_ref + SQRT3 * VM1qs_ref);

    Va0_ref = 0;
    Vb0_ref = 0;
    Vc0_ref = 0;
    return;
}

// 전류제어
void Current_Con(void)
{
    if(Flag_Voltage)
    {
        // d-axis Current Control
        IM1de_err = -IM1de_ref + (-IM1de);

        // q-axis Current Control
        IM1qe_err = -IM1qe_ref + (-IM1qe);
     //+ Ke_M1 * Wm_M1
    }
    else
    {
        // d-axis Current Control
       IM1de_err = IM1de_ref - IM1de;

       // q-axis Current Control
       IM1qe_err = IM1qe_ref - IM1qe;
    }

	//VM1de_ref_anti = KM1_ac * (VM1de_ref - VM1de);
	VM1de_ref_integ += TIMEBASE1_SAMPLING_TIME * KM1_ic * (IM1de_err); //- VM1de_ref_anti);
	VM1de_ref_prop = KM1_pc * IM1de_err;

	VM1de_ref_fb = VM1de_ref_integ + VM1de_ref_prop;
    VM1de_ref_ff = Erst_de_low - 2*PI*FREQ_GRID*Lrst_s*IM1qe;

	VM1de_ref = VM1de_ref_fb + VM1de_ref_ff;


	//VM1qe_ref_anti = KM1_ac * (VM1qe_ref - VM1qe);
	VM1qe_ref_integ += TIMEBASE1_SAMPLING_TIME * KM1_ic * (IM1qe_err);// - VM1qe_ref_anti);
	VM1qe_ref_prop = KM1_pc * IM1qe_err;

	VM1qe_ref_fb = VM1qe_ref_integ + VM1qe_ref_prop;
    VM1qe_ref_ff =  Erst_qe_low + 2*PI*FREQ_GRID*Lrst_s*IM1de;

	VM1qe_ref = VM1qe_ref_fb + VM1qe_ref_ff;

	// Inverse Transform(dqe to dqs)
	VM1ds_ref = cos_theta_grid  * VM1de_ref - sin_theta_grid  * VM1qe_ref;
	VM1qs_ref = sin_theta_grid  * VM1de_ref + cos_theta_grid  * VM1qe_ref;

	// Inverse Transform(dqs to abcs)
	VM1as_ref = VM1ds_ref;
	VM1bs_ref = -0.5 * (VM1ds_ref -	SQRT3 * VM1qs_ref);
	VM1cs_ref = -0.5 * (VM1ds_ref +	SQRT3 * VM1qs_ref);

	return;
}

void Current_Inv(void)
{
    // d-axis Current Control
    IM1de_err = IM1de_ref - IM1de;

    //VM1de_ref_anti = KM1_ac * (VM1de_ref - VM1de);
    VM1de_ref_integ += TIMEBASE1_SAMPLING_TIME * KM1_ic * (IM1de_err); //- VM1de_ref_anti);
    VM1de_ref_prop = KM1_pc * IM1de_err;

    VM1de_ref_fb = VM1de_ref_integ + VM1de_ref_prop;
    VM1de_ref_ff = -1 * Ls_M1 * We_M1 * IM1qe;

    VM1de_ref = VM1de_ref_fb + VM1de_ref_ff;

    // q-axis Current Control
    IM1qe_err = IM1qe_ref - IM1qe;

    //VM1qe_ref_anti = KM1_ac * (VM1qe_ref - VM1qe);
    VM1qe_ref_integ += TIMEBASE1_SAMPLING_TIME * KM1_ic * (IM1qe_err);// - VM1qe_ref_anti);
    VM1qe_ref_prop = KM1_pc * IM1qe_err;

    VM1qe_ref_fb = VM1qe_ref_integ + VM1qe_ref_prop;
    VM1qe_ref_ff =  Ls_M1 * We_M1 * IM1de;     //+ Ke_M1 * Wm_M1

    VM1qe_ref = VM1qe_ref_fb + VM1qe_ref_ff;

    // Inverse Transform(dqe to dqs)
    VM1ds_ref = cos_theta_grid  * VM1de_ref - sin_theta_grid  * VM1qe_ref;
    VM1qs_ref = sin_theta_grid  * VM1de_ref + cos_theta_grid  * VM1qe_ref;

    // Inverse Transform(dqs to abcs)
    VM1as_ref = VM1ds_ref;
    VM1bs_ref = -0.5 * (VM1ds_ref - SQRT3 * VM1qs_ref);
    VM1cs_ref = -0.5 * (VM1ds_ref + SQRT3 * VM1qs_ref);

    return;
}

void SuppCirCurrent(void)
{
    // Theta for double frequency negative sequence component
    if(theta2  >= 0)
    {
        theta2 = -2 * theta_grid + PI2;
        if(theta2  <= 0)
           theta2 += PI2;
    }
    else
    {
        theta2 = -2 * theta_grid -PI2;
        if(theta2  >= 0)
            theta2 -= PI2;
    }

    sin_theta2 = sin(theta2);
    cos_theta2 = cos(theta2);

    Icirds = I_ao;
    Icirqs = (I_bo - I_co) * INV_SQRT3;

    Icirde =  cos_theta2 * Icirds + sin_theta2 * Icirqs;
    Icirqe = -sin_theta2 * Icirds + cos_theta2 * Icirqs;

    Vciras_ref=0;
    Vcirbs_ref=0;
    Vcircs_ref=0;

    //circulating current suppressing algorithm

    if (Flag_cir_en ==1)

    {
        Icirde_err = Icirde_ref - Icirde;

        Vcirde_ref_integ += TIMEBASE1_SAMPLING_TIME * Kcir_ic * Icirde_err;//- Vcirde_ref_anti);
        Vcirde_ref_prop = Kcir_pc * Icirde_err;

        Vcirde_ref_fb = Vcirde_ref_integ + Vcirde_ref_prop;
        Vcirde_ref_ff = -La_M1 * 2 * We_M1 * Icirqe;   // 부호 질문

        Vcirde_ref = Vcirde_ref_fb + Vcirde_ref_ff;

        // q-axis circulating Current suppressing controller
        Icirqe_err = Icirqe_ref - Icirqe;

        Vcirqe_ref_integ += TIMEBASE1_SAMPLING_TIME * Kcir_ic * Icirqe_err;
        Vcirqe_ref_prop = Kcir_pc * Icirqe_err;

        Vcirqe_ref_fb = Vcirqe_ref_integ + Vcirqe_ref_prop;
        Vcirqe_ref_ff =  La_M1 *2* We_M1 * Icirde;// 부호및 앞의 텀 (역기전력)질문

        Vcirqe_ref = Vcirqe_ref_fb + Vcirqe_ref_ff;

        // Inverse Transform for circulating current controller (dqe to dqs)
        Vcirds_ref = cos_theta2 * Vcirde_ref - sin_theta2 * Vcirqe_ref;
        Vcirqs_ref = sin_theta2 * Vcirde_ref + cos_theta2 * Vcirqe_ref;

        // Inverse Transform for circulating current controller(dqs to abcs)
        Vciras_ref = Vcirds_ref;
        Vcirbs_ref = -0.5 * (Vcirds_ref - SQRT3 * Vcirqs_ref);
        Vcircs_ref = -0.5 * (Vcirds_ref + SQRT3 * Vcirqs_ref);
    }

    Va0_ref = Vciras_ref;
    Vb0_ref = Vcirbs_ref;
    Vc0_ref = Vcircs_ref;

    return;
}

// 전압 제어
void Converter_voltage(void)
{

    if (Flag_Out_Loop)
    {
        Vdc_err = Vdc_ref - Vdc_low;

        IM1qe_ref_anti = Krst_av * (IM1qe_ref_tmp - IM1qe_ref);
        IM1qe_ref_integ += OUTERLOOP_SAMPLING_TIME * Krst_iv * (Vdc_err - IM1qe_ref_anti);
        IM1qe_ref_prop = Krst_pv * Vdc_low;

        IM1qe_ref_fb = IM1qe_ref_integ - IM1qe_ref_prop;
        IM1qe_ref_ff = I_com;

        // Because of definition of output current direction
        IM1qe_ref_tmp = IM1qe_ref_fb + IM1qe_ref_ff;

        IM1qe_ref = BOUND(IM1qe_ref_tmp, IM1_max);
        IM1de_ref = sqrt(1 - pf_ref * pf_ref) / pf_ref * IM1qe_ref;
    }

    return;
}

 void Indirect_Modu_Con(void)
{
    Energy_Cal();

    if (Flag_Out_Loop)
    {
        if (Flag_total_Energy)    //total energy controller
        {
            W_total = W_suma + W_sumb + W_sumc;
            W_total_ref = 3*SM_cap*Vdc_rated*Vdc_rated/4;
            W_total_err = W_total_ref - W_total;

            Wtotal_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_total * W_total_err;
            Wtotal_ref_prop = Kp_total * W_total_err;
            Wtotal_ref_fb = Wtotal_ref_integ + Wtotal_ref_prop;
            Wtotal_ref_ff = -Vdc_rated*Idc_sensor_low; //

            IM1qe_ref = -2*(Wtotal_ref_fb + Wtotal_ref_ff)/(V_grid*3);//-(Wtotal_ref_fb + Wtotal_ref_ff)/Erst_qe*2/3
        }

        if(Flag_Energy_balance)    // leg balancing controller
            Leg_Energy_Balance();

        if(Flag_comm_Energy)        //upper and lower arm balancing controller- common error
            Commom_Energy_Balance();

        if(Flag_diff_Energy)     //upper and lower arm balancing controller- differential error
            Diff_Energy_Balance_Con();
    }

    Current_Con();

    Energy_diff_PIR();
     //DC current controller
 //   iDC_err = -iDC_ref + Idc_sensor;
//    Vdc_ref_integ += TIMEBASE1_SAMPLING_TIME * Ki_dc * iDC_err;
 //   Vdc_ref_prop = Kp_dc * iDC_err;

	return;

}

void Indirect_Modu_Inv(void)
{
    Current_Inv();

    Energy_Cal();

    if (Flag_Out_Loop)
    {
        if (Flag_total_Energy)    //total energy controller
        {
            W_total = W_suma + W_sumb + W_sumc;
            W_total_ref = 3*SM_cap*Vdc_rated*Vdc_rated/4;// W_total_ref = 3*SM_cap*Vdc_rated*Vdc_rated
            W_total_err = W_total_ref - W_total;

            Wtotal_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_total * W_total_err;
            Wtotal_ref_prop = Kp_total * W_total_err;
            PDC_ref = Wtotal_ref_integ + Wtotal_ref_prop + 3*VM1qe_ref*IM1qe/2;
            iDC_ref = PDC_ref/Vdc_rated;
        }

        if(Flag_Energy_balance)    // leg balancing controller
            Leg_Energy_Balance();

        if(Flag_comm_Energy)        //upper and lower arm balancing controller- common error
            Commom_Energy_Balance();

        if(Flag_diff_Energy)     //upper and lower arm balancing controller- differential error
            Diff_Energy_Balance_Inv();
    }

    //DC current controller
    iDC_err = -iDC_ref + Idc_sensor;
    Vdc_ref_integ += TIMEBASE1_SAMPLING_TIME * Ki_dc * iDC_err;
    Vdc_ref_prop = Kp_dc * iDC_err;
    Vdc_ref = Vdc_ref_integ + Vdc_ref_prop + Vdc_rated;

    Energy_diff_PIR();

    return;
}

void Energy_Cal(void)
{
    V_AU_sum = Va_SM_U[0] + Va_SM_U[1]+ Va_SM_U[2]+ Va_SM_U[3];
        V_AL_sum = Va_SM_L[0] + Va_SM_L[1]+ Va_SM_L[2]+ Va_SM_L[3];
        V_BU_sum = Vb_SM_U[0] + Vb_SM_U[1]+ Vb_SM_U[2]+ Vb_SM_U[3];
        V_BL_sum = Vb_SM_L[0] + Vb_SM_L[1]+ Vb_SM_L[2]+ Vb_SM_L[3];
        V_CU_sum = Vc_SM_U[0] + Vc_SM_U[1]+ Vc_SM_U[2]+ Vc_SM_U[3];
        V_CL_sum = Vc_SM_L[0] + Vc_SM_L[1]+ Vc_SM_L[2]+ Vc_SM_L[3];

        Inv_V_AU = 1/V_AU_sum;
        Inv_V_AL = 1/V_AL_sum;
        Inv_V_BU = 1/V_BU_sum;
        Inv_V_BL = 1/V_BL_sum;
        Inv_V_CU = 1/V_CU_sum;
        Inv_V_CL = 1/V_CL_sum;

        W_au = SM_cap*(Va_SM_U[0]*Va_SM_U[0] + Va_SM_U[1]*Va_SM_U[1] + Va_SM_U[2]*Va_SM_U[2] + Va_SM_U[3]*Va_SM_U[3])/2;
        W_al = SM_cap*(Va_SM_L[0]*Va_SM_L[0] + Va_SM_L[1]*Va_SM_L[1] + Va_SM_L[2]*Va_SM_L[2] + Va_SM_L[3]*Va_SM_L[3])/2;
        W_bu = SM_cap*(Vb_SM_U[0]*Vb_SM_U[0] + Vb_SM_U[1]*Vb_SM_U[1] + Vb_SM_U[2]*Vb_SM_U[2] + Vb_SM_U[3]*Vb_SM_U[3])/2;
        W_bl = SM_cap*(Vb_SM_L[0]*Vb_SM_L[0] + Vb_SM_L[1]*Vb_SM_L[1] + Vb_SM_L[2]*Vb_SM_L[2] + Vb_SM_L[3]*Vb_SM_L[3])/2;
        W_cu = SM_cap*(Vc_SM_U[0]*Vc_SM_U[0] + Vc_SM_U[1]*Vc_SM_U[1] + Vc_SM_U[2]*Vc_SM_U[2] + Vc_SM_U[3]*Vc_SM_U[3])/2;
        W_cl = SM_cap*(Vc_SM_L[0]*Vc_SM_L[0] + Vc_SM_L[1]*Vc_SM_L[1] + Vc_SM_L[2]*Vc_SM_L[2] + Vc_SM_L[3]*Vc_SM_L[3])/2;

        W_suma = W_au + W_al;
        W_sumb = W_bu + W_bl;
        W_sumc = W_cu + W_cl;

        W_diffa = W_au - W_al;
        W_diffb = W_bu - W_bl;
        W_diffc = W_cu - W_cl;

        // notch filter for the total and difference energy

        W_suma_low = BRF(W_suma_low, W_suma_low_old,W_suma_low_old_old, W_suma, W_suma_old, W_suma_old_old, TWc_Etotal,Q_120);
        W_sumb_low = BRF(W_sumb_low, W_sumb_low_old,W_sumb_low_old_old, W_sumb, W_sumb_old, W_sumb_old_old, TWc_Etotal,Q_120);
        W_sumc_low = BRF(W_sumc_low, W_sumc_low_old,W_sumc_low_old_old, W_sumc, W_sumc_old, W_sumc_old_old, TWc_Etotal,Q_120);

        W_diffa_low = BRF(W_diffa_low, W_diffa_low_old,W_diffa_low_old_old, W_diffa, W_diffa_old, W_diffa_old_old, TWc_Ediff,Q_60);
        W_diffb_low = BRF(W_diffb_low, W_diffb_low_old,W_diffb_low_old_old, W_diffb, W_diffb_old, W_diffb_old_old, TWc_Ediff,Q_60);
        W_diffc_low = BRF(W_diffc_low, W_diffc_low_old,W_diffc_low_old_old, W_diffc, W_diffc_old, W_diffc_old_old, TWc_Ediff,Q_60);

        //W_suma_low = LPF(W_suma_low, W_suma, Tcl);
        //W_sumb_low = LPF(W_sumb_low, W_sumb, Tcl);
        //W_sumc_low = LPF(W_sumc_low, W_sumc, Tcl);

        //W_diffa_low = LPF(W_diffa_low, W_diffa,Tcl);
        //W_diffb_low = LPF(W_diffb_low, W_diffb,Tcl);
        //W_diffc_low = LPF(W_diffc_low, W_diffc,Tcl);

        W_leg = (W_suma_low + W_sumb_low + W_sumc_low)/3;
        W_diff_com = (W_diffa_low + W_diffb_low + W_diffc_low)/3;
        //iDC_ref =0;
        //ia_cirAC_ref_neg =0;
        //ia_cirAC_ref_pos =0;
        //i_ao_cirDC_ref =0;

        //ib_cirAC_ref_neg =0;
        //ib_cirAC_ref_pos =0;
        //i_bo_cirDC_ref =0;

        //ic_cirAC_ref_neg =0;
        //ic_cirAC_ref_pos =0;
        //i_co_cirDC_ref =0;
}

void Leg_Energy_Balance(void)
{
    W_lega_err = W_leg - W_suma_low;
    Plega_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_leg * W_lega_err;
    Plega_ref_prop = Kp_leg * W_lega_err;

    i_ao_cirDC_ref = (Plega_ref_integ  + Plega_ref_prop)/Vdc_rated;

    W_legb_err = W_leg - W_sumb_low;
    Plegb_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_leg * W_legb_err;
    Plegb_ref_prop = Kp_leg * W_legb_err;

    i_bo_cirDC_ref = (Plegb_ref_integ  + Plegb_ref_prop)/Vdc_rated;

    W_legc_err = W_leg -W_sumc_low;
    Plegc_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_leg * W_legc_err;
    Plegc_ref_prop = Kp_leg * W_legc_err;

    i_co_cirDC_ref = (Plegc_ref_integ  + Plegc_ref_prop)/Vdc_rated;
}

void Commom_Energy_Balance(void)
{
   W_diff_com_err = 0 - W_diff_com;

   Pdiff_com_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_com * W_diff_com_err;
   Pdiff_com_ref_prop = Kp_com * W_diff_com_err;
   i_cirAC_ref_pos = Pdiff_com_ref_integ + Pdiff_com_ref_prop;
   i_cirAC_ref_pos = -i_cirAC_ref_pos/VM1qe_ref;

   ia_cirAC_ref_pos = i_cirAC_ref_pos * VM1as_ref/VM1qe_ref;
   ib_cirAC_ref_pos = i_cirAC_ref_pos * VM1bs_ref/VM1qe_ref;
   ic_cirAC_ref_pos = i_cirAC_ref_pos * VM1cs_ref/VM1qe_ref;
}

void Diff_Energy_Balance_Con(void)
{
    W_diff_diffa_err = 0 - W_diffa_low + W_diff_com;
    Pdiff_diffa_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_diff * W_diff_diffa_err;
    Pdiff_diffa_ref_prop = Kp_diff *  W_diff_diffa_err;
    Pdiff_diffa_ref = Pdiff_diffa_ref_integ + Pdiff_diffa_ref_prop;

    W_diff_diffb_err = 0 - W_diffb_low + W_diff_com;
    Pdiff_diffb_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_diff * W_diff_diffb_err;
    Pdiff_diffb_ref_prop = Kp_diff *  W_diff_diffb_err;
    Pdiff_diffb_ref = Pdiff_diffb_ref_integ + Pdiff_diffb_ref_prop;

    W_diff_diffc_err = 0 - W_diffc_low + W_diff_com;
    Pdiff_diffc_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_diff * W_diff_diffc_err;
    Pdiff_diffc_ref_prop = Kp_diff *  W_diff_diffc_err;
    Pdiff_diffc_ref = Pdiff_diffc_ref_integ + Pdiff_diffc_ref_prop;

    //phase controllerxcAZ

    Pdiffa_theta_integ += OUTERLOOP_SAMPLING_TIME * Ki_theta * W_diff_diffa_err;
    Pdiffa_theta_prop = Kp_theta * W_diff_diffa_err;
    Pdiffa_theta_ref = Pdiffa_theta_prop + Pdiffa_theta_integ;

    Pdiffb_theta_integ += OUTERLOOP_SAMPLING_TIME * Ki_theta * W_diff_diffb_err;
    Pdiffb_theta_prop = Kp_theta * W_diff_diffb_err;
    Pdiffb_theta_ref = Pdiffb_theta_prop + Pdiffb_theta_integ;

    Pdiffc_theta_integ += OUTERLOOP_SAMPLING_TIME * Ki_theta * W_diff_diffc_err;
    Pdiffc_theta_prop = Kp_theta * W_diff_diffc_err;
    Pdiffc_theta_ref = Pdiffc_theta_prop + Pdiffc_theta_integ;

    Pdiff_theta = -(Pdiffc_theta_ref + Pdiffb_theta_ref - Pdiffa_theta_ref)/(2*VM1qe_ref);

    if(Pdiff_theta >1)
        cos_theta1 = 1;
    else if (Pdiff_theta < -1)
        cos_theta1 = -1;
    else
        cos_theta1 = Pdiff_theta;
  /*
    Pdiffa_theta_integ += OUTERLOOP_SAMPLING_TIME * Ki_theta * (W_diff_diffa_err+W_diff_diffb_err+W_diff_diffc_err)/3;
    Pdiffa_theta_prop = Kp_theta * (W_diff_diffa_err+W_diff_diffb_err+W_diff_diffc_err)/3;
    Pdiffa_theta_ref = Pdiffa_theta_prop + Pdiffa_theta_integ;
  */
    theta_shift = acos(-Pdiffa_theta_ref/VM1qe_ref);
    theta_phase = theta_grid  + theta_shift;

   if (theta_phase >= PI2)
       theta_phase -= PI2;
   else if (theta_phase < 0)
       theta_phase += PI2;


  // dq Transform(abcs to dqs)

    P_diffds_ref = 2*(Pdiff_diffa_ref-Pdiff_diffb_ref/2 -Pdiff_diffc_ref/2)/3;
    P_diffqs_ref = (Pdiff_diffb_ref - Pdiff_diffc_ref) * INV_SQRT3;


   P_diffde_ref = -P_diffds_ref / VM1qe_ref;
   P_diffqe_ref = -P_diffqs_ref / VM1qe_ref;

 // Inverse Transform(dqe to dqs)

   id_cirAC_ref_neg = cos( theta_phase) * P_diffde_ref - sin( theta_phase) * P_diffqe_ref;
   iq_cirAC_ref_neg = sin( theta_phase) * P_diffde_ref + cos( theta_phase) * P_diffqe_ref;

   ia_cirAC_ref_neg = id_cirAC_ref_neg;
   ib_cirAC_ref_neg = -id_cirAC_ref_neg/2 - sqrt(3)*iq_cirAC_ref_neg/2;
   ic_cirAC_ref_neg = -id_cirAC_ref_neg/2 + sqrt(3)*iq_cirAC_ref_neg/2;
}

void Diff_Energy_Balance_Inv(void)
{
     W_diff_diffa_err = 0 - W_diffa_low + W_diff_com;
     Pdiff_diffa_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_diff * W_diff_diffa_err;
     Pdiff_diffa_ref_prop = Kp_diff *  W_diff_diffa_err;
     Pdiff_diffa_ref = Pdiff_diffa_ref_integ + Pdiff_diffa_ref_prop;

     W_diff_diffb_err = 0 - W_diffb_low + W_diff_com;
     Pdiff_diffb_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_diff * W_diff_diffb_err;
     Pdiff_diffb_ref_prop = Kp_diff *  W_diff_diffb_err;
     Pdiff_diffb_ref = Pdiff_diffb_ref_integ + Pdiff_diffb_ref_prop;

     W_diff_diffc_err = 0 - W_diffc_low + W_diff_com;
     Pdiff_diffc_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_diff * W_diff_diffc_err;
     Pdiff_diffc_ref_prop = Kp_diff *  W_diff_diffc_err;
     Pdiff_diffc_ref = Pdiff_diffc_ref_integ + Pdiff_diffc_ref_prop;

     //phase controllerxcAZ

     Pdiffa_theta_integ += OUTERLOOP_SAMPLING_TIME * Ki_theta * W_diff_diffa_err;
     Pdiffa_theta_prop = Kp_theta * W_diff_diffa_err;
     Pdiffa_theta_ref = Pdiffa_theta_prop + Pdiffa_theta_integ;

     Pdiffb_theta_integ += OUTERLOOP_SAMPLING_TIME * Ki_theta * W_diff_diffb_err;
     Pdiffb_theta_prop = Kp_theta * W_diff_diffb_err;
     Pdiffb_theta_ref = Pdiffb_theta_prop + Pdiffb_theta_integ;

     Pdiffc_theta_integ += OUTERLOOP_SAMPLING_TIME * Ki_theta * W_diff_diffc_err;
     Pdiffc_theta_prop = Kp_theta * W_diff_diffc_err;
     Pdiffc_theta_ref = Pdiffc_theta_prop + Pdiffc_theta_integ;

     Pdiff_theta = (Pdiffc_theta_ref + Pdiffb_theta_ref - Pdiffa_theta_ref)/(2*VM1qe_ref);

     if(Pdiff_theta >1)
         cos_theta1 = 1;
     else if (Pdiff_theta < -1)
         cos_theta1 = -1;
     else
         cos_theta1 = Pdiff_theta;
    /*
     Pdiffa_theta_integ += OUTERLOOP_SAMPLING_TIME * Ki_theta * (W_diff_diffa_err+W_diff_diffb_err+W_diff_diffc_err)/3;
     Pdiffa_theta_prop = Kp_theta * (W_diff_diffa_err+W_diff_diffb_err+W_diff_diffc_err)/3;
     Pdiffa_theta_ref = Pdiffa_theta_prop + Pdiffa_theta_integ;
    */
     theta_shift = acos(-Pdiffa_theta_ref/VM1qe_ref);
     theta_phase = theta + theta_shift;

    if (theta_phase >= PI2)
        theta_phase -= PI2;
    else if (theta_phase < 0)
        theta_phase += PI2;


    // dq Transform(abcs to dqs)

     P_diffds_ref = 2*(Pdiff_diffa_ref-Pdiff_diffb_ref/2 -Pdiff_diffc_ref/2)/3;
     P_diffqs_ref = (Pdiff_diffb_ref - Pdiff_diffc_ref) * INV_SQRT3;


    P_diffde_ref = -P_diffds_ref / VM1qe_ref;
    P_diffqe_ref = -P_diffqs_ref / VM1qe_ref;

    // Inverse Transform(dqe to dqs)

    id_cirAC_ref_neg = cos( theta_phase) * P_diffde_ref - sin( theta_phase) * P_diffqe_ref;
    iq_cirAC_ref_neg = sin( theta_phase) * P_diffde_ref + cos( theta_phase) * P_diffqe_ref;

    ia_cirAC_ref_neg = id_cirAC_ref_neg;
    ib_cirAC_ref_neg = -id_cirAC_ref_neg/2 - sqrt(3)*iq_cirAC_ref_neg/2;
    ic_cirAC_ref_neg = -id_cirAC_ref_neg/2 + sqrt(3)*iq_cirAC_ref_neg/2;
}

void Energy_diff_PIR(void)
{
    //PIR circulating current controller
    ia_cir_ref = ia_cirAC_ref_neg + ia_cirAC_ref_pos + i_ao_cirDC_ref;
    ib_cir_ref = ib_cirAC_ref_neg + ib_cirAC_ref_pos + i_bo_cirDC_ref;
    ic_cir_ref = ic_cirAC_ref_neg + ic_cirAC_ref_pos + i_co_cirDC_ref;

    ia_cir_err_n1 = ia_cir_err;
    ib_cir_err_n1 = ib_cir_err;
    ic_cir_err_n1 = ic_cir_err;

    ia_cir_err = ia_cir_ref - I_ao + Idc_sensor/3;
    ib_cir_err = ib_cir_ref - I_bo + Idc_sensor/3;
    ic_cir_err = ic_cir_ref - I_co + Idc_sensor/3;

    Va0_ref_integ += TIMEBASE1_SAMPLING_TIME * Ki_Pir *ia_cir_err;
    Va0_ref_prop = Kp_Pir *  ia_cir_err;
    Va0_ref_delay = Va0_ref_res;
    inter =  TIMEBASE1_SAMPLING_TIME*We_M1*We_M1*TIMEBASE1_SAMPLING_TIME;
    Va0_ref_res = (2*Va0_ref_res -Va0_ref_res_n1 + Kres_Pir*TIMEBASE1_SAMPLING_TIME*(ia_cir_err- ia_cir_err_n1))/(1 + inter);
    Va0_ref_res_n1 = Va0_ref_delay;

    Va0_ref = Va0_ref_integ + Va0_ref_prop + Va0_ref_res;

    Vb0_ref_integ += TIMEBASE1_SAMPLING_TIME * Ki_Pir * ( ib_cir_err);
    Vb0_ref_prop = Kp_Pir * ib_cir_errr;
    Vb0_ref_delay = Vb0_ref_res;
    Vb0_ref_res = (2*Vb0_ref_res - Vb0_ref_res_n1 + Kres_Pir*TIMEBASE1_SAMPLING_TIME*(ib_cir_err - ib_cir_err_n1))/(1 + inter);
    Vb0_ref_res_n1 = Vb0_ref_delay;

    Vb0_ref = Vb0_ref_integ + Vb0_ref_prop + Vb0_ref_res;

    Vc0_ref_integ += TIMEBASE1_SAMPLING_TIME * Ki_Pir * ( ic_cir_err);
    Vc0_ref_prop = Kp_Pir * ic_cir_err;
    Vc0_ref_delay = Vc0_ref_res;
    Vc0_ref_res = (2*Vc0_ref_res-Vc0_ref_res_n1 + Kres_Pir*TIMEBASE1_SAMPLING_TIME*(ic_cir_err- ic_cir_err_n1))/(1 + inter);
    Vc0_ref_res_n1 = Vc0_ref_delay;

    Vc0_ref = Vc0_ref_integ + Vc0_ref_prop + Vc0_ref_res;
}


void Reset(void)
{
	// Reset Speed Controller
//	rpm_M1_ref = 0;
	IM1qe_ref_anti = 0;
	IM1qe_ref_integ = 0;
	IM1qe_ref_prop = 0;
	IM1qe_ref_tmp = 0;
	IM1qe_ref = 0;
	IM1de_ref = 0;

	// Reset Current Controller
	IM1de_err = 0;
	VM1de_ref_anti = 0;
	VM1de_ref_integ = 0;
	VM1de_ref_prop = 0;
	VM1de_ref_fb = 0;
	VM1de_ref_ff = 0;
	VM1de_ref = 0;
	VM1de = 0;

	IM1qe_err = 0;
	VM1qe_ref_anti = 0;
	VM1qe_ref_integ = 0;
	VM1qe_ref_prop = 0;
	VM1qe_ref_fb = 0;
	VM1qe_ref_ff = 0;
	VM1qe_ref = 0;
	VM1qe = 0;

	// Reset circulating current suppressing controller
	Icirde_err=0;
	Icirde_ref=0;
	Icirde=0;
	Icirqe_err=0;
	Icirqe_ref=0;
	Icirqe=0;

	Vcirde_ref_integ=0;
	Vcirde_ref_prop=0;
	Vcirde_ref_fb=0;
	Vcirde_ref_ff=0;
	Vcirde_ref=0;

	Vcirqe_ref_integ=0;
	Vcirqe_ref_prop=0;
	Vcirqe_ref_fb=0;
	Vcirqe_ref_ff=0;
	Vcirqe_ref=0;

	// Reset Voltage Reference
	VM1as_ref = 0;
	VM1bs_ref = 0;
	VM1cs_ref = 0;

    W_total = 0;
    W_total_ref = 0;
    W_total_err = 0;

    Wtotal_ref_integ = 0;
    Wtotal_ref_prop = 0;
    Wtotal_ref_fb = 0;
    Wtotal_ref_ff = 0;
	W_lega_err = 0;

	Plega_ref_integ = 0;
	Plega_ref_prop = 0;

	i_ao_cirDC_ref = 0;

	W_legb_err =0;
	Plegb_ref_integ = 0;
	Plegb_ref_prop = 0;

	i_bo_cirDC_ref =0;

	W_legc_err = 0;
	Plegc_ref_integ = 0;
	Plegc_ref_prop = 0;

	i_co_cirDC_ref =0;

	W_diff_com_err = 0;

	Pdiff_com_ref_integ = 0;
	Pdiff_com_ref_prop = 0;
	i_cirAC_ref_pos = 0;
	i_cirAC_ref_pos = 0;


	ia_cirAC_ref_pos = 0;
	ib_cirAC_ref_pos = 0;
	ic_cirAC_ref_pos = 0;

	 W_diff_diffa_err =0;
	 Pdiff_diffa_ref_integ = 0;
	 Pdiff_diffa_ref_prop =0;
	 Pdiff_diffa_ref = 0;

	 W_diff_diffb_err =0;
	 Pdiff_diffb_ref_integ = 0;
	 Pdiff_diffb_ref_prop =0;
	 Pdiff_diffb_ref = 0;

	 W_diff_diffc_err = 0;
	 Pdiff_diffc_ref_integ = 0;
	 Pdiff_diffc_ref_prop = 0;
	 Pdiff_diffc_ref = 0;

	 Pdiffa_theta_integ = 0;
	 Pdiffa_theta_prop =0;
	 Pdiffa_theta_ref = 0;

	 Pdiffb_theta_integ =0;
	 Pdiffb_theta_prop = 0;
	 Pdiffb_theta_ref = 0;

	 Pdiffc_theta_integ = 0;
	 Pdiffc_theta_prop = 0;
	 Pdiffc_theta_ref = 0;

	 Pdiff_theta = 0;

	 P_diffds_ref = 0;
	 P_diffqs_ref = 0;

	P_diffde_ref = 0;
	P_diffqe_ref = 0;

	id_cirAC_ref_neg = 0;
	iq_cirAC_ref_neg = 0;

	ia_cirAC_ref_neg =0;
	ib_cirAC_ref_neg = 0;
	ic_cirAC_ref_neg = 0;

	iDC_err = 0;
	Vdc_ref_integ = 0;
	Vdc_ref_prop = 0;
	Vdc_ref = 0;

	ia_cir_ref = 0;
	ib_cir_ref = 0;
	ic_cir_ref = 0;

	ia_cir_err_n1 = 0;
	ib_cir_err_n1 = 0;
	ic_cir_err_n1 = 0;

	ia_cir_err = 0;
	ib_cir_err = 0;
	ic_cir_err = 0;

	Va0_ref_integ = 0;
	Va0_ref_prop = 0;
	Va0_ref_res_n2 = 0;
	Va0_ref_res_n1 =0;
	Va0_ref_res = 0;

	Va0_ref = 0;

	Vb0_ref_integ = 0;
	Vb0_ref_prop = 0;
	Vb0_ref_res_n2 = 0;
	Vb0_ref_res_n1 =0;
	Vb0_ref_res = 0;

	Vb0_ref = 0;

	Vc0_ref_integ = 0;
	Vc0_ref_prop = 0;
	Vc0_ref_res_n2 = 0;
	Vc0_ref_res_n1 =0;
	Vc0_ref_res = 0;

	Vc0_ref = 0;

	VM1as_refu = 0;
	VM1bs_refu = 0;
	VM1cs_refu = 0;

	VM1as_refl = 0;
	VM1bs_refl = 0;
	VM1cs_refl = 0;

	return;
}

/*

void Compensation()

    {

    I_ao_ext = I_al-I_au;
    I_bo_ext = I_bl-I_bu;
    I_co_ext = I_cl-I_cu;

    if((theta < PI) &&(theta_old >= PI))

    {

       A_scale= integ1;
       B_scale=integ2;
       C_scale=integ3;
       integ1=0;
       integ2=0;
       integ3=0;

    }

       integ1= integ1 + TIMEBASE1_SAMPLING_TIME*PI2 * freq*I_ao_ext;
       integ2= integ2 + TIMEBASE1_SAMPLING_TIME*PI2 * freq*I_bo_ext;
       integ3= integ3 + TIMEBASE1_SAMPLING_TIME*PI2 * freq*I_co_ext;

       theta_old= theta;

       I_a_scale = 3*A_scale/PI2;
       I_b_scale = 3*B_scale/PI2;
       I_c_scale = 3*C_scale/PI2;

       Kcom1 += TIMEBASE1_SAMPLING_TIME * Ks1_i * (0 - I_a_scale);
       Kcom2 += TIMEBASE1_SAMPLING_TIME * Ks1_i * (0 - I_b_scale);
       Kcom3 += TIMEBASE1_SAMPLING_TIME * Ks1_i * (0 - I_c_scale);

       return;

     }


void Compensation_1()

   {

    if((theta < PI) &&(theta_old >= PI))
           {
           A_offset= integ1;
           B_offset= integ2;
           C_offset= integ3;
           D_offset= integ4;
           E_offset= integ5;
           F_offset= integ6;
           integ1=0;
           integ2=0;
           integ3=0;
           integ4=0;
           integ5=0;
           integ6=0;
           }

       integ1= integ1 + TIMEBASE1_SAMPLING_TIME*PI2 * freq*I_au;
       integ2= integ2 + TIMEBASE1_SAMPLING_TIME*PI2 * freq*I_al;
       integ3= integ3 + TIMEBASE1_SAMPLING_TIME*PI2 * freq*I_bu;
       integ4= integ4 + TIMEBASE1_SAMPLING_TIME*PI2 * freq*I_bl;
       integ5= integ5 + TIMEBASE1_SAMPLING_TIME*PI2 * freq*I_cu;
       integ6= integ6 + TIMEBASE1_SAMPLING_TIME*PI2 * freq*I_cl;

       theta_old= theta;

       I_au_offset =TIMEBASE1_SAMPLING_TIME*Ks1_offset* A_offset;
       I_al_offset =TIMEBASE1_SAMPLING_TIME*Ks1_offset* B_offset;
       I_bu_offset =TIMEBASE1_SAMPLING_TIME*Ks1_offset* C_offset;
       I_bl_offset =TIMEBASE1_SAMPLING_TIME*Ks1_offset* D_offset;
       I_cu_offset =TIMEBASE1_SAMPLING_TIME*Ks1_offset* E_offset;
       I_cl_offset =TIMEBASE1_SAMPLING_TIME*Ks1_offset* F_offset;

       return;

    }

*/
