/*
 * Define_EMIF.h
 *
 *  Created on: 2020. 10. 10.
 *      Author: subi
 */

#ifndef INCLUDE_DEFINE_EMIF_H_
#define INCLUDE_DEFINE_EMIF_H_

// EMIF1
// cs0n 0x8000 0000 - 8FFF FFFF         // Data
//(Asynchronous memory access 2n, 3n, 4n)
// As the default values of ADDR in FPGA is 000 and FFF, do not use these effective addresses not to cause some malfunction.
// A0 takes on A1's bit and EM1BA1 takes A0's bit
// cs2n 0x0010 0000 - 002F FFFF         // Program + Data effective address FFF
// cs3n 0x0030 0000 - 0037 FFFF         // Program + Data
// cs4n 0x0038 0000 - 003D FFFF         // Program + Data

// EMIF2(EtherCAT)
// cs0n 0x9000 0000 - 91FF FFFF         // Data
// cs2n 0x0000 2000 - 0000 2FFF         // Program + Data



//extern function
extern void Init_Emif1(void);
extern void Init_Emif2(void);

#endif /* INCLUDE_DEFINE_EMIF_H_ */
