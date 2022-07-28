

#include <stdio.h>
#include <stdlib.h>
void interval (int x, int y);
void main (){
	printf("enter 2 numbers (intervals): ");
	fflush(stdout);
	fflush(stdin);
	int x,y;
	scanf("%d %d", &x , &y);
	printf("%d , %d \n",x ,y);
	interval(x,y);

}
void interval (int x, int y){
	printf("interval::\n");

	for(x;x<=y;x++)
    {
        if((x%2)!=0)
         printf("%d\t",x);

	}

}





