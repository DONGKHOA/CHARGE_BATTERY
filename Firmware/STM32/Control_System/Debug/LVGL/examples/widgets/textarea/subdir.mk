################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/examples/widgets/textarea/lv_example_textarea_1.c \
../LVGL/examples/widgets/textarea/lv_example_textarea_2.c \
../LVGL/examples/widgets/textarea/lv_example_textarea_3.c 

OBJS += \
./LVGL/examples/widgets/textarea/lv_example_textarea_1.o \
./LVGL/examples/widgets/textarea/lv_example_textarea_2.o \
./LVGL/examples/widgets/textarea/lv_example_textarea_3.o 

C_DEPS += \
./LVGL/examples/widgets/textarea/lv_example_textarea_1.d \
./LVGL/examples/widgets/textarea/lv_example_textarea_2.d \
./LVGL/examples/widgets/textarea/lv_example_textarea_3.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/examples/widgets/textarea/%.o LVGL/examples/widgets/textarea/%.su LVGL/examples/widgets/textarea/%.cyclo: ../LVGL/examples/widgets/textarea/%.c LVGL/examples/widgets/textarea/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-examples-2f-widgets-2f-textarea

clean-LVGL-2f-examples-2f-widgets-2f-textarea:
	-$(RM) ./LVGL/examples/widgets/textarea/lv_example_textarea_1.cyclo ./LVGL/examples/widgets/textarea/lv_example_textarea_1.d ./LVGL/examples/widgets/textarea/lv_example_textarea_1.o ./LVGL/examples/widgets/textarea/lv_example_textarea_1.su ./LVGL/examples/widgets/textarea/lv_example_textarea_2.cyclo ./LVGL/examples/widgets/textarea/lv_example_textarea_2.d ./LVGL/examples/widgets/textarea/lv_example_textarea_2.o ./LVGL/examples/widgets/textarea/lv_example_textarea_2.su ./LVGL/examples/widgets/textarea/lv_example_textarea_3.cyclo ./LVGL/examples/widgets/textarea/lv_example_textarea_3.d ./LVGL/examples/widgets/textarea/lv_example_textarea_3.o ./LVGL/examples/widgets/textarea/lv_example_textarea_3.su

.PHONY: clean-LVGL-2f-examples-2f-widgets-2f-textarea

