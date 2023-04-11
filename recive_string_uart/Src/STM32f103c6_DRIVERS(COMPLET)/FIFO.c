/*
 * FIFO.c
 *
 *  Created on: ??�/??�/????
 *      Author: 20102
 */
#include "FIFO.h"

FIFO_status_t FIFO_INIT(FIFO_BUF_t * FIFO,FIFO_TYPE* arr,uint16_t size){
	if(arr==NULL) return FIFO_NULL;
	FIFO->base=arr;
	FIFO->head=arr;
	FIFO->tail=arr;
	FIFO->lenght=size;
	FIFO->count=0;
	return FIFO_NO_ERROR;
}
FIFO_status_t FIFO_ENQUEUE(FIFO_BUF_t * FIFO, FIFO_TYPE item){
	if(FIFO->base==NULL||FIFO->head==NULL||FIFO->tail==NULL) return FIFO_NULL;

	if(FIFO->count >=FIFO->lenght) return FIFO_FULL;
	FIFO->count++;
	*(FIFO->head)=item;

	if(FIFO->head>=(FIFO->base+(FIFO->lenght *sizeof(FIFO_TYPE))))
		FIFO->head=FIFO->base;
	else FIFO->head++;

	return FIFO_NO_ERROR;
}
FIFO_status_t FIFO_DEQUEUE(FIFO_BUF_t * FIFO, FIFO_TYPE* item){
	if(FIFO->base==NULL||FIFO->head==NULL||FIFO->tail==NULL) return FIFO_NULL;
	if(FIFO->count<=0) return FIFO_EMPTY;

	*item = *(FIFO->tail);

	if(FIFO->tail>=(FIFO->base+(FIFO->lenght *sizeof(FIFO_TYPE))))
		FIFO->tail=FIFO->base;
	else FIFO->tail++;
	FIFO->count--;

	return FIFO_NO_ERROR;
}

