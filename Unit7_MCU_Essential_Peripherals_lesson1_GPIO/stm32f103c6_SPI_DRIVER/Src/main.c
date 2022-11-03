/**
 ******************************************************************************
 * @file           : main.c
 * @author         : MO_ALSHREIF
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

#include "STM32f103c6.h"
#include "GPIO_DRIVER.h"
#include "stm32f103c6_SPI_DRIVER.h"
#include "stm32f103c6_USART_SRIVER.h"
#include "stm32_speed_DRIVER.h"
uint16_t uart1_c='1';
uint16_t uart2_c='2';
uint16_t uart3_c='3';

uint16_t spi1_c='1';


void uart1_calback (void){
	//pinwrite(GPIOB, pin0,HIGH);
	USART_READ(USART1,&uart1_c);
	_delay_ms(10);
	USART_SEND(USART1,&uart1_c);
	//pinwrite(GPIOB, pin0,LOW);
}
void uart2_calback (void){
	//pinwrite(GPIOB, pin0,HIGH);
	USART_READ(USART2,&uart2_c);
	_delay_ms(10);
	USART_SEND(USART2,&uart2_c);
	//pinwrite(GPIOB, pin0,LOW);
}
void uart3_calback (void){
	//pinwrite(GPIOB, pin0,HIGH);
	USART_READ(USART3,&uart3_c);
	_delay_ms(10);
	USART_SEND(USART3,&uart3_c);
	//pinwrite(GPIOB, pin0,LOW);
}
int main(void)
{
	//MCAL_speed_init(CLK_SORC_IN_CLK8MHz, mood_FAST_MOOD_72MHzCORE);
	GPIOB_Clock_Enable();
	pinmode(GPIOB, pin1,GPIO_MODE_OUTPUT_push_pull_Speed10);
	SPI_INIT(SPI1, SPI_MODE_MASTER_unidirectional_receive_only, prescaler_256, Clock_polarity_idle_one, Clock_phase_first_clock_transition, frame_size_16, Frame_format_MSB);
	//SPI_SEND(SPI1,&ch);

	USART_INIT(USART1, mode_RX_TX_ENABLE, word_length_8, stop_bits_1, baud_rate_9600, parity_none,8000000);
	USART_INIT(USART2, mode_RX_TX_ENABLE, word_length_9, stop_bits_2, baud_rate_9600, parity_even,8000000);
	USART_INIT(USART3, mode_RX_TX_ENABLE, word_length_9, stop_bits_2, baud_rate_9600, parity_even,8000000);

	USART_READ_INTERRUPT_EN(USART1, uart1_calback);
	USART_READ_INTERRUPT_EN(USART2, uart2_calback);
	USART_READ_INTERRUPT_EN(USART3, uart3_calback);

	pinmode(GPIOA, pin4,GPIO_MODE_OUTPUT_push_pull_Speed10);//ss 1
	pinwrite(GPIOA, pin4, HIGH);
	char text[5];
	while(1){
		USART_SEND_STRING(USART2," mohammed alshreif ");
		//_delay_ms(1000);
		USART_SEND_STRING(USART1," \n ");
		//_delay_ms(1000);
		USART_SEND_STRING(USART3," mohammed alshreif ");
		_delay_ms(1400);

		SPI_RECEIVE_ONLY_MODE(SPI1,&spi1_c,pin4);//spi
		spi1_c=(spi1_c>>4);

		sprintf(text,"%d",spi1_c);

		USART_SEND_STRING(USART1,text);
		USART_SEND(USART2,&uart2_c);
		USART_SEND(USART3,&uart3_c) ;
		_delay_ms(1400);
	}


}
