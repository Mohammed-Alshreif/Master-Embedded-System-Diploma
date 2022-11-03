################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include stm32f103c6_DRIVER/STM32f103c6_DRIVERS/subdir.mk
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
stm32f103c6_SPI_DRIVER.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
stm32f103c6_SPI_DRIVER.list \

OBJCOPY_BIN += \
stm32f103c6_SPI_DRIVER.bin \


# All Target
all: stm32f103c6_SPI_DRIVER.elf secondary-outputs

# Tool invocations
stm32f103c6_SPI_DRIVER.elf: $(OBJS) $(USER_OBJS) C:\E\embedded\test\final\ simulation\ code\ for\ my\ assignments\Unit7_MCU_Essential_Peripherals_lesson1_GPIO\stm32f103c6_SPI_DRIVER\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "stm32f103c6_SPI_DRIVER.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\E\embedded\test\final simulation code for my assignments\Unit7_MCU_Essential_Peripherals_lesson1_GPIO\stm32f103c6_SPI_DRIVER\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="stm32f103c6_SPI_DRIVER.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

stm32f103c6_SPI_DRIVER.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "stm32f103c6_SPI_DRIVER.list"
	@echo 'Finished building: $@'
	@echo ' '

stm32f103c6_SPI_DRIVER.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "stm32f103c6_SPI_DRIVER.bin"
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
