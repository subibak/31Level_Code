/*
 * MemConfig.c
 *
 *  Created on: 2019. 6. 22.
 *      Author: HJHeo
 */

#include "Define_Header.h"
#include "Define_MemConfig.h"

void Init_RAM(void)
{
	EALLOW;

	// Dx Memory Initializing.
	//// Dx Memory Initializing : Dx Access Enable.
	MemCfgRegs.DxACCPROT0.all = DxACCPROT0_CPUWRPROT_D1_CPUWriteEn			// 25	: CPUWRPROT_D1	; 0(CPU Write Enable), 1(CPU Write Disable).
							| DxACCPROT0_FETCHPROT_D1_CPUFetchEn			// 24	: FETCHPROT_D1	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| DxACCPROT0_CPUWRPROT_D0_CPUWriteEn			// 17	: CPUWRPROT_D0	; 0(CPU Write Enable), 1(CPU Write Disable).
							| DxACCPROT0_FETCHPROT_D0_CPUFetchEn;			// 16	: FETCHPROT_D0	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).

	// LSx Memory Initializing.
	//// LSx Memory Initializing : LSx Master Selection.
	MemCfgRegs.LSxMSEL.all = LSxMSEL_MSEL_LS5_OnlyCPU						// 11-10: MSEL_LS5		; 00(CPU), 01(CPU and CLA1).
							| LSxMSEL_MSEL_LS4_OnlyCPU						// 9-8	: MSEL_LS4		; 00(CPU), 01(CPU and CLA1).
							| LSxMSEL_MSEL_LS3_OnlyCPU						// 7-6	: MSEL_LS3		; 00(CPU), 01(CPU and CLA1).
							| LSxMSEL_MSEL_LS2_OnlyCPU						// 5-4	: MSEL_LS2		; 00(CPU), 01(CPU and CLA1).
							| LSxMSEL_MSEL_LS1_OnlyCPU						// 3-2	: MSEL_LS1		; 00(CPU), 01(CPU and CLA1).
							| LSxMSEL_MSEL_LS0_OnlyCPU;						// 1-0	: MSEL_LS0		; 00(CPU), 01(CPU and CLA1).

	//// LSx Memory Initializing : LSx Access Enable.
	MemCfgRegs.LSxACCPROT1.all = LSxACCPROT1_CPUWRPROT_LS5_CPUWriteEn		// 9	: CPUWRPROT_LS5	; 0(CPU Write Enable), 1(CPU Write Disable).
							| LSxACCPROT1_FETCHPROT_LS5_CPUFetchEn			// 8	: FETCHPROT_LS5	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| LSxACCPROT1_CPUWRPROT_LS4_CPUWriteEn			// 1	: CPUWRPROT_LS4	; 0(CPU Write Enable), 1(CPU Write Disable).
							| LSxACCPROT1_FETCHPROT_LS4_CPUFetchEn;			// 0	: FETCHPROT_LS4	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
	MemCfgRegs.LSxACCPROT0.all = LSxACCPROT0_CPUWRPROT_LS3_CPUWriteEn		// 25	: CPUWRPROT_LS3	; 0(CPU Write Enable), 1(CPU Write Disable).
							| LSxACCPROT0_FETCHPROT_LS3_CPUFetchEn			// 24	: FETCHPROT_LS3	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| LSxACCPROT0_CPUWRPROT_LS2_CPUWriteEn			// 17	: CPUWRPROT_LS2	; 0(CPU Write Enable), 1(CPU Write Disable).
							| LSxACCPROT0_FETCHPROT_LS2_CPUFetchEn			// 16	: FETCHPROT_LS2	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| LSxACCPROT0_CPUWRPROT_LS1_CPUWriteEn			// 9	: CPUWRPROT_LS1	; 0(CPU Write Enable), 1(CPU Write Disable).
							| LSxACCPROT0_FETCHPROT_LS1_CPUFetchEn			// 8	: FETCHPROT_LS1	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| LSxACCPROT0_CPUWRPROT_LS0_CPUWriteEn			// 1	: CPUWRPROT_LS0	; 0(CPU Write Enable), 1(CPU Write Disable).
							| LSxACCPROT0_FETCHPROT_LS0_CPUFetchEn;			// 0	: FETCHPROT_LS0	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).

	//// LSx Memory Initializing : CLA Memory Configuration.
	MemCfgRegs.LSxCLAPGM.all = LSxCLAPGM_CLAPGM_LS5_CLAData					// 5	: CLAPGM_LS5	; 0(CLA Data), 1(CLA Program).
							| LSxCLAPGM_CLAPGM_LS4_CLAData					// 4	: CLAPGM_LS4	; 0(CLA Data), 1(CLA Program).
							| LSxCLAPGM_CLAPGM_LS3_CLAData					// 3	: CLAPGM_LS3	; 0(CLA Data), 1(CLA Program).
							| LSxCLAPGM_CLAPGM_LS2_CLAData					// 2	: CLAPGM_LS2	; 0(CLA Data), 1(CLA Program).
							| LSxCLAPGM_CLAPGM_LS1_CLAData					// 1	: CLAPGM_LS1	; 0(CLA Data), 1(CLA Program).
							| LSxCLAPGM_CLAPGM_LS0_CLAData;					// 0	: CLAPGM_LS0	; 0(CLA Data), 1(CLA Program).

#ifdef CPU1
	//// GSx Memory Initializing : GSx Access Enable.
	MemCfgRegs.GSxACCPROT3.all = GSxACCPROT3_DMAWRPROT_GS15_DMAWriteDis		// 26	: DMAWRPROT_GS15; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT3_CPUWRPROT_GS15_CPUWriteDis		// 25	: CPUWRPROT_GS15; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT3_FETCHPROT_GS15_CPUFetchDis		// 24	: FETCHPROT_GS15; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT3_DMAWRPROT_GS14_DMAWriteDis		// 18	: DMAWRPROT_GS14; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT3_CPUWRPROT_GS14_CPUWriteDis		// 17	: CPUWRPROT_GS14; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT3_FETCHPROT_GS14_CPUFetchDis		// 16	: FETCHPROT_GS14; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT3_DMAWRPROT_GS13_DMAWriteDis		// 10	: DMAWRPROT_GS13; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT3_CPUWRPROT_GS13_CPUWriteDis		// 9	: CPUWRPROT_GS13; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT3_FETCHPROT_GS13_CPUFetchDis		// 8	: FETCHPROT_GS13; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT3_DMAWRPROT_GS12_DMAWriteDis		// 2	: DMAWRPROT_GS12; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT3_CPUWRPROT_GS12_CPUWriteDis		// 1	: CPUWRPROT_GS12; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT3_FETCHPROT_GS12_CPUFetchDis;		// 0	: FETCHPROT_GS12; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
	MemCfgRegs.GSxACCPROT2.all = GSxACCPROT2_DMAWRPROT_GS11_DMAWriteDis		// 26	: DMAWRPROT_GS11; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT2_CPUWRPROT_GS11_CPUWriteDis		// 25	: CPUWRPROT_GS11; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT2_FETCHPROT_GS11_CPUFetchDis		// 24	: FETCHPROT_GS11; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT2_DMAWRPROT_GS10_DMAWriteDis		// 18	: DMAWRPROT_GS10; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT2_CPUWRPROT_GS10_CPUWriteDis		// 17	: CPUWRPROT_GS10; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT2_FETCHPROT_GS10_CPUFetchDis		// 16	: FETCHPROT_GS10; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT2_DMAWRPROT_GS9_DMAWriteDis			// 10	: DMAWRPROT_GS9	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT2_CPUWRPROT_GS9_CPUWriteDis			// 9	: CPUWRPROT_GS9	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT2_FETCHPROT_GS9_CPUFetchDis			// 8	: FETCHPROT_GS9	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT2_DMAWRPROT_GS8_DMAWriteDis			// 2	: DMAWRPROT_GS8	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT2_CPUWRPROT_GS8_CPUWriteDis			// 1	: CPUWRPROT_GS8	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT2_FETCHPROT_GS8_CPUFetchDis;		// 0	: FETCHPROT_GS8	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
	MemCfgRegs.GSxACCPROT1.all = GSxACCPROT1_DMAWRPROT_GS7_DMAWriteEn		// 26	: DMAWRPROT_GS7	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT1_CPUWRPROT_GS7_CPUWriteEn			// 25	: CPUWRPROT_GS7	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT1_FETCHPROT_GS7_CPUFetchEn			// 24	: FETCHPROT_GS7	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT1_DMAWRPROT_GS6_DMAWriteEn			// 18	: DMAWRPROT_GS6	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT1_CPUWRPROT_GS6_CPUWriteEn			// 17	: CPUWRPROT_GS6	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT1_FETCHPROT_GS6_CPUFetchEn			// 16	: FETCHPROT_GS6	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT1_DMAWRPROT_GS5_DMAWriteEn			// 10	: DMAWRPROT_GS5	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT1_CPUWRPROT_GS5_CPUWriteEn			// 9	: CPUWRPROT_GS5	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT1_FETCHPROT_GS5_CPUFetchEn			// 8	: FETCHPROT_GS5	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT1_DMAWRPROT_GS4_DMAWriteEn			// 2	: DMAWRPROT_GS4	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT1_CPUWRPROT_GS4_CPUWriteEn			// 1	: CPUWRPROT_GS4	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT1_FETCHPROT_GS4_CPUFetchEn;			// 0	: FETCHPROT_GS4	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
	MemCfgRegs.GSxACCPROT0.all = GSxACCPROT0_DMAWRPROT_GS3_DMAWriteEn		// 26	: DMAWRPROT_GS3	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT0_CPUWRPROT_GS3_CPUWriteEn			// 25	: CPUWRPROT_GS3	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT0_FETCHPROT_GS3_CPUFetchEn			// 24	: FETCHPROT_GS3	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT0_DMAWRPROT_GS2_DMAWriteEn			// 18	: DMAWRPROT_GS2	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT0_CPUWRPROT_GS2_CPUWriteEn			// 17	: CPUWRPROT_GS2	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT0_FETCHPROT_GS2_CPUFetchEn			// 16	: FETCHPROT_GS2	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT0_DMAWRPROT_GS1_DMAWriteEn			// 10	: DMAWRPROT_GS1	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT0_CPUWRPROT_GS1_CPUWriteEn			// 9	: CPUWRPROT_GS1	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT0_FETCHPROT_GS1_CPUFetchEn			// 8	: FETCHPROT_GS1	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT0_DMAWRPROT_GS0_DMAWriteEn			// 2	: DMAWRPROT_GS0	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT0_CPUWRPROT_GS0_CPUWriteEn			// 1	: CPUWRPROT_GS0	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT0_FETCHPROT_GS0_CPUFetchEn;			// 0	: FETCHPROT_GS0	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
#endif

#ifdef CPU2
	//// GSx Memory Initializing : GSx Access Enable.
	MemCfgRegs.GSxACCPROT3.all = GSxACCPROT3_DMAWRPROT_GS15_DMAWriteEn		// 26	: DMAWRPROT_GS15; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT3_CPUWRPROT_GS15_CPUWriteEn			// 25	: CPUWRPROT_GS15; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT3_FETCHPROT_GS15_CPUFetchEn			// 24	: FETCHPROT_GS15; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT3_DMAWRPROT_GS14_DMAWriteEn			// 18	: DMAWRPROT_GS14; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT3_CPUWRPROT_GS14_CPUWriteEn			// 17	: CPUWRPROT_GS14; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT3_FETCHPROT_GS14_CPUFetchEn			// 16	: FETCHPROT_GS14; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT3_DMAWRPROT_GS13_DMAWriteEn			// 10	: DMAWRPROT_GS13; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT3_CPUWRPROT_GS13_CPUWriteEn			// 9	: CPUWRPROT_GS13; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT3_FETCHPROT_GS13_CPUFetchEn			// 8	: FETCHPROT_GS13; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT3_DMAWRPROT_GS12_DMAWriteEn			// 2	: DMAWRPROT_GS12; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT3_CPUWRPROT_GS12_CPUWriteEn			// 1	: CPUWRPROT_GS12; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT3_FETCHPROT_GS12_CPUFetchEn;		// 0	: FETCHPROT_GS12; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
	MemCfgRegs.GSxACCPROT2.all = GSxACCPROT2_DMAWRPROT_GS11_DMAWriteEn		// 26	: DMAWRPROT_GS11; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT2_CPUWRPROT_GS11_CPUWriteEn			// 25	: CPUWRPROT_GS11; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT2_FETCHPROT_GS11_CPUFetchEn			// 24	: FETCHPROT_GS11; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT2_DMAWRPROT_GS10_DMAWriteEn			// 18	: DMAWRPROT_GS10; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT2_CPUWRPROT_GS10_CPUWriteEn			// 17	: CPUWRPROT_GS10; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT2_FETCHPROT_GS10_CPUFetchEn			// 16	: FETCHPROT_GS10; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT2_DMAWRPROT_GS9_DMAWriteEn			// 10	: DMAWRPROT_GS9	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT2_CPUWRPROT_GS9_CPUWriteEn			// 9	: CPUWRPROT_GS9	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT2_FETCHPROT_GS9_CPUFetchEn			// 8	: FETCHPROT_GS9	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT2_DMAWRPROT_GS8_DMAWriteEn			// 2	: DMAWRPROT_GS8	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT2_CPUWRPROT_GS8_CPUWriteEn			// 1	: CPUWRPROT_GS8	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT2_FETCHPROT_GS8_CPUFetchEn;			// 0	: FETCHPROT_GS8	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
	MemCfgRegs.GSxACCPROT1.all = GSxACCPROT1_DMAWRPROT_GS7_DMAWriteDis		// 26	: DMAWRPROT_GS7	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT1_CPUWRPROT_GS7_CPUWriteDis			// 25	: CPUWRPROT_GS7	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT1_FETCHPROT_GS7_CPUFetchDis			// 24	: FETCHPROT_GS7	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT1_DMAWRPROT_GS6_DMAWriteDis			// 18	: DMAWRPROT_GS6	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT1_CPUWRPROT_GS6_CPUWriteDis			// 17	: CPUWRPROT_GS6	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT1_FETCHPROT_GS6_CPUFetchDis			// 16	: FETCHPROT_GS6	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT1_DMAWRPROT_GS5_DMAWriteDis			// 10	: DMAWRPROT_GS5	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT1_CPUWRPROT_GS5_CPUWriteDis			// 9	: CPUWRPROT_GS5	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT1_FETCHPROT_GS5_CPUFetchDis			// 8	: FETCHPROT_GS5	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT1_DMAWRPROT_GS4_DMAWriteDis			// 2	: DMAWRPROT_GS4	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT1_CPUWRPROT_GS4_CPUWriteDis			// 1	: CPUWRPROT_GS4	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT1_FETCHPROT_GS4_CPUFetchDis;		// 0	: FETCHPROT_GS4	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
	MemCfgRegs.GSxACCPROT0.all = GSxACCPROT0_DMAWRPROT_GS3_DMAWriteDis		// 26	: DMAWRPROT_GS3	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT0_CPUWRPROT_GS3_CPUWriteDis			// 25	: CPUWRPROT_GS3	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT0_FETCHPROT_GS3_CPUFetchDis			// 24	: FETCHPROT_GS3	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT0_DMAWRPROT_GS2_DMAWriteDis			// 18	: DMAWRPROT_GS2	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT0_CPUWRPROT_GS2_CPUWriteDis			// 17	: CPUWRPROT_GS2	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT0_FETCHPROT_GS2_CPUFetchDis			// 16	: FETCHPROT_GS2	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT0_DMAWRPROT_GS1_DMAWriteDis			// 10	: DMAWRPROT_GS1	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT0_CPUWRPROT_GS1_CPUWriteDis			// 9	: CPUWRPROT_GS1	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT0_FETCHPROT_GS1_CPUFetchDis			// 8	: FETCHPROT_GS1	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
							| GSxACCPROT0_DMAWRPROT_GS0_DMAWriteDis			// 2	: DMAWRPROT_GS0	; 0(DMA Write Enable), 1(DMA Write Disable).
							| GSxACCPROT0_CPUWRPROT_GS0_CPUWriteDis			// 1	: CPUWRPROT_GS0	; 0(CPU Write Enable), 1(CPU Write Disable).
							| GSxACCPROT0_FETCHPROT_GS0_CPUFetchDis;		// 0	: FETCHPROT_GS0	; 0(CPU Fetch Enable), 1(CPU Fetch Disable).
#endif

	EDIS;

	return;
}

