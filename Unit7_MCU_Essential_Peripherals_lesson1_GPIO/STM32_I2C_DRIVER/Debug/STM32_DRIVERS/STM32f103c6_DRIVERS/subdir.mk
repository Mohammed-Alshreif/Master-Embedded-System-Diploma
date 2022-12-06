################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_DRIVERS/STM32f103c6_DRIVERS/EEPROM.c \
../STM32_DRIVERS/STM32f103c6_DRIVERS/GPIO_DRIVER.c \
../STM32_DRIVERS/STM32f103c6_DRIVERS/LCD.c \
../STM32_DRIVERS/STM32f103c6_DRIVERS/STM32_I2C_DRIVER.c \
../STM32_DRIVERS/STM32f103c6_DRIVERS/keypad.c \
../STM32_DRIVERS/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.c \
../STM32_DRIVERS/STM32f103c6_DRIVERS/stm32_speed_DRIVER.c \
../STM32_DRIVERS/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.c \
../STM32_DRIVERS/STM32f103c6_DRIVERS/stm32f103c6_USART_SRIVER.c 

OBJS += \
./STM32_DRIVERS/STM32f103c6_DRIVERS/EEPROM.o \
./STM32_DRIVERS/STM32f103c6_DRIVERS/GPIO_DRIVER.o \
./STM32_DRIVERS/STM32f103c6_DRIVERS/LCD.o \
./STM32_DRIVERS/STM32f103c6_DRIVERS/STM32_I2C_DRIVER.o \
./STM32_DRIVERS/STM32f103c6_DRIVERS/keypad.o \
./STM32_DRIVERS/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.o \
./STM32_DRIVERS/STM32f103c6_DRIVERS/stm32_speed_DRIVER.o \
./STM32_DRIVERS/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.o \
./STM32_DRIVERS/STM32f103c6_DRIVERS/stm32f103c6_USART_SRIVER.o 

C_DEPS += \
./STM32_DRIVERS/STM32f103c6_DRIVERS/EEPROM.d \
./STM32_DRIVERS/STM32f103c6_DRIVERS/GPIO_DRIVER.d \
./STM32_DRIVERS/STM32f103c6_DRIVERS/LCD.d \
./STM32_DRIVERS/STM32f103c6_DRIVERS/STM32_I2C_DRIVER.d \
./STM32_DRIVERS/STM32f103c6_DRIVERS/keypad.d \
./STM32_DRIVERS/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.d \
./STM32_DRIVERS/STM32f103c6_DRIVERS/stm32_speed_DRIVER.d \
./STM32_DRIVERS/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.d \
./STM32_DRIVERS/STM32f103c6_DRIVERS/stm32f103c6_USART_SRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_DRIVERS/STM32f103c6_DRIVERS/EEPROM.o: ../STM32_DRIVERS/STM32f103c6_DRIVERS/EEPROM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/STM32_I2C_DRIVER/STM32_DRIVERS/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_DRIVERS/STM32f103c6_DRIVERS/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_DRIVERS/STM32f103c6_DRIVERS/GPIO_DRIVER.o: ../STM32_DRIVERS/STM32f103c6_DRIVERS/GPIO_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/STM32_I2C_DRIVER/STM32_DRIVERS/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_DRIVERS/STM32f103c6_DRIVERS/GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_DRIVERS/STM32f103c6_DRIVERS/LCD.o: ../STM32_DRIVERS/STM32f103c6_DRIVERS/LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/STM32_I2C_DRIVER/STM32_DRIVERS/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_DRIVERS/STM32f103c6_DRIVERS/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_DRIVERS/STM32f103c6_DRIVERS/STM32_I2C_DRIVER.o: ../STM32_DRIVERS/STM32f103c6_DRIVERS/STM32_I2C_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/STM32_I2C_DRIVER/STM32_DRIVERS/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_DRIVERS/STM32f103c6_DRIVERS/STM32_I2C_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_DRIVERS/STM32f103c6_DRIVERS/keypad.o: ../STM32_DRIVERS/STM32f103c6_DRIVERS/keypad.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/STM32_I2C_DRIVER/STM32_DRIVERS/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_DRIVERS/STM32f103c6_DRIVERS/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_DRIVERS/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.o: ../STM32_DRIVERS/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/STM32_I2C_DRIVER/STM32_DRIVERS/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_DRIVERS/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_DRIVERS/STM32f103c6_DRIVERS/stm32_speed_DRIVER.o: ../STM32_DRIVERS/STM32f103c6_DRIVERS/stm32_speed_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/STM32_I2C_DRIVER/STM32_DRIVERS/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_DRIVERS/STM32f103c6_DRIVERS/stm32_speed_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_DRIVERS/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.o: ../STM32_DRIVERS/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/STM32_I2C_DRIVER/STM32_DRIVERS/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_DRIVERS/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_DRIVERS/STM32f103c6_DRIVERS/stm32f103c6_USART_SRIVER.o: ../STM32_DRIVERS/STM32f103c6_DRIVERS/stm32f103c6_USART_SRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/STM32_I2C_DRIVER/STM32_DRIVERS/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_DRIVERS/STM32f103c6_DRIVERS/stm32f103c6_USART_SRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

