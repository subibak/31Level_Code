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
    IRAM_MEM	: o = 0x00800000 l = 0x00008000   /* 32kB internal SRAM */
    OCMC_RAM3	: o = 0x40500000 l = 0x00100000   /* 1MB L3 OCMC SRAM3 */
}

SECTIONS
{
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
}


