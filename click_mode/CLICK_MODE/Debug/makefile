################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
CLICK_MODE.axf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
CLICK_MODE.list \

OBJCOPY_BIN += \
CLICK_MODE.bin \


# All Target
all: CLICK_MODE.axf secondary-outputs

# Tool invocations
CLICK_MODE.axf: $(OBJS) $(USER_OBJS) C:\E\embedded\test\final\ simulation\ code\ for\ my\ assignments\Unit7_MCU_Essential_Peripherals_lesson1_GPIO\click_mode\CLICK_MODE\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "CLICK_MODE.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\E\embedded\test\final simulation code for my assignments\Unit7_MCU_Essential_Peripherals_lesson1_GPIO\click_mode\CLICK_MODE\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="CLICK_MODE.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

CLICK_MODE.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "CLICK_MODE.list"
	@echo 'Finished building: $@'
	@echo ' '

CLICK_MODE.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "CLICK_MODE.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
