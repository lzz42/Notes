#include <stdio.h>
#include "00Basic.c"

/*
插入排序算法n^2
*/
void InsertSort(int *a, int len)
{
    int i = 1;
    while (i < len)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        i++;
    }
}

/* 合并数组nlgn
p<=q<r
合并子数组a[p,q],a[p+1,r]
没有哨兵元素
*/
void Merge(int *a, int p, int q, int r)
{
    int k = 0;
    int *ret = (int *)malloc((r - p + 1) * sizeof(int));
    for (k = p; k <= r; k++)
    {
        ret[k - p] = a[k];
    }
    int i = 0;
    int j = q - p + 1;
    for (k = p; k < r + 1; k++)
    {
        if (i == q + 1 - p)
        {
            a[k] = ret[j];
            j++;
            continue;
        }
        if (j == r + 1 - p)
        {
            a[k] = ret[i];
            i++;
            continue;
        }
        if (ret[i] < ret[j])
        {
            a[k] = ret[i];
            i++;
        }
        else
        {
            a[k] = ret[j];
            j++;
        }
    }
    free(ret);
}
void MergeSort(int *a, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MergeSort(a, p, q);
        MergeSort(a, q + 1, r);
        Merge(a, p, q, r);
    }
}
void MergeSortIn(int *a, int len)
{
    MergeSort(a, 0, len - 1);
}

void BubbleSort(int *a, int len)
{
    if (len < 2)
        return;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (a[i] > a[j])
            {
                a[i] = a[i] ^ a[j];
                a[j] = a[i] ^ a[j];
                a[i] = a[i] ^ a[j];
            }
        }
    }
}

#include "02Practise.c"

void main()
{
    int a0[] = {12, 14, 18, 6, 10, 8, 16};
    int a1[] = {12, 14, 18, 6, 10, 8, 16};

    int b0[] = {12, 14, 18, 6, 10, 8, 16, 20};
    int b1[] = {12, 14, 18, 6, 10, 8, 16, 20};

    printf("Sort Begin:\n");

    printArray("Org", a0, 7);
    InsertSort(a0, 7);
    printArray("Insert", a0, 7);
    printArray("Org", b0, 8);
    InsertSort(b0, 8);
    printArray("Insert", b0, 8);

    printf("---------------------\n");

    printArray("A1", a1, 7);
    printArray("B1", b1, 8);
    // Merge(a1, 1, 2, 3);
    // printArray("MergeSort", a1, 7);
    // MergeSortIn(a1, 7);
    // BubbleSort(a1, 7);
    // InsertSort_Desc(a1,7);
    // MergeSortIn(b1, 8);
    // BubbleSort(b1, 8);
    // InsertSort_Desc(b1,8);
    InsertSort_Recursion(a1, 7);
    InsertSort_Recursion(b1, 7);
    printArray("SortedA1", a1, 7);
    printArray("SortedB1", b1, 8);

    printf("Binary Search:\t %3d \n", Binary_Search(a1, 0, 6, 6));
    printf("Binary Search:\t %3d \n", Binary_Search(a1, 0, 6, 8));
    printf("Binary Search:\t %3d \n", Binary_Search(a1, 0, 6, 16));

    printf("Binary Search:\t %3d \n", Binary_Search(b1, 0, 6, 8));
    printf("Binary Search:\t %3d \n", Binary_Search(b1, 0, 7, 14));
    printf("Binary Search:\t %3d \n", Binary_Search(b1, 0, 7, 18));

    printf("Binary Search:\t %3d \n", Binary_Search(a1, 0, 6, 96));
    printf("Binary Search:\t %3d \n", Binary_Search(b1, 0, 7, 99));

    printf("Sort End.\n");
}