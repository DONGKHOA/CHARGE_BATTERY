################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Scheduler/subdir.mk
-include Middleware/Voltage_convert_frequency/subdir.mk
-include Middleware/Ring_Buffer/subdir.mk
-include Middleware/Read_220VAC/subdir.mk
-include Middleware/PI_Control/subdir.mk
-include Middleware/Frequency_convert_pulse/Private/subdir.mk
-include Middleware/Frequency_convert_pulse/subdir.mk
-include Middleware/Current_convert_frequency/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Devices/ADS1115/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include BSP/UART/subdir.mk
-include BSP/TIMER/PWM/subdir.mk
-include BSP/TIMER/IRQ/subdir.mk
-include BSP/SysTick/subdir.mk
-include BSP/I2C/subdir.mk
-include App/LED/subdir.mk
-include App/Data/subdir.mk
-include App/Control/subdir.mk
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


BUILD_ARTIFACT_NAME := Control_LLC
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Control_LLC.elf \

MAP_FILES += \
Control_LLC.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Control_LLC.list \

OBJCOPY_HEX += \
Control_LLC.hex \


# All Target
all: main-build

# Main-build Target
main-build: Control_LLC.elf secondary-outputs

# Tool invocations
Control_LLC.elf Control_LLC.map: $(OBJS) $(USER_OBJS) D:\OneDrive\Disk_2\CHARGE_BATTERY\Firmware\STM32\Control_LLC\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Control_LLC.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\OneDrive\Disk_2\CHARGE_BATTERY\Firmware\STM32\Control_LLC\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Control_LLC.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Control_LLC.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Control_LLC.list"
	@echo 'Finished building: $@'
	@echo ' '

Control_LLC.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Control_LLC.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Control_LLC.elf Control_LLC.hex Control_LLC.list Control_LLC.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
