/*
 * Define_Basetypes.h
 *
 *  Created on: 2018. 8. 27.
 *      Author: subi
 */

#ifndef DEFINE_BASETYPES_H_
#define DEFINE_BASETYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

// ADC.c
extern int AIN0_CH1, AIN0_CH2, AIN0_CH3, AIN0_CH4;
extern int AIN1_CH1, AIN1_CH2, AIN1_CH3, AIN1_CH4;
extern int AIN2_CH1, AIN2_CH2, AIN2_CH3, AIN2_CH4;
extern int AIN3_CH1, AIN3_CH2, AIN3_CH3, AIN3_CH4;
extern int AIN4_CH1, AIN4_CH2, AIN4_CH3, AIN4_CH4;

// Interrupt.c
extern int l, m, k, i, j, t;
extern int Number_SM;
extern int D_Number_SM;
extern int H_Number_SM;
extern Uint16 Group_number;

//LED.C
extern int LED_case;

// LPF_Parameter.c
extern float La_rpm, Lb_rpm;
extern float VM1de_delta, VM1de_pre, VM1de_lpf;

//Fault.c
extern Uint16 fault;

//DAQ_RS422
extern Uint16 TEST_RX[38], TEST_TX[20];
extern int test_tx_cnt;

//PWM.c
extern int Flag_Buffer_HW[4];
extern int Flag_Buffer_SW[6];
extern Uint16 BUFFER_HW;
extern Uint16 BUFFER_SW;
extern Uint16 PWM_x, NLC_x;
extern Uint16 REFERENCE[6];
extern Uint16 REFERENCE_t[6];
extern Uint16 V_ref_NLC;
extern Uint16 V_ref_PWM;

//Group_module_test.c
extern float SM_U_VOLTAGE_NEW_t[3];
extern float SM_L_VOLTAGE_NEW_t[3];
extern int SM_U_INDEX_NEW_t[3];
extern int SM_L_INDEX_NEW_t[3];

extern float theta_t;
extern float freq_t;
extern float sine_t[6];
extern float theta_t2;
extern float freq_t2;
extern float sine_t2[6];

extern float amp_sine_t;
extern float amp_sine_t2;

//Vol_Balance.c
extern int SM_INDEX_NEW[6];
extern float U_voltage_temp,  L_voltage_temp;
extern int U_index_temp, L_index_temp;

//OPERATION.c
extern Uint16 Flag_Normal_DT;
extern Uint16 Flag_Gating;
extern Uint16 PWM_MODE;

//Bypass.c
extern Uint16 Flag_Relay[6];
extern Uint16 Flag_IGBT[6];
extern Uint16 Flag_Bypass;

//FAN.c
extern Uint16 Flag_FAN[6];
extern Uint16 FAN_OP;

#ifdef __cplusplus
}
#endif

#endif /* DEFINE_BASETYPES_H_ */
