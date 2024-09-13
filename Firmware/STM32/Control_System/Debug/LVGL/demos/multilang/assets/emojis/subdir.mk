################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/demos/multilang/assets/emojis/img_emoji_artist_palette.c \
../LVGL/demos/multilang/assets/emojis/img_emoji_books.c \
../LVGL/demos/multilang/assets/emojis/img_emoji_camera_with_flash.c \
../LVGL/demos/multilang/assets/emojis/img_emoji_cat_face.c \
../LVGL/demos/multilang/assets/emojis/img_emoji_deciduous_tree.c \
../LVGL/demos/multilang/assets/emojis/img_emoji_dog_face.c \
../LVGL/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.c \
../LVGL/demos/multilang/assets/emojis/img_emoji_flexed_biceps.c \
../LVGL/demos/multilang/assets/emojis/img_emoji_movie_camera.c \
../LVGL/demos/multilang/assets/emojis/img_emoji_red_heart.c \
../LVGL/demos/multilang/assets/emojis/img_emoji_rocket.c \
../LVGL/demos/multilang/assets/emojis/img_emoji_soccer_ball.c 

OBJS += \
./LVGL/demos/multilang/assets/emojis/img_emoji_artist_palette.o \
./LVGL/demos/multilang/assets/emojis/img_emoji_books.o \
./LVGL/demos/multilang/assets/emojis/img_emoji_camera_with_flash.o \
./LVGL/demos/multilang/assets/emojis/img_emoji_cat_face.o \
./LVGL/demos/multilang/assets/emojis/img_emoji_deciduous_tree.o \
./LVGL/demos/multilang/assets/emojis/img_emoji_dog_face.o \
./LVGL/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.o \
./LVGL/demos/multilang/assets/emojis/img_emoji_flexed_biceps.o \
./LVGL/demos/multilang/assets/emojis/img_emoji_movie_camera.o \
./LVGL/demos/multilang/assets/emojis/img_emoji_red_heart.o \
./LVGL/demos/multilang/assets/emojis/img_emoji_rocket.o \
./LVGL/demos/multilang/assets/emojis/img_emoji_soccer_ball.o 

C_DEPS += \
./LVGL/demos/multilang/assets/emojis/img_emoji_artist_palette.d \
./LVGL/demos/multilang/assets/emojis/img_emoji_books.d \
./LVGL/demos/multilang/assets/emojis/img_emoji_camera_with_flash.d \
./LVGL/demos/multilang/assets/emojis/img_emoji_cat_face.d \
./LVGL/demos/multilang/assets/emojis/img_emoji_deciduous_tree.d \
./LVGL/demos/multilang/assets/emojis/img_emoji_dog_face.d \
./LVGL/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.d \
./LVGL/demos/multilang/assets/emojis/img_emoji_flexed_biceps.d \
./LVGL/demos/multilang/assets/emojis/img_emoji_movie_camera.d \
./LVGL/demos/multilang/assets/emojis/img_emoji_red_heart.d \
./LVGL/demos/multilang/assets/emojis/img_emoji_rocket.d \
./LVGL/demos/multilang/assets/emojis/img_emoji_soccer_ball.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/demos/multilang/assets/emojis/%.o LVGL/demos/multilang/assets/emojis/%.su LVGL/demos/multilang/assets/emojis/%.cyclo: ../LVGL/demos/multilang/assets/emojis/%.c LVGL/demos/multilang/assets/emojis/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F407xx -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/include" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable/GCC/ARM_CM4F" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/FREERTOS/portable" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL" -I"D:/OneDrive/Disk_2/CHARGE_BATTERY/Firmware/STM32/Control_System/LVGL/src" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-demos-2f-multilang-2f-assets-2f-emojis

