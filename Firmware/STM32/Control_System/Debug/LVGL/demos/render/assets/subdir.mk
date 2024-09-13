################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/demos/render/assets/img_render_arc_bg.c \
../LVGL/demos/render/assets/img_render_lvgl_logo_argb8888.c \
../LVGL/demos/render/assets/img_render_lvgl_logo_rgb565.c \
../LVGL/demos/render/assets/img_render_lvgl_logo_rgb888.c \
../LVGL/demos/render/assets/img_render_lvgl_logo_xrgb8888.c 

OBJS += \
./LVGL/demos/render/assets/img_render_arc_bg.o \
./LVGL/demos/render/assets/img_render_lvgl_logo_argb8888.o \
./LVGL/demos/render/assets/img_render_lvgl_logo_rgb565.o \
./LVGL/demos/render/assets/img_render_lvgl_logo_rgb888.o \
./LVGL/demos/render/assets/img_render_lvgl_logo_xrgb8888.o 

C_DEPS += \
./LVGL/demos/render/assets/img_render_arc_bg.d \
./LVGL/demos/render/assets/img_render_lvgl_logo_argb8888.d \
./LVGL/demos/render/assets/img_render_lvgl_logo_rgb565.d \
./LVGL/demos/render/assets/img_render_lvgl_logo_rgb888.d \
./LVGL/demos/render/assets/img_render_lvgl_logo_xrgb8888.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/demos/render/assets/%.o LVGL/demos/render/assets/%.su LVGL/demos/render/assets/%.cyclo: ../LVGL/demos/render/assets/%.c LVGL/demos/render/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-demos-2f-render-2f-assets

clean-LVGL-2f-demos-2f-render-2f-assets:
	-$(RM) ./LVGL/demos/render/assets/img_render_arc_bg.cyclo ./LVGL/demos/render/assets/img_render_arc_bg.d ./LVGL/demos/render/assets/img_render_arc_bg.o ./LVGL/demos/render/assets/img_render_arc_bg.su ./LVGL/demos/render/assets/img_render_lvgl_logo_argb8888.cyclo ./LVGL/demos/render/assets/img_render_lvgl_logo_argb8888.d ./LVGL/demos/render/assets/img_render_lvgl_logo_argb8888.o ./LVGL/demos/render/assets/img_render_lvgl_logo_argb8888.su ./LVGL/demos/render/assets/img_render_lvgl_logo_rgb565.cyclo ./LVGL/demos/render/assets/img_render_lvgl_logo_rgb565.d ./LVGL/demos/render/assets/img_render_lvgl_logo_rgb565.o ./LVGL/demos/render/assets/img_render_lvgl_logo_rgb565.su ./LVGL/demos/render/assets/img_render_lvgl_logo_rgb888.cyclo ./LVGL/demos/render/assets/img_render_lvgl_logo_rgb888.d ./LVGL/demos/render/assets/img_render_lvgl_logo_rgb888.o ./LVGL/demos/render/assets/img_render_lvgl_logo_rgb888.su ./LVGL/demos/render/assets/img_render_lvgl_logo_xrgb8888.cyclo ./LVGL/demos/render/assets/img_render_lvgl_logo_xrgb8888.d ./LVGL/demos/render/assets/img_render_lvgl_logo_xrgb8888.o ./LVGL/demos/render/assets/img_render_lvgl_logo_xrgb8888.su

.PHONY: clean-LVGL-2f-demos-2f-render-2f-assets

