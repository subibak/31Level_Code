/*
 * Define_MMC_controller.h
 *
 *  Created on: 2019. 1. 11.
 *      Author: subi
 */

#ifndef INCLUDES_AM572X_C66_DEFINE_MMC_CONTROLLER_H_
#define INCLUDES_AM572X_C66_DEFINE_MMC_CONTROLLER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define RAMP_STALL_MAX              20000
#define CCSC_TIME                   30000
#define INV_OFF_TIME                15000
//flag
extern Uint16 Flag_gating;

// Variable
extern float Vdc_low,VM1as_ref,Va0_ref, Vdc_ref, Vxo_ref;
extern float VM1bs_ref,Vb0_ref;
extern float VM1cs_ref,Vc0_ref;
extern float VM1as_sat, VM1bs_sat, VM1cs_sat;
extern float Vdc_rated;
extern union TRANSFER_DATA pf, P, Q;
extern Uint16 Conv_start, Inv_start, Inv_start_Req;
extern float IM1qe;

// Function
extern void Operation(void);
extern void PLL(void);
extern void DSOGI(void);
extern void Grid_DQ(void);
extern void Vf_Control(void);
extern void Converter_voltage(void);
extern void SuppCirCurrent(void);
extern void Inverter_Direct(void);
extern void Converter_Direct(void);
extern void Inverter_Indirect(void);
extern void Converter_Indirect(void);
extern void Energy_Cal(void);
extern void Leg_Energy_Balance(void);
extern void Commom_Energy_Balance(void);
extern void Diff_Energy_Balance(void);
extern void Energy_diff_PIR(void);
extern void Current_Control(void);
extern void Idc_Control(void);
extern void Reset(void);
extern void Reference(void);
extern void Gain_Cal(void);
extern void Starting_sequence(void);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDES_AM572X_C66_DEFINE_MMC_CONTROLLER_H_ */
