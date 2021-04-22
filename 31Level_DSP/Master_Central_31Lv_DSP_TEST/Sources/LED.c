/*
 * LED.c
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 *  Revised on: 2018. 11. 19.
 *      Author: Subi
 */

#include "Define_Header.h"

Uint16 LEDCount = 1, LEDCase = 0;

void LED(void)
{

    if (LEDCount++ >= (LEDCOUNT_MAX-1))
	{
        switch (LEDCase)
        {
                case 0: STATUSLED0_RED_ON;      EXPANSION_LED1_ON;    LED_FPGA_EN_CS0 = LEDCase;    LEDCase++;     break;
                case 1: STATUSLED1_RED_ON;      EXPANSION_LED2_ON;    LED_FPGA_EN_CS0 = LEDCase;    LEDCase++;     break;
                case 2: STATUSLED0_YELLOW_ON;   EXPANSION_LED3_ON;    LED_FPGA_EN_CS0 = LEDCase;    LEDCase++;     break;
                case 3: STATUSLED1_YELLOW_ON;   EXPANSION_LED4_ON;    LED_FPGA_EN_CS0 = LEDCase;    LEDCase++;     break;
                case 4: STATUSLED0_RED_OFF;     EXPANSION_LED1_OFF;   LED_FPGA_EN_CS0 = LEDCase;    LEDCase++;     break;
                case 5: STATUSLED1_RED_OFF;     EXPANSION_LED2_OFF;   LED_FPGA_EN_CS0 = LEDCase;    LEDCase++;     break;
                case 6: STATUSLED0_YELLOW_OFF;  EXPANSION_LED3_OFF;   LED_FPGA_EN_CS0 = LEDCase;    LEDCase++;     break;
                default:STATUSLED1_YELLOW_OFF;  EXPANSION_LED4_OFF;   LED_FPGA_EN_CS0 = LEDCase;    LEDCase = 0;   break;
        }

        LEDCount = 1;
	}
}



//switch (LEDCase)
//        {
//        case 0: STATUSLED0_RED_ON;      EXPANSION_LED1_ON;    LED_FPGA_EN_CS3 = LEDCase;    LEDCase++;     break;
//        case 1: STATUSLED1_RED_ON;      EXPANSION_LED2_ON;    LED_FPGA_EN_CS3 = LEDCase;    LEDCase++;     break;
//        case 2: STATUSLED0_YELLOW_ON;   EXPANSION_LED3_ON;    LED_FPGA_EN_CS3 = LEDCase;    LEDCase++;     break;
//        case 3: STATUSLED1_YELLOW_ON;   EXPANSION_LED4_ON;    LED_FPGA_EN_CS3 = LEDCase;    LEDCase++;     break;
//        case 4: STATUSLED0_RED_OFF;     EXPANSION_LED1_OFF;   LED_FPGA_EN_CS3 = LEDCase;    LEDCase++;     break;
//        case 5: STATUSLED1_RED_OFF;     EXPANSION_LED2_OFF;   LED_FPGA_EN_CS3 = LEDCase;    LEDCase++;     break;
//        case 6: STATUSLED0_YELLOW_OFF;  EXPANSION_LED3_OFF;   LED_FPGA_EN_CS3 = LEDCase;    LEDCase++;     break;
//        default:STATUSLED1_YELLOW_OFF;  EXPANSION_LED4_OFF;   LED_FPGA_EN_CS3 = LEDCase;    LEDCase = 0;   break;
//
