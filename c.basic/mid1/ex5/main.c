#include <stdio.h>
int num (int n){
    int c=0;
    while(n){
        if(n%2!=0)
            c++;
        n/=2;
    }
    return c;
}
int main() {
    int n;
    printf("input");
    scanf("%d",&n);
    printf("%d",num(n));
    return 0;
}
