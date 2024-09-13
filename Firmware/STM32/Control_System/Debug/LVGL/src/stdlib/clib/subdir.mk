################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/stdlib/clib/lv_mem_core_clib.c \
../LVGL/src/stdlib/clib/lv_sprintf_clib.c \
../LVGL/src/stdlib/clib/lv_string_clib.c 

OBJS += \
./LVGL/src/stdlib/clib/lv_mem_core_clib.o \
./LVGL/src/stdlib/clib/lv_sprintf_clib.o \
./LVGL/src/stdlib/clib/lv_string_clib.o 

C_DEPS += \
./LVGL/src/stdlib/clib/lv_mem_core_clib.d \
./LVGL/src/stdlib/clib/lv_sprintf_clib.d \
./LVGL/src/stdlib/clib/lv_string_clib.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/stdlib/clib/%.o LVGL/src/stdlib/clib/%.su LVGL/src/stdlib/clib/%.cyclo: ../LVGL/src/stdlib/clib/%.c LVGL/src/stdlib/clib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-stdlib-2f-clib

clean-LVGL-2f-src-2f-stdlib-2f-clib:
	-$(RM) ./LVGL/src/stdlib/clib/lv_mem_core_clib.cyclo ./LVGL/src/stdlib/clib/lv_mem_core_clib.d ./LVGL/src/stdlib/clib/lv_mem_core_clib.o ./LVGL/src/stdlib/clib/lv_mem_core_clib.su ./LVGL/src/stdlib/clib/lv_sprintf_clib.cyclo ./LVGL/src/stdlib/clib/lv_sprintf_clib.d ./LVGL/src/stdlib/clib/lv_sprintf_clib.o ./LVGL/src/stdlib/clib/lv_sprintf_clib.su ./LVGL/src/stdlib/clib/lv_string_clib.cyclo ./LVGL/src/stdlib/clib/lv_string_clib.d ./LVGL/src/stdlib/clib/lv_string_clib.o ./LVGL/src/stdlib/clib/lv_string_clib.su

.PHONY: clean-LVGL-2f-src-2f-stdlib-2f-clib

