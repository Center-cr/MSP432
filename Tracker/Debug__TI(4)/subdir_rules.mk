################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： Arm Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/MyPrograms/ccs/ccs_base/arm/include" --include_path="D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" --include_path="D:/MyFiles/Work_Place/Tracker" --include_path="D:/MyPrograms/ccs/tools/compiler/ti-cgt-arm_5.2.9/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=ccs --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


