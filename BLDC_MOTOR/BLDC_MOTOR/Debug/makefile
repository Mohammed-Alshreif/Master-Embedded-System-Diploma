################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include stm32_drivers/subdir.mk
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
BLDC_MOTOR.axf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
BLDC_MOTOR.list \

OBJCOPY_BIN += \
BLDC_MOTOR.bin \


# All Target
all: BLDC_MOTOR.axf secondary-outputs

# Tool invocations
BLDC_MOTOR.axf: $(OBJS) $(USER_OBJS) C:\E\embedded\test\final\ simulation\ code\ for\ my\ assignments\BLDC_MOTOR\BLDC_MOTOR\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "BLDC_MOTOR.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\E\embedded\test\final simulation code for my assignments\BLDC_MOTOR\BLDC_MOTOR\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="BLDC_MOTOR.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

BLDC_MOTOR.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "BLDC_MOTOR.list"
	@echo 'Finished building: $@'
	@echo ' '

BLDC_MOTOR.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "BLDC_MOTOR.bin"
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
