#include <stdio.h>
int sum (int x);
int main() {
    printf("inter your number");  int x=0;
    scanf("%d",&x);
    printf("%d", sum(x));
    return 0;
}
int sum (int x)
{
    if(x!=0)
    {
        int y=0;
        y=x%10;
        return y+ sum(x/10);
    }
}