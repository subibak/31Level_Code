/*
 * FPGA_GPIO.c
 *
 *  Created on: 2020. 10. 22.
 *      Author: subi
 */


#include <Define_Header.h>

#ifdef CPU2
Uint16 FPGA_LED_case = 0;
Uint16 FPGA_LED_cnt = 0;
#endif

#ifdef CPU2
void Init_LED_FPGA(void)
{
    FpgaCs2Regs.GPA.DIR.all =    GPIO0_DIR_OUTPUT  | GPIO1_DIR_OUTPUT
                               | GPIO2_DIR_OUTPUT  | GPIO3_DIR_OUTPUT
                               | GPIO4_DIR_OUTPUT  | GPIO4_DIR_OUTPUT
                               | GPIO6_DIR_OUTPUT  | GPIO7_DIR_OUTPUT
                               | GPIO8_DIR_OUTPUT  | GPIO9_DIR_OUTPUT
                               | GPIO10_DIR_OUTPUT | GPIO11_DIR_OUTPUT
                               | GPIO12_DIR_OUTPUT | GPIO13_DIR_OUTPUT
                               | GPIO14_DIR_OUTPUT | GPIO15_DIR_OUTPUT;

    FpgaCs2Regs.GPA.CLR.all = GPIO_ALL_CLR;

    return;
}
#endif

#ifdef CPU2
void LED_FPGA(void)
{
   if(++FPGA_LED_cnt > FPGA_LED_TIME)
   {
       switch(FPGA_LED_case)
       {
           case 0 : LED6_ON;   FPGA_LED_case++;    break;
           case 1 : LED5_ON;   FPGA_LED_case++;    break;
           case 2 : LED8_ON;   FPGA_LED_case++;    break;
           case 3 : LED7_ON;   FPGA_LED_case++;    break;
           case 4 : LED6_OFF;  FPGA_LED_case++;    break;
           case 5 : LED5_OFF;  FPGA_LED_case++;    break;
           case 6 : LED8_OFF;  FPGA_LED_case++;    break;
           case 7 : LED7_OFF;  FPGA_LED_case = 0;  break;
           default :    break;
       }

       FPGA_LED_cnt = 0;
   }

   return;
}
#endif
