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
unsigned char ch='s';

int main(void)
{
	SPI_INIT(SPI1, SPI_MODE_MASTER, prescaler_2, Clock_polarity_idle_one, Clock_phase_first_clock_transition, frame_size_8, Frame_format_MSB);
	//SPI_SEND(SPI1,&ch);
	//MCAL_speed_init(CLK_SORC_IN_CLK8MHz, mood_FAST_MOOD_72MHzCORE);
	USART_INIT(USART1, mode_RX_TX_ENABLE, word_length_9, stop_bits_2, baud_rate_9600, parity_even,8000000);
	//USART_READ_INTERRUPT_EN(USART1, momo);

	//USART_SEND_STRING(USART1," mohammed alshreif ");

	while(1){

		//USART_SEND_STRING(USART1,&ch);
		USART_SEND(USART1,&ch);
		_delay_ms(1000);
		SPI_SEND(SPI1,&ch);
		_delay_ms(1000);

	}


}
