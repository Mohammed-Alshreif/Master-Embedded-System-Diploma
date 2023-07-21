/*
 * WS2812b_LED.h
 *
 *  Created on: Jul 21, 2023
 *      Author: 20102
 */

#ifndef STM32F013C8_DRIVERS_INC_WS2812B_LED_H_
#define STM32F013C8_DRIVERS_INC_WS2812B_LED_H_

#include "STM32_TIMERS_DRIVER.h"
#include "stm32_speed_DRIVER.h"


//======
#define WS2812b_LED_PORT GPIOA
#define WS2812b_LED_PIN  pin1
//======
#define WS2812b_SENSOR_PORT GPIOA
#define WS2812b_SENSOR_PIN  pin4


//==============================
//******************************
//==============================




static uint16_t arr[3][8]={
		{155,0,0,255,0,0,50,20},
		{155,155,0,0,255,0,50,100},
		{0,0,255,155,0,155,34,55}};

static uint8_t A[8][5] = {
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
};
static uint8_t O[8][5] = {
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1}
};
static uint8_t H[8][5] = {
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1}
};
static uint8_t E[8][5] = {
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1}
};
static uint8_t M[8][5] = {
		{1, 1, 0, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1}
};
static uint8_t D[8][5] = {
		{1, 1, 1, 0, 0},
		{1, 0, 0, 1, 0},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 1, 0},
		{1, 1, 1, 0, 0}
};
static uint8_t sp[8][5] = {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
};
static uint8_t R[8][5] = {
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 0, 0},
		{1, 0, 1, 0, 0},
		{1, 0, 0, 1, 0},
		{1, 0, 0, 0, 1},
};
static uint8_t T[8][5] = {
		{1, 1, 1, 1, 1},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
};
static uint8_t S[8][5] = {
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
};
static uint8_t C[8][5] = {
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
};
static uint8_t L[8][5] =  {
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1}
};
static uint8_t I[8][5] =  {
		{1, 1, 1, 1, 1},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{1, 1, 1, 1, 1}
};
static uint8_t N[8][5] =  {
		{1, 1, 0, 0, 1},
		{1, 1, 0, 0, 1},
		{1, 1, 0, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 0, 1, 1},
		{1, 0, 0, 1, 1},
		{1, 0, 0, 1, 1}
};
static uint8_t P[8][5] =  {
		{1, 1, 1, 1, 0},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0}
};




//==============================
//*************API**************
//==============================

void WS2812b_LED_INIT();

void sendColor(uint8_t r, uint8_t g, uint8_t b);

#endif /* STM32F013C8_DRIVERS_INC_WS2812B_LED_H_ */
