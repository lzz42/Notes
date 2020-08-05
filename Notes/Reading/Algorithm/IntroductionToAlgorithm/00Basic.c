#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

//打印一维数组
void printArray(char* c, const int *a, const int len)
{
    printf("%s (%d)= \t", c,len);
    int i = 0;
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

//打印二维矩阵
/*
    int A[2][2] = {{1, 2}, {3, 4}};
    printMatrix('A', (int *)A, 2, 2);
*/
void printMatrix(char* c, int *a, int row, int col)
{
    int i = row - 1, j = col - 1;
    printf("%s (%dx%d):\n", c, row, col);
    int t = 0;
    for (int ii = 0; ii <= i; ii++)
    {
        for (int jj = 0; jj <= j; jj++)
        {
            printf("%5d(%d)\t", a[t],&a[t]);
            t++;
        }
        printf("\n");
    }
}

//构建指定行列的二维矩阵
int* Matrix_Malloc(int row,int col)
{
    return (int*)malloc(row*col*sizeof(int));
}

int main00(int argc, char *argv[])
{
    int a[8] = {12, 23, 34, 45, 56, 67, 78, 89};
    printArray("Helle", a, 8);
    int pa[2][3] =
        {
            {110, 120, 130},
            {210, 220, 230},
        };
    printMatrix("Normal", *pa, 2, 3);
    
    for (int i = 0; i < argc; i++)
    {
        printf("%s \n", argv[i]);
    }

    int *pptr;
    pptr= Matrix_Malloc(2, 5);
    int**ptr= (int**)&pptr[0];
    printf("this' OK.\n");
    printf("%8X --- %8X \n",&pptr[0],&pptr[1]);
    printf("%8X --- %8X \n",pptr[0],pptr[1]);
    printf("%8X --- %8X \n",&ptr[0][0],&ptr[0][1]);
    printf("%8X --- %8X \n",&ptr[0][4],&ptr[1][0]);
    ptr[0][0] = 11;
    ptr[0][1] = 12;
    ptr[0][2] = 13;
    ptr[0][3] = 14;
    ptr[0][4] = 15;

    ptr[0][5] = 121;
    ptr[0][6] = 122;
    ptr[0][7] = 123;
    ptr[0][8] = 124;
    ptr[0][9] = 125;

    printMatrix("Malloc", *ptr, 2, 5);
    printf("end.\n");
}