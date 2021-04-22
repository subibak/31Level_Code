/*
 * MMC_controller.c
 *
 *  Created on: Nov 22, 2018
 *      Author: Belete
 */

#include "Define_Header.h"

//initialize flags
Uint16 Mode = 0;
Uint16 Flag_Converter = 0;
Uint16 Flag_VF = 0;
Uint16 Flag_Current = 0;
Uint16 Flag_Voltage = 0;
Uint16 Flag_SupCirCur = 0;
Uint16 Flag_comm_Energy=0;
Uint16 Flag_diff_Energy=0;
Uint16 Flag_Energy_balance=0;
Uint16 Flag_total_Energy=0;
Uint16 Flag_Con = 0;
Uint16 flag_inv_boost=0;
Uint16 Flag_Inv = 0;
Uint16 Flag_test = 0;
Uint16 Flag_gating = 0;
Uint16 Conv_start = 0, Inv_start = 0, Inv_start_Req = 0;

float  Ref_method = 3;
float  Ref_time_cnt = 15000;
float  Ramp_stall_cnt = 0;
Uint16 Ramp_case = 1;

//MMC parameters
float L_arm    = 19e-3F;
float R_arm    = 1e-3F;
float SM_cap   = 4050e-6F;
float SM_mmc_eq= 4050e-7F;

//damping ratio, natural frequency and controller bandwidth
float Wn =0;
float zeta =0;
float Wcc =0;

//PLL
float Erst_ds = 0, Erst_qs = 0;
float Erst_de = 0, Erst_qe = 0;
float Erst_de_low = 0, Erst_qe_low = 0;
float Erst_de_old = 0, Erst_qe_old = 0;
float Kpll_d = 0.01;
float Kpll_p = 0.01;  // 0.1

float theta_grid_integ =0;
float Kpll_i =0.001;// 0.01

float Erst_de_err = 0, Erst_de_err_low = 0;
float Erst_de_err_old = 0, Erst_de_err_low_old = 0;
float theta_grid_ff = 2 * PI * FREQ_GRID * TIMEBASE1_SAMPLING_TIME;
float TWc_Erst_de_err = 0.00100000005;  //0.5024;
float TWc_Erst_dqe = 0.09;   //5.024
float theta_grid = 0;
float freq_grid = 0;
float w_grid_integ =0, w_grid_prop =0,  w_grid =0;
float sin_theta_grid = 0, cos_theta_grid = 0;
float cos_theta2 = 0, sin_theta2 = 0;
float theta2 = 0;
float IM1ds = 0, IM1qs = 0;

float theta_t = 0, freq_t = 60;
float sin_theta_t = 0, cos_theta_t = 0;

//Energy calculation
float W_au=0, W_al=0, W_bu=0, W_bl=0, W_cu=0, W_cl=0;
float W_suma =0, W_sumb =0, W_sumc =0, W_diffa =0, W_diffb =0, W_diffc=0;
float W_suma_low=0, W_sumb_low=0, W_sumc_low =0, W_diffa_low =0, W_diffb_low =0, W_diffc_low =0;
float W_suma_low_old =0, W_sumb_low_old =0, W_sumc_low_old =0, W_diffa_low_old =0,  W_diffb_low_old=0, W_diffc_low_old =0;
float W_suma_low_old_old =0, W_sumb_low_old_old =0, W_sumc_low_old_old =0, W_diffa_low_old_old =0, W_diffb_low_old_old =0, W_diffc_low_old_old =0;
float W_suma_old =0, W_sumb_old =0, W_sumc_old =0, W_diffa_old =0, W_diffb_old =0, W_diffc_old =0;
float TWc_Etotal = 0.075398, TWc_Ediff = 0.037699, Q_60= 2, Q_120= 2;//0.5,
float W_suma_old_old =0, W_sumb_old_old =0, W_sumc_old_old =0, W_diffa_old_old =0, W_diffb_old_old =0, W_diffc_old_old =0;
float P_A_leg_ff, P_B_leg_ff, P_C_leg_ff = 0;
float W_leg=0, W_diff_com=0;
float P_A_Leg_ff_low, P_B_Leg_ff_low, P_C_Leg_ff_low = 0;
float P_A_Leg_ff_low_old, P_B_Leg_ff_low_old, P_C_Leg_ff_low_old = 0;
float P_A_Leg_ff_low_old_old, P_B_Leg_ff_low_old_old, P_C_Leg_ff_low_old_old=0;
float P_A_leg_ff_old, P_B_leg_ff_old, P_C_leg_ff_old = 0;
float P_A_leg_ff_old_old, P_B_leg_ff_old_old, P_C_leg_ff_old_old = 0;
float P_Leg_ave, P_Leg_com = 0;

//Current controller parameters
float IM1de = 0, IM1qe = 0;
float IM1de_low = 0, IM1qe_low = 0;
float IM1de_old = 0, IM1qe_old = 0;
float TWc_IM1_dqe = 0.09;   //5.024
float IM1de_err = 0, IM1qe_err = 0;
float VM1ds_sat = 0, VM1qs_sat = 0, VM1de_sat =0, VM1qe_sat =0, IM1_max=45;
float VM1de_ref = 0, VM1qe_ref = 0;
float VM1de_ref_anti = 0, VM1qe_ref_anti = 0;
float VM1de_ref_prop = 0, VM1qe_ref_prop = 0;
float VM1de_ref_integ =0, VM1qe_ref_integ = 0;
float VM1de_ref_fb = 0, VM1qe_ref_fb = 0;
float VM1de_ref_ff = 0, VM1qe_ref_ff = 0;
float KM1_ac=0, KM1_ic=50, KM1_pc=10;                     //current controller gains  converter p = 6, i = 10, a = 0
float VM1ds_ref = 0, VM1qs_ref = 0;
float VM1as_ref = 0, VM1bs_ref = 0, VM1cs_ref = 0;
float VM1as_sat = 0, VM1bs_sat = 0, VM1cs_sat = 0;
float P_ref =0, P_ref_max =50000, Q_ref = 0;
float Ref_time = 50000,  I_ref_MAX = 0, IM1qe_ref_cc=18, IM1de_ref_cc = 0;
float VM1ds = 0, VM1qs = 0;
float VM1de = 0, VM1qe = 0;
float count =0;

//Circulating Current Suppressing controller parameters
float Icirds = 0, Icirqs = 0;
float Icirde_err = 0, Icirde_ref = 0, Icirde = 0;
float Vcirde_ref_integ = 0, Vcirde_ref_prop = 0, Vcirde_ref_fb = 0, Vcirde_ref_ff = 0;
float Icirqe_err = 0, Icirqe_ref = 0, Icirqe = 0;
float Vcirde_ref = 0, Vcirds_ref = 0;
float Vcirqe_ref_integ = 0, Vcirqe_ref_prop = 0, Vcirqe_ref_fb = 0, Vcirqe_ref_ff = 0;
float Vcirqe_ref = 0, Vcirqs_ref = 0;
float Vciras_ref = 0, Vcirbs_ref = 0, Vcircs_ref = 0;
float Kcir_ic=5, Kcir_pc=12;                                 // CCSC gains
Uint16 Flag_CCSC= 0;

