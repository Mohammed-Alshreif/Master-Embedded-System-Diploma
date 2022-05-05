
#include <stdio.h>
#include <stdlib.h>

void main (){

	printf("Enter the number of your numbers");
	fflush(stdout);
	int a;
	scanf("%d",&a);
	int x[a];
	printf("Enter the numbers");
	fflush(stdout);
	for(int i=0;i<=a-1;i++){
		scanf("%d" ,&x[i]);
	}
	for(int i=0;i<=a-1;i++){
			printf("%d \r\n" ,x[i]);
		}
	int max=x[0];
	for(int i=0;i<=a-1;i++){
	if(max<x[i])max=x[i];

	}
	printf("=========\r\n");
	printf("max = %d",max);


}
