/**
 ******************************************************************************
 * @file           : main.c
 * @author         : mo alshreif
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "stm32f103c6_USART_SRIVER.h"
#include "stm32_speed_DRIVER.h"
#include "GPIO_DRIVER.h"

int i=0;
unsigned char ch;
void momo (){
	pinwrite(GPIOB, pin0,HIGH);
	USART_READ(USART1,&ch);
    _delay_ms(10);
	USART_SEND(USART1,&ch);
	pinwrite(GPIOB, pin0,LOW);
}
int main(void)
{
	MCAL_speed_init(CLK_SORC_IN_CLK8MHz, mood_FAST_MOOD_72MHzCORE);
	GPIOB_Clock_Enable();
	pinmode(GPIOB, pin0,GPIO_MODE_OUTPUT_push_pull_Speed10);
	pinmode(GPIOB, pin1,GPIO_MODE_OUTPUT_push_pull_Speed10);
	pinwrite(GPIOB, pin0,LOW);
	USART_INIT(USART1, mode_RX_TX_ENABLE, word_length_9, stop_bits_2, baud_rate_9600, parity_even,36000000);
	USART_READ_INTERRUPT_EN(USART1, momo);

	USART_SEND_STRING(USART1," mohammed alshreif ");

	while(1){
//		_delay_ms(5000);
//		USART_SEND_STRING(USART1,"mohammed");
//		_delay_ms(5000);
	}

}