//I_DC Controller parameters for direct modulation
float Vxo_ref=0, Vxo_com=0;
float W_total_ref_init = 4.2;//float W_total_ref_init = 4.2;
float iDC_err =0, Vdc_ref_integ =0, Vdc_ref_prop =0;
float Ki_dc=0,  Kp_dc=0;
float Count_Idc_Transient=0;
float Idc_Transient_Time = 40e6;

//Total energy controller parameters
float W_total_err=0, W_total=0, Wtotal_ref_integ=0, Wtotal_ref_prop=0, PDC_ref=0, iDC_ref =0, p_total=0;//2000;
float W_total_rated_1 = 0;
float Ki_total=0, Kp_total=0,  Ki_dc_total=0, Kp_dc_total=0;      //total energy controller
float Wtotal_ref_fb = 0, Wtotal_ref_ff = 0;
float Vtotala_ref_integ=0,  Vtotala_ref_prop=0, Vtotala_ref=0, W_tran=5000, W_total_ref = 0;
float W_total_ref_cc = 0, W_total_rated = 0;

//I_DC Controller parameters for indirect modulation
float Ki_idc=0, Kp_idc=0;
float Vdc_ref_idc = 0;

//DC voltage controller parameters
float Vdc_ref =0, Vdc_rated =1700, Vdc_ref_vc=0,  pf_ref = 1;
float Vdc_ref_init =0, Vdc_ref_1=0, Vdc_tran =0;
float Vdc_err = 0;
float IM1qe_ref_anti = 0;
float IM1qe_ref_prop = 0;
float IM1qe_ref_integ = 0;
float IM1qe_ref_fb = 0;
float IM1qe_ref_ff = 0;
float IM1qe_ref_tmp = 0;
float IM1de_ref = 0, IM1qe_ref = 0, IM1qe_ref1 = 0;
float Vdc_rated_ref =2000;
float Krst_av=0, Krst_pv =0, Krst_iv=0;                    //DC voltage controller gains

//Leg energy controller
float Kp_leg=0, Ki_leg=0;                          //leg energy controller gains
float W_lega_err=0, Plega_ref_integ =0, Plega_ref_prop =0, i_ao_cirDC_ref =0,  W_legb_err =0, Plegb_ref_integ =0;
float Plegb_ref_prop =0, i_bo_cirDC_ref =0, W_legc_err =0, Plegc_ref_integ =0, Plegc_ref_prop =0, i_co_cirDC_ref =0;

//Common energy difference controller parameters
float Ki_com=0, Kp_com=0;                                                   //common energy difference controller
float W_diff_com_err =0, Pdiff_com_ref_prop =0, i_cirAC_ref_pos =0, ia_cirAC_ref_pos =0, ib_cirAC_ref_pos =0, ic_cirAC_ref_pos =0;//400;
float Pdiff_com_ref_integ =0;

//Differential difference energy controller parameters
float Ki_diff=0, Kp_diff=0;                                                //Differential energy difference controller
float ia_cirAC_ref_neg =0, ib_cirAC_ref_neg =0, ic_cirAC_ref_neg =0, W_diff_diffb_err =0;
float W_diff_diffa_err =0, Pdiff_diffa_ref_integ =0, Pdiff_diffa_ref_prop =0, Pdiff_diffa_ref =0;//1
float Pdiff_diffb_ref_integ =0, Pdiff_diffb_ref_prop =0, Pdiff_diffb_ref =0, W_diff_diffc_err =0, Pdiff_diffc_ref_integ =0, Pdiff_diffc_ref_prop =0, Pdiff_diffc_ref =0;
float Pdiff_diff_ds_ref, Pdiff_diff_qs_ref = 0;
float pdiff_multi_a, pdiff_multi_b, pdiff_multi_c, pdiff_multi_d = 0;
float P_diff_ds_old, P_diff_qs_old = 0, Vms_mag, Vms = 0;
float P_diff_ds, P_diff_qs = 0, Pdiff_diff_ds_ref=0;

//PIR controller parameter
float ia_cir_ref =0, ib_cir_ref =0, ic_cir_ref =0, ib_cir_errr =0;
float ia_cir_err_n1 =0, ib_cir_err_n1 =0, ic_cir_err_n1 =0, ia_cir_err =0, ib_cir_err =0, ic_cir_err =0, Va0_ref_integ =0, Ki_Pi =0, Va0_ref_prop  =0, Va0_ref_delay =0, inter =0, Kp_Pir = 4;
float Va0_ref_res =0, Va0_ref =0, Vb0_ref_integ =0, Vb0_ref_prop =0, Vb0_ref_delay =0, Vb0_ref_res =0,  Vb0_ref =0, Vc0_ref_integ =0, Vc0_ref_prop =0, Vc0_ref_delay =0, Kres_Pir =30;
float Vc0_ref_res =0, Vc0_ref  =0;
float  Ki_Pir =10;
float Va0_ref_res_n1 =0, Vb0_ref_res_n1 =0,  Vc0_ref_res_n1 =0;
float Va0_ref_res_n2 =0, Vb0_ref_res_n2 =0,  Vc0_ref_res_n2 =0;
float Wc = 10;

//Vf controller parameters
float VM1de_ref_vf = 0, VM1qe_ref_vf = 5;
float We_M1 = PI2 * 60;

float I_com = 0;
float V_grid = 48.9898;
Uint32 PRE_MC_TIMER_CNT = 0;

union Mode_Info_DATA Mode_Info, Mode_Info_old;

float Erst_qe_test = 600, Erst_de_test= 0;

//DSOGI pll
float qErst_ds = 0, qErst_qs = 0;
float Erst_ds_prime = 0, Erst_qs_prime = 0, qErst_ds_prime = 0, qErst_qs_prime = 0;
float Erst_ds_q = 0, Erst_qs_q = 0;
float K_dsogi =SQRT2 , W0 = 2 * PI * FREQ_GRID;

float Erst_ds_err = 0, Erst_qs_err = 0;
float Erst_ds_integ_err = 0, Erst_qs_integ_err = 0;
float Erst_ds_p = 0,  Erst_qs_p = 0;

//starting sequence
float Vdc_initial_status =0, Vdc_initial_threshold = 20;
Uint32 Pre_MC_count =0;
Uint32 MAIN_MC_OP_Rec_count =0, MAIN_MC_OP_Rec_TIMER_CNT =50055;

Uint32 CCSC_cnt = 0;
Uint32 Inv_off_cnt = 0;

//Power
union TRANSFER_DATA pf, P, Q;

Uint32 Measure_case = 0;
float test[20] = {0, };

