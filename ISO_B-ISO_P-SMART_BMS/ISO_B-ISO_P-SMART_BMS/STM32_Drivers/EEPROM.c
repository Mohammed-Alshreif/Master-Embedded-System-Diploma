/*
 * EEPROM.c
 *
 *  Created on: ٠٦‏/١٢‏/٢٠٢٢
 *      Author: 20102
 */

#include "EEPROM.h"

void eeprom_init(void){
	I2C_INIT(I2C1,8000000);

}
void EEprom_write(uint16_t Memory_address, uint8_t *data, uint8_t Data_Length){
	uint8_t i=0;
	uint8_t buffer[256];
	buffer[0] = (uint8_t)(Memory_address>>8);   //upper Memory Address
	buffer[1] = (uint8_t)(Memory_address);		//Lower Memory Address

	for( i =2 ; i< (Data_Length+2) ; i++){

		buffer[i]= data[i-2];
	}

	I2C_Master_Send(I2C1, buffer, Data_Length+2, EEPROM_Slave_Address, WithStop, Start);
}
void EEprom_read(uint16_t Memory_address, uint8_t *data, uint8_t Data_Length){

	uint8_t buffer[2];
	buffer[0] = (uint8_t)(Memory_address>>8);   //upper Memory Address
	buffer[1] = (uint8_t)(Memory_address);		//Lower Memory Address


	I2C_Master_Send(I2C1, buffer, 2, EEPROM_Slave_Address, WithoutStop, Start);
	I2C_Master_Recive(I2C1, data, Data_Length, EEPROM_Slave_Address, WithStop, RepeatedSart);

}
