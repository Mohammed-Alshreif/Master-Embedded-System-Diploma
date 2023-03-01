/*
 * OS.h
 *
 *  Created on: Mar 1, 2023
 *      Author: 20102
 */

#ifndef INC_OS_H_
#define INC_OS_H_
#include "stdio.h"
#include "stdint.h"

typedef enum CPU_PRIVILDEG {
	PRIVILDEG,
	UNPRIVILDEG
}CPU_PRIVILDEG_STAT;

extern void CHANGE_CPU_PRIVILDEG (CPU_PRIVILDEG_STAT STAT);

#endif /* INC_OS_H_ */
