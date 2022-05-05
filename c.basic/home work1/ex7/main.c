/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 20102
 */
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
	printf("Enter value of b:");
	fflush(stdout);
	scanf("%d" ,&b);
	a+=b;b=a-b;a=a-b;
	printf("After swapping, value of a=%d,,b= %d",a,b);


}




