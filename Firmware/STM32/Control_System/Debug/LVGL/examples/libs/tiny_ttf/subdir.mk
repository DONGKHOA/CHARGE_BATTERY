################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_1.c \
../LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_2.c \
../LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_3.c \
../LVGL/examples/libs/tiny_ttf/ubuntu_font.c 

OBJS += \
./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_1.o \
./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_2.o \
./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_3.o \
./LVGL/examples/libs/tiny_ttf/ubuntu_font.o 

C_DEPS += \
./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_1.d \
./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_2.d \
./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_3.d \
./LVGL/examples/libs/tiny_ttf/ubuntu_font.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/examples/libs/tiny_ttf/%.o LVGL/examples/libs/tiny_ttf/%.su LVGL/examples/libs/tiny_ttf/%.cyclo: ../LVGL/examples/libs/tiny_ttf/%.c LVGL/examples/libs/tiny_ttf/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-examples-2f-libs-2f-tiny_ttf

clean-LVGL-2f-examples-2f-libs-2f-tiny_ttf:
	-$(RM) ./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_1.cyclo ./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_1.d ./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_1.o ./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_1.su ./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_2.cyclo ./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_2.d ./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_2.o ./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_2.su ./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_3.cyclo ./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_3.d ./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_3.o ./LVGL/examples/libs/tiny_ttf/lv_example_tiny_ttf_3.su ./LVGL/examples/libs/tiny_ttf/ubuntu_font.cyclo ./LVGL/examples/libs/tiny_ttf/ubuntu_font.d ./LVGL/examples/libs/tiny_ttf/ubuntu_font.o ./LVGL/examples/libs/tiny_ttf/ubuntu_font.su

.PHONY: clean-LVGL-2f-examples-2f-libs-2f-tiny_ttf

