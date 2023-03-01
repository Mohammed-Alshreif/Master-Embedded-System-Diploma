################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32/EEPROM.c \
../STM32/GPIO_DRIVER.c \
../STM32/I2C_LCD.c \
../STM32/LCD.c \
../STM32/OS.c \
../STM32/STM32_I2C_DRIVER.c \
../STM32/STM32_TIMERS_DRIVER.c \
../STM32/keypad.c \
../STM32/stm32_speed_DRIVER.c \
../STM32/stm32f103c6_ADC.c \
../STM32/stm32f103c6_ISR_DRIVER.c \
../STM32/stm32f103c6_SPI_DRIVER.c \
../STM32/stm32f103c6_USART_SRIVER.c 

OBJS += \
./STM32/EEPROM.o \
./STM32/GPIO_DRIVER.o \
./STM32/I2C_LCD.o \
./STM32/LCD.o \
./STM32/OS.o \
./STM32/STM32_I2C_DRIVER.o \
./STM32/STM32_TIMERS_DRIVER.o \
./STM32/keypad.o \
./STM32/stm32_speed_DRIVER.o \
./STM32/stm32f103c6_ADC.o \
./STM32/stm32f103c6_ISR_DRIVER.o \
./STM32/stm32f103c6_SPI_DRIVER.o \
./STM32/stm32f103c6_USART_SRIVER.o 

C_DEPS += \
./STM32/EEPROM.d \
./STM32/GPIO_DRIVER.d \
./STM32/I2C_LCD.d \
./STM32/LCD.d \
./STM32/OS.d \
./STM32/STM32_I2C_DRIVER.d \
./STM32/STM32_TIMERS_DRIVER.d \
./STM32/keypad.d \
./STM32/stm32_speed_DRIVER.d \
./STM32/stm32f103c6_ADC.d \
./STM32/stm32f103c6_ISR_DRIVER.d \
./STM32/stm32f103c6_SPI_DRIVER.d \
./STM32/stm32f103c6_USART_SRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
STM32/EEPROM.o: ../STM32/EEPROM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/ARM/LEC4_STACK/ARM_STACK/STM32/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32/GPIO_DRIVER.o: ../STM32/GPIO_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/ARM/LEC4_STACK/ARM_STACK/STM32/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32/GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32/I2C_LCD.o: ../STM32/I2C_LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/ARM/LEC4_STACK/ARM_STACK/STM32/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32/I2C_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32/LCD.o: ../STM32/LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/ARM/LEC4_STACK/ARM_STACK/STM32/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32/OS.o: ../STM32/OS.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/ARM/LEC4_STACK/ARM_STACK/STM32/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32/OS.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32/STM32_I2C_DRIVER.o: ../STM32/STM32_I2C_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/ARM/LEC4_STACK/ARM_STACK/STM32/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32/STM32_I2C_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32/STM32_TIMERS_DRIVER.o: ../STM32/STM32_TIMERS_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/ARM/LEC4_STACK/ARM_STACK/STM32/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32/STM32_TIMERS_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32/keypad.o: ../STM32/keypad.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/ARM/LEC4_STACK/ARM_STACK/STM32/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32/stm32_speed_DRIVER.o: ../STM32/stm32_speed_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/ARM/LEC4_STACK/ARM_STACK/STM32/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32/stm32_speed_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32/stm32f103c6_ADC.o: ../STM32/stm32f103c6_ADC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/ARM/LEC4_STACK/ARM_STACK/STM32/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32/stm32f103c6_ADC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32/stm32f103c6_ISR_DRIVER.o: ../STM32/stm32f103c6_ISR_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/ARM/LEC4_STACK/ARM_STACK/STM32/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32/stm32f103c6_ISR_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32/stm32f103c6_SPI_DRIVER.o: ../STM32/stm32f103c6_SPI_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/ARM/LEC4_STACK/ARM_STACK/STM32/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32/stm32f103c6_SPI_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32/stm32f103c6_USART_SRIVER.o: ../STM32/stm32f103c6_USART_SRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/ARM/LEC4_STACK/ARM_STACK/STM32/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32/stm32f103c6_USART_SRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

