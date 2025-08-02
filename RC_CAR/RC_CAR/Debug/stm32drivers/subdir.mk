################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32drivers/CLICK_MODE.c \
../stm32drivers/EEPROM.c \
../stm32drivers/FIFO.c \
../stm32drivers/GPIO_DRIVER.c \
../stm32drivers/I2C_LCD.c \
../stm32drivers/LCD.c \
../stm32drivers/LIFO.c \
../stm32drivers/MPU6050.c \
../stm32drivers/STM32_I2C_DRIVER.c \
../stm32drivers/STM32_TIMERS_DRIVER.c \
../stm32drivers/Triac_drimmer.c \
../stm32drivers/keypad.c \
../stm32drivers/stm32_speed_DRIVER.c \
../stm32drivers/stm32f103c6_ADC.c \
../stm32drivers/stm32f103c6_ISR_DRIVER.c \
../stm32drivers/stm32f103c6_SPI_DRIVER.c \
../stm32drivers/stm32f103c6_USART_SRIVER.c 

OBJS += \
./stm32drivers/CLICK_MODE.o \
./stm32drivers/EEPROM.o \
./stm32drivers/FIFO.o \
./stm32drivers/GPIO_DRIVER.o \
./stm32drivers/I2C_LCD.o \
./stm32drivers/LCD.o \
./stm32drivers/LIFO.o \
./stm32drivers/MPU6050.o \
./stm32drivers/STM32_I2C_DRIVER.o \
./stm32drivers/STM32_TIMERS_DRIVER.o \
./stm32drivers/Triac_drimmer.o \
./stm32drivers/keypad.o \
./stm32drivers/stm32_speed_DRIVER.o \
./stm32drivers/stm32f103c6_ADC.o \
./stm32drivers/stm32f103c6_ISR_DRIVER.o \
./stm32drivers/stm32f103c6_SPI_DRIVER.o \
./stm32drivers/stm32f103c6_USART_SRIVER.o 

C_DEPS += \
./stm32drivers/CLICK_MODE.d \
./stm32drivers/EEPROM.d \
./stm32drivers/FIFO.d \
./stm32drivers/GPIO_DRIVER.d \
./stm32drivers/I2C_LCD.d \
./stm32drivers/LCD.d \
./stm32drivers/LIFO.d \
./stm32drivers/MPU6050.d \
./stm32drivers/STM32_I2C_DRIVER.d \
./stm32drivers/STM32_TIMERS_DRIVER.d \
./stm32drivers/Triac_drimmer.d \
./stm32drivers/keypad.d \
./stm32drivers/stm32_speed_DRIVER.d \
./stm32drivers/stm32f103c6_ADC.d \
./stm32drivers/stm32f103c6_ISR_DRIVER.d \
./stm32drivers/stm32f103c6_SPI_DRIVER.d \
./stm32drivers/stm32f103c6_USART_SRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
stm32drivers/CLICK_MODE.o: ../stm32drivers/CLICK_MODE.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/CLICK_MODE.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/EEPROM.o: ../stm32drivers/EEPROM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/FIFO.o: ../stm32drivers/FIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/GPIO_DRIVER.o: ../stm32drivers/GPIO_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/I2C_LCD.o: ../stm32drivers/I2C_LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/I2C_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/LCD.o: ../stm32drivers/LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/LIFO.o: ../stm32drivers/LIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/LIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/MPU6050.o: ../stm32drivers/MPU6050.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/MPU6050.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/STM32_I2C_DRIVER.o: ../stm32drivers/STM32_I2C_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/STM32_I2C_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/STM32_TIMERS_DRIVER.o: ../stm32drivers/STM32_TIMERS_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/STM32_TIMERS_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/Triac_drimmer.o: ../stm32drivers/Triac_drimmer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/Triac_drimmer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/keypad.o: ../stm32drivers/keypad.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/stm32_speed_DRIVER.o: ../stm32drivers/stm32_speed_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/stm32_speed_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/stm32f103c6_ADC.o: ../stm32drivers/stm32f103c6_ADC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/stm32f103c6_ADC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/stm32f103c6_ISR_DRIVER.o: ../stm32drivers/stm32f103c6_ISR_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/stm32f103c6_ISR_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/stm32f103c6_SPI_DRIVER.o: ../stm32drivers/stm32f103c6_SPI_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/stm32f103c6_SPI_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32drivers/stm32f103c6_USART_SRIVER.o: ../stm32drivers/stm32f103c6_USART_SRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I"C:/E/embedded/مجلد جديد/Master-Embedded-System-Diploma/RC_CAR/RC_CAR/stm32drivers/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32drivers/stm32f103c6_USART_SRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

