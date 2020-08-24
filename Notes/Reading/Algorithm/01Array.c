#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int removeDuplicates(int *a, int len);
void printArray(char c[], int *a, int len);
void rotate(int *nums, int numsSize, int k);

//打印数组
void printArray(char c[], int *a, int len)
{
    int i = 0;
    while (c[i] != '\0')
    {
        printf("%c", c[i]);
        i++;
    }
    i = 0;
    printf("%c", '\t');
    printf("%c", '=');
    i = 0;
    while (i < len)
    {
        if (i == 0)
        {
            printf("%3d", a[i]);
        }
        else
        {
            printf(",%3d", a[i]);
        }
        i++;
    }
    printf(".\n");
}

int removeDuplicates(int *nums, int numsSize)
{
    if (nums == NULL || numsSize == 0)
        return 0;
    if (numsSize == 1)
        return 1;
    int nl = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[nl] != nums[i])
        {
            nl++;
            nums[nl] = nums[i];
        }
    }
    return nl + 1;
}

/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/
int maxProfit(int *prices, int pricesSize)
{
    if (prices == NULL || pricesSize == 0 || pricesSize == 1)
        return 0;
    int profit = 0;
    int index = 1;
    while (index < pricesSize)
    {
        if (prices[index] > prices[index - 1])
        {
            profit += prices[index] - prices[index - 1];
        }
        index++;
    }
    return profit;
}

/*
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
void rotate_recursion(int *nums, int numsSize, int k)
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

void rotate_jump(int *nums, int numsSize, int k)
{
    if (numsSize < 1 || k < 1)
        return;
    if (k >= numsSize)
        k = k % numsSize;
    if (k < 1)
        return;
    if (k != 1)
    {
        if (numsSize & 1)
        {
            if (k & 1 == 0)
            {
                rotate(nums, numsSize, 1);
                k--;
            }
        }
        else
        {
            if (k & 1 == 0)
            {
                rotate(nums, numsSize, 1);
                k--;
            }
        }
    }
    int i = 0, l = 0, t = nums[0], tt = 0;
    while (i < numsSize)
    {
        l += k;
        if (l >= numsSize)
            l -= numsSize;
        tt = nums[l];
        nums[l] = t;
        t = tt;
        i++;
    }
}

int main(char args[])
{
    int a[] = {1, 1, 2};
    int l1 = removeDuplicates(a, 3);
    printArray("112", a, l1);
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // rotate(b, 9, 2);
    // printArray("RRR", b, 9);

    int bb[5][9] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9}};

    // rotate(bb[0], 9, 2);
    // printArray("RRR", b, 9);
    for (int i = 0; i < 5; i++)
    {
        rotate(bb[i], 9, i + 1);
        printArray("RRR", bb[i], 9);
    }
}