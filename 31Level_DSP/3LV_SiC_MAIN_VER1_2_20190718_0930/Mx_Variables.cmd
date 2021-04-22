/*
 * 2837xD_RAM_lnk_cpu1.cmd
 *
 *   Edited on: 2019. 06. 21.
 *      Author: TI Co.
 *		Editor: HJHeo
 *
 */

#define M1VAR_BASE							0x011000	// RAMGS5 Start Address
#define M2VAR_BASE							0x019000	// RAMGS13 Start Address

#define MxSYS_OFFSET						0x000000
#define MxSAMP_LENGTH						0x00001A
#define MxPARA_LENGTH						0x00000C
#define MxCONT_LENGTH						0x000014
#define MxCOUNT_LENGTH						0x000004
#define MxFLAG_LENGTH						0x000003 + 0x000002

#define MxCGN_OFFSET						0x000050
#define MxKOUT_LENGTH						0x000006
#define MxKIN_LENGTH						0x00000C
#define MxKOFF_LENGTH						0x000002
#define MxKPLL_LENGTH						0x000006

#define MxANG_OFFSET						0x000070
#define MxEL_LENGTH							0x000006
#define MxEP_LENGTH							0x000006
#define MxES_LENGTH							0x000004
#define MxEE_ERR_LENGTH						0x00000A
#define MxEE_ERR_LOW_OLD_LENGTH				0x000002
#define MxEE_LENGTH							0x000014
#define MxTHETA_SENS_LENGTH					0x000014

#define MxSPD_OFFSET						0x0000C0
#define MxRPM_REF_LENGTH					0x000002
#define MxWM_REF_LENGTH						0x000002
#define MxWM_ERR_LENGTH						0x000002
#define MxSPEED_SENS_LENGTH					0x00000E

#define MxCUR_OFFSET						0x0000E0
#define MxIE_REF_PROP_LENGTH				0x000002
#define MxIE_REF_INTEG_LENGTH				0x000002
#define MxIE_REF_ANTI_LENGTH				0x000002
#define MxIE_REF_UL_LENGTH					0x000002
#define MxIE_REF_LENGTH						0x000004
#define MxIE_ERR_LENGTH						0x000004
#define MxIP_LENGTH							0x000006
#define MxIP_SUM_LENGTH						0x000006
#define MxIP_OFFSET_LENGTH					0x000006 + 0x000004
#define MxIS_LENGTH							0x000004
#define MxIE_LENGTH							0x000004

#define MxVLT_OFFSET						0x000110
#define MxVE_REF_PROP_LENGTH				0x000004
#define MxVE_REF_INTEG_LENGTH				0x000004
#define MxVE_REF_ANTI_LENGTH				0x000004
#define MxVE_REF_LENGTH						0x000004
#define MxVS_REF_LENGTH						0x000004
#define MxVP_REF_LENGTH						0x000006
#define MxVN_REF_LENGTH						0x000008
#define MxVS_LENGTH							0x000004
#define MxVE_LENGTH							0x000004
#define MxNP_REF_LENGTH						0x000006
#define MxNN_REF_LENGTH						0x000008
#define MxCMPU_LENGTH						0x000003
#define MXCMPL_LENGTH						0x000003

#define MxFLT_OFFSET						0x000150
#define MxFAULT_LEVEL_LENGTH				0x000008
#define MxFAULT_REGISTER_LENGTH				0x000001

#define MxCOM_OFFSET						0x000160
#define M1TOM2VP_DATA_LENGTH				0x000001
#define M1TOM2VN_DATA_LENGTH				0x000001
#define M1TOM2IP_DATA_LENGTH				0x000003
#define M1TOM2EL_DATA_LENGTH				0x000003

#define MxVDC_OFFSET						0x000180
#define VDC_LENGTH							0x000028

