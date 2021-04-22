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
// Include header files
#include "F2837xD/F2837xD_device.h"

extern void LED_DSP(void);

//Dual_core.c
extern void Init_CpuSelect(void);

//Emif.c
extern void Init_Emif(void);
extern void EMif1Initialize(void);

//ePWM.c
extern void Init_Epwm(void);
extern void Start_PWM(void);

//GPIO.c
extern void Init_GPIO(void);

//MAIN_Interrupt.c
interrupt void Interrupt(void);

//SysCtrl.c
extern void Init_Mem(void);
extern void Init_PLL(void);
extern void Init_PeripheralClocks(void);
extern void Init_PieCtrl(void);
extern void Init_PieVectTable(void);
extern void Start_PieCtrl(void);
interrupt void ISR_Default(void);
extern void Init_Flash(void);

//IPC.c
#ifdef CPU1
// CPU1 Prototype Define
//// CPU1 Prototype Define : IPC
extern Uint16 IPCBootCPU2(Uint32);
extern void IPCWrite32bitProtect(Uint32, Uint32);

#endif

extern void CPU_Msg_Read(Uint16 EtherCAT_Msg_RD[]);
extern void CPU_Msg_Write(Uint16 EtherCAT_Msg_WR[]);

//Timer.c
extern void Init_Timer(void);
extern void Start_Timer(void);

//WatchDog.c
extern void DisableDog(void);

//Sensor.c
//extern void Temp_Calc(void);
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
