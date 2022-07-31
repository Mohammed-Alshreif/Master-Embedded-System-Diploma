#include <stdio.h>
char x[20];
int main() {
    printf("print the name");gets(x);
    //printf("%s",x);
    int i=strlen(x)-1, j;
    for(;i>=0;i--){
        if((x[i]==' ')){
            j=i+1;
            for(;j<strlen(x);j++){
                printf("%c",x[j]);
                if(x[j+1]==' ') break;
            }
            printf(" ");
        }
    }

    return 0;
}
