################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Clock.obj: D:/MyFiles/Work_Place/inc/Clock.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： ARM Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/Lab08_Track_Maze" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

JN_LCD.obj: D:/MyFiles/Work_Place/inc/JN_LCD.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： ARM Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/Lab08_Track_Maze" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Motor.obj: D:/MyFiles/Work_Place/inc/Motor.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： ARM Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/Lab08_Track_Maze" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

PWM.obj: D:/MyFiles/Work_Place/inc/PWM.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： ARM Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/Lab08_Track_Maze" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Reflectance.obj: D:/MyFiles/Work_Place/inc/Reflectance.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： ARM Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/Lab08_Track_Maze" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

UART0.obj: D:/MyFiles/Work_Place/inc/UART0.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： ARM Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/Lab08_Track_Maze" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： ARM Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/Lab08_Track_Maze" --include_path="D:/MyFiles/Work_Place/inc" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


