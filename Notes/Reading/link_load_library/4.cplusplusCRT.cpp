//new delete
extern "C" void *malloc(unsigned int);
extern "C" void free(void *);

void *operator new(unsigned int size)
{
    return malloc(size);
}

void operator delete(void *p)
{
    free(p);
}

void *operator new[](unsigned int size)
{
    return malloc(size);
}

void operator delete[](void *p)
{
    free(p);
}

//ctors

typedef void (*init_func)(void);

#ifdef WIN32
#pragma section(".CRT$CXA", long, read);
#pragma section(".CRT$CXZ", long, read);

__declspec(allocate(".CRT$XCA")) init_func ctors_begin[] = {0};
__declspec(allocate(".CRT$XCZ")) init_func ctors_end[] = {0};

extern "C" void do_global_ctors()
{
    init_func *f = ctors_begin;
    while (p < ctors_end)
    {
        if (*p != 0)
        {
            (**p)();
        }
        ++p;
    }
}
#else

void run_hooks();
extern "C" void do_global_ctors()
{
    run_hooks();
}
#endif

//gcc crtbegin
#ifndef WIN32
typedef void (*ctor_func)(void);
ctor_func ctors_begin[1] __attribute__((section(".ctors"))) = {
    (ctor_func)-1};
void run_hooks()
{
    const ctor_func *list = ctors_begin;
    while ((int)*++list != -1)
    {
        (**list)();
    }
}
#endif

//gcc crtend
#ifndef WIN32
typedef void (*ctor_func)(void);
ctor_func crt_end[1] __attribute__((section(".ctors"))) = {
    (ctor_func)-1};

#endif

//atexit
#include "4.miniCRT.h"

typedef struct _func_node
{
    atexit_func_t func;
    void *arg;
    int is_cxa;
    struct _func_node *next;
} func_node;
static func_node *atexit_list = 0;

int register_atexit(atexit_func_t func, void *arg, int is_cxa)
{
    func_node *node;
    if (!func)
        return -1;
    node = (func_node *)malloc(sizeof(func_node));
    if (node == 0)
        return -1;
    node->func = func;
    node->arg = arg;
    node->is_cxa = is_cxa;
    node->next = atexit_list;
    atexit_list = node;
    return 0;
}

#ifndef WIN32
typedef void (*cax_func_t)(void *);
int __cxa_atexit(cax_func_t func, void *arg, void *unused)
{
    return register_atexit((atexit_func_t)func, arg, 1);
}
#endif

int atexit(atexit_func_t func)
{
    return register_atexit(func, 0, 0);
}

void mini_crt_call_exit_routine(){
    func_node* p = atexit_list;
    for (; p!=0; p=p->next)
    {
        #ifdef WIN32
        p->func();
        #else
        if(p->is_cxa)
            ((cax_func_t)p->func)(p->arg);
        else
            p->func();
        #endif
        free(p);
    }
    atexit_list =0;
}