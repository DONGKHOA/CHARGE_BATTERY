################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.c \
../LVGL/demos/flex_layout/lv_demo_flex_layout_flex_loader.c \
../LVGL/demos/flex_layout/lv_demo_flex_layout_main.c \
../LVGL/demos/flex_layout/lv_demo_flex_layout_view.c \
../LVGL/demos/flex_layout/lv_demo_flex_layout_view_child_node.c \
../LVGL/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.c 

OBJS += \
./LVGL/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.o \
./LVGL/demos/flex_layout/lv_demo_flex_layout_flex_loader.o \
./LVGL/demos/flex_layout/lv_demo_flex_layout_main.o \
./LVGL/demos/flex_layout/lv_demo_flex_layout_view.o \
./LVGL/demos/flex_layout/lv_demo_flex_layout_view_child_node.o \
./LVGL/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.o 

C_DEPS += \
./LVGL/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.d \
./LVGL/demos/flex_layout/lv_demo_flex_layout_flex_loader.d \
./LVGL/demos/flex_layout/lv_demo_flex_layout_main.d \
./LVGL/demos/flex_layout/lv_demo_flex_layout_view.d \
./LVGL/demos/flex_layout/lv_demo_flex_layout_view_child_node.d \
./LVGL/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/demos/flex_layout/%.o LVGL/demos/flex_layout/%.su LVGL/demos/flex_layout/%.cyclo: ../LVGL/demos/flex_layout/%.c LVGL/demos/flex_layout/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-demos-2f-flex_layout

clean-LVGL-2f-demos-2f-flex_layout:
	-$(RM) ./LVGL/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.cyclo ./LVGL/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.d ./LVGL/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.o ./LVGL/demos/flex_layout/lv_demo_flex_layout_ctrl_pad.su ./LVGL/demos/flex_layout/lv_demo_flex_layout_flex_loader.cyclo ./LVGL/demos/flex_layout/lv_demo_flex_layout_flex_loader.d ./LVGL/demos/flex_layout/lv_demo_flex_layout_flex_loader.o ./LVGL/demos/flex_layout/lv_demo_flex_layout_flex_loader.su ./LVGL/demos/flex_layout/lv_demo_flex_layout_main.cyclo ./LVGL/demos/flex_layout/lv_demo_flex_layout_main.d ./LVGL/demos/flex_layout/lv_demo_flex_layout_main.o ./LVGL/demos/flex_layout/lv_demo_flex_layout_main.su ./LVGL/demos/flex_layout/lv_demo_flex_layout_view.cyclo ./LVGL/demos/flex_layout/lv_demo_flex_layout_view.d ./LVGL/demos/flex_layout/lv_demo_flex_layout_view.o ./LVGL/demos/flex_layout/lv_demo_flex_layout_view.su ./LVGL/demos/flex_layout/lv_demo_flex_layout_view_child_node.cyclo ./LVGL/demos/flex_layout/lv_demo_flex_layout_view_child_node.d ./LVGL/demos/flex_layout/lv_demo_flex_layout_view_child_node.o ./LVGL/demos/flex_layout/lv_demo_flex_layout_view_child_node.su ./LVGL/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.cyclo ./LVGL/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.d ./LVGL/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.o ./LVGL/demos/flex_layout/lv_demo_flex_layout_view_ctrl_pad.su

.PHONY: clean-LVGL-2f-demos-2f-flex_layout

