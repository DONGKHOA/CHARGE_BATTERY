################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_1.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_10.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_11.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_12.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_13.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_14.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_15.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_16.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_17.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_18.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_19.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_2.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_22.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_25.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_3.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_4.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_5.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_6.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_7.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_8.c \
../LVGL/demos/multilang/assets/avatars/img_multilang_avatar_9.c 

OBJS += \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_1.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_10.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_11.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_12.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_13.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_14.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_15.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_16.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_17.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_18.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_19.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_2.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_22.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_25.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_3.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_4.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_5.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_6.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_7.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_8.o \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_9.o 

C_DEPS += \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_1.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_10.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_11.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_12.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_13.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_14.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_15.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_16.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_17.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_18.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_19.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_2.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_22.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_25.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_3.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_4.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_5.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_6.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_7.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_8.d \
./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_9.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/demos/multilang/assets/avatars/%.o LVGL/demos/multilang/assets/avatars/%.su LVGL/demos/multilang/assets/avatars/%.cyclo: ../LVGL/demos/multilang/assets/avatars/%.c LVGL/demos/multilang/assets/avatars/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-demos-2f-multilang-2f-assets-2f-avatars

clean-LVGL-2f-demos-2f-multilang-2f-assets-2f-avatars:
	-$(RM) ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_1.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_1.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_1.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_1.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_10.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_10.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_10.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_10.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_11.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_11.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_11.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_11.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_12.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_12.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_12.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_12.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_13.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_13.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_13.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_13.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_14.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_14.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_14.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_14.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_15.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_15.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_15.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_15.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_16.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_16.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_16.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_16.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_17.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_17.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_17.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_17.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_18.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_18.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_18.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_18.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_19.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_19.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_19.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_19.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_2.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_2.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_2.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_2.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_22.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_22.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_22.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_22.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_25.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_25.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_25.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_25.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_3.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_3.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_3.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_3.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_4.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_4.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_4.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_4.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_5.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_5.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_5.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_5.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_6.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_6.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_6.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_6.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_7.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_7.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_7.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_7.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_8.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_8.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_8.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_8.su ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_9.cyclo ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_9.d ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_9.o ./LVGL/demos/multilang/assets/avatars/img_multilang_avatar_9.su

.PHONY: clean-LVGL-2f-demos-2f-multilang-2f-assets-2f-avatars

