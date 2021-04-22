/*
 * Define_MMC_controller.h
 *
 *  Created on: 2019. 1. 11.
 *      Author: subi
 */

#ifndef INCLUDES_AM572X_C66_DEFINE_MMC_CONTROLLER_H_
#define INCLUDES_AM572X_C66_DEFINE_MMC_CONTROLLER_H_

#ifdef __cplusplus
extern "C" {
#endif

// Structure
struct Mode_Info_BITS{
    Uint32      HMI_status:2;
    Uint32      OP_Mode:4;
    Uint32      Valve_Location:2;
    Uint32      Valve_type:2;
    Uint32      Control_Method:2;
    Uint32      Switching_Method:2;
    Uint32      Panel_Mode:2;
    Uint32      Order_Method:2;
    Uint32      Flag_Pre_MC:1;
    Uint32      Flag_Main_MC:1;
    Uint32      Flag_UPS:1;
    Uint32      Flag_Controller:9;
    Uint32      rsvd:2;
};

union Mode_Info_DATA {
    struct  Mode_Info_BITS       bit;
    Uint32                       all;
};

extern union Mode_Info_DATA Mode_Info;
extern union Mode_Info_DATA Mode_Info_old;

extern void Converter_Indirect(ST_GXCLC *);
extern void Converter_Direct(ST_GXCLC *);
extern void Inverter_Indirect(ST_GXCLC *);
extern void Inverter_Direct(ST_GXCLC *);

extern void NLC(ST_GXCLC *);
extern void DIR_REF_GENEATOR(ST_GXCLC *);
extern void INDIR_REF_GENEATOR(ST_GXCLC *);
extern void RESET_GxCon(ST_GXCLC *);
extern void SVPWM(ST_GXCLC *);
extern void Inv_VfCon(ST_GXCLC *);
extern void ConV_VfCon(ST_GXCLC *);
extern void VdcCon(ST_GXCLC *);
extern void CcscCon(ST_GXCLC *);
extern void AcCurCon(ST_GXCLC *);
extern void CirCurCon(ST_GXCLC *);
extern void DcCurCon(ST_GXCLC *);
extern void ConvTotalEngyCon(ST_GXCLC *);
extern void InvTotalEngyCon(ST_GXCLC *);
extern void LegEngyBalCon(ST_GXCLC *);
extern void ArmEngyComCon(ST_GXCLC *);
extern void ArmEngyDiffCon(ST_GXCLC *);
extern void DSOGI(ST_GXCLC *);
extern void PLL(ST_GXCLC *);
extern void FPabc2dqe(ST_PH *, ST_DQ *, ST_DQ *, float *, float *);
extern void FPabc2dqs(ST_PH *, ST_DQ *);
extern void FPdqe2abc(ST_DQ *, ST_DQ *, ST_PH *, float *, float *);
extern void FPdqe2dqs(ST_DQ *, ST_DQ *, float *, float *);
extern void FPdqs2abc(ST_DQ *, ST_PH *);
extern void FNabc2dqe(ST_PH *, ST_DQ *, ST_DQ *, float *, float *);
extern void FNabc2dqs(ST_PH *, ST_DQ *);
extern void FNdqe2abc(ST_DQ *, ST_DQ *, ST_PH *, float *, float *);
extern void FNdqe2dqs(ST_DQ *, ST_DQ *, float *, float *);
extern void FNdqs2abc(ST_DQ *, ST_PH *);


#ifdef __cplusplus
}
#endif

#endif /* INCLUDES_AM572X_C66_DEFINE_MMC_CONTROLLER_H_ */
