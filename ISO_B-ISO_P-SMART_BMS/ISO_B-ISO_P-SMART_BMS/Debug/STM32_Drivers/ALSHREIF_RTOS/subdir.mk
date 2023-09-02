################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_Drivers/ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.c \
../STM32_Drivers/ALSHREIF_RTOS/RTOS_FIFO.c \
../STM32_Drivers/ALSHREIF_RTOS/SCEDULER.c 

OBJS += \
./STM32_Drivers/ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.o \
./STM32_Drivers/ALSHREIF_RTOS/RTOS_FIFO.o \
./STM32_Drivers/ALSHREIF_RTOS/SCEDULER.o 

C_DEPS += \
./STM32_Drivers/ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.d \
./STM32_Drivers/ALSHREIF_RTOS/RTOS_FIFO.d \
./STM32_Drivers/ALSHREIF_RTOS/SCEDULER.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_Drivers/ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.o: ../STM32_Drivers/ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/ALSHREIF_RTOS/RTOS_CORTEX_M3_PORTING.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/ALSHREIF_RTOS/RTOS_FIFO.o: ../STM32_Drivers/ALSHREIF_RTOS/RTOS_FIFO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/ALSHREIF_RTOS/RTOS_FIFO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_Drivers/ALSHREIF_RTOS/SCEDULER.o: ../STM32_Drivers/ALSHREIF_RTOS/SCEDULER.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/CMSIS" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/ALSHREIF_RTOS/INC" -I"C:/E/embedded/test/final simulation code for my assignments/ISO_B-ISO_P-SMART_BMS/ISO_B-ISO_P-SMART_BMS/STM32_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_Drivers/ALSHREIF_RTOS/SCEDULER.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

