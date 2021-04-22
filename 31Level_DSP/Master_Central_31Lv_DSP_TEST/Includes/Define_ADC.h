/*
 * Define_ADC.h
 *
 *  Created on: 2018. 12. 13.
 *      Author: subi
 */

#ifndef INCLUDES_DEFINE_ADC_H_
#define INCLUDES_DEFINE_ADC_H_

#ifdef __cplusplus
extern "C" {
#endif
#define ADC_OFFSET_COUNT            10000
#define ADC_INV_OFFSET_COUNT        1.e-4F
#define ADC_RESOLUTION              4.8828125e-4F   // 12bit

extern int32 AIN0_CH1, AIN0_CH2, AIN0_CH3, AIN0_CH4;    // U4 ADC                   CH1 : AINPUT1,  CH2 : AINPUT2,  CH3 : AINPUT3,  CH4 : AINPUT4
extern int32 AIN1_CH1, AIN1_CH2, AIN1_CH3, AIN1_CH4;    // U11 ADC                  CH1 : AINPUT5,  CH2 : AINPUT6,  CH3 : AINPUT7,  CH4 : AINPUT8
extern int32 AIN2_CH1, AIN2_CH2, AIN2_CH3, AIN2_CH4;    // U15 ADC                  CH1 : AINPUT9,  CH2 : AINPUT10, CH3 : AINPUT11, CH4 : AINPUT12
extern int32 AIN3_CH1, AIN3_CH2, AIN3_CH3, AIN3_CH4;    // U19 ADC(AC_Voltage)      CH1 : AINPUT13, CH2 : AINPUT14, CH3 : AINPUT15, CH4 : AINPUT16

extern float V_AB_offset, V_BC_offset, V_CA_offset;
extern float V_DC_offset;
extern float I_DC_offset;
extern float I_AS_offset, I_BS_offset, I_CS_offset;
extern float I_AU_offset, I_BU_offset, I_CU_offset;
extern float I_AL_offset, I_BL_offset, I_CL_offset;


extern void ADC_OP(void);
extern void Init_ADC(void);
extern void ADC(void);
extern void ADC_Read(void);
interrupt void ADC_Offset(void);

#ifdef _cplusplus
}
#endif

#endif /* INCLUDES_DEFINE_ADC_H_ */
