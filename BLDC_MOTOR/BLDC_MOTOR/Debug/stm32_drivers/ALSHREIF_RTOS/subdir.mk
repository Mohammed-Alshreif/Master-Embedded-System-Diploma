################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32_drivers/ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.c \
../stm32_drivers/ALSHREIF_RTOS/RTOS_FIFO.c \
../stm32_drivers/ALSHREIF_RTOS/SCEDULER.c 

OBJS += \
./stm32_drivers/ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.o \
./stm32_drivers/ALSHREIF_RTOS/RTOS_FIFO.o \
./stm32_drivers/ALSHREIF_RTOS/SCEDULER.o 

C_DEPS += \
./stm32_drivers/ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.d \
./stm32_drivers/ALSHREIF_RTOS/RTOS_FIFO.d \
./stm32_drivers/ALSHREIF_RTOS/SCEDULER.d 


# Each subdirectory must supply rules for building sources it contributes
stm32_drivers/ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.o: ../stm32_drivers/ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/BLDC_MOTOR/BLDC_MOTOR/stm32_drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/BLDC_MOTOR/BLDC_MOTOR/stm32_drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/BLDC_MOTOR/BLDC_MOTOR/stm32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_drivers/ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32_drivers/ALSHREIF_RTOS/RTOS_FIFO.o: ../stm32_drivers/ALSHREIF_RTOS/RTOS_FIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/BLDC_MOTOR/BLDC_MOTOR/stm32_drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/BLDC_MOTOR/BLDC_MOTOR/stm32_drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/BLDC_MOTOR/BLDC_MOTOR/stm32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_drivers/ALSHREIF_RTOS/RTOS_FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32_drivers/ALSHREIF_RTOS/SCEDULER.o: ../stm32_drivers/ALSHREIF_RTOS/SCEDULER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/BLDC_MOTOR/BLDC_MOTOR/stm32_drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/BLDC_MOTOR/BLDC_MOTOR/stm32_drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/BLDC_MOTOR/BLDC_MOTOR/stm32_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32_drivers/ALSHREIF_RTOS/SCEDULER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

