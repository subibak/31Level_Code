################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
source/%.obj: ../source/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.6.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O2 --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/GM_MMC31LV_R2" --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/GM_MMC31LV_R2/include" --include_path="C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.6.LTS/include" --define=CPU1 --define=CPU2_BOOT_ENABLE --define=CPU2_FLASH_BOOT --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="source/$(basename $(<F)).d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


