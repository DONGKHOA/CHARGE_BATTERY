################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/libs/fsdrv/lv_fs_cbfs.c \
../LVGL/src/libs/fsdrv/lv_fs_fatfs.c \
../LVGL/src/libs/fsdrv/lv_fs_memfs.c \
../LVGL/src/libs/fsdrv/lv_fs_posix.c \
../LVGL/src/libs/fsdrv/lv_fs_stdio.c \
../LVGL/src/libs/fsdrv/lv_fs_win32.c 

OBJS += \
./LVGL/src/libs/fsdrv/lv_fs_cbfs.o \
./LVGL/src/libs/fsdrv/lv_fs_fatfs.o \
./LVGL/src/libs/fsdrv/lv_fs_memfs.o \
./LVGL/src/libs/fsdrv/lv_fs_posix.o \
./LVGL/src/libs/fsdrv/lv_fs_stdio.o \
./LVGL/src/libs/fsdrv/lv_fs_win32.o 

C_DEPS += \
./LVGL/src/libs/fsdrv/lv_fs_cbfs.d \
./LVGL/src/libs/fsdrv/lv_fs_fatfs.d \
./LVGL/src/libs/fsdrv/lv_fs_memfs.d \
./LVGL/src/libs/fsdrv/lv_fs_posix.d \
./LVGL/src/libs/fsdrv/lv_fs_stdio.d \
./LVGL/src/libs/fsdrv/lv_fs_win32.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/libs/fsdrv/%.o LVGL/src/libs/fsdrv/%.su LVGL/src/libs/fsdrv/%.cyclo: ../LVGL/src/libs/fsdrv/%.c LVGL/src/libs/fsdrv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-libs-2f-fsdrv

clean-LVGL-2f-src-2f-libs-2f-fsdrv:
	-$(RM) ./LVGL/src/libs/fsdrv/lv_fs_cbfs.cyclo ./LVGL/src/libs/fsdrv/lv_fs_cbfs.d ./LVGL/src/libs/fsdrv/lv_fs_cbfs.o ./LVGL/src/libs/fsdrv/lv_fs_cbfs.su ./LVGL/src/libs/fsdrv/lv_fs_fatfs.cyclo ./LVGL/src/libs/fsdrv/lv_fs_fatfs.d ./LVGL/src/libs/fsdrv/lv_fs_fatfs.o ./LVGL/src/libs/fsdrv/lv_fs_fatfs.su ./LVGL/src/libs/fsdrv/lv_fs_memfs.cyclo ./LVGL/src/libs/fsdrv/lv_fs_memfs.d ./LVGL/src/libs/fsdrv/lv_fs_memfs.o ./LVGL/src/libs/fsdrv/lv_fs_memfs.su ./LVGL/src/libs/fsdrv/lv_fs_posix.cyclo ./LVGL/src/libs/fsdrv/lv_fs_posix.d ./LVGL/src/libs/fsdrv/lv_fs_posix.o ./LVGL/src/libs/fsdrv/lv_fs_posix.su ./LVGL/src/libs/fsdrv/lv_fs_stdio.cyclo ./LVGL/src/libs/fsdrv/lv_fs_stdio.d ./LVGL/src/libs/fsdrv/lv_fs_stdio.o ./LVGL/src/libs/fsdrv/lv_fs_stdio.su ./LVGL/src/libs/fsdrv/lv_fs_win32.cyclo ./LVGL/src/libs/fsdrv/lv_fs_win32.d ./LVGL/src/libs/fsdrv/lv_fs_win32.o ./LVGL/src/libs/fsdrv/lv_fs_win32.su

.PHONY: clean-LVGL-2f-src-2f-libs-2f-fsdrv

