/*
 * stm32_speed_DRIVER.c
 *
 *  Created on: Sep 27, 2022
 *      Author: mo
 */

#include "stm32_speed_DRIVER.h"

void MCAL_speed_init(uint8_t CLK_SORC,uint8_t mood){
	if(CLK_SORC==CLK_SORC_IN_CLK8MHz){
		if(mood==mood_FAST_MOOD_72MHzCORE){
//			Bit 16 PLLSRC: PLL entry clock source
//			Set and cleared by software to select PLL clock source. This bit can be written only when PLL is
//			disabled.
//			0: HSI oscillator clock / 2 selected as PLL input clock
//			1: Clock from PREDIV1 selected as PLL input clock
//			Note: When changing the main PLL’s entry clock source, the original clock source must be switched
//			off only after the selection of the new clock source.

			RCC->RCC_CFGR &=~(1<<16);//0: HSI oscillator clock / 2 selected as PLL input clock

//			Bits 21:18 PLLMUL[3:0]: PLL multiplication factor
//			These bits are written by software to define the PLL multiplication factor. They can be written only
//			when PLL is disabled.
//			000x: Reserved
//			0010: PLL input clock x 4
//			0011: PLL input clock x 5
//			0100: PLL input clock x 6
//			0101: PLL input clock x 7
//			0110: PLL input clock x 8
//			0111: PLL input clock x 9
//			10xx: Reserved
//			1100: Reserved
//			1101: PLL input clock x 6.5
//			111x: Reserved

			RCC->RCC_CFGR &=~(0b1111<<18);
			RCC->RCC_CFGR |=(0b0111<<18);//0111: PLL input clock x 9
			RCC->RCC_CR |=(1<<24);//pll on
			//SW[1:0]: System clock Switch
			//Set and cleared by software to select SYSCLK source.
			//Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of failure of
			//the HSE oscillator used directly or indirectly as system clock (if the Clock Security System is
			//enabled).
			//00: HSI selected as system clock
			//01: HSE selected as system clock
			//10: PLL selected as system clock
			//11: Not allowed

			RCC->RCC_CFGR &=~(0b11<<0);
			RCC->RCC_CFGR |=(0b10<<0);//10: PLL selected as system clock
			//			HPRE[3:0]: AHB prescaler
			//			Set and cleared by software to control AHB clock division factor.
			//			0xxx: SYSCLK not divided
			//			1000: SYSCLK divided by 2
			//			1001: SYSCLK divided by 4
			//			1010: SYSCLK divided by 8
			//			1011: SYSCLK divided by 16
			//			1100: SYSCLK divided by 64
			//			1101: SYSCLK divided by 128
			//			1110: SYSCLK divided by 256
			//			1111: SYSCLK divided by 512
			RCC->RCC_CFGR &=~(0b1111<<4);//0xxx: SYSCLK not divided


			//			Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)
			//			Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
			//			0xx: HCLK not divided
			//			100: HCLK divided by 2
			//			101: HCLK divided by 4
			//			110: HCLK divided by 8
			//			111: HCLK divided by 16
			RCC->RCC_CFGR &=~(0b111<<11);//0xx: HCLK not divided

			//			Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
			//			Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
			//			0xx: HCLK not divided
			//			100: HCLK divided by 2
			//			101: HCLK divided by 4
			//			110: HCLK divided by 8
			//			111: HCLK divided by 16
			RCC->RCC_CFGR &=~(0b111<<8);//0xx: HCLK not divided

		}
		else if (mood_SLOW_MOOD_8MHzCORE){

		}
		else{
			//			SW[1:0]: System clock Switch
			//			Set and cleared by software to select SYSCLK source.
			//			Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of failure of
			//			the HSE oscillator used directly or indirectly as system clock (if the Clock Security System is
			//			enabled).
			//			00: HSI selected as system clock
			//			01: HSE selected as system clock
			//			10: PLL selected as system clock
			//			11: Not allowed

			RCC->RCC_CFGR &=~(0b11<<0);//system clk =8
			//			HPRE[3:0]: AHB prescaler
			//			Set and cleared by software to control AHB clock division factor.
			//			0xxx: SYSCLK not divided
			//			1000: SYSCLK divided by 2
			//			1001: SYSCLK divided by 4
			//			1010: SYSCLK divided by 8
			//			1011: SYSCLK divided by 16
			//			1100: SYSCLK divided by 64
			//			1101: SYSCLK divided by 128
			//			1110: SYSCLK divided by 256
			//			1111: SYSCLK divided by 512
			RCC->RCC_CFGR &=~(0b1111<<4);//0xxx: SYSCLK not divided


			//			Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)
			//			Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
			//			0xx: HCLK not divided
			//			100: HCLK divided by 2
			//			101: HCLK divided by 4
			//			110: HCLK divided by 8
			//			111: HCLK divided by 16
			RCC->RCC_CFGR &=~(0b111<<11);//0xx: HCLK not divided

			//			Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
			//			Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
			//			0xx: HCLK not divided
			//			100: HCLK divided by 2
			//			101: HCLK divided by 4
			//			110: HCLK divided by 8
			//			111: HCLK divided by 16
			RCC->RCC_CFGR &=~(0b111<<8);//0xx: HCLK not divided

		}
	}
	else{
		if(mood==mood_FAST_MOOD_72MHzCORE){

		}
		else if (mood_SLOW_MOOD_8MHzCORE){

		}
		else{

		}
	}


}
