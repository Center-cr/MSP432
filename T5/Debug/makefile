################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./ADC14.obj" \
"./BumpInt.obj" \
"./Clock.obj" \
"./CortexM.obj" \
"./FlashProgram.obj" \
"./IRDistance.obj" \
"./LaunchPad.obj" \
"./Motor.obj" \
"./PWM.obj" \
"./Reflectance.obj" \
"./SysTickInts.obj" \
"./TimerA1.obj" \
"./UART0.obj" \
"./main.obj" \
"./startup_msp432p401r_ccs.obj" \
"./system_msp432p401r.obj" \
"../msp432p401r.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
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
T5.out \

EXE_OUTPUTS__QUOTED += \
"T5.out" \

BIN_OUTPUTS += \
T5.hex \

BIN_OUTPUTS__QUOTED += \
"T5.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "T5.out"

# Tool invocations
T5.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo '正在调用： Arm Linker'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --advice:power=all -g --gcc --define=__MSP432P401R__ --define=ccs --diag_warning=225 --diag_wrap=off --display_error_number -z -m"T5.map" --stack_size=512 --heap_size=1024 -i"D:/MyPrograms/ccs/ccs_base/arm/include" -i"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/lib" -i"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="T5_linkInfo.xml" --rom_model -o "T5.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

T5.hex: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo '正在调用： Arm Hex Utility'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/bin/armhex" --memwidth=8 --romwidth=8 --diag_wrap=off -o "T5.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "ADC14.obj" "BumpInt.obj" "Clock.obj" "CortexM.obj" "FlashProgram.obj" "IRDistance.obj" "LaunchPad.obj" "Motor.obj" "PWM.obj" "Reflectance.obj" "SysTickInts.obj" "TimerA1.obj" "UART0.obj" "main.obj" "startup_msp432p401r_ccs.obj" "system_msp432p401r.obj" 
	-$(RM) "BumpInt.d" "Clock.d" "CortexM.d" "FlashProgram.d" "IRDistance.d" "LaunchPad.d" "Motor.d" "PWM.d" "Reflectance.d" "SysTickInts.d" "TimerA1.d" "UART0.d" "main.d" "startup_msp432p401r_ccs.d" "system_msp432p401r.d" 
	-$(RM) "ADC14.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

