/*
 * AM572x_C66_Timer.h
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#ifndef AM572X_C66_TIMER_H_
#define AM572X_C66_TIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

struct TIDR_BITS {
	Uint32	REV;
};

union TIDR_REG {
	Uint32							all;
	struct TIDR_BITS				bit;
};

struct TIOCP_CFG_BITS {
	Uint32	SOFTRESET:1;
	Uint32	EMUFREE:1;
	Uint32	IDLEMODE:2;
	Uint32	rsvd0:28;
};

union TIOCP_CFG_REG {
	Uint32							all;
	struct TIOCP_CFG_BITS			bit;
};

// TIOCP_CFG Register
//// TIOCP_CFG Register : Byte Value.
#define TIOCP_CFG_IDLEMODE_ForcedIDLE		0x00000000
#define TIOCP_CFG_IDLEMODE_NoIDLE			0x00000004
#define TIOCP_CFG_IDLEMODE_SmartIDLE		0x00000008
#define	TIOCP_CFG_IDLEMODE_SmartIDLEwithWU	0x0000000C

#define TIOCP_CFG_EMUFREE_Frozen			0x00000000
#define TIOCP_CFG_EMUFREE_Free				0x00000002

#define TIOCP_CFG_SOFTRESET_Normal			0x00000000
#define TIOCP_CFG_SOFTRESET_SWReset			0x00000001

struct IRQ_EOI_BITS {
	Uint32	LINE_NUMBER:1;
	Uint32	rsvd0:31;
};

union IRQ_EOI_REG {
	Uint32							all;
	struct IRQ_EOI_BITS				bit;
};

struct IRQSTATUS_BITS {
	Uint32	MAT_IT_FLAG:1;
	Uint32	OVF_IT_FLAG:1;
	Uint32	TCAR_IT_FLAG:1;
	Uint32	rsvd0:29;
};

union IRQSTATUS_REG {
	Uint32							all;
	struct IRQSTATUS_BITS			bit;
};

// Timer Interrupt Status Register.
//// Timer Interrupt Status Register : Byte Value.
#define IRQSTATUS_TCAR_INT			0x00000004
#define IRQSTATUS_OVF_INT			0x00000002
#define IRQSTATUS_MAT_INT			0x00000001

struct IRQENABLE_BITS {
	Uint32	MAT_EN_FLAG:1;
	Uint32	OVF_EN_FLAG:1;
	Uint32	TCAR_EN_FALG:1;
	Uint32	rsvd0:29;
};

union IRQENABLE_REG {
	Uint32							all;
	struct IRQENABLE_BITS			bit;
};

// Timer Interrupt Enable Set/Clear Register.
//// Timer Interrupt Enable Set/Clear Register : Byte Value.
#define IRQENABLE_TCAR_INT			0x00000004
#define IRQENABLE_OVF_INT			0x00000002
#define IRQENABLE_MAT_INT			0x00000001

struct IRQWAKEEN_BITS {
	Uint32	MAT_WUP_ENA:1;
	Uint32	OVF_WUP_ENA:1;
	Uint32	TCAR_WUP_ENA:1;
	Uint32	rsvd0:29;
};

union IRQWAKEEN_REG {
	Uint32							all;
	struct IRQWAKEEN_BITS			bit;
};

struct TCLR_BITS {
	Uint32	ST:1;								// 0
	Uint32	AR:1;								// 1
	Uint32	PTV:3;								// 4:2
	Uint32	PRE:1;								// 5
	Uint32	CE:1;								// 6
	Uint32	SCPWM:1;							// 7
	Uint32	TCM:2;								// 9:8
	Uint32	TRG:2;								// 11:10
	Uint32	PT:1;								// 12
	Uint32	CAPT_MODE:1;						// 13
	Uint32	GP0_CFG:1;							// 14
	Uint32	rsvd0:17;							// 31:15
};

union TCLR_REG {
	Uint32							all;
	struct TCLR_BITS				bit;
};

// TCLR Register
//// TCLR Register : Byte Value.
//#define TCLR_GPO_CFG
//#define TCLR_CAPT_MODE
//#define TCLR_PT
//#define TCLR_TRG
//#define TCLR_TCM
//#define TCLR_SCPWM

#define TCLR_CE_COMPDis				0x00000000
#define TCLR_CE_COMPEn				0x00000040

#define TCLR_PRE_PRESCALEDis		0x00000000
#define TCLR_PRE_PRESCALEEn			0x00000020

#define TCLR_PTV_PREDIV2			0x00000000
#define TCLR_PTV_PREDIV4			0x00000004
#define TCLR_PTV_PREDIV8			0x00000008
#define TCLR_PTV_PREDIV16			0x0000000C
#define TCLR_PTV_PREDIV32			0x00000010
#define TCLR_PTV_PREDIV64			0x00000014
#define TCLR_PTV_PREDIV128			0x00000018
#define TCLR_PTV_PREDIV256			0x0000001C

#define TCLR_AR_OneShotMode			0x00000000
#define TCLR_AR_AutoReloadMode		0x00000002

#define TCLR_ST_TimerStop			0x00000000
#define TCLR_ST_TimerStart			0x00000001

struct TCRR_BITS {
	Uint32	TIMER_COUNTER;
};

union TCRR_REG {
	Uint32							all;
	struct TCRR_BITS				bit;
};

struct TLDR_BITS {
	Uint32	LOAD_VALUE;
};

union TLDR_REG {
	Uint32							all;
	struct TLDR_BITS				bit;
};

struct TTGR_BITS {
	Uint32 TTGR_VALUE;
};

union TTGR_REG {
	Uint32							all;
	struct TTGR_BITS				bit;
};

struct TWPS_BITS {
	Uint32 W_PEND_TCLR:1;						// 0
	Uint32 W_PEND_TCRR:1;						// 1
	Uint32 W_PEND_TLDR:1;						// 2
	Uint32 W_PEND_TTGR:1;						// 3
	Uint32 W_PEND_TMAR:1;						// 4
	Uint32 W_PEND_TPIR:1;						// 5
	Uint32 W_PEND_TNIR:1;						// 6
	Uint32 W_PEND_TCVR:1;						// 7
	Uint32 W_PEND_TOCR:1;						// 8
	Uint32 W_PEND_TOWR:1;						// 9
	Uint32 rsvd0:22;							// 31:10
};

union TWPS_REG {
	Uint32							all;
	struct TWPS_BITS				bit;
};

struct TMAR_BITS {
	Uint32 COMPARE;
};

union TMAR_REG {
	Uint32							all;
	struct TMAR_BITS				bit;
};

struct TCAR1_BITS {
	Uint32 CAPTURE1;
};

union TCAR1_REG {
	Uint32							all;
	struct TCAR1_BITS				bit;
};

struct TCAR2_BITS {
	Uint32 CAPTURE2;
};

union TCAR2_REG {
	Uint32							all;
	struct TCAR2_BITS				bit;
};

struct TSICR_BITS {
	Uint32 rsvd0:1;								// 0
	Uint32 SFT:1;								// 1
	Uint32 POSTED:1;							// 2
	Uint32 READ_MODE:1;							// 3
	Uint32 rsvd1:28;							// 31:4
};

// TSICR Register
//// TSICR Register : Byte Value.
#define TSICR_READ_MODE_RDPostedMode		0x00000000
#define TSICR_READ_MODE_RDNonPostedMode		0x00000008

#define TSICR_POSTED_WRRDPostedMode			0x00000000
#define TSICR_POSTED_WRRDNonPostedMode		0x00000004

//#define TSICR_SFT

union TSICR_REG {
	Uint32							all;
	struct TSICR_BITS				bit;
};

struct TPIR_BITS {
	Uint32 POSITIVE_INC_VALUE;
};

union TPIR_REG {
	Uint32							all;
	struct TPIR_BITS				bit;
};

struct TNIR_BITS {
	Uint32 NEGATIVE_INC_VALUE;
};

union TNIR_REG {
	Uint32							all;
	struct TNIR_BITS				bit;
};

struct TCVR_BITS {
	Uint32 CVR_COUNTER;
};

union TCVR_REG {
	Uint32							all;
	struct TCVR_BITS				bit;
};

struct TOCR_BITS {
	Uint32 OVF_COUNTER:24;						// 23:0
	Uint32 rsvd0:8;								// 31:24
};

union TOCR_REG {
	Uint32							all;
	struct TOCR_BITS				bit;
};

struct TOWR_BITS {
	Uint32 OVF_WRAPPING:24;						// 23:0
	Uint32 rsvd0:8;								// 31:24
};

union TOWR_REG {
	Uint32							all;
	struct TOWR_BITS				bit;
};

// -------------------- Individual Timer Registers Define --------------------//
struct TIMER1_2_10_REGS {						// Offset
	union	TIDR_REG			TIDR;			// 0x0000
	Uint32						rsvd0[3];		// 0x0004
	union	TIOCP_CFG_REG		TIOCP_CFG;		// 0x0010
	Uint32						rsvd1[3];		// 0x0014
	union	IRQ_EOI_REG			IRQ_EOI;		// 0x0020
	union	IRQSTATUS_REG		IRQSTATUS_RAW;	// 0x0024
	union	IRQSTATUS_REG		IRQSTATUS;		// 0x0028
	union	IRQENABLE_REG		IRQSTATUS_SET;	// 0x002C
	union	IRQENABLE_REG		IRQSTATUS_CLR;	// 0x0030
	union	IRQWAKEEN_REG		IRQWAKEEN;		// 0x0034
	union	TCLR_REG			TCLR;			// 0x0038
	union	TCRR_REG			TCRR;			// 0x003C
	union	TLDR_REG			TLDR;			// 0x0040
	union	TTGR_REG			TTGR;			// 0x0044
	union	TWPS_REG			TWPS;			// 0x0048
	union	TMAR_REG			TMAR;			// 0x004C
	union	TCAR1_REG			TCAR1;			// 0x0050
	union	TSICR_REG			TSICR;			// 0x0054
	union	TCAR2_REG			TCAR2;			// 0x0058
	union	TPIR_REG			TPIR;			// 0x005C
	union	TNIR_REG			TNIR;			// 0x0060
	union	TCVR_REG			TCVR;			// 0x0064
	union	TOCR_REG			TOCR;			// 0x0068
	union	TOWR_REG			TOWR;			// 0x006C
};

struct TIMER_REGS {
	union	TIDR_REG			TIDR;			// 0x0000
	Uint32						rsvd0[3];		// 0x0004
	union	TIOCP_CFG_REG		TIOCP_CFG;		// 0x0010
	Uint32						rsvd1[3];		// 0x0014
	union	IRQ_EOI_REG			IRQ_EOI;		// 0x0020
	union	IRQSTATUS_REG		IRQSTATUS_RAW;	// 0x0024
	union	IRQSTATUS_REG		IRQSTATUS;		// 0x0028
	union	IRQENABLE_REG		IRQENABLE_SET;	// 0x002C
	union	IRQENABLE_REG		IRQENABLE_CLR;	// 0x0030
	union	IRQWAKEEN_REG		IRQWAKEEN;		// 0x0034
	union	TCLR_REG			TCLR;			// 0x0038
	union	TCRR_REG			TCRR;			// 0x003C
	union	TLDR_REG			TLDR;			// 0x0040
	union	TTGR_REG			TTGR;			// 0x0044
	union	TWPS_REG			TWPS;			// 0x0048
	union	TMAR_REG			TMAR;			// 0x004C
	union	TCAR1_REG			TCAR1;			// 0x0050
	union	TSICR_REG			TSICR;			// 0x0054
	union	TCAR2_REG			TCAR2;			// 0x0058
};

extern volatile struct TIMER_REGS       Timer5Regs;

#ifdef __cplusplus
}
#endif

#endif /* AM572X_C66_TIMER_H_ */
