/*
 * Aritmetic_test.c
 *
 *  Created on: 2021. 3. 23.
 *      Author: subi
 */

#include "Define_Header.h"

#define SUM     1
#define SUB     2
#define MUL     3
#define DIV     4
#define LOOPFOR 5
#define ARRARY  10
#define SEVERAL 20

float   mSum = 0.0, mSub, mMul = 0.0, mDiv = 0.0;
float   rSum[10] = {0.0,}, rSub[10] = {0.0,}, rMul[10] = {0.0,}, rDiv[10] = {0.0,};
float   mA = 1.0, mB = 1.0;
float   rA[10] = {1.0,}, rB[10] = {1.0,};
float   rSum0 = 0.0, rSum1 = 0.0, rSum2 = 0.0, rSum3 = 0.0, rSum4 = 0.0, rSum5 = 0.0;
float   rSub0 = 0.0, rSub1 = 0.0, rSub2 = 0.0, rSub3 = 0.0, rSub4 = 0.0, rSub5 = 0.0;
float   rMul0 = 0.0, rMul1 = 0.0, rMul2 = 0.0, rMul3 = 0.0, rMul4 = 0.0, rMul5 = 0.0;
float   rDiv0 = 0.0, rDiv1 = 0.0, rDiv2 = 0.0, rDiv3 = 0.0, rDiv4 = 0.0, rDiv5 = 0.0;
float   mA0 = 1.0, mA1 = 1.0, mA2 = 1.0, mA3 = 1.0, mA4 = 1.0, mA5 = 1.0;
float   mB0 = 1.0, mB1 = 1.0, mB2 = 1.0, mB3 = 1.0, mB4 = 1.0, mB5 = 1.0;
float   x = 1.0, z = 100.0;

Uint32  M_CASE = 0;

void AL_test(void)
{
    switch(M_CASE)
    {
        case SUM : XF1_ON; mSum = mA + mB; XF1_OFF; break;
        case SUB : XF1_ON; mSub = mA - mB; XF1_OFF; break;
        case MUL : XF1_ON; mMul = mA * mB; XF1_OFF; break;
        case DIV : XF1_ON; mDiv = mA / mB; XF1_OFF; break;
        case LOOPFOR:
            XF1_ON;

            for(x = 1; x < z; x=x + 1.0)
            {
            }

            XF1_OFF;
            break;
        case SUM + LOOPFOR :
            XF1_ON;

            for(x = 1; x < z; x=x + 1.0)
            {
                mSum = mB + mA;
            }

            XF1_OFF;
            break;
        case SUB + LOOPFOR :
            XF1_ON;

            for(x = 1; x < z; x=x + 1.0)
            {
                mSub = mB - mA;
            }

            XF1_OFF;
            break;
        case MUL + LOOPFOR :
            XF1_ON;

            for(x = 1; x < z; x=x + 1.0)
            {
                mMul = mB * mA;
            }

            XF1_OFF;
            break;
        case DIV + LOOPFOR:
            XF1_ON;

            for(x = 1; x < z; x=x + 1.0)
            {
                mDiv = mB / mA;
            }

            XF1_OFF;
            break;
        case SUM + ARRARY:
            XF1_ON;
            rSum[0] = rA[0] + rB[0];
            rSum[1] = rA[1] + rB[1];
            rSum[2] = rA[2] + rB[2];
            rSum[3] = rA[3] + rB[3];
            rSum[4] = rA[4] + rB[4];
            XF1_OFF;
            break;
        case SUB + ARRARY:
            XF1_ON;
            rSub[0] = rA[0] - rB[0];
            rSub[1] = rA[1] - rB[1];
            rSub[2] = rA[2] - rB[2];
            rSub[3] = rA[3] - rB[3];
            rSub[4] = rA[4] - rB[4];
            XF1_OFF;
            break;
        case MUL + ARRARY:
            XF1_ON;
            rMul[0] = rA[0] * rB[0];
            rMul[1] = rA[1] * rB[1];
            rMul[2] = rA[2] * rB[2];
            rMul[3] = rA[3] * rB[3];
            rMul[4] = rA[4] * rB[4];
            XF1_OFF;
            break;
        case DIV + ARRARY:
            XF1_ON;
            rDiv[0] = rA[0] / rB[0];
            rDiv[1] = rA[1] / rB[1];
            rDiv[2] = rA[2] / rB[2];
            rDiv[3] = rA[3] / rB[3];
            rDiv[4] = rA[4] / rB[4];
            XF1_OFF;
            break;
        case SUM + SEVERAL:
            XF1_ON;
            rSum0 = mA0 + mB0;
            rSum1 = mA1 + mB1;
            rSum2 = mA2 + mB2;
            rSum3 = mA3 + mB3;
            rSum4 = mA4 + mB4;
            XF1_OFF;
            break;
        case SUB + SEVERAL:
            XF1_ON;
            rSub0 = mA0 - mB0;
            rSub1 = mA1 - mB1;
            rSub2 = mA2 - mB2;
            rSub3 = mA3 - mB3;
            rSub4 = mA4 - mB4;
            XF1_OFF;
            break;
        case MUL + SEVERAL:
            XF1_ON;
            rMul0 = mA0 * mB0;
            rMul1 = mA1 * mB1;
            rMul2 = mA2 * mB2;
            rMul3 = mA3 * mB3;
            rMul4 = mA4 * mB4;
            XF1_OFF;
            break;
        case DIV + SEVERAL:
            XF1_ON;
            rDiv0 = mA0 / mB0;
            rDiv1 = mA1 / mB1;
            rDiv2 = mA2 / mB2;
            rDiv3 = mA3 / mB3;
            rDiv4 = mA4 / mB4;
            XF1_OFF;
            break;
        default  : XF1_ON; XF1_OFF; break;
    }

    if(mA > 100.0)
        mA = 0.55555;
    else
        mA++;

    if(mB > 101.0)
        mB = 0.44444;
    else
        mB++;

    for(x = 0; x < 10; x++)
    {
        *(rA + (int)x) += 0.44444;
        *(rB + (int)x) += 0.55555;
    }

    if(rA[0] > 100.0)
        rA[0] = 0.55555;
    else
        rA[0] += 1.0;

    if(rB[0] > 101.0)
        rB[0] = 0.44444;
    else
        rB[0] += 1.0;

    if(mA0 > 100.0)
    {
        mA0 = 0.55555;
        mA1 = 0.45555;
        mA2 = 0.35555;
        mA3 = 0.25555;
        mA4 = 0.15555;
    }
    else
    {
        mA0 += 1.0;
        mA1 += 1.0;
        mA2 += 1.0;
        mA3 += 1.0;
        mA4 += 1.0;

    }
    if(mB0 > 100.0)
    {
        mB0 = 0.55555;
        mB1 = 0.45555;
        mB2 = 0.35555;
        mB3 = 0.25555;
        mB4 = 0.15555;
    }
    else
    {
        mB0 += 1.0;
        mB1 += 1.0;
        mB2 += 1.0;
        mB3 += 1.0;
        mB4 += 1.0;
    }
}
