/*
 * LED.c
 *
 *  Created on: 2015. 4. 21.
 *     Power Conversion Lab, Pusan Univ, Korea.
 */

#include "Define_Header.h"

#define LED_Time	1000		// 100[ms] = 100[us] x 1000

Uint16 LED_cnt = 0;
int LED_case = 1;

void LED(void)
{
	if(++LED_cnt > LED_Time)
	{
		switch(LED_case)
		{
			case 1 :
				*LED_WR_ADDR = 0x0001;
				LED_case += 1;
				break;
			case 2 :
				*LED_WR_ADDR = 0x0002;
				LED_case += 1;
				break;
			case 3 :
				*LED_WR_ADDR = 0x0004;
				LED_case += 1;
				break;
			case 4 :
				*LED_WR_ADDR = 0x0008;
				LED_case = 1;
				break;
			}

		LED_cnt = 0;
	}

	return;
}
