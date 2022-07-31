#include "stdio.h"
int main(int argc, char *argv[]) {
    int a[100] = {0}; int n = 0;
    printf("Enter size: ");
    scanf("%d" , &n);
    printf("Enter element: ");
    int i=0,v;
    for ( ; i <n ; i++){
        scanf("%d" ,&v);
        a[v]++;
    }
    int r=0;
    for ( ; r <100 ; r++){
        if (a[r] == 1){
            printf("%d ",r);
        }
    }
    return 0;
}

