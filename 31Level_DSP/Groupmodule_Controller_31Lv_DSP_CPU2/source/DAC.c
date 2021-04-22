/*
 * DAC.c
 *
 *  Created on: 2018. 06. 19.
 *      Author: Subi
 */

#include "Define_Header.h"

S_DA da1, da2, da3, da4, da5, da6, da7, da8;

Uint16 da1_tmp = 0, da2_tmp = 0, da3_tmp = 0, da4_tmp = 0;
Uint16 da5_tmp = 0, da6_tmp = 0, da7_tmp = 0, da8_tmp = 0;
Uint16 temp = 0;

Uint16 da_sel = 0;

void DAC(void)
{
    switch (da_sel)
    {
    case 30:
        da1.out = &V_SMt[0];        da1.rng = 10;    da1.mid = 0;     da1.type = 0;
        da2.out = &V_SMt[1];        da2.rng = 10;    da2.mid = 0;     da2.type = 0;
        da3.out = &V_SMt[2];        da3.rng = 10;    da3.mid = 0;     da3.type = 0;
        da4.out = &Arm_Cur_A;       da4.rng = 10;    da4.mid = 0;     da4.type = 0;
        da_sel =  0;
        break;
    case 31:
        da1.out = &IPC_Temp_Vol[0].all;    da1.rng = 10;    da1.mid = 0;     da1.type = 0;
        da2.out = &IPC_Temp_Vol[1].all;    da2.rng = 10;    da2.mid = 0;     da2.type = 0;
        da3.out = &IPC_Temp_Vol[2].all;    da3.rng = 10;    da3.mid = 0;     da3.type = 0;
        da4.out = &IPC_Temp_Vol[3].all;    da4.rng = 10;    da4.mid = 0;     da4.type = 0;
        da_sel =  0;
        break;
    case 32:
        da1.out = &IPC_Temp_Vol[4].all;    da1.rng = 10;    da1.mid = 0;     da1.type = 0;
        da2.out = &IPC_Temp_Vol[5].all;    da2.rng = 10;    da2.mid = 0;     da2.type = 0;
        da3.out = &IPC_Temp_Vol[11].all;    da3.rng = 10;    da3.mid = 0;     da3.type = 0;
        da4.out = &IPC_Temp_Vol[10].all;    da4.rng = 10;    da4.mid = 0;     da4.type = 0;
        da_sel =  0;
        break;
    case 33:
        da1.out = &IPC_Temp_Vol[9].all;    da1.rng = 10;    da1.mid = 0;     da1.type = 0;
        da2.out = &IPC_Temp_Vol[8].all;    da2.rng = 10;    da2.mid = 0;     da2.type = 0;
        da3.out = &IPC_Temp_Vol[7].all;    da3.rng = 10;    da3.mid = 0;     da3.type = 0;
        da4.out = &IPC_Temp_Vol[6].all;    da4.rng = 10;    da4.mid = 0;     da4.type = 0;
        da_sel =  0;
        break;
    case 34:
        da1.out = &Arm_Cur_B;       da1.rng = 10;    da1.mid = 0;     da1.type = 0;
        da2.out = &V_SMt[5];        da2.rng = 10;    da2.mid = 0;     da2.type = 0;
        da3.out = &V_SMt[4];        da3.rng = 10;    da3.mid = 0;     da3.type = 0;
        da4.out = &V_SMt[3];        da4.rng = 10;    da4.mid = 0;     da4.type = 0;
        da_sel =  0;
        break;
    case 35:
        da1.out = &LED_case;       da1.rng = 10;    da1.mid = 0;     da1.type = 1;
        da2.out = &LED_case;       da2.rng = 10;    da2.mid = 0;     da2.type = 1;
        da3.out = &LED_case;       da3.rng = 10;    da3.mid = 0;     da3.type = 1;
        da4.out = &LED_case;       da4.rng = 10;    da4.mid = 0;     da4.type = 1;
        da_sel =  0;
        break;
    }

    da1_tmp = (Uint16)((int)((DA(1) - da1.mid) * DAC_RNG / da1.rng) + DAC_MID);
	da2_tmp = (Uint16)((int)((DA(2) - da2.mid) * DAC_RNG / da2.rng) + DAC_MID);
	da3_tmp = (Uint16)((int)((DA(3) - da3.mid) * DAC_RNG / da3.rng) + DAC_MID);
	da4_tmp = (Uint16)((int)((DA(4) - da4.mid) * DAC_RNG / da4.rng) + DAC_MID);


	da5_tmp = (Uint16)((int)((DA(5) - da5.mid) * DAC_RNG / da5.rng) + DAC_MID);
	da6_tmp = (Uint16)((int)((DA(6) - da6.mid) * DAC_RNG / da6.rng) + DAC_MID);
	da7_tmp = (Uint16)((int)((DA(7) - da7.mid) * DAC_RNG / da7.rng) + DAC_MID);
	da8_tmp = (Uint16)((int)((DA(8) - da8.mid) * DAC_RNG / da8.rng) + DAC_MID);

	DAC_out(1, da1_tmp);
	DAC_out(2, da2_tmp);
	DAC_out(3, da3_tmp);
	DAC_out(4, da4_tmp);
	DAC_out(5, da5_tmp);
	DAC_out(6, da6_tmp);
	DAC_out(7, da7_tmp);
	DAC_out(8, da8_tmp);

	*DAC_GEN = 0x0;
	return;
}

void DAC_out(Uint16 ch, Uint16 data)
{
	switch(ch)																// DA Out.
	{
		case 1:
			*DAC_A1_WR = (0x0000 | (data & DAC_EFF));
			break;

		case 2:
			*DAC_A2_WR = (0x4000 | (data & DAC_EFF));
			break;

		case 3:
			*DAC_A3_WR = (0x8000 | (data & DAC_EFF));
			break;

		case 4:
			*DAC_A4_WR = (0xC000 | (data & DAC_EFF));
			break;

		case 5:
			*DAC_A5_WR = (0x0000 | (data & DAC_EFF));
			break;

		case 6:
			*DAC_A6_WR = (0x4000 | (data & DAC_EFF));
			break;

		case 7:
			*DAC_A7_WR = (0x8000 | (data & DAC_EFF));
			break;

		case 8:
			*DAC_A8_WR = (0xC000 | (data & DAC_EFF));
			break;

		default: break;
	}

	return;
}




