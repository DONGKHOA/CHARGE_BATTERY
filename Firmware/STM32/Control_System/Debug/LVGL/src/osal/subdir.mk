################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/osal/lv_cmsis_rtos2.c \
../LVGL/src/osal/lv_freertos.c \
../LVGL/src/osal/lv_os_none.c \
../LVGL/src/osal/lv_pthread.c \
../LVGL/src/osal/lv_rtthread.c \
../LVGL/src/osal/lv_windows.c 

OBJS += \
./LVGL/src/osal/lv_cmsis_rtos2.o \
./LVGL/src/osal/lv_freertos.o \
./LVGL/src/osal/lv_os_none.o \
./LVGL/src/osal/lv_pthread.o \
./LVGL/src/osal/lv_rtthread.o \
./LVGL/src/osal/lv_windows.o 

C_DEPS += \
./LVGL/src/osal/lv_cmsis_rtos2.d \
./LVGL/src/osal/lv_freertos.d \
./LVGL/src/osal/lv_os_none.d \
./LVGL/src/osal/lv_pthread.d \
./LVGL/src/osal/lv_rtthread.d \
./LVGL/src/osal/lv_windows.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/osal/%.o LVGL/src/osal/%.su LVGL/src/osal/%.cyclo: ../LVGL/src/osal/%.c LVGL/src/osal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-osal

clean-LVGL-2f-src-2f-osal:
	-$(RM) ./LVGL/src/osal/lv_cmsis_rtos2.cyclo ./LVGL/src/osal/lv_cmsis_rtos2.d ./LVGL/src/osal/lv_cmsis_rtos2.o ./LVGL/src/osal/lv_cmsis_rtos2.su ./LVGL/src/osal/lv_freertos.cyclo ./LVGL/src/osal/lv_freertos.d ./LVGL/src/osal/lv_freertos.o ./LVGL/src/osal/lv_freertos.su ./LVGL/src/osal/lv_os_none.cyclo ./LVGL/src/osal/lv_os_none.d ./LVGL/src/osal/lv_os_none.o ./LVGL/src/osal/lv_os_none.su ./LVGL/src/osal/lv_pthread.cyclo ./LVGL/src/osal/lv_pthread.d ./LVGL/src/osal/lv_pthread.o ./LVGL/src/osal/lv_pthread.su ./LVGL/src/osal/lv_rtthread.cyclo ./LVGL/src/osal/lv_rtthread.d ./LVGL/src/osal/lv_rtthread.o ./LVGL/src/osal/lv_rtthread.su ./LVGL/src/osal/lv_windows.cyclo ./LVGL/src/osal/lv_windows.d ./LVGL/src/osal/lv_windows.o ./LVGL/src/osal/lv_windows.su

.PHONY: clean-LVGL-2f-src-2f-osal

