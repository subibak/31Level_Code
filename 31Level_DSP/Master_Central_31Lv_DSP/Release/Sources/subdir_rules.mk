################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Sources/%.obj: ../Sources/%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.2.5/bin/cl6x" -mv6600 -O2 --include_path="C:/Users/MP2C/Desktop/subi_code/BTB_31level/31Level_Code(190423_1754)/31Level_DSP/Master_Central_31Lv_DSP" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.2.5/include" --define=am5728 --define=core1 --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="Sources/$(basename $(<F)).d_raw" --obj_directory="Sources" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


