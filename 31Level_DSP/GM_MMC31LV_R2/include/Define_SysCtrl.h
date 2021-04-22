/*
 * Define_SysCtrl.h
 *
 *  Created on: 2015. 8. 13.
 *      Author: cjs9426
 *  Revised on: 2020. 10. 10.
 *     Reviser: subi
 */

#ifndef DEFINE_SYSCTRL_H_
#define DEFINE_SYSCTRL_H_

#define CPU_RATE 5.000000L

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

extern void F28x_usDelay(long LoopCount);
// DO NOT MODIFY THIS LINE.
#define DELAY_US(A)  F28x_usDelay(((((long double) A * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 5.0L)

// extern function
#ifdef CPU1
extern void Init_PLL(void);
extern void Init_GSMem_Sel(void);
#endif

extern void Init_Mem(void);
extern void Init_PeripheralClocks(void);
extern void Init_PieCtrl(void);
extern void Init_PieVectTable(void);
extern void Start_PieCtrl(void);
interrupt void ISR_Default(void);
extern void Init_Flash(void);


// This function MUST be executed out of RAM. Executing it
// out of OTP/Flash will yield unpredictable results
extern void InitFlash(void);
extern void InitFlash_Bank0(void);
extern void InitFlash_Bank1(void);

#endif /* DEFINE_SYSCTRL_H_ */
