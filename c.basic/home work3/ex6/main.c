/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 20102
 */

#include <stdio.h>
#include <stdlib.h>

void main (){
	int arr[30], element, num, i, location;
	printf("\nEnter no of elements : ");fflush(stdout);
	scanf("%d", &num);
	for (i = 0; i < num; i++) {

		printf("n::");
		fflush(stdout);fflush(stdin);
		scanf("%d", &arr[i]);

	}
	printf("\nEnter the element to be inserted : ");
	fflush(stdout);fflush(stdin);

	scanf("%d", &element);
	printf("\nEnter the location");
	fflush(stdout);fflush(stdin);

	scanf("%d", &location);

	for (i = num; i >= location; i--) {
		arr[i] = arr[i - 1]; } num++; arr[location - 1] = element;

		for (i = 0; i < num; i++) printf("n %d", arr[i]);


}


