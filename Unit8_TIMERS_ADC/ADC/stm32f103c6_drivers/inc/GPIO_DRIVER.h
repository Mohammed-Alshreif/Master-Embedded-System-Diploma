/*
 * GPIO_DRIVER.h
 *
 *  Created on: Sep 21, 2022
 *      Author: 20102
 */

#ifndef INC_GPIO_DRIVER_H_
#define INC_GPIO_DRIVER_H_
//include     ============================
#include "STM32f103c6.h"

//========================================

#define pin0  0
#define pin1  1
#define pin2  2
#define pin3  3
#define pin4  4
#define pin5  5
#define pin6  6
#define pin7  7
#define pin8  8
#define pin9  9
#define pin10 10
#define pin11 11
#define pin12 12
#define pin13 13
#define pin14 14
#define pin15 15

//*******************************
//pin modes
//*******************************
//CNFy[1:0]: Port x configuration bits (y= 0 .. 7)
//These bits are written by software to configure the corresponding I/O port.
//Refer to Table 20: Port bit configuration table.
//In input mode (MODE[1:0]=00):
//00: Analog mode
//01: Floating input (reset state)
//10: Input with pull-up / pull-down
//11: Reserved
//In output mode (MODE[1:0] > 00):
//00: General purpose output push-pull
//01: General purpose output Open-drain
//10: Alternate function output Push-pull
//11: Alternate function output Open-drain
//Bits 29:28, 25:24,
//21:20, 17:16, 13:12,
//9:8, 5:4, 1:0
//MODEy[1:0]: Port x mode bits (y= 0 .. 7)
//These bits are written by software to configure the corresponding I/O port.
//Refer to Table 20: Port bit configuration table.
//00: General purpose output push-pull
//01: General purpose output Open-drain
//10: Alternate function output Push-pull
//11: Alternate function output Open-drain
//00: Input mode (reset state)
//01: Output mode, max speed 10 MHz.
//10: Output mode, max speed 2 MHz.
//11: Output mode, max speed 50 MHz.

#define GPIO_MODE_ANALOG			   				0b0000     // 00: Analog mode 00: Input mode (reset state)
#define GPIO_MODE_INPUT_FLO			   				0b0100    //01: Floating input (reset state) 00: Input mode (reset state)
#define GPIO_MODE_INPUT_PU							0b11000  // 10: Input with pull-up  00: Input mode (reset state)
#define GPIO_MODE_INPUT_PD							0b01000 //10: Input with  pull-down  00: Input mode (reset state)
#define GPIO_MODE_INTPUT_AF		       			 	0b0100 // 00: Input mode (reset state)

#define GPIO_MODE_OUTPUT_push_pull_Speed10			0b0001  //00: General purpose output push-pull
#define GPIO_MODE_OUTPUT_push_pull_Speed2			0b0010 //00: General purpose output push-pull
#define GPIO_MODE_OUTPUT_push_pull_Speed50			0b0011//00: General purpose output push-pull

#define GPIO_MODE_OUTPUT_Open_drain_Speed10			0b0101  //01: General purpose output Open-drain
#define GPIO_MODE_OUTPUT_Open_drain_Speed2			0b0110 //01: General purpose output Open-drain
#define GPIO_MODE_OUTPUT_Open_drain_Speed50			0b0111//01: General purpose output Open-drain

#define GPIO_MODE_OUTPUT_AF_push_pull_Speed10		0b1001  //10: Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_push_pull_Speed2		0b1010 //10: Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_push_pull_Speed50		0b1011//10: Alternate function output Push-pull

#define GPIO_MODE_OUTPUT_AF_Open_drain_Speed10		0b1101  //11: Alternate function output Open-drain
#define GPIO_MODE_OUTPUT_AF_Open_drain_Speed2		0b1110 //11: Alternate function output Open-drain
#define GPIO_MODE_OUTPUT_AF_Open_drain_Speed50		0b1111//11: Alternate function output Open-drain


//=====================================================
#define HIGH 1
#define LOW  0

//*************************
 //API   ==  ==  ==  ==  ==
//*************************

void pinmode(GPIO_typeDef* GPIOx,uint16_t pin,uint32_t pinmode);//port , pin , mode
void pinwrite(GPIO_typeDef* GPIOx,uint16_t pin,uint8_t status);
void WRITE_PORT(GPIO_typeDef* GPIOx,uint16_t status);
void set_Value_PORT(GPIO_typeDef* GPIOx,uint16_t status,uint16_t position);
void res_Value_PORT(GPIO_typeDef* GPIOx,uint16_t status,uint16_t position);
uint8_t READ_PIN(GPIO_typeDef* GPIOx, uint16_t pin);
uint16_t READ_PORT(GPIO_typeDef* GPIOx);
void TogglePin(GPIO_typeDef* GPIOx, uint16_t pin);
uint8_t MCAL_GPIO_LockPin(GPIO_typeDef* GPIOx, uint16_t pin_number);
#endif /* INC_GPIO_DRIVER_H_ */
