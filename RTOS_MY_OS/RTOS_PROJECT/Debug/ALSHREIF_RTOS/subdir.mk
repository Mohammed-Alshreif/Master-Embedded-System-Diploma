################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.c \
../ALSHREIF_RTOS/RTOS_FIFO.c \
../ALSHREIF_RTOS/SCEDULER.c 

OBJS += \
./ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.o \
./ALSHREIF_RTOS/RTOS_FIFO.o \
./ALSHREIF_RTOS/SCEDULER.o 

C_DEPS += \
./ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.d \
./ALSHREIF_RTOS/RTOS_FIFO.d \
./ALSHREIF_RTOS/SCEDULER.d 


# Each subdirectory must supply rules for building sources it contributes
ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.o: ../ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
ALSHREIF_RTOS/RTOS_FIFO.o: ../ALSHREIF_RTOS/RTOS_FIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"ALSHREIF_RTOS/RTOS_FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
ALSHREIF_RTOS/SCEDULER.o: ../ALSHREIF_RTOS/SCEDULER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/CMSIS" -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/RTOS_MY_OS/RTOS_PROJECT/STM32f103c8_DRIVERS/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"ALSHREIF_RTOS/SCEDULER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

