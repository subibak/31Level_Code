################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
source/%.obj: ../source/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS/include" --include_path="C:/Users/subi/Desktop/Code/DSP/workspace_5level_PD_con_20171114/workspace_5level_PD_con_20171101/source" --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/kk_5level/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="source/$(basename $(<F)).d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

source/%.obj: ../source/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS/include" --include_path="C:/Users/subi/Desktop/Code/DSP/workspace_5level_PD_con_20171114/workspace_5level_PD_con_20171101/source" --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/kk_5level/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="source/$(basename $(<F)).d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


