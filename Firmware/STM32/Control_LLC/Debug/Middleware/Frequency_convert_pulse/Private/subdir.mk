################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middleware/Frequency_convert_pulse/Private/data_private.c 

OBJS += \
./Middleware/Frequency_convert_pulse/Private/data_private.o 

C_DEPS += \
./Middleware/Frequency_convert_pulse/Private/data_private.d 


# Each subdirectory must supply rules for building sources it contributes
Middleware/Frequency_convert_pulse/Private/%.o Middleware/Frequency_convert_pulse/Private/%.su Middleware/Frequency_convert_pulse/Private/%.cyclo: ../Middleware/Frequency_convert_pulse/Private/%.c Middleware/Frequency_convert_pulse/Private/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -DUSE_FULL_LL_DRIVER -DHSE_VALUE=8000000 -DHSE_STARTUP_TIMEOUT=100 -DLSE_STARTUP_TIMEOUT=5000 -DLSE_VALUE=32768 -DHSI_VALUE=8000000 -DLSI_VALUE=40000 -DVDD_VALUE=3300 -DPREFETCH_ENABLE=1 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../BSP/UART -I../Scheduler -I../BSP/I2C -I../BSP/SysTick -I../App/Control -I../App/LED -I../App/CMDLine/Include -I../App/Common/Include -I../App/Data -I../Middleware/PI_Control -I../Middleware/Frequency_convert_pulse -I../Middleware/Ring_Buffer -I../Middleware/Voltage_convert_frequency -I../Middleware/Current_convert_frequency -I../Devices -I../Devices/ACS712 -I../Devices/ADS1115 -I../BSP -I../BSP/GPIO -I../Middleware/Read_220VAC -I../BSP/TIMER/PWM -I../BSP/TIMER/IRQ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middleware-2f-Frequency_convert_pulse-2f-Private

clean-Middleware-2f-Frequency_convert_pulse-2f-Private:
	-$(RM) ./Middleware/Frequency_convert_pulse/Private/data_private.cyclo ./Middleware/Frequency_convert_pulse/Private/data_private.d ./Middleware/Frequency_convert_pulse/Private/data_private.o ./Middleware/Frequency_convert_pulse/Private/data_private.su

.PHONY: clean-Middleware-2f-Frequency_convert_pulse-2f-Private

