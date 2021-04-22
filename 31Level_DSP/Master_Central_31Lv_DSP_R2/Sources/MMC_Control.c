/*
 * MMC_Control.c
 *
 *  Created on: 2020. 9. 24.
 *      Author: subi
 */

#include "Define_Header.h"

//Time Base(Controller) Parameter ///////////////////////////////////////////////
ST_TB G1TimeBase = {0U,                                         // {Period, Half-Period, SamplingTime, Sampling Frequency
                    0U,                                         // {Half-Period}
                    200e-6F,                                    // {Sampling Time}
                    5e3F,                                       // {Sampling Frequency}
                    {0U, 20e-3, 5e2F}};                         // {OUTERLOOP.{Period, SamplingTime, SamplingF Frequency}}


// Grid & Power Conversion System Parameter /////////////////////////////////////
ST_SP G1Para = {60.0F,                                          // Fundamental Frequency : {60Hz}
                376.99111843077518861551720599354F,             // Fundamental Angular Frequency : {2*PI*60 rad/s}
                30.0F,                                          // Number of Sub-module in an arm : {30 num}
                3600e-6F,                                       // Capacitance of Sub-module : {3600 uF}
                19e-3F,                                         // Inductance of Arm Inductor : {19 mH}
                1e-3F,                                          // Resistance of Arm Inductor : {1 mOhm}
                0.0F,                                           // Line Inductance : { mH}
                0.0F,                                           // Line Resistance : { mOhm}
                2000.0F,                                        // Rated Vdc : {2000 V}
                0.0005F,                                        // Inverse Vdc : {0.0005}
                0.0F, 0.0F,                                     // 1st Side {Vpp_rms, Vph_rms}
                0.0F, 0.0F,                                     // 1st Side {Vpp_peak, Vph_peak}
                0.0F, 0.0F,                                     // 2nd Side {Vpp_rms, Vph_rms}
                0.0F, 0.0F};                                    // 2nd Side {Vpp_peak, Vph_peak}

// Grid & Power Conversion System Control ///////////////////////////////////////
ST_GCCLC G1CON = {0x00,                                         // MODE(Indirect:1, Direct:1, Converter:1, Inverter:1, SVPWM:1)
                  0x00,                                         // Flag_Indir(VF:1, E_total:1, E_leg:1, E_arm_diff:1, Energy:1, AC_current:1)
                  0x00,                                         // Flag_Dir(VF:1, Vdc:1, CCSC:1, AC_current:1)
                  0x00,                                         // Flag(Switching:1, OM:1, OUTERLOOP:1)
                  {{0.0F},                                      // Reference.Energy.tot
                   {0.0F, 0.0F, 0.0F},                          // Reference.Power.(active, reactive, pf)
                   {0.0F, 0.0F, 0.0F},                          // Reference.Voltage.(dc, vf_dc, vf_e.(d, q))
                   {0.0F, 0.0F}} };                             // Reference.Current.(ac_e.(d,q), cir_e.(d,q))

