/*
  * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 20102
 */



#include <stdio.h>
#include <stdlib.h>

void main (){
	char a;
	printf("inter the char :: ");
	fflush(stdout);
	scanf("%c" ,&a);
	switch(a) {

	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		printf("the char is vowel");
		break;
	default:
		printf("the char is consontant");
		break;

	}


}







