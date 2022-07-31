#include <stdio.h>
int sum (int x){
    return (x*(x+1))/2;
}
int main() {
    printf("%d",sum(100));
    return 0;
}
