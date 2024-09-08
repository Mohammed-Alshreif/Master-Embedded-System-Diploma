/*
 * STM32_I2C_LCD.c
 *
 *  Created on: Dec 7, 2022
 *      Author: 20102
 */
static unsigned flag_init=0;
#include "I2C_LCD.h"
//============================================
void _12cdelay_ms(long x){
	for(long i=0;i<(x*190);i++);
}

void I2C_LCD_write_CMD(I2C_TypeDef* I2Cx,char CMD,uint16_t address){

	unsigned char temp = 0x00;
	uint8_t lcd = 0x0C;//1100  RS=0 RW=0 E=1 backlight =1
	lcd &= 0x0F;
	temp = (CMD & 0xF0);//4 MSB first //1111 0101//  1111 1100  //1111 0100
	lcd |= (temp| 0x04);// 4 MSB of CMD + 1100  RS=0 RW=0 E=1 backlight =1

	I2C_Master_Send(I2Cx, &lcd, 1, address, WithStop, Start);//send to i2C

	_12cdelay_ms(10);
	lcd &= ~(0x04);//E=0
	I2C_Master_Send(I2Cx, &lcd, 1, address, WithStop, Start);// 4 MSB of CMD + 1100  RS=0 RW=0 E=0 backlight =1
	_12cdelay_ms(10);




	if(flag_init)
	{

		temp = ((CMD & 0x0F)<<4);//4 LSB first
		lcd = 0x0C;//1100  RS=0 RW=0 E=1 backlight =1
		lcd |= (temp| 0x04);// 4 LSB of CMD + 1100  RS=0 RW=0 E=1 backlight =1

		I2C_Master_Send(I2Cx, &lcd, 1, address, WithStop, Start);//send to i2C
		_12cdelay_ms(10);
		lcd &= ~(0x04);//E=0
		I2C_Master_Send(I2Cx, &lcd, 1, address, WithStop, Start);// 4 LSB of CMD + 1100  RS=0 RW=0 E=0 backlight =1
		_12cdelay_ms(5);
	}
	_12cdelay_ms(2);
}
void I2C_LCD_Init(I2C_TypeDef* I2Cx,uint16_t address,uint32_t clk){
	I2C_INIT(I2C1,clk);
	flag_init=0;
	_12cdelay_ms(90);
	I2C_LCD_write_CMD(I2Cx,0x03, address);//--- Initialize Sequence
	I2C_LCD_write_CMD(I2Cx,0x03, address);
	I2C_LCD_write_CMD(I2Cx,0x03, address);
	I2C_LCD_write_CMD(I2Cx,0x20, address);//--- Return to Home
	I2C_LCD_write_CMD(I2Cx,0x20, address);//--- Return to Home
	I2C_LCD_write_CMD(I2Cx,0x80, address);// 2 line and 5x7 pixel N=1 f=0
	_12cdelay_ms(2);
	I2C_LCD_write_CMD(I2Cx,0x00, address);
	I2C_LCD_write_CMD(I2Cx,0xC0, address);//cerser
	_12cdelay_ms(2);
	I2C_LCD_write_CMD(I2Cx,0x00, address);
	I2C_LCD_write_CMD(I2Cx,0x10, address);//--- Clear LCD
	_12cdelay_ms(30);
flag_init=1;
}
void I2C_LCD_write_data(I2C_TypeDef* I2Cx ,char data,uint16_t address){

	unsigned char temp = 0x00;
	uint8_t lcd = 0x0D;//1101  RS=1 RW=0 E=1 backlight =1
	temp = (data & 0xF0);
	lcd |= (temp| 0x04);

	I2C_Master_Send(I2Cx, &lcd, 1, address, WithStop, Start)	;

	_12cdelay_ms(1);
	lcd &= ~(0x04);
	I2C_Master_Send(I2Cx, &lcd, 1, address, WithStop, Start);
	_12cdelay_ms(1);


	temp = ((data & 0x0F)<<4);
	lcd = 0x0D;//1101  RS=1 RW=0 E=1 backlight =1
	lcd |= (temp|0x04);
	I2C_Master_Send(I2Cx, &lcd, 1, address, WithStop, Start);
	_12cdelay_ms(1);
	lcd &= ~(0x04);//E=0
	I2C_Master_Send(I2Cx, &lcd, 1, address, WithStop, Start);
	_12cdelay_ms(5);

}
void I2C_LCD_write_string(I2C_TypeDef* I2Cx ,char* data,uint16_t address){
	while((*data)!=0){

		I2C_LCD_write_data(I2Cx, *data, address);
		data++;
	}

}
void I2C_LCD_setcerser(I2C_TypeDef* I2Cx,uint16_t address,char ROW , char COL){
	volatile unsigned char location ;
	if(ROW<2 && COL<16){
		location =(0x40 * ROW) + COL ;
		location |=(1<<7);
	}

	I2C_LCD_write_CMD(I2Cx,location,address);
}
void I2C_LCD_clear(I2C_TypeDef* I2Cx,uint16_t address){
	I2C_LCD_write_CMD(I2Cx, LCD_CLEAR_SCREEN, address);
}

void I2C_LCD_write_FLOATnumber(I2C_TypeDef* I2Cx,uint16_t address,float num,unsigned char digit){
	char text[20];
	gcvt(num,digit,text);
	I2C_LCD_write_string(I2Cx, text, address);
}
void I2C_LCD_write_INTnumber(I2C_TypeDef* I2Cx,uint16_t address,int num){
	char text[20];
	sprintf(text,"%d",num);
	I2C_LCD_write_string(I2Cx, text, address);
}
