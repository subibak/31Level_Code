/*
 * FPGA_GlobalVariableDefs.c
 *
 *  Created on: 2020. 10. 17.
 *      Author: subi
 */

#include "FPGA_device.h"


// EMIF1 Chip Selection 2(CS2) Variables
#ifdef CPU2
#pragma DATA_SECTION(FpgaCs2Regs,"FpgaCs2RegsFile");
volatile struct FPGA_CS2_REGS FpgaCs2Regs;
#endif
