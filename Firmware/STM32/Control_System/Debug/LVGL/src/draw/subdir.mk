################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/draw/lv_draw.c \
../LVGL/src/draw/lv_draw_arc.c \
../LVGL/src/draw/lv_draw_img.c \
../LVGL/src/draw/lv_draw_label.c \
../LVGL/src/draw/lv_draw_layer.c \
../LVGL/src/draw/lv_draw_line.c \
../LVGL/src/draw/lv_draw_mask.c \
../LVGL/src/draw/lv_draw_rect.c \
../LVGL/src/draw/lv_draw_transform.c \
../LVGL/src/draw/lv_draw_triangle.c \
../LVGL/src/draw/lv_img_buf.c \
../LVGL/src/draw/lv_img_cache.c \
../LVGL/src/draw/lv_img_decoder.c 

OBJS += \
./LVGL/src/draw/lv_draw.o \
./LVGL/src/draw/lv_draw_arc.o \
./LVGL/src/draw/lv_draw_img.o \
./LVGL/src/draw/lv_draw_label.o \
./LVGL/src/draw/lv_draw_layer.o \
./LVGL/src/draw/lv_draw_line.o \
./LVGL/src/draw/lv_draw_mask.o \
./LVGL/src/draw/lv_draw_rect.o \
./LVGL/src/draw/lv_draw_transform.o \
./LVGL/src/draw/lv_draw_triangle.o \
./LVGL/src/draw/lv_img_buf.o \
./LVGL/src/draw/lv_img_cache.o \
./LVGL/src/draw/lv_img_decoder.o 

C_DEPS += \
./LVGL/src/draw/lv_draw.d \
./LVGL/src/draw/lv_draw_arc.d \
./LVGL/src/draw/lv_draw_img.d \
./LVGL/src/draw/lv_draw_label.d \
./LVGL/src/draw/lv_draw_layer.d \
./LVGL/src/draw/lv_draw_line.d \
./LVGL/src/draw/lv_draw_mask.d \
./LVGL/src/draw/lv_draw_rect.d \
./LVGL/src/draw/lv_draw_transform.d \
./LVGL/src/draw/lv_draw_triangle.d \
./LVGL/src/draw/lv_img_buf.d \
./LVGL/src/draw/lv_img_cache.d \
./LVGL/src/draw/lv_img_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/draw/%.o LVGL/src/draw/%.su LVGL/src/draw/%.cyclo: ../LVGL/src/draw/%.c LVGL/src/draw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/App/CMDLine/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/BSP" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Devices" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Middleware/Ring_Buffer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-draw

clean-LVGL-2f-src-2f-draw:
	-$(RM) ./LVGL/src/draw/lv_draw.cyclo ./LVGL/src/draw/lv_draw.d ./LVGL/src/draw/lv_draw.o ./LVGL/src/draw/lv_draw.su ./LVGL/src/draw/lv_draw_arc.cyclo ./LVGL/src/draw/lv_draw_arc.d ./LVGL/src/draw/lv_draw_arc.o ./LVGL/src/draw/lv_draw_arc.su ./LVGL/src/draw/lv_draw_img.cyclo ./LVGL/src/draw/lv_draw_img.d ./LVGL/src/draw/lv_draw_img.o ./LVGL/src/draw/lv_draw_img.su ./LVGL/src/draw/lv_draw_label.cyclo ./LVGL/src/draw/lv_draw_label.d ./LVGL/src/draw/lv_draw_label.o ./LVGL/src/draw/lv_draw_label.su ./LVGL/src/draw/lv_draw_layer.cyclo ./LVGL/src/draw/lv_draw_layer.d ./LVGL/src/draw/lv_draw_layer.o ./LVGL/src/draw/lv_draw_layer.su ./LVGL/src/draw/lv_draw_line.cyclo ./LVGL/src/draw/lv_draw_line.d ./LVGL/src/draw/lv_draw_line.o ./LVGL/src/draw/lv_draw_line.su ./LVGL/src/draw/lv_draw_mask.cyclo ./LVGL/src/draw/lv_draw_mask.d ./LVGL/src/draw/lv_draw_mask.o ./LVGL/src/draw/lv_draw_mask.su ./LVGL/src/draw/lv_draw_rect.cyclo ./LVGL/src/draw/lv_draw_rect.d ./LVGL/src/draw/lv_draw_rect.o ./LVGL/src/draw/lv_draw_rect.su ./LVGL/src/draw/lv_draw_transform.cyclo ./LVGL/src/draw/lv_draw_transform.d ./LVGL/src/draw/lv_draw_transform.o ./LVGL/src/draw/lv_draw_transform.su ./LVGL/src/draw/lv_draw_triangle.cyclo ./LVGL/src/draw/lv_draw_triangle.d ./LVGL/src/draw/lv_draw_triangle.o ./LVGL/src/draw/lv_draw_triangle.su ./LVGL/src/draw/lv_img_buf.cyclo ./LVGL/src/draw/lv_img_buf.d ./LVGL/src/draw/lv_img_buf.o ./LVGL/src/draw/lv_img_buf.su ./LVGL/src/draw/lv_img_cache.cyclo ./LVGL/src/draw/lv_img_cache.d ./LVGL/src/draw/lv_img_cache.o ./LVGL/src/draw/lv_img_cache.su ./LVGL/src/draw/lv_img_decoder.cyclo ./LVGL/src/draw/lv_img_decoder.d ./LVGL/src/draw/lv_img_decoder.o ./LVGL/src/draw/lv_img_decoder.su

.PHONY: clean-LVGL-2f-src-2f-draw

