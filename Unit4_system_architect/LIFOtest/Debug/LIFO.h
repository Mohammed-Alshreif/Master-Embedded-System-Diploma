/*
 * LIFO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: 20102
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdlib.h"

typedef struct {
	unsigned int *head;
	unsigned int *base;
	unsigned int length;
	unsigned int count;

}LIFO_BUF_t;

typedef enum {
	LIFO_NO_ERROR,
	LIFO_NULL,
	LIFO_FULL,
	LIFO_EMPTY
}LIFO_status_t;


LIFO_status_t LIFO_INIT(LIFO_BUF_t * LIFO,unsigned int* arr[]);
LIFO_status_t LIFO_PUSH(LIFO_BUF_t * LIFO,unsigned int* item);
LIFO_status_t LIFO_POP(LIFO_BUF_t * LIFO,unsigned int* item);



#endif /* LIFO_H_ */