#ifdef CPU1
void Init_GSRAM(void)
{
	EALLOW;

	// GSx Memory Initializing.
	//// GSx Memory Initializing : GSx Master Selection.
	MemCfgRegs.GSxMSEL.all = GSxMSEL_MSEL_GS15_CPU2Host						// 15	: MSEL_GS15		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS14_CPU2Host					// 14	: MSEL_GS14		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS13_CPU2Host					// 13	: MSEL_GS13		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS12_CPU2Host					// 12	: MSEL_GS12		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS11_CPU2Host					// 11	: MSEL_GS11		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS10_CPU2Host					// 10	: MSEL_GS10		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS9_CPU2Host						// 9	: MSEL_GS9		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS8_CPU2Host						// 8	: MSEL_GS8		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS7_CPU1Host						// 7	: MSEL_GS7		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS6_CPU1Host						// 6	: MSEL_GS6		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS5_CPU1Host						// 5	: MSEL_GS5		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS4_CPU1Host						// 4	: MSEL_GS4		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS3_CPU1Host						// 3	: MSEL_GS3		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS2_CPU1Host						// 2	: MSEL_GS2		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS1_CPU1Host						// 1	: MSEL_GS1		; 0(CPU1), 1(CPU2).
							| GSxMSEL_MSEL_GS0_CPU1Host;					// 0	: MSEL_GS0		; 0(CPU1), 1(CPU2).

	EDIS;

	return;
}
#endif
