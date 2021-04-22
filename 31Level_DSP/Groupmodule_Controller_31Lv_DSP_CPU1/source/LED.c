/*
 * LED.c
 *
 *  Created on: 2017. 4. 21.
 *      Author: Seung Hwan
 *  Revised on: 2018. 9. 26.
 *      Reviser: subi
 */

#include "Define_Header.h"
#include "Define_LED.h"

#define LED_Time				2000		//100[ms] = 100[us] x 1000

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
			LED0_ON;	LEDcase++;		break;
		case 1:
			LED1_ON;	LEDcase++;		break;
		case 2:
			LED0_OFF;	LEDcase++;		break;
		default:
            LED1_OFF;   LEDcase = 0;    break;
		}

		LED_loop_cnt = 1;
	}

	return;
}
