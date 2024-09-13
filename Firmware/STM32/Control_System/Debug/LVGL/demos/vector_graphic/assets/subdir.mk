################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/demos/vector_graphic/assets/img_demo_vector_avatar.c 

OBJS += \
./LVGL/demos/vector_graphic/assets/img_demo_vector_avatar.o 

C_DEPS += \
./LVGL/demos/vector_graphic/assets/img_demo_vector_avatar.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/demos/vector_graphic/assets/%.o LVGL/demos/vector_graphic/assets/%.su LVGL/demos/vector_graphic/assets/%.cyclo: ../LVGL/demos/vector_graphic/assets/%.c LVGL/demos/vector_graphic/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-demos-2f-vector_graphic-2f-assets

clean-LVGL-2f-demos-2f-vector_graphic-2f-assets:
	-$(RM) ./LVGL/demos/vector_graphic/assets/img_demo_vector_avatar.cyclo ./LVGL/demos/vector_graphic/assets/img_demo_vector_avatar.d ./LVGL/demos/vector_graphic/assets/img_demo_vector_avatar.o ./LVGL/demos/vector_graphic/assets/img_demo_vector_avatar.su

.PHONY: clean-LVGL-2f-demos-2f-vector_graphic-2f-assets

