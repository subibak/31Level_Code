/*
 * Define_Group_sorting.h
 *
 *  Created on: 2019. 1. 11.
 *      Author: subi
 */

#ifndef INCLUDES_AM572X_C66_DEFINE_GROUP_SORTING_H_
#define INCLUDES_AM572X_C66_DEFINE_GROUP_SORTING_H_

#define INV_OP_CHARGE_TIMER_CNT       50055U    // 1 sec  5000 count (in 200us)(DC_CHARGE) + 5 sec 25000 CONNECT MAIN CIRCUIT
#define PRE_MC_OP_TIMER_CNT           10010U    // After DC Charging  10000 count (in 200us)(DC_CHARGE)
#define MAIN_MC_OP_TIMER_CNT          30010U
    // After DC Charging  10000 count (in 200us)(DC_CHARGE)

extern float V_AU[5];
extern float V_AL[5];
extern float V_BU[5];
extern float V_BL[5];
extern float V_CU[5];
extern float V_CL[5];
extern float SMua_on, SMla_on, SMub_on, SMlb_on, SMuc_on, SMlc_on;
extern Uint32 DC_CHARGE_cnt;
extern float Vdc_char_ref;
extern float DC_CHARGE_RAMP;

extern void NLC(void);
extern void DC_CHRAGING_SEQ(void);

#endif /* INCLUDES_AM572X_C66_DEFINE_GROUP_SORTING_H_ */
