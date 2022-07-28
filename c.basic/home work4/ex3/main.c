#include <stdio.h>
#include <stdlib.h>
void revers(char x[]);
char x[40];
unsigned short i;
void main (){
	printf("enter the sentence  ");
	fflush(stdout);
	fflush(stdin);
	scanf("%s", &x);
	printf("%s \n",x);
    revers(x);
}
void revers (char x[]){

	if(i!=strlen(x))
	{
	    ++i;
	    printf("%c",x[strlen(x)-i]);
		revers(x);

	}

}




