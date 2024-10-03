################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/misc/lv_anim.c \
../LVGL/src/misc/lv_anim_timeline.c \
../LVGL/src/misc/lv_area.c \
../LVGL/src/misc/lv_async.c \
../LVGL/src/misc/lv_bidi.c \
../LVGL/src/misc/lv_color.c \
../LVGL/src/misc/lv_fs.c \
../LVGL/src/misc/lv_gc.c \
../LVGL/src/misc/lv_ll.c \
../LVGL/src/misc/lv_log.c \
../LVGL/src/misc/lv_lru.c \
../LVGL/src/misc/lv_math.c \
../LVGL/src/misc/lv_mem.c \
../LVGL/src/misc/lv_printf.c \
../LVGL/src/misc/lv_style.c \
../LVGL/src/misc/lv_style_gen.c \
../LVGL/src/misc/lv_templ.c \
../LVGL/src/misc/lv_timer.c \
../LVGL/src/misc/lv_tlsf.c \
../LVGL/src/misc/lv_txt.c \
../LVGL/src/misc/lv_txt_ap.c \
../LVGL/src/misc/lv_utils.c 

OBJS += \
./LVGL/src/misc/lv_anim.o \
./LVGL/src/misc/lv_anim_timeline.o \
./LVGL/src/misc/lv_area.o \
./LVGL/src/misc/lv_async.o \
./LVGL/src/misc/lv_bidi.o \
./LVGL/src/misc/lv_color.o \
./LVGL/src/misc/lv_fs.o \
./LVGL/src/misc/lv_gc.o \
./LVGL/src/misc/lv_ll.o \
./LVGL/src/misc/lv_log.o \
./LVGL/src/misc/lv_lru.o \
./LVGL/src/misc/lv_math.o \
./LVGL/src/misc/lv_mem.o \
./LVGL/src/misc/lv_printf.o \
./LVGL/src/misc/lv_style.o \
./LVGL/src/misc/lv_style_gen.o \
./LVGL/src/misc/lv_templ.o \
./LVGL/src/misc/lv_timer.o \
./LVGL/src/misc/lv_tlsf.o \
./LVGL/src/misc/lv_txt.o \
./LVGL/src/misc/lv_txt_ap.o \
./LVGL/src/misc/lv_utils.o 

C_DEPS += \
./LVGL/src/misc/lv_anim.d \
./LVGL/src/misc/lv_anim_timeline.d \
./LVGL/src/misc/lv_area.d \
./LVGL/src/misc/lv_async.d \
./LVGL/src/misc/lv_bidi.d \
./LVGL/src/misc/lv_color.d \
./LVGL/src/misc/lv_fs.d \
./LVGL/src/misc/lv_gc.d \
./LVGL/src/misc/lv_ll.d \
./LVGL/src/misc/lv_log.d \
./LVGL/src/misc/lv_lru.d \
./LVGL/src/misc/lv_math.d \
./LVGL/src/misc/lv_mem.d \
./LVGL/src/misc/lv_printf.d \
./LVGL/src/misc/lv_style.d \
./LVGL/src/misc/lv_style_gen.d \
./LVGL/src/misc/lv_templ.d \
./LVGL/src/misc/lv_timer.d \
./LVGL/src/misc/lv_tlsf.d \
./LVGL/src/misc/lv_txt.d \
./LVGL/src/misc/lv_txt_ap.d \
./LVGL/src/misc/lv_utils.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/misc/%.o LVGL/src/misc/%.su LVGL/src/misc/%.cyclo: ../LVGL/src/misc/%.c LVGL/src/misc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/App/CMDLine/Include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/BSP" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Devices" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/Middleware/Ring_Buffer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-src-2f-misc

