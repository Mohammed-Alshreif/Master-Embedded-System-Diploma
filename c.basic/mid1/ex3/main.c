#include <stdio.h>
int is_prime(int n){
    int i=2;
    for(;i<n;i++)
        if(n%i==0) return 0;
    return 1;
}
int main() {
    int x=0,y;
    printf("n1");    scanf("%d",&x);    printf("n2");    scanf("%d",&y);
    int i=x;
    for(;i<=y;i++){
       if(is_prime(i)){
           printf(" %d ",i);
       }
    }
    return 0;
}
