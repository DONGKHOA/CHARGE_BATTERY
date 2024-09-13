################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/drivers/nuttx/lv_nuttx_cache.c \
../LVGL/src/drivers/nuttx/lv_nuttx_entry.c \
../LVGL/src/drivers/nuttx/lv_nuttx_fbdev.c \
../LVGL/src/drivers/nuttx/lv_nuttx_lcd.c \
../LVGL/src/drivers/nuttx/lv_nuttx_libuv.c \
../LVGL/src/drivers/nuttx/lv_nuttx_profiler.c \
../LVGL/src/drivers/nuttx/lv_nuttx_touchscreen.c 

OBJS += \
./LVGL/src/drivers/nuttx/lv_nuttx_cache.o \
./LVGL/src/drivers/nuttx/lv_nuttx_entry.o \
./LVGL/src/drivers/nuttx/lv_nuttx_fbdev.o \
./LVGL/src/drivers/nuttx/lv_nuttx_lcd.o \
./LVGL/src/drivers/nuttx/lv_nuttx_libuv.o \
./LVGL/src/drivers/nuttx/lv_nuttx_profiler.o \
./LVGL/src/drivers/nuttx/lv_nuttx_touchscreen.o 

C_DEPS += \
./LVGL/src/drivers/nuttx/lv_nuttx_cache.d \
./LVGL/src/drivers/nuttx/lv_nuttx_entry.d \
./LVGL/src/drivers/nuttx/lv_nuttx_fbdev.d \
./LVGL/src/drivers/nuttx/lv_nuttx_lcd.d \
./LVGL/src/drivers/nuttx/lv_nuttx_libuv.d \
./LVGL/src/drivers/nuttx/lv_nuttx_profiler.d \
./LVGL/src/drivers/nuttx/lv_nuttx_touchscreen.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/drivers/nuttx/%.o LVGL/src/drivers/nuttx/%.su LVGL/src/drivers/nuttx/%.cyclo: ../LVGL/src/drivers/nuttx/%.c LVGL/src/drivers/nuttx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-drivers-2f-nuttx

clean-LVGL-2f-src-2f-drivers-2f-nuttx:
	-$(RM) ./LVGL/src/drivers/nuttx/lv_nuttx_cache.cyclo ./LVGL/src/drivers/nuttx/lv_nuttx_cache.d ./LVGL/src/drivers/nuttx/lv_nuttx_cache.o ./LVGL/src/drivers/nuttx/lv_nuttx_cache.su ./LVGL/src/drivers/nuttx/lv_nuttx_entry.cyclo ./LVGL/src/drivers/nuttx/lv_nuttx_entry.d ./LVGL/src/drivers/nuttx/lv_nuttx_entry.o ./LVGL/src/drivers/nuttx/lv_nuttx_entry.su ./LVGL/src/drivers/nuttx/lv_nuttx_fbdev.cyclo ./LVGL/src/drivers/nuttx/lv_nuttx_fbdev.d ./LVGL/src/drivers/nuttx/lv_nuttx_fbdev.o ./LVGL/src/drivers/nuttx/lv_nuttx_fbdev.su ./LVGL/src/drivers/nuttx/lv_nuttx_lcd.cyclo ./LVGL/src/drivers/nuttx/lv_nuttx_lcd.d ./LVGL/src/drivers/nuttx/lv_nuttx_lcd.o ./LVGL/src/drivers/nuttx/lv_nuttx_lcd.su ./LVGL/src/drivers/nuttx/lv_nuttx_libuv.cyclo ./LVGL/src/drivers/nuttx/lv_nuttx_libuv.d ./LVGL/src/drivers/nuttx/lv_nuttx_libuv.o ./LVGL/src/drivers/nuttx/lv_nuttx_libuv.su ./LVGL/src/drivers/nuttx/lv_nuttx_profiler.cyclo ./LVGL/src/drivers/nuttx/lv_nuttx_profiler.d ./LVGL/src/drivers/nuttx/lv_nuttx_profiler.o ./LVGL/src/drivers/nuttx/lv_nuttx_profiler.su ./LVGL/src/drivers/nuttx/lv_nuttx_touchscreen.cyclo ./LVGL/src/drivers/nuttx/lv_nuttx_touchscreen.d ./LVGL/src/drivers/nuttx/lv_nuttx_touchscreen.o ./LVGL/src/drivers/nuttx/lv_nuttx_touchscreen.su

.PHONY: clean-LVGL-2f-src-2f-drivers-2f-nuttx