clean-LVGL-2f-src-2f-misc:
	-$(RM) ./LVGL/src/misc/lv_anim.cyclo ./LVGL/src/misc/lv_anim.d ./LVGL/src/misc/lv_anim.o ./LVGL/src/misc/lv_anim.su ./LVGL/src/misc/lv_anim_timeline.cyclo ./LVGL/src/misc/lv_anim_timeline.d ./LVGL/src/misc/lv_anim_timeline.o ./LVGL/src/misc/lv_anim_timeline.su ./LVGL/src/misc/lv_area.cyclo ./LVGL/src/misc/lv_area.d ./LVGL/src/misc/lv_area.o ./LVGL/src/misc/lv_area.su ./LVGL/src/misc/lv_async.cyclo ./LVGL/src/misc/lv_async.d ./LVGL/src/misc/lv_async.o ./LVGL/src/misc/lv_async.su ./LVGL/src/misc/lv_bidi.cyclo ./LVGL/src/misc/lv_bidi.d ./LVGL/src/misc/lv_bidi.o ./LVGL/src/misc/lv_bidi.su ./LVGL/src/misc/lv_color.cyclo ./LVGL/src/misc/lv_color.d ./LVGL/src/misc/lv_color.o ./LVGL/src/misc/lv_color.su ./LVGL/src/misc/lv_fs.cyclo ./LVGL/src/misc/lv_fs.d ./LVGL/src/misc/lv_fs.o ./LVGL/src/misc/lv_fs.su ./LVGL/src/misc/lv_gc.cyclo ./LVGL/src/misc/lv_gc.d ./LVGL/src/misc/lv_gc.o ./LVGL/src/misc/lv_gc.su ./LVGL/src/misc/lv_ll.cyclo ./LVGL/src/misc/lv_ll.d ./LVGL/src/misc/lv_ll.o ./LVGL/src/misc/lv_ll.su ./LVGL/src/misc/lv_log.cyclo ./LVGL/src/misc/lv_log.d ./LVGL/src/misc/lv_log.o ./LVGL/src/misc/lv_log.su ./LVGL/src/misc/lv_lru.cyclo ./LVGL/src/misc/lv_lru.d ./LVGL/src/misc/lv_lru.o ./LVGL/src/misc/lv_lru.su ./LVGL/src/misc/lv_math.cyclo ./LVGL/src/misc/lv_math.d ./LVGL/src/misc/lv_math.o ./LVGL/src/misc/lv_math.su ./LVGL/src/misc/lv_mem.cyclo ./LVGL/src/misc/lv_mem.d ./LVGL/src/misc/lv_mem.o ./LVGL/src/misc/lv_mem.su ./LVGL/src/misc/lv_printf.cyclo ./LVGL/src/misc/lv_printf.d ./LVGL/src/misc/lv_printf.o ./LVGL/src/misc/lv_printf.su ./LVGL/src/misc/lv_style.cyclo ./LVGL/src/misc/lv_style.d ./LVGL/src/misc/lv_style.o ./LVGL/src/misc/lv_style.su ./LVGL/src/misc/lv_style_gen.cyclo ./LVGL/src/misc/lv_style_gen.d ./LVGL/src/misc/lv_style_gen.o ./LVGL/src/misc/lv_style_gen.su ./LVGL/src/misc/lv_templ.cyclo ./LVGL/src/misc/lv_templ.d ./LVGL/src/misc/lv_templ.o ./LVGL/src/misc/lv_templ.su ./LVGL/src/misc/lv_timer.cyclo ./LVGL/src/misc/lv_timer.d ./LVGL/src/misc/lv_timer.o ./LVGL/src/misc/lv_timer.su ./LVGL/src/misc/lv_tlsf.cyclo ./LVGL/src/misc/lv_tlsf.d ./LVGL/src/misc/lv_tlsf.o ./LVGL/src/misc/lv_tlsf.su ./LVGL/src/misc/lv_txt.cyclo ./LVGL/src/misc/lv_txt.d ./LVGL/src/misc/lv_txt.o ./LVGL/src/misc/lv_txt.su ./LVGL/src/misc/lv_txt_ap.cyclo ./LVGL/src/misc/lv_txt_ap.d ./LVGL/src/misc/lv_txt_ap.o ./LVGL/src/misc/lv_txt_ap.su ./LVGL/src/misc/lv_utils.cyclo ./LVGL/src/misc/lv_utils.d ./LVGL/src/misc/lv_utils.o ./LVGL/src/misc/lv_utils.su

.PHONY: clean-LVGL-2f-src-2f-misc

