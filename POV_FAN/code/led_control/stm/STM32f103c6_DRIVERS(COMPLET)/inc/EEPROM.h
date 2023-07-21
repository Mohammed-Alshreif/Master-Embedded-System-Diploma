/*
 * EEPROM.h
 *
 *  Created on: ٠٦‏/١٢‏/٢٠٢٢
 *      Author: 20102
 */

#ifndef STM32F103C6_DRIVERS_INC_EEPROM_H_
#define STM32F103C6_DRIVERS_INC_EEPROM_H_

#include "STM32_I2C_DRIVER.h"
#define EEPROM_Slave_Address	0x2A
//========================================
void eeprom_init(void);
void EEprom_write(uint16_t Memory_address, uint8_t *data, uint8_t Data_Length);
void EEprom_read(uint16_t Memory_address, uint8_t *data, uint8_t Data_Length);


#endif /* STM32F103C6_DRIVERS_INC_EEPROM_H_ */
