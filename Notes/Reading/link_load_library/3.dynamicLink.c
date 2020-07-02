#include <stdio.h>
#include <stdlib.h>

// 测试 malloc 最大内存申请数量
int get_maximum_number_malloc_shared()
{
    printf("entry shared method [get_maximum_number_malloc_shared]\n");
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
    printf("exit shared method [get_maximum_number_malloc_shared]\n");
    return max;
}