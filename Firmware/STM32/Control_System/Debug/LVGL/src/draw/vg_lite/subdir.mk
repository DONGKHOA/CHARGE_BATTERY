################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/draw/vg_lite/lv_draw_buf_vg_lite.c \
../LVGL/src/draw/vg_lite/lv_draw_vg_lite.c \
../LVGL/src/draw/vg_lite/lv_draw_vg_lite_arc.c \
../LVGL/src/draw/vg_lite/lv_draw_vg_lite_border.c \
../LVGL/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.c \
../LVGL/src/draw/vg_lite/lv_draw_vg_lite_fill.c \
../LVGL/src/draw/vg_lite/lv_draw_vg_lite_img.c \
../LVGL/src/draw/vg_lite/lv_draw_vg_lite_label.c \
../LVGL/src/draw/vg_lite/lv_draw_vg_lite_layer.c \
../LVGL/src/draw/vg_lite/lv_draw_vg_lite_line.c \
../LVGL/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.c \
../LVGL/src/draw/vg_lite/lv_draw_vg_lite_triangle.c \
../LVGL/src/draw/vg_lite/lv_draw_vg_lite_vector.c \
../LVGL/src/draw/vg_lite/lv_vg_lite_decoder.c \
../LVGL/src/draw/vg_lite/lv_vg_lite_math.c \
../LVGL/src/draw/vg_lite/lv_vg_lite_path.c \
../LVGL/src/draw/vg_lite/lv_vg_lite_utils.c 

OBJS += \
./LVGL/src/draw/vg_lite/lv_draw_buf_vg_lite.o \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite.o \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_arc.o \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_border.o \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.o \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_fill.o \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_img.o \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_label.o \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_layer.o \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_line.o \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.o \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_triangle.o \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_vector.o \
./LVGL/src/draw/vg_lite/lv_vg_lite_decoder.o \
./LVGL/src/draw/vg_lite/lv_vg_lite_math.o \
./LVGL/src/draw/vg_lite/lv_vg_lite_path.o \
./LVGL/src/draw/vg_lite/lv_vg_lite_utils.o 

C_DEPS += \
./LVGL/src/draw/vg_lite/lv_draw_buf_vg_lite.d \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite.d \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_arc.d \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_border.d \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.d \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_fill.d \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_img.d \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_label.d \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_layer.d \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_line.d \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.d \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_triangle.d \
./LVGL/src/draw/vg_lite/lv_draw_vg_lite_vector.d \
./LVGL/src/draw/vg_lite/lv_vg_lite_decoder.d \
./LVGL/src/draw/vg_lite/lv_vg_lite_math.d \
./LVGL/src/draw/vg_lite/lv_vg_lite_path.d \
./LVGL/src/draw/vg_lite/lv_vg_lite_utils.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/draw/vg_lite/%.o LVGL/src/draw/vg_lite/%.su LVGL/src/draw/vg_lite/%.cyclo: ../LVGL/src/draw/vg_lite/%.c LVGL/src/draw/vg_lite/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-draw-2f-vg_lite

clean-LVGL-2f-src-2f-draw-2f-vg_lite:
	-$(RM) ./LVGL/src/draw/vg_lite/lv_draw_buf_vg_lite.cyclo ./LVGL/src/draw/vg_lite/lv_draw_buf_vg_lite.d ./LVGL/src/draw/vg_lite/lv_draw_buf_vg_lite.o ./LVGL/src/draw/vg_lite/lv_draw_buf_vg_lite.su ./LVGL/src/draw/vg_lite/lv_draw_vg_lite.cyclo ./LVGL/src/draw/vg_lite/lv_draw_vg_lite.d ./LVGL/src/draw/vg_lite/lv_draw_vg_lite.o ./LVGL/src/draw/vg_lite/lv_draw_vg_lite.su ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_arc.cyclo ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_arc.d ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_arc.o ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_arc.su ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_border.cyclo ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_border.d ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_border.o ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_border.su ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.cyclo ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.d ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.o ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.su ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_fill.cyclo ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_fill.d ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_fill.o ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_fill.su ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_img.cyclo ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_img.d ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_img.o ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_img.su ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_label.cyclo ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_label.d ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_label.o ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_label.su ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_layer.cyclo ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_layer.d ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_layer.o ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_layer.su ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_line.cyclo ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_line.d ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_line.o ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_line.su ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.cyclo ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.d ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.o ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_mask_rect.su ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_triangle.cyclo ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_triangle.d ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_triangle.o ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_triangle.su ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_vector.cyclo ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_vector.d ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_vector.o ./LVGL/src/draw/vg_lite/lv_draw_vg_lite_vector.su ./LVGL/src/draw/vg_lite/lv_vg_lite_decoder.cyclo ./LVGL/src/draw/vg_lite/lv_vg_lite_decoder.d ./LVGL/src/draw/vg_lite/lv_vg_lite_decoder.o ./LVGL/src/draw/vg_lite/lv_vg_lite_decoder.su ./LVGL/src/draw/vg_lite/lv_vg_lite_math.cyclo ./LVGL/src/draw/vg_lite/lv_vg_lite_math.d ./LVGL/src/draw/vg_lite/lv_vg_lite_math.o ./LVGL/src/draw/vg_lite/lv_vg_lite_math.su ./LVGL/src/draw/vg_lite/lv_vg_lite_path.cyclo ./LVGL/src/draw/vg_lite/lv_vg_lite_path.d ./LVGL/src/draw/vg_lite/lv_vg_lite_path.o ./LVGL/src/draw/vg_lite/lv_vg_lite_path.su ./LVGL/src/draw/vg_lite/lv_vg_lite_utils.cyclo ./LVGL/src/draw/vg_lite/lv_vg_lite_utils.d ./LVGL/src/draw/vg_lite/lv_vg_lite_utils.o ./LVGL/src/draw/vg_lite/lv_vg_lite_utils.su

.PHONY: clean-LVGL-2f-src-2f-draw-2f-vg_lite

