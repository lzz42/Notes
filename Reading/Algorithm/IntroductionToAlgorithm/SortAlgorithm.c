#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void printLageArray(int *a)
{
    int i = 0;
    while (a[i] != '\0')
    {
        printf("%3d\t", a[i]);
        i++;
        if (i == 100)
        {
            printf("\n");
        }
    }
}

//打印数组
void printArray(char c[], int a[])
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
    while (a[i] != '\0')
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
//插入排序算法
void InsertSort(int a[])
{
    int i = 0;
    while (a[i] != '\0')
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

//合并分组
void Merge(int a[], int p, int q, int r)
{
    //copy data
    int L[1024];
    int R[1024];
    int i = 0;
    int j = 0;
    for (i = 0; i <= q - p; i++)
    {
        L[i] = a[p + i];
    }
    for (j = 0; j < r - q; j++)
    {
        R[j] = a[q + j + 1];
    }
    L[i] = INT_MAX;
    R[j] = INT_MAX;
    i = 0;
    j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}

//归并排序
void Merge_Sort(int a[], int p, int r)
{
    if (p >= r)
    {
        return;
    }
    int q = (p + r) / 2;
    Merge_Sort(a, p, q);
    Merge_Sort(a, q + 1, r);
    // Merge(a, p, q, r);
    //copy data
    int L[1024], R[1024];
    int i = 0, j = 0;
    for (i = 0; i <= q - p; i++)
    {
        L[i] = a[p + i];
    }
    for (j = 0; j < r - q; j++)
    {
        R[j] = a[q + j + 1];
    }
    L[i] = INT_MAX;
    R[j] = INT_MAX;
    i = 0;
    j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}

// 归并排序入口
void MergeSort(int a[])
{
    int i = 0;
    while (a[i] != '\0')
    {
        i++;
    }
    Merge_Sort(a, 0, i - 1);
}

//快速排序
void Quick_Sort(int a[], int low, int hight)
{
    //基线条件
    if (hight - low < 1)
    {
        return;
    }
    int base = a[low];
    int mid = low;
    for (size_t i = low + 1; i <= hight; i++)
    {
        if (a[i] <= base)
        {
            int temp = a[i];
            for (size_t j = i; j > mid; j--)
            {
                a[j] = a[j - 1];
            }
            a[mid] = temp;
            mid++;
        }
    }
    Quick_Sort(a, low, mid - 1);
    Quick_Sort(a, mid + 1, hight);
}

//快速排序
void QuickSort(int a[])
{
    int len = 0;
    while (a[len] != '\0')
    {
        len++;
    }
    Quick_Sort(a, 0, len - 1);
}

//有序数组的二分查找
int BinaryFind(int sa[], int target, int *index)
{
    int len = 0;
    while (sa[len] != '\0')
    {
        len++;
    }
    if (len <= 0)
    {
        return 0;
    }
    if (sa[0] == target)
    {
        *index = 0;
        return 1;
    }
    else if (sa[len] == target)
    {
        *index = len;
        return 1;
    }
    int m = len / 2;
    int s = 0, l = len;
    int i = 1;
    while (m > 0 && m < len)
    {
        printf("Fiund Loop:%2d M:%2d \n", i, m);
        i++;
        if (i > 32)
        {
            return 0;
        }
        if (sa[m] == target)
        {
            *index = m;
            return 1;
        }
        else if (sa[m] > target)
        {
            l = m;
            m = (s + m) / 2;
        }
        else
        {
            s = m;
            m = (m + l) / 2;
        }
    }
    return 0;
}

int main(char arg[])
{
    int a[] = {122, 56, 77, 1, 8, 6, 568, 33, 12, 55, 21, 22, 14, 18, 9, '\0'};
    int b[] = {122, 56, 77, 1, 8, 6, 568, 33, 12, 55, 21, 22, 14, 18, 9, '\0'};
    int c[] = {122, 56, 77, 1, 8, 6, 568, 33, 12, 55, 21, 22, 14, 18, 9, '\0'};
    printArray("Origin", a);
    //insert sort
    InsertSort(c);
    printArray("Insert Sort", c);
    //merge sort
    MergeSort(b);
    printArray("Merge Sort", b);
    //quick sort
    QuickSort(a);
    printArray("Quick Sort", a);
    int max = 1024 * 4;
    int *ss = (int *)malloc((max + 1) * sizeof(int));
    for (size_t i = 0; i < max + 1; i++)
    {
        ss[i] = i + 100;
    }
    ss[max + 1] = '\0';
    // printLageArray(ss);
    int out;
    int tar = 2889;
    if (BinaryFind(ss, tar, &out) == 1)
    {
        printf("Success Find %2d, At:%2d \n", tar, out);
    }
    else
    {
        printf("Faild Find %2d \n", tar);
    }
}