void Operation(void)
{
// send MSB of falg_controller to leg master to enable or disable PWM(buffer enable,74F24)
//Mode_Info.bit.Flag_Controller && 0x100 == 0x000, disable : else  enable PWM.
    if(Measure_case == 1) XF2_ON;
    Grid_DQ();
    if(Measure_case == 1) XF2_OFF;

    if(Measure_case == 2) XF2_ON;
    DSOGI();
    if(Measure_case == 2) XF2_OFF;

    if(Measure_case == 3) XF2_ON;
    PLL();
    if(Measure_case == 3) XF2_OFF;

    if(Measure_case == 4) XF2_ON;
    Starting_sequence();
    if(Measure_case == 4) XF2_OFF;


    if(Flag_fault > 0)
    {
        Mode_Info.bit.Flag_Controller = 0;
        Mode_Info.bit.Flag_Pre_MC = 0;
        Mode_Info.bit.Flag_Main_MC = 0;
    }

    Mode_Info.bit.Flag_Controller = test[4];

    //Controller
    switch(Mode_Info.bit.Valve_type)
    {
    case 0x1: //Inverter
        if(Mode_Info.bit.Control_Method == 1)       // Direct Modulation Control
        {
            //Gain_cal();                           //gain calculation based on operation mode: BTB PTP, or single

            Inverter_Direct();
        }
        else if(Mode_Info.bit.Control_Method == 2)  // Indirect Modulation Control
        {
            //gain calculation based on operation mode: BTB, PTP, or single
            Inverter_Indirect();
        }
        else                                        // Reset
        {
            Mode_Info.bit.Control_Method = Mode_Info.bit.Control_Method && 0x0;

        }

        break;
    case 0x2: //Converter
        if(Mode_Info.bit.Control_Method == 1)       // Direct Modulation Control
         {
            //Gain_cal();                           //gain calculation based on operation mode: BTB PTP, or single
             Converter_Direct();
         }
         else if(Mode_Info.bit.Control_Method == 2)  // Indirect Modulation Control
         {
             //gain calculation based on operation mode: BTB PTP, or single
             Converter_Indirect();
         }
         else                                        // Reset
         {
             Mode_Info.bit.Control_Method = Mode_Info.bit.Control_Method && 0x0;

         }
        break;
    default: //break
        Mode_Info.bit.Flag_Controller = Mode_Info.bit.Flag_Controller && 0x0FF;
        Reset();
        Flag_gating = 0;
        break;
    }

   NLC();

}

/*
 * 1
 */

void PLL(void)
{
    Erst_de_err = -(cos_theta_grid * Erst_ds + sin_theta_grid * Erst_qs);
    Erst_de_err_low = LPF1(Erst_de_err_low, Erst_de_err, Erst_de_err_old, TWc_Erst_de_err);

    //PD pll controller
//    theta_grid += Kpll_d * (Erst_de_err - Erst_de_err_old) + Kpll_p * Erst_de_err*TIMEBASE1_SAMPLING_TIME;
//    theta_grid += Kpll_d * (Erst_de_err_low - Erst_de_err_low_old) + Kpll_p * Erst_de_err_low * TIMEBASE1_SAMPLING_TIME;

    //Pi pll controller
    w_grid_integ += Kpll_i * Erst_de_err_low*TIMEBASE1_SAMPLING_TIME;
    w_grid_prop = Kpll_p * Erst_de_err_low;
    w_grid = w_grid_integ + w_grid_prop + W0;

    theta_grid += w_grid*TIMEBASE1_SAMPLING_TIME;

    Erst_de_err_low_old = Erst_de_err_low;
    Erst_de_err_old = Erst_de_err;

    if (theta_grid > 2*PI)     theta_grid -= 2*PI;
    else if (theta_grid < 0)    theta_grid += 2*PI;

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

    Icirds = (I_AO - 0.5 * (I_BO + I_CO))*2/3;
    Icirqs = (I_BO  - I_CO) * INV_SQRT3;

    Icirde =  cos_theta2 * Icirds + sin_theta2 * Icirqs;
    Icirqe = -sin_theta2 * Icirds + cos_theta2 * Icirqs;
}

/*
 * 2
 */

void Grid_DQ(void)
{
    sin_theta_grid = sin(theta_grid);
    cos_theta_grid = cos(theta_grid);

    //dq Transform for line current(abcs to dqe)
    IM1ds = I_AS ;
    IM1qs = (I_BS  - I_CS ) * INV_SQRT3;

    // dq Transform for line current(dqs to dqe)
    IM1de =  cos_theta_grid  * IM1ds + sin_theta_grid  * IM1qs;
    IM1qe = -sin_theta_grid  * IM1ds + cos_theta_grid  * IM1qs;

    IM1de_low = LPF1(IM1de_low, IM1de, IM1de_old, TWc_IM1_dqe);
    IM1qe_low = LPF1(IM1qe_low, IM1qe, IM1qe_old, TWc_IM1_dqe);

    // dq Transform  Grid voltage(abcs to dqs)
//    Erst_ds = V_AS_sec;
//    Erst_qs = (V_BS_sec - V_CS_sec) * INV_SQRT3;

//    Erst_ds = (V_AS_pri - 0.5 * (V_BS_pri + V_CS_pri))*2/3;
//    Erst_qs = (V_BS_pri - V_CS_pri) * INV_SQRT3;

    Erst_ds = (V_AS_sec - 0.5 * (V_BS_sec + V_CS_sec))*2/3;
    Erst_qs = (V_BS_sec - V_CS_sec) * INV_SQRT3;

    Erst_de = cos_theta_grid * Erst_ds + sin_theta_grid * Erst_qs;
    Erst_qe = -sin_theta_grid * Erst_ds + cos_theta_grid * Erst_qs;

    Erst_de_low = LPF1(Erst_de_low, Erst_de, Erst_de_old, TWc_Erst_dqe);
    Erst_qe_low = LPF1(Erst_qe_low, Erst_qe, Erst_qe_old, TWc_Erst_dqe);

    //Power Calculation
    pf.all_F =   IM1qe_low/(IM1qe_low*IM1qe_low + IM1de_low*IM1de_low);                   // Power factor
    P.all_F =    1.5*(Erst_qe_low*IM1qe_low + Erst_de_low*IM1de_low);                     // Active Power
    Q.all_F =    1.5*(Erst_de_low*IM1qe_low - Erst_qe_low*IM1de_low);                     // Reactive Power
}

/*
 * 3
 */
void Energy_Cal(void)
{
     W_au = 0.5*SM_cap*(V_AU[0]*V_AU[0]+V_AU[1]*V_AU[1]+V_AU[2]*V_AU[2]+V_AU[3]*V_AU[3]+V_AU[4]*V_AU[4]);
     W_bu = 0.5*SM_cap*(V_BU[0]*V_BU[0]+V_BU[1]*V_BU[1]+V_BU[2]*V_BU[2]+V_BU[3]*V_BU[3]+V_BU[4]*V_BU[4]);
     W_cu = 0.5*SM_cap*(V_CU[0]*V_CU[0]+V_CU[1]*V_CU[1]+V_CU[2]*V_CU[2]+V_CU[3]*V_CU[3]+V_CU[4]*V_CU[4]);

     W_al = 0.5*SM_cap*(V_AL[0]*V_AL[0]+V_AL[1]*V_AL[1]+V_AL[2]*V_AL[2]+V_AL[3]*V_AL[3]+V_AL[4]*V_AL[4]);
     W_bl = 0.5*SM_cap*(V_BL[0]*V_BL[0]+V_BL[1]*V_BL[1]+V_BL[2]*V_BL[2]+V_BL[3]*V_BL[3]+V_BL[4]*V_BL[4]);
     W_cl = 0.5*SM_cap*(V_CL[0]*V_CL[0]+V_CL[1]*V_CL[1]+V_CL[2]*V_CL[2]+V_CL[3]*V_CL[3]+V_CL[4]*V_CL[4]);

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

     W_leg = (W_suma_low + W_sumb_low + W_sumc_low)/3;
     W_diff_com = (W_diffa_low + W_diffb_low + W_diffc_low)/3;

     P_A_leg_ff = VM1as_ref * I_AS ;
     P_B_leg_ff = VM1bs_ref * I_BS ;
     P_C_leg_ff = VM1cs_ref * I_CS ;

     P_A_Leg_ff_low = BRF(P_A_Leg_ff_low, P_A_Leg_ff_low_old, P_A_Leg_ff_low_old_old, P_A_leg_ff, P_A_leg_ff_old, P_A_leg_ff_old_old,TWc_Etotal,Q_120);
     P_B_Leg_ff_low = BRF(P_B_Leg_ff_low, P_B_Leg_ff_low_old, P_B_Leg_ff_low_old_old, P_B_leg_ff, P_B_leg_ff_old, P_B_leg_ff_old_old,TWc_Etotal,Q_120);
     P_C_Leg_ff_low = BRF(P_C_Leg_ff_low, P_C_Leg_ff_low_old, P_C_Leg_ff_low_old_old, P_C_leg_ff, P_C_leg_ff_old, P_C_leg_ff_old_old,TWc_Etotal,Q_120);

     P_Leg_ave = (P_A_Leg_ff_low + P_B_Leg_ff_low + P_C_Leg_ff_low)/3;
     P_Leg_com = - P_Leg_ave;

     Vdc_low = LPF1(Vdc_low, V_DC, Vdc_old, Twc_Vdc);
     Idc_sensor_low = LPF1(Idc_sensor_low, I_DC, I_DC_old, Tcl);

     return;
}

