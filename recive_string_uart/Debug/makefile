################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/STM32f103c6_DRIVERS(COMPLET)/subdir.mk
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
recive_string_uart.axf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
recive_string_uart.list \

OBJCOPY_BIN += \
recive_string_uart.bin \


# All Target
all: recive_string_uart.axf secondary-outputs

# Tool invocations
recive_string_uart.axf: $(OBJS) $(USER_OBJS) C:\Users\20102\Desktop\recive_string_uart\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "recive_string_uart.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\20102\Desktop\recive_string_uart\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="recive_string_uart.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

recive_string_uart.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "recive_string_uart.list"
	@echo 'Finished building: $@'
	@echo ' '

recive_string_uart.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "recive_string_uart.bin"
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
