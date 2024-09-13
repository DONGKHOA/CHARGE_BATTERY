################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/drivers/sdl/lv_sdl_keyboard.c \
../LVGL/src/drivers/sdl/lv_sdl_mouse.c \
../LVGL/src/drivers/sdl/lv_sdl_mousewheel.c \
../LVGL/src/drivers/sdl/lv_sdl_window.c 

OBJS += \
./LVGL/src/drivers/sdl/lv_sdl_keyboard.o \
./LVGL/src/drivers/sdl/lv_sdl_mouse.o \
./LVGL/src/drivers/sdl/lv_sdl_mousewheel.o \
./LVGL/src/drivers/sdl/lv_sdl_window.o 

C_DEPS += \
./LVGL/src/drivers/sdl/lv_sdl_keyboard.d \
./LVGL/src/drivers/sdl/lv_sdl_mouse.d \
./LVGL/src/drivers/sdl/lv_sdl_mousewheel.d \
./LVGL/src/drivers/sdl/lv_sdl_window.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/drivers/sdl/%.o LVGL/src/drivers/sdl/%.su LVGL/src/drivers/sdl/%.cyclo: ../LVGL/src/drivers/sdl/%.c LVGL/src/drivers/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-drivers-2f-sdl

clean-LVGL-2f-src-2f-drivers-2f-sdl:
	-$(RM) ./LVGL/src/drivers/sdl/lv_sdl_keyboard.cyclo ./LVGL/src/drivers/sdl/lv_sdl_keyboard.d ./LVGL/src/drivers/sdl/lv_sdl_keyboard.o ./LVGL/src/drivers/sdl/lv_sdl_keyboard.su ./LVGL/src/drivers/sdl/lv_sdl_mouse.cyclo ./LVGL/src/drivers/sdl/lv_sdl_mouse.d ./LVGL/src/drivers/sdl/lv_sdl_mouse.o ./LVGL/src/drivers/sdl/lv_sdl_mouse.su ./LVGL/src/drivers/sdl/lv_sdl_mousewheel.cyclo ./LVGL/src/drivers/sdl/lv_sdl_mousewheel.d ./LVGL/src/drivers/sdl/lv_sdl_mousewheel.o ./LVGL/src/drivers/sdl/lv_sdl_mousewheel.su ./LVGL/src/drivers/sdl/lv_sdl_window.cyclo ./LVGL/src/drivers/sdl/lv_sdl_window.d ./LVGL/src/drivers/sdl/lv_sdl_window.o ./LVGL/src/drivers/sdl/lv_sdl_window.su

.PHONY: clean-LVGL-2f-src-2f-drivers-2f-sdl