/*
 * 4
 */
void Current_Control(void)
{
    // d-axis Current Control
    if(Mode_Info.bit.Valve_type ==1)
    {
        IM1de_err = IM1de_ref - IM1de;
        IM1qe_err = IM1qe_ref - IM1qe;
    }
    else if (Mode_Info.bit.Valve_type ==2)
    {
//        IM1de_err = IM1de_ref - IM1de;
//        IM1qe_err = IM1qe_ref - IM1qe;
        IM1de_err = -IM1de_ref + (-IM1de);
        IM1qe_err = -IM1qe_ref + (-IM1qe);
    }

    VM1ds_sat = VM1as_sat;
    VM1qs_sat = (VM1bs_sat - VM1cs_sat) * INV_SQRT3;

    // dq Transform(dqs to dqe)
    VM1de_sat =  cos_theta_grid  * VM1ds_sat + sin_theta_grid  * VM1qs_sat;
    VM1qe_sat = -sin_theta_grid  * VM1ds_sat + cos_theta_grid  * VM1qs_sat;

    VM1de_ref_anti = KM1_ac * (VM1de_ref - VM1de_sat);
    VM1de_ref_integ += TIMEBASE1_SAMPLING_TIME * KM1_ic * (IM1de_err- VM1de_ref_anti);
    VM1de_ref_prop = KM1_pc * IM1de_err;

    VM1de_ref_fb = VM1de_ref_integ + VM1de_ref_prop;
    VM1de_ref_ff = 0 - 2*PI*FREQ_GRID*(L_arm/2)*IM1qe; //Erst_de_low =0
    VM1de_ref = VM1de_ref_fb + VM1de_ref_ff;

    // q-axis Current Control

    VM1qe_ref_anti = KM1_ac * (VM1qe_ref - VM1qe_sat);
    VM1qe_ref_integ += TIMEBASE1_SAMPLING_TIME * KM1_ic * (IM1qe_err - VM1qe_ref_anti);
    VM1qe_ref_prop = KM1_pc * IM1qe_err;

    VM1qe_ref_fb = VM1qe_ref_integ + VM1qe_ref_prop;
    VM1qe_ref_ff = Erst_qe_test + 2*PI*FREQ_GRID*(L_arm/2)*IM1de; // Erst_qe_low

    VM1qe_ref = VM1qe_ref_fb + VM1qe_ref_ff;

    // Inverse Transform(dqe to dqs)
    VM1ds_ref = cos_theta_grid  * VM1de_ref - sin_theta_grid  * VM1qe_ref;
    VM1qs_ref = sin_theta_grid  * VM1de_ref + cos_theta_grid  * VM1qe_ref;

    // Inverse Transform(dqs to abcs)
    VM1as_ref = VM1ds_ref;
    VM1bs_ref = -0.5 * (VM1ds_ref - SQRT3 * VM1qs_ref);
    VM1cs_ref = -0.5 * (VM1ds_ref + SQRT3 * VM1qs_ref);

}

/*
 * 5
 */
void SuppCirCurrent(void)
{
    Icirde_err = Icirde_ref - Icirde;

    Vcirde_ref_integ += TIMEBASE1_SAMPLING_TIME * Kcir_ic * Icirde_err;
    Vcirde_ref_prop = Kcir_pc * Icirde_err;

    Vcirde_ref_fb = Vcirde_ref_integ + Vcirde_ref_prop;
    Vcirde_ref_ff = -L_arm* 2 * We_M1 * Icirqe;

    Vcirde_ref = Vcirde_ref_fb + Vcirde_ref_ff;

    // q-axis circulating Current suppressing controller
    Icirqe_err = Icirqe_ref - Icirqe;

    Vcirqe_ref_integ += TIMEBASE1_SAMPLING_TIME * Kcir_ic * Icirqe_err;
    Vcirqe_ref_prop = Kcir_pc * Icirqe_err;

    Vcirqe_ref_fb = Vcirqe_ref_integ + Vcirqe_ref_prop;
    Vcirqe_ref_ff =  L_arm *2* We_M1 * Icirde;

    Vcirqe_ref = Vcirqe_ref_fb + Vcirqe_ref_ff;

    // Inverse Transform for circulating current controller (dqe to dqs)
    Vcirds_ref = cos_theta2 * Vcirde_ref - sin_theta2 * Vcirqe_ref;
    Vcirqs_ref = sin_theta2 * Vcirde_ref + cos_theta2 * Vcirqe_ref;

    // Inverse Transform for circulating current controller(dqs to abcs)
    Vciras_ref = Vcirds_ref;
    Vcirbs_ref = -0.5 * (Vcirds_ref - SQRT3 * Vcirqs_ref);
    Vcircs_ref = -0.5 * (Vcirds_ref + SQRT3 * Vcirqs_ref);

    Va0_ref = Vciras_ref;
    Vb0_ref = Vcirbs_ref;
    Vc0_ref = Vcircs_ref;
}

/*
 * 6
 */
