/*
 * lcd_driver.c
 *
 * Created: 19/09/2022 10:25:48 ص
 * Author : 20102
 */ 


#define F_CPU 4000000UL
#include "atmega32_DRIVERS/LCD_DRIVER/LCD.h"
#include "atmega32_DRIVERS/keypad/keypad.h"
int main(void)
{
	LCD_Init();
	Keypad_init();
	int i=10;
    
    float f =10.5;
    while (1) 
    {
		_delay_ms(1);
		LCD_write_data(Keypad_getkey());
		LCD_write_string(" moalshreif ");
		LCD_write_INTnumber(i);
		LCD_setcerser(1,0);
		LCD_write_FLOATnumber(f,4);
		_delay_ms(50);
		LCD_clear();
		i--;
		f=f-.5f;
		
    }
}

