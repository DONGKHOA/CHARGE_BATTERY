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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP/UART" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP/PWM" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Middleware/PI_Control" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/Control" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/LED" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Scheduler" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/CMDLine/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP/SysTick" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/Common/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Middleware/Frequency_convert_pulse" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP/I2C" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Devices/ADS1115" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Devices" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Middleware/Voltage_convert_frequency" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/Data" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middleware-2f-Frequency_convert_pulse-2f-Private

clean-Middleware-2f-Frequency_convert_pulse-2f-Private:
	-$(RM) ./Middleware/Frequency_convert_pulse/Private/data_private.cyclo ./Middleware/Frequency_convert_pulse/Private/data_private.d ./Middleware/Frequency_convert_pulse/Private/data_private.o ./Middleware/Frequency_convert_pulse/Private/data_private.su

.PHONY: clean-Middleware-2f-Frequency_convert_pulse-2f-Private

