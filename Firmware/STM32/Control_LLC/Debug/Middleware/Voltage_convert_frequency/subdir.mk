################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middleware/Voltage_convert_frequency/voltage_convert_frequency.c 

OBJS += \
./Middleware/Voltage_convert_frequency/voltage_convert_frequency.o 

C_DEPS += \
./Middleware/Voltage_convert_frequency/voltage_convert_frequency.d 


# Each subdirectory must supply rules for building sources it contributes
Middleware/Voltage_convert_frequency/%.o Middleware/Voltage_convert_frequency/%.su Middleware/Voltage_convert_frequency/%.cyclo: ../Middleware/Voltage_convert_frequency/%.c Middleware/Voltage_convert_frequency/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../BSP/UART -I../Scheduler -I../BSP/I2C -I../BSP/SysTick -I../App/Control -I../App/LED -I../App/CMDLine/Include -I../App/Common/Include -I../App/Data -I../Middleware/PI_Control -I../Middleware/Frequency_convert_pulse -I../Middleware/Ring_Buffer -I../Middleware/Voltage_convert_frequency -I../Middleware/Current_convert_frequency -I../Devices -I../Devices/ACS712 -I../Devices/ADS1115 -I../BSP -I../BSP/GPIO -I../BSP/TIMER/PWM -I../BSP/TIMER/IRQ -I../App/CheckInputVoltage -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middleware-2f-Voltage_convert_frequency

clean-Middleware-2f-Voltage_convert_frequency:
	-$(RM) ./Middleware/Voltage_convert_frequency/voltage_convert_frequency.cyclo ./Middleware/Voltage_convert_frequency/voltage_convert_frequency.d ./Middleware/Voltage_convert_frequency/voltage_convert_frequency.o ./Middleware/Voltage_convert_frequency/voltage_convert_frequency.su

.PHONY: clean-Middleware-2f-Voltage_convert_frequency

