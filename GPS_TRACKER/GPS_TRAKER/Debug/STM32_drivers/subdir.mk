################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_drivers/CLICK_MODE.c \
../STM32_drivers/EEPROM.c \
../STM32_drivers/FIFO.c \
../STM32_drivers/GPIO_DRIVER.c \
../STM32_drivers/I2C_LCD.c \
../STM32_drivers/LCD.c \
../STM32_drivers/LIFO.c \
../STM32_drivers/MPU6050.c \
../STM32_drivers/STM32_I2C_DRIVER.c \
../STM32_drivers/STM32_TIMERS_DRIVER.c \
../STM32_drivers/Triac_drimmer.c \
../STM32_drivers/keypad.c \
../STM32_drivers/stm32_speed_DRIVER.c \
../STM32_drivers/stm32f103c6_ADC.c \
../STM32_drivers/stm32f103c6_ISR_DRIVER.c \
../STM32_drivers/stm32f103c6_SPI_DRIVER.c \
../STM32_drivers/stm32f103c6_USART_SRIVER.c 

OBJS += \
./STM32_drivers/CLICK_MODE.o \
./STM32_drivers/EEPROM.o \
./STM32_drivers/FIFO.o \
./STM32_drivers/GPIO_DRIVER.o \
./STM32_drivers/I2C_LCD.o \
./STM32_drivers/LCD.o \
./STM32_drivers/LIFO.o \
./STM32_drivers/MPU6050.o \
./STM32_drivers/STM32_I2C_DRIVER.o \
./STM32_drivers/STM32_TIMERS_DRIVER.o \
./STM32_drivers/Triac_drimmer.o \
./STM32_drivers/keypad.o \
./STM32_drivers/stm32_speed_DRIVER.o \
./STM32_drivers/stm32f103c6_ADC.o \
./STM32_drivers/stm32f103c6_ISR_DRIVER.o \
./STM32_drivers/stm32f103c6_SPI_DRIVER.o \
./STM32_drivers/stm32f103c6_USART_SRIVER.o 

C_DEPS += \
./STM32_drivers/CLICK_MODE.d \
./STM32_drivers/EEPROM.d \
./STM32_drivers/FIFO.d \
./STM32_drivers/GPIO_DRIVER.d \
./STM32_drivers/I2C_LCD.d \
./STM32_drivers/LCD.d \
./STM32_drivers/LIFO.d \
./STM32_drivers/MPU6050.d \
./STM32_drivers/STM32_I2C_DRIVER.d \
./STM32_drivers/STM32_TIMERS_DRIVER.d \
./STM32_drivers/Triac_drimmer.d \
./STM32_drivers/keypad.d \
./STM32_drivers/stm32_speed_DRIVER.d \
./STM32_drivers/stm32f103c6_ADC.d \
./STM32_drivers/stm32f103c6_ISR_DRIVER.d \
./STM32_drivers/stm32f103c6_SPI_DRIVER.d \
./STM32_drivers/stm32f103c6_USART_SRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_drivers/CLICK_MODE.o: ../STM32_drivers/CLICK_MODE.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/CLICK_MODE.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/EEPROM.o: ../STM32_drivers/EEPROM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/FIFO.o: ../STM32_drivers/FIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/GPIO_DRIVER.o: ../STM32_drivers/GPIO_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/I2C_LCD.o: ../STM32_drivers/I2C_LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/I2C_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/LCD.o: ../STM32_drivers/LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/LIFO.o: ../STM32_drivers/LIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/LIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/MPU6050.o: ../STM32_drivers/MPU6050.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/MPU6050.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/STM32_I2C_DRIVER.o: ../STM32_drivers/STM32_I2C_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/STM32_I2C_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/STM32_TIMERS_DRIVER.o: ../STM32_drivers/STM32_TIMERS_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/STM32_TIMERS_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/Triac_drimmer.o: ../STM32_drivers/Triac_drimmer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/Triac_drimmer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/keypad.o: ../STM32_drivers/keypad.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/stm32_speed_DRIVER.o: ../STM32_drivers/stm32_speed_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/stm32_speed_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/stm32f103c6_ADC.o: ../STM32_drivers/stm32f103c6_ADC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/stm32f103c6_ADC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/stm32f103c6_ISR_DRIVER.o: ../STM32_drivers/stm32f103c6_ISR_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/stm32f103c6_ISR_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/stm32f103c6_SPI_DRIVER.o: ../STM32_drivers/stm32f103c6_SPI_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/stm32f103c6_SPI_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_drivers/stm32f103c6_USART_SRIVER.o: ../STM32_drivers/stm32f103c6_USART_SRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/GPS_TRAKER/GPS_TRAKER/STM32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_drivers/stm32f103c6_USART_SRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

