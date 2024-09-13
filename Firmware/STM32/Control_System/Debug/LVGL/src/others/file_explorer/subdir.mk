################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/others/file_explorer/lv_file_explorer.c 

OBJS += \
./LVGL/src/others/file_explorer/lv_file_explorer.o 

C_DEPS += \
./LVGL/src/others/file_explorer/lv_file_explorer.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/others/file_explorer/%.o LVGL/src/others/file_explorer/%.su LVGL/src/others/file_explorer/%.cyclo: ../LVGL/src/others/file_explorer/%.c LVGL/src/others/file_explorer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-others-2f-file_explorer

clean-LVGL-2f-src-2f-others-2f-file_explorer:
	-$(RM) ./LVGL/src/others/file_explorer/lv_file_explorer.cyclo ./LVGL/src/others/file_explorer/lv_file_explorer.d ./LVGL/src/others/file_explorer/lv_file_explorer.o ./LVGL/src/others/file_explorer/lv_file_explorer.su

.PHONY: clean-LVGL-2f-src-2f-others-2f-file_explorer

