################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/extra/widgets/meter/lv_meter.c 

OBJS += \
./LVGL/src/extra/widgets/meter/lv_meter.o 

C_DEPS += \
./LVGL/src/extra/widgets/meter/lv_meter.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/extra/widgets/meter/%.o LVGL/src/extra/widgets/meter/%.su LVGL/src/extra/widgets/meter/%.cyclo: ../LVGL/src/extra/widgets/meter/%.c LVGL/src/extra/widgets/meter/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/App/CMDLine/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/BSP" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Devices" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-extra-2f-widgets-2f-meter

clean-LVGL-2f-src-2f-extra-2f-widgets-2f-meter:
	-$(RM) ./LVGL/src/extra/widgets/meter/lv_meter.cyclo ./LVGL/src/extra/widgets/meter/lv_meter.d ./LVGL/src/extra/widgets/meter/lv_meter.o ./LVGL/src/extra/widgets/meter/lv_meter.su

.PHONY: clean-LVGL-2f-src-2f-extra-2f-widgets-2f-meter

