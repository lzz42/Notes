#include <stdio.h>
#include <stdlib.h>

// 测试 malloc 最大内存申请数量
int get_maximum_number_malloc()
{
    unsigned blocksize[] = {1024 * 1024, 1024, 1};
    int i, count;
    unsigned max = 0;
    for (i = 0; i < 3; i++)
    {
        for (count = 1;; count++)
        {
            void *block = malloc(max + blocksize[i] * count);
            if (block)
            {
                max = max + blocksize[i] * count;
                free(block);
            }
            else
            {
                break;
            }
        }
    }
    return max;
}

void print_maximum_number_mlloc()
{
    unsigned max = get_maximum_number_malloc();
    float k = max / 1024;
    float g = k / 1024;
    printf("Max malloc size is : %u bytes\n", max);
    printf("Max malloc size is : %f KB\n", k);
    printf("Max malloc size is : %f G\n", g);
}

// #include <sys/types.h>
// #include <unistd.h>
// int mini_bash(){
//     char buf[1000]={0};
//     pid_t pid;
//     while (1)
//     {
//         printf("mini bash$");
//         scanf("%s",buf);
//         pid = fork();
//         if(pid==0){
//             if(execlp(buf,0)<0){
//                 printf("exec error\n");
//             }
//         }else if(pid >0){
//             int status;
//             waitpid(pid,&status,0);
//         }else{
//             printf("fork error \n");
//         }
//     }
//     return 0;
// }

#include "3.dynamicLink.h"
void get_max_malloc_shared()
{
    int max = get_maximum_number_malloc_shared();
    printf("Max malloc size is (Shared): %u bytes\n", max);
}

//打印堆栈中的初始化信息
#include <stdio.h>
#include <elf.h>
void print_all_stack_info(int argc, char *argv[])
{
    int *p = (int *)argv;
    int i;
    Elf32_auxv_t *aux;
    printf("Argument Count:\t%d\n", *(p - 1));
    for (int i = 0; i < *(p - 1); ++i)
    {
        printf("Argument \t%d:\t%s\n", i, *(p + i));
    }
    p += i;
    p++;
    printf("Environment:\n");
    while (*p)
    {
        printf("%s\n", *p);
        p++;
    }
    p++;
    printf("Auxiliary Vectors:\n");
    aux = (Elf32_auxv_t *)p;
    while (auv->a_type != AT_NULL)
    {
        printf("Type: %2d  Value: %x\n", aux->a_type, aux->a_un.a_val);
        aux++;
    }
}

#include <dlfcn.h>
int explicit_dynamic_linking(int argc, char *argv[])
{
    void *handle;
    double (*func)(double);
    char *error;
    hanle = dlopen(argv[1], RTLD_NOW);
    if (handle == NULL)
    {
        printf("Open libarry:[%s] error.Error: %s\n", argv[1], dllerror());
        return -1;
    }
    func = dlsym(handle, "sin");
    if ((error = dlerror()) != NULL)
    {
        printf("Symbol [sin] Not Found : %s\n", error);
        goto exit_runso;
    }
    printf("Sin:%f \n", func(3.1415 / 2));
exit_runso:
    dlclose(handle);
}

/*
    runso
*/
#include <dlfcn.h>
#define SETUP_STACK                                           \
    i = 2;                                                    \
    while (++i < argc - i)                                    \
    {                                                         \
        switch (argv[i][0])                                   \
        {                                                     \
        case 'i':                                             \
            asm volatile("push %0" ::"r"(atoi(&argv[i][1]))); \
            esp += 4;                                         \
            break;                                            \
        case 'd':                                             \
            atof(&argv[i][1]);                                \
            asm volatile("subl $8,%esp\nfstpl (%esp)");       \
            esp += 8;                                         \
            break;                                            \
        case 's':                                             \
            asm volatile("push %0" ::"r"(&argv[i][1]));       \
            esp += 4;                                         \
            break;                                            \
        default:                                              \
            printf("error argument type");                    \
            goto exit_runso;                                  \
            break;                                            \
        }                                                     \
    }
#define RESTORE_STACK \
    asm volatile("add %0,%%esp" ::"r"(esp))
int runso(int argc, char *argv[])
{
    void *handle;
    char *error;
    int i;
    int esp = 0;
    void *func;
    handle = dlopen(argv[1], RTLD_NOW);
    if (handle == 0)
    {
        printf("Can't Find Library: %s\n", argv[1]);
        return -1;
    }
    func = dlsym(handle, argv[2]);
    if ((error = dlerror()) != NULL)
    {
        printf("Find Symbol: %s Error: %s \n", argv[2], error);
        goto exit_runso;
    }
    switch (argv[argc - 1][0])
    {
    case 'i':
        int (*func_int)() = func;
        SETUP_STACK;
        int ret = func_int();
        RESTORE_STACK;
        printf("ret = %d \n", ret);
        break;
    case 'd':
        double (*func_double)() = func;
        SETUP_STACK;
        double ret = func_double();
        RESTORE_STACK;
        printf("ret = %f \n", ret);
        break;
    case 's':
        char (*func_char)() = func;
        SETUP_STACK;
        char *ret = func_char();
        RESTORE_STACK;
        printf("ret = %s \n", ret);
        break;
    case 'v':
        void (*func_void)() = func;
        SETUP_STACK;
        func_void();
        RESTORE_STACK;
        printf("ret = void \n");
        break;
    default:
        break;
    }
exit_runso:
    dlclose(handle);
}

int main(int argc, char *argv[])
{
    // print_maximum_number_mlloc();
    // get_max_malloc_shared();
    print_all_stack_info(argc, argv);
}