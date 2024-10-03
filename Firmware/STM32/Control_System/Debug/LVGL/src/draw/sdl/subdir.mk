################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/draw/sdl/lv_draw_sdl.c \
../LVGL/src/draw/sdl/lv_draw_sdl_arc.c \
../LVGL/src/draw/sdl/lv_draw_sdl_bg.c \
../LVGL/src/draw/sdl/lv_draw_sdl_composite.c \
../LVGL/src/draw/sdl/lv_draw_sdl_img.c \
../LVGL/src/draw/sdl/lv_draw_sdl_label.c \
../LVGL/src/draw/sdl/lv_draw_sdl_layer.c \
../LVGL/src/draw/sdl/lv_draw_sdl_line.c \
../LVGL/src/draw/sdl/lv_draw_sdl_mask.c \
../LVGL/src/draw/sdl/lv_draw_sdl_polygon.c \
../LVGL/src/draw/sdl/lv_draw_sdl_rect.c \
../LVGL/src/draw/sdl/lv_draw_sdl_stack_blur.c \
../LVGL/src/draw/sdl/lv_draw_sdl_texture_cache.c \
../LVGL/src/draw/sdl/lv_draw_sdl_utils.c 

OBJS += \
./LVGL/src/draw/sdl/lv_draw_sdl.o \
./LVGL/src/draw/sdl/lv_draw_sdl_arc.o \
./LVGL/src/draw/sdl/lv_draw_sdl_bg.o \
./LVGL/src/draw/sdl/lv_draw_sdl_composite.o \
./LVGL/src/draw/sdl/lv_draw_sdl_img.o \
./LVGL/src/draw/sdl/lv_draw_sdl_label.o \
./LVGL/src/draw/sdl/lv_draw_sdl_layer.o \
./LVGL/src/draw/sdl/lv_draw_sdl_line.o \
./LVGL/src/draw/sdl/lv_draw_sdl_mask.o \
./LVGL/src/draw/sdl/lv_draw_sdl_polygon.o \
./LVGL/src/draw/sdl/lv_draw_sdl_rect.o \
./LVGL/src/draw/sdl/lv_draw_sdl_stack_blur.o \
./LVGL/src/draw/sdl/lv_draw_sdl_texture_cache.o \
./LVGL/src/draw/sdl/lv_draw_sdl_utils.o 

C_DEPS += \
./LVGL/src/draw/sdl/lv_draw_sdl.d \
./LVGL/src/draw/sdl/lv_draw_sdl_arc.d \
./LVGL/src/draw/sdl/lv_draw_sdl_bg.d \
./LVGL/src/draw/sdl/lv_draw_sdl_composite.d \
./LVGL/src/draw/sdl/lv_draw_sdl_img.d \
./LVGL/src/draw/sdl/lv_draw_sdl_label.d \
./LVGL/src/draw/sdl/lv_draw_sdl_layer.d \
./LVGL/src/draw/sdl/lv_draw_sdl_line.d \
./LVGL/src/draw/sdl/lv_draw_sdl_mask.d \
./LVGL/src/draw/sdl/lv_draw_sdl_polygon.d \
./LVGL/src/draw/sdl/lv_draw_sdl_rect.d \
./LVGL/src/draw/sdl/lv_draw_sdl_stack_blur.d \
./LVGL/src/draw/sdl/lv_draw_sdl_texture_cache.d \
./LVGL/src/draw/sdl/lv_draw_sdl_utils.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/draw/sdl/%.o LVGL/src/draw/sdl/%.su LVGL/src/draw/sdl/%.cyclo: ../LVGL/src/draw/sdl/%.c LVGL/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/App/CMDLine/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/BSP" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Devices" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Middleware/Ring_Buffer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-draw-2f-sdl

