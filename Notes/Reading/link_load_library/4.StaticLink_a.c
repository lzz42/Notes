#include <stdio.h>

extern int Shared;
extern void swap41(int *, int *);
extern void swap42(int *, int *);
// 弱引用 编译不报错
static __attribute__((weakref("swap43"))) void swap43x(int *, int *);
// swap44 编译会报错
// extern void swap44(int *, int *);
// extern 

int main(int argc, char const *argv[])
{
    int a = 100, b = 200;
    if (swap41)
    {
        printf("S1 \t%d \t%d \n", a, Shared);
        swap41(&a, &Shared);
        printf("S1 \t%d \t%d \n", a, Shared);
    }
    else
    {
        printf("None function swap41");
    }
    if (swap42)
    {
        printf("S2 \t%d \t%d \n", b, Shared);
        swap42(&b, &Shared);
        printf("S2 \t%d \t%d \n", b, Shared);
    }
    else
    {
        printf("None function swap42");
    }
    if (swap43x)
    {
        printf("S2 \t%d \t%d \n", b, Shared);
        swap43x(&b, &Shared);
        printf("S2 \t%d \t%d \n", b, Shared);
    }
    else
    {
        printf("None function swap43");
    }
    // if (swap44)
    // {
    //     printf("S2 \t%d \t%d \n", b, Shared);
    //     swap44(&b, &Shared);
    //     printf("S2 \t%d \t%d \n", b, Shared);
    // }
    // else
    // {
    //     printf("None function swap44");
    // }
    return 0;
}
