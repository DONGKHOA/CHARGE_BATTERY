################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/examples/porting/lv_port_disp_template.c \
../LVGL/examples/porting/lv_port_fs_template.c \
../LVGL/examples/porting/lv_port_indev_template.c 

OBJS += \
./LVGL/examples/porting/lv_port_disp_template.o \
./LVGL/examples/porting/lv_port_fs_template.o \
./LVGL/examples/porting/lv_port_indev_template.o 

C_DEPS += \
./LVGL/examples/porting/lv_port_disp_template.d \
./LVGL/examples/porting/lv_port_fs_template.d \
./LVGL/examples/porting/lv_port_indev_template.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/examples/porting/%.o LVGL/examples/porting/%.su LVGL/examples/porting/%.cyclo: ../LVGL/examples/porting/%.c LVGL/examples/porting/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-examples-2f-porting

clean-LVGL-2f-examples-2f-porting:
	-$(RM) ./LVGL/examples/porting/lv_port_disp_template.cyclo ./LVGL/examples/porting/lv_port_disp_template.d ./LVGL/examples/porting/lv_port_disp_template.o ./LVGL/examples/porting/lv_port_disp_template.su ./LVGL/examples/porting/lv_port_fs_template.cyclo ./LVGL/examples/porting/lv_port_fs_template.d ./LVGL/examples/porting/lv_port_fs_template.o ./LVGL/examples/porting/lv_port_fs_template.su ./LVGL/examples/porting/lv_port_indev_template.cyclo ./LVGL/examples/porting/lv_port_indev_template.d ./LVGL/examples/porting/lv_port_indev_template.o ./LVGL/examples/porting/lv_port_indev_template.su

.PHONY: clean-LVGL-2f-examples-2f-porting

