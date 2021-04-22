/*
 * LED.c
 *
 *  Created on: 2017. 4. 21.
 *      Author: Seung Hwan
 *  Revised on: 2018. 9. 27.
 *      Reviser: subi
 */

#include "Define_Header.h"
#include "Define_LED.h"

#define LED_Time				1000		//100[ms] = 100[us] x 1000

Uint16 LED_cnt = 0;
int LED_case = 1;

void LED_DSP(void)
{
	static int LED_loop_cnt = 1, LEDcase = 0;

	if(LED_loop_cnt++ > LED_Time)
	{
		switch(LEDcase)
		{
		case 0:
			LED2_ON;	LEDcase++;		break;
		case 1:
			LED3_ON;	LEDcase++;		break;
		case 2:
			LED2_OFF;	LEDcase++;		break;
		default:
			LED3_OFF;	LEDcase = 0;	break;
		}

		LED_loop_cnt = 1;
	}



    return;
}

void LED_FPGA(void)
{

	if (LED_cnt++ >LED_Time)
	{

		*LED_FPGA_EN = LED_case;
		LED_case += 1;

		if (LED_case> 0x9)
		{
			LED_case = 0x01;

		}
		LED_cnt=0;

	}

	return;
}