void Idc_Control(void)
{
    Energy_Cal();

    if (Flag_Out_Loop)
    {
        W_total = W_suma + W_sumb + W_sumc;
        W_total_ref_init = 3*SM_cap*(Vdc_rated*0.5)*(Vdc_rated*0.5)/4;
        W_total_rated_1 = W_total_ref_init;

        if(W_total_rated_1 >= W_total_ref)
        W_total_rated_1 = W_total_ref;
        else
        W_total_rated_1 += (TIMEBASE1_SAMPLING_TIME*W_tran);

        //Total Energy controller gains

        Wn =2*PI/(20*OUTERLOOP_SAMPLING_TIME);
        Ki_dc_total = Wn*Wn/Vdc_rated;
        Kp_dc_total = 2*zeta*Wn/Vdc_rated;

        W_total_err = W_total_rated_1 - W_total;
        Wtotal_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_dc_total * W_total_err;
        Wtotal_ref_prop = Kp_dc_total * W_total_err;
        PDC_ref = Wtotal_ref_integ + Wtotal_ref_prop + 3*VM1qe_ref*IM1qe_ref/2;
        iDC_ref = PDC_ref/Vdc_rated;
   }

    //DC current controller gains
    Wcc =2*PI/(20*TIMEBASE1_SAMPLING_TIME);
    Ki_idc = R_arm* Wcc;
    Kp_idc = L_arm*Wcc;

    //DC current controller
    iDC_err = iDC_ref - Idc_sensor_low;
    Vdc_ref_integ += TIMEBASE1_SAMPLING_TIME * Ki_idc * iDC_err;
    Vdc_ref_prop = Kp_idc * iDC_err;
    Vdc_ref_idc = Vdc_ref_integ + Vdc_ref_prop + Vdc_rated;
    Vxo_com = Vdc_ref_idc - (Vdc_low) + (Vdc_rated);
    Vxo_ref = Vxo_com/3;

    return;
}

/*
 * 7
 */
void Converter_voltage(void)
{

    if (Flag_Out_Loop)
    {
        if(count ==0)
        {
        Vdc_ref_1 = Vdc_low;
        IM1qe_ref_integ = Krst_pv * Vdc_low;
        count += 1;
        }

        if(Ref_method == 1)                             //ramp voltage reference
        {
            Vdc_tran = 10*Ref_time;
            if(Vdc_ref_1 >= Vdc_ref)
            Vdc_ref_1 = Vdc_ref;
            else
            Vdc_ref_1 += (TIMEBASE1_SAMPLING_TIME*Vdc_tran);
        }
        else
            Vdc_ref_1 = Vdc_ref;

        Vdc_err = Vdc_ref_1 - Vdc_low;

        //IP controller gain calculation
//        Wn =2*PI/(20*OUTERLOOP_SAMPLING_TIME);
//        Krst_iv = Wn*Wn*SM_mmc_eq*Vdc_ref_1/(1.5*Erst_qe_low);
//        Krst_pv = 2*zeta*Wn*SM_mmc_eq*Vdc_ref_1/(1.5*Erst_qe_low);
//        Krst_av =1/Krst_pv;

        IM1qe_ref_anti = Krst_av * (IM1qe_ref_tmp - IM1qe_ref);
        IM1qe_ref_integ += OUTERLOOP_SAMPLING_TIME * Krst_iv * (Vdc_err - IM1qe_ref_anti);
        IM1qe_ref_prop = Krst_pv * Vdc_low;

        IM1qe_ref_fb = IM1qe_ref_integ - IM1qe_ref_prop;
        IM1qe_ref_ff = I_com;
        // Because of definition of output current direction
        IM1qe_ref_tmp = IM1qe_ref_fb + IM1qe_ref_ff;

        IM1qe_ref = BOUND(IM1qe_ref_tmp, IM1_max); //Limit

        IM1qe_ref1 = -IM1qe_ref;
        IM1de_ref = sqrt(1 - pf_ref * pf_ref) / pf_ref * IM1qe_ref;
    }

}

/*
 * 8
 */
void Vf_Control_Inv(void)
{
    sin_theta_t = sin(theta_t);
    cos_theta_t = cos(theta_t);

    // Inverse Transform(dqe to dqs)
    VM1ds_ref = cos_theta_t * VM1de_ref - sin_theta_t * VM1qe_ref;
    VM1qs_ref = sin_theta_t * VM1de_ref + cos_theta_t * VM1qe_ref;

    // Inverse Transform(dqs to abc)
    VM1as_ref = VM1ds_ref;
    VM1bs_ref = -0.5 * (VM1ds_ref - SQRT3 * VM1qs_ref);
    VM1cs_ref = -0.5 * (VM1ds_ref + SQRT3 * VM1qs_ref);

    Va0_ref = 0;
    Vb0_ref = 0;
    Vc0_ref = 0;
}

void Vf_Control(void)
{
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
}
/*
 * 9
 */

void Reference(void)
{
    //I_ref_MAX = 1.5*P_ref_max/(Erst_qe_low);
//    IM1qe_ref_cc = 1.5* P_ref/(Erst_qe_low);
//    IM1de_ref_cc =  1.5 * Q_ref/(Erst_qe_low);
//
//    IM1qe_ref_cc = IM1qe_ramp_ref;
//    IM1de_ref_cc =  0;

    if(Ref_method ==0)                              //step reference method
    {
        IM1de_ref = IM1de_ref_cc;
        IM1qe_ref = IM1qe_ref_cc;
    }
    else if(Ref_method == 1)                             //ramp reference for forward power flow
    {
        if(IM1qe_ref >= IM1qe_ref_cc) IM1qe_ref = IM1qe_ref_cc;
        else                          IM1qe_ref += IM1qe_ref_cc/Ref_time_cnt;
    }
    else if(Ref_method == 2)                             //ramp reference for forward power flow
    {
        if(IM1qe_ref <= -IM1qe_ref_cc) IM1qe_ref = -IM1qe_ref_cc;
        else                           IM1qe_ref -= IM1qe_ref_cc/Ref_time_cnt;
    }
    else if(Ref_method == 3)                              //ramp reference for reverse power flow
    {
        switch(Ramp_case)
        {
        case 1:
            if(Ramp_stall_cnt++ >= RAMP_STALL_MAX)
            {
                Ramp_case = 2;
                Ramp_stall_cnt = 0;
            }
            break;
        case 2:
            if(IM1qe_ref >= IM1qe_ref_cc)
            {
                IM1qe_ref = IM1qe_ref_cc;
                Ramp_case = 3;
            }
            else
                IM1qe_ref += IM1qe_ref_cc/Ref_time_cnt;

            break;
        case 3:
            if(Ramp_stall_cnt++ >= RAMP_STALL_MAX)
            {
                Ramp_case = 4;
                Ramp_stall_cnt = 0;
            }
            break;
        case 4:
            if(IM1qe_ref <= -IM1qe_ref_cc)
            {
                IM1qe_ref = -IM1qe_ref_cc;
                Ramp_case = 1;
            }
            else
                IM1qe_ref -= IM1qe_ref_cc/Ref_time_cnt;

            break;

        default: break;
        }


    }
    return;
}

/*
 * 10
 */
//void Gain_Cal(void)
//
// {
//    if(Mode_Info.bit.OP_Mode|Mode_Info.bit.Valve_type == 0x1)                //Single valve Converter operation
//    {
        //Current controller gains
//            KM1_ac=0;
//            KM1_ic=0;
//            KM1_pc=0;

        //CCSC gains
//            Kcir_ic=0;
//            Kcir_pc=0;

        //Voltage controller gain
//            Krst_av=0;
//            Krst_pv =0;
//            Krst_iv=0;

//    }
//    if(Mode_Info.bit.OP_Mode|Mode_Info.bit.Valve_type == 0x2)                //PTP Converter operation
//    {
        //Current controller gains
//            KM1_ac=0;
//            KM1_ic=0;
//            KM1_pc=0;

        //CCSC gains
//            Kcir_ic=0;
//            Kcir_pc=0;

        //Voltage controller gain