// Digital Filter ///////////////////////////////////////////////////////////////
Uint8 Df2Vde_Type   = 1U;
float Df2Vde_w0     = 0.0F;
float Df2Vde_Q      = 0.0F;
float Df2Vde_Ts     = 200e-6F;
ST_DF2CLC Df2Vde    = { &Df2Vde_Type,                           // Type(1 : LowPass, 2 : HighPass, 3 : BandPass, 4 : BandStop(Notch) 5 : AllPass)
                        &Df2Vde_w0, &Df2Vde_Q, &Df2Vde_Ts,      // {w0, Q, Ts}
                        {0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},       // S-domain coefficient {sa0, sa1}, {sb0, sb1, sb2}
                        {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, // Z-domain coefficient {za0, sa1, za2}, {zb0, zb1, zb2}
                        {0.0F, 0.0F}};                          // old value {old0, old1}

Uint8 Df2Eleg_Type  = 4U;
float Df2Eleg_w0    = 0.0F;
float Df2Eleg_Q     = 0.0F;
float Df2Eleg_Ts    = 200e-6F;
ST_DF2CLC Df2Eleg_a = { &Df2Eleg_Type,                          // Type(1 : LowPass, 2 : HighPass, 3 : BandPass, 4 : BandStop(Notch) 5 : AllPass)
                        &Df2Eleg_w0, &Df2Eleg_Q, &Df2Eleg_Ts,   // {w0, Q, Ts}
                        {0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},       // S-domain coefficient {sa0, sa1}, {sb0, sb1, sb2}
                        {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, // Z-domain coefficient {za0, sa1, za2}, {zb0, zb1, zb2}
                        {0.0F, 0.0F}};                          // old value {old0, old1}

ST_DF2CLC Df2Eleg_b = { &Df2Eleg_Type,                          // Type(1 : LowPass, 2 : HighPass, 3 : BandPass, 4 : BandStop(Notch) 5 : AllPass)
                        &Df2Eleg_w0, &Df2Eleg_Q, &Df2Eleg_Ts,   // {w0, Q, Ts}
                        {0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},       // S-domain coefficient {sa0, sa1}, {sb0, sb1, sb2}
                        {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, // Z-domain coefficient {za0, sa1, za2}, {zb0, zb1, zb2}
                        {0.0F, 0.0F}};                          // old value {old0, old1}

ST_DF2CLC Df2Eleg_c = { &Df2Eleg_Type,                          // Type(1 : LowPass, 2 : HighPass, 3 : BandPass, 4 : BandStop(Notch) 5 : AllPass)
                        &Df2Eleg_w0, &Df2Eleg_Q, &Df2Eleg_Ts,   // {w0, Q, Ts}
                        {0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},       // S-domain coefficient {sa0, sa1}, {sb0, sb1, sb2}
                        {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, // Z-domain coefficient {za0, sa1, za2}, {zb0, zb1, zb2}
                        {0.0F, 0.0F}};                          // old value {old0, old1}

Uint8 Df2Plff_Type  = 4U;
float Df2Plff_w0    = 0.0F;
float Df2Plff_Q     = 0.0F;
float Df2Plff_Ts    = 200e-6F;
ST_DF2CLC Df2Plff_a = { &Df2Plff_Type,                          // Type(1 : LowPass, 2 : HighPass, 3 : BandPass, 4 : BandStop(Notch) 5 : AllPass)
                        &Df2Plff_w0, &Df2Plff_Q, &Df2Plff_Ts,   // {w0, Q, Ts}
                        {0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},       // S-domain coefficient {sa0, sa1}, {sb0, sb1, sb2}
                        {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, // Z-domain coefficient {za0, sa1, za2}, {zb0, zb1, zb2}
                        {0.0F, 0.0F}};                          // old value {old0, old1}

ST_DF2CLC Df2Plff_b = { &Df2Plff_Type,                          // Type(1 : LowPass, 2 : HighPass, 3 : BandPass, 4 : BandStop(Notch) 5 : AllPass)
                        &Df2Plff_w0, &Df2Plff_Q, &Df2Plff_Ts,   // {w0, Q, Ts}
                        {0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},       // S-domain coefficient {sa0, sa1}, {sb0, sb1, sb2}
                        {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, // Z-domain coefficient {za0, sa1, za2}, {zb0, zb1, zb2}
                        {0.0F, 0.0F}};                          // old value {old0, old1}

ST_DF2CLC Df2Plff_c = { &Df2Plff_Type,                          // Type(1 : LowPass, 2 : HighPass, 3 : BandPass, 4 : BandStop(Notch) 5 : AllPass)
                        &Df2Plff_w0, &Df2Plff_Q, &Df2Plff_Ts,   // {w0, Q, Ts}
                        {0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},       // S-domain coefficient {sa0, sa1}, {sb0, sb1, sb2}
                        {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, // Z-domain coefficient {za0, sa1, za2}, {zb0, zb1, zb2}
                        {0.0F, 0.0F}};                          // old value {old0, old1}

ST_DFCLC G1DF = {&Df2Vde,
                 &Df2Eleg_a, &Df2Eleg_b, &Df2Eleg_c,
                 &Df2Plff_a, &Df2Plff_b, &Df2Plff_c};

// Controller Gain //////////////////////////////////////////////////////////////
float   G1Sogi_k    = 1.4142135623730950488016887242097F;       // Sogi Gains : {Kd}
ST_PI   G1Pll_k     = {0.0F, 0.0F};                             // PLL Gains : {Kp, Ki}
ST_PIA  G1Iac_k     = {0.0F, 0.0F, 0.0F};                       // AC Current Gains : {Kp, Ki, Ka}
ST_PI   G1Idc_k     = {0.0F, 0.0F};                             // DC Current Gains : {Kp, Ki}
ST_PIR  G1Icir_k    = {0.0F, 0.0F, 0.0F};                       // Circulating Current Gains(Indirect) : {Kp, Ki, Kr}
ST_PI   G1Etot_k    = {0.0F, 0.0F};                             // Total Energy Balance Controller Gains : {Kp, Ki}
ST_PI   G1Eleg_k    = {0.0F, 0.0F};                             // Leg Energy Balance Controller Gains : {Kp, Ki}
ST_PI   G1Eacom_k   = {0.0F, 0.0F};                             // Arm Energy Diff-Com Balance Controller Gains : {Kp, Ki}
ST_PI   G1Eadiff_k  = {0.0F, 0.0F};                             // Arm Energy Diff-Diff Balance Controller Gains : {Kp, Ki}
ST_PIA  G1Vdc_k     = {0.0F, 0.0F};                             // Vdc Controller Gatins : {Kp, Ki}
ST_PI   G1Iccsc_k   = {0.0F, 0.0F};                             // CCSC Controller Gatins : {Kp, Ki}

ST_GCLC G1Gain = {&G1Sogi_k, &G1Pll_k, &G1Iac_k, &G1Idc_k,
                  &G1Icir_k, &G1Etot_k, &G1Eleg_k, &G1Eacom_k,
                  &G1Eadiff_k, &G1Vdc_k, &G1Iccsc_k};

// Theta ////////////////////////////////////////////////////////////////////////
ST_SOGI G1Sogi_d = {0.0F, 0.0F, 0.0F, 0.0F};                    // Sogi d-axis {v_err_prop, v_err_integ, v_prime, qv_prime}
ST_SOGI G1Sogi_q = {0.0F, 0.0F, 0.0F, 0.0F};                    // Sogi q-axis {v_err_prop, v_err_integ, v_prime, qv_prime}
ST_PLL  G1PLL = {0.0F,                                          // PLL.{e_err,
                 0.0F, 0.0F, 0.0F,                              // w_ref_integ, w_ref_prop, w_ref,
                 0.0F, 0.0F, 0.0F,                              // theta, sint, cost,
                 0.0F, 0.0F, 0.0F,                              // theta_2nd, sint_2nd, cost_2nd,
                 0.0F, 0.0F, 0.0F, 0.0F};                       // freq_vf, theta_vf, sint_vf, cost_vf}

ST_TCLC G1Theta = {&G1Sogi_d, &G1Sogi_q, &G1PLL};

// Energy ///////////////////////////////////////////////////////////////////////
ST_ARM G1Earm        = {{0.0F, 0.0F},{0.0F, 0.0F},{0.0F, 0.0F}};// MMC Arm Energy {{Eau, Eal}, {Ebu, Ebl}, {Ecu, Ecl}}
float G1Etot         = 0.0F;                                    // MMC Arm Total Energy  {Etot_a, Etot_b, Etot_c}
ST_PH G1Eleg         = {0.0F,0.0F,0.0F};                        // MMC Arm Energy Sum(Leg energy) {Eleg_a, Eleg_b, Eleg_c}
ST_PH G1Ediff        = {0.0F,0.0F,0.0F};                        // MMC Arm Energy Difference {Ediff_a, Ediff_b, Ediff_c}
float G1Ecom         = 0.0F;                                    // Arm Energy Difference Common
ST_PH G1Eleg_flt     = {0.0F,0.0F,0.0F};                        // Filtered Arm Energy Sum(Leg Energy)
ST_PH G1Ediff_flt    = {0.0F,0.0F,0.0F};                        // Filtered Arm Energy Difference

float G1E_total_ref = 0.0F;                                     // Total Energy Controller Reference
float G1Eleg_ref = 0.0F;                                        // Leg Energy Controller Reference
float G1Eadiff_ref = 0.0F;                                      // Arm Energy Difference Difference Controller
float G1Eacom_ref = 0.0F;                                       // Arm Energy Difference Common Controller

float G1Etot_err = 0.0F;                                        // Total Energy Error
ST_PH G1Eleg_p_err = {0.0F,0.0F,0.0F};                          // Leg Energy Error
float G1Eacom_n_err = 0.0F;                                     // Arm Energy Difference Common Error
ST_PH G1Eadiff_p_err = {0.0F,0.0F,0.0F};                        // Arm Energy Difference Difference Error

ST_ECLC G1E = {&G1Earm, &G1Etot, &G1Eleg, &G1Ediff, &G1Ecom,
               &G1Eleg_flt, &G1Ediff_flt,
               &G1E_total_ref, &G1Eleg_ref, &G1Eadiff_ref, &G1Eacom_ref,
               &G1Etot_err, &G1Eleg_p_err, &G1Eacom_n_err, &G1Eadiff_p_err};

// Power ///////////////////////////////////////////////////////////////////////
float G1Ptot_conv_ff    = 0.0F;                                 // Total Energy Controller Feed Forward
float G1Ptot_inv_ff     = 0.0F;                                 // Total Energy Controller Feed Forward
ST_PH G1Pleg_ff         = {0.0F,0.0F,0.0F};                     // Leg Energy Controller Feed Forward
float G1Pleg_avg_ff     = 0.0F;                                 // Leg Energy Average Feed Forward

ST_DQ G1PAdiff_s_ref    = {0.0F, 0.0F};                         // Reference Sum dqs

ST_FPICON   G1P_Tot     = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F};     // Total Energy Controller
ST_PHPICON  G1P_Leg     = {{0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},  // Leg(Arm Sum) Energy Controller
                           {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},
                           {0.0F, 0.0F, 0.0F}};
ST_FPICON   G1P_Acom    = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F};     // Arm Energy Difference Common  Controller
ST_PHPICON  G1P_Adiff   = {{0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},  // Arm Energy Difference Difference Controller
                           {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},
                           {0.0F, 0.0F, 0.0F}};

ST_PCLC G1P = {&G1Ptot_conv_ff, &G1Ptot_inv_ff, &G1Pleg_ff, &G1Pleg_avg_ff,
               &G1PAdiff_s_ref,
               &G1P_Tot, &G1P_Leg, &G1P_Acom, &G1P_Adiff};

// Voltage //////////////////////////////////////////////////////////////////////
ST_PP G1V1pp         = {0.0F, 0.0F, 0.0F};                      // Transformer 1-st side Phase-phase Voltage {ab, bc, ca}
ST_PH G1V1ph         = {0.0F, 0.0F, 0.0F};                      // Transformer 1-st Side Phase Voltage{a, b, c}
ST_DQ G1V1ph_dqs     = {0.0F, 0.0F};                            // Transformer 1-st Side dqs Voltage {ds, qs}
ST_DQ G1V1ph_dqe     = {0.0F, 0.0F};                            // Transformer 1-st Side dqe Voltage {de, qe}
ST_PP G1V2pp         = {0.0F, 0.0F, 0.0F};                      // Transformer 2-nd Side Positive Phase-phase Voltage {a, b, c}
ST_PH G1V2ph         = {0.0F, 0.0F, 0.0F};                      // Transformer 2-nd Side Phase Voltage{a, b, c}
ST_DQ G1V2ph_dqs     = {0.0F, 0.0F};                            // Transformer 2-nd Side dqs Voltage {ds, qs}
ST_DQ G1V2ph_dqe     = {0.0F, 0.0F};                            // Transformer 2-nd Side dqe Voltage {de, qe}
ST_PH G1V2ph_p       = {0.0F, 0.0F, 0.0F};                      // Transformer 2-nd Side Positive Phase Voltage{a, b, c}
ST_DQ G1V2ph_dqs_p   = {0.0F, 0.0F};                            // Transformer 2-nd Side Positive dqs Voltage {ds, qs}
ST_DQ G1V2ph_dqe_p   = {0.0F, 0.0F};                            // Transformer 2-nd Side Positive dqe Voltage {de, qe}
ST_DQ G1Vph_dqe_p_flt= {0.0F, 0.0F};                            // Transformer 2-nd side Positive Filtered dqe voltage
float G1Vdc          = 0.0F;                                    // Vdc
ST_ARMGRP G1Vgrp_sm  = {{{0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F},   // 3-Phase Upper & Lower Group Submodule
                        {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}},
                        {{0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F},
                        {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}},
                        {{0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F},
                        {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}}};
ST_ARM G1Vsm_sum     = {{0.0F, 0.0F},{0.0F, 0.0F},{0.0F, 0.0F}};// 3-Phase Upper & Lower Sum of Submodule Voltage

float G1Ve_invsq     = 0.0F;                                    // dqe Inverse Square

ST_ARM G1Varm_ref    = {{0.0F, 0.0F},{0.0F, 0.0F},{0.0F, 0.0F}};    // 3-Phase Upper & Lower Arm Reference Voltage
ST_ARM G1Varm_norm_ref = {{0.0F, 0.0F},{0.0F, 0.0F},{0.0F, 0.0F}};  // 3-Phase Upper & Lower Arm Reference Voltage
ST_ARM G1Varm_num_ref= {{0.0F, 0.0F},{0.0F, 0.0F},{0.0F, 0.0F}};    // 3-Phase Upper & Lower Arm Reference Voltage
float G1Vdc_ref      = 0.0F;                                    // Vdc Reference
ST_PH G1Vp_ref       = {0.0F, 0.0F, 0.0F};                      // Phase Voltage Reference
ST_PO G1Vn_ref       = {0.0F, 0.0F, 0.0F};                      // Pole Voltage Reference
ST_DQ G1Vs_ref       = {0.0F, 0.0F};                            // dqs Voltage Reference
ST_DQ G1Ve_ref       = {0.0F, 0.0F};                            // dqe Voltage Reference
ST_DQ G1Vs_anti_ref  = {0.0F, 0.0F};                            // dqs Anti Windup Voltage Reference
ST_DQ G1Ve_anti_ref  = {0.0F, 0.0F};                            // dqe Anti Windup Voltage Reference
ST_PH G1Vcir_ref     = {0.0F, 0.0F, 0.0F};                      // Leg Internal Voltage
ST_DQ G1Vcir_s_ref   = {0.0F, 0.0F};                            // dqs Leg Internal Voltage
ST_DQ G1Vcir_e_ref   = {0.0F, 0.0F};                            // dqe Leg Internal Voltage

float G1Vdc_err      = 0.0F;                                    // DC Voltage err

ST_DQPICON  G1V_AC   = {{0.0F, 0.0F}, {0.0F, 0.0F},             // AC Current Controller
                        {0.0F, 0.0F}, {0.0F, 0.0F},
                        {0.0F, 0.0F}, {0.0F, 0.0F}};
ST_FPICON   G1V_DC   = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F};    // DC Current Controller
ST_PHPIRCON G1V_CIR  = {{0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, // Circulating Current Controller(Indirect)
                        {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},
                        {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},
                        {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},
                        {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}};
ST_DQPICON  G1V_CCSC = {{0.0F, 0.0F}, {0.0F, 0.0F},              // Circulating Current Suppressing Controller(Direct)
                        {0.0F, 0.0F}, {0.0F, 0.0F},
                        {0.0F, 0.0F}, {0.0F, 0.0F}};


ST_VCLC G1V = {&G1V1pp, &G1V1ph, &G1V1ph_dqs, &G1V1ph_dqe,
               &G1V2pp, &G1V2ph, &G1V2ph_dqs, &G1V2ph_dqe,
               &G1V2ph_p, &G1V2ph_dqs_p, &G1V2ph_dqe_p, &G1Vph_dqe_p_flt,
               &G1Vdc,
               &G1Vgrp_sm,
               &G1Vsm_sum,
               &G1Ve_invsq,
               &G1Varm_ref, &G1Varm_norm_ref, &G1Varm_num_ref,
               &G1Vdc_ref, &G1Vp_ref, &G1Vn_ref, &G1Vs_ref, &G1Ve_ref,
               &G1Vs_anti_ref, &G1Ve_anti_ref, &G1Vcir_ref, &G1Vcir_s_ref, &G1Vcir_e_ref,
               &G1Vdc_err,
               &G1V_AC, &G1V_DC, &G1V_CIR, &G1V_CCSC};

// Current //////////////////////////////////////////////////////////////////////
ST_PH G1I2ph         = {0.0F, 0.0F, 0.0F};                      // Transformer 2-nd Side Phase Current {a, b, c}
ST_DQ G1I2ph_dqs     = {0.0F, 0.0F};                            // Transformer 2-nd Side dqs Current {ds, qs}
ST_DQ G1I2ph_dqe     = {0.0F, 0.0F};                            // Transformer 2-nd Side dqe Current {de, qe}
ST_DQ G1I2ph_dqs_p   = {0.0F, 0.0F};                            // Transformer 2-nd Side Positive dqs Current {ds, qs}
ST_DQ G1I2ph_dqe_p   = {0.0F, 0.0F};                            // Transformer 2-nd Side Positive dqe Current {de, qe}
ST_PH G1Icir         = {0.0F, 0.0F, 0.0F};                      // Circulating Current in Indirect Modulation or Leg Current in Direct Modulation {a, b, c}
ST_DQ G1I2cir_dqs_p  = {0.0F, 0.0F};                            // Transformer 2-nd Side Positive dqs Current {ds, qs}
ST_DQ G1I2cir_dqe_p  = {0.0F, 0.0F};                            // Transformer 2-nd Side Positive dqe Current {de, qe}
float G1Idc          = 0.0F;                                    // DC Current

float G1I_qe_limit;                                             // q-axit Current limit(for Vdc Controller)

float G1Idc_ref         = 0.0F;                                 // DC Current Reference
ST_DQ G1Iac_e_ref       = {0.0F, 0.0F};                                              // AC Current Reference
ST_PH G1Icir_dc_ref     = {0.0F, 0.0F, 0.0F};                                            // DC Circulating Current Reference
ST_PH G1Icir_ac_p_ref   = {0.0F, 0.0F, 0.0F};                                          // Positive AC Circulating Current Reference
ST_PH G1Icir_ac_n_ref   = {0.0F, 0.0F, 0.0F};                   // Negative AC Circulating Current Reference
ST_DQ G1Icir_ac_n_s_ref = {0.0F, 0.0F};                         // Negative dqs AC Circulating Current Reference
ST_DQ G1Icir_e_ref      = {0.0F, 0.0F};                         // dqe Circulating Current Reference
ST_PH G1Icir_ref        = {0.0F, 0.0F, 0.0F};                   // Circulating Current Reference

ST_DQ G1Iac_e_err    = {0.0F, 0.0F};                            // AC Current Error
float G1Idc_err      = 0.0F;                                    // DC Current Error
ST_PH G1Icir_err     = {0.0F, 0.0F, 0.0F};                      // Circulating Current Error(Energy Controller)
ST_DQ G1Icir_e_err   = {0.0F, 0.0F};                            // Circulating Current dqe Error(CCSC)

ST_FPICON G1I_Vdc    = {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F};    // Vdc Controller(Direct)

ST_CCLC G1I = {&G1I2ph, &G1I2ph_dqs, &G1I2ph_dqe,
               &G1I2ph_dqs_p, &G1I2ph_dqe_p,
               &G1Icir, &G1I2cir_dqs_p, &G1I2cir_dqe_p,
               &G1Idc,
               &G1I_qe_limit,
               &G1Idc_ref, &G1Iac_e_ref, &G1Icir_dc_ref,
               &G1Icir_ac_p_ref, &G1Icir_ac_n_ref, &G1Icir_ac_n_s_ref,
               &G1Icir_e_ref, &G1Icir_ref,
               &G1Iac_e_err, &G1Idc_err, &G1Icir_err, &G1Icir_e_err,
               &G1I_Vdc};

//Grid-1 Control Variable Collection
ST_GXCLC G1 = {&G1TimeBase, &G1Para, &G1CON, &G1DF, &G1Gain,
               &G1Theta, &G1E, &G1P, &G1V, &G1I};


#define CONVERTER_INDIRECT_MODE          0x0005
#define CONVERTER_DIRECT_MODE            0x0006
#define INVERTER_INDIRECT_MODE           0x0009
#define INVERTER_DIRECT_MODE             0x000A

void GxControl(ST_GXCLC *Gx)
{
    static Uint16 Mode_Sel = 0;

    //if(Flag_fault > 0) Mode_Info.all = 0;         //Move this to Fault code

    Mode_Sel = Gx->CON->MODE.all & 0x000F;
    switch(Mode_Sel)
    {
        case CONVERTER_INDIRECT_MODE :   Converter_Indirect(Gx);   break;
        case CONVERTER_DIRECT_MODE   :   Converter_Direct(Gx);     break;
        case INVERTER_INDIRECT_MODE  :   Inverter_Indirect(Gx);    break;
        case INVERTER_DIRECT_MODE    :   Inverter_Direct(Gx);      break;
        default : break;
    }

    return;
}

void Converter_Indirect(ST_GXCLC *Gx)
{
    static Uint16 Mode_Sel = 0;

    Mode_Sel = (Gx->CON->Flag.bit.Switching << 15) | (Gx->CON->Flag_Indir.all & 0x007F);
    switch(Mode_Sel)
    {
    default : break;
    }

    return;
}

void Converter_Direct(ST_GXCLC *Gx)
{
    return;
}

void Inverter_Indirect(ST_GXCLC *Gx)
{
    return;
}

void Inverter_Direct(ST_GXCLC *Gx)
{
    return;
}

void NLC(ST_GXCLC *Gx)
{
    static float Vnorm_ref_au = 0.0F,  Vnorm_ref_al = 0.0F;
    static float Vnorm_ref_bu = 0.0F,  Vnorm_ref_bl = 0.0F;
    static float Vnorm_ref_cu = 0.0F,  Vnorm_ref_cl = 0.0F;

    Vnorm_ref_au = Gx->V->arm_norm_ref->a.u;
    Vnorm_ref_al = Gx->V->arm_norm_ref->a.l;
    Vnorm_ref_bu = Gx->V->arm_norm_ref->b.u;
    Vnorm_ref_bl = Gx->V->arm_norm_ref->b.l;
    Vnorm_ref_cu = Gx->V->arm_norm_ref->c.u;
    Vnorm_ref_cl = Gx->V->arm_norm_ref->c.l;

    if(Vnorm_ref_au - floor(Vnorm_ref_au) >=0.5F)
        Gx->V->arm_num_ref->a.u = ceil(Vnorm_ref_au);
    else
        Gx->V->arm_num_ref->a.u = floor(Vnorm_ref_au);

    if(Vnorm_ref_al - floor(Vnorm_ref_al) >=0.5F)
        Gx->V->arm_num_ref->a.l = ceil(Vnorm_ref_al);
    else
        Gx->V->arm_num_ref->a.l = floor(Vnorm_ref_al);

    if(Vnorm_ref_bu - floor(Vnorm_ref_bu) >=0.5F)
        Gx->V->arm_num_ref->b.u = ceil(Vnorm_ref_bu);
    else
        Gx->V->arm_num_ref->b.u = floor(Vnorm_ref_bu);

    if(Vnorm_ref_bl - floor(Vnorm_ref_bl) >=0.5F)
        Gx->V->arm_num_ref->b.l = ceil(Vnorm_ref_bl);
    else
        Gx->V->arm_num_ref->b.l = floor(Vnorm_ref_bl);

    if(Vnorm_ref_cu - floor(Vnorm_ref_cu) >=0.5F)
        Gx->V->arm_num_ref->c.u = ceil(Vnorm_ref_cu);
    else
        Gx->V->arm_num_ref->c.u = floor(Vnorm_ref_cu);

    if(Vnorm_ref_cl - floor(Vnorm_ref_cl) >=0.5F)
        Gx->V->arm_num_ref->c.l = ceil(Vnorm_ref_cl);
    else
        Gx->V->arm_num_ref->c.l = floor(Vnorm_ref_cl);

    return;
}

#define INDIRECT_MODULATION                 0x1U
#define DIRECT_MODULATION                   0x2U
#define CONVERTER_OPERATION                 0x4U
#define INVETER_OPERATION                   0x8U

void DIR_REF_GENEATOR(ST_GXCLC *Gx)
{
    static float Vdc_ref = 0.0F;
    static float Num_SM = 0.0F;
    static float Inv_Vdc_rated = 0.0F;

    Vdc_ref = *(Gx->V->dc_ref);
    Num_SM = Gx->SP->NumSM;
    Inv_Vdc_rated = Gx->SP->Inv_Vdc;

    Gx->V->arm_ref->a.u = Vdc_ref*0.5F - Gx->V->n_ref->a - Gx->V->cir_ref->a;
    Gx->V->arm_ref->a.l = Vdc_ref*0.5F + Gx->V->n_ref->a - Gx->V->cir_ref->a;

    Gx->V->arm_ref->b.u = Vdc_ref*0.5F - Gx->V->n_ref->b - Gx->V->cir_ref->b;
    Gx->V->arm_ref->b.l = Vdc_ref*0.5F + Gx->V->n_ref->b - Gx->V->cir_ref->b;

    Gx->V->arm_ref->b.u = Vdc_ref*0.5F - Gx->V->n_ref->c - Gx->V->cir_ref->c;
    Gx->V->arm_ref->b.l = Vdc_ref*0.5F + Gx->V->n_ref->c - Gx->V->cir_ref->c;

    Gx->V->arm_norm_ref->a.u = Gx->V->arm_ref->a.u*Inv_Vdc_rated*Num_SM;
    Gx->V->arm_norm_ref->a.l = Gx->V->arm_ref->a.l*Inv_Vdc_rated*Num_SM;

    Gx->V->arm_norm_ref->b.u = Gx->V->arm_ref->b.u*Inv_Vdc_rated*Num_SM;
    Gx->V->arm_norm_ref->b.l = Gx->V->arm_ref->b.l*Inv_Vdc_rated*Num_SM;

    Gx->V->arm_norm_ref->c.u = Gx->V->arm_ref->c.u*Inv_Vdc_rated*Num_SM;
    Gx->V->arm_norm_ref->c.l = Gx->V->arm_ref->c.l*Inv_Vdc_rated*Num_SM;

    return;
}

void INDIR_REF_GENEATOR(ST_GXCLC *Gx)
{
    static float Vdc_ref = 0.0F;
    static float Num_SM = 0.0F;

    Vdc_ref = *(Gx->V->dc_ref);
    Num_SM = Gx->SP->NumSM;

    Gx->V->arm_ref->a.u = Vdc_ref*0.5F - Gx->V->n_ref->a - Gx->V->cir_ref->a;
    Gx->V->arm_ref->a.l = Vdc_ref*0.5F + Gx->V->n_ref->a - Gx->V->cir_ref->a;

    Gx->V->arm_ref->b.u = Vdc_ref*0.5F - Gx->V->n_ref->b - Gx->V->cir_ref->b;
    Gx->V->arm_ref->b.l = Vdc_ref*0.5F + Gx->V->n_ref->b - Gx->V->cir_ref->b;

    Gx->V->arm_ref->b.u = Vdc_ref*0.5F - Gx->V->n_ref->c - Gx->V->cir_ref->c;
    Gx->V->arm_ref->b.l = Vdc_ref*0.5F + Gx->V->n_ref->c - Gx->V->cir_ref->c;

    Gx->V->arm_norm_ref->a.u = Gx->V->arm_ref->a.u/Gx->V->sm_sum->a.u*Num_SM;
    Gx->V->arm_norm_ref->a.l = Gx->V->arm_ref->a.l/Gx->V->sm_sum->a.l*Num_SM;

    Gx->V->arm_norm_ref->b.u = Gx->V->arm_ref->b.u/Gx->V->sm_sum->b.u*Num_SM;
    Gx->V->arm_norm_ref->b.l = Gx->V->arm_ref->b.l/Gx->V->sm_sum->b.l*Num_SM;

    Gx->V->arm_norm_ref->c.u = Gx->V->arm_ref->c.u/Gx->V->sm_sum->c.u*Num_SM;
    Gx->V->arm_norm_ref->c.l = Gx->V->arm_ref->c.l/Gx->V->sm_sum->c.l*Num_SM;

    return;
}

void RESET_GxCon(ST_GXCLC *Gx)
{
    //Filter
    DF2O_INIT(Gx->DF->pll);
    DF2O_INIT(Gx->DF->diff_a);
    DF2O_INIT(Gx->DF->diff_b);
    DF2O_INIT(Gx->DF->diff_c);
    DF2O_INIT(Gx->DF->leg_a);
    DF2O_INIT(Gx->DF->leg_b);
    DF2O_INIT(Gx->DF->leg_c);

    // Controller Component ////////////////////////////////////////
    // Total Energy Controller
    Gx->P->Tot->ref = 0.0F;
    Gx->P->Tot->ref_anti = 0.0F;
    Gx->P->Tot->ref_fb = 0.0F;
    Gx->P->Tot->ref_ff = 0.0F;
    Gx->P->Tot->ref_integ = 0.0F;
    Gx->P->Tot->ref_prop = 0.0F;

    // Leg Energy Controller
    Gx->P->Leg->p_ref.a = 0.0F;
    Gx->P->Leg->p_ref.b = 0.0F;
    Gx->P->Leg->p_ref.c = 0.0F;
    Gx->P->Leg->p_ref_fb.a = 0.0F;
    Gx->P->Leg->p_ref_fb.b = 0.0F;
    Gx->P->Leg->p_ref_fb.c = 0.0F;
    Gx->P->Leg->p_ref_ff.a = 0.0F;
    Gx->P->Leg->p_ref_ff.b = 0.0F;
    Gx->P->Leg->p_ref_ff.c = 0.0F;
    Gx->P->Leg->p_ref_integ.a = 0.0F;
    Gx->P->Leg->p_ref_integ.b = 0.0F;
    Gx->P->Leg->p_ref_integ.c = 0.0F;
    Gx->P->Leg->p_ref_prop.a = 0.0F;
    Gx->P->Leg->p_ref_prop.b = 0.0F;
    Gx->P->Leg->p_ref_prop.c = 0.0F;

    // Am Energy Difference Common Controller
    Gx->P->Acom->ref = 0.0F;
    Gx->P->Acom->ref = 0.0F;
    Gx->P->Acom->ref = 0.0F;
    Gx->P->Acom->ref_anti = 0.0F;
    Gx->P->Acom->ref_fb = 0.0F;
    Gx->P->Acom->ref_ff = 0.0F;
    Gx->P->Acom->ref_integ = 0.0F;
    Gx->P->Acom->ref_prop = 0.0F;

    // Arm Energy Difference Difference Controller
    Gx->P->Adiff->p_ref.a = 0.0F;
    Gx->P->Adiff->p_ref.b = 0.0F;
    Gx->P->Adiff->p_ref.c = 0.0F;
    Gx->P->Adiff->p_ref_fb.a = 0.0F;
    Gx->P->Adiff->p_ref_fb.b = 0.0F;
    Gx->P->Adiff->p_ref_fb.c = 0.0F;
    Gx->P->Adiff->p_ref_ff.a = 0.0F;
    Gx->P->Adiff->p_ref_ff.b = 0.0F;
    Gx->P->Adiff->p_ref_ff.c = 0.0F;
    Gx->P->Adiff->p_ref_integ.a = 0.0F;
    Gx->P->Adiff->p_ref_integ.b = 0.0F;
    Gx->P->Adiff->p_ref_integ.c = 0.0F;
    Gx->P->Adiff->p_ref_prop.a = 0.0F;
    Gx->P->Adiff->p_ref_prop.b = 0.0F;
    Gx->P->Adiff->p_ref_prop.c = 0.0F;

    // AC Current Controller
    Gx->V->AC->e_ref.d = 0.0F;
    Gx->V->AC->e_ref.q = 0.0F;
    Gx->V->AC->e_ref_anti.d = 0.0F;
    Gx->V->AC->e_ref_anti.q = 0.0F;
    Gx->V->AC->e_ref_fb.d = 0.0F;
    Gx->V->AC->e_ref_fb.q = 0.0F;
    Gx->V->AC->e_ref_ff.d = 0.0F;
    Gx->V->AC->e_ref_ff.q = 0.0F;
    Gx->V->AC->e_ref_integ.d = 0.0F;
    Gx->V->AC->e_ref_integ.q = 0.0F;
    Gx->V->AC->e_ref_prop.d = 0.0F;
    Gx->V->AC->e_ref_prop.q = 0.0F;

    // DC Current Controller
    Gx->V->DC->ref = 0.0F;
    Gx->V->DC->ref_anti =0.0F;
    Gx->V->DC->ref_fb = 0.0F;
    Gx->V->DC->ref_ff = 0.0F;
    Gx->V->DC->ref_integ = 0.0F;
    Gx->V->DC->ref_prop = 0.0F;

    // Circulating Current Controller(Indirect)
    Gx->V->CIR->p_ref.a = 0.0F;
    Gx->V->CIR->p_ref.b = 0.0F;
    Gx->V->CIR->p_ref.c = 0.0F;
    Gx->V->CIR->p_ref_fb.a = 0.0F;
    Gx->V->CIR->p_ref_fb.b = 0.0F;
    Gx->V->CIR->p_ref_fb.c = 0.0F;
    Gx->V->CIR->p_ref_ff.a = 0.0F;
    Gx->V->CIR->p_ref_ff.b = 0.0F;
    Gx->V->CIR->p_ref_ff.c = 0.0F;
    Gx->V->CIR->p_ref_integ.a = 0.0F;
    Gx->V->CIR->p_ref_integ.b = 0.0F;
    Gx->V->CIR->p_ref_integ.c = 0.0F;
    Gx->V->CIR->p_ref_prop.a = 0.0F;
    Gx->V->CIR->p_ref_prop.b = 0.0F;
    Gx->V->CIR->p_ref_prop.c = 0.0F;
    Gx->V->CIR->p_ref_r_o_old.a = 0.0F;
    Gx->V->CIR->p_ref_r_o_old.b = 0.0F;
    Gx->V->CIR->p_ref_r_o_old.c = 0.0F;
    Gx->V->CIR->p_ref_r_old.a = 0.0F;
    Gx->V->CIR->p_ref_r_old.b = 0.0F;
    Gx->V->CIR->p_ref_r_old.c = 0.0F;
    Gx->V->CIR->p_ref_resnt.a = 0.0F;
    Gx->V->CIR->p_ref_resnt.b = 0.0F;
    Gx->V->CIR->p_ref_resnt.c = 0.0F;

    // Circulating Current Suppressing Controller(Direct)
    Gx->V->CCSC->e_ref.d = 0.0F;
    Gx->V->CCSC->e_ref.q = 0.0F;
    Gx->V->CCSC->e_ref_anti.d = 0.0F;
    Gx->V->CCSC->e_ref_anti.q = 0.0F;
    Gx->V->CCSC->e_ref_fb.d = 0.0F;
    Gx->V->CCSC->e_ref_fb.q = 0.0F;
    Gx->V->CCSC->e_ref_ff.d = 0.0F;
    Gx->V->CCSC->e_ref_ff.q = 0.0F;
    Gx->V->CCSC->e_ref_integ.d = 0.0F;
    Gx->V->CCSC->e_ref_integ.q = 0.0F;
    Gx->V->CCSC->e_ref_prop.d = 0.0F;
    Gx->V->CCSC->e_ref_prop.q = 0.0F;

    // Vdc Controller(Direct)
    Gx->I->Vdc->ref = 0.0F;
    Gx->I->Vdc->ref_anti = 0.0F;
    Gx->I->Vdc->ref_fb = 0.0F;
    Gx->I->Vdc->ref_ff = 0.0F;
    Gx->I->Vdc->ref_integ = Gx->K->vdc->p*(*Gx->V->dc);
    Gx->I->Vdc->ref_prop = 0.0F;

    return;
}

void SVPWM(ST_GXCLC *Gx)
{
    float MaxVref, MinVref;
    float MaxMinDiff;
    float OM;

    // Sorting Vp_ref
    if(Gx->V->p_ref->a >= Gx->V->p_ref->b)
    {
        MaxVref = Gx->V->p_ref->a;
        MinVref = Gx->V->p_ref->b;
    }
    else
    {
        MaxVref = Gx->V->p_ref->a;
        MinVref = Gx->V->p_ref->b;
    }

    if(Gx->V->p_ref->c > MaxVref)
        MaxVref = Gx->V->p_ref->c;

    if(Gx->V->p_ref->c < MinVref)
        MinVref = Gx->V->p_ref->c;

    // Offset Voltages
    Gx->V->n_ref->s = -0.5F*(MaxVref + MinVref);

    // Over Modulation
    MaxMinDiff = MaxVref - MinVref;
    if(MaxMinDiff > Gx->SP->Vdc_rated)
    {
        Gx->CON->Flag.bit.OM = 1U;

        OM = Gx->SP->Vdc_rated/MaxMinDiff;

        Gx->V->p_ref->a *= OM;
        Gx->V->p_ref->b *= OM;
        Gx->V->p_ref->c *= OM;
        Gx->V->n_ref->s *= OM;

        FPabc2dqe(Gx->V->p_ref, Gx->V->s_ref, Gx->V->e_ref, &Gx->T->Pll->cost, &Gx->T->Pll->sint);
    }
    else
    {
        Gx->CON->Flag.bit.OM = 0U;

        OM = 0.0F;

        Gx->V->e_ref->d = Gx->V->AC->e_ref.d;
        Gx->V->e_ref->q = Gx->V->AC->e_ref.q;
    }

    if(Gx->CON->Flag.bit.SVPWM == 0U)
        Gx->V->n_ref->s = 0.0F;

    Gx->V->n_ref->a = Gx->V->p_ref->a + Gx->V->n_ref->s;
    Gx->V->n_ref->b = Gx->V->p_ref->b + Gx->V->n_ref->s;
    Gx->V->n_ref->c = Gx->V->p_ref->c + Gx->V->n_ref->s;

    return;
}

void Inv_VfCon(ST_GXCLC *Gx)
{
    Gx->V->e_ref->d = Gx->CON->Ref.V.vf_e.d;
    Gx->V->e_ref->q = Gx->CON->Ref.V.vf_e.q;

    FPdqe2abc(Gx->V->e_ref, Gx->V->s_ref, Gx->V->p_ref, &Gx->T->Pll->cost_vf, &Gx->T->Pll->sint_vf);

    *(Gx->V->dc_ref) = Gx->CON->Ref.V.vf_dc;

    Gx->V->cir_ref->a = 0.0F;
    Gx->V->cir_ref->b = 0.0F;
    Gx->V->cir_ref->c = 0.0F;

    return;
}

void ConV_VfCon(ST_GXCLC *Gx)
{
    Gx->V->e_ref->d = Gx->V->e2_p_flt->d - Gx->CON->Ref.V.vf_e.d;
    Gx->V->e_ref->q = Gx->V->e2_p_flt->q - Gx->CON->Ref.V.vf_e.q;

    FPdqe2abc(Gx->V->e_ref, Gx->V->s_ref, Gx->V->p_ref, &Gx->T->Pll->cost_vf, &Gx->T->Pll->sint_vf);

    *(Gx->V->dc_ref) = Gx->CON->Ref.V.vf_dc;

    Gx->V->cir_ref->a = 0.0F;
    Gx->V->cir_ref->b = 0.0F;
    Gx->V->cir_ref->c = 0.0F;

    return;
}

void VdcCon(ST_GXCLC *Gx)
{
    *(Gx->V->dc_err)        = *(Gx->V->dc_ref) - *Gx->V->dc;

    Gx->I->Vdc->ref_anti    = Gx->K->vdc->a*(Gx->I->Vdc->ref - Gx->I->ac_e_ref->q);
    Gx->I->Vdc->ref_integ   += Gx->K->vdc->i*(*(Gx->V->dc_err) - Gx->I->Vdc->ref_anti)*Gx->TB->SampT;
    Gx->I->Vdc->ref_prop    = Gx->K->vdc->p*(*(Gx->V->dc));
    Gx->I->Vdc->ref         = Gx->I->Vdc->ref_integ - Gx->I->Vdc->ref_prop;

    Gx->I->ac_e_ref->q      = BOUND(Gx->I->Vdc->ref, *(Gx->I->I_qe_limit));

    return;
}

void CcscCon(ST_GXCLC *Gx)
{
    Gx->I->cir_e_ref->d =  0.0F;

    Gx->I->cir_e_err->d = Gx->I->cir_e_ref->d - Gx->I->cir_e->d;

    Gx->V->CCSC->e_ref_integ.d  += Gx->K->ccsc->i*Gx->I->cir_e_err->d*Gx->TB->SampT;
    Gx->V->CCSC->e_ref_prop.d   = Gx->K->ccsc->i*Gx->I->cir_e_err->d;
    Gx->V->CCSC->e_ref_fb.d     = Gx->V->CCSC->e_ref_integ.d + Gx->V->CCSC->e_ref_prop.d;
    Gx->V->CCSC->e_ref_fb.d     = - 2*Gx->SP->Larm*Gx->SP->w0*Gx->I->cir_e->q;
    Gx->V->CCSC->e_ref.d        = Gx->V->CCSC->e_ref_fb.d + Gx->V->CCSC->e_ref_fb.d;

    Gx->I->cir_e_ref->q =  0.0F;

    Gx->I->cir_e_err->q = Gx->I->cir_e_ref->q - Gx->I->cir_e->q;

    Gx->V->CCSC->e_ref_integ.q  += Gx->K->ccsc->i*Gx->I->cir_e_err->q*Gx->TB->SampT;
    Gx->V->CCSC->e_ref_prop.q   = Gx->K->ccsc->i*Gx->I->cir_e_err->q;
    Gx->V->CCSC->e_ref_fb.q     = Gx->V->CCSC->e_ref_integ.q + Gx->V->CCSC->e_ref_prop.q;
    Gx->V->CCSC->e_ref_fb.q     = 2*Gx->SP->Larm*Gx->SP->w0*Gx->I->cir_e->d;
    Gx->V->CCSC->e_ref.q        = Gx->V->CCSC->e_ref_fb.q + Gx->V->CCSC->e_ref_fb.q;

    FNdqe2abc(&Gx->V->CCSC->e_ref, Gx->V->cir_s_ref, Gx->V->cir_ref, &Gx->T->Pll->cost_2nd, &Gx->T->Pll->sint_2nd);

    return;
}

void AcCurCon(ST_GXCLC *Gx)
{
    Gx->I->ac_e_err->d = Gx->I->ac_e_ref->d - Gx->I->e2->d;

    Gx->V->AC->e_ref_anti.d    =  Gx->K->iac->a*(Gx->V->AC->e_ref.d - Gx->V->e_ref->d);
    Gx->V->AC->e_ref_integ.d   += Gx->K->iac->i*(Gx->I->ac_e_err->d - Gx->V->AC->e_ref_anti.d)*Gx->TB->SampT;
    Gx->V->AC->e_ref_prop.d    =  Gx->K->iac->p*Gx->I->ac_e_err->d;
    Gx->V->AC->e_ref_ff.d      = -Gx->V->AC->e_ref_integ.d + Gx->V->AC->e_ref_prop.d;
    Gx->V->AC->e_ref_fb.d      =  Gx->SP->w0*(0.5F*Gx->SP->Larm + Gx->SP->Ls)*Gx->I->e2->q;
    Gx->V->AC->e_ref.d         =  Gx->V->AC->e_ref_ff.d + Gx->V->AC->e_ref_fb.d;

    Gx->I->ac_e_err->q = Gx->I->ac_e_ref->q - Gx->I->e2->d;

    Gx->V->AC->e_ref_anti.q    =  Gx->K->iac->a*(Gx->V->AC->e_ref.q - Gx->V->e_ref->q);
    Gx->V->AC->e_ref_integ.q   += Gx->K->iac->i*(Gx->I->ac_e_err->q - Gx->V->AC->e_ref_anti.q)*Gx->TB->SampT;
    Gx->V->AC->e_ref_prop.q    =  Gx->K->iac->p*Gx->I->ac_e_err->q;
    Gx->V->AC->e_ref_ff.q      =  Gx->V->AC->e_ref_integ.q + Gx->V->AC->e_ref_prop.q;
    Gx->V->AC->e_ref_fb.q      =  Gx->SP->w0*(0.5F*Gx->SP->Larm + Gx->SP->Ls)*Gx->I->e2->d + Gx->V->e2->q;
    Gx->V->AC->e_ref.q         =  Gx->V->AC->e_ref_ff.q + Gx->V->AC->e_ref_fb.q;

    FPdqe2abc(&Gx->V->AC->e_ref, Gx->V->s_ref, Gx->V->p_ref, &Gx->T->Pll->cost, &Gx->T->Pll->sint);

    return;
}

void CirCurCon(ST_GXCLC *Gx)
{
    Gx->I->cir_ref->a = Gx->I->cir_dc_ref->a + Gx->I->cir_ac_p_ref->a + Gx->I->cir_ac_n_ref->a;

    Gx->I->cir_err->a              =  Gx->I->cir_ref->a - Gx->I->cir->a;

    Gx->V->CIR->p_ref_integ.a     += Gx->K->cir->i*Gx->I->cir_err->a*Gx->TB->SampT;
    Gx->V->CIR->p_ref_prop.a      =  Gx->K->cir->p*Gx->I->cir_err->a;
    Gx->V->CIR->p_ref_resnt.a     =  Gx->V->CIR->zb[0]*Gx->I->cir_err->a + Gx->V->CIR->p_ref_r_old.a;
    Gx->V->CIR->p_ref_r_old.a     =  Gx->V->CIR->p_ref_r_o_old.a + Gx->V->CIR->zb[1]*Gx->I->cir_err->a - Gx->V->CIR->za[1]*Gx->V->CIR->p_ref_resnt.a;
    Gx->V->CIR->p_ref_r_o_old.a   =  Gx->V->CIR->zb[2]*Gx->I->cir_err->a - Gx->V->CIR->za[2]*Gx->V->CIR->p_ref_resnt.a;
    Gx->V->CIR->p_ref.a           =  Gx->V->CIR->p_ref_r_old.a + Gx->V->CIR->p_ref_prop.a + Gx->V->CIR->p_ref_resnt.a;

    Gx->I->cir_ref->b = Gx->I->cir_dc_ref->b + Gx->I->cir_ac_p_ref->b + Gx->I->cir_ac_n_ref->b;

    Gx->I->cir_err->b              =  Gx->I->cir_ref->b - Gx->I->cir->b;

    Gx->V->CIR->p_ref_integ.b     += Gx->K->cir->i*Gx->I->cir_err->b*Gx->TB->SampT;
    Gx->V->CIR->p_ref_prop.b      =  Gx->K->cir->p*Gx->I->cir_err->b;
    Gx->V->CIR->p_ref_resnt.b     =  Gx->V->CIR->zb[0]*Gx->I->cir_err->b + Gx->V->CIR->p_ref_r_old.b;
    Gx->V->CIR->p_ref_r_old.b     =  Gx->V->CIR->p_ref_r_o_old.b + Gx->V->CIR->zb[1]*Gx->I->cir_err->b - Gx->V->CIR->za[1]*Gx->V->CIR->p_ref_resnt.b;
    Gx->V->CIR->p_ref_r_o_old.b   =  Gx->V->CIR->zb[2]*Gx->I->cir_err->b - Gx->V->CIR->za[2]*Gx->V->CIR->p_ref_resnt.b;
    Gx->V->CIR->p_ref.b           =  Gx->V->CIR->p_ref_r_old.b + Gx->V->CIR->p_ref_prop.b + Gx->V->CIR->p_ref_resnt.b;

    Gx->I->cir_ref->c = Gx->I->cir_dc_ref->c + Gx->I->cir_ac_p_ref->c + Gx->I->cir_ac_n_ref->c;

    Gx->I->cir_err->c              =  Gx->I->cir_ref->c - Gx->I->cir->c;

    Gx->V->CIR->p_ref_integ.c     += Gx->K->cir->i*Gx->I->cir_err->c*Gx->TB->SampT;
    Gx->V->CIR->p_ref_prop.c      =  Gx->K->cir->p*Gx->I->cir_err->c;
    Gx->V->CIR->p_ref_resnt.c     =  Gx->V->CIR->zb[0]*Gx->I->cir_err->c + Gx->V->CIR->p_ref_r_old.c;
    Gx->V->CIR->p_ref_r_old.c     =  Gx->V->CIR->p_ref_r_o_old.c + Gx->V->CIR->zb[1]*Gx->I->cir_err->c - Gx->V->CIR->za[1]*Gx->V->CIR->p_ref_resnt.c;
    Gx->V->CIR->p_ref_r_o_old.c   =  Gx->V->CIR->zb[2]*Gx->I->cir_err->c - Gx->V->CIR->za[2]*Gx->V->CIR->p_ref_resnt.c;
    Gx->V->CIR->p_ref.c           =  Gx->V->CIR->p_ref_r_old.c + Gx->V->CIR->p_ref_prop.c + Gx->V->CIR->p_ref_resnt.c;

    Gx->V->cir_ref->a = Gx->V->CIR->p_ref.a;
    Gx->V->cir_ref->b = Gx->V->CIR->p_ref.b;
    Gx->V->cir_ref->c = Gx->V->CIR->p_ref.c;

    return;
}

void DcCurCon(ST_GXCLC *Gx)
{
    *(Gx->I->dc_err)        =  *(Gx->I->dc_ref) - *(Gx->I->dc);

    Gx->V->DC->ref_integ    += Gx->K->idc->i*(*(Gx->I->dc_err))*Gx->TB->SampT;
    Gx->V->DC->ref_prop     =  Gx->K->idc->p*(*(Gx->I->dc_err));
    Gx->V->DC->ref_fb       =  Gx->V->DC->ref_integ + Gx->V->DC->ref_prop;
    Gx->V->DC->ref_ff       =  Gx->SP->Vdc_rated;

    *(Gx->V->dc_ref)        =  Gx->V->DC->ref_fb + Gx->V->DC->ref_ff;

    return;
}

void ConvTotalEngyCon(ST_GXCLC *Gx)
{
    *(Gx->E->tot_err)       =  *(Gx->E->total_ref) - *(Gx->E->total);

    Gx->P->Tot->ref_integ   += Gx->K->tot->i*(*(Gx->E->tot_err))*Gx->TB->SampT;
    Gx->P->Tot->ref_prop    =  Gx->K->tot->p*(*(Gx->E->tot_err));
    Gx->P->Tot->ref_fb      =  Gx->P->Tot->ref_integ + Gx->P->Tot->ref_prop;
    Gx->P->Tot->ref_ff      = -1.0F*Gx->CON->Ref.V.dc*(*(Gx->I->dc));
    Gx->P->Tot->ref         = -Gx->P->Tot->ref_fb + Gx->P->Tot->ref_ff;

    Gx->I->ac_e_ref->q      = -1.0F*Gx->P->Tot->ref/(Gx->SP->V2ph_peak*1.5F);

    return;
}

void InvTotalEngyCon(ST_GXCLC *Gx)
{
    *(Gx->E->tot_err)       =  *(Gx->E->total_ref) - *(Gx->E->total);

    Gx->P->Tot->ref_integ   += Gx->K->tot->i*(*(Gx->E->tot_err))*Gx->TB->SampT;
    Gx->P->Tot->ref_prop    =  Gx->K->tot->p*(*(Gx->E->tot_err));
    Gx->P->Tot->ref_fb      =  Gx->P->Tot->ref_integ + Gx->P->Tot->ref_prop;
    Gx->P->Tot->ref_ff      =  1.5*Gx->I->ac_e_ref->q*Gx->V->e2->q;
    Gx->P->Tot->ref         =  Gx->P->Tot->ref_fb + Gx->P->Tot->ref_ff;

    *(Gx->I->dc_ref)        =  Gx->P->Tot->ref/Gx->SP->Vdc_rated;

    return;
}

void LegEngyBalCon(ST_GXCLC *Gx)
{
    *(Gx->P->leg_avg_ff)      = (Gx->P->Leg->p_ref_ff.a + Gx->P->Leg->p_ref_ff.b + Gx->P->Leg->p_ref_ff.c)*INV_3;

    *(Gx->E->leg_ref)         = (Gx->E->leg_flt->a + Gx->E->leg_flt->b + Gx->E->leg_flt->c)*INV_3;

    Gx->E->leg_p_err->a       =  *(Gx->E->leg_ref) - Gx->E->leg_flt->a;

    Gx->P->Leg->p_ref_integ.a += Gx->K->leg->i*Gx->E->leg_p_err->a*Gx->TB->SampT;
    Gx->P->Leg->p_ref_prop.a  =  Gx->K->leg->p*Gx->E->leg_p_err->a;
    Gx->P->Leg->p_ref_fb.a    =  Gx->P->Leg->p_ref_integ.a + Gx->P->Leg->p_ref_prop.a;
    Gx->P->Leg->p_ref_ff.a    -= *(Gx->P->leg_avg_ff);
    Gx->P->Leg->p_ref.a       =  Gx->P->Leg->p_ref_fb.a + Gx->P->Leg->p_ref_ff.a;

    Gx->I->cir_dc_ref->a       =  Gx->P->Leg->p_ref.a * Gx->SP->Inv_Vdc;

    Gx->E->leg_p_err->b       =  *(Gx->E->leg_ref)  - Gx->E->leg_flt->b;

    Gx->P->Leg->p_ref_integ.b += Gx->K->leg->i*Gx->E->leg_p_err->b*Gx->TB->SampT;
    Gx->P->Leg->p_ref_prop.b  =  Gx->K->leg->p*Gx->E->leg_p_err->b;
    Gx->P->Leg->p_ref_fb.b    =  Gx->P->Leg->p_ref_integ.b + Gx->P->Leg->p_ref_prop.b;
    Gx->P->Leg->p_ref_ff.b    -= *(Gx->P->leg_avg_ff);
    Gx->P->Leg->p_ref.b       =  Gx->P->Leg->p_ref_fb.b + Gx->P->Leg->p_ref_ff.b;

    Gx->I->cir_dc_ref->b       =  Gx->P->Leg->p_ref.b * Gx->SP->Inv_Vdc;

    Gx->E->leg_p_err->c       =  *(Gx->E->leg_ref)  - Gx->E->leg_flt->c;

    Gx->P->Leg->p_ref_integ.c += Gx->K->leg->i*Gx->E->leg_p_err->c*Gx->TB->SampT;
    Gx->P->Leg->p_ref_prop.c  =  Gx->K->leg->p*Gx->E->leg_p_err->c;
    Gx->P->Leg->p_ref_fb.c    =  Gx->P->Leg->p_ref_integ.c + Gx->P->Leg->p_ref_prop.c;
    Gx->P->Leg->p_ref_ff.c    -= *(Gx->P->leg_avg_ff);
    Gx->P->Leg->p_ref.c       =  Gx->P->Leg->p_ref_fb.c + Gx->P->Leg->p_ref_ff.c;

    Gx->I->cir_dc_ref->c       =  Gx->P->Leg->p_ref.c * Gx->SP->Inv_Vdc;

    return;
}

// Arms Energy Difference Common Controller
void ArmEngyComCon(ST_GXCLC *Gx)
{
    *(Gx->E->acom_ref) = 0.0F;

    *(Gx->E->acom_n_err)     = *(Gx->E->acom_ref) - *(Gx->E->com);

    Gx->P->Acom->ref_integ   += Gx->K->acom->i*(*(Gx->E->acom_n_err))*Gx->TB->SampT;
    Gx->P->Acom->ref_prop    = Gx->K->acom->p*(*(Gx->E->acom_n_err));
    Gx->P->Acom->ref         = Gx->P->Acom->ref_integ + Gx->P->Acom->ref_prop;

    Gx->I->cir_ac_p_ref->a   = *(Gx->V->e_invsq) * Gx->V->p_ref->a;
    Gx->I->cir_ac_p_ref->b   = *(Gx->V->e_invsq) * Gx->V->p_ref->b;
    Gx->I->cir_ac_p_ref->c   = *(Gx->V->e_invsq) * Gx->V->p_ref->c;

    return;
}

// Arms Energy Difference Difference Controller
void ArmEngyDiffCon(ST_GXCLC *Gx)
{
    *(Gx->E->adiff_ref) = 0.0F;

    Gx->E->adiff_p_err->a       = *(Gx->E->adiff_ref) - Gx->E->diff->a;

    Gx->P->Adiff->p_ref_integ.a += Gx->K->acom->i*Gx->E->adiff_p_err->a*Gx->TB->SampT;
    Gx->P->Adiff->p_ref_prop.a  = Gx->K->acom->p*Gx->E->adiff_p_err->a;
    Gx->P->Adiff->p_ref.a       = Gx->P->Adiff->p_ref_integ.a + Gx->P->Adiff->p_ref_prop.a;

    Gx->E->adiff_p_err->b       = *(Gx->E->adiff_ref) - Gx->E->diff->b;

    Gx->P->Adiff->p_ref_integ.b += Gx->K->acom->i*Gx->E->adiff_p_err->b*Gx->TB->SampT;
    Gx->P->Adiff->p_ref_prop.b  = Gx->K->acom->p*Gx->E->adiff_p_err->b;
    Gx->P->Adiff->p_ref.b       = Gx->P->Adiff->p_ref_integ.b + Gx->P->Adiff->p_ref_prop.b;

    Gx->E->adiff_p_err->c       = *(Gx->E->adiff_ref) - Gx->E->diff->c;

    Gx->P->Adiff->p_ref_integ.c += Gx->K->acom->i*Gx->E->adiff_p_err->c*Gx->TB->SampT;
    Gx->P->Adiff->p_ref_prop.c  = Gx->K->acom->p*Gx->E->adiff_p_err->c;
    Gx->P->Adiff->p_ref.c       = Gx->P->Adiff->p_ref_integ.c + Gx->P->Adiff->p_ref_prop.c;

    FPabc2dqs(&Gx->P->Adiff->p_ref, Gx->P->Adiff_s_ref);

    Gx->I->cir_ac_n_s_ref->d = *(Gx->V->e_invsq)*(Gx->P->Adiff_s_ref->d*Gx->V->s_ref->d - Gx->P->Adiff_s_ref->q*Gx->V->s_ref->q);
    Gx->I->cir_ac_n_s_ref->q = *(Gx->V->e_invsq)*(Gx->P->Adiff_s_ref->d*Gx->V->s_ref->q + Gx->P->Adiff_s_ref->q*Gx->V->s_ref->d);

    FNdqs2abc(Gx->I->cir_ac_n_s_ref, Gx->I->cir_ac_n_ref);

    return;
}

//DSOGI
void DSOGI(ST_GXCLC *Gx)
{
    Gx->T->SGd->v_err_prop  = *(Gx->K->sogi)*(Gx->V->s2->d - Gx->T->SGd->v_prime);
    Gx->T->SGd->v_err_integ = Gx->SP->w0*(Gx->T->SGd->v_err_prop - Gx->T->SGd->qv_prime);
    Gx->T->SGd->v_prime     += Gx->T->SGd->v_err_integ*Gx->TB->SampT;
    Gx->T->SGd->v_prime     += Gx->SP->w0*Gx->T->SGd->v_prime*Gx->TB->SampT;

    Gx->T->SGq->v_err_prop  = *(Gx->K->sogi)*(Gx->V->s2->q - Gx->T->SGq->v_prime);
    Gx->T->SGq->v_err_integ = Gx->SP->w0*(Gx->T->SGq->v_err_prop - Gx->T->SGq->qv_prime);
    Gx->T->SGq->v_prime     += Gx->T->SGq->v_err_integ*Gx->TB->SampT;
    Gx->T->SGq->v_prime     += Gx->SP->w0*Gx->T->SGq->v_prime*Gx->TB->SampT;

    Gx->V->s2_p->d = 0.5F*(Gx->T->SGd->v_prime - Gx->T->SGq->qv_prime);
    Gx->V->s2_p->q = 0.5F*(Gx->T->SGd->qv_prime + Gx->T->SGq->v_prime);

    return;
}

//PLL
void PLL(ST_GXCLC *Gx)
{
    Gx->T->Pll->e_err = -Gx->V->e2_p_flt->d;

    Gx->T->Pll->w_ref_integ += Gx->K->pll->i*Gx->T->Pll->e_err*Gx->TB->SampT;
    Gx->T->Pll->w_ref_prop = Gx->K->pll->p*Gx->T->Pll->e_err;
    Gx->T->Pll->w_ref =Gx->T->Pll->w_ref_integ + Gx->T->Pll->w_ref_prop;

    Gx->T->Pll->theta += Gx->T->Pll->w_ref*Gx->TB->SampT;

    if(Gx->T->Pll->theta > PI)      Gx->T->Pll->theta -= PI2;
    else if(Gx->T->Pll->theta <0)   Gx->T->Pll->theta += PI2;

    Gx->T->Pll->theta_2nd = 2*Gx->T->Pll->theta;
    if(Gx->T->Pll->theta_2nd)       Gx->T->Pll->theta_2nd -= PI2;
    else if(Gx->T->Pll->theta_2nd)  Gx->T->Pll->theta_2nd += PI2;

    return;
}

void PLL_VF(ST_GXCLC *Gx)
{
    Gx->T->Pll->theta_vf += Gx->T->Pll->freq_vf*PI2*Gx->TB->SampT;

    if(Gx->T->Pll->theta_vf > PI)      Gx->T->Pll->theta_vf -= PI2;
    else if(Gx->T->Pll->theta_vf <0)   Gx->T->Pll->theta_vf += PI2;

    return;
}

//Positive Sequence Synchronous frame Transformation
void FPabc2dqe(ST_PH *Fabc, ST_DQ *Fdqs, ST_DQ *Fdqe, float *cost, float *sint)
{
    Fdqs->d = (2.0F*Fabc->a - Fabc->b - Fabc->c)*INV_3;
    Fdqs->q = (Fabc->b - Fabc->c)*INV_SQRT3;

    Fdqe->d =  (*cost)*Fdqs->d + (*sint)*Fdqs->q;
    Fdqe->q = -(*sint)*Fdqs->d + (*cost)*Fdqs->q;

    return;
}

//Positive Sequence Stationary frame Transformation
void FPabc2dqs(ST_PH *Fabc, ST_DQ *Fdqs)
{
    Fdqs->d = (2.0F*Fabc->a - Fabc->b - Fabc->c)*INV_3;
    Fdqs->q = (Fabc->b - Fabc->c)*INV_SQRT3;

    return;
}

//Positive Sequence Synchronous frame Inverse Transformation
void FPdqe2abc(ST_DQ *Fdqe, ST_DQ *Fdqs, ST_PH *Fabc, float *cost, float *sint)
{
    Fdqs->d = (*cost)*Fdqe->d - (*sint)*Fdqe->q;
    Fdqs->q = (*sint)*Fdqe->d + (*cost)*Fdqe->q;

    Fabc->a = Fdqs->d;
    Fabc->b = -0.5F*(Fdqs->d - SQRT3*Fdqs->q);
    Fabc->c = -0.5F*(Fdqs->d + SQRT3*Fdqs->q);

    return;
}

//Positive Sequence Stationary frame Inverse Transformation
void FPdqe2dqs(ST_DQ *Fdqe, ST_DQ *Fdqs, float *cost, float *sint)
{
    Fdqs->d = (*cost)*Fdqe->d - (*sint)*Fdqe->q;
    Fdqs->q = (*sint)*Fdqe->d + (*cost)*Fdqe->q;

    return;
}

//Positive Sequence Stationary frame Inverse Transformation
void FPdqs2abc(ST_DQ *Fdqs, ST_PH *Fabc)
{
    Fabc->a = Fdqs->d;
    Fabc->b = -0.5F*(Fdqs->d - SQRT3*Fdqs->q);
    Fabc->c = -0.5F*(Fdqs->d + SQRT3*Fdqs->q);

    return;
}


//Negative Sequence Synchronous frame Transformation
void FNabc2dqe(ST_PH *Fabc, ST_DQ *Fdqs, ST_DQ *Fdqe, float *cost, float *sint)
{
    Fdqs->d = (2.0F*Fabc->a - Fabc->b - Fabc->c)*INV_3;
    Fdqs->q = (Fabc->c - Fabc->b)*INV_SQRT3;

    Fdqe->d =  (*cost)*Fdqs->d + (*sint)*Fdqs->q;
    Fdqe->q = -(*sint)*Fdqs->d + (*cost)*Fdqs->q;

    return;
}

//Negative Sequence Stationary frame Transformation
void FNabc2dqs(ST_PH *Fabc, ST_DQ *Fdqs)
{
    Fdqs->d = (2.0F*Fabc->a - Fabc->b - Fabc->c)*INV_3;
    Fdqs->q = (Fabc->c - Fabc->b)*INV_SQRT3;

    return;
}

//Negative Sequence Synchronous frame Inverse Transformation
void FNdqe2abc(ST_DQ *Fdqe, ST_DQ *Fdqs, ST_PH *Fabc, float *cost, float *sint)
{
    Fdqs->d = (*cost)*Fdqe->d - (*sint)*Fdqe->q;
    Fdqs->q = (*sint)*Fdqe->d + (*cost)*Fdqe->q;

    Fabc->a = Fdqs->d;
    Fabc->b = -0.5F*(Fdqs->d + SQRT3*Fdqs->q);
    Fabc->c = -0.5F*(Fdqs->d - SQRT3*Fdqs->q);

    return;
}

//Negative Sequence Stationary frame Inverse Transformation
void FNdqe2dqs(ST_DQ *Fdqe, ST_DQ *Fdqs, float *cost, float *sint)
{
    Fdqs->d = (*cost)*Fdqe->d - (*sint)*Fdqe->q;
    Fdqs->q = (*sint)*Fdqe->d + (*cost)*Fdqe->q;

    return;
}

//Negative Sequence Synchronous frame Inverse Transformation
void FNdqs2abc(ST_DQ *Fdqs, ST_PH *Fabc)
{
    Fabc->a = Fdqs->d;
    Fabc->b = -0.5F*(Fdqs->d + SQRT3*Fdqs->q);
    Fabc->c = -0.5F*(Fdqs->d - SQRT3*Fdqs->q);

    return;
}
