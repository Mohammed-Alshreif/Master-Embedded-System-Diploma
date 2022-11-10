#include "stdio.h"
#include "FIFO/FIFO.h"

FIFO_TYPE arr[5];
void main (){
	FIFO_BUF_t uart;
	FIFO_INIT(&uart,arr,5);

	for(int i=0;i<5;i++){
		printf("\n E :  %d ",FIFO_ENQUEUE(&uart,i));
	}
	for(int i=0;i<5;i++){
		FIFO_TYPE item;
		FIFO_DEQUEUE(&uart,&item);
			printf("\n L :  %d ",item);
		}
}
