/*
 * GPIO.c
 *
 *  Created on: 2015. 8. 12.
 *      Author: cjs9426
 *  Revised on: 2018. 9. 29.
 *      Resier: subi
 */


#include "Define_Header.h"

#ifdef CPU1
void Init_GPIO(void)
{
    EALLOW;
    //-------------------------------------------------------------------------------------------------//
    //-------------------------------------------- GPIOA-1 --------------------------------------------//
    //-------------------------------------------------------------------------------------------------//
    // GPIOA-1 MUX                          ; [GPxGMUXn,GPxMUXn]
    GpioCtrlRegs.GPAGMUX1.bit.GPIO0 = 0;    // [n,0](GPIO0),            [0,1](EPWM1A[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;     // [1,1](Reserved),         [1,2](SDAA[I/OD]),          [1,3](Reserved),            [3,3](Reserved)         ;nc

    GpioCtrlRegs.GPAGMUX1.bit.GPIO1 = 0;    // [n,0](GPIO1),            [0,1](EPWM1B[O]),           [0,2](Reserved),            [0,3](MFSRB[I/O])
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;     // [1,1](Reserved),         [1,2](SCLA[I/OD]),          [1,3](Reserved),            [3,3](Reserved)         ;nc

    GpioCtrlRegs.GPAGMUX1.bit.GPIO2 = 0;    // [n,0](GPIO2),            [0,1](EPWM2A[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;     // [1,1](OUTPUTXBAR1[O]),   [1,2](SDAB[I/OD]),          [1,3](Reserved),            [3,3](Reserved)         ;nc

    GpioCtrlRegs.GPAGMUX1.bit.GPIO3 = 0;    // [n,0](GPIO3),            [0,1](EPWM2B[O]),           [0,2](OUTPUTXBAR2[O]),      [0,3](MCLKRB[I/O])
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;     // [1,1](OUTPUTXBAR2[O]),   [1,2](SCLB[I/OD]),          [1,3](Reserved),            [3,3](Reserved)         ;nc

    GpioCtrlRegs.GPAGMUX1.bit.GPIO4 = 0;    // [n,0](GPIO4),            [0,1](EPWM3A[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 0;     // [1,1](OUTPUTXBAR3[O]),   [1,2](CANTXA[O]),           [1,3](Reserved),            [3,3](Reserved)         ;nc

    GpioCtrlRegs.GPAGMUX1.bit.GPIO5 = 0;    // [n,0](GPIO5),            [0,1](EPWM3B[O]),           [0,2](MFSRA[I/O]),          [0,3](OUTPUTXBAR3[O])
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 0;     // [1,1](Reserved),         [1,2](CANRXA[I]),           [1,3](Reserved),            [3,3](Reserved)         ;nc

    GpioCtrlRegs.GPAGMUX1.bit.GPIO6 = 0;    // [n,0](GPIO6),            [0,1](EPWM4A[O]),           [0,2](OUTPUTXBAR4[O]),      [0,3](EPWMSYNCO[O])
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0;     // [1,1](EQEP3A[I]),        [1,2](CANTXB[O]),           [1,3](Reserved),            [3,3](Reserved)         ;nc

    GpioCtrlRegs.GPAGMUX1.bit.GPIO7 = 0;    // [n,0](GPIO7),            [0,1](EPWM4B[O]),           [0,2](MCLKRA[I/O]),         [0,3](OUTPUTXBAR5[O])
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 0;     // [1,1](EQEP3B[I]),        [1,2](CANRXB[I]),           [1,3](Reserved),            [3,3](Reserved)         ;nc

    GpioCtrlRegs.GPAGMUX1.bit.GPIO8 = 0;    // [n,0](GPIO8),            [0,1](EPWM5A[O]),           [0,2](CANTXB[O]),           [0,3](ADCSOCAO[O])
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 0;     // [1,1](EQEP3S[I/O]),      [1,2](SCITXDA[O]),          [1,3](Reserved),            [3,3](Reserved)         ;nc

    GpioCtrlRegs.GPAGMUX1.bit.GPIO9 = 0;    // [n,0](GPIO9),            [0,1](EPWM5B[O]),           [0,2](SCITXDB[O]),          [0,3](OUTPUTXBAR6[O])   ;nc
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 0;     // [1,1](EQEP3I[I/O]),      [1,2](SCIRXDA[I]),          [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPAGMUX1.bit.GPIO10 = 0;   // [n,0](GPIO10),           [0,1](EPWM6A[O]),           [0,2](CANRXB[I]),           [0,3](ADCSOCBO[O])
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0;    // [1,1](EQEP1A[I]),        [1,2](SCITXDB[O]),          [1,3](Reserved),            [3,3](UPP-WAIT[I/O])    ;nc

    GpioCtrlRegs.GPAGMUX1.bit.GPIO11 = 0;   // [n,0](GPIO11),           [0,1](EPWM6B[O]),           [0,2](SCIRXDB[I]),          [0,3](OUTPUTXBAR7[O])
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0;    // [1,1](EQEP1B[I]),        [1,2](SCIRXDB[I]),          [1,3](Reserved),            [3,3](UPP-START[I/O])

    GpioCtrlRegs.GPAGMUX1.bit.GPIO12 = 0;   // [n,0](GPIO12),           [0,1](EPWM7A[O]),           [0,2](CANTXB[O]),           [0,3](MDXB[O])          ;nc
    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 0;    // [1,1](EQEP1S[I/O]),      [1,2](SCITXDC[O]),          [1,3](Reserved),            [3,3](UPP-ENA[I/O])

    GpioCtrlRegs.GPAGMUX1.bit.GPIO13 = 0;   // [n,0](GPIO13),           [0,1](EPWM7B[O]),           [0,2](CANRXB[I]),           [0,3](MDRB[I])          ;Pin_D1_DSP
    GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 0;    // [1,1](EQEP1I[I/O]),      [1,2](SCIRXDC[I]),          [1,3](Reserved),            [3,3](UPP-D7[I/O])

    GpioCtrlRegs.GPAGMUX1.bit.GPIO14 = 0;   // [n,0](GPIO14),           [0,1](EPWM8A[O]),           [0,2](SCITXDB[O]),          [0,3](MCLKXB[I/O])      ;Pin_D2_DSP
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0;    // [1,1](Reserved),         [1,2](OUTPUTXBAR3[O]),      [1,3](Reserved),            [3,3](UPP-D6[I/O])

    GpioCtrlRegs.GPAGMUX1.bit.GPIO15 = 0;   // [n,0](GPIO15),           [0,1](EPWM8B[O]),           [0,2](SCIRXDB[I]),          [0,3](MFSXB[I/O])       ;nc
    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 0;    // [1,1](Reserved),         [1,2](OUTPUTXBAR4[O]),      [1,3](Reserved),            [3,3](UPP-D5[I/O])

    // GPIOA-1 Input/Output of GPIO         ; 0(Input), 1(Output)
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO3 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO4 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO5 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO6 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO7 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO8 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO9 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO10 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO11 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO12 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO13 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO14 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO15 = 0;

    // GPIOA-1 Sampling Frequency of GPIO   ; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)    : 0(/1), 1(/2), 2(/4), ..., 255(/510)
    GpioCtrlRegs.GPACTRL.bit.QUALPRD0 = 0;  //GPIO0 ~ GPIO7
    GpioCtrlRegs.GPACTRL.bit.QUALPRD1 = 0;  //GPIO8 ~ GPIO15

    // GPIOA-1 Qualification Mode           ; ACQCLK = SAMPCLK/GPAQSELn             : 0(/1), 1(/2), 2(/5), 3(ASYNCH)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO0 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO1 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO2 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO3 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO4 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO5 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO6 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO7 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO8 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO9 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO10 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO11 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 0;
    GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 0;

    // GPIOA-1 Internal Pull-up             ; 0(Enable), 1(Disable)
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO9 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO12 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO13 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO15 = 1;

    // GPIOA-1 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPACSEL1.bit.GPIO0 = 0;
    GpioCtrlRegs.GPACSEL1.bit.GPIO1 = 0;
    GpioCtrlRegs.GPACSEL1.bit.GPIO2 = 0;
    GpioCtrlRegs.GPACSEL1.bit.GPIO3 = 0;
    GpioCtrlRegs.GPACSEL1.bit.GPIO4 = 0;
    GpioCtrlRegs.GPACSEL1.bit.GPIO5 = 0;
    GpioCtrlRegs.GPACSEL1.bit.GPIO6 = 0;
    GpioCtrlRegs.GPACSEL1.bit.GPIO7 = 0;
    // GPIOA-2 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPACSEL2.bit.GPIO8 = 0;
    GpioCtrlRegs.GPACSEL2.bit.GPIO9 = 0;
    GpioCtrlRegs.GPACSEL2.bit.GPIO11 = 0;
    GpioCtrlRegs.GPACSEL2.bit.GPIO12 = 0;
    GpioCtrlRegs.GPACSEL2.bit.GPIO13 = 2;
    GpioCtrlRegs.GPACSEL2.bit.GPIO14 = 2;
    GpioCtrlRegs.GPACSEL2.bit.GPIO15 = 0;
    //-------------------------------------------------------------------------------------------------//
    //-------------------------------------------- GPIOA-2 --------------------------------------------//
    //-------------------------------------------------------------------------------------------------//
    // GPIOA-2 MUX                          ; [GPxGMUXn,GPxMUXn]
    GpioCtrlRegs.GPAGMUX2.bit.GPIO16 = 0;   // [n,0](GPIO16),           [0,1](SPISIMOA[I/O]),       [0,2](CANTXB[O]),           [0,3](OUTPUTXBAR7[O])
    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 1;    // [1,1](EPWM9A[O]),        [1,2](Reserved),            [1,3](SD1_D1[I]),           [3,3](UPP-D4[I/O])      ;SPISIMOA(Flash ROM)

    GpioCtrlRegs.GPAGMUX2.bit.GPIO17 = 0;   // [n,0](GPIO17),           [0,1](SPISOMIA[I/O]),       [0,2](CANRXB[I]),           [0,3](OUTPUTXBAR8[O])
    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 1;    // [1,1](EPWM9B[O]),        [1,2](Reserved),            [1,3](SD1_C1[I]),           [3,3](UPP-D3[I/O])      ;SPISOMIA(Flash ROM)

    GpioCtrlRegs.GPAGMUX2.bit.GPIO18 = 0;   // [n,0](GPIO18),           [0,1](SPICLKA[I/O]),        [0,2](SCITXDB[O]),          [0,3](CANRXA[I])
    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 1;    // [1,1](EPWM10A[O]),       [1,2](Reserved),            [1,3](SD1_D2[I]),           [3,3](UPP-D2[I/O])      ;SPICLKA(Flash ROM)

    GpioCtrlRegs.GPAGMUX2.bit.GPIO19 = 0;   // [n,0](GPIO19),           [0,1](SPISTEAn[I/O]),       [0,2](SCIRXDB[I]),          [0,3](CANTXA[O])
    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 1;    // [1,1](EPWM10B[O]),       [1,2](Reserved),            [1,3](SD1_C2[I]),           [3,3](UPP-D1[I/O])      ;/SPISTEA(Flash ROM)

    GpioCtrlRegs.GPAGMUX2.bit.GPIO20 = 0;   // [n,0](GPIO20),           [0,1](EQEP1A[I]),           [0,2](MDXA[O]),             [0,3](CANTXB[O])        ;Pin_F2_DSP
    GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 0;    // [1,1](EPWM11A[O]),       [1,2](Reserved),            [1,3](SD1_D3[I]),           [3,3](UPP-D0[I/O])

    GpioCtrlRegs.GPAGMUX2.bit.GPIO21 = 0;   // [n,0](GPIO21),           [0,1](EQEP1B[I]),           [0,2](MDRA[I]),             [0,3](CANRXB[I])
    GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 0;    // [1,1](EPWM11B[O]),       [1,2](Reserved),            [1,3](SD1_C3[I]),           [3,3](UPP-CLK[I/O])     ;Pin_F3_DSP

    GpioCtrlRegs.GPAGMUX2.bit.GPIO22 = 0;   // [n,0](GPIO22),           [0,1](EQEP1S[I/O]),         [0,2](MCLKXA[I/O]),         [0,3](SCITXDB[O])
    GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 0;    // [1,1](EPWM12A[O]),       [1,2](SPICLKB[I/O]),        [1,3](SD1_D4[I]),           [3,3](Reserved)         ;Pin_J4_DSP

    GpioCtrlRegs.GPAGMUX2.bit.GPIO23 = 0;   // [n,0](GPIO23),           [0,1](EQEP1I[I/O]),         [0,2](MFSXA[I/O]),          [0,3](SCIRXDB[I])       ;Pin_K4_DSP
    GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 0;    // [1,1](EPWM12B[O]),       [1,2](SPISTEBn[I/O]),       [1,3](SD1_C4[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPAGMUX2.bit.GPIO24 = 0;   // [n,0](GPIO24),           [0,1](OUTPUTXBAR1[O]),      [0,2](EQEP2A[I]),           [0,3](MDXB[O])          ;nc
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0;    // [1,1](Reserved),         [1,2](SPISIMOB[I/O]),       [1,3](SD2_D1[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPAGMUX2.bit.GPIO25 = 0;   // [n,0](GPIO25),           [0,1](OUTPUTXBAR2[O]),      [0,2](EQEP2B[I]),           [0,3](MDRB[I])          ;nc
    GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 0;    // [1,1](Reserved),         [1,2](SPISOMIB[I/O]),       [1,3](SD2_C1[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPAGMUX2.bit.GPIO26 = 0;   // [n,0](GPIO26),           [0,1](OUTPUTXBAR3[O]),      [0,2](EQEP2I[I/O]),         [0,3](MCLKXB[I/O])      ;Led4
    GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 0;    // [1,1](OUTPUTXBAR3[O]),   [1,2](SPICLKB[I/O]),        [1,3](SD2_D2[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPAGMUX2.bit.GPIO27 = 0;   // [n,0](GPIO27),           [0,1](OUTPUTXBAR4[O]),      [0,2](EQEP2S[I/O]),         [0,3](MFSXB[I/O])       ;Led5
    GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 0;    // [1,1](OUTPUTXBAR4[O]),   [1,2](SPISTEBn[I/O]),       [1,3](SD2_C2[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPAGMUX2.bit.GPIO28 = 1;   // [n,0](GPIO28),           [0,1](SCIRXDA[I]),          [0,2](EM1CS4n[O]),          [0,3](Reserved)         ;EM1CS4n
    GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1;    // [1,1](OUTPUTXBAR5[O]),   [1,2](EQEP3A[I]),           [1,3](SD2_D3[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPAGMUX2.bit.GPIO29 = 0;   // [n,0](GPIO29),           [0,1](SCITXDA[O]),          [0,2](EM1SDCKE[O]),         [0,3](Reserved)         ;nc
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 0;    // [1,1](OUTPUTXBAR6[O]),   [1,2](EQEP3B[I]),           [1,3](SD2_C3[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPAGMUX2.bit.GPIO30 = 0;   // [n,0](GPIO30),           [0,1](CANRXA[I]),           [0,2](EM1CLK[O]),           [0,3](Reserved)         ;EM1CLK
    GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 2;    // [1,1](OUTPUTXBAR7[O]),   [1,2](EQEP3S[I/O]),         [1,3](SD2_D4[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPAGMUX2.bit.GPIO31 = 0;   // [n,0](GPIO31),           [0,1](CANTXA[O]),           [0,2](EM1WEn[O]),           [0,3](Reserved)
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 2;    // [1,1](OUTPUTXBAR8[O]),   [1,2](EQEP3I[I/O]),         [1,3](SD2_C4[I]),           [3,3](Reserved)         ;/EM1WE

    // GPIOA-2 Input/Output of GPIO         ; 0(Input), 1(Output)
    GpioCtrlRegs.GPADIR.bit.GPIO16 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO17 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO18 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO19 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO20 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO21 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO22 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO23 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO24 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO25 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO26 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO27 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO28 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO29 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO30 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;

    // GPIOA-2 Sampling Frequency of GPIO   ; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)    : 0(/1), 1(/2), 2(/4), ..., 255(/510)
    GpioCtrlRegs.GPACTRL.bit.QUALPRD2 = 0;  //GPIO15 ~ GPIO23
    GpioCtrlRegs.GPACTRL.bit.QUALPRD3 = 0;  //GPIO24 ~ GPIO31

    // GPIOA-2 Qualification Mode           ; ACQCLK = SAMPCLK/GPAQSELn             : 0(/1), 1(/2), 2(/5), 3(ASYNCH)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO20 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO22 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO23 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO24 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO25 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO27 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO29 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO30 = 0;
    GpioCtrlRegs.GPAQSEL2.bit.GPIO31 = 0;

    // GPIOA-2 Internal Pull-up             ; 0(Enable), 1(Disable)
    GpioCtrlRegs.GPAPUD.bit.GPIO16 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO17 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO18 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO19 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO20 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO21 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO22 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO23 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO24 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO25 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0;
    GpioCtrlRegs.GPAPUD.bit.GPIO27 = 0;
    GpioCtrlRegs.GPAPUD.bit.GPIO28 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO29 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO30 = 1;
    GpioCtrlRegs.GPAPUD.bit.GPIO31 = 1;

    // GPIOA-3 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPACSEL3.bit.GPIO16 = 0;
    GpioCtrlRegs.GPACSEL3.bit.GPIO17 = 0;
    GpioCtrlRegs.GPACSEL3.bit.GPIO18 = 0;
    GpioCtrlRegs.GPACSEL3.bit.GPIO19 = 0;
    GpioCtrlRegs.GPACSEL3.bit.GPIO20 = 0;
    GpioCtrlRegs.GPACSEL3.bit.GPIO21 = 0;
    GpioCtrlRegs.GPACSEL3.bit.GPIO22 = 0;
    GpioCtrlRegs.GPACSEL3.bit.GPIO23 = 0;
    // GPIOA-4 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPACSEL4.bit.GPIO24 = 0;
    GpioCtrlRegs.GPACSEL4.bit.GPIO25 = 0;
    GpioCtrlRegs.GPACSEL4.bit.GPIO26 = 0;
    GpioCtrlRegs.GPACSEL4.bit.GPIO27 = 0;
    GpioCtrlRegs.GPACSEL4.bit.GPIO28 = 2;
    GpioCtrlRegs.GPACSEL4.bit.GPIO29 = 0;
    GpioCtrlRegs.GPACSEL4.bit.GPIO30 = 2;
    GpioCtrlRegs.GPACSEL4.bit.GPIO31 = 2;

    //-------------------------------------------------------------------------------------------------//
    //-------------------------------------------- GPIOB-1 --------------------------------------------//
    //-------------------------------------------------------------------------------------------------//
    // GPIOB-1 MUX                          ; [GPxGMUXn,GPxMUXn]
    GpioCtrlRegs.GPBGMUX1.bit.GPIO32 = 0;   // [n,0](GPIO32),           [0,1](SDAA[I/OD]),          [0,2](EM1CS0n[O]),          [0,3](Reserved)
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0;    // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;nc

    GpioCtrlRegs.GPBGMUX1.bit.GPIO33 = 0;   // [n,0](GPIO33),           [0,1](SCLA[I/OD]),          [0,2](EM1RNW[O]),           [0,3](Reserved)         ;EM1RNW
    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 2;    // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX1.bit.GPIO34 = 0;   // [n,0](GPIO34),           [0,1](OUTPUTXBAR1[O]),      [0,2](EM1CS2n[O]),          [0,3](Reserved)         ;EM1CS2n
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 2;    // [1,1](Reserved),         [1,2](SDAB[I/OD]),          [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX1.bit.GPIO35 = 0;   // [n,0](GPIO35),           [0,1](SCIRXDA[I]),          [0,2](EM1CS3n[O]),          [0,3](Reserved)
    GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 2;    // [1,1](Reserved),         [1,2](SCLB[I/OD]),          [1,3](Reserved),            [3,3](Reserved)         ;EM1CS3n

    GpioCtrlRegs.GPBGMUX1.bit.GPIO36 = 0;   // [n,0](GPIO36),           [0,1](SCITXDA[O]),          [0,2](EM1WAIT[I]),          [0,3](Reserved)         ;EM1WAIT
    GpioCtrlRegs.GPBMUX1.bit.GPIO36 = 2;    // [1,1](Reserved),         [1,2](CANRXA[I]),           [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX1.bit.GPIO37 = 0;   // [n,0](GPIO37),           [0,1](OUTPUTXBAR2[O]),      [0,2](EM1OEn[O]),           [0,3](Reserved)
    GpioCtrlRegs.GPBMUX1.bit.GPIO37 = 2;    // [1,1](Reserved),         [1,2](CANTXA[O]),           [1,3](Reserved),            [3,3](Reserved)         ;/EM1OEn

    GpioCtrlRegs.GPBGMUX1.bit.GPIO38 = 0;   // [n,0](GPIO38),           [0,1](Reserved),            [0,2](EM1A0[O]),            [0,3](Reserved)         ;EM1A0
    GpioCtrlRegs.GPBMUX1.bit.GPIO38 = 2;    // [1,1](SCITXDC[O]),       [1,2](CANTXB[O]),           [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX1.bit.GPIO39 = 0;   // [n,0](GPIO39),           [0,1](Reserved),            [0,2](EM1A1[O]),            [0,3](Reserved)         ;EM1A1
    GpioCtrlRegs.GPBMUX1.bit.GPIO39 = 2;    // [1,1](SCIRXDC[I]),       [1,2](CANRXB[I]),           [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX1.bit.GPIO40 = 0;   // [n,0](GPIO40),           [0,1](Reserved),            [0,2](EM1A2[O]),            [0,3](Reserved)         ;EM1A2
    GpioCtrlRegs.GPBMUX1.bit.GPIO40 = 2;    // [1,1](Reserved),         [1,2](SDAB[I/OD]),          [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX1.bit.GPIO41 = 0;   // [n,0](GPIO41),           [0,1](Reserved),            [0,2](EM1A3[O]),            [0,3](Reserved)         ;EM1A3
    GpioCtrlRegs.GPBMUX1.bit.GPIO41 = 2;    // [1,1](Reserved),         [1,2](SCLB[I/OD]),          [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX1.bit.GPIO42 = 0;   // [n,0](GPIO42),           [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)         ;nc
    GpioCtrlRegs.GPBMUX1.bit.GPIO42 = 0;    // [1,1](Reserved),         [1,2](SDAA[I/OD]),          [1,3](Reserved),            [3,3](SCITXDA[O])

    GpioCtrlRegs.GPBGMUX1.bit.GPIO43 = 0;   // [n,0](GPIO43),           [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)         ;nc
    GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 0;    // [1,1](Reserved),         [1,2](SCLA[I/OD]),          [1,3](Reserved),            [3,3](SCIRXDA[I])

    GpioCtrlRegs.GPBGMUX1.bit.GPIO44 = 0;   // [n,0](GPIO44),           [0,1](Reserved),            [0,2](EM1A4[O]),            [0,3](Reserved)         ;EM1A4
    GpioCtrlRegs.GPBMUX1.bit.GPIO44 = 2;    // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX1.bit.GPIO45 = 0;   // [n,0](GPIO45),           [0,1](Reserved),            [0,2](EM1A5[O]),            [0,3](Reserved)         ;EM1A5
    GpioCtrlRegs.GPBMUX1.bit.GPIO45 = 2;    // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX1.bit.GPIO46 = 0;   // [n,0](GPIO46),           [0,1](Reserved),            [0,2](EM1A6[O]),            [0,3](Reserved)         ;EM1A6
    GpioCtrlRegs.GPBMUX1.bit.GPIO46 = 2;    // [1,1](Reserved),         [1,2](SCIRXDD[I]),          [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX1.bit.GPIO47 = 0;   // [n,0](GPIO47),           [0,1](Reserved),            [0,2](EM1A7[O]),            [0,3](Reserved)         ;EM1A7
    GpioCtrlRegs.GPBMUX1.bit.GPIO47 = 2;    // [1,1](Reserved),         [1,2](SCITXDD[O]),          [1,3](Reserved),            [3,3](Reserved)

    // GPIOB-1 Input/Output of GPIO         ; 0(Input), 1(Output)
    GpioCtrlRegs.GPBDIR.bit.GPIO32 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO33 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO35 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO36 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO37 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO38 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO39 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO40 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO41 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO42 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO43 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO44 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO45 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO46 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO47 = 1;

    // GPIOB-1 Sampling Frequency of GPIO   ; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)    : 0(/1), 1(/2), 2(/4), ..., 255(/510)
    GpioCtrlRegs.GPBCTRL.bit.QUALPRD0 = 0;  //GPIO32 ~ GPIO39
    GpioCtrlRegs.GPBCTRL.bit.QUALPRD1 = 0;  //GPIO40 ~ GPIO47

    // GPIOB-1 Qualification Mode           ; ACQCLK = SAMPCLK/GPAQSELn             : 0(/1), 1(/2), 2(/5), 3(ASYNCH)
    GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO33 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO34 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO35 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO36 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO37 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO38 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO39 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO40 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO41 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO42 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO43 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO44 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO45 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO46 = 0;
    GpioCtrlRegs.GPBQSEL1.bit.GPIO47 = 0;

    // GPIOB-1 Internal Pull-up             ; 0(Enable), 1(Disable)
    GpioCtrlRegs.GPBPUD.bit.GPIO32 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO33 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO34 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO35 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO36 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO37 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO38 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO39 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO40 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO41 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO42 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO43 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO44 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO45 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO46 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO47 = 1;

    //GPIO B Analog Mode Select             ; 0(digital function), 1(analog function)
    GpioCtrlRegs.GPBAMSEL.bit.GPIO42 = 0;   //USB0DP function
    GpioCtrlRegs.GPBAMSEL.bit.GPIO43 = 0;   //USB0DM function

    // GPIOB-1 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPBCSEL1.bit.GPIO32 = 2;
    GpioCtrlRegs.GPBCSEL1.bit.GPIO33 = 2;
    GpioCtrlRegs.GPBCSEL1.bit.GPIO34 = 2;
    GpioCtrlRegs.GPBCSEL1.bit.GPIO35 = 2;
    GpioCtrlRegs.GPBCSEL1.bit.GPIO36 = 2;
    GpioCtrlRegs.GPBCSEL1.bit.GPIO37 = 2;
    GpioCtrlRegs.GPBCSEL1.bit.GPIO38 = 2;
    GpioCtrlRegs.GPBCSEL1.bit.GPIO39 = 2;
    // GPIOB-2 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPBCSEL2.bit.GPIO40 = 2;
    GpioCtrlRegs.GPBCSEL2.bit.GPIO41 = 2;
    GpioCtrlRegs.GPBCSEL2.bit.GPIO42 = 2;
    GpioCtrlRegs.GPBCSEL2.bit.GPIO43 = 2;
    GpioCtrlRegs.GPBCSEL2.bit.GPIO44 = 2;
    GpioCtrlRegs.GPBCSEL2.bit.GPIO45 = 2;
    GpioCtrlRegs.GPBCSEL2.bit.GPIO46 = 2;
    GpioCtrlRegs.GPBCSEL2.bit.GPIO47 = 2;

    //-------------------------------------------------------------------------------------------------//
    //-------------------------------------------- GPIOB-2 --------------------------------------------//
    //-------------------------------------------------------------------------------------------------//
    // GPIOB-2 MUX                          ; [GPxGMUXn,GPxMUXn]
    GpioCtrlRegs.GPBGMUX2.bit.GPIO48 = 0;   // [n,0](GPIO48),           [0,1](OUTPUTXBAR3[O]),      [0,2](EM1A8[O]),            [0,3](Reserved)             ;EM1A8
    GpioCtrlRegs.GPBMUX2.bit.GPIO48 = 2;    // [1,1](Reserved),         [1,2](SCITXDA[O]),          [1,3](SD1_D1[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX2.bit.GPIO49 = 0;   // [n,0](GPIO49),           [0,1](OUTPUTXBAR4[O]),      [0,2](EM1A9[O]),            [0,3](Reserved)             ;EM1A9
    GpioCtrlRegs.GPBMUX2.bit.GPIO49 = 2;    // [1,1](Reserved),         [1,2](SCIRXDA[I]),          [1,3](SD1_C1[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX2.bit.GPIO50 = 0;   // [n,0](GPIO50),           [0,1](EQEP1A[I]),           [0,2](EM1A10[O]),           [0,3](Reserved)             ;EM1A10
    GpioCtrlRegs.GPBMUX2.bit.GPIO50 = 2;    // [1,1](Reserved),         [1,2](SPISIMOC[I/O]),       [1,3](SD1_D2[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX2.bit.GPIO51 = 0;   // [n,0](GPIO51),           [0,1](EQEP1B[I]),           [0,2](EM1A11[O]),           [0,3](Reserved)             ;nc
    GpioCtrlRegs.GPBMUX2.bit.GPIO51 = 0;    // [1,1](Reserved),         [1,2](SPISOMIC[I/O]),       [1,3](SD1_C2[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX2.bit.GPIO52 = 0;   // [n,0](GPIO52),           [0,1](EQEP1S[I/O]),         [0,2](EM1A12[O]),           [0,3](Reserved)             ;nc
    GpioCtrlRegs.GPBMUX2.bit.GPIO52 = 0;    // [1,1](Reserved),         [1,2](SPICLKC[I/O]),        [1,3](SD1_D3[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX2.bit.GPIO53 = 0;   // [n,0](GPIO53),           [0,1](EQEP1I[I/O]),         [0,2](EM1D31[I/O]),         [0,3](EM2D15[I/O]))         ;nc
    GpioCtrlRegs.GPBMUX2.bit.GPIO53 = 0;    // [1,1](Reserved),         [1,2](SPISTECn[I/O]),       [1,3](SD1_C3[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX2.bit.GPIO54 = 0;   // [n,0](GPIO54),           [0,1](SPISIMOA[I/O]),       [0,2](EM1D30[I/O]),         [0,3](EM2D14[I/O]))         ;nc
    GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 0;    // [1,1](EQEP2A[I]),        [1,2](SCITXDB[O]),          [1,3](SD1_D4[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX2.bit.GPIO55 = 0;   // [n,0](GPIO55),           [0,1](SPISOMIA[I/O]),       [0,2](EM1D29[I/O]),         [0,3](EM2D13[I/O]))         ;nc
    GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 0;    // [1,1](EQEP2B[I]),        [1,2](SCIRXDB[I]),          [1,3](SD1_C4[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX2.bit.GPIO56 = 0;   // [n,0](GPIO56),           [0,1](SPICLKA[I/O]),        [0,2](EM1D28[I/O]),         [0,3](EM2D12[I/O]))         ;nc
    GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 0;    // [1,1](EQEP2S[I/O]),      [1,2](SCITXDC[O]),          [1,3](SD2_D1[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX2.bit.GPIO57 = 0;   // [n,0](GPIO57),           [0,1](SPISTEAn[I/O]),       [0,2](EM1D27[I/O]),         [0,3](EM2D11[I/O]))         ;nc
    GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 0;    // [1,1](EQEP2I[I/O]),      [1,2](SCIRXDC[I]),          [1,3](SD2_C1[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX2.bit.GPIO58 = 0;   // [n,0](GPIO58),           [0,1](MCLKRA[I/O]),         [0,2](EM1D26[I/O]),         [0,3](EM2D10[I/O])
    GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 0;    // [1,1](OUTPUTXBAR1[O]),   [1,2](SPICLKB[I/O]),        [1,3](SD2_D2[I]),           [3,3](SPISIMOA[I/O])        ;nc

    GpioCtrlRegs.GPBGMUX2.bit.GPIO59 = 0;   // [n,0](GPIO59),           [0,1](MFSRA[I/O]),          [0,2](EM1D25[I/O]),         [0,3](EM2D9[I/O])
    GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 0;    // [1,1](OUTPUTXBAR2[O]),   [1,2](SPISTEBn[I/O]),       [1,3](SD2_C2[I]),           [3,3](SPISOMIA[I/O])        ;nc

    GpioCtrlRegs.GPBGMUX2.bit.GPIO60 = 0;   // [n,0](GPIO60),           [0,1](MCLKRB[I/O]),         [0,2](EM1D24[I/O]),         [0,3](EM2D8[I/O])
    GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 0;    // [1,1](OUTPUTXBAR3[O]),   [1,2](SPISIMOB[I/O]),       [1,3](SD2_D3[I]),           [3,3](SPICLKA[I/O])         ;nc

    GpioCtrlRegs.GPBGMUX2.bit.GPIO61 = 3;   // [n,0](GPIO61),           [0,1](MFSRB[I/O]),          [0,2](EM1D23[I/O]),         [0,3](EM2D7[I/O])
    GpioCtrlRegs.GPBMUX2.bit.GPIO61 = 3;    // [1,1](OUTPUTXBAR4[O]),   [1,2](SPISOMIB[I/O]),       [1,3](SD2_C3[I]),           [3,3](SPISTEAn[I/O])        ;nc

    GpioCtrlRegs.GPBGMUX2.bit.GPIO62 = 0;   // [n,0](GPIO62),           [0,1](SCIRXDC[I]),          [0,2](EM1D22[I/O]),         [0,3](EM2D6[I/O])           ;nc
    GpioCtrlRegs.GPBMUX2.bit.GPIO62 = 0;    // [1,1](EQEP3A[I]),        [1,2](CANRXA[I]),           [1,3](SD2_D4[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPBGMUX2.bit.GPIO63 = 0;   // [n,0](GPIO63),           [0,1](SCITXDC[O]),          [0,2](EM1D21[I/O]),         [0,3](EM2D5[I/O])           ;nc
    GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 0;    // [1,1](EQEP3B[I]),        [1,2](CANTXA[O]),           [1,3](SD2_C4[I]),           [3,3](SPISIMOB[I/O])

    // GPIOB-2 Input/Output of GPIO         ; 0(Input), 1(Output)
    GpioCtrlRegs.GPBDIR.bit.GPIO48 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO49 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO50 = 1;
    GpioCtrlRegs.GPBDIR.bit.GPIO51 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO52 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO53 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO54 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO55 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO56 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO57 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO58 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO59 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO60 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO61 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO62 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO63 = 0;

    // GPIOB-2 Sampling Frequency of GPIO   ; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)    : 0(/1), 1(/2), 2(/4), ..., 255(/510)
    GpioCtrlRegs.GPBCTRL.bit.QUALPRD2 = 0;  //GPIO48 ~ GPIO55
    GpioCtrlRegs.GPBCTRL.bit.QUALPRD3 = 0;  //GPIO56 ~ GPIO63

    // GPIOB-2 Qualification Mode           ; ACQCLK = SAMPCLK/GPAQSELn             : 0(/1), 1(/2), 2(/5), 3(ASYNCH)
    GpioCtrlRegs.GPBQSEL2.bit.GPIO48 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO49 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO50 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO51 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO52 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO53 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO54 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO55 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO56 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO57 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO58 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO59 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO60 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO61 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO62 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO63 = 0;

    // GPIOB-2 Internal Pull-up             ; 0(Enable), 1(Disable)
    GpioCtrlRegs.GPBPUD.bit.GPIO48 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO49 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO50 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO51 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO52 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO53 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO54 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO55 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO56 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO57 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO58 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO59 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO60 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO61 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO62 = 1;
    GpioCtrlRegs.GPBPUD.bit.GPIO63 = 1;

    // GPIOB-3 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPBCSEL3.bit.GPIO48 = 2;
    GpioCtrlRegs.GPBCSEL3.bit.GPIO49 = 2;
    GpioCtrlRegs.GPBCSEL3.bit.GPIO50 = 2;
    GpioCtrlRegs.GPBCSEL3.bit.GPIO51 = 2;
    GpioCtrlRegs.GPBCSEL3.bit.GPIO52 = 0;
    GpioCtrlRegs.GPBCSEL3.bit.GPIO53 = 0;
    GpioCtrlRegs.GPBCSEL3.bit.GPIO54 = 0;
    GpioCtrlRegs.GPBCSEL3.bit.GPIO55 = 0;
    // GPIOB-4 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPBCSEL4.bit.GPIO56 = 0;
    GpioCtrlRegs.GPBCSEL4.bit.GPIO57 = 0;
    GpioCtrlRegs.GPBCSEL4.bit.GPIO58 = 0;
    GpioCtrlRegs.GPBCSEL4.bit.GPIO59 = 0;
    GpioCtrlRegs.GPBCSEL4.bit.GPIO60 = 0;
    GpioCtrlRegs.GPBCSEL4.bit.GPIO61 = 0;
    GpioCtrlRegs.GPBCSEL4.bit.GPIO62 = 0;
    GpioCtrlRegs.GPBCSEL4.bit.GPIO63 = 0;

    //-------------------------------------------------------------------------------------------------//
    //-------------------------------------------- GPIOC-1 --------------------------------------------//
    //-------------------------------------------------------------------------------------------------//
    // GPIOC-1 MUX                          ; [GPxGMUXn,GPxMUXn]
    GpioCtrlRegs.GPCGMUX1.bit.GPIO64 = 0;   // [n,0](GPIO64),           [0,1](Reserved),            [0,2](EM1D20[I/O]),         [0,3](EM2D4[I/O])               ;nc
    GpioCtrlRegs.GPCMUX1.bit.GPIO64 = 0;    // [1,1](EQEP3S[I/O]),      [1,2](SCIRXDA[I]),          [1,3](Reserved),            [3,3](SPISOMIB[I/O])

    GpioCtrlRegs.GPCGMUX1.bit.GPIO65 = 0;   // [n,0](GPIO65),           [0,1](Reserved),            [0,2](EM1D19[I/O]),         [0,3](EM2D3[I/O])               ;nc
    GpioCtrlRegs.GPCMUX1.bit.GPIO65 = 0;    // [1,1](EQEP3I[I/O]),      [1,2](SCITXDA[O]),          [1,3](Reserved),            [3,3](SPICLKB[I/O])

    GpioCtrlRegs.GPCGMUX1.bit.GPIO66 = 0;   // [n,0](GPIO66),           [0,1](Reserved),            [0,2](EM1D18[I/O]),         [0,3](EM2D2[I/O])               ;nc
    GpioCtrlRegs.GPCMUX1.bit.GPIO66 = 0;    // [1,1](Reserved),         [1,2](SDAB[I/OD]),          [1,3](Reserved),            [3,3](SPISTEBn[I/O])

    GpioCtrlRegs.GPCGMUX1.bit.GPIO67 = 0;   // [n,0](GPIO67),           [0,1](Reserved),            [0,2](EM1D17[I/O]),         [0,3](EM2D1[I/O])               ;nc
    GpioCtrlRegs.GPCMUX1.bit.GPIO67 = 0;    // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPCGMUX1.bit.GPIO68 = 0;   // [n,0](GPIO68),           [0,1](Reserved),            [0,2](EM1D16[I/O]),         [0,3](EM2D0[I/O])               ;nc
    GpioCtrlRegs.GPCMUX1.bit.GPIO68 = 0;    // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPCGMUX1.bit.GPIO69 = 0;   // [n,0](GPIO69),           [0,1](Reserved),            [0,2](EM1D15[I/O]),         [0,3](Reserved)                 ;EM1D15
    GpioCtrlRegs.GPCMUX1.bit.GPIO69 = 2;    // [1,1](Reserved),         [1,2](SCLB[I/OD]),          [1,3](Reserved),            [3,3](SPISIMOC[I/O])

    GpioCtrlRegs.GPCGMUX1.bit.GPIO70 = 0;   // [n,0](GPIO70),           [0,1](Reserved),            [0,2](EM1D14[I/O]),         [0,3](Reserved)                 ;EM1D14
    GpioCtrlRegs.GPCMUX1.bit.GPIO70 = 2;    // [1,1](CANRXA[I]),        [1,2](SCITXDB[O]),          [1,3](Reserved),            [3,3](SPISOMIC[I/O])

    GpioCtrlRegs.GPCGMUX1.bit.GPIO71 = 0;   // [n,0](GPIO71),           [0,1](Reserved),            [0,2](EM1D13[I/O]),         [0,3](Reserved)                 ;EM1D13
    GpioCtrlRegs.GPCMUX1.bit.GPIO71 = 2;    // [1,1](CANTXA[O]),        [1,2](SCIRXDB[I]),          [1,3](Reserved),            [3,3](SPICLKC[I/O])

    GpioCtrlRegs.GPCGMUX1.bit.GPIO72 = 0;   // [n,0](GPIO72),           [0,1](Reserved),            [0,2](EM1D12[I/O]),         [0,3](Reserved)                 ;EM1D12
    GpioCtrlRegs.GPCMUX1.bit.GPIO72 = 2;    // [1,1](CANTXB[O]),        [1,2](SCITXDC[O]),          [1,3](Reserved),            [3,3](SPISTECn[I/O])    ;GPIO72(BOOT_SEL1) + ;EM1D11

    GpioCtrlRegs.GPCGMUX1.bit.GPIO73 = 0;   // [n,0](GPIO73),           [0,1](Reserved),            [0,2](EM1D11[I/O]),         [0,3](XCLKOUT[O])
    GpioCtrlRegs.GPCMUX1.bit.GPIO73 = 2;    // [1,1](CANRXB[I]),        [1,2](SCIRXDC[I]),          [1,3](Reserved),            [3,3](Reserved)         ;EM1D11

    GpioCtrlRegs.GPCGMUX1.bit.GPIO74 = 0;   // [n,0](GPIO74),           [0,1](Reserved),            [0,2](EM1D10[I/O]),         [0,3](Reserved)
    GpioCtrlRegs.GPCMUX1.bit.GPIO74 = 2;    // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EM1D10

    GpioCtrlRegs.GPCGMUX1.bit.GPIO75 = 0;   // [n,0](GPIO75),           [0,1](Reserved),            [0,2](EM1D9[I/O]),          [0,3](Reserved)
    GpioCtrlRegs.GPCMUX1.bit.GPIO75 = 2;    // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EM1D9

    GpioCtrlRegs.GPCGMUX1.bit.GPIO76 = 0;   // [n,0](GPIO76),           [0,1](Reserved),            [0,2](EM1D8[I/O]),          [0,3](Reserved)
    GpioCtrlRegs.GPCMUX1.bit.GPIO76 = 2;    // [1,1](Reserved),         [1,2](SCITXDD[O]),          [1,3](Reserved),            [3,3](Reserved)         ;EM1D8

    GpioCtrlRegs.GPCGMUX1.bit.GPIO77 = 0;   // [n,0](GPIO77),           [0,1](Reserved),            [0,2](EM1D7[I/O]),          [0,3](Reserved)
    GpioCtrlRegs.GPCMUX1.bit.GPIO77 = 2;    // [1,1](Reserved),         [1,2](SCIRXDD[I]),          [1,3](Reserved),            [3,3](Reserved)         ;EM1D7

    GpioCtrlRegs.GPCGMUX1.bit.GPIO78 = 0;   // [n,0](GPIO78),           [0,1](Reserved),            [0,2](EM1D6[O]),            [0,3](Reserved)
    GpioCtrlRegs.GPCMUX1.bit.GPIO78 = 2;    // [1,1](Reserved),         [1,2](EQEP2A[I]),           [1,3](Reserved),            [3,3](Reserved)         ;EM1D6

    GpioCtrlRegs.GPCGMUX1.bit.GPIO79 = 0;   // [n,0](GPIO79),           [0,1](Reserved),            [0,2](EM1D5[O]),            [0,3](Reserved)
    GpioCtrlRegs.GPCMUX1.bit.GPIO79 = 2;    // [1,1](Reserved),         [1,2](EQEP2B[I]),           [1,3](Reserved),            [3,3](Reserved)         ;EM1D5

    // GPIOC-1 Input/Output of GPIO         ; 0(Input), 1(Output)
    GpioCtrlRegs.GPCDIR.bit.GPIO64 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO65 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO66 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO67 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO68 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO69 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO70 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO71 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO72 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO73 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO74 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO75 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO76 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO77 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO78 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO79 = 1;

    // GPIOC-1 Sampling Frequency of GPIO   ; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)    : 0(/1), 1(/2), 2(/4), ..., 255(/510)
    GpioCtrlRegs.GPCCTRL.bit.QUALPRD0 = 0;  //GPIO64 ~ GPIO71
    GpioCtrlRegs.GPCCTRL.bit.QUALPRD1 = 0;  //GPIO72 ~ GPIO79

    // GPIOC-1 Qualification Mode           ; ACQCLK = SAMPCLK/GPAQSELn             : 0(/1), 1(/2), 2(/5), 3(ASYNCH)
    GpioCtrlRegs.GPCQSEL1.bit.GPIO64 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO65 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO66 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO67 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO68 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO69 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO70 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO71 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO72 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO73 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO74 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO75 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO76 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO77 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO78 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO79 = 0;

    // GPIOC-1 Internal Pull-up             ; 0(Enable), 1(Disable)
    GpioCtrlRegs.GPCPUD.bit.GPIO64 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO65 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO66 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO67 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO68 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO69 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO70 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO71 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO72 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO73 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO74 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO75 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO76 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO77 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO78 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO79 = 1;

    // GPIOC-1 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPCCSEL1.bit.GPIO64 = 0;
    GpioCtrlRegs.GPCCSEL1.bit.GPIO65 = 0;
    GpioCtrlRegs.GPCCSEL1.bit.GPIO66 = 0;
    GpioCtrlRegs.GPCCSEL1.bit.GPIO67 = 0;
    GpioCtrlRegs.GPCCSEL1.bit.GPIO68 = 0;
    GpioCtrlRegs.GPCCSEL1.bit.GPIO69 = 2;
    GpioCtrlRegs.GPCCSEL1.bit.GPIO70 = 2;
    GpioCtrlRegs.GPCCSEL1.bit.GPIO71 = 2;
    // GPIOC-2 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPCCSEL2.bit.GPIO72 = 2;
    GpioCtrlRegs.GPCCSEL2.bit.GPIO73 = 2;
    GpioCtrlRegs.GPCCSEL2.bit.GPIO74 = 2;
    GpioCtrlRegs.GPCCSEL2.bit.GPIO75 = 2;
    GpioCtrlRegs.GPCCSEL2.bit.GPIO76 = 2;
    GpioCtrlRegs.GPCCSEL2.bit.GPIO77 = 2;
    GpioCtrlRegs.GPCCSEL2.bit.GPIO78 = 2;
    GpioCtrlRegs.GPCCSEL2.bit.GPIO79 = 2;

    //-------------------------------------------------------------------------------------------------//
    //-------------------------------------------- GPIOC-2 --------------------------------------------//
    //-------------------------------------------------------------------------------------------------//
    // GPIOC-2 MUX                          ; [GPxGMUXn,GPxMUXn]
    GpioCtrlRegs.GPCGMUX2.bit.GPIO80 = 0;   // [n,0](GPIO80),           [0,1](Reserved),            [0,2](EM1D4[I/O]),          [0,3](Reserved)
    GpioCtrlRegs.GPCMUX2.bit.GPIO80 = 2;    // [1,1](Reserved),         [1,2](EQEP2S[I/O]),         [1,3](Reserved),            [3,3](Reserved)         ;EM1D4

    GpioCtrlRegs.GPCGMUX2.bit.GPIO81 = 0;   // [n,0](GPIO81),           [0,1](Reserved),            [0,2](EM1D3[I/O]),          [0,3](Reserved)
    GpioCtrlRegs.GPCMUX2.bit.GPIO81 = 2;    // [1,1](Reserved),         [1,2](EQEP2I[I/O]),         [1,3](Reserved),            [3,3](Reserved)         ;EM1D3

    GpioCtrlRegs.GPCGMUX2.bit.GPIO82 = 0;   // [n,0](GPIO82),           [0,1](Reserved),            [0,2](EM1D2[I/O]),          [0,3](Reserved)
    GpioCtrlRegs.GPCMUX2.bit.GPIO82 = 2;    // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EM1D2

    GpioCtrlRegs.GPCGMUX2.bit.GPIO83 = 0;   // [n,0](GPIO83),           [0,1](Reserved),            [0,2](EM1D1[I/O]),          [0,3](Reserved)
    GpioCtrlRegs.GPCMUX2.bit.GPIO83 = 2;    // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EM1D1

    GpioCtrlRegs.GPCGMUX2.bit.GPIO84 = 0;   // [n,0](GPIO84),           [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPCMUX2.bit.GPIO84 = 0;    // [1,1](SCITXDA[O]),       [1,2](MDXB[O]),             [1,3](Reserved),            [3,3](Reserved)         ;GPIO84(BOOT_SEL2)

    GpioCtrlRegs.GPCGMUX2.bit.GPIO85 = 0;   // [n,0](GPIO85),           [0,1](Reserved),            [0,2](EM1D0[I/O]),          [0,3](Reserved)
    GpioCtrlRegs.GPCMUX2.bit.GPIO85 = 2;    // [1,1](SCIRXDA[I]),       [1,2](MDRB[I]),             [1,3](Reserved),            [3,3](MDRA[I])          ;EM1D0

    GpioCtrlRegs.GPCGMUX2.bit.GPIO86 = 0;   // [n,0](GPIO86),           [0,1](Reserved),            [0,2](EM1A13[O]),           [0,3](EM1CAS[O])        ;nc
    GpioCtrlRegs.GPCMUX2.bit.GPIO86 = 0;    // [1,1](SCITXDB[O]),       [1,2](MCLKXB[I/O]),         [1,3](Reserved),            [3,3](MCLKXA[I/O])

    GpioCtrlRegs.GPCGMUX2.bit.GPIO87 = 0;   // [n,0](GPIO87),           [0,1](Reserved),            [0,2](EM1A14[O]),           [0,3](EM1RAS[O])        ;nc
    GpioCtrlRegs.GPCMUX2.bit.GPIO87 = 0;    // [1,1](SCIRXDB[I]),       [1,2](MFSXB[I/O]),          [1,3](Reserved),            [3,3](MFSXA[I/O])

    GpioCtrlRegs.GPCGMUX2.bit.GPIO88 = 0;   // [n,0](GPIO88),           [0,1](Reserved),            [0,2](EM1A15[O]),           [0,3](EM1DQM0[O])       ;nc
    GpioCtrlRegs.GPCMUX2.bit.GPIO88 = 0;    // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPCGMUX2.bit.GPIO89 = 0;   // [n,0](GPIO89),           [0,1](Reserved),            [0,2](EM1A16[O]),           [0,3](EM1DQM1[O])       ;GPIO89
    GpioCtrlRegs.GPCMUX2.bit.GPIO89 = 0;    // [1,1](Reserved),         [1,2](SCITXDC[O]),          [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPCGMUX2.bit.GPIO90 = 0;   // [n,0](GPIO90),           [0,1](Reserved),            [0,2](EM1A17[O]),           [0,3](EM1DQM2[O])       ;GPIO90
    GpioCtrlRegs.GPCMUX2.bit.GPIO90 = 0;    // [1,1](Reserved),         [1,2](SCIRXDC[I]),          [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPCGMUX2.bit.GPIO91 = 0;   // [n,0](GPIO91),           [0,1](Reserved),            [0,2](EM1A18[O]),           [0,3](EM1DQM3[O])
    GpioCtrlRegs.GPCMUX2.bit.GPIO91 = 0;    // [1,1](Reserved),         [1,2](SDAA[I/OD]),          [1,3](Reserved),            [3,3](Reserved)         ;nc

    GpioCtrlRegs.GPCGMUX2.bit.GPIO92 = 0;   // [n,0](GPIO92),           [0,1](Reserved),            [0,2](EM1A19[O]),           [0,3](EM1BA1[O])
    GpioCtrlRegs.GPCMUX2.bit.GPIO92 = 3;    // [1,1](Reserved),         [1,2](SCLA[I/OD]),          [1,3](Reserved),            [3,3](Reserved)         ;EM1BA1

    GpioCtrlRegs.GPCGMUX2.bit.GPIO93 = 0;   // [n,0](GPIO93),           [0,1](Reserved),            [0,2](Reserved),            [0,3](EM1BA0[O])
    GpioCtrlRegs.GPCMUX2.bit.GPIO93 = 3;    // [1,1](Reserved),         [1,2](SCITXDD[O]),          [1,3](Reserved),            [3,3](Reserved)         ;EM1BA0

    GpioCtrlRegs.GPCGMUX2.bit.GPIO94 = 0;   // [n,0](GPIO94),           [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPCMUX2.bit.GPIO94 = 0;    // [1,1](Reserved),         [1,2](SCIRXDD[I]),          [1,3](Reserved),            [3,3](Reserved)         ;Pin_A3_DSP

    GpioCtrlRegs.GPCGMUX2.bit.GPIO95 = 0;   // [n,0](GPIO95),           [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPCMUX2.bit.GPIO95 = 0;    // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;nc

    // GPIOC-2 Input/Output of GPIO         ; 0(Input), 1(Output)
    GpioCtrlRegs.GPCDIR.bit.GPIO80 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO81 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO82 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO83 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO84 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO85 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO86 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO87 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO88 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO89 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO90 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO91 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO92 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO93 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO94 = 1;
    GpioCtrlRegs.GPCDIR.bit.GPIO95 = 0;

    // GPIOC-2 Sampling Frequency of GPIO   ; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)    : 0(/1), 1(/2), 2(/4), ..., 255(/510)
    GpioCtrlRegs.GPCCTRL.bit.QUALPRD2 = 0;  //GPIO80 ~ GPIO87
    GpioCtrlRegs.GPCCTRL.bit.QUALPRD3 = 0;  //GPIO88 ~ GPIO95

    // GPIOC-2 Qualification Mode           ; ACQCLK = SAMPCLK/GPAQSELn             : 0(/1), 1(/2), 2(/5), 3(ASYNCH)
    GpioCtrlRegs.GPCQSEL2.bit.GPIO80 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO81 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO82 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO83 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO84 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO85 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO86 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO87 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO88 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO89 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO90 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO91 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO92 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO93 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO94 = 0;
    GpioCtrlRegs.GPCQSEL2.bit.GPIO95 = 0;

    // GPIOC-2 Internal Pull-up             ; 0(Enable), 1(Disable)
    GpioCtrlRegs.GPCPUD.bit.GPIO80 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO81 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO82 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO83 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO84 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO85 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO86 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO87 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO88 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO89 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO90 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO91 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO92 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO93 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO94 = 1;
    GpioCtrlRegs.GPCPUD.bit.GPIO95 = 1;

    // GPIOC-3 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPCCSEL3.bit.GPIO80 = 2;
    GpioCtrlRegs.GPCCSEL3.bit.GPIO81 = 2;
    GpioCtrlRegs.GPCCSEL3.bit.GPIO82 = 2;
    GpioCtrlRegs.GPCCSEL3.bit.GPIO83 = 2;
    GpioCtrlRegs.GPCCSEL3.bit.GPIO84 = 2;
    GpioCtrlRegs.GPCCSEL3.bit.GPIO85 = 2;
    GpioCtrlRegs.GPCCSEL3.bit.GPIO86 = 0;
    GpioCtrlRegs.GPCCSEL3.bit.GPIO87 = 0;
    // GPIOC-4 GPIO Core selection
    GpioCtrlRegs.GPCCSEL4.bit.GPIO88 = 2;
    GpioCtrlRegs.GPCCSEL4.bit.GPIO89 = 2;
    GpioCtrlRegs.GPCCSEL4.bit.GPIO90 = 0;
    GpioCtrlRegs.GPCCSEL4.bit.GPIO91 = 0;
    GpioCtrlRegs.GPCCSEL4.bit.GPIO92 = 2;
    GpioCtrlRegs.GPCCSEL4.bit.GPIO93 = 2;
    GpioCtrlRegs.GPCCSEL4.bit.GPIO94 = 2;
    GpioCtrlRegs.GPCCSEL4.bit.GPIO95 = 0;

    //-------------------------------------------------------------------------------------------------//
    //-------------------------------------------- GPIOD-1 --------------------------------------------//
    //-------------------------------------------------------------------------------------------------//
    // GPIOD-1 MUX                          ; [GPxGMUXn,GPxMUXn]
    GpioCtrlRegs.GPDGMUX1.bit.GPIO96 = 0;   // [n,0](GPIO96),           [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2DQM1[O])
    GpioCtrlRegs.GPDMUX1.bit.GPIO96 = 0;    // [1,1](EQEP1A[I]),        [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;

    GpioCtrlRegs.GPDGMUX1.bit.GPIO97 = 0;   // [n,0](GPIO97),           [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2DQM0[O])
    GpioCtrlRegs.GPDMUX1.bit.GPIO97 = 0;    // [1,1](EQEP1B[I]),        [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;

    GpioCtrlRegs.GPDGMUX1.bit.GPIO98 = 0;   // [n,0](GPIO98),           [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2A0[O])
    GpioCtrlRegs.GPDMUX1.bit.GPIO98 = 0;    // [1,1](EQEP1S[I/O]),      [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;

    GpioCtrlRegs.GPDGMUX1.bit.GPIO99 = 0;   // [n,0](GPIO99),           [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2A1[O])
    GpioCtrlRegs.GPDMUX1.bit.GPIO99 = 0;    // [1,1](EQEP1I[I/O]),      [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;

    GpioCtrlRegs.GPDGMUX1.bit.GPIO100 = 0;  // [n,0](GPIO100),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2A2[O])
    GpioCtrlRegs.GPDMUX1.bit.GPIO100 = 0;   // [1,1](EQEP2A[I]),        [1,2](SPISIMOC[I/O]),       [1,3](Reserved),            [3,3](Reserved)         ;

    GpioCtrlRegs.GPDGMUX1.bit.GPIO101 = 0;  // [n,0](GPIO101),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2A3[I/O])
    GpioCtrlRegs.GPDMUX1.bit.GPIO101 = 0;   // [1,1](EQEP2B[I]),        [1,2](SPISOMIC[I/O]),       [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX1.bit.GPIO102 = 0;  // [n,0](GPIO102),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2A4[O])
    GpioCtrlRegs.GPDMUX1.bit.GPIO102 = 0;   // [1,1](EQEP2S[I/O]),      [1,2](SPICLKC[I/O]),        [1,3](Reserved),            [3,3](Reserved)         ;

    GpioCtrlRegs.GPDGMUX1.bit.GPIO103 = 0;  // [n,0](GPIO103),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2A5[O])
    GpioCtrlRegs.GPDMUX1.bit.GPIO103 = 0;   // [1,1](EQEP2I[I/O]),      [1,2](SPISTECn[I/O]),       [1,3](Reserved),            [3,3](Reserved)         ;

    GpioCtrlRegs.GPDGMUX1.bit.GPIO104 = 0;  // [n,0](GPIO104),          [0,1](SDAA[I/OD]),          [0,2](Reserved),            [0,3](EM2A6[O])         ;
    GpioCtrlRegs.GPDMUX1.bit.GPIO104 = 0;   // [1,1](EQEP3A[I]),        [1,2](SCITXDD[O]),          [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX1.bit.GPIO105 = 0;  // [n,0](GPIO105),          [0,1](SCLA[I/OD]),          [0,2](Reserved),            [0,3](EM2A7[O])         ;
    GpioCtrlRegs.GPDMUX1.bit.GPIO105 = 0;   // [1,1](EQEP3B[I]),        [1,2](SCIRXDD[I]),          [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX1.bit.GPIO106 = 0;  // [n,0](GPIO106),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2A8[O])         ;
    GpioCtrlRegs.GPDMUX1.bit.GPIO106 = 0;   // [1,1](EQEP3S[I/O]),      [1,2](SCITXDC[O]),          [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX1.bit.GPIO107 = 0;  // [n,0](GPIO107),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2A9[O])         ;
    GpioCtrlRegs.GPDMUX1.bit.GPIO107 = 0;   // [1,1](EQEP3I[I/O]),      [1,2](SCIRXDC[I]),          [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX1.bit.GPIO108 = 0;  // [n,0](GPIO108),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2A10[O])        ;
    GpioCtrlRegs.GPDMUX1.bit.GPIO108 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX1.bit.GPIO109 = 0;  // [n,0](GPIO109),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2A11[O])        ;
    GpioCtrlRegs.GPDMUX1.bit.GPIO109 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX1.bit.GPIO110 = 0;  // [n,0](GPIO110),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2WAIT[I])       ;
    GpioCtrlRegs.GPDMUX1.bit.GPIO110 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX1.bit.GPIO111 = 0;  // [n,0](GPIO111),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2BA0[O])
    GpioCtrlRegs.GPDMUX1.bit.GPIO111 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    // GPIOD-1 Input/Output of GPIO         ; 0(Input), 1(Output)
    GpioCtrlRegs.GPDDIR.bit.GPIO96 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO97 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO98 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO99 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO100 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO101 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO102 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO103 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO104 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO105 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO106 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO107 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO108 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO109 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO110 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO111 = 0;

    // GPIOD-1 Sampling Frequency of GPIO   ; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)    : 0(/1), 1(/2), 2(/4), ..., 255(/510)
    GpioCtrlRegs.GPDCTRL.bit.QUALPRD0 = 0;  //GPIO96 ~ GPIO103
    GpioCtrlRegs.GPDCTRL.bit.QUALPRD1 = 0;  //GPIO104 ~ GPIO111

    // GPIOD-1 Qualification Mode           ; ACQCLK = SAMPCLK/GPAQSELn             : 0(/1), 1(/2), 2(/5), 3(ASYNCH)
    GpioCtrlRegs.GPDQSEL1.bit.GPIO96 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO97 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO98 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO99 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO100 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO101 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO102 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO103 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO104 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO105 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO106 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO107 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO108 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO109 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO110 = 0;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO111 = 0;

    // GPIOD-1 Internal Pull-up             ; 0(Enable), 1(Disable)
    GpioCtrlRegs.GPDPUD.bit.GPIO96 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO97 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO98 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO99 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO100 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO101 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO102 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO103 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO104 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO105 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO106 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO107 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO108 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO109 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO110 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO111 = 1;

    // GPIOD-1 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPDCSEL1.bit.GPIO96 = 0;
    GpioCtrlRegs.GPDCSEL1.bit.GPIO97 = 0;
    GpioCtrlRegs.GPDCSEL1.bit.GPIO98 = 0;
    GpioCtrlRegs.GPDCSEL1.bit.GPIO99 = 0;
    GpioCtrlRegs.GPDCSEL1.bit.GPIO101 = 0;
    GpioCtrlRegs.GPDCSEL1.bit.GPIO102 = 0;
    GpioCtrlRegs.GPDCSEL1.bit.GPIO103 = 0;
    // GPIOD-2 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPDCSEL2.bit.GPIO104 = 0;
    GpioCtrlRegs.GPDCSEL2.bit.GPIO105 = 0;
    GpioCtrlRegs.GPDCSEL2.bit.GPIO106 = 0;
    GpioCtrlRegs.GPDCSEL2.bit.GPIO107 = 0;
    GpioCtrlRegs.GPDCSEL2.bit.GPIO108 = 0;
    GpioCtrlRegs.GPDCSEL2.bit.GPIO109 = 0;
    GpioCtrlRegs.GPDCSEL2.bit.GPIO110 = 0;
    GpioCtrlRegs.GPDCSEL2.bit.GPIO111 = 0;


    //-------------------------------------------------------------------------------------------------//
    //-------------------------------------------- GPIOD-2 --------------------------------------------//
    //-------------------------------------------------------------------------------------------------//
    // GPIOD-2 MUX                          ; [GPxGMUXn,GPxMUXn]
    GpioCtrlRegs.GPDGMUX2.bit.GPIO112 = 0;  // [n,0](GPIO112),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2BA1[O])
    GpioCtrlRegs.GPDMUX2.bit.GPIO112 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO113 = 0;  // [n,0](GPIO113),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2CAS[O])
    GpioCtrlRegs.GPDMUX2.bit.GPIO113 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO114 = 0;  // [n,0](GPIO114),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2RAS[O])
    GpioCtrlRegs.GPDMUX2.bit.GPIO114 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO115 = 0;  // [n,0](GPIO115),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2CS0n[O])
    GpioCtrlRegs.GPDMUX2.bit.GPIO115 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO116 = 0;  // [n,0](GPIO116),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2CS2n[O])
    GpioCtrlRegs.GPDMUX2.bit.GPIO116 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO117 = 0;  // [n,0](GPIO117),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2SDCKE[O])
    GpioCtrlRegs.GPDMUX2.bit.GPIO117 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO118 = 0;  // [n,0](GPIO118),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2CLK[O])
    GpioCtrlRegs.GPDMUX2.bit.GPIO118 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO119 = 0;  // [n,0](GPIO119),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2RNW[O])
    GpioCtrlRegs.GPDMUX2.bit.GPIO119 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO120 = 0;  // [n,0](GPIO120),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2WEn[O])
    GpioCtrlRegs.GPDMUX2.bit.GPIO120 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](USB0PFLT)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO121 = 0;  // [n,0](GPIO121),          [0,1](Reserved),            [0,2](Reserved),            [0,3](EM2OEn[O])
    GpioCtrlRegs.GPDMUX2.bit.GPIO121 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](USB0EPEN)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO122 = 0;  // [n,0](GPIO122),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPDMUX2.bit.GPIO122 = 0;   // [1,1](Reserved),         [1,2](SPISIMOC[I/O]),       [1,3](SD1_D1[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO123 = 0;  // [n,0](GPIO123),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPDMUX2.bit.GPIO123 = 0;   // [1,1](Reserved),         [1,2](SPISOMIC[I/O]),       [1,3](SD1_C1[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO124 = 0;  // [n,0](GPIO124),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPDMUX2.bit.GPIO124 = 0;   // [1,1](Reserved),         [1,2](SPICLKC[I/O]),        [1,3](SD1_D2[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO125 = 0;  // [n,0](GPIO125),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPDMUX2.bit.GPIO125 = 0;   // [1,1](Reserved),         [1,2](SPISTECn[I/O]),       [1,3](SD1_C2[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO126 = 0;  // [n,0](GPIO126),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPDMUX2.bit.GPIO126 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](SD1_D3[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPDGMUX2.bit.GPIO127 = 0;  // [n,0](GPIO127),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPDMUX2.bit.GPIO127 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](SD1_C3[I]),           [3,3](Reserved)

    // GPIOD-2 Input/Output of GPIO         ; 0(Input), 1(Output)
    GpioCtrlRegs.GPDDIR.bit.GPIO112 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO113 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO114 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO115 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO116 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO117 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO118 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO119 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO120 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO121 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO122 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO123 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO124 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO125 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO126 = 0;
    GpioCtrlRegs.GPDDIR.bit.GPIO127 = 0;

    // GPIOD-2 Sampling Frequency of GPIO   ; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)    : 0(/1), 1(/2), 2(/4), ..., 255(/510)
    GpioCtrlRegs.GPDCTRL.bit.QUALPRD2 = 0;  //GPIO112 ~ GPIO119
    GpioCtrlRegs.GPDCTRL.bit.QUALPRD3 = 0;  //GPIO120 ~ GPIO127

    // GPIOD-2 Qualification Mode           ; ACQCLK = SAMPCLK/GPAQSELn             : 0(/1), 1(/2), 2(/5), 3(ASYNCH)
    GpioCtrlRegs.GPDQSEL2.bit.GPIO112 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO113 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO114 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO115 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO116 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO117 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO118 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO119 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO120 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO121 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO122 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO123 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO124 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO125 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO126 = 0;
    GpioCtrlRegs.GPDQSEL2.bit.GPIO127 = 0;

    // GPIOD-2 Internal Pull-up             ; 0(Enable), 1(Disable)
    GpioCtrlRegs.GPDPUD.bit.GPIO112 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO113 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO114 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO115 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO116 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO117 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO118 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO119 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO120 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO121 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO122 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO123 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO124 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO125 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO126 = 1;
    GpioCtrlRegs.GPDPUD.bit.GPIO127 = 1;

    // GPIOD-3 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPDCSEL3.bit.GPIO112 = 0;
    GpioCtrlRegs.GPDCSEL3.bit.GPIO113 = 0;
    GpioCtrlRegs.GPDCSEL3.bit.GPIO114 = 0;
    GpioCtrlRegs.GPDCSEL3.bit.GPIO115 = 0;
    GpioCtrlRegs.GPDCSEL3.bit.GPIO116 = 0;
    GpioCtrlRegs.GPDCSEL3.bit.GPIO117 = 0;
    GpioCtrlRegs.GPDCSEL3.bit.GPIO118 = 0;
    GpioCtrlRegs.GPDCSEL3.bit.GPIO119 = 0;
    // GPIOD-4 GPIO Core selection      ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPDCSEL4.bit.GPIO120 = 0;
    GpioCtrlRegs.GPDCSEL4.bit.GPIO121 = 0;
    GpioCtrlRegs.GPDCSEL4.bit.GPIO122 = 0;
    GpioCtrlRegs.GPDCSEL4.bit.GPIO123 = 0;
    GpioCtrlRegs.GPDCSEL4.bit.GPIO124 = 0;
    GpioCtrlRegs.GPDCSEL4.bit.GPIO125 = 0;
    GpioCtrlRegs.GPDCSEL4.bit.GPIO126 = 0;
    GpioCtrlRegs.GPDCSEL4.bit.GPIO127 = 0;

    //-------------------------------------------------------------------------------------------------//
    //-------------------------------------------- GPIOE-1 --------------------------------------------//
    //-------------------------------------------------------------------------------------------------//
    // GPIOE-1 MUX                          ; [GPxGMUXn,GPxMUXn]
    GpioCtrlRegs.GPEGMUX1.bit.GPIO128 = 0;  // [n,0](GPIO128),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO128 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](SD1_D4[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPEGMUX1.bit.GPIO129 = 0;  // [n,0](GPIO129),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO129 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](SD1_C4[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPEGMUX1.bit.GPIO130 = 0;  // [n,0](GPIO130),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO130 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](SD2_D1[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPEGMUX1.bit.GPIO131 = 0;  // [n,0](GPIO131),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO131 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](SD2_C1[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPEGMUX1.bit.GPIO132 = 0;  // [n,0](GPIO132),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO132 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](SD2_D2[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPEGMUX1.bit.GPIO133 = 0;  // [n,0](GPIO133/AUXCLKIN), [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO133 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](SD2_C2[I]),           [3,3](Reserved)

    GpioCtrlRegs.GPEGMUX1.bit.GPIO134 = 0;  // [n,0](GPIO134),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO134 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](SD2_D3[I]),           [3,3](Reserved)         ;GPIO134(XF1)

    GpioCtrlRegs.GPEGMUX1.bit.GPIO135 = 0;  // [n,0](GPIO135),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO135 = 0;   // [1,1](Reserved),         [1,2](SCITXDA[O]),          [1,3](SD2_C3[I]),           [3,3](Reserved)         ;SCITXDA(RS-232)

    GpioCtrlRegs.GPEGMUX1.bit.GPIO136 = 0;  // [n,0](GPIO136),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO136 = 0;   // [1,1](Reserved),         [1,2](SCIRXDA[I]),          [1,3](SD2_D4[I]),           [3,3](Reserved)         ;SCIRXDA(RS-232)

    GpioCtrlRegs.GPEGMUX1.bit.GPIO137 = 0;  // [n,0](GPIO137),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO137 = 0;   // [1,1](Reserved),         [1,2](SCITXDB[O]),          [1,3](SD2_C4[I]),           [3,3](Reserved)         ;GPIO137(LED3, D2)

    GpioCtrlRegs.GPEGMUX1.bit.GPIO138 = 0;  // [n,0](GPIO138),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO138 = 0;   // [1,1](Reserved),         [1,2](SCIRXDB[I]),          [1,3](Reserved),            [3,3](Reserved)         ;GPIO138(LED2, D3)

    GpioCtrlRegs.GPEGMUX1.bit.GPIO139 = 0;  // [n,0](GPIO139),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO139 = 0;   // [1,1](Reserved),         [1,2](SCIRXDC[I]),          [1,3](Reserved),            [3,3](Reserved)         ;GPIO139(LED1, D1)

    GpioCtrlRegs.GPEGMUX1.bit.GPIO140 = 0;  // [n,0](GPIO140),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO140 = 0;   // [1,1](Reserved),         [1,2](SCITXDC[O]),          [1,3](Reserved),            [3,3](Reserved)         ;GPIO140(LED0, D4)

    GpioCtrlRegs.GPEGMUX1.bit.GPIO141 = 0;  // [n,0](GPIO141),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO141 = 0;   // [1,1](Reserved),         [1,2](SCIRXDD[I]),          [1,3](Reserved),            [3,3](Reserved)         ;

    GpioCtrlRegs.GPEGMUX1.bit.GPIO142 = 0;  // [n,0](GPIO142),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO142 = 0;   // [1,1](Reserved),         [1,2](SCITXDD[O]),          [1,3](Reserved),            [3,3](Reserved)         ;

    GpioCtrlRegs.GPEGMUX1.bit.GPIO143 = 0;  // [n,0](GPIO143),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX1.bit.GPIO143 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    // GPIOE-1 Input/Output of GPIO         ; 0(Input), 1(Output)
    GpioCtrlRegs.GPEDIR.bit.GPIO128 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO129 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO130 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO131 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO132 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO133 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO134 = 1;
    GpioCtrlRegs.GPEDIR.bit.GPIO135 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO136 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO137 = 1;
    GpioCtrlRegs.GPEDIR.bit.GPIO138 = 1;
    GpioCtrlRegs.GPEDIR.bit.GPIO139 = 1;
    GpioCtrlRegs.GPEDIR.bit.GPIO140 = 1;
    GpioCtrlRegs.GPEDIR.bit.GPIO141 = 1;
    GpioCtrlRegs.GPEDIR.bit.GPIO142 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO143 = 0;

    // GPIOE-1 Sampling Frequency of GPIO   ; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)    : 0(/1), 1(/2), 2(/4), ..., 255(/510)
    GpioCtrlRegs.GPECTRL.bit.QUALPRD0 = 0;  //GPIO128 ~ GPIO135
    GpioCtrlRegs.GPECTRL.bit.QUALPRD1 = 0;  //GPIO136 ~ GPIO143

    // GPIOE-1 Qualification Mode           ; ACQCLK = SAMPCLK/GPAQSELn             : 0(/1), 1(/2), 2(/5), 3(ASYNCH)
    GpioCtrlRegs.GPEQSEL1.bit.GPIO128 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO129 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO130 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO131 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO132 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO133 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO134 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO135 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO136 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO137 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO138 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO139 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO140 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO141 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO142 = 0;
    GpioCtrlRegs.GPEQSEL1.bit.GPIO143 = 0;

    // GPIOE-1 Internal Pull-up             ; 0(Enable), 1(Disable)
    GpioCtrlRegs.GPEPUD.bit.GPIO128 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO129 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO130 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO131 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO132 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO133 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO134 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO135 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO136 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO137 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO138 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO139 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO140 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO141 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO142 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO143 = 1;


    // GPIOE-1 Core Select                  ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPECSEL1.bit.GPIO128 = 0;
    GpioCtrlRegs.GPECSEL1.bit.GPIO129 = 0;
    GpioCtrlRegs.GPECSEL1.bit.GPIO130 = 0;
    GpioCtrlRegs.GPECSEL1.bit.GPIO131 = 0;
    GpioCtrlRegs.GPECSEL1.bit.GPIO132 = 0;
    GpioCtrlRegs.GPECSEL1.bit.GPIO133 = 0;
    GpioCtrlRegs.GPECSEL1.bit.GPIO134 = 0;
    GpioCtrlRegs.GPECSEL1.bit.GPIO135 = 0;
    // GPIOE-2 Core Select                 ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPECSEL2.bit.GPIO136 = 0;
    GpioCtrlRegs.GPECSEL2.bit.GPIO137 = 0;
    GpioCtrlRegs.GPECSEL2.bit.GPIO138 = 2;
    GpioCtrlRegs.GPECSEL2.bit.GPIO139 = 2;
    GpioCtrlRegs.GPECSEL2.bit.GPIO140 = 0;
    GpioCtrlRegs.GPECSEL2.bit.GPIO141 = 0;
    GpioCtrlRegs.GPECSEL2.bit.GPIO142 = 0;
    GpioCtrlRegs.GPECSEL2.bit.GPIO143 = 0;

    //-------------------------------------------------------------------------------------------------//
    //-------------------------------------------- GPIOE-2 --------------------------------------------//
    //-------------------------------------------------------------------------------------------------//
    // GPIOE-2 MUX                          ; [GPxGMUXn,GPxMUXn]
    GpioCtrlRegs.GPEGMUX2.bit.GPIO144 = 0;  // [n,0](GPIO144),          [0,1](Reserved),            [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO144 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;GPIO144(Resolver)

    GpioCtrlRegs.GPEGMUX2.bit.GPIO145 = 0;  // [n,0](GPIO145),          [0,1](EPWM1A[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO145 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EPWM1A

    GpioCtrlRegs.GPEGMUX2.bit.GPIO146 = 0;  // [n,0](GPIO146),          [0,1](EPWM1B[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO146 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EPWM1B

    GpioCtrlRegs.GPEGMUX2.bit.GPIO147 = 0;  // [n,0](GPIO147),          [0,1](EPWM2A[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO147 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EPWM2A

    GpioCtrlRegs.GPEGMUX2.bit.GPIO148 = 0;  // [n,0](GPIO148),          [0,1](EPWM2B[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO148 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EPWM2B

    GpioCtrlRegs.GPEGMUX2.bit.GPIO149 = 0;  // [n,0](GPIO149),          [0,1](EPWM3A[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO149 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EPWM3A

    GpioCtrlRegs.GPEGMUX2.bit.GPIO150 = 0;  // [n,0](GPIO150),          [0,1](EPWM3B[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO150 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EPWM3B

    GpioCtrlRegs.GPEGMUX2.bit.GPIO151 = 0;  // [n,0](GPIO151),          [0,1](EPWM4A[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO151 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EPWM4A

    GpioCtrlRegs.GPEGMUX2.bit.GPIO152 = 0;  // [n,0](GPIO152),          [0,1](EPWM4B[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO152 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EPWM4B

    GpioCtrlRegs.GPEGMUX2.bit.GPIO153 = 0;  // [n,0](GPIO153),          [0,1](EPWM5A[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO153 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EPWM5A

    GpioCtrlRegs.GPEGMUX2.bit.GPIO154 = 0;  // [n,0](GPIO154),          [0,1](EPWM5B[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO154 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EPWM5B

    GpioCtrlRegs.GPEGMUX2.bit.GPIO155 = 0;  // [n,0](GPIO155),          [0,1](EPWM6A[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO155 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EPWM6A

    GpioCtrlRegs.GPEGMUX2.bit.GPIO156 = 0;  // [n,0](GPIO156),          [0,1](EPWM6B[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO156 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)         ;EPWM6B

    GpioCtrlRegs.GPEGMUX2.bit.GPIO157 = 0;  // [n,0](GPIO157),          [0,1](EPWM7A[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO157 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPEGMUX2.bit.GPIO158 = 0;  // [n,0](GPIO158),          [0,1](EPWM7B[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO158 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPEGMUX2.bit.GPIO159 = 0;  // [n,0](GPIO159),          [0,1](EPWM8A[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPEMUX2.bit.GPIO158 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    // GPIOE-2 Input/Output of GPIO         ; 0(Input), 1(Output)
    GpioCtrlRegs.GPEDIR.bit.GPIO144 = 1;
    GpioCtrlRegs.GPEDIR.bit.GPIO145 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO146 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO147 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO148 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO149 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO150 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO151 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO152 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO153 = 1;
    GpioCtrlRegs.GPEDIR.bit.GPIO154 = 1;
    GpioCtrlRegs.GPEDIR.bit.GPIO155 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO156 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO157 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO158 = 0;
    GpioCtrlRegs.GPEDIR.bit.GPIO159 = 0;

    // GPIOE-2 Sampling Frequency of GPIO   ; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)    : 0(/1), 1(/2), 2(/4), ..., 255(/510)
    GpioCtrlRegs.GPECTRL.bit.QUALPRD2 = 0;  //GPIO144 ~ GPIO151
    GpioCtrlRegs.GPECTRL.bit.QUALPRD3 = 0;  //GPIO152 ~ GPIO159

    // GPIOE-2 Qualification Mode           ; ACQCLK = SAMPCLK/GPAQSELn             : 0(/1), 1(/2), 2(/5), 3(ASYNCH)
    GpioCtrlRegs.GPEQSEL2.bit.GPIO144 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO145 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO146 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO147 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO148 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO149 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO150 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO151 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO152 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO153 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO154 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO155 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO156 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO157 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO158 = 0;
    GpioCtrlRegs.GPEQSEL2.bit.GPIO159 = 0;

    // GPIOE-2 Internal Pull-up             ; 0(Enable), 1(Disable)
    GpioCtrlRegs.GPEPUD.bit.GPIO144 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO145 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO146 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO147 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO148 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO149 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO150 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO151 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO152 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO153 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO154 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO155 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO156 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO157 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO158 = 1;
    GpioCtrlRegs.GPEPUD.bit.GPIO159 = 1;

    // GPIOE-3 Core Select                  ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPECSEL3.bit.GPIO144 = 0;
    GpioCtrlRegs.GPECSEL3.bit.GPIO145 = 0;
    GpioCtrlRegs.GPECSEL3.bit.GPIO146 = 0;
    GpioCtrlRegs.GPECSEL3.bit.GPIO147 = 0;
    GpioCtrlRegs.GPECSEL3.bit.GPIO148 = 0;
    GpioCtrlRegs.GPECSEL3.bit.GPIO149 = 0;
    GpioCtrlRegs.GPECSEL3.bit.GPIO150 = 0;
    GpioCtrlRegs.GPECSEL3.bit.GPIO151 = 0;
    // GPIOE-4 Core Select                  ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPECSEL4.bit.GPIO152 = 2;
    GpioCtrlRegs.GPECSEL4.bit.GPIO153 = 0;
    GpioCtrlRegs.GPECSEL4.bit.GPIO154 = 0;
    GpioCtrlRegs.GPECSEL4.bit.GPIO155 = 0;
    GpioCtrlRegs.GPECSEL4.bit.GPIO156 = 0;
    GpioCtrlRegs.GPECSEL4.bit.GPIO157 = 0;
    GpioCtrlRegs.GPECSEL4.bit.GPIO158 = 0;
    GpioCtrlRegs.GPECSEL4.bit.GPIO159 = 0;

    //-------------------------------------------------------------------------------------------------//
    //-------------------------------------------- GPIOF-1 --------------------------------------------//
    //-------------------------------------------------------------------------------------------------//
    // GPIOF-1 MUX                          ; [GPxGMUXn,GPxMUXn]
    GpioCtrlRegs.GPFGMUX1.bit.GPIO160 = 0;  // [n,0](GPIO160),          [0,1](EPWM8B[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPFMUX1.bit.GPIO160 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPFGMUX1.bit.GPIO161 = 0;  // [n,0](GPIO161),          [0,1](EPWM9A[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPFMUX1.bit.GPIO161 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPFGMUX1.bit.GPIO162 = 0;  // [n,0](GPIO162),          [0,1](EPWM9B[O]),           [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPFMUX1.bit.GPIO162 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPFGMUX1.bit.GPIO163 = 0;  // [n,0](GPIO163),          [0,1](EPWM10A[O]),          [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPFMUX1.bit.GPIO163 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPFGMUX1.bit.GPIO164 = 0;  // [n,0](GPIO164),          [0,1](EPWM10B[O]),          [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPFMUX1.bit.GPIO164 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPFGMUX1.bit.GPIO165 = 0;  // [n,0](GPIO165),          [0,1](EPWM11A[O]),          [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPFMUX1.bit.GPIO165 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPFGMUX1.bit.GPIO166 = 0;  // [n,0](GPIO166),          [0,1](EPWM11B[O]),          [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPFMUX1.bit.GPIO166 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPFGMUX1.bit.GPIO167 = 0;  // [n,0](GPIO167),          [0,1](EPWM12A[O]),          [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPFMUX1.bit.GPIO167 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    GpioCtrlRegs.GPFGMUX1.bit.GPIO168 = 0;  // [n,0](GPIO168),          [0,1](EPWM12B[O]),          [0,2](Reserved),            [0,3](Reserved)
    GpioCtrlRegs.GPFMUX1.bit.GPIO168 = 0;   // [1,1](Reserved),         [1,2](Reserved),            [1,3](Reserved),            [3,3](Reserved)

    // GPIOF-1 Input/Output of GPIO         ; 0(Input), 1(Output)
    GpioCtrlRegs.GPFDIR.bit.GPIO160 = 0;
    GpioCtrlRegs.GPFDIR.bit.GPIO161 = 0;
    GpioCtrlRegs.GPFDIR.bit.GPIO162 = 0;
    GpioCtrlRegs.GPFDIR.bit.GPIO163 = 0;
    GpioCtrlRegs.GPFDIR.bit.GPIO164 = 0;
    GpioCtrlRegs.GPFDIR.bit.GPIO165 = 0;
    GpioCtrlRegs.GPFDIR.bit.GPIO166 = 0;
    GpioCtrlRegs.GPFDIR.bit.GPIO167 = 0;
    GpioCtrlRegs.GPFDIR.bit.GPIO168 = 0;

    // GPIOF-1 Sampling Frequency of GPIO   ; SAMPCLK = SYSCLKOUT/(2 x QUALPRDn)    : 0(/1), 1(/2), 2(/4), ..., 255(/510)
    GpioCtrlRegs.GPFCTRL.bit.QUALPRD0 = 0;  //GPIO160 ~ GPIO168

    // GPIOF-1 Qualification Mode           ; ACQCLK = SAMPCLK/GPAQSELn             : 0(/1), 1(/2), 2(/5), 3(ASYNCH)
    GpioCtrlRegs.GPFQSEL1.bit.GPIO160 = 0;
    GpioCtrlRegs.GPFQSEL1.bit.GPIO161 = 0;
    GpioCtrlRegs.GPFQSEL1.bit.GPIO162 = 0;
    GpioCtrlRegs.GPFQSEL1.bit.GPIO163 = 0;
    GpioCtrlRegs.GPFQSEL1.bit.GPIO164 = 0;
    GpioCtrlRegs.GPFQSEL1.bit.GPIO165 = 0;
    GpioCtrlRegs.GPFQSEL1.bit.GPIO166 = 0;
    GpioCtrlRegs.GPFQSEL1.bit.GPIO167 = 0;
    GpioCtrlRegs.GPFQSEL1.bit.GPIO168 = 0;

    // GPIOF-1 Internal Pull-up             ; 0(Enable), 1(Disable)
    GpioCtrlRegs.GPFPUD.bit.GPIO160 = 1;
    GpioCtrlRegs.GPFPUD.bit.GPIO161 = 1;
    GpioCtrlRegs.GPFPUD.bit.GPIO162 = 1;
    GpioCtrlRegs.GPFPUD.bit.GPIO163 = 1;
    GpioCtrlRegs.GPFPUD.bit.GPIO164 = 1;
    GpioCtrlRegs.GPFPUD.bit.GPIO165 = 1;
    GpioCtrlRegs.GPFPUD.bit.GPIO166 = 1;
    GpioCtrlRegs.GPFPUD.bit.GPIO167 = 1;
    GpioCtrlRegs.GPFPUD.bit.GPIO168 = 1;

    // GPIOE-1 Core Select                  ; 0(CPU1), 1(CPU1.CLA1), 2(CPU2), 3(CPU2.CLA1)
    GpioCtrlRegs.GPFCSEL1.bit.GPIO160 = 0;
    GpioCtrlRegs.GPFCSEL1.bit.GPIO161 = 0;
    GpioCtrlRegs.GPFCSEL1.bit.GPIO162 = 0;
    GpioCtrlRegs.GPFCSEL1.bit.GPIO163 = 0;
    GpioCtrlRegs.GPFCSEL1.bit.GPIO164 = 0;
    GpioCtrlRegs.GPFCSEL1.bit.GPIO165 = 0;
    GpioCtrlRegs.GPFCSEL1.bit.GPIO166 = 0;
    GpioCtrlRegs.GPFCSEL1.bit.GPIO167 = 0;

    EDIS;
}
#endif
