

#include <stdio.h>
#include <stdlib.h>

void main (){
	int a,i=1;float x=1,y=1;
	printf("the max num of inputs :  ");
	fflush(stdout);
	scanf("%d" ,&a);
	for(i=1;i<=a;i++){
		printf("inter your num\r\n");
		fflush(stdout);
		scanf("%f" ,&x);
		if(x==0.0)continue;
		y=y*x;
	}

	printf("the mal. is :: %.2f",y);



}






