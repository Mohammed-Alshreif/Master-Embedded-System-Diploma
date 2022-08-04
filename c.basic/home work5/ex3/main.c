#include <stdio.h>
struct  Scomplex {
    double real;
    double imaginary;
};
struct  Scomplex add_comp(struct Scomplex com1,struct Scomplex com2){
    struct Scomplex add;
    add.real=com1.real+com2.real;
    add.imaginary=com1.imaginary+com2.imaginary;
    return add;
}
int main() {
    struct  Scomplex com1,com2,add;
    printf("inter complex number like that real imaginary\n");
    printf("inter first number\n ");
    scanf("%lf %lf",&com1.real ,&com1.imaginary);
    printf("inter second number ");
    scanf("%lf %lf",&com2.real ,&com2.imaginary);
    add=add_comp(com1,com2);
    printf("%.2lf+%.2lf j",add.real,add.imaginary);

    return 0;
}
