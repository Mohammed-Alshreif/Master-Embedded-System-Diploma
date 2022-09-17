/*
 * atmega32_gpio.c
 *
 * Created: 17/09/2022 01:40:53 م
 * Author : 20102
 */ 

#include <avr/io.h>
#include "memorymap.h"
#include "util/delay.h"
#define F_CPU 4000000UL

int main(void)
{
   DDRA =0xff;
    while (1) 
    {
		for(int i=0;i<8;i++)
		{
				PORTA |=(1<<i);
				_delay_ms(100);
		}
		//PORTA =0x00;
		for(int i=8;i>=0;i--)
		{
			PORTA &=~(1<<i);
			_delay_ms(100);
		}
    }
}

