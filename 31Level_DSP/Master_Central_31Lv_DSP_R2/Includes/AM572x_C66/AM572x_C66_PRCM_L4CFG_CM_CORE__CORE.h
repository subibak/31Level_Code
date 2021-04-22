/*
 * AM572x_C66_PRCM_L4CFG_CM_CORE__CORE.h
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#ifndef AM572X_C66_PRCM_L4CFG_CM_CORE__CORE_H_
#define AM572X_C66_PRCM_L4CFG_CM_CORE__CORE_H_

#ifdef __cplusplus
extern "C" {
#endif

struct CM_L3MAIN1_CLKSTCTRL_BITS {
	Uint32	CLKTRCTRL:2;
	Uint32	rsvd0:6;
	Uint32	CLKACTIVITY_L3MAIN1_L3_GICLK:1;
	Uint32	CLKACTIVITY_L3MAIN1_L4_GICLK:1;
	Uint32	rsvd1:22;
};

union CM_L3MAIN1_CLKSTCTRL_REG {
	Uint32								all;
	struct CM_L3MAIN1_CLKSTCTRL_BITS	bit;
};


struct CM_L3MAIN1_L3_MAIN_1_CLKCTRL_BITS {
	Uint32	MODULEMODE:2;
	Uint32	rsvd0:14;
	Uint32	IDLEST:2;
	Uint32	rsvd1:14;
};

union CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG {
	Uint32										all;
	struct CM_L3MAIN1_L3_MAIN_1_CLKCTRL_BITS	bit;
};

struct CM_L3MAIN1_GPMC_CLKCTRL_BITS {
	Uint32	MODULEMODE:2;
	Uint32	rsvd0:14;
	Uint32	IDLEST:2;
	Uint32	rsvd1:14;
};

union CM_L3MAIN1_GPMC_CLKCTRL_REG {
	Uint32										all;
	struct CM_L3MAIN1_GPMC_CLKCTRL_BITS			bit;
};


// -------------------- Registers Define --------------------//
struct CM_CORE__CORE_REGS {
	union CM_L3MAIN1_CLKSTCTRL_REG			CM_L3MAIN1_CLKSTCTRL;			// 0x0000
	Uint32									rsvd0_4;						// 0x0004
	Uint32									CM_L3MAIN1_DYNAMICDEP;			// 0x0008
	Uint32									rsvd0_C;						// 0x000C
	Uint32									rsvd1[4];						// 0x0010
	union CM_L3MAIN1_L3_MAIN_1_CLKCTRL_REG	CM_L3MAIN1_L3_MAIN_1_CLKCTRL;	// 0x0020
	Uint32									rsvd2_4;						// 0x0024
	union CM_L3MAIN1_GPMC_CLKCTRL_REG		CM_L3MAIN1_GPMC_CLKCTRL;		// 0x0028
	Uint32									rsvd2_C;						// 0x002C
	Uint32									CM_L3MAIN1_MMU_EDMA_CLKCTRL;	// 0x0030
	Uint32									rsvd3_48C[3];					// 0x0034
	Uint32									rsvd4_04[2];					// 0x0040
	Uint32									CM_L3MAIN1_MMU_PCIESS_CLKCTRL;	// 0x0048
	Uint32									rsvd4_C;						// 0x004C
	Uint32									CM_L3MAIN1_OCMC_RAM1_CLKCTRL;	// 0x0050
	Uint32									rsvd5_4;						// 0x0054
	Uint32									CM_L3MAIN1_OCMC_RAM2_CLKCTRL;	// 0x0058
	Uint32									rsvd5_C;						// 0x005C
	Uint32									CM_L3MAIN1_OCMC_RAM3_CLKCTRL;	// 0x0060
	Uint32									rsvd6_48C[3];					// 0x0064
	Uint32									CM_L3MAIN1_TPCC_CLKCTRL;		// 0x0070
	Uint32									rsvd7_4;						// 0x0074
	Uint32									CM_L3MAIN1_TPTC1_CLKCTRL;		// 0x0078
	Uint32									rsvd7_C;						// 0x007C
	Uint32									CM_L3MAIN1_TPTC2_CLKCTRL;		// 0x0080
	Uint32									rsvd8_4;						// 0x0084
	Uint32									CM_L3MAIN1_VCP1_CLKCTRL;		// 0x0088
	Uint32									rsvd8_C;						// 0x008C
	Uint32									CM_L3MAIN1_VCP2_CLKCTRL;		// 0x0090
};

extern volatile struct CM_CORE__CORE_REGS	CM_CORE__CORERegs;

#ifdef __cplusplus
}
#endif

#endif /* AM572X_C66_PRCM_L4CFG_CM_CORE__CORE_H_ */
