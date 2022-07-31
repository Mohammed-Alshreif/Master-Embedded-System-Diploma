#include <stdio.h>
#include <stdlib.h>
void revers(char x[]);
char x[40];
unsigned short i;
int main (){
    printf("enter the sentence  ");
    scanf("%s", &x);printf("%s \n",x);
    revers(x);
    return(0);
}
void revers (char x[]){
    if(i!=strlen(x))
    {
        ++i;
        printf("%c",x[strlen(x)-i]);
        revers(x);
    }
}




