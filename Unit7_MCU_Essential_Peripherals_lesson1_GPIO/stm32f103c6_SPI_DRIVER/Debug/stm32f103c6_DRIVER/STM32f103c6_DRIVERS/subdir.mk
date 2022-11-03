################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/GPIO_DRIVER.c \
../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/LCD.c \
../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/keypad.c \
../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.c \
../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32_speed_DRIVER.c \
../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.c \
../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_SPI_DRIVER.c \
../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_USART_SRIVER.c 

OBJS += \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/GPIO_DRIVER.o \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/LCD.o \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/keypad.o \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.o \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32_speed_DRIVER.o \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.o \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_SPI_DRIVER.o \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_USART_SRIVER.o 

C_DEPS += \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/GPIO_DRIVER.d \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/LCD.d \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/keypad.d \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.d \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32_speed_DRIVER.d \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.d \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_SPI_DRIVER.d \
./stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_USART_SRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6_DRIVER/STM32f103c6_DRIVERS/GPIO_DRIVER.o: ../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/GPIO_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/stm32f103c6_SPI_DRIVER/stm32f103c6_DRIVER/STM32f103c6_DRIVERS/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_DRIVER/STM32f103c6_DRIVERS/GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_DRIVER/STM32f103c6_DRIVERS/LCD.o: ../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/stm32f103c6_SPI_DRIVER/stm32f103c6_DRIVER/STM32f103c6_DRIVERS/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_DRIVER/STM32f103c6_DRIVERS/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_DRIVER/STM32f103c6_DRIVERS/keypad.o: ../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/stm32f103c6_SPI_DRIVER/stm32f103c6_DRIVER/STM32f103c6_DRIVERS/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_DRIVER/STM32f103c6_DRIVERS/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.o: ../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/stm32f103c6_SPI_DRIVER/stm32f103c6_DRIVER/STM32f103c6_DRIVERS/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32_speed_DRIVER.o: ../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32_speed_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/stm32f103c6_SPI_DRIVER/stm32f103c6_DRIVER/STM32f103c6_DRIVERS/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32_speed_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.o: ../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/stm32f103c6_SPI_DRIVER/stm32f103c6_DRIVER/STM32f103c6_DRIVERS/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_SPI_DRIVER.o: ../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_SPI_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/stm32f103c6_SPI_DRIVER/stm32f103c6_DRIVER/STM32f103c6_DRIVERS/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_SPI_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_USART_SRIVER.o: ../stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_USART_SRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/stm32f103c6_SPI_DRIVER/stm32f103c6_DRIVER/STM32f103c6_DRIVERS/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_DRIVER/STM32f103c6_DRIVERS/stm32f103c6_USART_SRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

