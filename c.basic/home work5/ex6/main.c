#include <stdio.h>
union job {
    char c:8;
    char name[32];
    float salary;
    int worker_no; }u;
//#pragma pack(1);
struct job1 { //defining a union
    //char c:8;
    char name[32];
    float salary;
    int worker_no;

}s;
int main() {
    printf("size of union=%d",sizeof(u));
    printf("\nsize of structure = %d", sizeof(s));
}
