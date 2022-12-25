################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32/EEPROM.c \
../stm32/GPIO_DRIVER.c \
../stm32/LCD.c \
../stm32/STM32_I2C_DRIVER.c \
../stm32/STM32_I2C_LCD.c \
../stm32/STM32_TIMERS_DRIVER.c \
../stm32/keypad.c \
../stm32/stm32_speed_DRIVER.c \
../stm32/stm32f103c6_ISR_DRIVER.c \
../stm32/stm32f103c6_SPI_DRIVER.c \
../stm32/stm32f103c6_USART_SRIVER.c 

OBJS += \
./stm32/EEPROM.o \
./stm32/GPIO_DRIVER.o \
./stm32/LCD.o \
./stm32/STM32_I2C_DRIVER.o \
./stm32/STM32_I2C_LCD.o \
./stm32/STM32_TIMERS_DRIVER.o \
./stm32/keypad.o \
./stm32/stm32_speed_DRIVER.o \
./stm32/stm32f103c6_ISR_DRIVER.o \
./stm32/stm32f103c6_SPI_DRIVER.o \
./stm32/stm32f103c6_USART_SRIVER.o 

C_DEPS += \
./stm32/EEPROM.d \
./stm32/GPIO_DRIVER.d \
./stm32/LCD.d \
./stm32/STM32_I2C_DRIVER.d \
./stm32/STM32_I2C_LCD.d \
./stm32/STM32_TIMERS_DRIVER.d \
./stm32/keypad.d \
./stm32/stm32_speed_DRIVER.d \
./stm32/stm32f103c6_ISR_DRIVER.d \
./stm32/stm32f103c6_SPI_DRIVER.d \
./stm32/stm32f103c6_USART_SRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
stm32/EEPROM.o: ../stm32/EEPROM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/bluetooth/stm32/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32/GPIO_DRIVER.o: ../stm32/GPIO_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/bluetooth/stm32/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32/GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32/LCD.o: ../stm32/LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/bluetooth/stm32/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32/STM32_I2C_DRIVER.o: ../stm32/STM32_I2C_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/bluetooth/stm32/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32/STM32_I2C_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32/STM32_I2C_LCD.o: ../stm32/STM32_I2C_LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/bluetooth/stm32/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32/STM32_I2C_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32/STM32_TIMERS_DRIVER.o: ../stm32/STM32_TIMERS_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/bluetooth/stm32/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32/STM32_TIMERS_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32/keypad.o: ../stm32/keypad.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/bluetooth/stm32/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32/stm32_speed_DRIVER.o: ../stm32/stm32_speed_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/bluetooth/stm32/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32/stm32_speed_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32/stm32f103c6_ISR_DRIVER.o: ../stm32/stm32f103c6_ISR_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/bluetooth/stm32/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32/stm32f103c6_ISR_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32/stm32f103c6_SPI_DRIVER.o: ../stm32/stm32f103c6_SPI_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/bluetooth/stm32/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32/stm32f103c6_SPI_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32/stm32f103c6_USART_SRIVER.o: ../stm32/stm32f103c6_USART_SRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/bluetooth/stm32/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32/stm32f103c6_USART_SRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

