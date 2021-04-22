// Slave Defin_Basetyes.h

#ifndef DEFINE_BASETYPES_H_
#define DEFINE_BASETYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

// ADC.c
extern int AIN_CH1, AIN_CH2, AIN_CH3, AIN_CH4;
extern int AIN_CH5, AIN_CH6, AIN_CH7, AIN_CH8;
extern int AIN_CH9, AIN_CH10, AIN_CH11, AIN_CH12;
extern int AIN_CH13, AIN_CH14, AIN_CH15, AIN_CH16;
extern int AIN_CH17, AIN_CH18, AIN_CH19, AIN_CH20;
extern int AIN_CH21, AIN_CH22, AIN_CH23, AIN_CH24;
extern int AIN_CH25, AIN_CH26, AIN_CH27, AIN_CH28;
extern int AIN_CH29, AIN_CH30, AIN_CH31, AIN_CH32;
extern int AIN_CH33, AIN_CH34, AIN_CH35, AIN_CH36;
extern int AIN_CH37, AIN_CH38, AIN_CH39, AIN_CH40;
extern int AIN_CH41, AIN_CH42, AIN_CH43, AIN_CH44;


extern float offset_sum;
extern float offset_sum_A, offset_sum_B, offset_sum_C, offset_sum_D;
extern float offset_sum_E, offset_sum_F, offset_sum_G, offset_sum_H;
extern float offset_sum_I, offset_sum_J;

extern int ADC_SEL;

// Interrupt.c
extern Uint16 Flag_Out_Loop;
extern float Vol_SM;
// eQEP.c
extern float theta_e;
extern float rpm_m, rpm_m_low;
extern float Wm_low, We_low;

// Sensor.c
extern float V_H1, V_H2, V_H3, V_H4;
extern float V_L1, V_L2, V_L3, V_L4;
extern float Va_SM_U[4], Va_SM_L[4];
extern float Vb_SM_U[4], Vb_SM_L[4];
extern float Vc_SM_U[4], Vc_SM_L[4];
//extern float offset_sum_au[4], offset_sum_al[4], offset_sum_bu[4], offset_sum_bl[4], offset_sum_cu[4], offset_sum_cl[4];
//extern float Va_SM_U_offset[4], Va_SM_L_offset[4], Vb_SM_U_offset[4], Vb_SM_L_offset[4], Vc_SM_U_offset[4], Vc_SM_L_offset[4];
extern float Va_SM_U_offset0, Va_SM_U_offset1, Va_SM_U_offset2, Va_SM_U_offset3;
extern float Va_SM_L_offset0, Va_SM_L_offset1, Va_SM_L_offset2, Va_SM_L_offset3;
extern float Vb_SM_U_offset0, Vb_SM_U_offset1, Vb_SM_U_offset2, Vb_SM_U_offset3;
extern float Vb_SM_L_offset0, Vb_SM_L_offset1, Vb_SM_L_offset2, Vb_SM_L_offset3;
extern float Vc_SM_U_offset0, Vc_SM_U_offset1, Vc_SM_U_offset2, Vc_SM_U_offset3;
extern float Vc_SM_L_offset0, Vc_SM_L_offset1, Vc_SM_L_offset2, Vc_SM_L_offset3;
//extern float offset_sum_Vdc, offset_sum_Vrs, offset_sum_Vst, offset_sum_Vtr;
extern float Vdc_offset, V_RS_offset, V_ST_offset, V_TR_offset;
extern float V_RS, V_ST, V_TR;
extern float Er, Es, Et;
extern float Vdc_sensor;
extern float I_as, I_bs, I_cs;
extern float Vdc, Vdc_test, Inv_Vdc;
extern float Vdc_low;
extern float I_Upper, I_Lower;
extern float I_Leg;
extern float I_Upper_offset, I_Lower_offset;
extern float V_offset_A, V_offset_B;
extern float I_dc_offset;
extern float I_as_offset;
extern float I_bs_offset;
extern float I_cs;
extern float I_al_offset;
extern float I_au_offset;
extern float I_cs_offset;
extern float I_bu_offset;
extern float I_bl_offset;
extern float I_cu_offset;
extern float I_au;
extern float I_al;
extern float I_bu;
extern float I_bl;
extern float I_cu;
extern float I_cl;
extern float Idc_sensor;
extern float Idc_sensor_low;
extern float I_cl_offset;
extern float I_ao, I_bo, I_co;
extern float Tcl;
extern float I_rs, I_ss, I_ts;
extern float theta_grid;

