################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_Drivers/CLICK_MODE.c \
../STM32_Drivers/EEPROM.c \
../STM32_Drivers/FIFO.c \
../STM32_Drivers/GPIO_DRIVER.c \
../STM32_Drivers/I2C_LCD.c \
../STM32_Drivers/LCD.c \
../STM32_Drivers/LIFO.c \
../STM32_Drivers/MPU6050.c \
../STM32_Drivers/STM32_I2C_DRIVER.c \
../STM32_Drivers/STM32_TIMERS_DRIVER.c \
../STM32_Drivers/Triac_drimmer.c \
../STM32_Drivers/keypad.c \
../STM32_Drivers/stm32_speed_DRIVER.c \
../STM32_Drivers/stm32f103c6_ADC.c \
../STM32_Drivers/stm32f103c6_ISR_DRIVER.c \
../STM32_Drivers/stm32f103c6_SPI_DRIVER.c \
../STM32_Drivers/stm32f103c6_USART_SRIVER.c 

OBJS += \
./STM32_Drivers/CLICK_MODE.o \
./STM32_Drivers/EEPROM.o \
./STM32_Drivers/FIFO.o \
./STM32_Drivers/GPIO_DRIVER.o \
./STM32_Drivers/I2C_LCD.o \
./STM32_Drivers/LCD.o \
./STM32_Drivers/LIFO.o \
./STM32_Drivers/MPU6050.o \
./STM32_Drivers/STM32_I2C_DRIVER.o \
./STM32_Drivers/STM32_TIMERS_DRIVER.o \
./STM32_Drivers/Triac_drimmer.o \
./STM32_Drivers/keypad.o \
./STM32_Drivers/stm32_speed_DRIVER.o \
./STM32_Drivers/stm32f103c6_ADC.o \
./STM32_Drivers/stm32f103c6_ISR_DRIVER.o \
./STM32_Drivers/stm32f103c6_SPI_DRIVER.o \
./STM32_Drivers/stm32f103c6_USART_SRIVER.o 

C_DEPS += \
./STM32_Drivers/CLICK_MODE.d \
./STM32_Drivers/EEPROM.d \
./STM32_Drivers/FIFO.d \
./STM32_Drivers/GPIO_DRIVER.d \
./STM32_Drivers/I2C_LCD.d \
./STM32_Drivers/LCD.d \
./STM32_Drivers/LIFO.d \
./STM32_Drivers/MPU6050.d \
./STM32_Drivers/STM32_I2C_DRIVER.d \
./STM32_Drivers/STM32_TIMERS_DRIVER.d \
./STM32_Drivers/Triac_drimmer.d \
./STM32_Drivers/keypad.d \
./STM32_Drivers/stm32_speed_DRIVER.d \
./STM32_Drivers/stm32f103c6_ADC.d \
./STM32_Drivers/stm32f103c6_ISR_DRIVER.d \
./STM32_Drivers/stm32f103c6_SPI_DRIVER.d \
./STM32_Drivers/stm32f103c6_USART_SRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_Drivers/CLICK_MODE.o: ../STM32_Drivers/CLICK_MODE.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/CLICK_MODE.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/EEPROM.o: ../STM32_Drivers/EEPROM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/FIFO.o: ../STM32_Drivers/FIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/GPIO_DRIVER.o: ../STM32_Drivers/GPIO_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/I2C_LCD.o: ../STM32_Drivers/I2C_LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/I2C_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/LCD.o: ../STM32_Drivers/LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/LIFO.o: ../STM32_Drivers/LIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/LIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/MPU6050.o: ../STM32_Drivers/MPU6050.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/MPU6050.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/STM32_I2C_DRIVER.o: ../STM32_Drivers/STM32_I2C_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/STM32_I2C_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/STM32_TIMERS_DRIVER.o: ../STM32_Drivers/STM32_TIMERS_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/STM32_TIMERS_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/Triac_drimmer.o: ../STM32_Drivers/Triac_drimmer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/Triac_drimmer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/keypad.o: ../STM32_Drivers/keypad.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/stm32_speed_DRIVER.o: ../STM32_Drivers/stm32_speed_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/stm32_speed_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/stm32f103c6_ADC.o: ../STM32_Drivers/stm32f103c6_ADC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/stm32f103c6_ADC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/stm32f103c6_ISR_DRIVER.o: ../STM32_Drivers/stm32f103c6_ISR_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/stm32f103c6_ISR_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/stm32f103c6_SPI_DRIVER.o: ../STM32_Drivers/stm32f103c6_SPI_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/stm32f103c6_SPI_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/stm32f103c6_USART_SRIVER.o: ../STM32_Drivers/stm32f103c6_USART_SRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/stm32f103c6_USART_SRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

