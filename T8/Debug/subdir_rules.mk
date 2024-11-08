################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.C $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： Arm Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/T8" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=ccs --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

BumpInt.obj: D:/MyFiles/Work_Place/inc/BumpInt.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： Arm Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/T8" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=ccs --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： Arm Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/T8" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=ccs --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CortexM.obj: D:/MyFiles/Work_Place/inc/CortexM.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： Arm Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/T8" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=ccs --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FlashProgram.obj: D:/MyFiles/Work_Place/inc/FlashProgram.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： Arm Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/T8" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=ccs --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

LaunchPad.obj: D:/MyFiles/Work_Place/inc/LaunchPad.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： Arm Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/T8" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=ccs --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Reflectance.obj: D:/MyFiles/Work_Place/inc/Reflectance.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： Arm Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/T8" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=ccs --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

SysTickInts.obj: D:/MyFiles/Work_Place/inc/SysTickInts.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： Arm Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/T8" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=ccs --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

TimerA1.obj: D:/MyFiles/Work_Place/inc/TimerA1.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： Arm Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/T8" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=ccs --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

UART0.obj: D:/MyFiles/Work_Place/inc/UART0.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： Arm Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/T8" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=ccs --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


