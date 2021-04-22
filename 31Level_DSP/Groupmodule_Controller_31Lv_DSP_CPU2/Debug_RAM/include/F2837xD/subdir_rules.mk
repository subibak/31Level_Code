################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
include/F2837xD/%.obj: ../include/F2837xD/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O2 --include_path="C:/Users/subi/Desktop/31Level_Code(190423_1754)/31Level_Code(190423_1754)/31Level_DSP/Groupmodule_Controller_31Lv_DSP_CPU2/include" --include_path="C:/Users/subi/Desktop/31Level_Code(190423_1754)/31Level_Code(190423_1754)/31Level_DSP/Groupmodule_Controller_31Lv_DSP_CPU2" --include_path="C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS/include" --advice:performance=all --define=CPU2 --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="include/F2837xD/$(basename $(<F)).d_raw" --obj_directory="include/F2837xD" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

include/F2837xD/%.obj: ../include/F2837xD/%.asm $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O2 --include_path="C:/Users/subi/Desktop/31Level_Code(190423_1754)/31Level_Code(190423_1754)/31Level_DSP/Groupmodule_Controller_31Lv_DSP_CPU2/include" --include_path="C:/Users/subi/Desktop/31Level_Code(190423_1754)/31Level_Code(190423_1754)/31Level_DSP/Groupmodule_Controller_31Lv_DSP_CPU2" --include_path="C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS/include" --advice:performance=all --define=CPU2 --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="include/F2837xD/$(basename $(<F)).d_raw" --obj_directory="include/F2837xD" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


