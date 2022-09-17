/*
 * lap2.c
 *
 * Created: 17/09/2022 04:25:49 م
 * Author : 20102
 */ 

#include <avr/io.h>
#include "memorymap.h"
#include "util/delay.h"
#include "util.h"
#define F_CPU 4000000UL
char flag1=1;
int i=1;
int main(void)
{  
	setport(DDRA);
	clearpit(DDRA,0);
    setpit(PORTA,0);
    while (1) 
    {
		if(readpit(PINA,0)==0)
		{
			if(flag1==1)
			{
				flag1=0;
				toglpit(PORTA,i);
				_delay_ms(30);
				if(i>6)i=1;
				else i++;
			}
			
		 }
		 else flag1=1;
		
    }
}

