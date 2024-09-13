################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/draw/nxp/pxp/lv_draw_buf_pxp.c \
../LVGL/src/draw/nxp/pxp/lv_draw_pxp.c \
../LVGL/src/draw/nxp/pxp/lv_draw_pxp_fill.c \
../LVGL/src/draw/nxp/pxp/lv_draw_pxp_img.c \
../LVGL/src/draw/nxp/pxp/lv_draw_pxp_layer.c \
../LVGL/src/draw/nxp/pxp/lv_pxp_cfg.c \
../LVGL/src/draw/nxp/pxp/lv_pxp_osa.c \
../LVGL/src/draw/nxp/pxp/lv_pxp_utils.c 

OBJS += \
./LVGL/src/draw/nxp/pxp/lv_draw_buf_pxp.o \
./LVGL/src/draw/nxp/pxp/lv_draw_pxp.o \
./LVGL/src/draw/nxp/pxp/lv_draw_pxp_fill.o \
./LVGL/src/draw/nxp/pxp/lv_draw_pxp_img.o \
./LVGL/src/draw/nxp/pxp/lv_draw_pxp_layer.o \
./LVGL/src/draw/nxp/pxp/lv_pxp_cfg.o \
./LVGL/src/draw/nxp/pxp/lv_pxp_osa.o \
./LVGL/src/draw/nxp/pxp/lv_pxp_utils.o 

C_DEPS += \
./LVGL/src/draw/nxp/pxp/lv_draw_buf_pxp.d \
./LVGL/src/draw/nxp/pxp/lv_draw_pxp.d \
./LVGL/src/draw/nxp/pxp/lv_draw_pxp_fill.d \
./LVGL/src/draw/nxp/pxp/lv_draw_pxp_img.d \
./LVGL/src/draw/nxp/pxp/lv_draw_pxp_layer.d \
./LVGL/src/draw/nxp/pxp/lv_pxp_cfg.d \
./LVGL/src/draw/nxp/pxp/lv_pxp_osa.d \
./LVGL/src/draw/nxp/pxp/lv_pxp_utils.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/draw/nxp/pxp/%.o LVGL/src/draw/nxp/pxp/%.su LVGL/src/draw/nxp/pxp/%.cyclo: ../LVGL/src/draw/nxp/pxp/%.c LVGL/src/draw/nxp/pxp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-draw-2f-nxp-2f-pxp

clean-LVGL-2f-src-2f-draw-2f-nxp-2f-pxp:
	-$(RM) ./LVGL/src/draw/nxp/pxp/lv_draw_buf_pxp.cyclo ./LVGL/src/draw/nxp/pxp/lv_draw_buf_pxp.d ./LVGL/src/draw/nxp/pxp/lv_draw_buf_pxp.o ./LVGL/src/draw/nxp/pxp/lv_draw_buf_pxp.su ./LVGL/src/draw/nxp/pxp/lv_draw_pxp.cyclo ./LVGL/src/draw/nxp/pxp/lv_draw_pxp.d ./LVGL/src/draw/nxp/pxp/lv_draw_pxp.o ./LVGL/src/draw/nxp/pxp/lv_draw_pxp.su ./LVGL/src/draw/nxp/pxp/lv_draw_pxp_fill.cyclo ./LVGL/src/draw/nxp/pxp/lv_draw_pxp_fill.d ./LVGL/src/draw/nxp/pxp/lv_draw_pxp_fill.o ./LVGL/src/draw/nxp/pxp/lv_draw_pxp_fill.su ./LVGL/src/draw/nxp/pxp/lv_draw_pxp_img.cyclo ./LVGL/src/draw/nxp/pxp/lv_draw_pxp_img.d ./LVGL/src/draw/nxp/pxp/lv_draw_pxp_img.o ./LVGL/src/draw/nxp/pxp/lv_draw_pxp_img.su ./LVGL/src/draw/nxp/pxp/lv_draw_pxp_layer.cyclo ./LVGL/src/draw/nxp/pxp/lv_draw_pxp_layer.d ./LVGL/src/draw/nxp/pxp/lv_draw_pxp_layer.o ./LVGL/src/draw/nxp/pxp/lv_draw_pxp_layer.su ./LVGL/src/draw/nxp/pxp/lv_pxp_cfg.cyclo ./LVGL/src/draw/nxp/pxp/lv_pxp_cfg.d ./LVGL/src/draw/nxp/pxp/lv_pxp_cfg.o ./LVGL/src/draw/nxp/pxp/lv_pxp_cfg.su ./LVGL/src/draw/nxp/pxp/lv_pxp_osa.cyclo ./LVGL/src/draw/nxp/pxp/lv_pxp_osa.d ./LVGL/src/draw/nxp/pxp/lv_pxp_osa.o ./LVGL/src/draw/nxp/pxp/lv_pxp_osa.su ./LVGL/src/draw/nxp/pxp/lv_pxp_utils.cyclo ./LVGL/src/draw/nxp/pxp/lv_pxp_utils.d ./LVGL/src/draw/nxp/pxp/lv_pxp_utils.o ./LVGL/src/draw/nxp/pxp/lv_pxp_utils.su

.PHONY: clean-LVGL-2f-src-2f-draw-2f-nxp-2f-pxp

