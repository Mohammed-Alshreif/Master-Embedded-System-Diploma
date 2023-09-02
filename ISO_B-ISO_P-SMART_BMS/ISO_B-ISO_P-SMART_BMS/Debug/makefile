################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STM32_Drivers/ALSHREIF_RTOS/subdir.mk
-include STM32_Drivers/subdir.mk
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
ISO_B-ISO_P-SMART_BMS.axf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ISO_B-ISO_P-SMART_BMS.list \

OBJCOPY_BIN += \
ISO_B-ISO_P-SMART_BMS.bin \


# All Target
all: ISO_B-ISO_P-SMART_BMS.axf secondary-outputs

# Tool invocations
ISO_B-ISO_P-SMART_BMS.axf: $(OBJS) $(USER_OBJS) C:\E\embedded\test\final\ simulation\ code\ for\ my\ assignments\ISO_B-ISO_P-SMART_BMS\ISO_B-ISO_P-SMART_BMS\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "ISO_B-ISO_P-SMART_BMS.axf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\E\embedded\test\final simulation code for my assignments\ISO_B-ISO_P-SMART_BMS\ISO_B-ISO_P-SMART_BMS\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ISO_B-ISO_P-SMART_BMS.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ISO_B-ISO_P-SMART_BMS.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ISO_B-ISO_P-SMART_BMS.list"
	@echo 'Finished building: $@'
	@echo ' '

ISO_B-ISO_P-SMART_BMS.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "ISO_B-ISO_P-SMART_BMS.bin"
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
