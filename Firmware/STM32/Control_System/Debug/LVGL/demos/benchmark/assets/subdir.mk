################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/demos/benchmark/assets/img_benchmark_cogwheel_alpha256.c \
../LVGL/demos/benchmark/assets/img_benchmark_cogwheel_argb.c \
../LVGL/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.c \
../LVGL/demos/benchmark/assets/img_benchmark_cogwheel_rgb.c \
../LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.c \
../LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.c \
../LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.c 

OBJS += \
./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_alpha256.o \
./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_argb.o \
./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.o \
./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_rgb.o \
./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.o \
./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.o \
./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.o 

C_DEPS += \
./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_alpha256.d \
./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_argb.d \
./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.d \
./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_rgb.d \
./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.d \
./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.d \
./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/demos/benchmark/assets/%.o LVGL/demos/benchmark/assets/%.su LVGL/demos/benchmark/assets/%.cyclo: ../LVGL/demos/benchmark/assets/%.c LVGL/demos/benchmark/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-demos-2f-benchmark-2f-assets

clean-LVGL-2f-demos-2f-benchmark-2f-assets:
	-$(RM) ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_alpha256.cyclo ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_alpha256.d ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_alpha256.o ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_alpha256.su ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_argb.cyclo ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_argb.d ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_argb.o ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_argb.su ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.cyclo ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.d ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.o ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.su ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_rgb.cyclo ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_rgb.d ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_rgb.o ./LVGL/demos/benchmark/assets/img_benchmark_cogwheel_rgb.su ./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.cyclo ./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.d ./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.o ./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_12_compr_az.c.su ./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.cyclo ./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.d ./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.o ./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_16_compr_az.c.su ./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.cyclo ./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.d ./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.o ./LVGL/demos/benchmark/assets/lv_font_benchmark_montserrat_28_compr_az.c.su

.PHONY: clean-LVGL-2f-demos-2f-benchmark-2f-assets

