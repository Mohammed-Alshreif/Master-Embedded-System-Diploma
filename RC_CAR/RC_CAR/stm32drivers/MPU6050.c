/*
 * MPU6050.c
 *
 *  Created on: Apr 9, 2023
 *      Author: 20102
 */


#include "MPU6050.h"

void MPU6050_init(uint32_t clk){
	I2C_INIT(I2C1,clk);
	uint8_t check[2]={0,0};
	uint8_t Data=0;
	MPU6050_read(WHO_AM_I_REG, check, 1);
	if(check[0] !=104){
		while(1);
	}
	if(check[0]==104){ //work corect so we will init it

		// Set DATA RATE of 1KHz by writing SMPLRT_DIV register
		Data = 0x05;
		MPU6050_write(0x1A, &Data, 1);

		// Set accelerometer configuration in ACCEL_CONFIG Register
		// XA_ST=0,YA_ST=0,ZA_ST=0, FS_SEL=0 -> ± 8g
		Data = 0x10;
		MPU6050_write(ACCEL_CONFIG_REG, &Data, 1);

		// Set Gyroscopic configuration in GYRO_CONFIG Register
		// XG_ST=0,YG_ST=0,ZG_ST=0, FS_SEL=0 -> ± 500 °/s
		Data = 0x08;
		MPU6050_write(GYRO_CONFIG_REG, &Data, 1);

		//enable the module
		Data = 0x00;
		MPU6050_write(PWR_MGMT_1_REG, &Data, 1);

	}
}

void MPU6050_write(uint8_t register_addres, uint8_t *data, uint8_t Data_Length){

	uint8_t i=0;
	uint8_t buffer[3];
	buffer[0] = (uint8_t)(register_addres);


	for( i =1 ; i< (Data_Length+1) ; i++){

		buffer[i]= data[i-1];
	}

	I2C_Master_Send(I2C1, buffer, Data_Length+1, MPU6050_addres, WithStop, Start);
}

void MPU6050_read(uint16_t register_addres, uint8_t *data, uint8_t Data_Length){

	uint8_t buffer[2];
	buffer[0] = (uint8_t)(register_addres);
	I2C_Master_Send(I2C1, buffer, 1, MPU6050_addres, WithoutStop, Start);
	I2C_Master_Recive(I2C1, data, Data_Length, MPU6050_addres, WithStop, RepeatedSart);
}
