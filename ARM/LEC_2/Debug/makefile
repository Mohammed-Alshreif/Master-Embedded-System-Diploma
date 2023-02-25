################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include stm32/subdir.mk
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
ARM_ASSEMBLY.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ARM_ASSEMBLY.list \

OBJCOPY_BIN += \
ARM_ASSEMBLY.bin \


# All Target
all: ARM_ASSEMBLY.elf secondary-outputs

# Tool invocations
ARM_ASSEMBLY.elf: $(OBJS) $(USER_OBJS) C:\E\embedded\test\final\ simulation\ code\ for\ my\ assignments\ARM\LEC_2\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "ARM_ASSEMBLY.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\E\embedded\test\final simulation code for my assignments\ARM\LEC_2\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ARM_ASSEMBLY.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	arm-none-eabi-objdump -D ARM_ASSEMBLY.elf > ARM_ASSEMBLY.s
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ARM_ASSEMBLY.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ARM_ASSEMBLY.list"
	@echo 'Finished building: $@'
	@echo ' '

ARM_ASSEMBLY.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "ARM_ASSEMBLY.bin"
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
