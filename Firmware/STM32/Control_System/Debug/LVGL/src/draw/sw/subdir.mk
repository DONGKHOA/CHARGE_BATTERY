################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/draw/sw/lv_draw_sw.c \
../LVGL/src/draw/sw/lv_draw_sw_arc.c \
../LVGL/src/draw/sw/lv_draw_sw_border.c \
../LVGL/src/draw/sw/lv_draw_sw_box_shadow.c \
../LVGL/src/draw/sw/lv_draw_sw_fill.c \
../LVGL/src/draw/sw/lv_draw_sw_gradient.c \
../LVGL/src/draw/sw/lv_draw_sw_img.c \
../LVGL/src/draw/sw/lv_draw_sw_letter.c \
../LVGL/src/draw/sw/lv_draw_sw_line.c \
../LVGL/src/draw/sw/lv_draw_sw_mask.c \
../LVGL/src/draw/sw/lv_draw_sw_mask_rect.c \
../LVGL/src/draw/sw/lv_draw_sw_transform.c \
../LVGL/src/draw/sw/lv_draw_sw_triangle.c \
../LVGL/src/draw/sw/lv_draw_sw_vector.c 

OBJS += \
./LVGL/src/draw/sw/lv_draw_sw.o \
./LVGL/src/draw/sw/lv_draw_sw_arc.o \
./LVGL/src/draw/sw/lv_draw_sw_border.o \
./LVGL/src/draw/sw/lv_draw_sw_box_shadow.o \
./LVGL/src/draw/sw/lv_draw_sw_fill.o \
./LVGL/src/draw/sw/lv_draw_sw_gradient.o \
./LVGL/src/draw/sw/lv_draw_sw_img.o \
./LVGL/src/draw/sw/lv_draw_sw_letter.o \
./LVGL/src/draw/sw/lv_draw_sw_line.o \
./LVGL/src/draw/sw/lv_draw_sw_mask.o \
./LVGL/src/draw/sw/lv_draw_sw_mask_rect.o \
./LVGL/src/draw/sw/lv_draw_sw_transform.o \
./LVGL/src/draw/sw/lv_draw_sw_triangle.o \
./LVGL/src/draw/sw/lv_draw_sw_vector.o 

C_DEPS += \
./LVGL/src/draw/sw/lv_draw_sw.d \
./LVGL/src/draw/sw/lv_draw_sw_arc.d \
./LVGL/src/draw/sw/lv_draw_sw_border.d \
./LVGL/src/draw/sw/lv_draw_sw_box_shadow.d \
./LVGL/src/draw/sw/lv_draw_sw_fill.d \
./LVGL/src/draw/sw/lv_draw_sw_gradient.d \
./LVGL/src/draw/sw/lv_draw_sw_img.d \
./LVGL/src/draw/sw/lv_draw_sw_letter.d \
./LVGL/src/draw/sw/lv_draw_sw_line.d \
./LVGL/src/draw/sw/lv_draw_sw_mask.d \
./LVGL/src/draw/sw/lv_draw_sw_mask_rect.d \
./LVGL/src/draw/sw/lv_draw_sw_transform.d \
./LVGL/src/draw/sw/lv_draw_sw_triangle.d \
./LVGL/src/draw/sw/lv_draw_sw_vector.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/draw/sw/%.o LVGL/src/draw/sw/%.su LVGL/src/draw/sw/%.cyclo: ../LVGL/src/draw/sw/%.c LVGL/src/draw/sw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-draw-2f-sw

clean-LVGL-2f-src-2f-draw-2f-sw:
	-$(RM) ./LVGL/src/draw/sw/lv_draw_sw.cyclo ./LVGL/src/draw/sw/lv_draw_sw.d ./LVGL/src/draw/sw/lv_draw_sw.o ./LVGL/src/draw/sw/lv_draw_sw.su ./LVGL/src/draw/sw/lv_draw_sw_arc.cyclo ./LVGL/src/draw/sw/lv_draw_sw_arc.d ./LVGL/src/draw/sw/lv_draw_sw_arc.o ./LVGL/src/draw/sw/lv_draw_sw_arc.su ./LVGL/src/draw/sw/lv_draw_sw_border.cyclo ./LVGL/src/draw/sw/lv_draw_sw_border.d ./LVGL/src/draw/sw/lv_draw_sw_border.o ./LVGL/src/draw/sw/lv_draw_sw_border.su ./LVGL/src/draw/sw/lv_draw_sw_box_shadow.cyclo ./LVGL/src/draw/sw/lv_draw_sw_box_shadow.d ./LVGL/src/draw/sw/lv_draw_sw_box_shadow.o ./LVGL/src/draw/sw/lv_draw_sw_box_shadow.su ./LVGL/src/draw/sw/lv_draw_sw_fill.cyclo ./LVGL/src/draw/sw/lv_draw_sw_fill.d ./LVGL/src/draw/sw/lv_draw_sw_fill.o ./LVGL/src/draw/sw/lv_draw_sw_fill.su ./LVGL/src/draw/sw/lv_draw_sw_gradient.cyclo ./LVGL/src/draw/sw/lv_draw_sw_gradient.d ./LVGL/src/draw/sw/lv_draw_sw_gradient.o ./LVGL/src/draw/sw/lv_draw_sw_gradient.su ./LVGL/src/draw/sw/lv_draw_sw_img.cyclo ./LVGL/src/draw/sw/lv_draw_sw_img.d ./LVGL/src/draw/sw/lv_draw_sw_img.o ./LVGL/src/draw/sw/lv_draw_sw_img.su ./LVGL/src/draw/sw/lv_draw_sw_letter.cyclo ./LVGL/src/draw/sw/lv_draw_sw_letter.d ./LVGL/src/draw/sw/lv_draw_sw_letter.o ./LVGL/src/draw/sw/lv_draw_sw_letter.su ./LVGL/src/draw/sw/lv_draw_sw_line.cyclo ./LVGL/src/draw/sw/lv_draw_sw_line.d ./LVGL/src/draw/sw/lv_draw_sw_line.o ./LVGL/src/draw/sw/lv_draw_sw_line.su ./LVGL/src/draw/sw/lv_draw_sw_mask.cyclo ./LVGL/src/draw/sw/lv_draw_sw_mask.d ./LVGL/src/draw/sw/lv_draw_sw_mask.o ./LVGL/src/draw/sw/lv_draw_sw_mask.su ./LVGL/src/draw/sw/lv_draw_sw_mask_rect.cyclo ./LVGL/src/draw/sw/lv_draw_sw_mask_rect.d ./LVGL/src/draw/sw/lv_draw_sw_mask_rect.o ./LVGL/src/draw/sw/lv_draw_sw_mask_rect.su ./LVGL/src/draw/sw/lv_draw_sw_transform.cyclo ./LVGL/src/draw/sw/lv_draw_sw_transform.d ./LVGL/src/draw/sw/lv_draw_sw_transform.o ./LVGL/src/draw/sw/lv_draw_sw_transform.su ./LVGL/src/draw/sw/lv_draw_sw_triangle.cyclo ./LVGL/src/draw/sw/lv_draw_sw_triangle.d ./LVGL/src/draw/sw/lv_draw_sw_triangle.o ./LVGL/src/draw/sw/lv_draw_sw_triangle.su ./LVGL/src/draw/sw/lv_draw_sw_vector.cyclo ./LVGL/src/draw/sw/lv_draw_sw_vector.d ./LVGL/src/draw/sw/lv_draw_sw_vector.o ./LVGL/src/draw/sw/lv_draw_sw_vector.su

.PHONY: clean-LVGL-2f-src-2f-draw-2f-sw

