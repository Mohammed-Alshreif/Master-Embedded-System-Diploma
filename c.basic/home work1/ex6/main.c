/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 20102
 */

#include <stdio.h>
#include <stdlib.h>

void main (){
	int a=0,b=0,c;
	printf("Enter value of a:");
	fflush(stdout);
	scanf("%d" ,&a);
	printf("Enter value of b:");
		fflush(stdout);
		scanf("%d" ,&b);
	c=a;
	a=b;b=c;
	printf("After swapping, value of a=%d,,b= %d",a,b);


}


