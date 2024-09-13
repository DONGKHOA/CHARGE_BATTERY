################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/demos/music/lv_demo_music.c \
../LVGL/demos/music/lv_demo_music_list.c \
../LVGL/demos/music/lv_demo_music_main.c 

OBJS += \
./LVGL/demos/music/lv_demo_music.o \
./LVGL/demos/music/lv_demo_music_list.o \
./LVGL/demos/music/lv_demo_music_main.o 

C_DEPS += \
./LVGL/demos/music/lv_demo_music.d \
./LVGL/demos/music/lv_demo_music_list.d \
./LVGL/demos/music/lv_demo_music_main.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/demos/music/%.o LVGL/demos/music/%.su LVGL/demos/music/%.cyclo: ../LVGL/demos/music/%.c LVGL/demos/music/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-demos-2f-music

clean-LVGL-2f-demos-2f-music:
	-$(RM) ./LVGL/demos/music/lv_demo_music.cyclo ./LVGL/demos/music/lv_demo_music.d ./LVGL/demos/music/lv_demo_music.o ./LVGL/demos/music/lv_demo_music.su ./LVGL/demos/music/lv_demo_music_list.cyclo ./LVGL/demos/music/lv_demo_music_list.d ./LVGL/demos/music/lv_demo_music_list.o ./LVGL/demos/music/lv_demo_music_list.su ./LVGL/demos/music/lv_demo_music_main.cyclo ./LVGL/demos/music/lv_demo_music_main.d ./LVGL/demos/music/lv_demo_music_main.o ./LVGL/demos/music/lv_demo_music_main.su

.PHONY: clean-LVGL-2f-demos-2f-music

