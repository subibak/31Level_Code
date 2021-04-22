/*
 * AM572x_C66_DSP_ICFG.h
 *
 *  Created on: 2018. 11. 6.
 *      Author: HJHeo
 */

#ifndef AM572X_C66_DSP_ICFG_H_
#define AM572X_C66_DSP_ICFG_H_

#ifdef __cplusplus
extern "C" {
#endif

struct EVT0_BITS {
	Uint32	EVT0:1;
	Uint32	EVT1:1;
	Uint32	EVT2:1;
	Uint32	EVT3:1;
	Uint32	EVT4:1;
	Uint32	EVT5:1;
	Uint32	EVT6:1;
	Uint32	EVT7:1;
	Uint32	EVT8:1;
	Uint32	EVT9:1;
	Uint32	EVT10:1;
	Uint32	EVT11:1;
	Uint32	EVT12:1;
	Uint32	EVT13:1;
	Uint32	EVT14:1;
	Uint32	EVT15:1;
	Uint32	EVT16:1;
	Uint32	EVT17:1;
	Uint32	EVT18:1;
	Uint32	EVT19:1;
	Uint32	EVT20:1;
	Uint32	EVT21:1;
	Uint32	EVT22:1;
	Uint32	EVT23:1;
	Uint32	EVT24:1;
	Uint32	EVT25:1;
	Uint32	EVT26:1;
	Uint32	EVT27:1;
	Uint32	EVT28:1;
	Uint32	EVT29:1;
	Uint32	EVT30:1;
	Uint32	EVT31:1;
};

union EVT0_REG {
	Uint32						all;
	struct EVT0_BITS			bit;
};

struct EVT1_BITS {
	Uint32	EVT32:1;
	Uint32	EVT33:1;
	Uint32	EVT34:1;
	Uint32	EVT35:1;
	Uint32	EVT36:1;
	Uint32	EVT37:1;
	Uint32	EVT38:1;
	Uint32	EVT39:1;
	Uint32	EVT40:1;
	Uint32	EVT41:1;
	Uint32	EVT42:1;
	Uint32	EVT43:1;
	Uint32	EVT44:1;
	Uint32	EVT45:1;
	Uint32	EVT46:1;
	Uint32	EVT47:1;
	Uint32	EVT48:1;
	Uint32	EVT49:1;
	Uint32	EVT50:1;
	Uint32	EVT51:1;
	Uint32	EVT52:1;
	Uint32	EVT53:1;
	Uint32	EVT54:1;
	Uint32	EVT55:1;
	Uint32	EVT56:1;
	Uint32	EVT57:1;
	Uint32	EVT58:1;
	Uint32	EVT59:1;
	Uint32	EVT60:1;
	Uint32	EVT61:1;
	Uint32	EVT62:1;
	Uint32	EVT63:1;
};

union EVT1_REG {
	Uint32						all;
	struct EVT1_BITS			bit;
};

struct EVT2_BITS {
	Uint32	EVT64:1;
	Uint32	EVT65:1;
	Uint32	EVT66:1;
	Uint32	EVT67:1;
	Uint32	EVT68:1;
	Uint32	EVT69:1;
	Uint32	EVT70:1;
	Uint32	EVT71:1;
	Uint32	EVT72:1;
	Uint32	EVT73:1;
	Uint32	EVT74:1;
	Uint32	EVT75:1;
	Uint32	EVT76:1;
	Uint32	EVT77:1;
	Uint32	EVT78:1;
	Uint32	EVT79:1;
	Uint32	EVT80:1;
	Uint32	EVT81:1;
	Uint32	EVT82:1;
	Uint32	EVT83:1;
	Uint32	EVT84:1;
	Uint32	EVT85:1;
	Uint32	EVT86:1;
	Uint32	EVT87:1;
	Uint32	EVT88:1;
	Uint32	EVT89:1;
	Uint32	EVT90:1;
	Uint32	EVT91:1;
	Uint32	EVT92:1;
	Uint32	EVT93:1;
	Uint32	EVT94:1;
	Uint32	EVT95:1;
};

union EVT2_REG {
	Uint32						all;
	struct EVT2_BITS			bit;
};

struct EVT3_BITS {
	Uint32	EVT96:1;
	Uint32	EVT97:1;
	Uint32	EVT98:1;
	Uint32	EVT99:1;
	Uint32	EVT100:1;
	Uint32	EVT101:1;
	Uint32	EVT102:1;
	Uint32	EVT103:1;
	Uint32	EVT104:1;
	Uint32	EVT105:1;
	Uint32	EVT106:1;
	Uint32	EVT107:1;
	Uint32	EVT108:1;
	Uint32	EVT109:1;
	Uint32	EVT110:1;
	Uint32	EVT111:1;
	Uint32	EVT112:1;
	Uint32	EVT113:1;
	Uint32	EVT114:1;
	Uint32	EVT115:1;
	Uint32	EVT116:1;
	Uint32	EVT117:1;
	Uint32	EVT118:1;
	Uint32	EVT119:1;
	Uint32	EVT120:1;
	Uint32	EVT121:1;
	Uint32	EVT122:1;
	Uint32	EVT123:1;
	Uint32	EVT124:1;
	Uint32	EVT125:1;
	Uint32	EVT126:1;
	Uint32	EVT127:1;
};

union EVT3_REG {
	Uint32						all;
	struct EVT3_BITS			bit;
};

struct INTMUX1_BITS {
	Uint32	INTSEL4:7;
	Uint32	rsvd0:1;
	Uint32	INTSEL5:7;
	Uint32	rsvd1:1;
	Uint32	INTSEL6:7;
	Uint32	rsvd2:1;
	Uint32	INTSEL7:7;
	Uint32	rsvd3:1;
};

union INTMUX1_REG {
	Uint32						all;
	struct INTMUX1_BITS			bit;
};

struct INTMUX2_BITS {
	Uint32	INTSEL8:7;
	Uint32	rsvd0:1;
	Uint32	INTSEL9:7;
	Uint32	rsvd1:1;
	Uint32	INTSEL10:7;
	Uint32	rsvd2:1;
	Uint32	INTSEL11:7;
	Uint32	rsvd3:1;
};

union INTMUX2_REG {
	Uint32						all;
	struct INTMUX2_BITS			bit;
};

struct INTMUX3_BITS {
	Uint32	INTSEL12:7;
	Uint32	rsvd0:1;
	Uint32	INTSEL13:7;
	Uint32	rsvd1:1;
	Uint32	INTSEL14:7;
	Uint32	rsvd2:1;
	Uint32	INTSEL15:7;
	Uint32	rsvd3:1;
};

union INTMUX3_REG {
	Uint32						all;
	struct INTMUX3_BITS			bit;
};

// INTMUX Register.
//// INTMUX Register : INSEL Bit Value
#define INTSEL_EVT0_EVT0to31	0U
#define INTSEL_EVT1_EVT32to63	1U
#define INTSEL_EVT2_EVT64to95	2U
#define INTSEL_EVT3_EVT96to127	3U

#define INTSEL_IDMAINT0			13U
#define INTSEL_IDMAINT1			14U

#define INTSEL_IRQ32			32U
#define INTSEL_IRQ33			33U
#define INTSEL_IRQ34			34U
#define INTSEL_IRQ35			35U
#define INTSEL_IRQ36			36U
#define INTSEL_IRQ37			37U
#define INTSEL_IRQ38			38U
#define INTSEL_IRQ39			39U
#define INTSEL_IRQ40			40U
#define INTSEL_IRQ41			41U
#define INTSEL_IRQ42			42U
#define INTSEL_IRQ43			43U
#define INTSEL_IRQ44			44U
#define INTSEL_IRQ45			45U
#define INTSEL_IRQ46			46U
#define INTSEL_IRQ47			47U
#define INTSEL_IRQ48			48U
#define INTSEL_IRQ49			49U
#define INTSEL_IRQ50			50U
#define INTSEL_IRQ51			51U
#define INTSEL_IRQ52			52U
#define INTSEL_IRQ53			53U
#define INTSEL_IRQ54			54U
#define INTSEL_IRQ55			55U
#define INTSEL_IRQ56			56U
#define INTSEL_IRQ57			57U
#define INTSEL_IRQ58			58U
#define INTSEL_IRQ59			59U
#define INTSEL_IRQ60			60U
#define INTSEL_IRQ61			61U
#define INTSEL_IRQ62			62U
#define INTSEL_IRQ63			63U
#define INTSEL_IRQ64			64U
#define INTSEL_IRQ65			65U
#define INTSEL_IRQ66			66U
#define INTSEL_IRQ67			67U
#define INTSEL_IRQ68			68U
#define INTSEL_IRQ69			69U
#define INTSEL_IRQ70			70U
#define INTSEL_IRQ71			71U
#define INTSEL_IRQ72			72U
#define INTSEL_IRQ73			73U
#define INTSEL_IRQ74			74U
#define INTSEL_IRQ75			75U
#define INTSEL_IRQ76			76U
#define INTSEL_IRQ77			77U
#define INTSEL_IRQ78			78U
#define INTSEL_IRQ79			79U
#define INTSEL_IRQ80			80U
#define INTSEL_IRQ81			81U
#define INTSEL_IRQ82			82U
#define INTSEL_IRQ83			83U
#define INTSEL_IRQ84			84U
#define INTSEL_IRQ85			85U
#define INTSEL_IRQ86			86U
#define INTSEL_IRQ87			87U
#define INTSEL_IRQ88			88U
#define INTSEL_IRQ89			89U
#define INTSEL_IRQ90			90U
#define INTSEL_IRQ91			91U
#define INTSEL_IRQ92			92U
#define INTSEL_IRQ93			93U
#define INTSEL_IRQ94			94U
#define INTSEL_IRQ95			95U
#define INTSEL_INTERR			96U
#define INTSEL_EMC_IDMAERR		97U

#define INTSEL_MDMAERREVT		110U

#define INTSEL_L1P_ED			113U

#define INTSEL_L2_ED1			116U
#define INTSEL_L2_ED2			117U
#define INTSEL_PDC_INT			118U
#define INTSEL_SYS_CMPA			119U
#define INTSEL_L1P_CMPA			120U
#define INTSEL_L1P_DMPA			121U
#define INTSEL_L1D_CMPA			122U
#define INTSEL_L1D_DMPA			123U
#define INTSEL_L2_CMPA			124U
#define INTSEL_L2_DMPA			125U
#define INTSEL_EMC_CMPA			126U
#define INTSEL_EMC_BUSERR		127U

struct AEGMUX0_BITS {
	Uint32	AEGSEL0:8;
	Uint32	AEGSEL1:8;
	Uint32	AEGSEL2:8;
	Uint32	AEGSEL3:8;
};

union AEGMUX0_REG {
	Uint32						all;
	struct AEGMUX0_BITS			bit;
};

struct AEGMUX1_BITS {
	Uint32	AEGSEL4:8;
	Uint32	AEGSEL5:8;
	Uint32	AEGSEL6:8;
	Uint32	AEGSEL7:8;
};

union AEGMUX1_REG {
	Uint32						all;
	struct AEGMUX1_BITS			bit;
};

// AEGMUX Register.
//// AEGMUX Register : AEGSEL Bit Value
#define AEGSEL_EVT0_EVT0to31	0U
#define AEGSEL_EVT1_EVT32to63	1U
#define AEGSEL_EVT2_EVT64to95	2U
#define AEGSEL_EVT3_EVT96to127	3U

#define AEGSEL_IDMAINT0			13U
#define AEGSEL_IDMAINT1			14U

#define AEGSEL_IRQ32			32U
#define AEGSEL_IRQ33			33U
#define AEGSEL_IRQ34			34U
#define AEGSEL_IRQ35			35U
#define AEGSEL_IRQ36			36U
#define AEGSEL_IRQ37			37U
#define AEGSEL_IRQ38			38U
#define AEGSEL_IRQ39			39U
#define AEGSEL_IRQ40			40U
#define AEGSEL_IRQ41			41U
#define AEGSEL_IRQ42			42U
#define AEGSEL_IRQ43			43U
#define AEGSEL_IRQ44			44U
#define AEGSEL_IRQ45			45U
#define AEGSEL_IRQ46			46U
#define AEGSEL_IRQ47			47U
#define AEGSEL_IRQ48			48U
#define AEGSEL_IRQ49			49U
#define AEGSEL_IRQ50			50U
#define AEGSEL_IRQ51			51U
#define AEGSEL_IRQ52			52U
#define AEGSEL_IRQ53			53U
#define AEGSEL_IRQ54			54U
#define AEGSEL_IRQ55			55U
#define AEGSEL_IRQ56			56U
#define AEGSEL_IRQ57			57U
#define AEGSEL_IRQ58			58U
#define AEGSEL_IRQ59			59U
#define AEGSEL_IRQ60			60U
#define AEGSEL_IRQ61			61U
#define AEGSEL_IRQ62			62U
#define AEGSEL_IRQ63			63U
#define AEGSEL_IRQ64			64U
#define AEGSEL_IRQ65			65U
#define AEGSEL_IRQ66			66U
#define AEGSEL_IRQ67			67U
#define AEGSEL_IRQ68			68U
#define AEGSEL_IRQ69			69U
#define AEGSEL_IRQ70			70U
#define AEGSEL_IRQ71			71U
#define AEGSEL_IRQ72			72U
#define AEGSEL_IRQ73			73U
#define AEGSEL_IRQ74			74U
#define AEGSEL_IRQ75			75U
#define AEGSEL_IRQ76			76U
#define AEGSEL_IRQ77			77U
#define AEGSEL_IRQ78			78U
#define AEGSEL_IRQ79			79U
#define AEGSEL_IRQ80			80U
#define AEGSEL_IRQ81			81U
#define AEGSEL_IRQ82			82U
#define AEGSEL_IRQ83			83U
#define AEGSEL_IRQ84			84U
#define AEGSEL_IRQ85			85U
#define AEGSEL_IRQ86			86U
#define AEGSEL_IRQ87			87U
#define AEGSEL_IRQ88			88U
#define AEGSEL_IRQ89			89U
#define AEGSEL_IRQ90			90U
#define AEGSEL_IRQ91			91U
#define AEGSEL_IRQ92			92U
#define AEGSEL_IRQ93			93U
#define AEGSEL_IRQ94			94U
#define AEGSEL_IRQ95			95U
#define AEGSEL_INTERR			96U
#define AEGSEL_EMC_IDMAERR		97U

#define AEGSEL_MDMAERREVT		110U

#define AEGSEL_L1P_ED			113U

#define AEGSEL_L2_ED1			116U
#define AEGSEL_L2_ED2			117U
#define AEGSEL_PDC_INT			118U
#define AEGSEL_SYS_CMPA			119U
#define AEGSEL_L1P_CMPA			120U
#define AEGSEL_L1P_DMPA			121U
#define AEGSEL_L1D_CMPA			122U
#define AEGSEL_L1D_DMPA			123U
#define AEGSEL_L2_CMPA			124U
#define AEGSEL_L2_DMPA			125U
#define AEGSEL_EMC_CMPA			126U
#define AEGSEL_EMC_BUSERR		127U

#define AEGSEL_EXCEP			192U
#define AEGSEL_NMI				193U

#define AEGSEL_DSPINT4			196U
#define AEGSEL_DSPINT5			197U
#define AEGSEL_DSPINT6			198U
#define AEGSEL_DSPINT7			199U
#define AEGSEL_DSPINT8			200U
#define AEGSEL_DSPINT9			201U
#define AEGSEL_DSPINT10			202U
#define AEGSEL_DSPINT11			203U
#define AEGSEL_DSPINT12			204U
#define AEGSEL_DSPINT13			205U
#define AEGSEL_DSPINT14			206U
#define AEGSEL_DSPINT15			207U

#define AEGSEL_IACK				224U
#define AEGSEL_EACK				225U

#define AEGSEL_IACK4			228U
#define AEGSEL_IACK5			229U
#define AEGSEL_IACK6			230U
#define AEGSEL_IACK7			231U
#define AEGSEL_IACK8			232U
#define AEGSEL_IACK9			233U
#define AEGSEL_IACK10			234U
#define AEGSEL_IACK11			235U
#define AEGSEL_IACK12			236U
#define AEGSEL_IACK13			237U
#define AEGSEL_IACK14			238U
#define AEGSEL_IACK15			239U

struct INTXSTAT_BITS {
	Uint32	DROP:1;
	Uint32	rsvd0:15;
	Uint32	DSPINT:8;
	Uint32	SYSINT:8;
};

union INTXSTAT_REG {
	Uint32						all;
	struct INTXSTAT_BITS		bit;
};

struct INTXCLR_BITS {
	Uint32	CLEAR:1;
	Uint32	rsvd0:31;
};

union INTXCLR_REG {
	Uint32						all;
	struct INTXCLR_BITS			bit;
};

struct INTDMASK_BITS {
	Uint32	rsvd0:4;
	Uint32	IDM4:1;
	Uint32	IDM5:1;
	Uint32	IDM6:1;
	Uint32	IDM7:1;
	Uint32	IDM8:1;
	Uint32	IDM9:1;
	Uint32	IDM10:1;
	Uint32	IDM11:1;
	Uint32	IDM12:1;
	Uint32	IDM13:1;
	Uint32	IDM14:1;
	Uint32	IDM15:1;
	Uint32	rsvd1:16;
};

union INTDMASK_REG {
	Uint32						all;
	struct INTDMASK_BITS		bit;
};

// INTDMASK Register.
//// INTDMASK Register : Byte Value.
#define INTDMASK_IDM4_INT4Ignore		0x00000010
#define INTDMASK_IDM5_INT5Ignore		0x00000020
#define INTDMASK_IDM6_INT6Ignore		0x00000040
#define INTDMASK_IDM7_INT7Ignore		0x00000080
#define INTDMASK_IDM8_INT8Ignore		0x00000100
#define INTDMASK_IDM9_INT9Ignore		0x00000200
#define INTDMASK_IDM10_INT10Ignore		0x00000400
#define INTDMASK_IDM11_INT11Ignore		0x00000800
#define INTDMASK_IDM12_INT12Ignore		0x00001000
#define INTDMASK_IDM13_INT13Ignore		0x00002000
#define INTDMASK_IDM14_INT14Ignore		0x00004000
#define INTDMASK_IDM15_INT15Ignore		0x00008000

//// INTDMASK Register : Quick Value.
#define INTDMASK_IDMAll_INTAllIgnore	0x0000FFF0

// -------------------- Registers Define --------------------//
struct DSP_ICFG_REGS {								// Offset
	union EVT0_REG				EVTFLAG0;			// 0x0000
	union EVT1_REG				EVTFLAG1;			// 0x0004
	union EVT2_REG				EVTFLAG2;			// 0x0008
	union EVT3_REG				EVTFLAG3;			// 0x000C
	Uint32						rsvd1[4];			// 0x0010
	union EVT0_REG				EVTSET0;			// 0x0020
	union EVT1_REG				EVTSET1;			// 0x0024
	union EVT2_REG				EVTSET2;			// 0x0028
	union EVT3_REG				EVTSET3;			// 0x002C
	Uint32						rsvd3[4];			// 0x0030
	union EVT0_REG				EVTCLR0;			// 0x0040
	union EVT1_REG				EVTCLR1;			// 0x0044
	union EVT2_REG				EVTCLR2;			// 0x0048
	union EVT3_REG				EVTCLR3;			// 0x004C
	Uint32						rsvd5[4];			// 0x0050
	Uint32						rsvd6[4];			// 0x0060
	Uint32						rsvd7[4];			// 0x0070
	union EVT0_REG				EVTMASK0;			// 0x0080
	union EVT1_REG				EVTMASK1;			// 0x0084
	union EVT2_REG				EVTMASK2;			// 0x0088
	union EVT3_REG				EVTMASK3;			// 0x008C
	Uint32						rsvd9[4];			// 0x0090
	union EVT0_REG				MEVTFLAG0;			// 0x00A0
	union EVT1_REG				MEVTFLAG1;			// 0x00A4
	union EVT2_REG				MEVTFLAG2;			// 0x00A8
	union EVT3_REG				MEVTFLAG3;			// 0x00AC
	Uint32						rsvdB[4];			// 0x00B0
	union EVT0_REG				EXPMASK0;			// 0x00C0
	union EVT1_REG				EXPMASK1;			// 0x00C4
	union EVT2_REG				EXPMASK2;			// 0x00C8
	union EVT3_REG				EXPMASK3;			// 0x00CC
	Uint32						rsvdD[4];			// 0x00D0
	union EVT0_REG				MEXPFLAG0;			// 0x00E0
	union EVT1_REG				MEXPFLAG1;			// 0x00E4
	union EVT2_REG				MEXPFLAG2;			// 0x00E8
	union EVT3_REG				MEXPFLAG3;			// 0x00EC
	Uint32						rsvdF[4];			// 0x00F0
	Uint32						rsvd10_0;			// 0x0100
	union INTMUX1_REG			INTMUX1;			// 0x0104
	union INTMUX2_REG			INTMUX2;			// 0x0108
	union INTMUX3_REG			INTMUX3;			// 0x010C
	Uint32						rsvd11[4];			// 0x0110
	Uint32						rsvd12[4];			// 0x0120
	Uint32						rsvd13[4];			// 0x0130
	union AEGMUX0_REG			AEGMUX0;			// 0x0140
	union AEGMUX1_REG			AEGMUX1;			// 0x0144
	Uint32						rsvd14_8;			// 0x0148
	Uint32						rsvd14_C;			// 0x014C
	Uint32						rsvd15[4];			// 0x0150
	Uint32						rsvd16[4];			// 0x0160
	Uint32						rsvd17[4];			// 0x0170
	union INTXSTAT_REG			INTXSTAT;			// 0x0180
	union INTXCLR_REG			INTXCLR;			// 0x0184
	union INTDMASK_REG			INTDMAKS;			// 0x0188
};

extern volatile struct DSP_ICFG_REGS	DSP_ICFGRegs;

#ifdef __cplusplus
}
#endif

#endif /* AM572X_C66_DSP_ICFG_H_ */