extern int SM_aU_INDEX_NEW[4];
extern int SM_aL_INDEX_NEW[4];
extern int SM_bU_INDEX_NEW[4];
extern int SM_bL_INDEX_NEW[4];
extern int SM_cU_INDEX_NEW[4];
extern int SM_cL_INDEX_NEW[4];

// LPF_Parameter.c
extern float La_rpm, Lb_rpm;

// M1_Inverter.c

extern Uint16 Flag_MMC;

extern float theta;
extern float theta_M1;
extern float rpm_M1_ref, rpm_M1;
extern float cos_theta_M1, sin_theta_M1;
extern float IM1de_ref, IM1qe_ref;
extern float IM1de, IM1qe;
extern float VM1as_ref, VM1bs_ref, VM1cs_ref;
extern float VM1an_ref, VM1bn_ref, VM1cn_ref, VM1sn_ref;
extern float NM1an_ref, NM1bn_ref, NM1cn_ref;
extern float VM1ds_ref, VM1qs_ref;
extern float VM1de_ref, VM1qe_ref;
extern float VM1ds, VM1qs;
extern float VM1de, VM1qe;
extern float theta_M1_vf;

extern float NM1an_refu, NM1bn_refu, NM1cn_refu;
extern float NM1an_refl, NM1bn_refl, NM1cn_refl;
extern float VM1as_refu, VM1bs_refu, VM1cs_refu;
extern float VM1as_refl, VM1bs_refl, VM1cs_refl;
extern float VM1an_refu, VM1bn_refu, VM1cn_refu;
extern float VM1an_refl, VM1bn_refl, VM1cn_refl;
extern float Vdc, Vdc_test, Inv_Vdc;

extern float Ls_M1, Rs_M1, Ke_M1;

extern float W_total_ref, W_total, iDC_ref;
extern float W_leg, W_suma_low, W_sumb_low, W_sumc_low;
extern float W_diff_com, W_diffa_low, W_diffb_low, W_diffc_low;
extern float Pdiff_theta, theta_phase;
extern float ia_cir_err, ib_cir_err, ic_cir_err;
// eQEP.c
extern float Pole_Pairs;

// Fault.c
extern Uint16 Fault_register1;
extern Uint16 Fault_register2;
extern Uint16 Fault_register3;
extern Uint16 Fault_register4;
extern Uint16 Fault_register5;
extern Uint16 Fault_register6;
extern Uint16 Fault_register7;
extern Uint16 Fault_register8;

extern Uint16 Fault_Init_Flag;
extern Uint16 SM_FaultA_Register;
extern Uint16 SM_FaultB_Register;
extern Uint16 SM_FaultC_Register;

extern float Inv_V_AU, Inv_V_AL, Inv_V_BU, Inv_V_BL, Inv_V_CU, Inv_V_CL;
extern float Vdc_ref;
extern float Va0_ref, Vb0_ref, Vc0_ref;
extern float Er, Es, Et;
extern Uint16 Flag_Indirectmodu;
extern Uint16 Flag_comm_Energy;
extern Uint16 Flag_diff_Energy;
extern Uint16 Flag_Energy_balance;
extern Uint16 Flag_total_Energy;

extern int test_flag;

#ifdef __cplusplus
}
#endif

#endif /* DEFINE_BASETYPES_H_ */
