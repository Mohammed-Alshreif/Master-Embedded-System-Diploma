/*
 * STM32_I2C_DRIVER.h
 *
 *  Created on: Nov 5, 2022
 *      Author: 20102
 */

#ifndef STM32F103C6_DRIVERS_INC_STM32_I2C_DRIVER_H_
#define STM32F103C6_DRIVERS_INC_STM32_I2C_DRIVER_H_
#include "stdio.h"
#include "stdlib.h"
#include "STM32f103c6.h"
#include "GPIO_DRIVER.h"
//===========================================================================
#define i2c_direction_Read  1
#define i2c_direction_Write 0

//===========================================================================
typedef enum
{
	WithStop,
	WithoutStop

}Stop_Condition;


typedef enum
{
	Start,
	RepeatedSart

}Repeated_Start;

typedef enum {DISABLE , ENABLE } FunctionalState;
typedef enum {RESET , SET } FlagStatus;

typedef enum
{
	I2C_FLAG_BUSY,
	EV5,      //EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	EV6,      //: ADDR=1, cleared by reading SR1 register followed by reading SR2
	EV8,	//EV8: TxE=1, shift register not empty, d . ata register empty, cleared by writing DR register
	EV8_1,
	EV8_2,	//EV8_2: TxE=1, BTF = 1, Program Stop request. TxE and BTF are cleared by hardware by the Stop condition
	EV7,   //RXNE=1
	MASTER_BYTE_TRANSMITING  = 0x00070080 //4. Busy MSL TXE TRA

}Status;
//===========================================================================
//PB10 I2C2 SCL  //PB11 I2C2 SDA
//PB6 I2C1 SCL  //PB7 I2C1 SDA
void I2C_INIT(I2C_TypeDef* I2Cx,uint32_t APB_clock);

void I2C_Start_PIT(I2C_TypeDef* I2Cx,Repeated_Start Start);

void I2C_Stop_PIT(I2C_TypeDef* I2Cx);

void I2C_Master_Send(I2C_TypeDef* I2Cx,uint8_t* data, uint32_t dataLen,uint16_t devAdd,Stop_Condition Stop , Repeated_Start start);

void I2C_Master_Recive(I2C_TypeDef* I2Cx,uint8_t* data, uint32_t dataLen,uint16_t devAdd,Stop_Condition Stop , Repeated_Start start);

FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, Status Flag);

void I2C_SEND_ADRRESS(I2C_TypeDef* I2Cx,uint8_t address,uint8_t i2c_direction);

void I2C_Acknowledge(I2C_TypeDef *I2Cx,FunctionalState State);

#endif /* STM32F103C6_DRIVERS_INC_STM32_I2C_DRIVER_H_ */
