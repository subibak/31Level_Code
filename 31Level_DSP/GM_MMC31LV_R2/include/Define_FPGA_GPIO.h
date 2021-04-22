/*
 * Define_FPGA_GPIO.h
 *
 *  Created on: 2020. 10. 22.
 *      Author: subi
 */

#ifndef INCLUDE_DEFINE_FPGA_GPIO_H_
#define INCLUDE_DEFINE_FPGA_GPIO_H_

#ifdef CPU2
#define FPGA_LED_TIME               500

#define GPIO0_DIR_INPUT             0x0000
#define GPIO1_DIR_INPUT             0x0000
#define GPIO2_DIR_INPUT             0x0000
#define GPIO3_DIR_INPUT             0x0000
#define GPIO4_DIR_INPUT             0x0000
#define GPIO5_DIR_INPUT             0x0000
#define GPIO6_DIR_INPUT             0x0000
#define GPIO7_DIR_INPUT             0x0000
#define GPIO8_DIR_INPUT             0x0000
#define GPIO9_DIR_INPUT             0x0000
#define GPIO10_DIR_INPUT            0x0000
#define GPIO11_DIR_INPUT            0x0000
#define GPIO12_DIR_INPUT            0x0000
#define GPIO13_DIR_INPUT            0x0000
#define GPIO14_DIR_INPUT            0x0000
#define GPIO15_DIR_INPUT            0x0000

#define GPIO0_DIR_OUTPUT            0x0001
#define GPIO1_DIR_OUTPUT            0x0002
#define GPIO2_DIR_OUTPUT            0x0004
#define GPIO3_DIR_OUTPUT            0x0008
#define GPIO4_DIR_OUTPUT            0x0010
#define GPIO5_DIR_OUTPUT            0x0020
#define GPIO6_DIR_OUTPUT            0x0040
#define GPIO7_DIR_OUTPUT            0x0080
#define GPIO8_DIR_OUTPUT            0x0100
#define GPIO9_DIR_OUTPUT            0x0200
#define GPIO10_DIR_OUTPUT           0x0400
#define GPIO11_DIR_OUTPUT           0x0800
#define GPIO12_DIR_OUTPUT           0x1000
#define GPIO13_DIR_OUTPUT           0x2000
#define GPIO14_DIR_OUTPUT           0x4000
#define GPIO15_DIR_OUTPUT           0x8000

#define GPIO0_SET                   0x0001
#define GPIO1_SET                   0x0002
#define GPIO2_SET                   0x0004
#define GPIO3_SET                   0x0008
#define GPIO4_SET                   0x0010
#define GPIO5_SET                   0x0020
#define GPIO6_SET                   0x0040
#define GPIO7_SET                   0x0080
#define GPIO8_SET                   0x0100
#define GPIO9_SET                   0x0200
#define GPIO10_SET                  0x0400
#define GPIO11_SET                  0x0800
#define GPIO12_SET                  0x1000
#define GPIO13_SET                  0x2000
#define GPIO14_SET                  0x4000
#define GPIO15_SET                  0x8000

#define GPIO0_CLR                   0x0001
#define GPIO1_CLR                   0x0002
#define GPIO2_CLR                   0x0004
#define GPIO3_CLR                   0x0008
#define GPIO4_CLR                   0x0010
#define GPIO5_CLR                   0x0020
#define GPIO6_CLR                   0x0040
#define GPIO7_CLR                   0x0080
#define GPIO8_CLR                   0x0100
#define GPIO9_CLR                   0x0200
#define GPIO10_CLR                  0x0400
#define GPIO11_CLR                  0x0800
#define GPIO12_CLR                  0x1000
#define GPIO13_CLR                  0x2000
#define GPIO14_CLR                  0x4000
#define GPIO15_CLR                  0x8000

#define GPIO_ALL_CLR                0xFFFF
#define GPIO_ALL_SET                0xFFFF

#define LED6_ON                     FpgaCs2Regs.GPA.SET.all |= GPIO0_SET
#define LED5_ON                     FpgaCs2Regs.GPA.SET.all |= GPIO1_SET
#define LED8_ON                     FpgaCs2Regs.GPA.SET.all |= GPIO2_SET
#define LED7_ON                     FpgaCs2Regs.GPA.SET.all |= GPIO3_SET
#define LED6_OFF                    FpgaCs2Regs.GPA.CLR.all |= GPIO0_CLR
#define LED5_OFF                    FpgaCs2Regs.GPA.CLR.all |= GPIO1_CLR
#define LED8_OFF                    FpgaCs2Regs.GPA.CLR.all |= GPIO2_CLR
#define LED7_OFF                    FpgaCs2Regs.GPA.CLR.all |= GPIO3_CLR

#define LED_ON                      ((volatile int *)(0x00100002))
#define LED_OFF                     ((volatile int *)(0x00100003))

extern void Init_LED_FPGA(void);
extern void LED_FPGA(void);
#endif

#endif /* INCLUDE_DEFINE_FPGA_GPIO_H_ */
