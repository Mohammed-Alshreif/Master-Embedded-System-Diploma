#include <stdio.h>
#include <stdlib.h>
void p(int x,int y);
int res=1;
void main (){
	int x,y;
	printf("enter base number  ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &x);
	printf("enter power number  ");
	fflush(stdout);
    fflush(stdin);
	scanf("%d", &y);

    p(x,y);
    printf("%d",res);
}
void p(int x,int y){

	if(y>0)
	{
	    --y;
	    res*=x;
		p(x,y);

	}

}




