#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "00Basic.c"

void Matrix_Malloc(int **mtr, int row, int col)
{
    mtr = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        mtr[i] = (int *)malloc(col * sizeof(int));
    }
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

//正常的矩阵乘法 n^3
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

void Expand_Matrix_AddOne(int **M, int n)
{
}

void Expand_Matrix_SubOne(int **M, int n)
{
}

int **Matrix_Copy(int **M, int srow, int scol, int r, int c)
{
    int **S;
    //为子矩阵申请空间
    Matrix_Malloc(S, r, c);
    //复制数据
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            S[i][j] = M[i + srow][j + scol];
        }
    }
}

int **Matrix_Add(int **A, int **B)
{
    int n = 0;
    while (A[0][n] != '\0')
    {
        n++;
    }
    n--;
    int **S;
    Matrix_Malloc(S, n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            S[i][i] = A[i][i] + B[i][i];
        }
    }
}

int **Matrix_Sub(int **A, int **B)
{
    int n = 0;
    while (A[0][n] != '\0')
    {
        n++;
    }
    n--;
    int **S;
    Matrix_Malloc(S, n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            S[i][i] = A[i][i] - B[i][i];
        }
    }
}

int **Matrix_Combine(int **C11, int **C12, int **C21, int **C22)
{
    int n1 = 0, n1 = 0, n1 = 0, n1 = 0;
    while (C11[0][n1] != '\0')
    {
        n1++;
    }
    n1--;
}

//Starassen 算法n^lg(7)
int **Square_Matrix_Multiply_Strassen(int **A, int **B)
{
    int n = 0;
    while (A[0][n] != '\0')
    {
        n++;
    }
    n--;
    int **C;
    if (n == 1)
    {
        Matrix_Malloc(C, 1, 1);
        C[0][0] = A[0][0] * B[0][0];
    }
    else
    {
        int k = n;
        //矩阵大小为奇数 补1
        if (n % 2 == 1)
        {
            Expand_Matrix_AddOne(A, n);
            Expand_Matrix_AddOne(B, n);
            k++;
        }
        int l = k / 2;
        int **A11 = Matrix_Copy(A, 0, 0, l, l);
        int **A12 = Matrix_Copy(A, 0, l, l, l);
        int **A21 = Matrix_Copy(A, l, 0, l, l);
        int **A22 = Matrix_Copy(A, l, l, l, l);
        int **B11 = Matrix_Copy(B, 0, 0, l, l);
        int **B12 = Matrix_Copy(B, 0, l, l, l);
        int **B21 = Matrix_Copy(B, l, 0, l, l);
        int **B22 = Matrix_Copy(B, l, l, l, l);
        int **S1 = Matrix_Sub(B12, B22);
        int **S2 = Matrix_Add(A11, A12);
        int **S3 = Matrix_Add(A21, A22);
        int **S4 = Matrix_Sub(B21, B11);
        int **S5 = Matrix_Add(A11, A22);
        int **S6 = Matrix_Add(B11, B22);
        int **S7 = Matrix_Sub(A12, A22);
        int **S8 = Matrix_Add(B21, B22);
        int **S9 = Matrix_Sub(A11, B21);
        int **S10 = Matrix_Add(B11, B12);
        int **P1 = Square_Matrix_Multiply_Strassen(A11, S1);
        int **P2 = Square_Matrix_Multiply_Strassen(S2, B22);
        int **P3 = Square_Matrix_Multiply_Strassen(S3, B11);
        int **P4 = Square_Matrix_Multiply_Strassen(A22, S4);
        int **P5 = Square_Matrix_Multiply_Strassen(S5, S6);
        int **P6 = Square_Matrix_Multiply_Strassen(S7, S8);
        int **P7 = Square_Matrix_Multiply_Strassen(S9, S10);
        int **C11 = Matrix_Sub(Matrix_Add(P5, P4), Matrix_Sub(P2, P6));
        int **C12 = Matrix_Add(P1, P2);
        int **C21 = Matrix_Add(P3, P4);
        int **C22 = Matrix_Sub(Matrix_Add(P5, P1), Matrix_Add(P3, P7));
        C = Matrix_Combine(C11, C12, C21, C22);
        if (k > n)
        {
            Expand_Matrix_SubOne(C, k);
        }
    }
    return C;
}

void Square_Matrix_Multiply_Test()
{
    int A[2][2] = {{1, 2}, {3, 4}};
    printMatrix('A', (int *)A, 2, 2);
    int B[3][3] = {{1, 2, 3}, {3, 4, 5}, {6, 7, 8}};
    printMatrix('B', (int *)B, 3, 3);
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
    // findMaxSubArrayTest();
    Square_Matrix_Multiply_Test();
    return 0;
}