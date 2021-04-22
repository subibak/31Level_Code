/*
 * FPGA.c
 *
 *  Created on: 2018. 9. 22.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_FPGA.h"

#ifdef CPU1
#ifdef __cplusplus
#pragma DATA_SECTION("FpgaCs2RegsFile")
#else
#pragma DATA_SECTION(FpgaCs2Regs, "FpgaCs2RegsFile");
#endif
volatile struct FPGA_CS2_REGS FpgaCs2Regs;
#endif
