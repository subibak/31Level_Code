/*
 * AM572x_C66_GPIO.h
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#ifndef AM572X_C66_GPIO_H_
#define AM572X_C66_GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

struct GPIO_SYSCONFIG_BITS {
	Uint32	AUTOIDLE:1;
	Uint32	SOFTRESET:1;
	Uint32	ENAWAKEUP:1;
	Uint32	IDLEMODE:2;
	Uint32	rsvd0:27;
};

union GPIO_SYSCONFIG_REG {
	Uint32								all;
	struct GPIO_SYSCONFIG_BITS			bit;
};

// GPIO_SYSCNFIG Register.



struct GPIO_SYSSTATUS_BITS {
	Uint32	RESETDONE:1;
	Uint32	rsvd0:31;
};

union GPIO_SYSSTATUS_REG {
	Uint32								all;
	struct GPIO_SYSSTATUS_BITS			bit;
};

// GPIO_SYSSTATUS Register.

struct GPIO_CTRL_BITS {
	Uint32	DISABLEMODULE:1;
	Uint32	GATINGRATIO:2;
	Uint32	rsvd0:29;
};

union GPIO_CTRL_REG {
	Uint32								all;
	struct GPIO_CTRL_BITS				bit;
};

// GPIO_CTRL Register.

struct GPIO_OE_BITS {
	Uint32	OUTPUT0EN:1;
	Uint32	OUTPUT1EN:1;
	Uint32	OUTPUT2EN:1;
	Uint32	OUTPUT3EN:1;
	Uint32	OUTPUT4EN:1;
	Uint32	OUTPUT5EN:1;
	Uint32	OUTPUT6EN:1;
	Uint32	OUTPUT7EN:1;
	Uint32	OUTPUT8EN:1;
	Uint32	OUTPUT9EN:1;
	Uint32	OUTPUT10EN:1;
	Uint32	OUTPUT11EN:1;
	Uint32	OUTPUT12EN:1;
	Uint32	OUTPUT13EN:1;
	Uint32	OUTPUT14EN:1;
	Uint32	OUTPUT15EN:1;
	Uint32	OUTPUT16EN:1;
	Uint32	OUTPUT17EN:1;
	Uint32	OUTPUT18EN:1;
	Uint32	OUTPUT19EN:1;
	Uint32	OUTPUT20EN:1;
	Uint32	OUTPUT21EN:1;
	Uint32	OUTPUT22EN:1;
	Uint32	OUTPUT23EN:1;
	Uint32	OUTPUT24EN:1;
	Uint32	OUTPUT25EN:1;
	Uint32	OUTPUT26EN:1;
	Uint32	OUTPUT27EN:1;
	Uint32	OUTPUT28EN:1;
	Uint32	OUTPUT29EN:1;
	Uint32	OUTPUT30EN:1;
	Uint32	OUTPUT31EN:1;
};

union GPIO_OE_REG {
	Uint32								all;
	struct GPIO_OE_BITS					bit;
};

struct GPIO_BITS {
	Uint32	IO0:1;
	Uint32	IO1:1;
	Uint32	IO2:1;
	Uint32	IO3:1;
	Uint32	IO4:1;
	Uint32	IO5:1;
	Uint32	IO6:1;
	Uint32	IO7:1;
	Uint32	IO8:1;
	Uint32	IO9:1;
	Uint32	IO10:1;
	Uint32	IO11:1;
	Uint32	IO12:1;
	Uint32	IO13:1;
	Uint32	IO14:1;
	Uint32	IO15:1;
	Uint32	IO16:1;
	Uint32	IO17:1;
	Uint32	IO18:1;
	Uint32	IO19:1;
	Uint32	IO20:1;
	Uint32	IO21:1;
	Uint32	IO22:1;
	Uint32	IO23:1;
	Uint32	IO24:1;
	Uint32	IO25:1;
	Uint32	IO26:1;
	Uint32	IO27:1;
	Uint32	IO28:1;
	Uint32	IO29:1;
	Uint32	IO30:1;
	Uint32	IO31:1;
};

union GPIO_REG {
	Uint32								all;
	struct GPIO_BITS					bit;
};

#define GPIO_GPIO0						0x00000001
#define GPIO_GPIO1						0x00000002
#define GPIO_GPIO2						0x00000004
#define GPIO_GPIO3						0x00000008
#define GPIO_GPIO4						0x00000010
#define GPIO_GPIO5						0x00000020
#define GPIO_GPIO6						0x00000040
#define GPIO_GPIO7						0x00000080
#define GPIO_GPIO8						0x00000100
#define GPIO_GPIO9						0x00000200
#define GPIO_GPIO10						0x00000400
#define GPIO_GPIO11						0x00000800
#define GPIO_GPIO12						0x00001000
#define GPIO_GPIO13						0x00002000
#define GPIO_GPIO14						0x00004000
#define GPIO_GPIO15						0x00008000
#define GPIO_GPIO16						0x00010000
#define GPIO_GPIO17						0x00020000
#define GPIO_GPIO18						0x00040000
#define GPIO_GPIO19						0x00080000
#define GPIO_GPIO20						0x00100000
#define GPIO_GPIO21						0x00200000
#define GPIO_GPIO22						0x00400000
#define GPIO_GPIO23						0x00800000
#define GPIO_GPIO24						0x01000000
#define GPIO_GPIO25						0x02000000
#define GPIO_GPIO26						0x04000000
#define GPIO_GPIO27						0x08000000
#define GPIO_GPIO28						0x10000000
#define GPIO_GPIO29						0x20000000
#define GPIO_GPIO30						0x40000000
#define GPIO_GPIO31						0x80000000

// -------------------- Registers Define --------------------//
struct GPIO_REGS {
	Uint32								GPIO_REVISION;			// 0x0000
	Uint32								rsvd0[3];				// 0x0004
	union GPIO_SYSCONFIG_REG			GPIO_SYSCONFIG;			// 0x0010
	Uint32								rsvd1[3];				// 0x0014
	Uint32								EOI;					// 0x0020
	Uint32								GPIO_IRQSTATUS_RAW_0;	// 0x0024
	Uint32								GPIO_IRQSTATUS_RAW_1;	// 0x0028
	Uint32								GPIO_IRQSTATUS_0;		// 0x002C
	Uint32								GPIO_IRQSTATUS_1;		// 0x0030
	Uint32								GPIO_IRQSTATUS_SET_0;	// 0x0034
	Uint32								GPIO_IRQSTATUS_SET_1;	// 0x0038
	Uint32								GPIO_IRQSTATUS_CLR_0;	// 0x003C
	Uint32								GPIO_IRQSTATUS_CLR_1;	// 0x0040
	Uint32								GPIO_IRQWAKEN_0;		// 0x0044
	Uint32								GPIO_IRQWAKEN_1;		// 0x0048
	Uint32								rsvd4;					// 0x004C
	Uint32								rsvd5[4];				// 0x0050
	Uint32								rsvd6[4];				// 0x0060
	Uint32								rsvd7[4];				// 0x0070
	Uint32								rsvd8[4];				// 0x0080
	Uint32								rsvd9[4];				// 0x0090
	Uint32								rsvdA[4];				// 0x00A0
	Uint32								rsvdB[4];				// 0x00B0
	Uint32								rsvdC[4];				// 0x00C0
	Uint32								rsvdD[4];				// 0x00D0
	Uint32								rsvdE[4];				// 0x00E0
	Uint32								rsvdF[4];				// 0x00F0
	Uint32								rsvd10[4];				// 0x0100
	Uint32								rsvd11_0;				// 0x0110
	union GPIO_SYSSTATUS_REG			GPIO_SYSSTATUS;			// 0x0114
	Uint32								rsvd11_8;				// 0x0118
	Uint32								rsvd11_C;				// 0x011C
	Uint32								rsvd12[4];				// 0x0120
	union GPIO_CTRL_REG					GPIO_CTRL;				// 0x0130
	union GPIO_OE_REG					GPIO_OE;				// 0x0134
	union GPIO_REG						GPIO_DATAIN;			// 0x0138
	union GPIO_REG						GPIO_DATAOUT;			// 0x013C
	Uint32								GPIO_LEVELDETECT0;		// 0x0140
	Uint32								GPIO_LEVELDETECT1;		// 0x0144
	Uint32								GPIO_RISINGDETECT;		// 0x0148
	Uint32								GPIO_FALLINGDETECT;		// 0x014C
	Uint32								GPIO_DEBOUNCENABLE;		// 0x0150
	Uint32								GPIO_DEBOUNCEINGTIME;	// 0x0154
	Uint32								rsvd15[2];				// 0x015C
	Uint32								rsvd16[4];				// 0x0160
	Uint32								rsvd17[4];				// 0x0170
	Uint32								rsvd18[4];				// 0x0180
	union GPIO_REG						GPIO_CLEARDATAOUT;		// 0x0190
	union GPIO_REG						GPIO_SETDATAOUT;		// 0x0194
};

extern volatile struct GPIO_REGS	GPIO1Regs;
extern volatile struct GPIO_REGS	GPIO2Regs;
extern volatile struct GPIO_REGS	GPIO3Regs;
extern volatile struct GPIO_REGS	GPIO4Regs;
extern volatile struct GPIO_REGS	GPIO5Regs;
extern volatile struct GPIO_REGS	GPIO6Regs;
extern volatile struct GPIO_REGS	GPIO7Regs;
extern volatile struct GPIO_REGS	GPIO8Regs;

#ifdef __cplusplus
}
#endif




#endif /* AM572X_C66_GPIO_H_ */
