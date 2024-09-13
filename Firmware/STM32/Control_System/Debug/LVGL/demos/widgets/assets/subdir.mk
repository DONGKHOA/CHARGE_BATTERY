################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/demos/widgets/assets/img_clothes.c \
../LVGL/demos/widgets/assets/img_demo_widgets_avatar.c \
../LVGL/demos/widgets/assets/img_demo_widgets_needle.c \
../LVGL/demos/widgets/assets/img_lvgl_logo.c 

OBJS += \
./LVGL/demos/widgets/assets/img_clothes.o \
./LVGL/demos/widgets/assets/img_demo_widgets_avatar.o \
./LVGL/demos/widgets/assets/img_demo_widgets_needle.o \
./LVGL/demos/widgets/assets/img_lvgl_logo.o 

C_DEPS += \
./LVGL/demos/widgets/assets/img_clothes.d \
./LVGL/demos/widgets/assets/img_demo_widgets_avatar.d \
./LVGL/demos/widgets/assets/img_demo_widgets_needle.d \
./LVGL/demos/widgets/assets/img_lvgl_logo.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/demos/widgets/assets/%.o LVGL/demos/widgets/assets/%.su LVGL/demos/widgets/assets/%.cyclo: ../LVGL/demos/widgets/assets/%.c LVGL/demos/widgets/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-demos-2f-widgets-2f-assets

clean-LVGL-2f-demos-2f-widgets-2f-assets:
	-$(RM) ./LVGL/demos/widgets/assets/img_clothes.cyclo ./LVGL/demos/widgets/assets/img_clothes.d ./LVGL/demos/widgets/assets/img_clothes.o ./LVGL/demos/widgets/assets/img_clothes.su ./LVGL/demos/widgets/assets/img_demo_widgets_avatar.cyclo ./LVGL/demos/widgets/assets/img_demo_widgets_avatar.d ./LVGL/demos/widgets/assets/img_demo_widgets_avatar.o ./LVGL/demos/widgets/assets/img_demo_widgets_avatar.su ./LVGL/demos/widgets/assets/img_demo_widgets_needle.cyclo ./LVGL/demos/widgets/assets/img_demo_widgets_needle.d ./LVGL/demos/widgets/assets/img_demo_widgets_needle.o ./LVGL/demos/widgets/assets/img_demo_widgets_needle.su ./LVGL/demos/widgets/assets/img_lvgl_logo.cyclo ./LVGL/demos/widgets/assets/img_lvgl_logo.d ./LVGL/demos/widgets/assets/img_lvgl_logo.o ./LVGL/demos/widgets/assets/img_lvgl_logo.su

.PHONY: clean-LVGL-2f-demos-2f-widgets-2f-assets

