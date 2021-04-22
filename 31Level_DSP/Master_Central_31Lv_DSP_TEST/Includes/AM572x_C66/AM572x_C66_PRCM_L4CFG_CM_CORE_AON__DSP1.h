/*
 * AM572x_C66_PRCM_L4CFG_CM_CORE_AON__DSP1.h
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#ifndef AM572X_C66_PRCM_L4CFG_CM_CORE_AON__DSP1_H_
#define AM572X_C66_PRCM_L4CFG_CM_CORE_AON__DSP1_H_

#ifdef __cplusplus
extern "C" {
#endif

struct CM_DSP1_CLKSTCTRL_BITS {
	Uint32	CLKTRCTRL:2;
	Uint32	rsvd0:6;
	Uint32	CLKACTIVITY_DSP1_GFCLK:1;
	Uint32	rsvd1:23;
};

union CM_DSP1_CLKSTCTRL_REG {
	Uint32								all;
	struct CM_DSP1_CLKSTCTRL_BITS		bit;
};


struct CM_DSP1_DYNAMICDEP_BITS {
	Uint32	rsvd0:5;
	Uint32	L3MAIN1_DYNDEP:1;
	Uint32	rsvd1:18;
	Uint32	WINDOWSIZE:4;
	Uint32	rsvd2:4;
};

union CM_DSP1_DYNAMICDEP_REG {
	Uint32								all;
	struct CM_DSP1_DYNAMICDEP_BITS		bit;
};

struct CM_DSP1_DSP1_CLKCTRL_BITS {
	Uint32	MODULEMODE:2;
	Uint32	rsvd0:14;
	Uint32	IDLEST:2;
	Uint32	STBYST:1;
	Uint32	rsvd1:13;
};

union CM_DSP1_DSP1_CLKCTRL_REG {
	Uint32								all;
	struct CM_DSP1_DSP1_CLKCTRL_BITS	bit;
};

// -------------------- Registers Define --------------------//
struct CM_CORE_AON__DSP1_REGS {
	union CM_DSP1_CLKSTCTRL_REG			CM_DSP1_CLKSTCTRL;		// 0x0000
	Uint32								CM_DSP1_STATICDEP;		// 0x0004
	union CM_DSP1_DYNAMICDEP_REG		CM_DSP1_DYNAMICDEP;		// 0x0008
	Uint32								rsvd0_C;				// 0x000C
	Uint32								rsvd1[4];				// 0x0010
	union CM_DSP1_DSP1_CLKCTRL_REG		CM_DSP1_DSP1_CLKCTRL;	// 0x0020
};

extern volatile struct CM_CORE_AON__DSP1_REGS		CM_CORE_AON__DSP1Regs;

#ifdef __cplusplus
}
#endif

#endif /* AM572X_C66_PRCM_L4CFG_CM_CORE_AON__DSP1_H_ */
