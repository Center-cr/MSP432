################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo '正在调用： Arm Compiler'
	"D:/MyPrograms/ccs/tools/compiler/ti-cgt-armllvm_2.1.2.LTS/bin/tiarmclang.exe" -c -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mlittle-endian -mthumb -Og -I"D:/MyPrograms/ccs/ccs_base/arm/include" -I"D:/MyPrograms/ccs/ccs_base/arm/include/CMSIS" -I"D:/MyFiles/Work_Place/Tracker" -I"D:/MyPrograms/ccs/tools/compiler/ti-cgt-armllvm_2.1.2.LTS/include" -D__MSP432P401R__ -Dgcc -g -Wall -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


