/****************************************************************************/
/*  AM57xx_C66.cmd                                                          */
/*  Copyright (c) 2015  Texas Instruments Incorporated                      */
/*  Author: Rafael de Souza                                                 */
/*  Revised: Subi                                                                        */
/*                                                                          */
/*    Description: This file is a sample linker command file that can be    */
/*                 used for linking programs built with the C compiler and  */
/*                 running the resulting .out file on the C66x DSP core of  */
/*                 an AM57xx device.                                        */
/*                 Use it as a guideline.  You will want to                 */
/*                 change the memory layout to match your specific          */
/*                 target system.  You may want to change the allocation    */
/*                 scheme according to the size of your program.            */
/*                                                                          */
/****************************************************************************/

MEMORY
{

    DSP_L2		: o = 0x00800000 l = 0x00048000		/* 288 kB internal DSP L2 SRAM */
    DSP_L1P		: o = 0x00E00000 l = 0x00008000		/* 32 kB DSP L1P SRAM */
    DSP_L1D		: o = 0x00F00000 l = 0x00008000		/* 32 kB DSP L1D SRAM */



//	IRAM_MEM	: o = 0x00800000 l = 0x00008000		/* 32kB internal SRAM */


//	OCMC_RAM1	: o = 0x40300000 l = 0x00010000	  	/* 512 kB L3 OCMC SRAM1 */
//  OCMC_RAM2	: o = 0x40400000 l = 0x00100000	  	/* 1MB L3 OCMC SRAM2 */
//  OCMC_RAM3	: o = 0x40500000 l = 0x00100000		/* 1MB L3 OCMC SRAM3 */

}

SECTIONS
{

    .text		> DSP_L2
    .cinit		> DSP_L2
    .stack		> DSP_L2
	.far        > DSP_L2
	.bss		> DSP_L2
	.rodata		> DSP_L2

    .vects		> DSP_L2
    .l2_int		> DSP_L2
    .switch		> DSP_L2
    .fardata	> DSP_L2
    .neardata	> DSP_L2
/*
    .text		> OCMC_RAM3
    .cinit		> OCMC_RAM3
    .stack		> OCMC_RAM3
	.far        > OCMC_RAM3
	.bss		> OCMC_RAM3
	.rodata		> OCMC_RAM3

    .vects		> IRAM_MEM
    .l2_int		> IRAM_MEM
    .switch		> OCMC_RAM3
    .fardata	> OCMC_RAM3
    .neardata	> OCMC_RAM3
*/
}


