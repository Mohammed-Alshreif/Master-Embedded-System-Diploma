

#include <stdio.h>
#include <stdlib.h>
void fact (int x);
void main (){
	printf("enter positive integer number ");
	fflush(stdout);
	fflush(stdin);
	int x;
	scanf("%d", &x);
	printf("%d \n",x);
	fact(x);

}
void fact (int x){

    int i=x-1;
	for(;i>0;i--)
    {
       x=i*x;

	}
	printf("fact :: %d\n",x);

}





