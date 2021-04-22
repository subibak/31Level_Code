/*
 * GPIO.c
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 *  Revised on: 2018. 11. 19.
 *      Author: Subi
 */

#include "Define_Header.h"
#include "Define_GPIO.h"

void Init_GPIO(void)
{
//  when using the GPIO INPUT, Do no write this code

//    // GPIO1 module
//    GPIO1Regs.GPIO_SYSCONFIG.bit.SOFTRESET = 1;
//    while (GPIO1Regs.GPIO_SYSSTATUS.bit.RESETDONE == 0);
//
//    GPIO1Regs.GPIO_SYSCONFIG.bit.IDLEMODE = 1;
//    GPIO1Regs.GPIO_SYSCONFIG.bit.AUTOIDLE = 0;
//    GPIO1Regs.GPIO_OE.all &= ~(GPIO_GPIO6                      //GPMC_AD0
//                            | GPIO_GPIO7                       //GPMC_AD1
//                            | GPIO_GPIO8                       //GPMC_AD2
//                            | GPIO_GPIO9                       //GPMC_AD3
//                            | GPIO_GPIO10                      //GPMC_AD4
//                            | GPIO_GPIO11                      //GPMC_AD5
//                            | GPIO_GPIO12                      //GPMC_AD6
//                            | GPIO_GPIO13                      //GPMC_AD7
//                            | GPIO_GPIO18                      //GPMC_AD12
//                            | GPIO_GPIO19                      //GPMC_AD13
//                            | GPIO_GPIO20                      //GPMC_AD14
//                            | GPIO_GPIO21                      //GPMC_AD15
//                            | GPIO_GPIO26                      //GPMC_A4
//                            | GPIO_GPIO27                      //GPMC_A5
//                            | GPIO_GPIO28                      //GPMC_A6
//                            | GPIO_GPIO29                      //GPMC_A7
//                            | GPIO_GPIO30                      //GPMC_A8
//                            | GPIO_GPIO31);                    //GPMC_A9
    // GPIO2 module
    GPIO2Regs.GPIO_SYSCONFIG.bit.SOFTRESET = 1;
    while (GPIO2Regs.GPIO_SYSSTATUS.bit.RESETDONE == 0);

    GPIO2Regs.GPIO_SYSCONFIG.bit.IDLEMODE = 1;
    GPIO2Regs.GPIO_SYSCONFIG.bit.AUTOIDLE = 0;
    GPIO2Regs.GPIO_OE.all &= ~(//GPIO_GPIO22                     //GPMC_CLK  -> GPIO2_22
                              GPIO_GPIO23                      //GPMC_ADVn -> GPIO2_23
                            | GPIO_GPIO26);                      //GPMC_BEn0 -> GPIO2_26
//                            | GPIO_GPIO27);                    //GPMC_BEn1 -> GPIO2_27


    // GPIO3 module
	GPIO3Regs.GPIO_SYSCONFIG.bit.SOFTRESET = 1;
	while (GPIO3Regs.GPIO_SYSSTATUS.bit.RESETDONE == 0);

	GPIO3Regs.GPIO_SYSCONFIG.bit.IDLEMODE = 1;
	GPIO3Regs.GPIO_SYSCONFIG.bit.AUTOIDLE = 0;
	GPIO3Regs.GPIO_OE.all &= ~(GPIO_GPIO4                      //Digital output1, Relay_1
	                        | GPIO_GPIO5                       //Digital output2, Relay_2
	                        | GPIO_GPIO6                       //Digital output3, Relay_3
	                        | GPIO_GPIO7                       //Digital output4, Relay_4
	                        | GPIO_GPIO8                       //Expansion connector LED3 D21
                            | GPIO_GPIO10                      //STATUSLED1_RED
                            | GPIO_GPIO11                      //STATUSLED0_GREEN
                            | GPIO_GPIO12                      //STATUSLED0_YELLOW
	                        | GPIO_GPIO13                      //Expansion connector LED1 D22
	                        | GPIO_GPIO14                      //Expansion connector LED2 D23
	                        | GPIO_GPIO15);                    //Expansion connector LED4 D24
//	                        | GPIO_GPIO20                      //Digital input1
//	                        | GPIO_GPIO22                      //Digital input2
//	                        | GPIO_GPIO23                      //Digital input3
//	                        | GPIO_GPIO24                      //Digital input5
//	                        | GPIO_GPIO25);                    //Digital input6

    // GPIO4 module
    GPIO4Regs.GPIO_SYSCONFIG.bit.SOFTRESET = 1;
    while (GPIO4Regs.GPIO_SYSSTATUS.bit.RESETDONE == 0);

    GPIO4Regs.GPIO_SYSCONFIG.bit.IDLEMODE = 1;
    GPIO4Regs.GPIO_SYSCONFIG.bit.AUTOIDLE = 0;
    GPIO4Regs.GPIO_OE.all &= ~(GPIO_GPIO0);                     //STATUSLED0_RED

	// GPIO6 module
	GPIO6Regs.GPIO_SYSCONFIG.bit.SOFTRESET = 1;
	while (GPIO6Regs.GPIO_SYSSTATUS.bit.RESETDONE == 0);

	GPIO6Regs.GPIO_SYSCONFIG.bit.IDLEMODE = 1;
	GPIO6Regs.GPIO_SYSCONFIG.bit.AUTOIDLE = 0;
	GPIO6Regs.GPIO_OE.all &= ~(GPIO_GPIO15);                    //Check signal

	// GPIO7 module
	GPIO7Regs.GPIO_SYSCONFIG.bit.SOFTRESET = 1;
	while (GPIO7Regs.GPIO_SYSSTATUS.bit.RESETDONE == 0);

	GPIO7Regs.GPIO_SYSCONFIG.bit.IDLEMODE = 1;
	GPIO7Regs.GPIO_SYSCONFIG.bit.AUTOIDLE = 0;
	GPIO7Regs.GPIO_OE.all &= ~(GPIO_GPIO7                      // Check signal
	                        | GPIO_GPIO16                      // GPIO 7_16 : DAC_LOADn
                            | GPIO_GPIO22                      // STATUSLED1_YELLOW
							| GPIO_GPIO23);                    // STATUSLED1_GREEN

	return;
}
