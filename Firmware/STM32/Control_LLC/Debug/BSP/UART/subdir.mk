################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/UART/ring_buffer.c \
../BSP/UART/uart.c 

OBJS += \
./BSP/UART/ring_buffer.o \
./BSP/UART/uart.o 

C_DEPS += \
./BSP/UART/ring_buffer.d \
./BSP/UART/uart.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/UART/%.o BSP/UART/%.su BSP/UART/%.cyclo: ../BSP/UART/%.c BSP/UART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32F103xB -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP/UART" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP/PWM" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Middleware/PI_Control" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/Control" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/LED" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Scheduler" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/CMDLine/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP/SysTick" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/Common/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Middleware/Frequency_convert_pulse" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP/I2C" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Devices/ADS1115" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/BSP" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Devices" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/Middleware/Voltage_convert_frequency" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_LLC/App/Data" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-BSP-2f-UART

clean-BSP-2f-UART:
	-$(RM) ./BSP/UART/ring_buffer.cyclo ./BSP/UART/ring_buffer.d ./BSP/UART/ring_buffer.o ./BSP/UART/ring_buffer.su ./BSP/UART/uart.cyclo ./BSP/UART/uart.d ./BSP/UART/uart.o ./BSP/UART/uart.su

.PHONY: clean-BSP-2f-UART

