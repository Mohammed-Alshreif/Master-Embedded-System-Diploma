#include <stdio.h>
struct Sstudent{
    char name [20];
    float marks;
    int rol;
};
int main() {
    struct Sstudent s[20] ;
    char f='n',i=0;
    printf("inter information of student \n");
    do{
        printf("name:: ");
        scanf("%s",&s[i].name);
        printf("\n");
        printf("mark:: ");
        scanf("%f",&s[i].marks);
        printf("\n");
        printf("rol:: ");
        scanf("%d",&s[i].rol);
        printf("\n");
        printf("do you want to add another student ?? (y or n)");
        scanf("%s",&f);
        printf("\n");
        if(i>=20) f = 'n';
        i++;
    } while (f=='y');

    int x=0;
    for(;x<i;x++){
        printf("name:: ");
        printf("%s",s[x].name);
        printf("\n");
        printf("mark:: ");
        printf("%.2f",s[x].marks);
        printf("\n");
        printf("rol:: ");
        printf("%d",s[x].rol);
        printf("\n");
    }
}
