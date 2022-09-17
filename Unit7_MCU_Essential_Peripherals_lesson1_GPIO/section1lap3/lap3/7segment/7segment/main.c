/*
 * $safeprojectname$.c
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
char segment[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	
	
int main(void)
{  
	setport(DDRA);
	setpit(DDRB,0);
	setpit(DDRB,1);
	
	
    while (1) 
    {
		
		for(int i=0 ;i<100;i++){
			int x=0;
			x=i%10;
			clearpit(PORTB,0);
			setpit(PORTB,1);
			PORTA=segment[x];
			_delay_ms(50);
			x=i/10;
			if(x==0){
				setpit(PORTB,1);
			}
			else{
				clearpit(PORTB,1);
				setpit(PORTB,0);
				PORTA=segment[x];
				_delay_ms(50);
			}
			
		}	
    }
}

