################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/draw/renesas/dave2d/lv_draw_dave2d.c \
../LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_arc.c \
../LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_border.c \
../LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_fill.c \
../LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_image.c \
../LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_label.c \
../LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_line.c \
../LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.c \
../LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.c \
../LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_utils.c 

OBJS += \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d.o \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_arc.o \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_border.o \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_fill.o \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_image.o \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_label.o \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_line.o \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.o \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.o \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_utils.o 

C_DEPS += \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d.d \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_arc.d \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_border.d \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_fill.d \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_image.d \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_label.d \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_line.d \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.d \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.d \
./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_utils.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/draw/renesas/dave2d/%.o LVGL/src/draw/renesas/dave2d/%.su LVGL/src/draw/renesas/dave2d/%.cyclo: ../LVGL/src/draw/renesas/dave2d/%.c LVGL/src/draw/renesas/dave2d/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-draw-2f-renesas-2f-dave2d

clean-LVGL-2f-src-2f-draw-2f-renesas-2f-dave2d:
	-$(RM) ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d.cyclo ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d.d ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d.o ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d.su ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_arc.cyclo ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_arc.d ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_arc.o ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_arc.su ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_border.cyclo ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_border.d ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_border.o ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_border.su ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_fill.cyclo ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_fill.d ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_fill.o ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_fill.su ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_image.cyclo ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_image.d ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_image.o ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_image.su ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_label.cyclo ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_label.d ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_label.o ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_label.su ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_line.cyclo ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_line.d ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_line.o ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_line.su ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.cyclo ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.d ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.o ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.su ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.cyclo ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.d ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.o ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_triangle.su ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_utils.cyclo ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_utils.d ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_utils.o ./LVGL/src/draw/renesas/dave2d/lv_draw_dave2d_utils.su

.PHONY: clean-LVGL-2f-src-2f-draw-2f-renesas-2f-dave2d