#define MxDAC_OFFSET						0x000200
#define DA1_LENGTH							0x000008
#define DA2_LENGTH							0x000008
#define DA3_LENGTH							0x000008
#define DA4_LENGTH							0x000008
#define DA1_INVRNG_LENGTH					0x000002
#define DA2_INVRNG_LENGTH					0x000002
#define DA3_INVRNG_LENGTH					0x000002
#define DA4_INVRNG_LENGTH					0x000002
#define DA_TEMP_LENGTH						0x000004
#define DA_RNG_LENGTH						0x000002
#define DA_SEL_LENGTH						0x000001

SECTIONS
{
	//******************** Allocate CPU1 Variables ********************//
	M1SampFile			> M1VAR_BASE + MxSYS_OFFSET
	M1ParaFile			> M1VAR_BASE + MxSYS_OFFSET + MxSAMP_LENGTH
	M1ContFile			> M1VAR_BASE + MxSYS_OFFSET + MxSAMP_LENGTH + MxPARA_LENGTH
	M1CountFile			> M1VAR_BASE + MxSYS_OFFSET + MxSAMP_LENGTH + MxPARA_LENGTH + MxCONT_LENGTH
	M1FlagFile			> M1VAR_BASE + MxSYS_OFFSET + MxSAMP_LENGTH + MxPARA_LENGTH + MxCONT_LENGTH + MxCOUNT_LENGTH

	M1KsFile			> M1VAR_BASE + MxCGN_OFFSET
	M1KcFile			> M1VAR_BASE + MxCGN_OFFSET + MxKOUT_LENGTH
	M1KoffFile			> M1VAR_BASE + MxCGN_OFFSET + MxKOUT_LENGTH + MxKIN_LENGTH

	M1Theta_SensFile	> M1VAR_BASE + MxANG_OFFSET + MxEL_LENGTH + MxEP_LENGTH + MxES_LENGTH + MxEE_ERR_LENGTH + MxEE_LENGTH

	M1RPM_refFile		> M1VAR_BASE + MxSPD_OFFSET
	M1Wm_refFile		> M1VAR_BASE + MxSPD_OFFSET + MxRPM_REF_LENGTH
	M1Wm_errFile		> M1VAR_BASE + MxSPD_OFFSET + MxRPM_REF_LENGTH + MxWM_REF_LENGTH
	M1Speed_SensFile	> M1VAR_BASE + MxSPD_OFFSET + MxRPM_REF_LENGTH + MxWM_REF_LENGTH + MxWM_ERR_LENGTH

	M1Ie_ref_propFile	> M1VAR_BASE + MxCUR_OFFSET
	M1Ie_ref_integFile	> M1VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH
	M1Ie_ref_antiFile	> M1VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH
	M1Ie_ref_ulFile		> M1VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH
	M1Ie_refFile		> M1VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH + MxIE_REF_UL_LENGTH
	M1Ie_errFile		> M1VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH + MxIE_REF_UL_LENGTH + MxIE_REF_LENGTH
	M1IpFile			> M1VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH + MxIE_REF_UL_LENGTH + MxIE_REF_LENGTH + MxIE_ERR_LENGTH
	M1Ip_sumFile		> M1VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH + MxIE_REF_UL_LENGTH + MxIE_REF_LENGTH + MxIE_ERR_LENGTH + MxIP_LENGTH
	M1Ip_offsetFile		> M1VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH + MxIE_REF_UL_LENGTH + MxIE_REF_LENGTH + MxIE_ERR_LENGTH + MxIP_LENGTH + MxIP_SUM_LENGTH
	M1IsFile			> M1VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH + MxIE_REF_UL_LENGTH + MxIE_REF_LENGTH + MxIE_ERR_LENGTH + MxIP_LENGTH + MxIP_SUM_LENGTH + MxIP_OFFSET_LENGTH
	M1IeFile			> M1VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH + MxIE_REF_UL_LENGTH + MxIE_REF_LENGTH + MxIE_ERR_LENGTH + MxIP_LENGTH + MxIP_SUM_LENGTH + MxIP_OFFSET_LENGTH + MxIS_LENGTH

	M1Ve_ref_propFile	> M1VAR_BASE + MxVLT_OFFSET
	M1Ve_ref_integFile	> M1VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH
	M1Ve_ref_antiFile	> M1VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH
	M1Ve_refFile		> M1VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH
	M1Vs_refFile		> M1VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH
	M1Vp_refFile		> M1VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH
	M1Vn_refFile		> M1VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH + MxVP_REF_LENGTH
	M1VsFile			> M1VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH + MxVP_REF_LENGTH + MxVN_REF_LENGTH
	M1VeFile			> M1VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH + MxVP_REF_LENGTH + MxVN_REF_LENGTH + MxVS_LENGTH
	M1Np_refFile		> M1VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH + MxVP_REF_LENGTH + MxVN_REF_LENGTH + MxVS_LENGTH + MxVE_LENGTH
	M1Nn_refFile		> M1VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH + MxVP_REF_LENGTH + MxVN_REF_LENGTH + MxVS_LENGTH + MxVE_LENGTH + MxNP_REF_LENGTH
	M1CMPuFile			> M1VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH + MxVP_REF_LENGTH + MxVN_REF_LENGTH + MxVS_LENGTH + MxVE_LENGTH + MxNP_REF_LENGTH + MxNN_REF_LENGTH
	M1CMPlFile			> M1VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH + MxVP_REF_LENGTH + MxVN_REF_LENGTH + MxVS_LENGTH + MxVE_LENGTH + MxNP_REF_LENGTH + MxNN_REF_LENGTH + MxCMPU_LENGTH

	M1Fault_LevelFile	> M1VAR_BASE + MxFLT_OFFSET
	M1Fault_RegisterFile> M1VAR_BASE + MxFLT_OFFSET + MxFAULT_LEVEL_LENGTH

	M1toM2Vp_dataFile	> M1VAR_BASE + MxCOM_OFFSET
	M1toM2Vn_dataFile	> M1VAR_BASE + MxCOM_OFFSET + M1TOM2VP_DATA_LENGTH
	M1toM2Ip_dataFile	> M1VAR_BASE + MxCOM_OFFSET + M1TOM2VP_DATA_LENGTH + M1TOM2VN_DATA_LENGTH
	M1toM2El_dataFile	> M1VAR_BASE + MxCOM_OFFSET + M1TOM2VP_DATA_LENGTH + M1TOM2VN_DATA_LENGTH + M1TOM2IP_DATA_LENGTH

	M1VdcFile			> M1VAR_BASE + MxVDC_OFFSET

	M1da1File			> M1VAR_BASE + MxDAC_OFFSET
	M1da2File			> M1VAR_BASE + MxDAC_OFFSET + DA1_LENGTH
	M1da3File			> M1VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH
	M1da4File			> M1VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH
	M1da1_invrngFile	> M1VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH + DA4_LENGTH
	M1da2_invrngFile	> M1VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH + DA4_LENGTH + DA1_INVRNG_LENGTH
	M1da3_invrngFile	> M1VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH + DA4_LENGTH + DA1_INVRNG_LENGTH + DA2_INVRNG_LENGTH
	M1da4_invrngFile	> M1VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH + DA4_LENGTH + DA1_INVRNG_LENGTH + DA2_INVRNG_LENGTH + DA3_INVRNG_LENGTH
	M1dac_tempFile		> M1VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH + DA4_LENGTH + DA1_INVRNG_LENGTH + DA2_INVRNG_LENGTH + DA3_INVRNG_LENGTH + DA4_INVRNG_LENGTH
	M1da_rngFile		> M1VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH + DA4_LENGTH + DA1_INVRNG_LENGTH + DA2_INVRNG_LENGTH + DA3_INVRNG_LENGTH + DA4_INVRNG_LENGTH + DA_TEMP_LENGTH
	M1da_selFile		> M1VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH + DA4_LENGTH + DA1_INVRNG_LENGTH + DA2_INVRNG_LENGTH + DA3_INVRNG_LENGTH + DA4_INVRNG_LENGTH + DA_TEMP_LENGTH + DA_RNG_LENGTH

	//******************** Allocate CPU2 Variables ********************//
	M2SampFile			> M2VAR_BASE + MxSYS_OFFSET
	M2ParaFile			> M2VAR_BASE + MxSYS_OFFSET + MxSAMP_LENGTH
	M2ContFile			> M2VAR_BASE + MxSYS_OFFSET + MxSAMP_LENGTH + MxPARA_LENGTH
	M2CountFile			> M2VAR_BASE + MxSYS_OFFSET + MxSAMP_LENGTH + MxPARA_LENGTH + MxCONT_LENGTH
	M2FlagFile			> M2VAR_BASE + MxSYS_OFFSET + MxSAMP_LENGTH + MxPARA_LENGTH + MxCONT_LENGTH + MxCOUNT_LENGTH

	M2KsFile			> M2VAR_BASE + MxCGN_OFFSET
	M2KcFile			> M2VAR_BASE + MxCGN_OFFSET + MxKOUT_LENGTH
	M2KoffFile			> M2VAR_BASE + MxCGN_OFFSET + MxKOUT_LENGTH + MxKIN_LENGTH

	M2Theta_SensFile	> M2VAR_BASE + MxANG_OFFSET + MxEL_LENGTH + MxEP_LENGTH + MxES_LENGTH + MxEE_ERR_LENGTH + MxEE_ERR_LOW_OLD_LENGTH + MxEE_LENGTH

	M2RPM_refFile		> M2VAR_BASE + MxSPD_OFFSET
	M2Wm_refFile		> M2VAR_BASE + MxSPD_OFFSET + MxRPM_REF_LENGTH
	M2Wm_errFile		> M2VAR_BASE + MxSPD_OFFSET + MxRPM_REF_LENGTH + MxWM_REF_LENGTH
	M2Speed_SensFile	> M2VAR_BASE + MxSPD_OFFSET + MxRPM_REF_LENGTH + MxWM_REF_LENGTH + MxWM_ERR_LENGTH

	M2Ie_ref_propFile	> M2VAR_BASE + MxCUR_OFFSET
	M2Ie_ref_integFile	> M2VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH
	M2Ie_ref_antiFile	> M2VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH
	M2Ie_ref_ulFile		> M2VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH
	M2Ie_refFile		> M2VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH + MxIE_REF_UL_LENGTH
	M2Ie_errFile		> M2VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH + MxIE_REF_UL_LENGTH + MxIE_REF_LENGTH
	M2IpFile			> M2VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH + MxIE_REF_UL_LENGTH + MxIE_REF_LENGTH + MxIE_ERR_LENGTH
	M2Ip_sumFile		> M2VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH + MxIE_REF_UL_LENGTH + MxIE_REF_LENGTH + MxIE_ERR_LENGTH + MxIP_LENGTH
	M2Ip_offsetFile		> M2VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH + MxIE_REF_UL_LENGTH + MxIE_REF_LENGTH + MxIE_ERR_LENGTH + MxIP_LENGTH + MxIP_SUM_LENGTH
	M2IsFile			> M2VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH + MxIE_REF_UL_LENGTH + MxIE_REF_LENGTH + MxIE_ERR_LENGTH + MxIP_LENGTH + MxIP_SUM_LENGTH + MxIP_OFFSET_LENGTH
	M2IeFile			> M2VAR_BASE + MxCUR_OFFSET + MxIE_REF_PROP_LENGTH + MxIE_REF_INTEG_LENGTH + MxIE_REF_ANTI_LENGTH + MxIE_REF_UL_LENGTH + MxIE_REF_LENGTH + MxIE_ERR_LENGTH + MxIP_LENGTH + MxIP_SUM_LENGTH + MxIP_OFFSET_LENGTH + MxIS_LENGTH

	M2Ve_ref_propFile	> M2VAR_BASE + MxVLT_OFFSET
	M2Ve_ref_integFile	> M2VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH
	M2Ve_ref_antiFile	> M2VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH
	M2Ve_refFile		> M2VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH
	M2Vs_refFile		> M2VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH
	M2Vp_refFile		> M2VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH
	M2Vn_refFile		> M2VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH + MxVP_REF_LENGTH
	M2VsFile			> M2VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH + MxVP_REF_LENGTH + MxVN_REF_LENGTH
	M2VeFile			> M2VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH + MxVP_REF_LENGTH + MxVN_REF_LENGTH + MxVS_LENGTH
	M2Np_refFile		> M2VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH + MxVP_REF_LENGTH + MxVN_REF_LENGTH + MxVS_LENGTH + MxVE_LENGTH
	M2Nn_refFile		> M2VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH + MxVP_REF_LENGTH + MxVN_REF_LENGTH + MxVS_LENGTH + MxVE_LENGTH + MxNP_REF_LENGTH
	M2CMPuFile			> M2VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH + MxVP_REF_LENGTH + MxVN_REF_LENGTH + MxVS_LENGTH + MxVE_LENGTH + MxNP_REF_LENGTH + MxNN_REF_LENGTH
	M2CMPlFile			> M2VAR_BASE + MxVLT_OFFSET + MxVE_REF_PROP_LENGTH + MxVE_REF_INTEG_LENGTH + MxVE_REF_ANTI_LENGTH + MxVE_REF_LENGTH + MxVS_REF_LENGTH + MxVP_REF_LENGTH + MxVN_REF_LENGTH + MxVS_LENGTH + MxVE_LENGTH + MxNP_REF_LENGTH + MxNN_REF_LENGTH + MxCMPU_LENGTH

	M2Fault_LevelFile	> M2VAR_BASE + MxFLT_OFFSET
	M2Fault_RegisterFile> M2VAR_BASE + MxFLT_OFFSET + MxFAULT_LEVEL_LENGTH

	M2VdcFile			> M2VAR_BASE + MxVDC_OFFSET

	M2da1File			> M2VAR_BASE + MxDAC_OFFSET
	M2da2File			> M2VAR_BASE + MxDAC_OFFSET + DA1_LENGTH
	M2da3File			> M2VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH
	M2da4File			> M2VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH
	M2da1_invrngFile	> M2VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH + DA4_LENGTH
	M2da2_invrngFile	> M2VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH + DA4_LENGTH + DA1_INVRNG_LENGTH
	M2da3_invrngFile	> M2VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH + DA4_LENGTH + DA1_INVRNG_LENGTH + DA2_INVRNG_LENGTH
	M2da4_invrngFile	> M2VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH + DA4_LENGTH + DA1_INVRNG_LENGTH + DA2_INVRNG_LENGTH + DA3_INVRNG_LENGTH
	M2dac_tempFile		> M2VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH + DA4_LENGTH + DA1_INVRNG_LENGTH + DA2_INVRNG_LENGTH + DA3_INVRNG_LENGTH + DA4_INVRNG_LENGTH
	M2da_rngFile		> M2VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH + DA4_LENGTH + DA1_INVRNG_LENGTH + DA2_INVRNG_LENGTH + DA3_INVRNG_LENGTH + DA4_INVRNG_LENGTH + DA_TEMP_LENGTH
	M2da_selFile		> M2VAR_BASE + MxDAC_OFFSET + DA1_LENGTH + DA2_LENGTH + DA3_LENGTH + DA4_LENGTH + DA1_INVRNG_LENGTH + DA2_INVRNG_LENGTH + DA3_INVRNG_LENGTH + DA4_INVRNG_LENGTH + DA_TEMP_LENGTH + DA_RNG_LENGTH
}
