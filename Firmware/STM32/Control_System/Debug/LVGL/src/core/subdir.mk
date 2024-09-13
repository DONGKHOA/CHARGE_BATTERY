################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/core/lv_group.c \
../LVGL/src/core/lv_obj.c \
../LVGL/src/core/lv_obj_class.c \
../LVGL/src/core/lv_obj_draw.c \
../LVGL/src/core/lv_obj_event.c \
../LVGL/src/core/lv_obj_id_builtin.c \
../LVGL/src/core/lv_obj_pos.c \
../LVGL/src/core/lv_obj_property.c \
../LVGL/src/core/lv_obj_scroll.c \
../LVGL/src/core/lv_obj_style.c \
../LVGL/src/core/lv_obj_style_gen.c \
../LVGL/src/core/lv_obj_tree.c \
../LVGL/src/core/lv_refr.c 

OBJS += \
./LVGL/src/core/lv_group.o \
./LVGL/src/core/lv_obj.o \
./LVGL/src/core/lv_obj_class.o \
./LVGL/src/core/lv_obj_draw.o \
./LVGL/src/core/lv_obj_event.o \
./LVGL/src/core/lv_obj_id_builtin.o \
./LVGL/src/core/lv_obj_pos.o \
./LVGL/src/core/lv_obj_property.o \
./LVGL/src/core/lv_obj_scroll.o \
./LVGL/src/core/lv_obj_style.o \
./LVGL/src/core/lv_obj_style_gen.o \
./LVGL/src/core/lv_obj_tree.o \
./LVGL/src/core/lv_refr.o 

C_DEPS += \
./LVGL/src/core/lv_group.d \
./LVGL/src/core/lv_obj.d \
./LVGL/src/core/lv_obj_class.d \
./LVGL/src/core/lv_obj_draw.d \
./LVGL/src/core/lv_obj_event.d \
./LVGL/src/core/lv_obj_id_builtin.d \
./LVGL/src/core/lv_obj_pos.d \
./LVGL/src/core/lv_obj_property.d \
./LVGL/src/core/lv_obj_scroll.d \
./LVGL/src/core/lv_obj_style.d \
./LVGL/src/core/lv_obj_style_gen.d \
./LVGL/src/core/lv_obj_tree.d \
./LVGL/src/core/lv_refr.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/core/%.o LVGL/src/core/%.su LVGL/src/core/%.cyclo: ../LVGL/src/core/%.c LVGL/src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-core

clean-LVGL-2f-src-2f-core:
	-$(RM) ./LVGL/src/core/lv_group.cyclo ./LVGL/src/core/lv_group.d ./LVGL/src/core/lv_group.o ./LVGL/src/core/lv_group.su ./LVGL/src/core/lv_obj.cyclo ./LVGL/src/core/lv_obj.d ./LVGL/src/core/lv_obj.o ./LVGL/src/core/lv_obj.su ./LVGL/src/core/lv_obj_class.cyclo ./LVGL/src/core/lv_obj_class.d ./LVGL/src/core/lv_obj_class.o ./LVGL/src/core/lv_obj_class.su ./LVGL/src/core/lv_obj_draw.cyclo ./LVGL/src/core/lv_obj_draw.d ./LVGL/src/core/lv_obj_draw.o ./LVGL/src/core/lv_obj_draw.su ./LVGL/src/core/lv_obj_event.cyclo ./LVGL/src/core/lv_obj_event.d ./LVGL/src/core/lv_obj_event.o ./LVGL/src/core/lv_obj_event.su ./LVGL/src/core/lv_obj_id_builtin.cyclo ./LVGL/src/core/lv_obj_id_builtin.d ./LVGL/src/core/lv_obj_id_builtin.o ./LVGL/src/core/lv_obj_id_builtin.su ./LVGL/src/core/lv_obj_pos.cyclo ./LVGL/src/core/lv_obj_pos.d ./LVGL/src/core/lv_obj_pos.o ./LVGL/src/core/lv_obj_pos.su ./LVGL/src/core/lv_obj_property.cyclo ./LVGL/src/core/lv_obj_property.d ./LVGL/src/core/lv_obj_property.o ./LVGL/src/core/lv_obj_property.su ./LVGL/src/core/lv_obj_scroll.cyclo ./LVGL/src/core/lv_obj_scroll.d ./LVGL/src/core/lv_obj_scroll.o ./LVGL/src/core/lv_obj_scroll.su ./LVGL/src/core/lv_obj_style.cyclo ./LVGL/src/core/lv_obj_style.d ./LVGL/src/core/lv_obj_style.o ./LVGL/src/core/lv_obj_style.su ./LVGL/src/core/lv_obj_style_gen.cyclo ./LVGL/src/core/lv_obj_style_gen.d ./LVGL/src/core/lv_obj_style_gen.o ./LVGL/src/core/lv_obj_style_gen.su ./LVGL/src/core/lv_obj_tree.cyclo ./LVGL/src/core/lv_obj_tree.d ./LVGL/src/core/lv_obj_tree.o ./LVGL/src/core/lv_obj_tree.su ./LVGL/src/core/lv_refr.cyclo ./LVGL/src/core/lv_refr.d ./LVGL/src/core/lv_refr.o ./LVGL/src/core/lv_refr.su

.PHONY: clean-LVGL-2f-src-2f-core

