################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middleware/Ring_Buffer/subdir.mk
-include LVGL/src/widgets/subdir.mk
-include LVGL/src/misc/subdir.mk
-include LVGL/src/hal/subdir.mk
-include LVGL/src/font/subdir.mk
-include LVGL/src/extra/widgets/win/subdir.mk
-include LVGL/src/extra/widgets/tileview/subdir.mk
-include LVGL/src/extra/widgets/tabview/subdir.mk
-include LVGL/src/extra/widgets/spinner/subdir.mk
-include LVGL/src/extra/widgets/spinbox/subdir.mk
-include LVGL/src/extra/widgets/span/subdir.mk
-include LVGL/src/extra/widgets/msgbox/subdir.mk
-include LVGL/src/extra/widgets/meter/subdir.mk
-include LVGL/src/extra/widgets/menu/subdir.mk
-include LVGL/src/extra/widgets/list/subdir.mk
-include LVGL/src/extra/widgets/led/subdir.mk
-include LVGL/src/extra/widgets/keyboard/subdir.mk
-include LVGL/src/extra/widgets/imgbtn/subdir.mk
-include LVGL/src/extra/widgets/colorwheel/subdir.mk
-include LVGL/src/extra/widgets/chart/subdir.mk
-include LVGL/src/extra/widgets/calendar/subdir.mk
-include LVGL/src/extra/widgets/animimg/subdir.mk
-include LVGL/src/extra/themes/mono/subdir.mk
-include LVGL/src/extra/themes/default/subdir.mk
-include LVGL/src/extra/themes/basic/subdir.mk
-include LVGL/src/extra/others/snapshot/subdir.mk
-include LVGL/src/extra/others/msg/subdir.mk
-include LVGL/src/extra/others/monkey/subdir.mk
-include LVGL/src/extra/others/imgfont/subdir.mk
-include LVGL/src/extra/others/ime/subdir.mk
-include LVGL/src/extra/others/gridnav/subdir.mk
-include LVGL/src/extra/others/fragment/subdir.mk
-include LVGL/src/extra/libs/tiny_ttf/subdir.mk
-include LVGL/src/extra/libs/sjpg/subdir.mk
-include LVGL/src/extra/libs/rlottie/subdir.mk
-include LVGL/src/extra/libs/qrcode/subdir.mk
-include LVGL/src/extra/libs/png/subdir.mk
-include LVGL/src/extra/libs/gif/subdir.mk
-include LVGL/src/extra/libs/fsdrv/subdir.mk
-include LVGL/src/extra/libs/freetype/subdir.mk
-include LVGL/src/extra/libs/ffmpeg/subdir.mk
-include LVGL/src/extra/libs/bmp/subdir.mk
-include LVGL/src/extra/layouts/grid/subdir.mk
-include LVGL/src/extra/layouts/flex/subdir.mk
-include LVGL/src/extra/subdir.mk
-include LVGL/src/draw/swm341_dma2d/subdir.mk
-include LVGL/src/draw/sw/subdir.mk
-include LVGL/src/draw/stm32_dma2d/subdir.mk
-include LVGL/src/draw/sdl/subdir.mk
-include LVGL/src/draw/renesas/subdir.mk
-include LVGL/src/draw/nxp/vglite/subdir.mk
-include LVGL/src/draw/nxp/pxp/subdir.mk
-include LVGL/src/draw/arm2d/subdir.mk
-include LVGL/src/draw/subdir.mk
-include LVGL/src/core/subdir.mk
-include FREERTOS/portable/GCC/ARM_CM4F/subdir.mk
-include FREERTOS/portable/subdir.mk
-include FREERTOS/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Devices/XPT2046/subdir.mk
-include Devices/SSD1963/subdir.mk
-include Devices/ADC_MUX/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include BSP/UART/subdir.mk
-include BSP/SysTick/subdir.mk
-include BSP/SPI/subdir.mk
-include BSP/GPIO/subdir.mk
-include BSP/FSMC/subdir.mk
-include BSP/ADC/subdir.mk
-include App/CMDLine/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Control_System
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Control_System.elf \

MAP_FILES += \
Control_System.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Control_System.list \


# All Target
all: main-build

# Main-build Target
main-build: Control_System.elf secondary-outputs

# Tool invocations
Control_System.elf Control_System.map: $(OBJS) $(USER_OBJS) D:\OneDrive\Disk_2\CHARGE_BATTERY\Firmware\STM32\Control_System\STM32F407VETX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Control_System.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\OneDrive\Disk_2\CHARGE_BATTERY\Firmware\STM32\Control_System\STM32F407VETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Control_System.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Control_System.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Control_System.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Control_System.elf Control_System.list Control_System.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
