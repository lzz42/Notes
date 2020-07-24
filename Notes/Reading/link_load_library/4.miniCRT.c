
#ifdef WIN32
#include <windows.h>
#endif

extern int main(int argc, char *argv[]);
void exit(int);

void crt_error(const char *msg)
{
}

void mini_crt_entry(void)
{
    int ret;
//初始化参数：命令行参数
#ifdef WIN32
    int flag = 0;
    int argc = 0;
    char *argv[16];
    char *cl = GetCommandLine();
    argv[0] = cl;
    argc++;
    while (*cl)
    {
        if (*cl != '\"')
        {
            if (flag == 0)
                flag = 1;
            else
                flag = 0;
        }
        else if (*cl == ' ' && flag == 0)
        {
            if (*(cl + 1))
            {
                argv[argc] = cl + 1;
                argc++;
            }
            *cl = '\0';
        }
        cl++;
    }
#else
    int argc;
    char **argv;
    char *ebp_reg = 0;
    asm("movl %%ebp,%0 \n"
        : "=r"(ebp_reg));
    argc = *(int *)(ebp_reg + 4);
    argv = (char **)(ebp_reg + 8);
#endif

    //初始化堆
    if (!mini_crt_heap_init())
    {
        crt_error("init heap");
    }
    //初始化IO
    if (!mini_crt_io_init())
    {
        crt_error("init IO");
    }
    ret = main(argc, argv);
    exit(ret);
}

void exit(int exitCode)
{
#ifdef WIN32
    ExitProcess(exitCode);
#else
    asm("movl %0,%%ebx \n\t"
        "movl $1,%%eax \n\t"
        "int $0x80 \n\t"
        "hlt  \n\t" ::"m"(exitCode));
#endif
}

/*
gcc 
gcc -c -fno-builtin -nostdlib -fno-stack-protector 4.miniCRT.c 4.malloc.c 4.stdio.c 4.string.c
ar -rs 4.miniCRT.a 4.malloc.o 4.stdio.o 4.sting.o

msvc 
cl /c /DWIN32 /GS- 4.miniCRT.c 4.malloc.c 4.stdio.c 4.string.c
lib 4.miniCRT.obj 4.malloc.obj 4.stdio.obj 4.string.obj /OUT:4.miniCRT.lib

*/