################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
CPU2_BOOT_FLASH/%.obj: ../CPU2_BOOT_FLASH/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.6.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/GM_MMC31LV_R2" --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/GM_MMC31LV_R2/include" --include_path="C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.6.LTS/include" --define=CPU2 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="CPU2_BOOT_FLASH/$(basename $(<F)).d_raw" --obj_directory="CPU2_BOOT_FLASH" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


