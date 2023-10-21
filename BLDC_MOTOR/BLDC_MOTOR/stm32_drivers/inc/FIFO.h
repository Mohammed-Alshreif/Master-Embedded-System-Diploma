/*
 * FIFO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: 20102
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#define FIFO_TYPE uint32_t

typedef struct {
	FIFO_TYPE *head;
	FIFO_TYPE *tail;
	FIFO_TYPE *base;
	uint16_t  count;
	uint16_t  lenght;

}FIFO_BUF_t;

typedef enum {
	FIFO_NO_ERROR,
	FIFO_NULL,
	FIFO_FULL,
	FIFO_EMPTY
}FIFO_status_t;


FIFO_status_t FIFO_INIT(FIFO_BUF_t * FIFO,FIFO_TYPE* arr,uint16_t size);
FIFO_status_t FIFO_ENQUEUE(FIFO_BUF_t * FIFO, FIFO_TYPE item);
FIFO_status_t FIFO_DEQUEUE(FIFO_BUF_t * FIFO, FIFO_TYPE* item);

#endif /* FIFO_H_ */
