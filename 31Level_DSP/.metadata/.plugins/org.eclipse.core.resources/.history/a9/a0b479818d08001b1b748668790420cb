/*
 * Define_Prototypes.h
 *
 *  Created on: 2018. 06. 19.
 *      Author: Subi
 */

#ifndef DEFINE_PROTOTYPES_H_
#define DEFINE_PROTOTYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "F2837xD/F2837xD_device.h"

extern void LED_DSP(void);
extern void LED_FPGA(void);

//ADC.c
interrupt void ADC_Offset(void);
extern void Init_ADC(void);
extern void ADC(void);
extern void ADC_Read(void);

//DAC.c
extern void DAC(void);
extern void DAC_out(Uint16,Uint16);

//Dual_core.c
extern void Init_CpuSelect(void);

//Emif.c
extern void Init_Emif(void);
extern void EMif1Initialize(void);

//ePWM.c
extern void Init_Epwm(void);
extern void Start_PWM(void);
extern void PWM1_out(float, float, float);
extern void PWM2_out(float, float, float);

//Fault.c
extern void Fault(void);

//GPIO.c
extern void Init_GPIO(void);

//MAIN_Interrupt.c
interrupt void Interrupt(void);

//LPF_Parameter.c
extern void LPF_Parameter(void);

//Sensor.c
extern void SM_Vol_Sensor(void);
extern void Temp_Sensor(void);
extern void Arm_Current_Sensor(void);
extern void Temp_Calc(float [], float [], int);

//Vol_Balance.c
extern void Bubble_sort(int, float[]);

//DAQ_RS422.c
//extern void DAQ_RS422_TXRX(void);
extern void DAQ_RS422(float [], float[], Uint16, Uint16);

//PWM.c
extern void PMW_INIT(void);
extern void GATING(Uint16 []);
extern void PD(int, int, int, Uint16, int [], Uint16 []);      //num_sm, current_dir, NLC, PWM, index, reference
extern void NLC(int, int, int, int [], Uint16 []);
extern void PSC(void);

//OPERATION_MODE.c
extern void OPERATION(void);
extern void PWM_METHOD(void);
extern void Reset(void);

//Group_module_test
extern void Bubble_t_sort(int, float[]);
extern void Open_Loop(void);

//Bypass.c
extern void BYPASSING(void);
//FAN.c
extern void FAN(void);
//SysCtrl.c
extern void Init_Shared_Mem(void);
extern void Init_PLL(void);
extern void Init_PeripheralClocks(void);
extern void Init_PieCtrl(void);
extern void Init_PieVectTable(void);
extern void Start_PieCtrl(void);
interrupt void ISR_Default(void);
extern void Init_Flash(void);

//Timer.c
extern void Init_Timer(void);
extern void Start_Timer(void);

//WatchDog.c
extern void DisableDog(void);

//                 CAUTION
// This function MUST be executed out of RAM. Executing it
// out of OTP/Flash will yield unpredictable results
extern void InitFlash(void);
extern void InitFlash_Bank0(void);
extern void InitFlash_Bank1(void);

//---------------------------------------------------------------------------
// External symbols created by the linker cmd file
// DSP28 examples will use these to relocate code from one LOAD location
// in Flash to a different RUN location in internal
// RAM
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsLoadSize;
extern Uint16 RamfuncsRunStart;
extern Uint16 RamfuncsRunEnd;
extern Uint16 RamfuncsRunSize;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif /* DEFINE_PROTOTYPES_H_ */
