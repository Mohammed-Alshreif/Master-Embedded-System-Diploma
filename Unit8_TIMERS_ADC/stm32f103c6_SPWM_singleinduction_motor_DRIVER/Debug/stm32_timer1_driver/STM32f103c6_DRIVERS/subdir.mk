################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32_timer1_driver/STM32f103c6_DRIVERS/GPIO_DRIVER.c \
../stm32_timer1_driver/STM32f103c6_DRIVERS/LCD.c \
../stm32_timer1_driver/STM32f103c6_DRIVERS/keypad.c \
../stm32_timer1_driver/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.c \
../stm32_timer1_driver/STM32f103c6_DRIVERS/stm32_speed_DRIVER.c \
../stm32_timer1_driver/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.c 

OBJS += \
./stm32_timer1_driver/STM32f103c6_DRIVERS/GPIO_DRIVER.o \
./stm32_timer1_driver/STM32f103c6_DRIVERS/LCD.o \
./stm32_timer1_driver/STM32f103c6_DRIVERS/keypad.o \
./stm32_timer1_driver/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.o \
./stm32_timer1_driver/STM32f103c6_DRIVERS/stm32_speed_DRIVER.o \
./stm32_timer1_driver/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.o 

C_DEPS += \
./stm32_timer1_driver/STM32f103c6_DRIVERS/GPIO_DRIVER.d \
./stm32_timer1_driver/STM32f103c6_DRIVERS/LCD.d \
./stm32_timer1_driver/STM32f103c6_DRIVERS/keypad.d \
./stm32_timer1_driver/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.d \
./stm32_timer1_driver/STM32f103c6_DRIVERS/stm32_speed_DRIVER.d \
./stm32_timer1_driver/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
stm32_timer1_driver/STM32f103c6_DRIVERS/GPIO_DRIVER.o: ../stm32_timer1_driver/STM32f103c6_DRIVERS/GPIO_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/stm32f103c6_TIMER1_DRIVER/stm32_timer1_driver/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_timer1_driver/STM32f103c6_DRIVERS/GPIO_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32_timer1_driver/STM32f103c6_DRIVERS/LCD.o: ../stm32_timer1_driver/STM32f103c6_DRIVERS/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/stm32f103c6_TIMER1_DRIVER/stm32_timer1_driver/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_timer1_driver/STM32f103c6_DRIVERS/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32_timer1_driver/STM32f103c6_DRIVERS/keypad.o: ../stm32_timer1_driver/STM32f103c6_DRIVERS/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/stm32f103c6_TIMER1_DRIVER/stm32_timer1_driver/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_timer1_driver/STM32f103c6_DRIVERS/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32_timer1_driver/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.o: ../stm32_timer1_driver/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/stm32f103c6_TIMER1_DRIVER/stm32_timer1_driver/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_timer1_driver/STM32f103c6_DRIVERS/stm32_TIMER1_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32_timer1_driver/STM32f103c6_DRIVERS/stm32_speed_DRIVER.o: ../stm32_timer1_driver/STM32f103c6_DRIVERS/stm32_speed_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/stm32f103c6_TIMER1_DRIVER/stm32_timer1_driver/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_timer1_driver/STM32f103c6_DRIVERS/stm32_speed_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32_timer1_driver/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.o: ../stm32_timer1_driver/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/Unit7_MCU_Essential_Peripherals_lesson1_GPIO/stm32f103c6_TIMER1_DRIVER/stm32_timer1_driver/STM32f103c6_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_timer1_driver/STM32f103c6_DRIVERS/stm32f103c6_ISR_DRIVER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

