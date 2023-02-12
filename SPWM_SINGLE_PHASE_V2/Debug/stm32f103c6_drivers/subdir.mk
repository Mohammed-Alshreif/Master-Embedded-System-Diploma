################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6_drivers/EEPROM.c \
../stm32f103c6_drivers/GPIO_DRIVER.c \
../stm32f103c6_drivers/I2C_LCD.c \
../stm32f103c6_drivers/LCD.c \
../stm32f103c6_drivers/STM32_I2C_DRIVER.c \
../stm32f103c6_drivers/STM32_TIMERS_DRIVER.c \
../stm32f103c6_drivers/keypad.c \
../stm32f103c6_drivers/stm32_speed_DRIVER.c \
../stm32f103c6_drivers/stm32f103c6_ADC.c \
../stm32f103c6_drivers/stm32f103c6_ISR_DRIVER.c \
../stm32f103c6_drivers/stm32f103c6_SPI_DRIVER.c \
../stm32f103c6_drivers/stm32f103c6_USART_SRIVER.c 

OBJS += \
./stm32f103c6_drivers/EEPROM.o \
./stm32f103c6_drivers/GPIO_DRIVER.o \
./stm32f103c6_drivers/I2C_LCD.o \
./stm32f103c6_drivers/LCD.o \
./stm32f103c6_drivers/STM32_I2C_DRIVER.o \
./stm32f103c6_drivers/STM32_TIMERS_DRIVER.o \
./stm32f103c6_drivers/keypad.o \
./stm32f103c6_drivers/stm32_speed_DRIVER.o \
./stm32f103c6_drivers/stm32f103c6_ADC.o \
./stm32f103c6_drivers/stm32f103c6_ISR_DRIVER.o \
./stm32f103c6_drivers/stm32f103c6_SPI_DRIVER.o \
./stm32f103c6_drivers/stm32f103c6_USART_SRIVER.o 

C_DEPS += \
./stm32f103c6_drivers/EEPROM.d \
./stm32f103c6_drivers/GPIO_DRIVER.d \
./stm32f103c6_drivers/I2C_LCD.d \
./stm32f103c6_drivers/LCD.d \
./stm32f103c6_drivers/STM32_I2C_DRIVER.d \
./stm32f103c6_drivers/STM32_TIMERS_DRIVER.d \
./stm32f103c6_drivers/keypad.d \
./stm32f103c6_drivers/stm32_speed_DRIVER.d \
./stm32f103c6_drivers/stm32f103c6_ADC.d \
./stm32f103c6_drivers/stm32f103c6_ISR_DRIVER.d \
./stm32f103c6_drivers/stm32f103c6_SPI_DRIVER.d \
./stm32f103c6_drivers/stm32f103c6_USART_SRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6_drivers/EEPROM.o: ../stm32f103c6_drivers/EEPROM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/unit8_ADC/ADC/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_drivers/GPIO_DRIVER.o: ../stm32f103c6_drivers/GPIO_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/unit8_ADC/ADC/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_drivers/I2C_LCD.o: ../stm32f103c6_drivers/I2C_LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/unit8_ADC/ADC/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/I2C_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_drivers/LCD.o: ../stm32f103c6_drivers/LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/unit8_ADC/ADC/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_drivers/STM32_I2C_DRIVER.o: ../stm32f103c6_drivers/STM32_I2C_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/unit8_ADC/ADC/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/STM32_I2C_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_drivers/STM32_TIMERS_DRIVER.o: ../stm32f103c6_drivers/STM32_TIMERS_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/unit8_ADC/ADC/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/STM32_TIMERS_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_drivers/keypad.o: ../stm32f103c6_drivers/keypad.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/unit8_ADC/ADC/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_drivers/stm32_speed_DRIVER.o: ../stm32f103c6_drivers/stm32_speed_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/unit8_ADC/ADC/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/stm32_speed_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_drivers/stm32f103c6_ADC.o: ../stm32f103c6_drivers/stm32f103c6_ADC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/unit8_ADC/ADC/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/stm32f103c6_ADC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_drivers/stm32f103c6_ISR_DRIVER.o: ../stm32f103c6_drivers/stm32f103c6_ISR_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/unit8_ADC/ADC/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/stm32f103c6_ISR_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_drivers/stm32f103c6_SPI_DRIVER.o: ../stm32f103c6_drivers/stm32f103c6_SPI_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/unit8_ADC/ADC/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/stm32f103c6_SPI_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_drivers/stm32f103c6_USART_SRIVER.o: ../stm32f103c6_drivers/stm32f103c6_USART_SRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/unit8_ADC/ADC/stm32f103c6_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/stm32f103c6_USART_SRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

