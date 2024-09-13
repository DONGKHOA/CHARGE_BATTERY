################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/draw/sw/blend/lv_draw_sw_blend.c \
../LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.c \
../LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.c \
../LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.c 

OBJS += \
./LVGL/src/draw/sw/blend/lv_draw_sw_blend.o \
./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.o \
./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.o \
./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.o 

C_DEPS += \
./LVGL/src/draw/sw/blend/lv_draw_sw_blend.d \
./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.d \
./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.d \
./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/draw/sw/blend/%.o LVGL/src/draw/sw/blend/%.su LVGL/src/draw/sw/blend/%.cyclo: ../LVGL/src/draw/sw/blend/%.c LVGL/src/draw/sw/blend/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-draw-2f-sw-2f-blend

clean-LVGL-2f-src-2f-draw-2f-sw-2f-blend:
	-$(RM) ./LVGL/src/draw/sw/blend/lv_draw_sw_blend.cyclo ./LVGL/src/draw/sw/blend/lv_draw_sw_blend.d ./LVGL/src/draw/sw/blend/lv_draw_sw_blend.o ./LVGL/src/draw/sw/blend/lv_draw_sw_blend.su ./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.cyclo ./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.d ./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.o ./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_argb8888.su ./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.cyclo ./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.d ./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.o ./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_rgb565.su ./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.cyclo ./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.d ./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.o ./LVGL/src/draw/sw/blend/lv_draw_sw_blend_to_rgb888.su

.PHONY: clean-LVGL-2f-src-2f-draw-2f-sw-2f-blend

