################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ti-cgt-c6000_8.2.2

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./Includes/AM572x_C66/AM572x_C66_GlobarVariableDefs.obj" \
"./Sources/ADC.obj" \
"./Sources/CtrlModule.obj" \
"./Sources/DAC.obj" \
"./Sources/D_IO.obj" \
"./Sources/Fault.obj" \
"./Sources/GPIO.obj" \
"./Sources/GPMC.obj" \
"./Sources/Group_sorting.obj" \
"./Sources/IPC.obj" \
"./Sources/IntCtrl.obj" \
"./Sources/Interrupt.obj" \
"./Sources/L3_MAIN_interconnect.obj" \
"./Sources/LED.obj" \
"./Sources/MMC_controller.obj" \
"./Sources/Mailbox.obj" \
"./Sources/McSPI.obj" \
"./Sources/PRCM.obj" \
"./Sources/Sensor.obj" \
"./Sources/Timer.obj" \
"./Sources/device.obj" \
"./Sources/main.obj" \
"../AM572x_C66_Headers_nonBIOS.cmd" \
"../AM57xx_C66.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Includes/AM572x_C66/subdir_vars.mk
-include Sources/subdir_vars.mk
-include subdir_rules.mk
-include Includes/AM572x_C66/subdir_rules.mk
-include Sources/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Master_Central_31Lv_DSP_TEST.out \

EXE_OUTPUTS__QUOTED += \
"Master_Central_31Lv_DSP_TEST.out" \

BIN_OUTPUTS += \
Master_Central_31Lv_DSP_TEST.hex \

BIN_OUTPUTS__QUOTED += \
"Master_Central_31Lv_DSP_TEST.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "Master_Central_31Lv_DSP_TEST.out"

# Tool invocations
Master_Central_31Lv_DSP_TEST.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C6000 Linker'
	"C:/ti/ti-cgt-c6000_8.2.2/bin/cl6x" -mv6600 -O2 --define=am5728 --define=core1 --diag_warning=225 --diag_wrap=off --display_error_number -z -m"Master_Central_31Lv_DSP_TEST.map" --heap_size=0x800 --stack_size=0x800 -i"C:/ti/ti-cgt-c6000_8.2.2/lib" -i"C:/ti/ti-cgt-c6000_8.2.2/include" --reread_libs --define=CORE1=1 --diag_wrap=off --display_error_number --warn_sections --xml_link_info="Master_Central_31Lv_DSP_TEST_linkInfo.xml" --rom_model -o "Master_Central_31Lv_DSP_TEST.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

Master_Central_31Lv_DSP_TEST.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: C6000 Hex Utility'
	"C:/ti/ti-cgt-c6000_8.2.2/bin/hex6x" --diag_wrap=off -o "Master_Central_31Lv_DSP_TEST.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "Includes\AM572x_C66\AM572x_C66_GlobarVariableDefs.obj" "Sources\ADC.obj" "Sources\CtrlModule.obj" "Sources\DAC.obj" "Sources\D_IO.obj" "Sources\Fault.obj" "Sources\GPIO.obj" "Sources\GPMC.obj" "Sources\Group_sorting.obj" "Sources\IPC.obj" "Sources\IntCtrl.obj" "Sources\Interrupt.obj" "Sources\L3_MAIN_interconnect.obj" "Sources\LED.obj" "Sources\MMC_controller.obj" "Sources\Mailbox.obj" "Sources\McSPI.obj" "Sources\PRCM.obj" "Sources\Sensor.obj" "Sources\Timer.obj" "Sources\device.obj" "Sources\main.obj" 
	-$(RM) "Includes\AM572x_C66\AM572x_C66_GlobarVariableDefs.d" "Sources\ADC.d" "Sources\CtrlModule.d" "Sources\DAC.d" "Sources\D_IO.d" "Sources\Fault.d" "Sources\GPIO.d" "Sources\GPMC.d" "Sources\Group_sorting.d" "Sources\IPC.d" "Sources\IntCtrl.d" "Sources\Interrupt.d" "Sources\L3_MAIN_interconnect.d" "Sources\LED.d" "Sources\MMC_controller.d" "Sources\Mailbox.d" "Sources\McSPI.d" "Sources\PRCM.d" "Sources\Sensor.d" "Sources\Timer.d" "Sources\device.d" "Sources\main.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