clean-LVGL-2f-demos-2f-multilang-2f-assets-2f-emojis:
	-$(RM) ./LVGL/demos/multilang/assets/emojis/img_emoji_artist_palette.cyclo ./LVGL/demos/multilang/assets/emojis/img_emoji_artist_palette.d ./LVGL/demos/multilang/assets/emojis/img_emoji_artist_palette.o ./LVGL/demos/multilang/assets/emojis/img_emoji_artist_palette.su ./LVGL/demos/multilang/assets/emojis/img_emoji_books.cyclo ./LVGL/demos/multilang/assets/emojis/img_emoji_books.d ./LVGL/demos/multilang/assets/emojis/img_emoji_books.o ./LVGL/demos/multilang/assets/emojis/img_emoji_books.su ./LVGL/demos/multilang/assets/emojis/img_emoji_camera_with_flash.cyclo ./LVGL/demos/multilang/assets/emojis/img_emoji_camera_with_flash.d ./LVGL/demos/multilang/assets/emojis/img_emoji_camera_with_flash.o ./LVGL/demos/multilang/assets/emojis/img_emoji_camera_with_flash.su ./LVGL/demos/multilang/assets/emojis/img_emoji_cat_face.cyclo ./LVGL/demos/multilang/assets/emojis/img_emoji_cat_face.d ./LVGL/demos/multilang/assets/emojis/img_emoji_cat_face.o ./LVGL/demos/multilang/assets/emojis/img_emoji_cat_face.su ./LVGL/demos/multilang/assets/emojis/img_emoji_deciduous_tree.cyclo ./LVGL/demos/multilang/assets/emojis/img_emoji_deciduous_tree.d ./LVGL/demos/multilang/assets/emojis/img_emoji_deciduous_tree.o ./LVGL/demos/multilang/assets/emojis/img_emoji_deciduous_tree.su ./LVGL/demos/multilang/assets/emojis/img_emoji_dog_face.cyclo ./LVGL/demos/multilang/assets/emojis/img_emoji_dog_face.d ./LVGL/demos/multilang/assets/emojis/img_emoji_dog_face.o ./LVGL/demos/multilang/assets/emojis/img_emoji_dog_face.su ./LVGL/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.cyclo ./LVGL/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.d ./LVGL/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.o ./LVGL/demos/multilang/assets/emojis/img_emoji_earth_globe_europe_africa.su ./LVGL/demos/multilang/assets/emojis/img_emoji_flexed_biceps.cyclo ./LVGL/demos/multilang/assets/emojis/img_emoji_flexed_biceps.d ./LVGL/demos/multilang/assets/emojis/img_emoji_flexed_biceps.o ./LVGL/demos/multilang/assets/emojis/img_emoji_flexed_biceps.su ./LVGL/demos/multilang/assets/emojis/img_emoji_movie_camera.cyclo ./LVGL/demos/multilang/assets/emojis/img_emoji_movie_camera.d ./LVGL/demos/multilang/assets/emojis/img_emoji_movie_camera.o ./LVGL/demos/multilang/assets/emojis/img_emoji_movie_camera.su ./LVGL/demos/multilang/assets/emojis/img_emoji_red_heart.cyclo ./LVGL/demos/multilang/assets/emojis/img_emoji_red_heart.d ./LVGL/demos/multilang/assets/emojis/img_emoji_red_heart.o ./LVGL/demos/multilang/assets/emojis/img_emoji_red_heart.su ./LVGL/demos/multilang/assets/emojis/img_emoji_rocket.cyclo ./LVGL/demos/multilang/assets/emojis/img_emoji_rocket.d ./LVGL/demos/multilang/assets/emojis/img_emoji_rocket.o ./LVGL/demos/multilang/assets/emojis/img_emoji_rocket.su ./LVGL/demos/multilang/assets/emojis/img_emoji_soccer_ball.cyclo ./LVGL/demos/multilang/assets/emojis/img_emoji_soccer_ball.d ./LVGL/demos/multilang/assets/emojis/img_emoji_soccer_ball.o ./LVGL/demos/multilang/assets/emojis/img_emoji_soccer_ball.su

.PHONY: clean-LVGL-2f-demos-2f-multilang-2f-assets-2f-emojis

