################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/examples/widgets/arc/lv_example_arc_1.c \
../LVGL/examples/widgets/arc/lv_example_arc_2.c 

OBJS += \
./LVGL/examples/widgets/arc/lv_example_arc_1.o \
./LVGL/examples/widgets/arc/lv_example_arc_2.o 

C_DEPS += \
./LVGL/examples/widgets/arc/lv_example_arc_1.d \
./LVGL/examples/widgets/arc/lv_example_arc_2.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/examples/widgets/arc/%.o LVGL/examples/widgets/arc/%.su LVGL/examples/widgets/arc/%.cyclo: ../LVGL/examples/widgets/arc/%.c LVGL/examples/widgets/arc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-examples-2f-widgets-2f-arc

clean-LVGL-2f-examples-2f-widgets-2f-arc:
	-$(RM) ./LVGL/examples/widgets/arc/lv_example_arc_1.cyclo ./LVGL/examples/widgets/arc/lv_example_arc_1.d ./LVGL/examples/widgets/arc/lv_example_arc_1.o ./LVGL/examples/widgets/arc/lv_example_arc_1.su ./LVGL/examples/widgets/arc/lv_example_arc_2.cyclo ./LVGL/examples/widgets/arc/lv_example_arc_2.d ./LVGL/examples/widgets/arc/lv_example_arc_2.o ./LVGL/examples/widgets/arc/lv_example_arc_2.su

.PHONY: clean-LVGL-2f-examples-2f-widgets-2f-arc

