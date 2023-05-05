################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/CLICK_MODE.c \
../Src/EEPROM.c \
../Src/FIFO.c \
../Src/GPIO_DRIVER.c \
../Src/I2C_LCD.c \
../Src/LCD.c \
../Src/LIFO.c \
../Src/MPU6050.c \
../Src/STM32_I2C_DRIVER.c \
../Src/STM32_TIMERS_DRIVER.c \
../Src/keypad.c \
../Src/main.c \
../Src/stm32_speed_DRIVER.c \
../Src/stm32f103c6_ADC.c \
../Src/stm32f103c6_ISR_DRIVER.c \
../Src/stm32f103c6_SPI_DRIVER.c \
../Src/stm32f103c6_USART_SRIVER.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/CLICK_MODE.o \
./Src/EEPROM.o \
./Src/FIFO.o \
./Src/GPIO_DRIVER.o \
./Src/I2C_LCD.o \
./Src/LCD.o \
./Src/LIFO.o \
./Src/MPU6050.o \
./Src/STM32_I2C_DRIVER.o \
./Src/STM32_TIMERS_DRIVER.o \
./Src/keypad.o \
./Src/main.o \
./Src/stm32_speed_DRIVER.o \
./Src/stm32f103c6_ADC.o \
./Src/stm32f103c6_ISR_DRIVER.o \
./Src/stm32f103c6_SPI_DRIVER.o \
./Src/stm32f103c6_USART_SRIVER.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/CLICK_MODE.d \
./Src/EEPROM.d \
./Src/FIFO.d \
./Src/GPIO_DRIVER.d \
./Src/I2C_LCD.d \
./Src/LCD.d \
./Src/LIFO.d \
./Src/MPU6050.d \
./Src/STM32_I2C_DRIVER.d \
./Src/STM32_TIMERS_DRIVER.d \
./Src/keypad.d \
./Src/main.d \
./Src/stm32_speed_DRIVER.d \
./Src/stm32f103c6_ADC.d \
./Src/stm32f103c6_ISR_DRIVER.d \
./Src/stm32f103c6_SPI_DRIVER.d \
./Src/stm32f103c6_USART_SRIVER.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/CLICK_MODE.o: ../Src/CLICK_MODE.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/CLICK_MODE.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/EEPROM.o: ../Src/EEPROM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/FIFO.o: ../Src/FIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/GPIO_DRIVER.o: ../Src/GPIO_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/I2C_LCD.o: ../Src/I2C_LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/I2C_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/LCD.o: ../Src/LCD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/LIFO.o: ../Src/LIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/LIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/MPU6050.o: ../Src/MPU6050.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/MPU6050.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32_I2C_DRIVER.o: ../Src/STM32_I2C_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32_I2C_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STM32_TIMERS_DRIVER.o: ../Src/STM32_TIMERS_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STM32_TIMERS_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/keypad.o: ../Src/keypad.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/stm32_speed_DRIVER.o: ../Src/stm32_speed_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32_speed_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/stm32f103c6_ADC.o: ../Src/stm32f103c6_ADC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32f103c6_ADC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/stm32f103c6_ISR_DRIVER.o: ../Src/stm32f103c6_ISR_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32f103c6_ISR_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/stm32f103c6_SPI_DRIVER.o: ../Src/stm32f103c6_SPI_DRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32f103c6_SPI_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/stm32f103c6_USART_SRIVER.o: ../Src/stm32f103c6_USART_SRIVER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32f103c6_USART_SRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/click_mode/CLICK_MODE/Src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

