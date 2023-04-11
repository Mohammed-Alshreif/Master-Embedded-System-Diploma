################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/STM32f103c6_DRIVERS(COMPLET)/EEPROM.c \
../Src/STM32f103c6_DRIVERS(COMPLET)/FIFO.c \
../Src/STM32f103c6_DRIVERS(COMPLET)/GPIO_DRIVER.c \
../Src/STM32f103c6_DRIVERS(COMPLET)/I2C_LCD.c \
../Src/STM32f103c6_DRIVERS(COMPLET)/LCD.c \
../Src/STM32f103c6_DRIVERS(COMPLET)/LIFO.c \
../Src/STM32f103c6_DRIVERS(COMPLET)/STM32_I2C_DRIVER.c \
../Src/STM32f103c6_DRIVERS(COMPLET)/STM32_TIMERS_DRIVER.c \
../Src/STM32f103c6_DRIVERS(COMPLET)/keypad.c \
../Src/STM32f103c6_DRIVERS(COMPLET)/stm32_speed_DRIVER.c \
../Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_ADC.c \
../Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_ISR_DRIVER.c \
../Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_SPI_DRIVER.c \
../Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_USART_SRIVER.c 

OBJS += \
./Src/STM32f103c6_DRIVERS(COMPLET)/EEPROM.o \
./Src/STM32f103c6_DRIVERS(COMPLET)/FIFO.o \
./Src/STM32f103c6_DRIVERS(COMPLET)/GPIO_DRIVER.o \
./Src/STM32f103c6_DRIVERS(COMPLET)/I2C_LCD.o \
./Src/STM32f103c6_DRIVERS(COMPLET)/LCD.o \
./Src/STM32f103c6_DRIVERS(COMPLET)/LIFO.o \
./Src/STM32f103c6_DRIVERS(COMPLET)/STM32_I2C_DRIVER.o \
./Src/STM32f103c6_DRIVERS(COMPLET)/STM32_TIMERS_DRIVER.o \
./Src/STM32f103c6_DRIVERS(COMPLET)/keypad.o \
./Src/STM32f103c6_DRIVERS(COMPLET)/stm32_speed_DRIVER.o \
./Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_ADC.o \
./Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_ISR_DRIVER.o \
./Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_SPI_DRIVER.o \
./Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_USART_SRIVER.o 

C_DEPS += \
./Src/STM32f103c6_DRIVERS(COMPLET)/EEPROM.d \
./Src/STM32f103c6_DRIVERS(COMPLET)/FIFO.d \
./Src/STM32f103c6_DRIVERS(COMPLET)/GPIO_DRIVER.d \
./Src/STM32f103c6_DRIVERS(COMPLET)/I2C_LCD.d \
./Src/STM32f103c6_DRIVERS(COMPLET)/LCD.d \
./Src/STM32f103c6_DRIVERS(COMPLET)/LIFO.d \
./Src/STM32f103c6_DRIVERS(COMPLET)/STM32_I2C_DRIVER.d \
./Src/STM32f103c6_DRIVERS(COMPLET)/STM32_TIMERS_DRIVER.d \
./Src/STM32f103c6_DRIVERS(COMPLET)/keypad.d \
./Src/STM32f103c6_DRIVERS(COMPLET)/stm32_speed_DRIVER.d \
./Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_ADC.d \
./Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_ISR_DRIVER.d \
./Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_SPI_DRIVER.d \
./Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_USART_SRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
Src/STM32f103c6_DRIVERS(COMPLET)/EEPROM.o: ../Src/STM32f103c6_DRIVERS(COMPLET)/EEPROM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/recive_string_uart/Src/STM32f103c6_DRIVERS(COMPLET)/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32f103c6_DRIVERS(COMPLET)/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32f103c6_DRIVERS(COMPLET)/FIFO.o: ../Src/STM32f103c6_DRIVERS(COMPLET)/FIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/recive_string_uart/Src/STM32f103c6_DRIVERS(COMPLET)/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32f103c6_DRIVERS(COMPLET)/FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32f103c6_DRIVERS(COMPLET)/GPIO_DRIVER.o: ../Src/STM32f103c6_DRIVERS(COMPLET)/GPIO_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/recive_string_uart/Src/STM32f103c6_DRIVERS(COMPLET)/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32f103c6_DRIVERS(COMPLET)/GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32f103c6_DRIVERS(COMPLET)/I2C_LCD.o: ../Src/STM32f103c6_DRIVERS(COMPLET)/I2C_LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/recive_string_uart/Src/STM32f103c6_DRIVERS(COMPLET)/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32f103c6_DRIVERS(COMPLET)/I2C_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32f103c6_DRIVERS(COMPLET)/LCD.o: ../Src/STM32f103c6_DRIVERS(COMPLET)/LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/recive_string_uart/Src/STM32f103c6_DRIVERS(COMPLET)/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32f103c6_DRIVERS(COMPLET)/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32f103c6_DRIVERS(COMPLET)/LIFO.o: ../Src/STM32f103c6_DRIVERS(COMPLET)/LIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/recive_string_uart/Src/STM32f103c6_DRIVERS(COMPLET)/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32f103c6_DRIVERS(COMPLET)/LIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32f103c6_DRIVERS(COMPLET)/STM32_I2C_DRIVER.o: ../Src/STM32f103c6_DRIVERS(COMPLET)/STM32_I2C_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/recive_string_uart/Src/STM32f103c6_DRIVERS(COMPLET)/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32f103c6_DRIVERS(COMPLET)/STM32_I2C_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32f103c6_DRIVERS(COMPLET)/STM32_TIMERS_DRIVER.o: ../Src/STM32f103c6_DRIVERS(COMPLET)/STM32_TIMERS_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/recive_string_uart/Src/STM32f103c6_DRIVERS(COMPLET)/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32f103c6_DRIVERS(COMPLET)/STM32_TIMERS_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32f103c6_DRIVERS(COMPLET)/keypad.o: ../Src/STM32f103c6_DRIVERS(COMPLET)/keypad.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/recive_string_uart/Src/STM32f103c6_DRIVERS(COMPLET)/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32f103c6_DRIVERS(COMPLET)/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32f103c6_DRIVERS(COMPLET)/stm32_speed_DRIVER.o: ../Src/STM32f103c6_DRIVERS(COMPLET)/stm32_speed_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/recive_string_uart/Src/STM32f103c6_DRIVERS(COMPLET)/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32f103c6_DRIVERS(COMPLET)/stm32_speed_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_ADC.o: ../Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_ADC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/recive_string_uart/Src/STM32f103c6_DRIVERS(COMPLET)/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_ADC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_ISR_DRIVER.o: ../Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_ISR_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/recive_string_uart/Src/STM32f103c6_DRIVERS(COMPLET)/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_ISR_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_SPI_DRIVER.o: ../Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_SPI_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/recive_string_uart/Src/STM32f103c6_DRIVERS(COMPLET)/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_SPI_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_USART_SRIVER.o: ../Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_USART_SRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/Users/20102/Desktop/recive_string_uart/Src/STM32f103c6_DRIVERS(COMPLET)/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32f103c6_DRIVERS(COMPLET)/stm32f103c6_USART_SRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

