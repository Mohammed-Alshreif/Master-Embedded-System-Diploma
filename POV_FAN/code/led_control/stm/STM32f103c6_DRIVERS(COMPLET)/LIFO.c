/*
 * LIFO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 20102
 */

#include "LIFO.h"

LIFO_status_t LIFO_INIT(LIFO_BUF_t * LIFO,unsigned int*arr,unsigned int size){
	if(arr==NULL) return LIFO_NULL;

	LIFO->base=arr;
	LIFO->head=arr;
	LIFO->length=size;
	LIFO->count=0;
	return LIFO_NO_ERROR;

}
LIFO_status_t LIFO_PUSH(LIFO_BUF_t * LIFO,int item){
	if(LIFO->base==NULL||LIFO->head==NULL) return LIFO_NULL;
	if(LIFO->count>=LIFO->length) return LIFO_FULL;

	*(LIFO->head)=item;
	LIFO->head++;
	LIFO->count++;
	return LIFO_NO_ERROR;
}
LIFO_status_t LIFO_POP(LIFO_BUF_t * LIFO,int* item){
	if(LIFO->base==NULL||LIFO->head==NULL) return LIFO_NULL;
	if(LIFO->count<=0) return LIFO_EMPTY;

	LIFO->head--;
	LIFO->count--;
	*item = *(LIFO->head);
	return LIFO_NO_ERROR;
}
