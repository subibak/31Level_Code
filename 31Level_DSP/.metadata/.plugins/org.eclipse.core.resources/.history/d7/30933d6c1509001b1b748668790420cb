/*
 * main.c
 */


#include "Define_Header.h"

void main(void) {

	Init_Flash();
	Init_Shared_Mem();

	DisableDog();

	Init_PLL();
	Init_PeripheralClocks();

	Init_CpuSelect();

	Init_GPIO();

	Init_PieCtrl();
	Init_PieVectTable();

	Init_Emif();
    Init_ADC();
	Init_Epwm();
	Init_Timer();

	LPF_Parameter();

	Start_PieCtrl();
	Start_PWM();

  	for(;;);
}

