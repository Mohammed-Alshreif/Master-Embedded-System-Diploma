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
	int a=0,b=1;
	printf("Enter value of a:");
	fflush(stdout);
	scanf("%d" ,&a);
	for(int i=1;i<=a;i++){
		b=b*i;
	}
	printf("%d",b);

}




