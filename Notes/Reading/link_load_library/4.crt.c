#include <stdio.h>

//变长参数
#include "stdarg.h"
int Adds(int c, ...)
{
    int ret = 0;
    va_list args;
    va_start(args, c);
    while (c--)
    {
        int x = va_arg(args, int);
        ret += x;
    }
    va_end(args);
    return ret;
}

#include "stdarg.h"
int Adds2(int c, ...)
{
    int ret = 0;
    int *p = &c + 1;
    while (c--)
    {
        ret += *p++;
    }
    return ret;
}

//GCC
//#define _ADDS_(c...) Adds(c, ##args)
//MSVC
//#define _ADDS2_(c) Adds2(c, __VA_ARGS__)

void args_main(){
    int a1=10,a2=20,a3=30,a4=40;
    printf("Total Sum:\t %d \n",a1+a2+a3+a4);
    printf("Total Adds:\t %d \n",Adds(4,a1,a2,a3,a4));
    printf("Total Adds2:\t %d \n",Adds2(4,a1,a2,a3,a4));
    //printf("Total ADDS:\t %d \n",_ADDS_(4,a1,a2,a3,a4));
    //printf("Total ADDS2:\t %d \n",_ADDS2_(4,a1,a2,a3,a4));
}

//非局部跳转
#include "setjmp.h"
jmp_buf jmp_k;
void jmp_func()
{
    printf("Func:%s\t File:%s\t Line:%d \n", __func__, __FILE__, __LINE__);
    longjmp(jmp_k, 1);
}
void jmp_main()
{
    if (setjmp(jmp_k))
    {
        printf(" World! \n");
        printf("Func:%s\t File:%s\t Line:%d \n", __func__, __FILE__, __LINE__);
    }
    else
    {
        printf("Hello \n");
        printf("Func:%s\t File:%s\t Line:%d \n", __func__, __FILE__, __LINE__);
        jmp_func();
    };
}

/*TLS*/
#ifdef __GNUC__
//gcc
//__pthrad int tls_int_a;
#elif _MSC_VER
//MSVC
//__declspec(thread) int tls_int_a;
#endif


//在main函数前调用

void init_before_main(void){
    printf("init_before_main called %s \n",__func__);
}
typedef void (*ctor_t)(void);
ctor_t __attribute__((section(".ctors"))) init_before_main_p = &init_before_main;

void init_before_main2(void) __attribute__((constructor));
void init_before_main2(void){
    printf("init_before_main2 called %s \n",__func__);
}

#ifdef _MSC_VER

#define SEC_NAME ".CRT$XCG"
#pragma section(SEC_NAME,long,read)
void init_before_main_msvc(){
    printf("init_before_main_msvc Called %s \n",__func__);
}

#define SEC_NAME_AFTER_MAIN ".CRT$XCV"
#pragma section(SEC_NAME_AFTER_MAIN,long,read)
void init_after_main_msvc(){
    printf("init_after_main_msvc Called %s \n",__func__);
}

typedef void(__cdecl *_PVFV)();

__declspec(allocate(SEC_NAME)) _PVFV dummy[] ={init_before_main_msvc};
__declspec(allocate(SEC_NAME_AFTER_MAIN)) _PVFV dummy2[] ={init_after_main_msvc};

#endif


void main(int argc, int *argv[])
{
    printf("main called \n");
    args_main();
    jmp_main();
    jmp_main();
}