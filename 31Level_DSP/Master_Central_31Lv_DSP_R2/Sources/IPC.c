/*
 * IPC.c
 *
 *  Created on: 2019. 1. 8.
 *      Author: subi
 */



#include "Define_Header.h"

Uint32 IPC_test[10];
#define IPC_WRITE        *((Uint32 *)(0x8E0033A4))
//IPC_FLAG1 A15 WR
//IPC_FLAG2 A15 RD
//IPC_FLAG3 DSP WR
//IPC_FLAG4 DSP RD
void IPC_DSP_Init(void){

}

