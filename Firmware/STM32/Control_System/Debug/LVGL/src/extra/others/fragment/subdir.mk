################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/extra/others/fragment/lv_fragment.c \
../LVGL/src/extra/others/fragment/lv_fragment_manager.c 

OBJS += \
./LVGL/src/extra/others/fragment/lv_fragment.o \
./LVGL/src/extra/others/fragment/lv_fragment_manager.o 

C_DEPS += \
./LVGL/src/extra/others/fragment/lv_fragment.d \
./LVGL/src/extra/others/fragment/lv_fragment_manager.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/extra/others/fragment/%.o LVGL/src/extra/others/fragment/%.su LVGL/src/extra/others/fragment/%.cyclo: ../LVGL/src/extra/others/fragment/%.c LVGL/src/extra/others/fragment/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/App/CMDLine/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/BSP" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Devices" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-extra-2f-others-2f-fragment

clean-LVGL-2f-src-2f-extra-2f-others-2f-fragment:
	-$(RM) ./LVGL/src/extra/others/fragment/lv_fragment.cyclo ./LVGL/src/extra/others/fragment/lv_fragment.d ./LVGL/src/extra/others/fragment/lv_fragment.o ./LVGL/src/extra/others/fragment/lv_fragment.su ./LVGL/src/extra/others/fragment/lv_fragment_manager.cyclo ./LVGL/src/extra/others/fragment/lv_fragment_manager.d ./LVGL/src/extra/others/fragment/lv_fragment_manager.o ./LVGL/src/extra/others/fragment/lv_fragment_manager.su

.PHONY: clean-LVGL-2f-src-2f-extra-2f-others-2f-fragment

