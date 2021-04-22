/*
 * Filter.c
 *
 *  Created on: 2020. 9. 22.
 *      Author: subi
 */

#include "Define_Header.h"


//Digital Filter(IIR type) Second-order IIR Initialization
void DF2O_INIT(ST_DF2CLC *Df)
{
    Uint8 Type;
    float w0;
    float Q;
    float Ts;

    float InvT;
    float SqInvT;
    float InvA0;

    Type = *(Df->Type);
    w0 = *(Df->w0);
    Q  = *(Df->Q);
    Ts = *(Df->Ts);

    /*
     * Digital Filter(IIR) Filter Type
     * Type 1 : 2nd Order Low Pass Filter
     * Type 2 : 2nd Order High Pass Filter
     * Type 3 : 2nd Order Band Pass Filter
     * Type 4 : 2nd Order Band Stop(Notch) Filter
     * Type 5 : 2nd Order All Pass Filter
     *
     * NOTICE : DC, Flat, Center frequency of each filters gain is set to 1.0
     *          Try to manipulate if you want to new gains.
     *          sa[2] for coefficient s^2 is set to 1.0. so it doesn't appear here.
     */
    switch (Type)
    {
    case 1 :
        Df->sa[0] = w0*w0;
        Df->sa[1] = w0/Q;
        Df->sb[0] = 1.0F;
        Df->sb[1] = 0.0F;
        Df->sb[2] = 1.0F;
        break;
    case 2 :
        Df->sa[0] = w0*w0;
        Df->sa[1] = w0/Q;
        Df->sb[0] = 0.0F;
        Df->sb[1] = 0.0F;
        Df->sb[2] = 1.0F;
        break;
    case 3 :
        Df->sa[0] = w0*w0;
        Df->sa[1] = w0/Q;
        Df->sb[0] = 0.0F;
        Df->sb[1] = 1.0F;
        Df->sb[2] = 0.0F;
        break;
    case 4 :
        Df->sa[0] = w0*w0;
        Df->sa[1] = w0/Q;
        Df->sb[0] = w0*w0;
        Df->sb[1] = 0.0F;
        Df->sb[2] = 1.0F;
        break;
    case 5 :
        Df->sa[0] = w0*w0;
        Df->sa[1] = w0/Q;
        Df->sb[0] = w0*w0;
        Df->sb[1] = -w0/Q;
        Df->sb[2] = 1.0F;
        break;
    default :
        break;
    }

    InvT = 2/Ts;
    SqInvT = InvT * InvT;

    Df->za[0] = SqInvT + InvT*Df->sa[1] + Df->sa[0];
    InvA0 = 1/Df->za[0];

    Df->za[1] = 2.0*(Df->sa[0] - SqInvT)*InvA0;
    Df->za[2] = (SqInvT - InvT*Df->sa[1] + Df->sa[0])*InvA0;
    Df->zb[0] = (SqInvT*Df->sb[2] + InvT*Df->sb[1] + Df->sb[0])*InvA0;
    Df->zb[1] = 2.0*(Df->sb[0] - SqInvT*Df->sb[2])*InvA0;
    Df->zb[2] = (SqInvT*Df->sb[2] - InvT*Df->sb[1] + Df->sb[0])*InvA0;

    Df->old[0] = 0.0F;
    Df->old[1] = 0.0F;

    return;
}

//Digital Filter(IIR type) Second-order Operation
float DF2O_OP(float var, ST_DF2CLC *Df)
{
    float flt;

    flt = Df->zb[0]*var + Df->old[0];
    Df->old[0] = Df->old[1] + Df->zb[1]*var - Df->za[1]*flt;
    Df->old[1] = Df->zb[2]*var - Df->za[2]*flt;

    return flt;
}

//Digital Filter(IIR type) First-order IIR Initialization
void DF1O_INIT(ST_DF1CLC *Df)
{
    Uint8 Type;
    float w0;
    float Ts;

    float InvT;
    float InvA0;

    Type = *(Df->Type);
    w0 = *(Df->w0);
    Ts = *(Df->Ts);

    /*
     * Digital Filter(IIR) Filter Type
     * Type 1 : 1st Order Low Pass Filter
     * Type 2 : 1st Order All Pass Filter
     *
     * NOTICE : DC is set to 1.0
     *          Try to manipulate if you want to new gains.
     *          sa1 for coefficient s is set to 1.0. so it doesn't appear here.
     */
    switch (Type)
    {
    case 1 :
        Df->sa0   = w0;
        Df->sb[0] = 1.0F;
        Df->sb[1] = 0.0F;
        break;
    case 2 :
        Df->sa0   = w0;
        Df->sb[0] = -w0;
        Df->sb[1] = 1.0F;
        break;
    default :
        break;
    }

    InvT = 2/Ts;

    Df->za[0] = InvT + Df->sa0;
    InvA0 = 1/Df->za[0];

    Df->za[1] = (Df->sa0 - InvT)*InvA0;
    Df->zb[0] = (InvT*Df->sb[1] + Df->sb[0])*InvA0;
    Df->zb[1] = (Df->sb[0] - InvT*Df->sb[1])*InvA0;

    Df->old = 0.0F;

    return;
}

//Digital Filter(IIR type) First-order Operation
float DF1O_OP(float var, ST_DF1CLC *Df)
{
    float flt;

    flt = Df->zb[0]*var + Df->old;
    Df->old = Df->zb[1]*var - Df->za[1]*flt;

    return flt;
}
