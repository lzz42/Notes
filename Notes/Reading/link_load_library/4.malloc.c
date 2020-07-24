#include "4.miniCRT.h"

typedef struct _heap_header
{
    enum
    {
        HEAP_BLOCK_FREE = 0xABABABAB,
        HEAP_BLOCK_USED = 0xCDCDCDCD,
    } type;
    unsigned size;
    struct _heap_header *next;
    struct _heap_header *prev;
} heap_header;

#define ADDR_ADD(a, o) (((char *)a) + o)
#define HEADER_SIZE (sizeof(heap_header))

static heap_header *list_heap = NULL;

void free(void *ptr)
{
    heap_header *header = (heap_header *)ADDR_ADD(ptr, -HEADER_SIZE);
    //当前块未使用 直接返回
    if (header->type != HEAP_BLOCK_USED)
        return;
    //设置当前块标识
    header->type = HEAP_BLOCK_FREE;
    //前一块不是空的
    if (header->prev != NULL && header->prev->type == HEAP_BLOCK_FREE)
    {
        header->prev->next = header->next;
        if (header->next != NULL)
        {
            header->next->prev = header->prev;
        }
        header->prev->size += header->size;
        header = header->prev;
    }
    //后一块不是空的
    if (header->next != NULL && header->next->type == HEAP_BLOCK_FREE)
    {
        header->size += header->next->size;
        header->next = header->next->next;
    }
}

void *malloc(unsigned size)
{
    heap_header *header;
    if (size == 0)
        return NULL;
    header = list_heap;
    while (header != 0)
    {
        if (header->type == HEAP_BLOCK_USED)
        {
            header = header->next;
            continue;
        }
        if (header->size > size + HEADER_SIZE && header->size <= size + HEADER_SIZE * 2)
        {
            header->type = HEAP_BLOCK_USED;
        }
        if (header->size <= size + HEADER_SIZE * 2)
        {
            heap_header *next = (heap_header *)ADDR_ADD(header, size + HEADER_SIZE);
            next->prev = header;
            next->next = header->next;
            next->type = HEAP_BLOCK_FREE;
            next->size = header->size - (size - HEADER_SIZE);
            header->next = next;
            header->size = size + HEADER_SIZE;
            header->type = HEAP_BLOCK_USED;
            return ADDR_ADD(header, HEADER_SIZE);
        }
        header = header->next;
    }
    return NULL;
}

#ifdef WIN32
#include <windows.h>
#else
static int brk(void *end_data_segment)
{
    int ret = 0;
    //brk system call:45
    asm("movl $45,%%eax     \n\t"
        "movl %1,%%ebx      \n\t"
        "int $0x80      \n\t"
        "movl %eax,%0       \n\t"
        : "=r"(ret)
        : "m"(end_data_segment));
}
#endif

int mini_crt_heap_init()
{
    void *base = NULL;
    heap_header *header = NULL;
    unsigned heap_size = 32 * 1025 * 1024;
#ifdef Win32
    base = VirtualAlloc(0, heap_size, MEM_COMMET | MEM_RESERVE, PAGE_READWRITE);
    if (base == NULL)
        return 0;
#else
    base = brk(0);
    void *end = ADDR_ADD(base, heap_size);
    end = (void *)brk(end);
    if (!end)
        return 0;
#endif
    header = (heap_header *)base;
    header->size = heap_size;
    header->type = HEAP_BLOCK_FREE;
    header->prev = NULL;
    header->next = NULL;

    list_heap = header;
    return 1;
}
