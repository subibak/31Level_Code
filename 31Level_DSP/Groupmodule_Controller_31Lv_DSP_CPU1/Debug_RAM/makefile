################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./include/F2837xD/F2837xD_GlobalVariableDefs.obj" \
"./include/F2837xD/F2837xD_usDelay.obj" \
"./source/Dual_core.obj" \
"./source/EMIF.obj" \
"./source/GPIO.obj" \
"./source/IPC.obj" \
"./source/Input_Xbar.obj" \
"./source/Interrupt.obj" \
"./source/LED.obj" \
"./source/Sensor.obj" \
"./source/SysCtrl.obj" \
"./source/WatchDog.obj" \
"./source/ePWM.obj" \
"./source/main.obj" \
"../F2837xD_Headers_nonBIOS_cpu1.cmd" \
"../BOOT_RAM/2837xD_RAM_lnk_cpu1.cmd" \
"../EtherCAT_Library/F2837xD_EtherCAT_Slave_Lib.lib" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-l"C:/Users/subi/Desktop/31Level_Code(190423_1754)/31Level_Code(190423_1754)/31Level_DSP/Groupmodule_Controller_31Lv_DSP_CPU1/EtherCAT_Library/F2837xD_EtherCAT_Slave_Lib.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include BOOT_RAM/subdir_vars.mk
-include EtherCAT_Library/subdir_vars.mk
-include include/F2837xD/subdir_vars.mk
-include source/subdir_vars.mk
-include subdir_rules.mk
-include BOOT_RAM/subdir_rules.mk
-include EtherCAT_Library/subdir_rules.mk
-include include/F2837xD/subdir_rules.mk
-include source/subdir_rules.mk
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
Groupmodule_Controller_31Lv_DSP_CPU1.out \

EXE_OUTPUTS__QUOTED += \
"Groupmodule_Controller_31Lv_DSP_CPU1.out" \

BIN_OUTPUTS += \
Groupmodule_Controller_31Lv_DSP_CPU1.hex \

BIN_OUTPUTS__QUOTED += \
"Groupmodule_Controller_31Lv_DSP_CPU1.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "Groupmodule_Controller_31Lv_DSP_CPU1.out"

# Tool invocations
Groupmodule_Controller_31Lv_DSP_CPU1.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -O2 --define=CPU1 --diag_warning=225 --diag_wrap=off --display_error_number -z -m"Groupmodule_Controller_31Lv_DSP_CPU1.map" --heap_size=0x200 --stack_size=0x200 --warn_sections -i"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS/lib" -i"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="Groupmodule_Controller_31Lv_DSP_CPU1_linkInfo.xml" --rom_model -o "Groupmodule_Controller_31Lv_DSP_CPU1.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

Groupmodule_Controller_31Lv_DSP_CPU1.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: C2000 Hex Utility'
	"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.1.LTS/bin/hex2000"  -o "Groupmodule_Controller_31Lv_DSP_CPU1.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "include\F2837xD\F2837xD_GlobalVariableDefs.obj" "include\F2837xD\F2837xD_usDelay.obj" "source\Dual_core.obj" "source\EMIF.obj" "source\GPIO.obj" "source\IPC.obj" "source\Input_Xbar.obj" "source\Interrupt.obj" "source\LED.obj" "source\Sensor.obj" "source\SysCtrl.obj" "source\WatchDog.obj" "source\ePWM.obj" "source\main.obj" 
	-$(RM) "include\F2837xD\F2837xD_GlobalVariableDefs.d" "source\Dual_core.d" "source\EMIF.d" "source\GPIO.d" "source\IPC.d" "source\Input_Xbar.d" "source\Interrupt.d" "source\LED.d" "source\Sensor.d" "source\SysCtrl.d" "source\WatchDog.d" "source\ePWM.d" "source\main.d" 
	-$(RM) "include\F2837xD\F2837xD_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

