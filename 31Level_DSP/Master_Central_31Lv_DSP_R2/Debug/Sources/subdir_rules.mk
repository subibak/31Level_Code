################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Sources/%.obj: ../Sources/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ti-cgt-c6000_8.2.2/bin/cl6x" -mv6600 --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/Master_Central_31Lv_DSP_R2" --include_path="C:/Users/subi/Desktop/31Level_Code/31Level_DSP/Master_Central_31Lv_DSP_R2/Includes" --include_path="C:/ti/ti-cgt-c6000_8.2.2/include" --define=am5728 --define=L2RAM --define=core1 -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="Sources/$(basename $(<F)).d_raw" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


