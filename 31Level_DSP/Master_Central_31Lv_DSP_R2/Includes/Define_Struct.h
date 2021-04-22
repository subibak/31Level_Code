/*
 * Define_C66_Struct.h
 *
 *  Created on: 2020. 9. 22.
 *      Author: subi
 */

#ifndef INCLUDES_AM572X_C66_AM572X_C66_STRUCT_H_
#define INCLUDES_AM572X_C66_AM572X_C66_STRUCT_H_


#ifdef __cplusplus
extern "C" {
#endif

//******************************Base Structure*****************************************//
//SM Group Module Variable
typedef struct {
    float           g1;
    float           g2;
    float           g3;
    float           g4;
    float           g5;
    float           g6;
} ST_GRPMODULE;

//Arm Variable
typedef struct {
    float           u;          // Upper Arm
    float           l;          // Lower Arm
} ST_ARMUL;

typedef struct {
    ST_GRPMODULE    u;
    ST_GRPMODULE    l;
} ST_ARMGRPUL;

//Leg Variable
typedef struct {
    ST_ARMUL        a;
    ST_ARMUL        b;
    ST_ARMUL        c;
} ST_ARM;

typedef struct {
    ST_ARMGRPUL     a;
    ST_ARMGRPUL     b;
    ST_ARMGRPUL     c;
} ST_ARMGRP;

//3-phase Phase-to-Phase variable
typedef struct {
    float           ab;
    float           bc;
    float           ca;
} ST_PP;

//3-phase Phase variable
typedef struct {
    float           a;
    float           b;
    float           c;
} ST_PH;

//3-phase Pole variable
typedef struct {
    float           a;
    float           b;
    float           c;
    float           s;
} ST_PO;

//DQ Variable
typedef struct {
    float           d;
    float           q;
} ST_DQ;

//PI gain
typedef struct {
    float           p;
    float           i;
} ST_PI;

//PI(Anti-windup) gain
typedef struct {
    float           p;
    float           i;
    float           a;
} ST_PIA;

//PIR gain
typedef struct {
    float           p;
    float           i;
    float           r;
} ST_PIR;

typedef struct {
    float           ref_integ;          // Reference Integration
    float           ref_prop;           // Reference Proportion
    float           ref_anti;           // Reference Anti-windup
    float           ref_fb;             // Reference Feedback
    float           ref_ff;             // Reference Feedback
    float           ref;                // Reference Sum
} ST_FPICON;

typedef struct {
    ST_DQ           e_ref_integ;        // Reference Integration
    ST_DQ           e_ref_prop;         // Reference Proportion
    ST_DQ           e_ref_anti;         // Reference Anti-windup
    ST_DQ           e_ref_fb;           // Reference Feedback
    ST_DQ           e_ref_ff;           // Reference Feedback
    ST_DQ           e_ref;              // Reference Sum
} ST_DQPICON;

typedef struct {
    ST_PH           p_ref_integ;        // Reference Integration
    ST_PH           p_ref_prop;         // Reference Proportion
    ST_PH           p_ref_fb;           // Reference Feedback
    ST_PH           p_ref_ff;           // Reference Feedback
    ST_PH           p_ref;              // Reference Sum
} ST_PHPICON;

typedef struct {
    ST_PH           p_ref_integ;        // Reference Integration
    ST_PH           p_ref_prop;         // Reference Proportion
    ST_PH           p_ref_resnt;        // Reference Resonant
    ST_PH           p_ref_r_old;        // Reference Resonant Old
    ST_PH           p_ref_r_o_old;      // Reference Resonant Old Old
    ST_PH           p_ref_fb;           // Reference Feedback
    ST_PH           p_ref_ff;           // Reference Feedback
    ST_PH           p_ref;              // Reference Sum
    float           za[3];              // Coefficient a[2]
    float           zb[3];              // Coefficient b[2]
} ST_PHPIRCON;

//******************************System Specification***********************************//
//Time Base Parameter(Controller Parameter)
typedef struct {
    Uint16          PRD;
    Uint16          HALF_PRD;
    float           SampT;
    float           Freq;
    struct  {
        Uint16          PRD;
        float           SampT;
        float           Freq;
    } OUTERLOOP;
} ST_TB;

//Grid & Power Conversion System Parameter
typedef struct {
    float           f0;
    float           w0;
    float           NumSM;
    float           Csm;
    float           Larm;
    float           Rarm;
    float           Ls;
    float           Rs;
    float           Vdc_rated;
    float           Inv_Vdc;
    float           V1pp_rms;
    float           V1ph_rms;
    float           V1pp_peak;
    float           V1ph_peak;
    float           V2pp_rms;
    float           V2ph_rms;
    float           V2pp_peak;
    float           V2ph_peak;
} ST_SP;

//******************************Grid & Power Conversion System Control*****************//
//Gird Control Variable Collection
typedef struct {
    union {
        Uint16          all;
        struct {
            Uint16          MOM:2;          // Modulation Method(Indirect : 0x1, Direct : 0x2)
            Uint16          OPM:2;          // Converter Mode(Converter : 0x1, Inverter : 0x2)
        } bit;
    } MODE;

    union {
        Uint16          all;
        struct {
            Uint16          VF:1;           // V/F Control
            Uint16          E_total:1;      // Total Energy Control
            Uint16          E_leg:1;        // Leg Energy Control
            Uint16          E_arm_diff:1;   // Arm Energy Difference Difference Control
            Uint16          E_arm_com:1;    // Arm Energy Difference Common Control
            Uint16          Energy:1;       // All of Energy Control
            Uint16          AC_current:1;   // AC Current Control
        } bit;
    } Flag_Indir;

    union {
        Uint16          all;
        struct {
            Uint16          VF:1;           // V/F Control
            Uint16          Vdc:1;          // DC Voltage Control
            Uint16          CCSC:1;         // Circulating Current Suppression Control
            Uint16          AC_current:1;   // AC Current Control
        } bit;
    } Flag_Dir;

    union {
        Uint16          all;
        struct {
            Uint16          Switching:1;    // Controller START/STOP
            Uint16          SVPWM:1;        // SVPWM Enable
            Uint16          OM:1;           // Over Modulation
            Uint16          OUTERLOOP:1;    // Outer Loop Control Enable
        } bit;
    } Flag;

    struct {
        struct {
            float           tot;
        } E;
        struct {
            float           acivte;
            float           reacitve;
            float           pf;
        } P;
        struct {
            float           dc;
            float           vf_dc;
            ST_DQ           vf_e;
        } V;
        struct {
            ST_DQ           ac_e;
            ST_DQ           cir_e;
        } I;
    } Ref;

} ST_GCCLC;

//******************************Digital Filter*****************************************//
//Digital Filter Second-order IIR Collection
typedef struct {
    Uint8           *Type;              // Filter type
    float           *w0;                // Undamped natural frequency
    float           *Q;                 // Quality factor
    float           *Ts;
    float           sa[2];              // S-domain denominator coefficient
    float           sb[3];              // S-domain numerator coefficient
    float           za[3];              // Z-domain denominator coefficient
    float           zb[3];              // Z-domain numerator coefficient
    float           old[2];             // old value
} ST_DF2CLC;

//Digital Filter First-order IIR Collection
typedef struct {
    Uint8           *Type;              // Filter type
    float           *w0;                // Undamped natural frequency
    float           *Ts;
    float           sa0;                // S-domain denominator coefficient
    float           sb[2];              // S-domain numerator coefficient
    float           za[2];              // Z-domain denominator coefficient
    float           zb[2];              // Z-domain numerator coefficient
    float           old;                // old value
} ST_DF1CLC;

//Digital Filter Variable Collection
typedef struct {
    ST_DF2CLC       *pll;                // Digital Filter for pll
    ST_DF2CLC       *leg_a;              // Digital Filter for Phase-A Arm Energy Sum(Leg Energy)
    ST_DF2CLC       *leg_b;              // Digital Filter for Phase-B Arm Energy Sum(Leg Energy)
    ST_DF2CLC       *leg_c;              // Digital Filter for Phase-C Arm Energy Sum(Leg Energy)
    ST_DF2CLC       *diff_a;             // Digital Filter for Phase-A Arm Energy Difference
    ST_DF2CLC       *diff_b;             // Digital Filter for Phase-B Arm Energy Difference
    ST_DF2CLC       *diff_c;             // Digital Filter for Phase-C Arm Energy Difference
} ST_DFCLC;



//******************************Controller Gain****************************************//
//Gain Collection
typedef struct {
    float           *sogi;              // Sogi Gain
    ST_PI           *pll;               // Pll Gain
    ST_PIA          *iac;               // AC Current Controller Gain
    ST_PI           *idc;               // DC Current Controller Gain
    ST_PIR          *cir;               // Circulating Current Controller Gain(Indirect)
    ST_PI           *tot;               // Total Energy Controller Gain
    ST_PI           *leg;               // Leg Energy Controller Gain
    ST_PI           *acom;              // Arm Energy Difference-Common Controller Gain
    ST_PI           *adiff;             // Arm Energy Difference-Difference Controller Gain
    ST_PIA          *vdc;               // Vdc Controller Gain(Direct)
    ST_PI           *ccsc;              // Circulating Current Suppression Controller Gain(Direct)
} ST_GCLC;

//******************************Theta**************************************************//
//SOGI variable
typedef struct {
    float           v_err_prop;         // V Error Proportion
    float           v_err_integ;        // V Error Integration
    float           v_prime;            // Sogi output1
    float           qv_prime;           // Sogi output2
} ST_SOGI;

//PLL variable
typedef struct {
    float           e_err;              // Error
    float           w_ref_integ;        // Reference Integration
    float           w_ref_prop;         // Reference Proportion
    float           w_ref;              // Reference sum
    float           theta;              // theta
    float           sint;               // sin(theta)
    float           cost;               // cos(theta)
    float           theta_2nd;          // theta 2nd Harmonic
    float           sint_2nd;           // sin(theta) 2nd Harmonic
    float           cost_2nd;           // cos(theta) 2nd Harmonic
    float           freq_vf;            // Frequency vf
    float           theta_vf;           // theta vf
    float           sint_vf;            // sin(theta) vf
    float           cost_vf;            // cos(theta) vf
} ST_PLL;

typedef struct {
    ST_SOGI         *SGd;               // Sogi for d-axis
    ST_SOGI         *SGq;               // Sogi for q-axis
    ST_PLL          *Pll;               // Pll
} ST_TCLC;

//******************************Energy*************************************************//
//Energy Variable Collection
typedef struct {
    ST_ARM          *arm;               // Arm Energy
    float           *total;             // Arm Total Energy
    ST_PH           *leg;               // Arm Energy Sum(Leg Energy)
    ST_PH           *diff;              // Arm Energy Difference Difference
    float           *com;               // Arm Energy Difference Common
    ST_PH           *leg_flt;           // Filtered Arm Energy Sum(Leg Energy)
    ST_PH           *Adiff_flt;         // Filtered Arm Energy Difference

    float           *total_ref;         // Total Energy Controller Reference
    float           *leg_ref;           // Leg Energy Controller Reference
    float           *adiff_ref;         // Arm Energy Difference Difference Controller
    float           *acom_ref;          // Arm Energy Difference Common Controller

    float           *tot_err;           // Total Energy Error
    ST_PH           *leg_p_err;         // Leg Energy Error
    float           *acom_n_err;        // Arm Energy Difference Common Error
    ST_PH           *adiff_p_err;       // Arm Energy Difference Difference Error
} ST_ECLC;

//******************************Power**************************************************//
//Power Variable Collection
typedef struct {
    float           *tot_conv_ff;       // Total Energy Controller Feed Forward    ** Check if it is a necessary variable
    float           *tot_inv_ff;        // Total Energy Controller Feed Forward    ** Check if it is a necessary variable
    ST_PH           *leg_ff;            // Leg Energy Controller Feed Forward      ** Check if it is a necessary variable
    float           *leg_avg_ff;        // Leg Energy Average Feed Forward

    ST_DQ           *Adiff_s_ref;        // Reference Sum dqs

    ST_FPICON       *Tot;               // Total Energy Controller
    ST_PHPICON      *Leg;               // Leg(Arm Sum) Energy Controller
    ST_FPICON       *Acom;              // Arm Energy Difference Common Controller
    ST_PHPICON      *Adiff;             // Arm Energy Difference Difference Controller
} ST_PCLC;

//******************************Voltage************************************************//
//Voltage Variable Collection
typedef struct {
    ST_PP           *pp1;               // Transformer 1-st side Phase-to-Phase Voltage
    ST_PH           *ph1;               // Transformer 1-st side Phase voltage
    ST_DQ           *s1;                // Transformer 1-st side dqs voltage
    ST_DQ           *e1;                // Transformer 1-st side dqe voltage
    ST_PP           *pp2;               // Transformer 2-nd side Phase-to-Phase Voltage
    ST_PH           *ph2;               // Transformer 2-nd side Phase voltage
    ST_DQ           *s2;                // Transformer 2-nd side dqs voltage
    ST_DQ           *e2;                // Transformer 2-nd side dqe voltage
    ST_PH           *ph2_p;             // Transformer 2-nd side Positive Phase voltage
    ST_DQ           *s2_p;              // Transformer 2-nd side Positive dqs voltage
    ST_DQ           *e2_p;              // Transformer 2-nd side Positive dqe voltage
    ST_DQ           *e2_p_flt;          // Transformer 2-nd side Positive Filtered dqe voltage
    float           *dc;                // Vdc
    ST_ARMGRP       *grp_sm;             // 3-Phase Upper & Lower Group Submodule
    ST_ARM          *sm_sum;            // 3-Phase Upper & Lower Sum of Submodule Voltage

    float           *e_invsq;           // dqe Inverse Square

    ST_ARM          *arm_ref;           // 3-Phase Upper & Lower Arm Reference Voltage
    ST_ARM          *arm_norm_ref;      // 3-Phase Upper & Lower Arm Normalized Reference Voltage
    ST_ARM          *arm_num_ref;       // 3-Phase Upper & Lower Arm Turn-On Number Reference Voltage
    float           *dc_ref;            // Vdc Reference
    ST_PH           *p_ref;             // Phase Voltage Reference
    ST_PO           *n_ref;             // Pole Voltage Reference
    ST_DQ           *s_ref;             // dqs Voltage Reference
    ST_DQ           *e_ref;             // dqe Voltage Reference
    ST_DQ           *s_anti_ref;        // dqs Anti Windup Voltage Reference    ** Check if it is a necessary variable
    ST_DQ           *e_anti_ref;        // dqe Anti Windup Voltage Reference    ** Check if it is a necessary variable
    ST_PH           *cir_ref;           // Leg Internal Voltage
    ST_DQ           *cir_s_ref;         // dqs Leg Internal Voltage
    ST_DQ           *cir_e_ref;         // dqe Leg Internal Voltage

    float           *dc_err;            // DC Voltage err

    ST_DQPICON      *AC;                // AC Current Controller
    ST_FPICON       *DC;                // DC Current Controller
    ST_PHPIRCON     *CIR;               // Circulating Current Controller(Indirect)
    ST_DQPICON      *CCSC;              // Circulating Current Suppressing Controller(Direct)
} ST_VCLC;

//******************************Current************************************************//
//Current Variable Collection
typedef struct {
   ST_PH            *ph2;               // Transformer 2-nd side Phase Current
   ST_DQ            *s2;                // Transformer 2-nd side dqs Current
   ST_DQ            *e2;                // Transformer 2-nd side dqe Curent
   ST_DQ            *s2_p;              // Transformer 2-nd side Positive dqs Current
   ST_DQ            *e2_p;              // Transformer 2-nd side Positive dqe Current
   ST_PH            *cir;               // Circulating Current(Or Leg Current)
   ST_DQ            *cir_s;             // dqs Circulating Current
   ST_DQ            *cir_e;             // dqe Circulating Current
   float            *dc;                // DC current

   float            *I_qe_limit;        // q-axit Curren limit(for Vdc Controller)

   float            *dc_ref;            // DC Current Reference
   ST_DQ            *ac_e_ref;          // AC Current Reference
   ST_PH            *cir_dc_ref;        // DC Circulating Current Reference
   ST_PH            *cir_ac_p_ref;      // Positive AC Circulating Current Reference
   ST_PH            *cir_ac_n_ref;      // Negative AC Circulating Current Reference
   ST_DQ            *cir_ac_n_s_ref;    // Negative dqs AC Circulating Current Reference
   ST_DQ            *cir_e_ref;         // dqe Circulating Current Reference
   ST_PH            *cir_ref;           // Circulating Current Reference

   ST_DQ            *ac_e_err;          // AC Current Error
   float            *dc_err;            // DC Current Error
   ST_PH            *cir_err;           // Circulating Current Error(Energy Controller)
   ST_DQ            *cir_e_err;         // Circulating Current dqe Error(CCSC)

   ST_FPICON        *Vdc;               // Vdc Controller(Direct)
} ST_CCLC;

//******************************Grid-x ************************************************//
//Grid-X Variable Collection
typedef struct {
    ST_TB           *TB;                // Time Base(Controller) Parameter
    ST_SP           *SP;                // Grid & Power System Parameter
    ST_GCCLC        *CON;               // Grid & Power System Parameter Control
    ST_DFCLC        *DF;                // Digital Filter Collection
    ST_GCLC         *K;                 // Gain(K) Collection

    ST_TCLC         *T;                 // Theta Variable Collection
    ST_ECLC         *E;                 // Energy Variable Collection
    ST_PCLC         *P;                 // Power Variable Collection
    ST_VCLC         *V;                 // Voltage Variable Collection
    ST_CCLC         *I;                 // Current Variable Collection
} ST_GXCLC;


#ifdef __cplusplus
}
#endif

#endif /* INCLUDES_AM572X_C66_AM572X_C66_STRUCT_H_ */
