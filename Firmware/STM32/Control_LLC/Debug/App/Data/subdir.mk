################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Data/app_data_struct.c 

OBJS += \
./App/Data/app_data_struct.o 

C_DEPS += \
./App/Data/app_data_struct.d 


# Each subdirectory must supply rules for building sources it contributes
App/Data/%.o App/Data/%.su App/Data/%.cyclo: ../App/Data/%.c App/Data/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -DUSE_FULL_LL_DRIVER -DHSE_VALUE=8000000 -DHSE_STARTUP_TIMEOUT=100 -DLSE_STARTUP_TIMEOUT=5000 -DLSE_VALUE=32768 -DHSI_VALUE=8000000 -DLSI_VALUE=40000 -DVDD_VALUE=3300 -DPREFETCH_ENABLE=1 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP/UART" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP/PWM" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Middleware/PI_Control" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/Control" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/LED" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Scheduler" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/CMDLine/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP/SysTick" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/Common/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Middleware/Frequency_convert_pulse" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP/I2C" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Devices/ADS1115" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Devices" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Middleware/Voltage_convert_frequency" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/Data" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Middleware/Ring_Buffer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-App-2f-Data

clean-App-2f-Data:
	-$(RM) ./App/Data/app_data_struct.cyclo ./App/Data/app_data_struct.d ./App/Data/app_data_struct.o ./App/Data/app_data_struct.su

.PHONY: clean-App-2f-Data

