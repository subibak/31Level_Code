/*
 * Define_D_IO.h
 *
 *  Created on: 2019. 1. 12.
 *      Author: subi
 */

#ifndef INCLUDES_DEFINE_D_IO_H_
#define INCLUDES_DEFINE_D_IO_H_

#ifdef __cplusplus
extern "C" {
#endif\

#define XF1_ON         GPIO6Regs.GPIO_SETDATAOUT.all     = GPIO_GPIO15
#define XF1_OFF        GPIO6Regs.GPIO_CLEARDATAOUT.all   = GPIO_GPIO15
#define XF2_ON         GPIO7Regs.GPIO_SETDATAOUT.all     = GPIO_GPIO7
#define XF2_OFF        GPIO7Regs.GPIO_CLEARDATAOUT.all   = GPIO_GPIO7

#define PRE_MC_OFF     GPIO3Regs.GPIO_SETDATAOUT.all     = GPIO_GPIO4               // RELAY1 OFF
#define PRE_MC_ON      GPIO3Regs.GPIO_CLEARDATAOUT.all   = GPIO_GPIO4               // RELAY1 ON
#define MAIN_MC_OFF    GPIO3Regs.GPIO_SETDATAOUT.all     = GPIO_GPIO5               // RELAY2 OFF
#define MAIN_MC_ON     GPIO3Regs.GPIO_CLEARDATAOUT.all   = GPIO_GPIO5               // RELAY2 ON
#define RELAY3_OFF     GPIO3Regs.GPIO_SETDATAOUT.all     = GPIO_GPIO6               // RELAY3 OFF
#define RELAY3_ON      GPIO3Regs.GPIO_CLEARDATAOUT.all   = GPIO_GPIO6               // RELAY3 ON
#define RELAY4_OFF     GPIO3Regs.GPIO_SETDATAOUT.all     = GPIO_GPIO7               // RELAY4 OFF
#define RELAY4_ON      GPIO3Regs.GPIO_CLEARDATAOUT.all   = GPIO_GPIO7               // RELAY4 ON

//This is the basic definition of DI. Follow this sequence
//#define DI1            GPIO3Regs.GPIO_DATAIN.bit.IO20;
//#define DI2            GPIO3Regs.GPIO_DATAIN.bit.IO22;
//#define DI3            GPIO3Regs.GPIO_DATAIN.bit.IO23;
//#define DI4            GPIO6Regs.GPIO_DATAIN.bit.IO14;
//#define DI5            GPIO3Regs.GPIO_DATAIN.bit.IO24;
//#define DI6            GPIO3Regs.GPIO_DATAIN.bit.IO25;

#define MAIN_MC_STATE   GPIO3Regs.GPIO_DATAIN.bit.IO20;     // 1 : off, 0 : on
#define PRE_MC_STATE    GPIO3Regs.GPIO_DATAIN.bit.IO22;     // 1 : off, 0 : on
#define MAIN_MCCB_STATE GPIO3Regs.GPIO_DATAIN.bit.IO23;     // 1 : off, 0 : on
#define DI4             GPIO6Regs.GPIO_DATAIN.bit.IO14;
#define UPS_STATE       GPIO3Regs.GPIO_DATAIN.bit.IO24;     // 1 : Battery off, 0 : Battery on
#define DI6             GPIO3Regs.GPIO_DATAIN.bit.IO25;
extern void MC_OP(void);
extern void MC_OP_Inv(void);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDES_DEFINE_D_IO_H_ */
