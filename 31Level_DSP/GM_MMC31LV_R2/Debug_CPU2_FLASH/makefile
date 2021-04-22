################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.6.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./CPU2_BOOT_FLASH/DSP28xxx_FLASH_CodeStartBranch.obj" \
"./CPU2_BOOT_FLASH/DSP28xxx_SectionCopy_nonBIOS.obj" \
"./include/F2837xD/F2837xD_GlobalVariableDefs.obj" \
"./include/F2837xD/F2837xD_usDelay.obj" \
"./include/FPGA/FPGA_GlobalVariableDefs.obj" \
"./source/CPU1_Interrupt.obj" \
"./source/CPU2_Interrupt.obj" \
"./source/Dual_core.obj" \
"./source/EMIF.obj" \
"./source/FPGA_GPIO.obj" \
"./source/GPIO.obj" \
"./source/IPC.obj" \
"./source/Input_Xbar.obj" \
"./source/LED.obj" \
"./source/Sensor.obj" \
"./source/SysCtrl.obj" \
"./source/WatchDog.obj" \
"./source/ePWM.obj" \
"./source/main.obj" \
"../CPU1_2_Common/F2837xD_UserDefined_lnk.cmd" \
"../CPU2_BOOT_FLASH/2837xD_FLASH_lnk_cpu2.cmd" \
"../CPU2_BOOT_FLASH/F2837xD_Headers_nonBIOS_cpu2.cmd" \
"../include/FPGA/FPGA_RAM.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include CPU1_2_Common/subdir_vars.mk
-include CPU2_BOOT_FLASH/subdir_vars.mk
-include include/F2837xD/subdir_vars.mk
-include include/FPGA/subdir_vars.mk
-include source/subdir_vars.mk
-include CPU1_2_Common/subdir_rules.mk
-include CPU2_BOOT_FLASH/subdir_rules.mk
-include include/F2837xD/subdir_rules.mk
-include include/FPGA/subdir_rules.mk
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
GM_MMC31LV_CPU2_FLASH.out \

EXE_OUTPUTS__QUOTED += \
"GM_MMC31LV_CPU2_FLASH.out" \

BIN_OUTPUTS += \
GM_MMC31LV_CPU2_FLASH.hex \

BIN_OUTPUTS__QUOTED += \
"GM_MMC31LV_CPU2_FLASH.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "GM_MMC31LV_CPU2_FLASH.out"

# Tool invocations
GM_MMC31LV_CPU2_FLASH.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.6.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 --define=CPU2 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi -z -m"GM_MMC31LV_CPU2_FLASH.map" --heap_size=0x400 --stack_size=0x200 --warn_sections -i"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.6.LTS/lib" -i"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.6.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="GM_MMC31LV_R2_linkInfo.xml" --rom_model -o "GM_MMC31LV_CPU2_FLASH.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

GM_MMC31LV_CPU2_FLASH.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: C2000 Hex Utility'
	"C:/ti/ccs901/ccs/tools/compiler/ti-cgt-c2000_18.12.6.LTS/bin/hex2000"  -o "GM_MMC31LV_CPU2_FLASH.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "CPU2_BOOT_FLASH\DSP28xxx_FLASH_CodeStartBranch.obj" "CPU2_BOOT_FLASH\DSP28xxx_SectionCopy_nonBIOS.obj" "include\F2837xD\F2837xD_GlobalVariableDefs.obj" "include\F2837xD\F2837xD_usDelay.obj" "include\FPGA\FPGA_GlobalVariableDefs.obj" "source\CPU1_Interrupt.obj" "source\CPU2_Interrupt.obj" "source\Dual_core.obj" "source\EMIF.obj" "source\FPGA_GPIO.obj" "source\GPIO.obj" "source\IPC.obj" "source\Input_Xbar.obj" "source\LED.obj" "source\Sensor.obj" "source\SysCtrl.obj" "source\WatchDog.obj" "source\ePWM.obj" "source\main.obj" 
	-$(RM) "include\F2837xD\F2837xD_GlobalVariableDefs.d" "include\FPGA\FPGA_GlobalVariableDefs.d" "source\CPU1_Interrupt.d" "source\CPU2_Interrupt.d" "source\Dual_core.d" "source\EMIF.d" "source\FPGA_GPIO.d" "source\GPIO.d" "source\IPC.d" "source\Input_Xbar.d" "source\LED.d" "source\Sensor.d" "source\SysCtrl.d" "source\WatchDog.d" "source\ePWM.d" "source\main.d" 
	-$(RM) "CPU2_BOOT_FLASH\DSP28xxx_FLASH_CodeStartBranch.d" "CPU2_BOOT_FLASH\DSP28xxx_SectionCopy_nonBIOS.d" "include\F2837xD\F2837xD_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

