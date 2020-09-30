/* 旋转字符串
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法
*/

#include <stdio.h>
#include <stdlib.h>
#include "01Array.c"

void rotate_force(int *nums, int numsSize, int k)
{
    if (numsSize < 1 || k < 1)
        return;
    if (k >= numsSize)
        k = k % numsSize;
    if (k < 1)
        return;
    while (k > 0)
    {
        int l = numsSize - 1;
        int key = nums[l];
        while (l > 0)
        {
            nums[l] = nums[l - 1];
            l--;
        }
        nums[0] = key;
        k--;
    }
}

void rotate(int *nums, int from, int to)
{
    while (from < to)
    {
        int t = nums[from];
        nums[from] = nums[to];
        nums[to] = t;
        from++;
        to--;
    }
}

void rotate_recursion(int *nums, int len, int k)
{
    k = (len - k) % len;
    if (k < 0)
    {
        k = -k;
    }
    rotate(nums, 0, k - 1);
    rotate(nums, k, len - 1);
    rotate(nums, 0, len - 1);
}

/*
链表翻转。
给出一个链表和一个数k，
比如，链表为1→2→3→4→5→6，k=2，则翻转后2→1→6→5→4→3，若k=3，翻转后3→2→1→6→5→4，若k=4，翻转后4→3→2→1→6→5，用程序实现
https://www.bookstack.cn/read/The-Art-Of-Programming-By-July/ebook-zh-01.01.md
*/
struct Node
{
    struct Node *next;
    int value;
};

void printNode(struct Node *head, int k)
{
    if (&head != NULL)
    {
        if (k == 0)
        {
            printf("Node %d-%d", k, head->value);
        }
        else
        {
            printf(";%d-%d", k, head->value);
        }
        k++;
        printNode(head->next, k);
    }
}

void rotateNode(struct Node *head, int end)
{
}

void rotate_node(struct Node *head, int k)
{
    rotateNode(head, k);
    Node *node = head;
    while (k > 0)
    {
        node = Node->next;
    }
    rotateNode(node, -1);
}

void main(char *argv, int argc)
{
    int a0[] = {1, 2, 3, 4, 5, 6};
    int a1[] = {1, 2, 3, 4, 5, 6};
    int a2[] = {1, 2, 3, 4, 5, 6};

    printArray("a0", a0, 6);
    rotate_force(a0, 6, 2);
    printArray("a0", a0, 6);
    printArray("a1", a1, 6);
    rotate_recursion(a1, 6, 2);
    printArray("a1", a1, 6);

    struct Node n1, n2, n3, n4, n5;
    n1.value = 100;
    n2.value = 200;
    n3.value = 300;
    n4.value = 400;
    n5.value = 500;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = NULL;
    printNode(&n1, 0);
}