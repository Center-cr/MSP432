################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Bump.obj: D:/MyFiles/Work_Place/inc/Bump.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： ARM Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyFiles/Work_Place/Lab12_Motors/MSP432P4xx" --include_path="D:/MyFiles/Work_Place/Lab12_Motors" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="E:/ProgramInstall/TI/tirslk_maze_1_00_00/inc" --include_path="D:/MyFiles/Work_Place/inc" --advice:power=all --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Clock.obj: D:/MyFiles/Work_Place/inc/Clock.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： ARM Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyFiles/Work_Place/Lab12_Motors/MSP432P4xx" --include_path="D:/MyFiles/Work_Place/Lab12_Motors" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="E:/ProgramInstall/TI/tirslk_maze_1_00_00/inc" --include_path="D:/MyFiles/Work_Place/inc" --advice:power=all --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： ARM Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyFiles/Work_Place/Lab12_Motors/MSP432P4xx" --include_path="D:/MyFiles/Work_Place/Lab12_Motors" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="E:/ProgramInstall/TI/tirslk_maze_1_00_00/inc" --include_path="D:/MyFiles/Work_Place/inc" --advice:power=all --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

LaunchPad.obj: D:/MyFiles/Work_Place/inc/LaunchPad.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： ARM Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyFiles/Work_Place/Lab12_Motors/MSP432P4xx" --include_path="D:/MyFiles/Work_Place/Lab12_Motors" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="E:/ProgramInstall/TI/tirslk_maze_1_00_00/inc" --include_path="D:/MyFiles/Work_Place/inc" --advice:power=all --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

MotorSimple.obj: D:/MyFiles/Work_Place/inc/MotorSimple.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： ARM Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyFiles/Work_Place/Lab12_Motors/MSP432P4xx" --include_path="D:/MyFiles/Work_Place/Lab12_Motors" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="E:/ProgramInstall/TI/tirslk_maze_1_00_00/inc" --include_path="D:/MyFiles/Work_Place/inc" --advice:power=all --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


