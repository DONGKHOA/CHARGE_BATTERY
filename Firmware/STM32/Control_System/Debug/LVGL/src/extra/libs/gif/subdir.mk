################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/extra/libs/gif/gifdec.c \
../LVGL/src/extra/libs/gif/lv_gif.c 

OBJS += \
./LVGL/src/extra/libs/gif/gifdec.o \
./LVGL/src/extra/libs/gif/lv_gif.o 

C_DEPS += \
./LVGL/src/extra/libs/gif/gifdec.d \
./LVGL/src/extra/libs/gif/lv_gif.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/extra/libs/gif/%.o LVGL/src/extra/libs/gif/%.su LVGL/src/extra/libs/gif/%.cyclo: ../LVGL/src/extra/libs/gif/%.c LVGL/src/extra/libs/gif/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/App/CMDLine/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/BSP" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Devices" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Middleware/Ring_Buffer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-extra-2f-libs-2f-gif

clean-LVGL-2f-src-2f-extra-2f-libs-2f-gif:
	-$(RM) ./LVGL/src/extra/libs/gif/gifdec.cyclo ./LVGL/src/extra/libs/gif/gifdec.d ./LVGL/src/extra/libs/gif/gifdec.o ./LVGL/src/extra/libs/gif/gifdec.su ./LVGL/src/extra/libs/gif/lv_gif.cyclo ./LVGL/src/extra/libs/gif/lv_gif.d ./LVGL/src/extra/libs/gif/lv_gif.o ./LVGL/src/extra/libs/gif/lv_gif.su

.PHONY: clean-LVGL-2f-src-2f-extra-2f-libs-2f-gif

