################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Include/FPGA/%.obj: ../Include/FPGA/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/3LV_SiC_MAIN_VER1_2_20190718_0930" --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/3LV_SiC_MAIN_VER1_2_20190718_0930/Include" --include_path="C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS/include" --advice:performance=all --define=CPU2 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="Include/FPGA/$(basename $(<F)).d_raw" --obj_directory="Include/FPGA" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


