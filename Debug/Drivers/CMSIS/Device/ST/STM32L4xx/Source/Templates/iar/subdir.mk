################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates/iar/startup_stm32l475xx.s 

OBJS += \
./Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates/iar/startup_stm32l475xx.o 

S_DEPS += \
./Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates/iar/startup_stm32l475xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates/iar/%.o: ../Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates/iar/%.s Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates/iar/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Drivers-2f-CMSIS-2f-Device-2f-ST-2f-STM32L4xx-2f-Source-2f-Templates-2f-iar

clean-Drivers-2f-CMSIS-2f-Device-2f-ST-2f-STM32L4xx-2f-Source-2f-Templates-2f-iar:
	-$(RM) ./Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates/iar/startup_stm32l475xx.d ./Drivers/CMSIS/Device/ST/STM32L4xx/Source/Templates/iar/startup_stm32l475xx.o

.PHONY: clean-Drivers-2f-CMSIS-2f-Device-2f-ST-2f-STM32L4xx-2f-Source-2f-Templates-2f-iar

