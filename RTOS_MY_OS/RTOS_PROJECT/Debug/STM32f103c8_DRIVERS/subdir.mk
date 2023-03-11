################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32f103c8_DRIVERS/EEPROM.c \
../STM32f103c8_DRIVERS/GPIO_DRIVER.c \
../STM32f103c8_DRIVERS/I2C_LCD.c \
../STM32f103c8_DRIVERS/LCD.c \
../STM32f103c8_DRIVERS/LIFO.c \
../STM32f103c8_DRIVERS/STM32_I2C_DRIVER.c \
../STM32f103c8_DRIVERS/STM32_TIMERS_DRIVER.c \
../STM32f103c8_DRIVERS/keypad.c \
../STM32f103c8_DRIVERS/stm32_speed_DRIVER.c \
../STM32f103c8_DRIVERS/stm32f103c6_ADC.c \
../STM32f103c8_DRIVERS/stm32f103c6_ISR_DRIVER.c \
../STM32f103c8_DRIVERS/stm32f103c6_SPI_DRIVER.c \
../STM32f103c8_DRIVERS/stm32f103c6_USART_SRIVER.c 

OBJS += \
./STM32f103c8_DRIVERS/EEPROM.o \
./STM32f103c8_DRIVERS/GPIO_DRIVER.o \
./STM32f103c8_DRIVERS/I2C_LCD.o \
./STM32f103c8_DRIVERS/LCD.o \
./STM32f103c8_DRIVERS/LIFO.o \
./STM32f103c8_DRIVERS/STM32_I2C_DRIVER.o \
./STM32f103c8_DRIVERS/STM32_TIMERS_DRIVER.o \
./STM32f103c8_DRIVERS/keypad.o \
./STM32f103c8_DRIVERS/stm32_speed_DRIVER.o \
./STM32f103c8_DRIVERS/stm32f103c6_ADC.o \
./STM32f103c8_DRIVERS/stm32f103c6_ISR_DRIVER.o \
./STM32f103c8_DRIVERS/stm32f103c6_SPI_DRIVER.o \
./STM32f103c8_DRIVERS/stm32f103c6_USART_SRIVER.o 

C_DEPS += \
./STM32f103c8_DRIVERS/EEPROM.d \
./STM32f103c8_DRIVERS/GPIO_DRIVER.d \
./STM32f103c8_DRIVERS/I2C_LCD.d \
./STM32f103c8_DRIVERS/LCD.d \
./STM32f103c8_DRIVERS/LIFO.d \
./STM32f103c8_DRIVERS/STM32_I2C_DRIVER.d \
./STM32f103c8_DRIVERS/STM32_TIMERS_DRIVER.d \
./STM32f103c8_DRIVERS/keypad.d \
./STM32f103c8_DRIVERS/stm32_speed_DRIVER.d \
./STM32f103c8_DRIVERS/stm32f103c6_ADC.d \
./STM32f103c8_DRIVERS/stm32f103c6_ISR_DRIVER.d \
./STM32f103c8_DRIVERS/stm32f103c6_SPI_DRIVER.d \
./STM32f103c8_DRIVERS/stm32f103c6_USART_SRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
STM32f103c8_DRIVERS/EEPROM.o: ../STM32f103c8_DRIVERS/EEPROM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c8_DRIVERS/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32f103c8_DRIVERS/GPIO_DRIVER.o: ../STM32f103c8_DRIVERS/GPIO_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c8_DRIVERS/GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32f103c8_DRIVERS/I2C_LCD.o: ../STM32f103c8_DRIVERS/I2C_LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c8_DRIVERS/I2C_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32f103c8_DRIVERS/LCD.o: ../STM32f103c8_DRIVERS/LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c8_DRIVERS/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32f103c8_DRIVERS/LIFO.o: ../STM32f103c8_DRIVERS/LIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c8_DRIVERS/LIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32f103c8_DRIVERS/STM32_I2C_DRIVER.o: ../STM32f103c8_DRIVERS/STM32_I2C_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c8_DRIVERS/STM32_I2C_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32f103c8_DRIVERS/STM32_TIMERS_DRIVER.o: ../STM32f103c8_DRIVERS/STM32_TIMERS_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c8_DRIVERS/STM32_TIMERS_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32f103c8_DRIVERS/keypad.o: ../STM32f103c8_DRIVERS/keypad.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c8_DRIVERS/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32f103c8_DRIVERS/stm32_speed_DRIVER.o: ../STM32f103c8_DRIVERS/stm32_speed_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c8_DRIVERS/stm32_speed_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32f103c8_DRIVERS/stm32f103c6_ADC.o: ../STM32f103c8_DRIVERS/stm32f103c6_ADC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c8_DRIVERS/stm32f103c6_ADC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32f103c8_DRIVERS/stm32f103c6_ISR_DRIVER.o: ../STM32f103c8_DRIVERS/stm32f103c6_ISR_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c8_DRIVERS/stm32f103c6_ISR_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32f103c8_DRIVERS/stm32f103c6_SPI_DRIVER.o: ../STM32f103c8_DRIVERS/stm32f103c6_SPI_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c8_DRIVERS/stm32f103c6_SPI_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32f103c8_DRIVERS/stm32f103c6_USART_SRIVER.o: ../STM32f103c8_DRIVERS/stm32f103c6_USART_SRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c8_DRIVERS/stm32f103c6_USART_SRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

