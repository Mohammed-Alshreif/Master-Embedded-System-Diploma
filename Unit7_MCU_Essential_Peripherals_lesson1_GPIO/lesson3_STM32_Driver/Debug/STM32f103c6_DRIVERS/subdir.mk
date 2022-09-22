################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32f103c6_DRIVERS/GPIO_DRIVER.c 

OBJS += \
./STM32f103c6_DRIVERS/GPIO_DRIVER.o 

C_DEPS += \
./STM32f103c6_DRIVERS/GPIO_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
STM32f103c6_DRIVERS/GPIO_DRIVER.o: ../STM32f103c6_DRIVERS/GPIO_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/lesson3_STM32_Driver/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c6_DRIVERS/GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

