/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 20102
 */

#include <stdio.h>
#include <stdlib.h>

void main (){
	int a=0,b=0;
	printf("Enter value of a:");
	fflush(stdout);
	scanf("%d" ,&a);
	for(int i=0;i<=a;i++){
		b=b+i;
	}
	printf("%d",b);

}


