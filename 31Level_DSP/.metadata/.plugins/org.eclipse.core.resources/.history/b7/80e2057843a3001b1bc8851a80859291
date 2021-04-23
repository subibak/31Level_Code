/*
 * DAC.c
 *
 *  Created on: 2018. 12. 15.
 *      Author: subi
 */


#include "Define_Header.h"

S_DA da1, da2, da3, da4;
Uint16 da_sel = 1U;
Uint16 da1_tmp = 0U, da2_tmp = 0U, da3_tmp = 0U, da4_tmp = 0U;

void DAC(void)
{
    switch (da_sel)
    {
    case 1:
        da1.out = &I_AS;   da1.rng = 24;   da1.mid = 0;    da1.type = 0;
        da2.out = &I_BS;   da2.rng = 24;   da2.mid = 0;    da2.type = 0;
        da3.out = &I_CS;   da3.rng = 24;   da3.mid = 0;    da3.type = 0;
        da4.out = &IM1qe;   da4.rng = 24;   da4.mid = 0;    da4.type = 0;
        da_sel = 0U;
        break;
    default: break;
    }
//    da1.out = &I_AS;
//    da1.mid = 0;
//    da1.rng = 24;
//    da1.type = 1;
//
//    da2.out = &I_BS;
//    da2.mid = 0;
//    da2.rng = 24;
//    da2.type = 1;
//
//    da3.out = &I_CS;
//    da3.mid = 0;
//    da3.rng = 24;
//    da3.type = 1;
//
//    da4.out = &IM1qe;
//    da4.mid = 0;
//    da4.rng = 24;
//    da4.type = 1;

//    da1_tmp = (Uint16)((int16)((I_AS) * DAC_RNG / 24) + DAC_MID);
//    da2_tmp = (Uint16)((int16)((I_BS) * DAC_RNG / 24) + DAC_MID);
//    da3_tmp = (Uint16)((int16)((I_CS) * DAC_RNG / 24) + DAC_MID);
//    da4_tmp = (Uint16)((int16)((IM1qe) * DAC_RNG / 24) + DAC_MID);
//
    da1_tmp = (Uint16)((int16)((DA(1) - da1.mid) * DAC_RNG / da1.rng) + DAC_MID);
    da2_tmp = (Uint16)((int16)((DA(2) - da2.mid) * DAC_RNG / da2.rng) + DAC_MID);
    da3_tmp = (Uint16)((int16)((DA(3) - da3.mid) * DAC_RNG / da3.rng) + DAC_MID);
    da4_tmp = (Uint16)((int16)((DA(4) - da4.mid) * DAC_RNG / da4.rng) + DAC_MID);

    DAC_out(0U, da1_tmp);
    DAC_out(1U, da2_tmp);
    DAC_out(2U, da3_tmp);
    DAC_out(3U, da4_tmp);

    return;
}

void DAC_out(Uint16 ch, Uint32 data)
{
//    while(McSPI2Regs.MCSPI_CH0STAT.bit.TXS == 1);

    switch(ch)
    {
        case 0: McSPI2Regs.MCSPI_TX0.all = (0x00000000 | (data & DAC_EFF)); break;
        case 1: McSPI2Regs.MCSPI_TX0.all = (0x00004000 | (data & DAC_EFF)); break;
        case 2: McSPI2Regs.MCSPI_TX0.all = (0x00008000 | (data & DAC_EFF)); break;
        case 3: McSPI2Regs.MCSPI_TX0.all = (0x0000C000 | (data & DAC_EFF)); break;
        default: break;
    }

    while(McSPI2Regs.MCSPI_CH0STAT.bit.TXFFE == 0)
    {
        DAC_LOAD_HIGH;
    };

    DAC_LOAD_LOW;


    return;
}
