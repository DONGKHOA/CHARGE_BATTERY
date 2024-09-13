################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/misc/cache/_lv_cache_lru_rb.c \
../LVGL/src/misc/cache/lv_cache.c \
../LVGL/src/misc/cache/lv_cache_entry.c \
../LVGL/src/misc/cache/lv_image_cache.c 

OBJS += \
./LVGL/src/misc/cache/_lv_cache_lru_rb.o \
./LVGL/src/misc/cache/lv_cache.o \
./LVGL/src/misc/cache/lv_cache_entry.o \
./LVGL/src/misc/cache/lv_image_cache.o 

C_DEPS += \
./LVGL/src/misc/cache/_lv_cache_lru_rb.d \
./LVGL/src/misc/cache/lv_cache.d \
./LVGL/src/misc/cache/lv_cache_entry.d \
./LVGL/src/misc/cache/lv_image_cache.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/misc/cache/%.o LVGL/src/misc/cache/%.su LVGL/src/misc/cache/%.cyclo: ../LVGL/src/misc/cache/%.c LVGL/src/misc/cache/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-misc-2f-cache

clean-LVGL-2f-src-2f-misc-2f-cache:
	-$(RM) ./LVGL/src/misc/cache/_lv_cache_lru_rb.cyclo ./LVGL/src/misc/cache/_lv_cache_lru_rb.d ./LVGL/src/misc/cache/_lv_cache_lru_rb.o ./LVGL/src/misc/cache/_lv_cache_lru_rb.su ./LVGL/src/misc/cache/lv_cache.cyclo ./LVGL/src/misc/cache/lv_cache.d ./LVGL/src/misc/cache/lv_cache.o ./LVGL/src/misc/cache/lv_cache.su ./LVGL/src/misc/cache/lv_cache_entry.cyclo ./LVGL/src/misc/cache/lv_cache_entry.d ./LVGL/src/misc/cache/lv_cache_entry.o ./LVGL/src/misc/cache/lv_cache_entry.su ./LVGL/src/misc/cache/lv_image_cache.cyclo ./LVGL/src/misc/cache/lv_image_cache.d ./LVGL/src/misc/cache/lv_image_cache.o ./LVGL/src/misc/cache/lv_image_cache.su

.PHONY: clean-LVGL-2f-src-2f-misc-2f-cache

