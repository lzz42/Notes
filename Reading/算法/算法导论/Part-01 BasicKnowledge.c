#include <stdio.h>
#include <limits.h>
#include <math.h>

//打印数组
void printArray(char c, int a[])
{
    int i = 0;
    printf("%c=", c);
    while (a[i] != '\0')
    {
        if (i == 0)
        {
            printf("[%d]:%d", i, a[i]);
        }
        else
        {
            printf(",[%d]:%d", i, a[i]);
        }
        i++;
    }
    printf(".\n");
}

//打印二维矩阵
/*
    int A[2][2] = {{1, 2}, {3, 4}};
    int *PA[2];
    PA[0] = A[0];
    PA[1] = A[1];
    printMatrixP('A', PA, 2, 2);
*/
void printMatrixP(char c, int **a, int row, int col)
{
    int i = row - 1, j = col - 1;
    printf("%c %d x %d Matrix:\n", c, i + 1, j + 1);
    for (int ii = 0; ii <= i; ii++)
    {
        for (int jj = 0; jj <= j; jj++)
        {
            printf("%d\t", a[ii][jj]);
        }
        printf("\n");
    }
}

//打印二维矩阵
/*
    int A[2][2] = {{1, 2}, {3, 4}};
    printMatrixEx('A', (int *)A, 2, 2);
*/
void printMatrix(char c, int *a, int row, int col)
{
    int i = row - 1, j = col - 1;
    printf("%c %d x %d Matrix:\n", c, i + 1, j + 1);
    int t=0;
    for (int ii = 0; ii <= i; ii++)
    {
        for (int jj = 0; jj <= j; jj++)
        {
            printf("%d\t", a[t]);
            t++;
        }
        printf("\n");
    }
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
    // printf("p:%d,q:%d,r:%d \n", p, q, r);
    int c0 = q - p;
    int c1 = r - q + 1;
    int L[1024];
    int R[1024];
    int i = 0;
    int j = 0;
    for (i = 0; i < c0; i++)
    {
        L[i] = a[p + i];
    }
    for (j = 0; j < c1; j++)
    {
        R[j] = a[q + j];
    }
    // printf("c0:%d,c1:%d,i:%d,j:%d,\n", c0, c1, i, j);
    L[i] = INT_MAX;
    L[i + 1] = '\0';
    R[j] = INT_MAX;
    R[j + 1] = '\0';
    i = 0;
    j = 0;
    for (int k = p; k <= r; k++)
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

//最大子数组结果
struct MaxSubarrayResult
{
    int left_index;
    int right_index;
    int sum;
};

//查找跨越中点的最大子数组
void Find_Maximum_Crossing_Subarray(int a[], int low, int mid, int high, struct MaxSubarrayResult *result)
{
    int sum = 0;
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int max_left = mid;
    int max_right = mid;
    for (int i = mid; i >= low; i--)
    {
        sum += a[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += a[i];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    // printf("Sum:%d,Left_Index:%d,Right_Index:%d \n", left_sum + right_sum, max_left, max_right);
    result->sum = left_sum + right_sum;
    result->left_index = max_left;
    result->right_index = max_right;
}
//查找最大子数组
void Find_Maximum_Subarray(int a[], int low, int high, struct MaxSubarrayResult *result)
{
    if (low == high)
    {
        result->sum = a[low];
        result->left_index = low;
        result->right_index = high;
    }
    else
    {
        int mid = floor((low + high) / 2);
        // printf("Mid::%d \n", mid);
        struct MaxSubarrayResult lRes, rRes, mRes;
        Find_Maximum_Subarray(a, low, mid, &lRes);
        Find_Maximum_Subarray(a, mid + 1, high, &rRes);
        Find_Maximum_Crossing_Subarray(a, low, mid, high, &mRes);
        if (lRes.sum > rRes.sum && lRes.sum > mRes.sum)
        {
            result->sum = lRes.sum;
            result->left_index = lRes.left_index;
            result->right_index = lRes.right_index;
        }
        else if (rRes.sum > lRes.sum && rRes.sum > mRes.sum)
        {
            result->sum = rRes.sum;
            result->left_index = rRes.left_index;
            result->right_index = rRes.right_index;
        }
        else
        {
            result->sum = mRes.sum;
            result->left_index = mRes.left_index;
            result->right_index = mRes.right_index;
        }
    }
}

//查找最大子数组函数入口
void Find_Maximum_Subarray_Entry(int a[], struct MaxSubarrayResult *result)
{
    int i = 0;
    while (a[i] != '\0')
    {
        i++;
    }
    Find_Maximum_Subarray(a, 0, i - 1, result);
}

//暴力查找最大子数组
void Find_Maximum_Subarray_Force(int a[], struct MaxSubarrayResult *result)
{
    int c = 0;
    while (a[c] != '\0')
    {
        c++;
    }
    c--;
    int sum = INT_MIN;
    int left_index = 0;
    int right_index = 0;
    for (int i = 0; i <= c; i++)
    {
        int temp = 0;
        for (int j = i; j <= c; j++)
        {
            temp += a[j];
            if (temp > sum)
            {
                sum = temp;
                left_index = i;
                right_index = j;
            }
        }
    }
    result->sum = sum;
    result->left_index = left_index;
    result->right_index = right_index;
}
//4.1-5
void Find_Maximum_Subarray_5(int a[], struct MaxSubarrayResult *result)
{
    int c = 0;
    while (a[c] != '\0')
    {
        c++;
    }
    c--;
    int sum = a[0], lIndex = 0, rIndex = 0;
    for (int i = 1; i <= c; i++)
    {
        int tempSum = 0;
        for (int j = i; j >= 0; j--)
        {
            tempSum += a[j];
            if (tempSum > sum)
            {
                sum = tempSum;
                lIndex = j;
                rIndex = i;
            }
        }
    }
    result->sum = sum;
    result->left_index = lIndex;
    result->right_index = rIndex;
}

void Square_Matrix_Multiply(int **A, int **B, int **C)
{
    int n = 0;
    while (A[0][n] != '\0')
    {
        n++;
    }
    n--;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

void Square_Matrix_Multiply(int **A, int **B, int **C)
{
    int n = 0;
    while (A[0][n] != '\0')
    {
        n++;
    }
    n--;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

void Square_Matrix_Multiply_Test()
{
    int A[2][2] = {{1, 2}, {3, 4}};
    printMatrixEx('A', (int *)A, 2, 2);
    int B[3][3] = {{1, 2, 3}, {3, 4, 5}, {6, 7, 8}};
    printMatrixEx('B', (int *)B, 3, 3);
    
}

void sortTest()
{
    int A[9] = {12, 24, 36, 3, 9, 16, 17, 11, '\0'};
    int B[9] = {12, 24, 36, 3, 9, 16, 17, 11, '\0'};
    printf("---InsertSort----------\n");
    printArray('A', A);
    InsertSort(A);
    printArray('A', A);
    printf("---MergeSort----------\n");
    printArray('B', B);
    // int C[9] = {12, 13, 140, 150, 22, 23, 24, 25, '\0'};
    // Merge(C, 0, 3, 7);
    MergeSort(B);
    printArray('B', B);
    printf("-------------\n");
}

void findMaxSubArrayTest()
{
    int X[10] = {-8, -6, -9, 15, -1, 2};
    // printArray('X', X);
    // Find_Maximum_Subarray(X, 0, 5, &result);
    // Find_Maximum_Crossing_Subarray(X, 0, 2, 5, &result);
    printf("---findMaxSubArrayTest----------\n");
    int A[10] = {8, -12, 24, -36, 3, -9, 16, -17, 11, '\0'};
    int B[10] = {8, 12, 24, 36, 3, 9, 16, 17, 11, '\0'};
    int C[10] = {-8, -12, -24, -36, -3, -9, -16, -17, -11, '\0'};
    printArray('A', A);
    printArray('B', B);
    printArray('C', C);
    struct MaxSubarrayResult result, result2, result3;
    // Find_Maximum_Subarray_Entry(A, &result);
    // Find_Maximum_Subarray_Entry(B, &result2);
    // Find_Maximum_Subarray_Entry(C, &result3);
    // Find_Maximum_Subarray_Force_Entry(A, &result);
    // Find_Maximum_Subarray_Force_Entry(B, &result2);
    // Find_Maximum_Subarray_Force_Entry(C, &result3);
    Find_Maximum_Subarray_5(A, &result);
    Find_Maximum_Subarray_5(B, &result2);
    Find_Maximum_Subarray_5(C, &result3);
    printArray('C', C);
    printf("---Find_Maximum_Subarray_Force_Entry----------\n");
    //24 2 2
    //136 0 8
    //-3 4 4
    printf("%c Result:Sum:%d,L:%d,R:%d.\n", 'A', result.sum, result.left_index, result.right_index);
    printf("%c Result:Sum:%d,L:%d,R:%d.\n", 'B', result2.sum, result2.left_index, result2.right_index);
    printf("%c Result:Sum:%d,L:%d,R:%d.\n", 'C', result3.sum, result3.left_index, result3.right_index);
}

int main()
{
    // sortTest();
    // findMaxSubArrayTest();
    Square_Matrix_Multiply_Test();
    return 0;
}