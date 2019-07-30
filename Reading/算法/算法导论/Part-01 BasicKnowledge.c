#include <stdio.h>
#include <limits.h>

void printArray(char c, int a[])
{
    int i = 0;
    printf("Out::%c=", c);
    while (a[i] != '\0')
    {
        printf("[%d]:%d,", i, a[i]);
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

//合并
void Merge(int a[], int p, int q, int r)
{
    printf("p:%d,q:%d,r:%d \n", p, q, r);
    int c0 = q - p + 1;
    int c1 = r - q+1;
    int L[100];
    int R[100];
    int i = 0;
    int j = 0;
    for (i = 0; i < c0; i++)
    {
        L[i] = a[p + i];
    }
    for (j = 0; j <= c1; j++)
    {
        R[j] = a[q + j];
    }
    printf("c0:%d,c1:%d,i:%d,j:%d,\n", c0, c1,i,j);
    L[i + 1-1] = INT_MAX;
    L[i + 2-1] = '\0';
    R[j + 1-1] = INT_MAX;
    R[j + 2-1] = '\0';
    printArray('L', L);
    printArray('R', R);
    i = 0;
    j = 0;
    for (int k = p - 1; k < r; k++)
    {
        if (L[i] < R[j])
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
    if (p < r)
    {
        int q = (p + r) / 2;
        Merge_Sort(a, p, q);
        Merge_Sort(a, p + 1, r);
        Merge(a, p, q, r);
    }
}

void MergeSort(int a[])
{
    int i = 0;
    while (a[i] != '\0')
    {
        i++;
    }
    printf("A Len:%d \n", i);
    Merge_Sort(a, 0, i - 1);
}

int main()
{
    int A[9] = {12, 24, 36, 3, 9, 16, 17, 11, '\0'};
    int B[9] = {12, 24, 36, 3, 9, 16, 17, 11, '\0'};
    // printArray('A', A);
    // InsertSort(A);
    // printArray('A', A);
    printf("-------------\n");
    printArray('B', B);
    MergeSort(B);
    printArray('B', B);
    return 0;
}