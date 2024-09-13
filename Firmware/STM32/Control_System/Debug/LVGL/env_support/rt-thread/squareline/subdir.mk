################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/env_support/rt-thread/squareline/lv_ui_entry.c 

OBJS += \
./LVGL/env_support/rt-thread/squareline/lv_ui_entry.o 

C_DEPS += \
./LVGL/env_support/rt-thread/squareline/lv_ui_entry.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/env_support/rt-thread/squareline/%.o LVGL/env_support/rt-thread/squareline/%.su LVGL/env_support/rt-thread/squareline/%.cyclo: ../LVGL/env_support/rt-thread/squareline/%.c LVGL/env_support/rt-thread/squareline/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-env_support-2f-rt-2d-thread-2f-squareline

clean-LVGL-2f-env_support-2f-rt-2d-thread-2f-squareline:
	-$(RM) ./LVGL/env_support/rt-thread/squareline/lv_ui_entry.cyclo ./LVGL/env_support/rt-thread/squareline/lv_ui_entry.d ./LVGL/env_support/rt-thread/squareline/lv_ui_entry.o ./LVGL/env_support/rt-thread/squareline/lv_ui_entry.su

.PHONY: clean-LVGL-2f-env_support-2f-rt-2d-thread-2f-squareline

