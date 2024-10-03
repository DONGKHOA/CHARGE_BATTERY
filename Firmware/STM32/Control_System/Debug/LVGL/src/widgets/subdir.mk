################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/widgets/lv_arc.c \
../LVGL/src/widgets/lv_bar.c \
../LVGL/src/widgets/lv_btn.c \
../LVGL/src/widgets/lv_btnmatrix.c \
../LVGL/src/widgets/lv_canvas.c \
../LVGL/src/widgets/lv_checkbox.c \
../LVGL/src/widgets/lv_dropdown.c \
../LVGL/src/widgets/lv_img.c \
../LVGL/src/widgets/lv_label.c \
../LVGL/src/widgets/lv_line.c \
../LVGL/src/widgets/lv_objx_templ.c \
../LVGL/src/widgets/lv_roller.c \
../LVGL/src/widgets/lv_slider.c \
../LVGL/src/widgets/lv_switch.c \
../LVGL/src/widgets/lv_table.c \
../LVGL/src/widgets/lv_textarea.c 

OBJS += \
./LVGL/src/widgets/lv_arc.o \
./LVGL/src/widgets/lv_bar.o \
./LVGL/src/widgets/lv_btn.o \
./LVGL/src/widgets/lv_btnmatrix.o \
./LVGL/src/widgets/lv_canvas.o \
./LVGL/src/widgets/lv_checkbox.o \
./LVGL/src/widgets/lv_dropdown.o \
./LVGL/src/widgets/lv_img.o \
./LVGL/src/widgets/lv_label.o \
./LVGL/src/widgets/lv_line.o \
./LVGL/src/widgets/lv_objx_templ.o \
./LVGL/src/widgets/lv_roller.o \
./LVGL/src/widgets/lv_slider.o \
./LVGL/src/widgets/lv_switch.o \
./LVGL/src/widgets/lv_table.o \
./LVGL/src/widgets/lv_textarea.o 

C_DEPS += \
./LVGL/src/widgets/lv_arc.d \
./LVGL/src/widgets/lv_bar.d \
./LVGL/src/widgets/lv_btn.d \
./LVGL/src/widgets/lv_btnmatrix.d \
./LVGL/src/widgets/lv_canvas.d \
./LVGL/src/widgets/lv_checkbox.d \
./LVGL/src/widgets/lv_dropdown.d \
./LVGL/src/widgets/lv_img.d \
./LVGL/src/widgets/lv_label.d \
./LVGL/src/widgets/lv_line.d \
./LVGL/src/widgets/lv_objx_templ.d \
./LVGL/src/widgets/lv_roller.d \
./LVGL/src/widgets/lv_slider.d \
./LVGL/src/widgets/lv_switch.d \
./LVGL/src/widgets/lv_table.d \
./LVGL/src/widgets/lv_textarea.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/widgets/%.o LVGL/src/widgets/%.su LVGL/src/widgets/%.cyclo: ../LVGL/src/widgets/%.c LVGL/src/widgets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/App/CMDLine/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/BSP" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Devices" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Middleware/Ring_Buffer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-widgets

clean-LVGL-2f-src-2f-widgets:
	-$(RM) ./LVGL/src/widgets/lv_arc.cyclo ./LVGL/src/widgets/lv_arc.d ./LVGL/src/widgets/lv_arc.o ./LVGL/src/widgets/lv_arc.su ./LVGL/src/widgets/lv_bar.cyclo ./LVGL/src/widgets/lv_bar.d ./LVGL/src/widgets/lv_bar.o ./LVGL/src/widgets/lv_bar.su ./LVGL/src/widgets/lv_btn.cyclo ./LVGL/src/widgets/lv_btn.d ./LVGL/src/widgets/lv_btn.o ./LVGL/src/widgets/lv_btn.su ./LVGL/src/widgets/lv_btnmatrix.cyclo ./LVGL/src/widgets/lv_btnmatrix.d ./LVGL/src/widgets/lv_btnmatrix.o ./LVGL/src/widgets/lv_btnmatrix.su ./LVGL/src/widgets/lv_canvas.cyclo ./LVGL/src/widgets/lv_canvas.d ./LVGL/src/widgets/lv_canvas.o ./LVGL/src/widgets/lv_canvas.su ./LVGL/src/widgets/lv_checkbox.cyclo ./LVGL/src/widgets/lv_checkbox.d ./LVGL/src/widgets/lv_checkbox.o ./LVGL/src/widgets/lv_checkbox.su ./LVGL/src/widgets/lv_dropdown.cyclo ./LVGL/src/widgets/lv_dropdown.d ./LVGL/src/widgets/lv_dropdown.o ./LVGL/src/widgets/lv_dropdown.su ./LVGL/src/widgets/lv_img.cyclo ./LVGL/src/widgets/lv_img.d ./LVGL/src/widgets/lv_img.o ./LVGL/src/widgets/lv_img.su ./LVGL/src/widgets/lv_label.cyclo ./LVGL/src/widgets/lv_label.d ./LVGL/src/widgets/lv_label.o ./LVGL/src/widgets/lv_label.su ./LVGL/src/widgets/lv_line.cyclo ./LVGL/src/widgets/lv_line.d ./LVGL/src/widgets/lv_line.o ./LVGL/src/widgets/lv_line.su ./LVGL/src/widgets/lv_objx_templ.cyclo ./LVGL/src/widgets/lv_objx_templ.d ./LVGL/src/widgets/lv_objx_templ.o ./LVGL/src/widgets/lv_objx_templ.su ./LVGL/src/widgets/lv_roller.cyclo ./LVGL/src/widgets/lv_roller.d ./LVGL/src/widgets/lv_roller.o ./LVGL/src/widgets/lv_roller.su ./LVGL/src/widgets/lv_slider.cyclo ./LVGL/src/widgets/lv_slider.d ./LVGL/src/widgets/lv_slider.o ./LVGL/src/widgets/lv_slider.su ./LVGL/src/widgets/lv_switch.cyclo ./LVGL/src/widgets/lv_switch.d ./LVGL/src/widgets/lv_switch.o ./LVGL/src/widgets/lv_switch.su ./LVGL/src/widgets/lv_table.cyclo ./LVGL/src/widgets/lv_table.d ./LVGL/src/widgets/lv_table.o ./LVGL/src/widgets/lv_table.su ./LVGL/src/widgets/lv_textarea.cyclo ./LVGL/src/widgets/lv_textarea.d ./LVGL/src/widgets/lv_textarea.o ./LVGL/src/widgets/lv_textarea.su

.PHONY: clean-LVGL-2f-src-2f-widgets

