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
void get_max_malloc_shared(){
    int max = get_maximum_number_malloc_shared();
    printf("Max malloc size is (Shared): %u bytes\n", max);
}


//打印堆栈中的初始化信息
#include <stdio.h>
#include <elf.h>
void print_all_stack_info(int argc,char *argv[]){
    int * p =(int*)argv;
    int i;
    Elf32_auxv_t* aux;
    printf("Argument Count:\t%d\n",*(p-1));
    for (int i = 0; i < *(p-1); ++i)
    {
        printf("Argument \t%d:\t%s\n",i,*(p+i));
    }
    p+=i;
    p++;
    printf("Environment:\n");
    while (*p)
    {
        printf("%s\n",*p);
        p++;
    }
    p++;
    printf("Auxiliary Vectors:\n");
    aux =(Elf32_auxv_t*)p;
    while (auv->a_type!=AT_NULL)
    {
        printf("Type: %2d  Value: %x\n",aux->a_type,aux->a_un.a_val);
        aux++;
    }
}


int main(int argc, char *argv[])
{
    // print_maximum_number_mlloc();
    // get_max_malloc_shared();
    print_all_stack_info(argc,argv);
}