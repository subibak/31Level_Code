/*
 * Define_Prototypes.h
 *
 *  Created on: 2012. 8. 8.
 *      Author: HJHeo
 */

#ifndef DEFINE_PROTOTYPES_H_
#define DEFINE_PROTOTYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

// ADC.c
extern void Init_ADC(void);
extern void ADC(void);
extern void ADC_Read(void);
interrupt void ADC_Offset(void);
extern void offset_test(void);
extern void ADC_test(void);

// DAC.c
extern void DAC(void);
extern void DAC_out(Uint16, Uint16);
extern void M1_vf(void);

// DSP2834x_usDelay.asm
extern void DSP28x_usDelay(Uint32 Count);	// Time Delay

// ePWM.c
extern void Init_PWM(void);
extern void Start_PWM(void);				// PWM Time Base Start
extern void PWM1_out(float, float, float);	//
extern void PWM2_out(float, float, float);	//

// eQEP.c
//extern void Init_QEP(void);
//extern void Position(void);
//extern void M_Method(void);

// Fault.c
extern void Fault(void);

// GPIO.c
extern void Init_GPIO(void);

// Interrupt.c
interrupt void Interrupt(void);

// M1 Inverter.c
//extern void M1_Inverter(void);
//extern void M1_align(void);
//extern void M1_current(void);
//extern void M1_speed(void);
//extern void M1_reset(void);
//extern void Speed(void);
//extern void Vf(void);

extern void MMC(void);
extern void Current_Con(void);
extern void Current_Inv(void);
extern void Reset(void);
extern void PLL(void);
extern void MMC_open(void);
extern void Converter_voltage(void);
extern void SuppCirCurrent(void);
extern void Compensation(void);
extern void Indirect_Modu_Con(void);
extern void Indirect_Modu_Inv(void);
extern void Energy_Cal(void);
extern void Leg_Energy_Balance(void);
extern void Commom_Energy_Balance(void);
extern void Diff_Energy_Balance_Con(void);
extern void Diff_Energy_Balance_Inv(void);
extern void Energy_diff_PIR(void);

// LED.c
extern void LED(void);
extern void LED1(void);

// LPF_Parameter.c
extern void LPF_Parameter(void);

// Sensor.c
extern void Voltage_Sensor(void);
extern void Current_Sensor(void);

// SPI.c
extern void Init_SPI(void);

// SCI.c
extern void Init_SCI(void);
extern void SCIB_TX(int);
extern int SCIB_RX(void);
extern void REF_RX(void);

// SysCtrl.c
extern void Init_PLL(void);
extern void Init_PeripheralClocks(void);
extern void Init_PieCtrl(void);
extern void Start_PieCtrl(void);
extern void Init_PieVectTable(void);
interrupt void ISR_Default(void);			// Default Interrupt Function

// WatchDog.c
extern void ResetDog(void);					// Enable & Reset WatchDog
extern void DisableDog(void);				// Disable WatchDog

// Xintf.c
extern void Init_Xintf(void);
// pwm_test.c
extern void Gating(void);
extern void PWM(void);
extern void SVPWM(void);
extern void Inverter(void);
extern void PD_MOD(void);

// CAN.c
extern void Init_CAN(void);
extern void CAN_TX_FaultA(void);
extern void CAN_TX_FaultB(void);
extern void CAN_TX_FaultC(void);
extern void CAN_RX_Init_Fault(void);
extern void CAN_RX_Balance(void);
extern void CAN_TX_STM(void);
extern void CAN_RX_STM(void);

//
extern void Balance(void);
extern void Bubble_sort(void);


// pwm
extern void PD_MOD(void);
extern void Gating_Allocation(float I_arm, float Vxn_ref_norm, int SM_INDEX[], Uint16 SM_REF[]);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* DEFINE_PROTOTYPES_H_ */
