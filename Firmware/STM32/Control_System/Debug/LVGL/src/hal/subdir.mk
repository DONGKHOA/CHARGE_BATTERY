################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/hal/lv_hal_disp.c \
../LVGL/src/hal/lv_hal_indev.c \
../LVGL/src/hal/lv_hal_tick.c 

OBJS += \
./LVGL/src/hal/lv_hal_disp.o \
./LVGL/src/hal/lv_hal_indev.o \
./LVGL/src/hal/lv_hal_tick.o 

C_DEPS += \
./LVGL/src/hal/lv_hal_disp.d \
./LVGL/src/hal/lv_hal_indev.d \
./LVGL/src/hal/lv_hal_tick.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/hal/%.o LVGL/src/hal/%.su LVGL/src/hal/%.cyclo: ../LVGL/src/hal/%.c LVGL/src/hal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/App/CMDLine/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/BSP" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Devices" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Middleware/Ring_Buffer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-hal

clean-LVGL-2f-src-2f-hal:
	-$(RM) ./LVGL/src/hal/lv_hal_disp.cyclo ./LVGL/src/hal/lv_hal_disp.d ./LVGL/src/hal/lv_hal_disp.o ./LVGL/src/hal/lv_hal_disp.su ./LVGL/src/hal/lv_hal_indev.cyclo ./LVGL/src/hal/lv_hal_indev.d ./LVGL/src/hal/lv_hal_indev.o ./LVGL/src/hal/lv_hal_indev.su ./LVGL/src/hal/lv_hal_tick.cyclo ./LVGL/src/hal/lv_hal_tick.d ./LVGL/src/hal/lv_hal_tick.o ./LVGL/src/hal/lv_hal_tick.su

.PHONY: clean-LVGL-2f-src-2f-hal

