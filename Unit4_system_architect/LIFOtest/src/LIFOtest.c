/*
 ============================================================================
 Name        : LIFOtest.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LIFO.h"

int x[5];
int main(void) {
	LIFO_BUF_t UART;
	LIFO_INIT(&UART,x,5);


		LIFO_PUSH(&UART,5);
		LIFO_PUSH(&UART,-50);
		LIFO_PUSH(&UART,-57);
		LIFO_PUSH(&UART,-53);
		LIFO_PUSH(&UART,-100);

	for(int i=0;i<6;i++){
		int item;
		printf("E : %d   ",LIFO_POP(&UART,&item));
		printf("I : %d \n",item);
	}
	return EXIT_SUCCESS;
}