//            Krst_av=0;
//            Krst_pv =0;
//            Krst_iv=0;
//
//    }
//    if(Mode_Info.bit.OP_Mode|Mode_Info.bit.Valve_type == 0x3)                // BTB Converter operation
//    {
        //Current controller gains
//            KM1_ac=0;
//            KM1_ic=0;
//            KM1_pc=0;

        //CCSC gains
//            Kcir_ic=0;
//            Kcir_pc=0;

        //Voltage controller gain
//            Krst_av=0;
//            Krst_pv =0;
//            Krst_iv=0;
//    }
//    if(Mode_Info.bit.OP_Mode|Mode_Info.bit.Valve_type == 0x1)                //Single valve Inverter operation
//    {
        //Current controller gains
//            KM1_ac=0;
//            KM1_ic=0;
//            KM1_pc=0;

        //CCSC gains
//            Kcir_ic=0;
//            Kcir_pc=0;

        //Total energy controller gains
//            Ki_dc_total=0;
//            Kp_dc_total=0;

        //DC current controller gains
//            Ki_idc=0;
//            Kp_idc=0;
//    }
//    if(Mode_Info.bit.OP_Mode|Mode_Info.bit.Valve_type == 0x2)                //PTP Inverter operation
//    {
        //Current controller gains
//            KM1_ac=0;
//            KM1_ic=0;
//            KM1_pc=0;

        //CCSC gains
//            Kcir_ic=0;
//            Kcir_pc=0;

        //Total energy controller gains
//            Ki_dc_total=0;
//            Kp_dc_total=0;

        //DC current controller gains
//            Ki_idc=0;
//            Kp_idc=0;

//    }
//    if(Mode_Info.bit.OP_Mode|Mode_Info.bit.Valve_type == 0x3)                // BTB Inverter operation
//    {
        //Current controller gains
//            KM1_ac=0;
//            KM1_ic=0;
//            KM1_pc=0;

        //CCSC gains
//            Kcir_ic=0;
//            Kcir_pc=0;

        //Total energy controller gains
//            Ki_dc_total=0;
//            Kp_dc_total=0;

        //DC current controller gains
//            Ki_idc=0;
//            Kp_idc=0;

//    }
//
//    return;
//}

/*
 * 11
 */
void Reset(void)
{
    // Reset Voltage controller
    IM1qe_ref_anti = 0;
    IM1qe_ref_integ = 0;
    IM1qe_ref_prop = 0;
    IM1qe_ref_tmp = 0;
    IM1qe_ref = 0;
    IM1de_ref = 0;
    count =0;

    // Reset Current Controller
    IM1de_err = 0;
    VM1de_ref_anti = 0;
    VM1de_ref_integ = 0;
    VM1de_ref_prop = 0;
    VM1de_ref_fb = 0;
    VM1de_ref_ff = 0;
    VM1de_ref = 0;
    VM1de = 0;
    VM1de_sat = 0;

    IM1qe_err = 0;
    VM1qe_ref_anti = 0;
    VM1qe_ref_integ = 0;
    VM1qe_ref_prop = 0;
    VM1qe_ref_fb = 0;
    VM1qe_ref_ff = 0;
    VM1qe_ref = 0;
    VM1qe = 0;
    VM1qe_sat = 0;

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

    // CCSC
    Flag_CCSC = 0;
    CCSC_cnt = 0;
    // DC charging
    Ref_method = 3;
    Ramp_stall_cnt = 0;
    Ramp_case = 1;
    Vdc_char_ref = 850;
    DC_CHARGE_cnt = 0;

    //starting sequence reset
    Inv_start_Req =0;
    Vdc_initial_status =0;
    Pre_MC_count =0;
    MAIN_MC_OP_Rec_count =0;

}


/*
 * 12
 */

void Inverter_Direct(void)
{
    switch(Mode_Info.bit.Flag_Controller)             // Flag controller bits; 9: operation, 8:v/f, 7:comm_diff, 6:comm_diff, 5: leg, 4:Total, 3:I_dc or Vdc , 2: ccsc, 1: cc
    {
    case 0x101 :      // Flag_Operation + Current Control
        // Reference Input
        if(DC_CHARGE_cnt < INV_OP_CHARGE_TIMER_CNT)
        {
            DC_CHRAGING_SEQ();
            switch(DC_CHARGE_cnt)
            {
            case PRE_MC_OP_TIMER_CNT:
                Mode_Info.bit.Flag_Pre_MC = 1;
                break;
            case MAIN_MC_OP_TIMER_CNT:
                Mode_Info.bit.Flag_Main_MC = 1;
                break;
            default:
                break;
            }
            DC_CHARGE_cnt++;
        }
        else
        {
            Flag_gating = 1;
            Reference();
            Current_Control();
        }

        break;
    case 0x103 :      // Flag_Operation + Current Control + CCSC
        // Reference Input
        if(DC_CHARGE_cnt < INV_OP_CHARGE_TIMER_CNT)
        {
            if(Measure_case == 5) XF2_ON;
            DC_CHRAGING_SEQ();
            if(Measure_case == 5) XF2_OFF;

            switch(DC_CHARGE_cnt)
            {
            case PRE_MC_OP_TIMER_CNT:
                Mode_Info.bit.Flag_Pre_MC = 1;
                break;
            case MAIN_MC_OP_TIMER_CNT:
                Mode_Info.bit.Flag_Main_MC = 1;
                break;
            default:
                break;
            }
            DC_CHARGE_cnt++;
        }
        else
        {
            Flag_gating = 1;
            if(Measure_case == 6) XF2_ON;
            Reference();
            if(Measure_case == 6) XF2_OFF;

            Icirde_ref = 0;
            Icirqe_ref = 0;

            if(Measure_case == 7) XF2_ON;
            Current_Control();
            if(Measure_case == 7) XF2_OFF;

            if(Measure_case == 8) XF2_ON;
            if(CCSC_cnt < CCSC_TIME) CCSC_cnt++;
            else                     SuppCirCurrent();
            if(Measure_case == 8) XF2_OFF;
        }

        break;
    case 0x104 :      // Flag_Operation + DC_Currnet Control
        // Reference Input
        Flag_gating = 1;

        W_total_ref = W_total_ref_cc;                     //  W_total_ref_cc = 3*SM_cap*Vdc_rated*Vdc_rated/4;

        if(Measure_case == 9) XF2_ON;
        Idc_Control();
        if(Measure_case == 9) XF2_OFF;

        break;
    case 0x105:               // Flag_Operation + Current Control + DC_Current Control
        // Reference Input
        Flag_gating = 1;

        W_total_ref = W_total_ref_cc;                     //  W_total_ref_cc = 3*SM_cap*Vdc_rated*Vdc_rated/4;

        Reference();

        if(++Count_Idc_Transient >= Idc_Transient_Time)   //counter until the DC current controller reach steady state
        {
            MC_OP_Inv();                                  //connect the grid to inverter first through PRE_MC and then through MAIN_MC

            Current_Control();

        }
        Idc_Control();

        break;
    case 0x107:             // Flag_Operation + Current Control + DC_Current Control + CCSE
        // Reference Input
        Flag_gating = 1;

        W_total_ref = W_total_ref_cc;                     //  W_total_ref_cc = 3*SM_cap*Vdc_rated*Vdc_rated/4;

        Reference();

        Icirde_ref = 0;
        Icirqe_ref = 0;

        if(++Count_Idc_Transient >= Idc_Transient_Time)    //counter until the DC current controller reach steady state
        {
            MC_OP_Inv();                                   //connect the grid to inverter first through PRE_MC and then through MAIN_MC

            Current_Control();
            SuppCirCurrent();

        }

        Idc_Control();

        break;
    case 0x180 :                                // Flag_Operation + V/F
        Flag_gating = 1;
    case 0x080 : // V/F
        VM1de_ref = VM1de_ref_vf;
        VM1qe_ref = VM1qe_ref_vf;

        theta_t += TIMEBASE1_SAMPLING_TIME * freq_t * PI2;
        if (theta_t > PI2)         theta_t -= PI2;
        else if (theta_t < 0)      theta_t += PI2;

        if(Measure_case == 10) XF2_ON;
        Vf_Control_Inv();
        if(Measure_case == 10) XF2_OFF;

        break;
    default :
        Reset();
        Flag_gating = 0;
        break;
    }

}
/*
 * 13
 */
