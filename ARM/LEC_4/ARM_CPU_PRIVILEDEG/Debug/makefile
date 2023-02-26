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
ARM_CPU_PRIVILEDEG.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ARM_CPU_PRIVILEDEG.list \

OBJCOPY_BIN += \
ARM_CPU_PRIVILEDEG.bin \


# All Target
all: ARM_CPU_PRIVILEDEG.elf secondary-outputs

# Tool invocations
ARM_CPU_PRIVILEDEG.elf: $(OBJS) $(USER_OBJS) C:\E\embedded\test\final\ simulation\ code\ for\ my\ assignments\ARM\LEC_3_CPU_PRIVILEGED\ARM_CPU_PRIVILEDEG\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "ARM_CPU_PRIVILEDEG.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\E\embedded\test\final simulation code for my assignments\ARM\LEC_3_CPU_PRIVILEGED\ARM_CPU_PRIVILEDEG\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ARM_CPU_PRIVILEDEG.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	arm-none-eabi-objdump -D ARM_CPU_PRIVILEDEG.elf > ARM_CPU_PRIVILEDEG.s
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ARM_CPU_PRIVILEDEG.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ARM_CPU_PRIVILEDEG.list"
	@echo 'Finished building: $@'
	@echo ' '

ARM_CPU_PRIVILEDEG.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "ARM_CPU_PRIVILEDEG.bin"
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
