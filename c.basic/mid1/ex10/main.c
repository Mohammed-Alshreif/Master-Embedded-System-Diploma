#include <stdio.h>
int flag=0;
int num (int n){
    int c=0,m=0;
    while(n){
        if(n%2!=0){
            if (flag==1) c++;
        }
        else{
            c>m?(m=c):1,c=0;   flag=1;
        }
        n/=2;
    }
    c>m?(m=c):1;   return m;
}
int main() {
    int n;
    printf("input");      scanf("%d",&n);  printf("%d",num(n));     return 0;
}
