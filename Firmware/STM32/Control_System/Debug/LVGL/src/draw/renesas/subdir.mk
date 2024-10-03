################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/draw/renesas/lv_gpu_d2_draw_label.c \
../LVGL/src/draw/renesas/lv_gpu_d2_ra6m3.c 

OBJS += \
./LVGL/src/draw/renesas/lv_gpu_d2_draw_label.o \
./LVGL/src/draw/renesas/lv_gpu_d2_ra6m3.o 

C_DEPS += \
./LVGL/src/draw/renesas/lv_gpu_d2_draw_label.d \
./LVGL/src/draw/renesas/lv_gpu_d2_ra6m3.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/draw/renesas/%.o LVGL/src/draw/renesas/%.su LVGL/src/draw/renesas/%.cyclo: ../LVGL/src/draw/renesas/%.c LVGL/src/draw/renesas/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/App/CMDLine/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/BSP" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Devices" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Middleware/Ring_Buffer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-draw-2f-renesas

clean-LVGL-2f-src-2f-draw-2f-renesas:
	-$(RM) ./LVGL/src/draw/renesas/lv_gpu_d2_draw_label.cyclo ./LVGL/src/draw/renesas/lv_gpu_d2_draw_label.d ./LVGL/src/draw/renesas/lv_gpu_d2_draw_label.o ./LVGL/src/draw/renesas/lv_gpu_d2_draw_label.su ./LVGL/src/draw/renesas/lv_gpu_d2_ra6m3.cyclo ./LVGL/src/draw/renesas/lv_gpu_d2_ra6m3.d ./LVGL/src/draw/renesas/lv_gpu_d2_ra6m3.o ./LVGL/src/draw/renesas/lv_gpu_d2_ra6m3.su

.PHONY: clean-LVGL-2f-src-2f-draw-2f-renesas

