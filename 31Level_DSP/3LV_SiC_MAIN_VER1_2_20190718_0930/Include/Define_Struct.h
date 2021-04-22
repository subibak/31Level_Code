/*
 * Define_Struct.h
 *
 *  Created on: 2019. 6. 26.
 *      Author: HJHeo
 */

#ifndef INCLUDE_DEFINE_STRUCT_H_
#define INCLUDE_DEFINE_STRUCT_H_

#ifdef __cplusplus
extern "C" {
#endif

//*************** Basic Structure ***************//
// Float Type Low Pass Value.
typedef struct {
	float	now;
	float	old;
	float	low;
	float	La;
	float	Lb;
} S_FLPF;

// Uint16 Type Three-Phase Value.
typedef struct {
	Uint16	a;
	Uint16	b;
	Uint16	c;
} S_UTP;

// Float Type Three-Phase Value.
typedef struct {
	float	a;
	float	b;
	float	c;
} S_FTP;

// Float Type Three-Phase Pole Value.
typedef struct {
	float	a;
	float	b;
	float	c;
	float	s;
} S_FPL;

// Uint16 Type Three-Phase Line to Line Value.
typedef struct {
	Uint16	ab;
	Uint16	bc;
	Uint16	ca;
} S_ULL;

// Float Type Three-Phase Line to Line Value.
typedef struct {
	float	ab;
	float	bc;
	float	ca;
} S_FLL;

// Float Type DQ-Axis Value.
typedef struct {
	float	d;
	float	q;
} S_FDQ;

// Float Type DQ-Axis Value with LPF.
typedef struct {
	S_FLPF	d;
	S_FLPF	q;
} S_FDQLPF;

//*************** System Parameter ***************//
// Sampling Time Value.
typedef struct {
	struct {
		Uint16	PERIOD;
		float	TIME;
		float	FREQ;
	} TIMEBASE;
	struct {
		Uint16	PERIOD;
		Uint16	PERIOD_HALF;
		float	TIME;
		float	FREQ;
	} PWM;
	struct {
		Uint16	PERIOD;
		float	TIME;
		float	FREQ;
	} OUTERLOOP;
	struct {
		Uint16	PERIOD;
		float	TIME;
	} DEADTIME;
	struct {
		Uint32	COUNT_MAX;
		float	INV_COUNT_MAX;
	} OFFSET;
} S_STV;

// Motor/Converter Parameter.
typedef struct {
	S_FDQ	Rs;
	S_FDQ	Ls;
	float	Ke;
	float	Pole_Pairs;
} S_PRM;

//*************** Control ***************//
// Motor Control Value.
typedef struct {
	union {
		Uint16	all;
		struct {
			Uint16	VF:1;
			Uint16	Align:1;
			Uint16	V:1;
			Uint16	Current:1;
			Uint16	Speed:1;
		} bit;
	} Flag;
	struct {
		float	Vde_ref;
		float	Vqe_ref;
		float	Freq;
		float	Theta;
	} VF_V;
	struct {
		float	Vds_ref;
	} Align;
	struct {
		float	Ide_ref;
		float	Iqe_ref;
	} Current;
	struct {
		float	rpm_ref;
		float	Iqe_max;
	} Speed;
} S_MTC;

// Converter Control Value.
typedef struct {
	union {
		Uint16	all;
		struct {
			Uint16	VF:1;
			Uint16	Align:1;
			Uint16	V:1;
			Uint16	Current:1;
			Uint16	Voltage:1;
		} bit;
	} Flag;
	struct {
		float	Vde_ref;
		float	Vqe_ref;
		float	Freq;
		float	Theta;
	} VF_V;
	struct {
		float	Vds_ref;
	} Align;
	struct {
		float	Ide_ref;
		float	Iqe_ref;
	} Current;
	struct {
		float	Vdc_ref;
		float	Iqe_max;
	} Voltage;
} S_CVC;

//// Control Value : Predefine Value.
#define MODE_VF					0x0001
#define MODE_ALIGN				0x0002
#define MODE_V					0x0004
#define MODE_CURRENT			0x0008
#define MODE_SPEED				0x0010
#define MODE_VOLTAGE			0x0010

#define MODE_VF_INV				0x8001
#define MODE_ALIGN_INV			0x8002
#define MODE_V_INV				0x8004
#define MODE_CURRENT_INV		0x8008
#define MODE_SPEED_INV			0x8010
#define MODE_VOLTAGE_INV		0x8010

//*************** Control Gain ***************//
// PI-Controller Gain Value.
typedef struct {
	float	p;
	float	i;
	float	a;
} S_PIC;

// DQ-Axis PI-Controller Gain Value.
typedef struct {
	S_FDQ	p;
	S_FDQ	i;
	S_FDQ	a;
} S_DQPIC;

// PD-Controller Gain Value.
typedef struct {
	float	d;
	float	p;
} S_PDC;

//*************** Angle & Speed ***************//
// Angle(Theta) Value.
typedef struct {
	float	m_now;
	float	e_now;
	float	e_offset;
	float	e_sin;
	float	e_cos;
	struct {
		float		now;
		float		old;
		Uint16		dir;
		const float	PPR;
		const float	INV_PPR;
	} COUNT;
} S_THT;

// Speed Value.
typedef struct {
	struct {
		float	now;
		float	old;
		float	low;
		float	La;
		float	Lb;
	} RPM;

	struct {
		float	low;
	} Wm;

	struct {
		float	low;
	} We;
} S_SPD;

//*************** Count & Flag ***************//
// Counter Value.
typedef struct {
	Uint32	Offset;
	Uint16	OuterLoop;
} S_CNT;

// Flag Value.
typedef struct {
	Uint16	Inverter;
	Uint16	OuterLoop;
	Uint16	OM;
} S_FLG;

//*************** Fault ***************//
// Fault Register Value.
typedef union {
	Uint16	all;
	struct {
		Uint16	OC_A:1;
		Uint16	OC_B:1;
		Uint16	OC_C:1;
		Uint16	OS:1;
		Uint16	UV:1;
		Uint16	OV:1;
	} bit;
} U_FTR;

// Fault Level Value.
typedef struct {
	float	Ioc;
	float	RPMos;
	float	VDCuv;
	float	VDCov;
} S_FTL;

//*************** DC-Link ***************//
// Voltage Value.
typedef struct {
	struct {
		float	low;
		float	INV_low;
	} dc;
	struct {
		float	low;
	} diff;
	struct {
		float	now;
		float	old;
		float	low;
		float	INV_low;
		float	offset;
		float	La;
		float	Lb;
	} p;
	struct {
		float	now;
		float	old;
		float	low;
		float	INV_low;
		float	offset;
		float	La;
		float	Lb;
	} n;
	struct {
		Uint16	Flag;
		struct {
			float	p;
			float	n;
		} Value;
	} IMG;
} S_VDC;


#ifdef __cplusplus
}
#endif

#endif /* INCLUDE_DEFINE_STRUCT_H_ */
