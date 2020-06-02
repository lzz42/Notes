/*
Simple Demo C
linux:
    gcc -c SimpleDemo.c

windows:
    cl SimpleDemo.c /c /2a
    gcc -c SimpleDemo.c
    objdump -h SimpleDemo.o

.text 代码段
.data 数据段
.bss  
.rdata 只读数据段

CONTENTS:该段在文件中存在

    objdump -s -d SimpleDemo.o
    将SimpleDemo.o中的代码段内容以16进制打印
    objdump -x -s -d SimpleDemo.o

*/

#include <stdio.h>

int printf(const char* format,...);

int global_init_var = 84;
int global_uninit_var ;

// extern char __executable_start[];
extern char __CTOR_LIST__[],__DTOR_LIST__[];
extern char etext[];//,_etext[];//,__etext[];
// extern char edata[],_edata[];
extern char end[];//,_end[];

void func1(int i)
{
    printf("%d\n",i);
    // printf("Exec Start: \t%X \n",__executable_start);
    printf("Exec Start: \t%X\t%X \n",__CTOR_LIST__,__DTOR_LIST__);
    printf("Text End: \t%X \tX \t\n",etext);
    // printf("Data End: \t%X \t%X \n",edata,_edata);
    printf("Exec End: \t%X \tX \n",end);
}

int main(void)
{
    static int static_var = 85;
    static int static_var2;

    int a=1;
    int b;
    func1(static_var+static_var2+a+b);
    return a;
}

__attribute__((section("Name"))) 
int Name(int rr){
    return rr * 100;
}
