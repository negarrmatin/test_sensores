################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Components/hts221/hts221.c 

OBJS += \
./Core/Components/hts221/hts221.o 

C_DEPS += \
./Core/Components/hts221/hts221.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Components/hts221/%.o Core/Components/hts221/%.su Core/Components/hts221/%.cyclo: ../Core/Components/hts221/%.c Core/Components/hts221/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32L475xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Components-2f-hts221

clean-Core-2f-Components-2f-hts221:
	-$(RM) ./Core/Components/hts221/hts221.cyclo ./Core/Components/hts221/hts221.d ./Core/Components/hts221/hts221.o ./Core/Components/hts221/hts221.su

.PHONY: clean-Core-2f-Components-2f-hts221