clean-LVGL-2f-src-2f-draw-2f-sdl:
	-$(RM) ./LVGL/src/draw/sdl/lv_draw_sdl.cyclo ./LVGL/src/draw/sdl/lv_draw_sdl.d ./LVGL/src/draw/sdl/lv_draw_sdl.o ./LVGL/src/draw/sdl/lv_draw_sdl.su ./LVGL/src/draw/sdl/lv_draw_sdl_arc.cyclo ./LVGL/src/draw/sdl/lv_draw_sdl_arc.d ./LVGL/src/draw/sdl/lv_draw_sdl_arc.o ./LVGL/src/draw/sdl/lv_draw_sdl_arc.su ./LVGL/src/draw/sdl/lv_draw_sdl_bg.cyclo ./LVGL/src/draw/sdl/lv_draw_sdl_bg.d ./LVGL/src/draw/sdl/lv_draw_sdl_bg.o ./LVGL/src/draw/sdl/lv_draw_sdl_bg.su ./LVGL/src/draw/sdl/lv_draw_sdl_composite.cyclo ./LVGL/src/draw/sdl/lv_draw_sdl_composite.d ./LVGL/src/draw/sdl/lv_draw_sdl_composite.o ./LVGL/src/draw/sdl/lv_draw_sdl_composite.su ./LVGL/src/draw/sdl/lv_draw_sdl_img.cyclo ./LVGL/src/draw/sdl/lv_draw_sdl_img.d ./LVGL/src/draw/sdl/lv_draw_sdl_img.o ./LVGL/src/draw/sdl/lv_draw_sdl_img.su ./LVGL/src/draw/sdl/lv_draw_sdl_label.cyclo ./LVGL/src/draw/sdl/lv_draw_sdl_label.d ./LVGL/src/draw/sdl/lv_draw_sdl_label.o ./LVGL/src/draw/sdl/lv_draw_sdl_label.su ./LVGL/src/draw/sdl/lv_draw_sdl_layer.cyclo ./LVGL/src/draw/sdl/lv_draw_sdl_layer.d ./LVGL/src/draw/sdl/lv_draw_sdl_layer.o ./LVGL/src/draw/sdl/lv_draw_sdl_layer.su ./LVGL/src/draw/sdl/lv_draw_sdl_line.cyclo ./LVGL/src/draw/sdl/lv_draw_sdl_line.d ./LVGL/src/draw/sdl/lv_draw_sdl_line.o ./LVGL/src/draw/sdl/lv_draw_sdl_line.su ./LVGL/src/draw/sdl/lv_draw_sdl_mask.cyclo ./LVGL/src/draw/sdl/lv_draw_sdl_mask.d ./LVGL/src/draw/sdl/lv_draw_sdl_mask.o ./LVGL/src/draw/sdl/lv_draw_sdl_mask.su ./LVGL/src/draw/sdl/lv_draw_sdl_polygon.cyclo ./LVGL/src/draw/sdl/lv_draw_sdl_polygon.d ./LVGL/src/draw/sdl/lv_draw_sdl_polygon.o ./LVGL/src/draw/sdl/lv_draw_sdl_polygon.su ./LVGL/src/draw/sdl/lv_draw_sdl_rect.cyclo ./LVGL/src/draw/sdl/lv_draw_sdl_rect.d ./LVGL/src/draw/sdl/lv_draw_sdl_rect.o ./LVGL/src/draw/sdl/lv_draw_sdl_rect.su ./LVGL/src/draw/sdl/lv_draw_sdl_stack_blur.cyclo ./LVGL/src/draw/sdl/lv_draw_sdl_stack_blur.d ./LVGL/src/draw/sdl/lv_draw_sdl_stack_blur.o ./LVGL/src/draw/sdl/lv_draw_sdl_stack_blur.su ./LVGL/src/draw/sdl/lv_draw_sdl_texture_cache.cyclo ./LVGL/src/draw/sdl/lv_draw_sdl_texture_cache.d ./LVGL/src/draw/sdl/lv_draw_sdl_texture_cache.o ./LVGL/src/draw/sdl/lv_draw_sdl_texture_cache.su ./LVGL/src/draw/sdl/lv_draw_sdl_utils.cyclo ./LVGL/src/draw/sdl/lv_draw_sdl_utils.d ./LVGL/src/draw/sdl/lv_draw_sdl_utils.o ./LVGL/src/draw/sdl/lv_draw_sdl_utils.su

.PHONY: clean-LVGL-2f-src-2f-draw-2f-sdl

