################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/examples/get_started/lv_example_get_started_1.c \
../LVGL/examples/get_started/lv_example_get_started_2.c \
../LVGL/examples/get_started/lv_example_get_started_3.c \
../LVGL/examples/get_started/lv_example_get_started_4.c 

OBJS += \
./LVGL/examples/get_started/lv_example_get_started_1.o \
./LVGL/examples/get_started/lv_example_get_started_2.o \
./LVGL/examples/get_started/lv_example_get_started_3.o \
./LVGL/examples/get_started/lv_example_get_started_4.o 

C_DEPS += \
./LVGL/examples/get_started/lv_example_get_started_1.d \
./LVGL/examples/get_started/lv_example_get_started_2.d \
./LVGL/examples/get_started/lv_example_get_started_3.d \
./LVGL/examples/get_started/lv_example_get_started_4.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/examples/get_started/%.o LVGL/examples/get_started/%.su LVGL/examples/get_started/%.cyclo: ../LVGL/examples/get_started/%.c LVGL/examples/get_started/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-examples-2f-get_started

clean-LVGL-2f-examples-2f-get_started:
	-$(RM) ./LVGL/examples/get_started/lv_example_get_started_1.cyclo ./LVGL/examples/get_started/lv_example_get_started_1.d ./LVGL/examples/get_started/lv_example_get_started_1.o ./LVGL/examples/get_started/lv_example_get_started_1.su ./LVGL/examples/get_started/lv_example_get_started_2.cyclo ./LVGL/examples/get_started/lv_example_get_started_2.d ./LVGL/examples/get_started/lv_example_get_started_2.o ./LVGL/examples/get_started/lv_example_get_started_2.su ./LVGL/examples/get_started/lv_example_get_started_3.cyclo ./LVGL/examples/get_started/lv_example_get_started_3.d ./LVGL/examples/get_started/lv_example_get_started_3.o ./LVGL/examples/get_started/lv_example_get_started_3.su ./LVGL/examples/get_started/lv_example_get_started_4.cyclo ./LVGL/examples/get_started/lv_example_get_started_4.d ./LVGL/examples/get_started/lv_example_get_started_4.o ./LVGL/examples/get_started/lv_example_get_started_4.su

.PHONY: clean-LVGL-2f-examples-2f-get_started

