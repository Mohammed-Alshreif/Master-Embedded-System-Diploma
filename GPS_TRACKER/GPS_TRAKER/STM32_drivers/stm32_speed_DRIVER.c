/*
 * stm32_speed_DRIVER.c
 *
 *  Created on: Sep 27, 2022
 *      Author: mo
 */

#include "stm32_speed_DRIVER.h"
#define FLASH_BASE_ADDR     0x40022000
#define FLASH_ACR_OFFSET    0x00
#define FLASH_ACR          (*(volatile unsigned int*)(FLASH_BASE_ADDR + FLASH_ACR_OFFSET))
#define FLASH_ACR_LATENCY_Pos 0
void MCAL_speed_init(uint8_t CLK_SORC,uint8_t mood){
	if(CLK_SORC==CLK_SORC_IN_CLK8MHz){
		if(mood==mood_FAST_MOOD_36MHzCORE){
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
		if(mood==mood_FAST_MOOD_72MHzCORE36MHzpref){


			//			Bit 16 HSEON: HSE clock enable
			//			Set and cleared by software.
			//			Cleared by hardware to stop the HSE oscillator when entering Stop or Standby mode. This
			//			bit cannot be reset if the HSE oscillator is used directly or indirectly as the system clock.
			//			0: HSE oscillator OFF
			//			1: HSE oscillator ON
			RCC->RCC_CR |= (1 << 16);
			//			Bit 17 HSERDY: External high-speed clock ready flag
			//			Set by hardware to indicate that the HSE oscillator is stable. This bit needs 6 cycles of the
			//			HSE oscillator clock to fall down after HSEON reset.
			//			0: HSE oscillator not ready
			//			1: HSE oscillator ready
			while (!(RCC->RCC_CR & (1 << 17)));



			//			Bit 18 HSEBYP: External high-speed clock bypass
			//			Set and cleared by software to bypass the oscillator with an external clock. The external
			//			clock must be enabled with the HSEON bit set, to be used by the device. The HSEBYP bit
			//			can be written only if the HSE oscillator is disabled.
			//			0: external 4-16 MHz oscillator not bypassed
			//			1: external 4-16 MHz oscillator bypassed with external clock
			//===RCC->RCC_CR &=~(1<<18);

			//			Bit 16 HSEON: HSE clock enable
			//			Set and cleared by software.
			//			Cleared by hardware to stop the HSE oscillator when entering Stop or Standby mode. This
			//			bit cannot be reset if the HSE oscillator is used directly or indirectly as the system clock.
			//			0: HSE oscillator OFF
			//			1: HSE oscillator ON
			//===RCC->RCC_CR|=(1<<16);

			//			Bit 17 PLLXTPRE: HSE divider for PLL entry
			//			Set and cleared by software to divide HSE before PLL entry. This bit can be written only
			//			when PLL is disabled.
			//			0: HSE clock not divided
			//			1: HSE clock divided by 2

			//			Bit 16 PLLSRC: PLL entry clock source
			//			Set and cleared by software to select PLL clock source. This bit can be written only when
			//			PLL is disabled.
			//			0: HSI oscillator clock / 2 selected as PLL input clock
			//			1: HSE oscillator clock selected as PLL input clock
			RCC->RCC_CFGR|=(1<<16);

			RCC->RCC_CFGR|=(0b0111<<18);//0111: PLL input clock x 9

			//Bit 24 PLLON: PLL enable
			//			Set and cleared by software to enable PLL.
			//			Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
			//			PLL clock is used as system clock or is selected to become the system clock.
			//			0: PLL OFF
			//			1: PLL ON
			RCC->RCC_CR |=(1<<24);//pll on
			while (!(RCC->RCC_CR & (1 << 25)));


//			Bits 2:0 LATENCY: Latency
//			These bits represent the ratio of the SYSCLK (system clock) period to the Flash access
//			time.
//			000 Zero wait state, if 0 < SYSCLK≤ 24 MHz
//			001 One wait state, if 24 MHz < SYSCLK ≤ 48 MHz
//			010 Two wait states, if 48 MHz < SYSCLK ≤72 MHz
			// Configure Flash memory latency
			FLASH_ACR &= ~(0x7 << FLASH_ACR_LATENCY_Pos); // Clear LATENCY bits
			FLASH_ACR |= (2 << FLASH_ACR_LATENCY_Pos); // Set latency to 2 wait states for 72 MHz


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
			RCC->RCC_CFGR |=(0b1000<<4);//1000: SYSCLK divided by 2


			//			Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)
			//			Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
			//			0xx: HCLK not divided
			//			100: HCLK divided by 2
			//			101: HCLK divided by 4
			//			110: HCLK divided by 8
			//			111: HCLK divided by 16
			RCC->RCC_CFGR &=~(0b111<<11);//100: HCLK divided by 2

			//			Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
			//			Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
			//			0xx: HCLK not divided
			//			100: HCLK divided by 2
			//			101: HCLK divided by 4
			//			110: HCLK divided by 8
			//			111: HCLK divided by 16
			RCC->RCC_CFGR &=~(0b111<<8);//100: HCLK divided by 2



		}
		else if (mood==mood_FAST_MOOD_72MHzCORE72MHzpref){

			//			Bit 16 HSEON: HSE clock enable
			//			Set and cleared by software.
			//			Cleared by hardware to stop the HSE oscillator when entering Stop or Standby mode. This
			//			bit cannot be reset if the HSE oscillator is used directly or indirectly as the system clock.
			//			0: HSE oscillator OFF
			//			1: HSE oscillator ON
			RCC->RCC_CR |= (1 << 16);
			//			Bit 17 HSERDY: External high-speed clock ready flag
			//			Set by hardware to indicate that the HSE oscillator is stable. This bit needs 6 cycles of the
			//			HSE oscillator clock to fall down after HSEON reset.
			//			0: HSE oscillator not ready
			//			1: HSE oscillator ready
			while (!(RCC->RCC_CR & (1 << 17)));



			//			Bit 18 HSEBYP: External high-speed clock bypass
			//			Set and cleared by software to bypass the oscillator with an external clock. The external
			//			clock must be enabled with the HSEON bit set, to be used by the device. The HSEBYP bit
			//			can be written only if the HSE oscillator is disabled.
			//			0: external 4-16 MHz oscillator not bypassed
			//			1: external 4-16 MHz oscillator bypassed with external clock
			//===RCC->RCC_CR &=~(1<<18);

			//			Bit 16 HSEON: HSE clock enable
			//			Set and cleared by software.
			//			Cleared by hardware to stop the HSE oscillator when entering Stop or Standby mode. This
			//			bit cannot be reset if the HSE oscillator is used directly or indirectly as the system clock.
			//			0: HSE oscillator OFF
			//			1: HSE oscillator ON
			//===RCC->RCC_CR|=(1<<16);

			//			Bit 17 PLLXTPRE: HSE divider for PLL entry
			//			Set and cleared by software to divide HSE before PLL entry. This bit can be written only
			//			when PLL is disabled.
			//			0: HSE clock not divided
			//			1: HSE clock divided by 2

			//			Bit 16 PLLSRC: PLL entry clock source
			//			Set and cleared by software to select PLL clock source. This bit can be written only when
			//			PLL is disabled.
			//			0: HSI oscillator clock / 2 selected as PLL input clock
			//			1: HSE oscillator clock selected as PLL input clock
			RCC->RCC_CFGR|=(1<<16);

			RCC->RCC_CFGR|=(0b0111<<18);//0111: PLL input clock x 9

			//Bit 24 PLLON: PLL enable
			//			Set and cleared by software to enable PLL.
			//			Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
			//			PLL clock is used as system clock or is selected to become the system clock.
			//			0: PLL OFF
			//			1: PLL ON
			RCC->RCC_CR |=(1<<24);//pll on
			while (!(RCC->RCC_CR & (1 << 25)));


//			Bits 2:0 LATENCY: Latency
//			These bits represent the ratio of the SYSCLK (system clock) period to the Flash access
//			time.
//			000 Zero wait state, if 0 < SYSCLK≤ 24 MHz
//			001 One wait state, if 24 MHz < SYSCLK ≤ 48 MHz
//			010 Two wait states, if 48 MHz < SYSCLK ≤72 MHz
			// Configure Flash memory latency
			FLASH_ACR &= ~(0x7 << FLASH_ACR_LATENCY_Pos); // Clear LATENCY bits
			FLASH_ACR |= (2 << FLASH_ACR_LATENCY_Pos); // Set latency to 2 wait states for 72 MHz


			RCC->RCC_CFGR &=~(0b11<<0);
			RCC->RCC_CFGR |=(0b10<<0);//10: PLL selected as system clock

		}
		else{

		}
	}


}
