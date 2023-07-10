/*
 * MPU6050.h
 *
 *  Created on: Apr 9, 2023
 *      Author: 20102
 */

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include "STM32_I2C_DRIVER.h"
#define MPU6050_addres	0x68  //low == if high us 0x69


#define SMPLRT_DIV_REG   0x19
#define GYRO_CONFIG_REG  0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG   0x41
#define GYRO_XOUT_H_REG  0x43
#define PWR_MGMT_1_REG   0x6B
#define WHO_AM_I_REG     0x75


void MPU6050_init(uint32_t clk);
void MPU6050_write(uint8_t register_addres, uint8_t *data, uint8_t Data_Length);
void MPU6050_read(uint16_t register_addres, uint8_t *data, uint8_t Data_Length);



#endif /* INC_MPU6050_H_ */
