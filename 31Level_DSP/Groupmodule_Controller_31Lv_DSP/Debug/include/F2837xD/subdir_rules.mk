################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
include/F2837xD/%.obj: ../include/F2837xD/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1020/ccs/tools/compiler/ti-cgt-c2000_20.2.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/Groupmodule_Controller_31Lv_DSP" --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/Groupmodule_Controller_31Lv_DSP/include/F2837xD" --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/Groupmodule_Controller_31Lv_DSP/include" --include_path="C:/ti/ccs1020/ccs/tools/compiler/ti-cgt-c2000_20.2.2.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="include/F2837xD/$(basename $(<F)).d_raw" --obj_directory="include/F2837xD" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

include/F2837xD/%.obj: ../include/F2837xD/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1020/ccs/tools/compiler/ti-cgt-c2000_20.2.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/Groupmodule_Controller_31Lv_DSP" --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/Groupmodule_Controller_31Lv_DSP/include/F2837xD" --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/Groupmodule_Controller_31Lv_DSP/include" --include_path="C:/ti/ccs1020/ccs/tools/compiler/ti-cgt-c2000_20.2.2.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="include/F2837xD/$(basename $(<F)).d_raw" --obj_directory="include/F2837xD" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


