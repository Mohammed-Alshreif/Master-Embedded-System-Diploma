

#include <stdio.h>
#include <stdlib.h>

void main (){
	int a,i=1;float x=0,y=0,avaredge=0;
	printf("the max num of inputs :  ");
	fflush(stdout);
	scanf("%d" ,&a);
	for(i=1;i<=a;i++){
		printf("inter your num\r\n");
		fflush(stdout);
	    scanf("%f" ,&x);
		if(x<0.0)break;
		y=y+x;
	}
	avaredge=y/(i-1);
	printf("the avaredge is :: %.2f",avaredge);



}






