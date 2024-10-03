################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/draw/sw/lv_draw_sw.c \
../LVGL/src/draw/sw/lv_draw_sw_arc.c \
../LVGL/src/draw/sw/lv_draw_sw_blend.c \
../LVGL/src/draw/sw/lv_draw_sw_dither.c \
../LVGL/src/draw/sw/lv_draw_sw_gradient.c \
../LVGL/src/draw/sw/lv_draw_sw_img.c \
../LVGL/src/draw/sw/lv_draw_sw_layer.c \
../LVGL/src/draw/sw/lv_draw_sw_letter.c \
../LVGL/src/draw/sw/lv_draw_sw_line.c \
../LVGL/src/draw/sw/lv_draw_sw_polygon.c \
../LVGL/src/draw/sw/lv_draw_sw_rect.c \
../LVGL/src/draw/sw/lv_draw_sw_transform.c 

OBJS += \
./LVGL/src/draw/sw/lv_draw_sw.o \
./LVGL/src/draw/sw/lv_draw_sw_arc.o \
./LVGL/src/draw/sw/lv_draw_sw_blend.o \
./LVGL/src/draw/sw/lv_draw_sw_dither.o \
./LVGL/src/draw/sw/lv_draw_sw_gradient.o \
./LVGL/src/draw/sw/lv_draw_sw_img.o \
./LVGL/src/draw/sw/lv_draw_sw_layer.o \
./LVGL/src/draw/sw/lv_draw_sw_letter.o \
./LVGL/src/draw/sw/lv_draw_sw_line.o \
./LVGL/src/draw/sw/lv_draw_sw_polygon.o \
./LVGL/src/draw/sw/lv_draw_sw_rect.o \
./LVGL/src/draw/sw/lv_draw_sw_transform.o 

C_DEPS += \
./LVGL/src/draw/sw/lv_draw_sw.d \
./LVGL/src/draw/sw/lv_draw_sw_arc.d \
./LVGL/src/draw/sw/lv_draw_sw_blend.d \
./LVGL/src/draw/sw/lv_draw_sw_dither.d \
./LVGL/src/draw/sw/lv_draw_sw_gradient.d \
./LVGL/src/draw/sw/lv_draw_sw_img.d \
./LVGL/src/draw/sw/lv_draw_sw_layer.d \
./LVGL/src/draw/sw/lv_draw_sw_letter.d \
./LVGL/src/draw/sw/lv_draw_sw_line.d \
./LVGL/src/draw/sw/lv_draw_sw_polygon.d \
./LVGL/src/draw/sw/lv_draw_sw_rect.d \
./LVGL/src/draw/sw/lv_draw_sw_transform.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/draw/sw/%.o LVGL/src/draw/sw/%.su LVGL/src/draw/sw/%.cyclo: ../LVGL/src/draw/sw/%.c LVGL/src/draw/sw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/App/CMDLine/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/BSP" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Devices" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Middleware/Ring_Buffer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-draw-2f-sw

clean-LVGL-2f-src-2f-draw-2f-sw:
	-$(RM) ./LVGL/src/draw/sw/lv_draw_sw.cyclo ./LVGL/src/draw/sw/lv_draw_sw.d ./LVGL/src/draw/sw/lv_draw_sw.o ./LVGL/src/draw/sw/lv_draw_sw.su ./LVGL/src/draw/sw/lv_draw_sw_arc.cyclo ./LVGL/src/draw/sw/lv_draw_sw_arc.d ./LVGL/src/draw/sw/lv_draw_sw_arc.o ./LVGL/src/draw/sw/lv_draw_sw_arc.su ./LVGL/src/draw/sw/lv_draw_sw_blend.cyclo ./LVGL/src/draw/sw/lv_draw_sw_blend.d ./LVGL/src/draw/sw/lv_draw_sw_blend.o ./LVGL/src/draw/sw/lv_draw_sw_blend.su ./LVGL/src/draw/sw/lv_draw_sw_dither.cyclo ./LVGL/src/draw/sw/lv_draw_sw_dither.d ./LVGL/src/draw/sw/lv_draw_sw_dither.o ./LVGL/src/draw/sw/lv_draw_sw_dither.su ./LVGL/src/draw/sw/lv_draw_sw_gradient.cyclo ./LVGL/src/draw/sw/lv_draw_sw_gradient.d ./LVGL/src/draw/sw/lv_draw_sw_gradient.o ./LVGL/src/draw/sw/lv_draw_sw_gradient.su ./LVGL/src/draw/sw/lv_draw_sw_img.cyclo ./LVGL/src/draw/sw/lv_draw_sw_img.d ./LVGL/src/draw/sw/lv_draw_sw_img.o ./LVGL/src/draw/sw/lv_draw_sw_img.su ./LVGL/src/draw/sw/lv_draw_sw_layer.cyclo ./LVGL/src/draw/sw/lv_draw_sw_layer.d ./LVGL/src/draw/sw/lv_draw_sw_layer.o ./LVGL/src/draw/sw/lv_draw_sw_layer.su ./LVGL/src/draw/sw/lv_draw_sw_letter.cyclo ./LVGL/src/draw/sw/lv_draw_sw_letter.d ./LVGL/src/draw/sw/lv_draw_sw_letter.o ./LVGL/src/draw/sw/lv_draw_sw_letter.su ./LVGL/src/draw/sw/lv_draw_sw_line.cyclo ./LVGL/src/draw/sw/lv_draw_sw_line.d ./LVGL/src/draw/sw/lv_draw_sw_line.o ./LVGL/src/draw/sw/lv_draw_sw_line.su ./LVGL/src/draw/sw/lv_draw_sw_polygon.cyclo ./LVGL/src/draw/sw/lv_draw_sw_polygon.d ./LVGL/src/draw/sw/lv_draw_sw_polygon.o ./LVGL/src/draw/sw/lv_draw_sw_polygon.su ./LVGL/src/draw/sw/lv_draw_sw_rect.cyclo ./LVGL/src/draw/sw/lv_draw_sw_rect.d ./LVGL/src/draw/sw/lv_draw_sw_rect.o ./LVGL/src/draw/sw/lv_draw_sw_rect.su ./LVGL/src/draw/sw/lv_draw_sw_transform.cyclo ./LVGL/src/draw/sw/lv_draw_sw_transform.d ./LVGL/src/draw/sw/lv_draw_sw_transform.o ./LVGL/src/draw/sw/lv_draw_sw_transform.su

.PHONY: clean-LVGL-2f-src-2f-draw-2f-sw

