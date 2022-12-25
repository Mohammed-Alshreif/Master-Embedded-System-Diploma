#include "I2C_LCD.h"
#include "STM32_TIMERS_DRIVER.h"
int i=0;
#define address 0x3f
int main(void)
{
	delay(200, U_ms,8000000);
	I2C_LCD_Init(I2C1,address);
	I2C_LCD_write_string(I2C1,"MOHAMMED",address);
	I2C_LCD_setcerser(I2C1, address,1,0);
	while(1){
		I2C_LCD_setcerser(I2C1, address,1,0);
		I2C_LCD_write_string(I2C1,"MOHAMMED ",address);
		I2C_LCD_write_INTnumber(I2C1, address,i);
		delay(300, U_ms,8000000);
		if(i<100)i++;
		else i--;
		I2C_LCD_clear( I2C1,address);
	}

}