void Converter_Direct(void)
{
    switch(Mode_Info.bit.Flag_Controller)            // Flag controller bits; 9: operation, 8:E_total, 7:leg, 6:comm_diff, 5: diff_diff, 4:PIR, 3:I_dc , 2: ccsc, 1: cc
    {
    case 0x101 :             // Flag_Operation + Current Control
        // Reference Input
        IM1de_ref = IM1de_ref_cc;
        IM1qe_ref = IM1qe_ref_cc;
//        Vdc_rated = Vdc_low;

        Current_Control();

        Flag_gating = 1;

        break;
    case 0x103 :             // Flag_Operation + Current Control +CCSC
        // Reference Input
        IM1de_ref = IM1de_ref_cc;
        IM1qe_ref = IM1qe_ref_cc;

        Icirde_ref = 0;
        Icirqe_ref = 0;

        Current_Control();
        SuppCirCurrent();

        Flag_gating = 1;

        break;
    case 0x104 :             // Flag_Operation + Voltage Control
        // Reference Input

        Vdc_ref = Vdc_ref_vc;
        Vdc_rated = Vdc_ref_vc;
        Converter_voltage();

//        IM1de_err = -IM1de_ref + (-IM1de);
//        IM1qe_err = -IM1qe_ref + (-IM1qe);
        Current_Control();

        Flag_gating = 1;

        break;
    case 0x106 :             // Flag_Operation + Voltage Control + CCSC
        // Reference Input
        if(Measure_case == 11) XF2_ON;
        Vdc_ref = Vdc_ref_vc;
        Vdc_rated = Vdc_ref_vc;
        Converter_voltage();
        if(Measure_case == 11) XF2_OFF;
        IM1de_err = -IM1de_ref + (-IM1de);
        IM1qe_err = -IM1qe_ref + (-IM1qe);

        Icirde_ref = 0;
        Icirqe_ref = 0;
        Current_Control();
        SuppCirCurrent();

        Flag_gating = 1;

        break;

    case 0x180 :                                            // Flag_Operation + V/F
        Flag_gating = 1;
    case 0x080 : // V/F
        // Reference Input
        VM1de_ref = -VM1de_ref_vf;
        VM1qe_ref = -VM1qe_ref_vf + Erst_qe_low;             //use very small VM1qe_ref_vf
//        Vdc_rated = Vdc_low;
        Vf_Control();
        break;
    default :
        Reset();
        Flag_gating = 0;
        break;
    }

}

/*
 * 14
 */


