;/*
; * TMU.asm
; *
; *  Created on: 2018. 10. 8.
; *      Author: HJHeo
; */

;// Assembly Function Define
	.def	_MPY2PIF32
	.def	_DIV2PIF32
	.def	_DIVF32
	.def	_SQRTF32
	.def	_SINF32
	.def	_COSF32
	.def	_ATANF32

_MPY2PIF32
	MPY2PIF32	R0H, R0H		; R0H = R0H * PI2
	NOP							; Pipeline Delay.
	LRETR

_DIV2PIF32
	DIV2PIF32	R0H, R0H		; R0H = R0H / PI2
	NOP							; Pipeline Delay.
	LRETR

;// C Prototype float RST = DIVF32(float NUM, float DEN)
;// NUM	: R0H
;// DEN : R1H
;// RST = NUM / DEN
_DIVF32:
	DIVF32		R0H, R0H, R1H	; R0H = R0H / R1H.
	NOP							; Pipeline Delay.
	NOP							; Pipeline Delay.
	NOP							; Pipeline Delay.
	NOP							; Pipeline Delay.
	LRETR

;// C Prototype float RST = SQRTF32(float VAL)
;// VAL	: R0H
;// RST = sqrt(VAL)
_SQRTF32:
	SQRTF32		R0H, R0H		; R1H = sqrt(R0H)
	NOP							; Pipeline Delay.
	NOP							; Pipeline Delay.
	NOP							; Pipeline Delay.
	NOP							; Pipeline Delay.
	LRETR

;// C Prototype float RST = SINF32(float VAL)
;// VAL	: R0H (-PI2 ~ PI2)
;// RST = sin(VAL)
_SINF32:
	DIV2PIF32	R1H, R0H		; R1H = R0H / PI2
	NOP							; Pipeline Delay.
	SINPUF32	R0H, R1H		; R2H = sin(R1H)
	NOP							; Pipeline Delay.
	NOP							; Pipeline Delay.
	NOP							; Pipeline Delay.
	LRETR

;// C Prototype float RST = COSF32(float VAL)
;// VAL	: R0H (-PI2 ~ PI2)
;// RST = cos(VAL)
_COSF32:
	DIV2PIF32	R1H, R0H		; R1H = R0H / PI2
	NOP							; Pipeline Delay.
	COSPUF32	R0H, R1H		; R2H = cos(R1H)
	NOP							; Pipeline Delay.
	NOP							; Pipeline Delay.
	NOP							; Pipeline Delay.
	LRETR

;// C Prototype float RST = ATANF32(float VAL)
;// VAL	: R0H (-1.0 ~ 1.0)
;// RST = atan(VAL)
_ATANF32:
	ATANPUF32	R1H, R0H		; R1H = atan(R0H)
	NOP							; Pipeline Delay.
	NOP							; Pipeline Delay.
	NOP							; Pipeline Delay.
	MPY2PIF32	R0H, R1H		; R0H = R1H * PI2
	NOP							; Pipeline Delay.
	LRETR
