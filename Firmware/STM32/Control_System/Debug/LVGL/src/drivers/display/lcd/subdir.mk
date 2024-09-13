################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/drivers/display/lcd/lv_lcd_generic_mipi.c 

OBJS += \
./LVGL/src/drivers/display/lcd/lv_lcd_generic_mipi.o 

C_DEPS += \
./LVGL/src/drivers/display/lcd/lv_lcd_generic_mipi.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/drivers/display/lcd/%.o LVGL/src/drivers/display/lcd/%.su LVGL/src/drivers/display/lcd/%.cyclo: ../LVGL/src/drivers/display/lcd/%.c LVGL/src/drivers/display/lcd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-drivers-2f-display-2f-lcd

clean-LVGL-2f-src-2f-drivers-2f-display-2f-lcd:
	-$(RM) ./LVGL/src/drivers/display/lcd/lv_lcd_generic_mipi.cyclo ./LVGL/src/drivers/display/lcd/lv_lcd_generic_mipi.d ./LVGL/src/drivers/display/lcd/lv_lcd_generic_mipi.o ./LVGL/src/drivers/display/lcd/lv_lcd_generic_mipi.su

.PHONY: clean-LVGL-2f-src-2f-drivers-2f-display-2f-lcd