void Converter_Indirect(void)
{
    if(Measure_case == 12) XF2_ON;
    Energy_Cal();
    if(Measure_case == 12) XF2_OFF;

    if(Measure_case == 13) XF2_ON;
    if (Flag_Out_Loop)
    {
        if (Flag_total_Energy)    //total energy controller
        {
            W_total = W_suma + W_sumb + W_sumc;
            W_total_ref = 3*SM_cap*Vdc_rated*Vdc_rated/4;
            W_total_ref_init = 3*SM_cap*(Vdc_rated*0.5)*(Vdc_rated*0.5)/4;
            W_total_rated_1 = W_total_ref_init;

            if(W_total_rated_1 >= W_total_ref)
             W_total_rated_1 = W_total_ref;
            else
              W_total_rated_1 += (TIMEBASE1_SAMPLING_TIME*W_tran);

            //Total Energy controller gains
            //Wn =2*PI/(20*OUTERLOOP_SAMPLING_TIME);
            // Ki_dc_total = Wn*Wn/(1.5*Erst_qe_low);
            // Kp_dc_total = 2*zeta*Wn/(1.5*Erst_qe_low);

            W_total_err = W_total_rated_1- W_total;
            Wtotal_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_total * W_total_err;
            Wtotal_ref_prop = Kp_total * W_total_err;
            Wtotal_ref_fb = Wtotal_ref_integ + Wtotal_ref_prop;
            Wtotal_ref_ff = -Vdc_rated*Idc_sensor_low; //

            IM1qe_ref = -2*(Wtotal_ref_fb + Wtotal_ref_ff)/(Erst_qe*3);
        }
        if(Measure_case == 13) XF2_OFF;

        if(Measure_case == 14) XF2_ON;
        if(Flag_Energy_balance)    // leg balancing controller
            Leg_Energy_Balance();
        if(Measure_case == 14) XF2_OFF;

        if(Measure_case == 15) XF2_ON;
        if(Flag_comm_Energy)        //upper and lower arm balancing controller- common error
            Commom_Energy_Balance();
        if(Measure_case == 15) XF2_OFF;

        if(Measure_case == 16) XF2_ON;
        if(Flag_diff_Energy)     //upper and lower arm balancing controller- differential error
            Diff_Energy_Balance();
        if(Measure_case == 16) XF2_OFF;
    }

    Current_Control();

    if(Measure_case == 17) XF2_ON;
    Energy_diff_PIR();
    if(Measure_case == 17) XF2_OFF;

    return;

}

 void Inverter_Indirect(void)

 {
     if(Flag_Inv)
     {

         Current_Control();

     }


     Energy_Cal();

     if (Flag_Out_Loop)
     {
        if (Flag_total_Energy)    //total energy controller
        {
        W_total = W_suma + W_sumb + W_sumc;
        W_total_ref = 3*SM_cap*Vdc_rated*Vdc_rated/4;
        W_total_err = W_total_ref - W_total;

        //Total Energy controller gains

        //Wn =2*PI/(20*OUTERLOOP_SAMPLING_TIME);
        // Ki_total = Wn*Wn/Vdc_rated;
        // Kp_total = 2*zeta*Wn/Vdc_rated;

        Wtotal_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_total * W_total_err;
        Wtotal_ref_prop = Kp_total * W_total_err;
        PDC_ref = Wtotal_ref_integ + Wtotal_ref_prop + 3*VM1qe_ref*IM1qe/2;
        iDC_ref = PDC_ref/Vdc_rated;

         }


        if(Flag_Energy_balance)        // leg balancing controller
         Leg_Energy_Balance();

        if(Flag_comm_Energy)           //upper and lower arm balancing controller- common error
         Commom_Energy_Balance();

        if(Flag_diff_Energy)           //upper and lower arm balancing controller- differential error
         Diff_Energy_Balance();

     }

     if(Measure_case == 18) XF2_ON;
     //DC current controller
     iDC_err = -iDC_ref + Idc_sensor_low;
     Vdc_ref_integ += TIMEBASE1_SAMPLING_TIME * Ki_dc * iDC_err;
     Vdc_ref_prop = Kp_dc * iDC_err;
     Vdc_ref = Vdc_ref_integ + Vdc_ref_prop + Vdc_rated;
     if(Measure_case == 18) XF2_OFF;

     Energy_diff_PIR();

     return;
 }

 void Leg_Energy_Balance(void)

 {

     W_lega_err = W_leg - W_suma_low;
     Plega_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_leg * W_lega_err;
     Plega_ref_prop = Kp_leg * W_lega_err;
     i_ao_cirDC_ref = ((Plega_ref_integ  + Plega_ref_prop) + P_A_Leg_ff_low + P_Leg_com)/Vdc_rated;
     //i_ao_cirDC_ref = (Plega_ref_integ  + Plega_ref_prop)/Vdc_rated;

     W_legb_err = W_leg - W_sumb_low;
     Plegb_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_leg * W_legb_err;
     Plegb_ref_prop = Kp_leg * W_legb_err;
     i_bo_cirDC_ref = ((Plegb_ref_integ  + Plegb_ref_prop) + P_B_Leg_ff_low + P_Leg_com)/Vdc_rated;
     //i_bo_cirDC_ref = (Plegb_ref_integ  + Plegb_ref_prop)/Vdc_rated;

     W_legc_err = W_leg -W_sumc_low;
     Plegc_ref_integ += OUTERLOOP_SAMPLING_TIME * Ki_leg * W_legc_err;
     Plegc_ref_prop = (Kp_leg * W_legc_err);
     i_co_cirDC_ref = ((Plegc_ref_integ  + Plegc_ref_prop) + P_C_Leg_ff_low + P_Leg_com)/Vdc_rated;

 //i_co_cirDC_ref = (Plegc_ref_integ  + Plegc_ref_prop)/Vdc_rated;
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


 void Diff_Energy_Balance(void)

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

 //차동성분 제어기 수정 18.05.10
     Pdiff_diff_ds_ref = Pdiff_diffa_ref;
     Pdiff_diff_qs_ref = (Pdiff_diffb_ref - Pdiff_diffc_ref) * INV_SQRT3;

     pdiff_multi_a = Pdiff_diff_ds_ref * VM1ds_ref;
     pdiff_multi_b = Pdiff_diff_qs_ref * VM1qs_ref;

     pdiff_multi_c = Pdiff_diff_ds_ref * VM1qs_ref;
     pdiff_multi_d = Pdiff_diff_qs_ref * VM1ds_ref;

     P_diff_ds_old = pdiff_multi_a - pdiff_multi_b;
     P_diff_qs_old = pdiff_multi_c + pdiff_multi_d;

     Vms_mag = sqrt((VM1qe_ref*VM1qe_ref)+(VM1de_ref*VM1de_ref));
     Vms = -(Vms_mag*Vms_mag);

     P_diff_ds = P_diff_ds_old / Vms;
     P_diff_qs = P_diff_qs_old / Vms;

     ia_cirAC_ref_neg = P_diff_ds;
     ib_cirAC_ref_neg = -0.5 * (P_diff_ds - SQRT3 * P_diff_qs);
     ic_cirAC_ref_neg = -0.5 * (P_diff_ds + SQRT3 * P_diff_qs);

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

     ia_cir_err = ia_cir_ref - I_AO  + Idc_sensor_low/3;
     ib_cir_err = ib_cir_ref - I_BO  + Idc_sensor_low/3;
     ic_cir_err = ic_cir_ref - I_CO  + Idc_sensor_low/3;


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

void DSOGI(void)
{
    Erst_ds_err = Erst_ds - Erst_ds_prime;
    Erst_ds_integ_err = K_dsogi * Erst_ds_err - qErst_ds_prime;
    Erst_ds_prime += w_grid * TIMEBASE1_SAMPLING_TIME * Erst_ds_integ_err;
    qErst_ds_prime += w_grid * TIMEBASE1_SAMPLING_TIME * Erst_ds_prime;

    Erst_qs_err = Erst_qs - Erst_qs_prime;
    Erst_qs_integ_err = K_dsogi * Erst_qs_err - qErst_qs_prime;
    Erst_qs_prime += w_grid * TIMEBASE1_SAMPLING_TIME * Erst_qs_integ_err;
    qErst_qs_prime += w_grid * TIMEBASE1_SAMPLING_TIME * Erst_qs_prime;

    Erst_ds_p = 0.5 * (Erst_ds_prime - qErst_qs_prime);
    Erst_qs_p = 0.5 * (Erst_qs_prime + qErst_ds_prime);

//    Erst_ds = Erst_ds_p;
//    Erst_qs = Erst_qs_p;
}



void Starting_sequence(void)
{

    Inv_start = test[0];
    Flag_fault = test[1];
    Vdc_low = test[2];
    Conv_start = test[3];

    switch(Mode_Info.bit.Valve_type)

    {
    case 0x1:
        if (Inv_start ==0 && Flag_fault ==0 && Vdc_low > 1700)
            Inv_start_Req = 1;

        if (Inv_start ==1 && Flag_fault ==0)
        {
            CenLegComm.Slave_OP_Mode.bit.OP_Mode =1;
            Mode_Info.bit.Flag_Controller =0x103;

            Inv_off_cnt = 0;

        }
        else
        {
            if(Inv_off_cnt < INV_OFF_TIME)
            {
                Inv_off_cnt++;
                Mode_Info.bit.Flag_Controller =0;
            }
            else
            {
                Mode_Info.bit.Flag_Main_MC = 0;
                Mode_Info.bit.Flag_Pre_MC = 0;
                CenLegComm.Slave_OP_Mode.bit.OP_Mode =0;

                Fault_register1 = 0;
                Fault_register2 = 0;
                Fault_register3 = 0;
                Fault_register4 = 0;
                Fault_register5 = 0;
                Fault_register6 = 0;
                Fault_register7 = 0;
                Flag_fault = 0;
            }

        }

        break;

    case 0x2:
        if (Conv_start ==1 && Flag_fault ==0)
        {
            if(Pre_MC_count == 0)
                Vdc_initial_status = Vdc_low;
            else
                Vdc_initial_status = Vdc_initial_threshold;

            CenLegComm.Slave_OP_Mode.bit.OP_Mode =1;

            if(Vdc_initial_status <= Vdc_initial_threshold)
            {
                Pre_MC_count += 1;
                if(Pre_MC_count < PRE_MC_OP_TIMER_CNT)
                    Mode_Info.bit.Flag_Pre_MC = 1;
                else
                {
                    Mode_Info.bit.Flag_Pre_MC = 0;
                    Mode_Info.bit.Flag_Main_MC = 1;
                }
            }

            MAIN_MC_OP_Rec_count += 1;

            if(MAIN_MC_OP_Rec_count > MAIN_MC_OP_Rec_TIMER_CNT)
                Mode_Info.bit.Flag_Controller =0x106;

        }
        else
        {
            Mode_Info.bit.Flag_Controller =0;
            Mode_Info.bit.Flag_Main_MC = 0;
            Mode_Info.bit.Flag_Pre_MC = 0;
        }

        break;
    default:
        break;
    }

}
