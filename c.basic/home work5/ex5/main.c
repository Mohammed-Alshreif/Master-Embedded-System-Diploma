#include <stdio.h>
#define pi 3.1415
#define arr(r)(pi*r*r)
int main() {
    int ra;
    float area;
    printf("inter rade\n ");
    scanf("%d",&ra);
    area=arr(ra);
    printf("area %.2f",(area));

    return 0;
}
