################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/draw/nxp/vglite/lv_draw_buf_vglite.c \
../LVGL/src/draw/nxp/vglite/lv_draw_vglite.c \
../LVGL/src/draw/nxp/vglite/lv_draw_vglite_arc.c \
../LVGL/src/draw/nxp/vglite/lv_draw_vglite_border.c \
../LVGL/src/draw/nxp/vglite/lv_draw_vglite_fill.c \
../LVGL/src/draw/nxp/vglite/lv_draw_vglite_img.c \
../LVGL/src/draw/nxp/vglite/lv_draw_vglite_label.c \
../LVGL/src/draw/nxp/vglite/lv_draw_vglite_layer.c \
../LVGL/src/draw/nxp/vglite/lv_draw_vglite_line.c \
../LVGL/src/draw/nxp/vglite/lv_draw_vglite_triangle.c \
../LVGL/src/draw/nxp/vglite/lv_vglite_buf.c \
../LVGL/src/draw/nxp/vglite/lv_vglite_matrix.c \
../LVGL/src/draw/nxp/vglite/lv_vglite_path.c \
../LVGL/src/draw/nxp/vglite/lv_vglite_utils.c 

OBJS += \
./LVGL/src/draw/nxp/vglite/lv_draw_buf_vglite.o \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite.o \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_arc.o \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_border.o \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_fill.o \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_img.o \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_label.o \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_layer.o \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_line.o \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_triangle.o \
./LVGL/src/draw/nxp/vglite/lv_vglite_buf.o \
./LVGL/src/draw/nxp/vglite/lv_vglite_matrix.o \
./LVGL/src/draw/nxp/vglite/lv_vglite_path.o \
./LVGL/src/draw/nxp/vglite/lv_vglite_utils.o 

C_DEPS += \
./LVGL/src/draw/nxp/vglite/lv_draw_buf_vglite.d \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite.d \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_arc.d \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_border.d \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_fill.d \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_img.d \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_label.d \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_layer.d \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_line.d \
./LVGL/src/draw/nxp/vglite/lv_draw_vglite_triangle.d \
./LVGL/src/draw/nxp/vglite/lv_vglite_buf.d \
./LVGL/src/draw/nxp/vglite/lv_vglite_matrix.d \
./LVGL/src/draw/nxp/vglite/lv_vglite_path.d \
./LVGL/src/draw/nxp/vglite/lv_vglite_utils.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/draw/nxp/vglite/%.o LVGL/src/draw/nxp/vglite/%.su LVGL/src/draw/nxp/vglite/%.cyclo: ../LVGL/src/draw/nxp/vglite/%.c LVGL/src/draw/nxp/vglite/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-draw-2f-nxp-2f-vglite

clean-LVGL-2f-src-2f-draw-2f-nxp-2f-vglite:
	-$(RM) ./LVGL/src/draw/nxp/vglite/lv_draw_buf_vglite.cyclo ./LVGL/src/draw/nxp/vglite/lv_draw_buf_vglite.d ./LVGL/src/draw/nxp/vglite/lv_draw_buf_vglite.o ./LVGL/src/draw/nxp/vglite/lv_draw_buf_vglite.su ./LVGL/src/draw/nxp/vglite/lv_draw_vglite.cyclo ./LVGL/src/draw/nxp/vglite/lv_draw_vglite.d ./LVGL/src/draw/nxp/vglite/lv_draw_vglite.o ./LVGL/src/draw/nxp/vglite/lv_draw_vglite.su ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_arc.cyclo ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_arc.d ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_arc.o ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_arc.su ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_border.cyclo ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_border.d ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_border.o ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_border.su ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_fill.cyclo ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_fill.d ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_fill.o ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_fill.su ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_img.cyclo ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_img.d ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_img.o ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_img.su ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_label.cyclo ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_label.d ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_label.o ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_label.su ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_layer.cyclo ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_layer.d ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_layer.o ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_layer.su ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_line.cyclo ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_line.d ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_line.o ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_line.su ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_triangle.cyclo ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_triangle.d ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_triangle.o ./LVGL/src/draw/nxp/vglite/lv_draw_vglite_triangle.su ./LVGL/src/draw/nxp/vglite/lv_vglite_buf.cyclo ./LVGL/src/draw/nxp/vglite/lv_vglite_buf.d ./LVGL/src/draw/nxp/vglite/lv_vglite_buf.o ./LVGL/src/draw/nxp/vglite/lv_vglite_buf.su ./LVGL/src/draw/nxp/vglite/lv_vglite_matrix.cyclo ./LVGL/src/draw/nxp/vglite/lv_vglite_matrix.d ./LVGL/src/draw/nxp/vglite/lv_vglite_matrix.o ./LVGL/src/draw/nxp/vglite/lv_vglite_matrix.su ./LVGL/src/draw/nxp/vglite/lv_vglite_path.cyclo ./LVGL/src/draw/nxp/vglite/lv_vglite_path.d ./LVGL/src/draw/nxp/vglite/lv_vglite_path.o ./LVGL/src/draw/nxp/vglite/lv_vglite_path.su ./LVGL/src/draw/nxp/vglite/lv_vglite_utils.cyclo ./LVGL/src/draw/nxp/vglite/lv_vglite_utils.d ./LVGL/src/draw/nxp/vglite/lv_vglite_utils.o ./LVGL/src/draw/nxp/vglite/lv_vglite_utils.su

.PHONY: clean-LVGL-2f-src-2f-draw-2f-nxp-2f-vglite

