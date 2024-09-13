################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/stdlib/rtthread/lv_mem_core_rtthread.c \
../LVGL/src/stdlib/rtthread/lv_sprintf_rtthread.c \
../LVGL/src/stdlib/rtthread/lv_string_rtthread.c 

OBJS += \
./LVGL/src/stdlib/rtthread/lv_mem_core_rtthread.o \
./LVGL/src/stdlib/rtthread/lv_sprintf_rtthread.o \
./LVGL/src/stdlib/rtthread/lv_string_rtthread.o 

C_DEPS += \
./LVGL/src/stdlib/rtthread/lv_mem_core_rtthread.d \
./LVGL/src/stdlib/rtthread/lv_sprintf_rtthread.d \
./LVGL/src/stdlib/rtthread/lv_string_rtthread.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/stdlib/rtthread/%.o LVGL/src/stdlib/rtthread/%.su LVGL/src/stdlib/rtthread/%.cyclo: ../LVGL/src/stdlib/rtthread/%.c LVGL/src/stdlib/rtthread/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-stdlib-2f-rtthread

clean-LVGL-2f-src-2f-stdlib-2f-rtthread:
	-$(RM) ./LVGL/src/stdlib/rtthread/lv_mem_core_rtthread.cyclo ./LVGL/src/stdlib/rtthread/lv_mem_core_rtthread.d ./LVGL/src/stdlib/rtthread/lv_mem_core_rtthread.o ./LVGL/src/stdlib/rtthread/lv_mem_core_rtthread.su ./LVGL/src/stdlib/rtthread/lv_sprintf_rtthread.cyclo ./LVGL/src/stdlib/rtthread/lv_sprintf_rtthread.d ./LVGL/src/stdlib/rtthread/lv_sprintf_rtthread.o ./LVGL/src/stdlib/rtthread/lv_sprintf_rtthread.su ./LVGL/src/stdlib/rtthread/lv_string_rtthread.cyclo ./LVGL/src/stdlib/rtthread/lv_string_rtthread.d ./LVGL/src/stdlib/rtthread/lv_string_rtthread.o ./LVGL/src/stdlib/rtthread/lv_string_rtthread.su

.PHONY: clean-LVGL-2f-src-2f-stdlib-2f-rtthread

