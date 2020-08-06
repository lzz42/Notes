/*
02 算法入门 Practise
*/
/*
2.1-1 插入排序在<31,41,59,26,41,58>执行过程
非降序
Setp 0 :<31,41,59,26,41,58>
Setp 1 :<31,41,59,26,41,58>
Setp 2 :<31,41,59,26,41,58>
Setp 3 :<26,31,41,59,41,58>
Setp 4 :<26,31,41,41,59,58>
Setp 5 :<26,31,41,41,58,59>
*/
/*
2.1-2 将插入排序改造为非升序排序
*/
void InsertSort_Desc(int *a, int len)
{
    if (len < 2)
        return;
    for (int i = 1; i < len; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] < key) //核心比较位置
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
/*
2.1-3
输入：A=<a1,a2,a3,...an> and v
输出：i,使得v=ai，若不存在则输出NIL
伪代码：
FindV(A,v):
    for j = 1 to A.length
        if A[j] == v
            return j
    return NIL
循环不变式
初始化：开始前，j从1开始判断第一个元素是否等于v,若等于则返回，否则判断下一个
保持：
终止：
*/
/*
2.1-4
输入：二进制加法 长度都是为n的数组A和数组B,数字为二进制整数（0/1）
输出：长度为n+1的数组C = 数组A+数组B
伪代码：
Add(A,B):
    k = 0
    for i=1 to A.Length
        r = A[i]+B[i] + k
        if r == 2
            C[i] =0
            k = 1
        else if r==3
            C[i]=1
            k = 1
        else
            C[i]=r
            k=0
    C[i+1]=k
    return C
*/
/*
2.2-2 选择排序
输入：乱序的数字数组A
输出：非降序的数组A
SelectSort(A):
    for i = 1 to A.Length
        for j=i+1 to A.Lenght
            if A[i] > A[j]
                t = A[i]
                k = A[j]
                A[j] = t
*/

/*
2.3-1
说明分治法排序 A=<3,41,52,26,38,57,9,49> 的执行过程
执行开始:
拆分:<3,41,52,26     ,38,57,9,49>
----
拆分:<3,41      ,52,26,...>
拆分:<3   ,41,52   ,26,...>
合并:<3,41   ,52   ,26,...>
合并:<3,41      ,26,52,...>
合并:<3,26,41,52      ,...>
----
拆分:<...|38,57      ,9,49>
拆分:<...|38    ,57  ,9     ,49>
合并:<...|38,57      ,9     ,49>
合并:<...|38    ,57  ,9,49>
合并:<...|9,38,49,57>
----
合并:<3,9,26,38,41,49,52,57>
执行结束.
*/
/*
2.3-2 改写的不使用哨兵元素的MERGE过程 01Sort.c/void Merge(int *a, int p, int q, int r)
*/
/*
2.3-3
*/
/*
2.3-4 插入排序的递归实现
思路：为排序A[1..n]，首先排序A[1..n-1]，然后将A[n]插入到A[1..n-1]中,依次递归
递归开始条件为：数组元素数量>1
递归终止条件为：数组元素数量=1
*/

void InsertToSortedArray(int v, int *a, int len)
{
    if (len <= 0)
        return;
    int i = len;
    while (len > 0)
    {
        if (a[len - 1] > v)
        {
            a[len] = a[len - 1];
            i = len - 1;
        }
        len--;
    }
    a[i] = v;
}

void InsertSort_Recursion(int *a, int len)
{
    if (len > 1)
    {
        InsertSort_Recursion(a, len - 1);
        InsertToSortedArray(a[len - 1], a, len - 1);
    }
}

/*
2.3-5 二分查找 时间复杂度lgn
对已排序的序列A查找某个值v,在A中的索引
输入：已排序的数组A,查找值v
输出：返回v在A中的索引值，不存在则返回-1
*/
int Binary_Search(int *a, int p, int q, int v)
{
    if (p > q)
        return -1;
    if (p == q)
        return a[p] == v ? p : -1;
    if (q - p == 1)
        return a[q] == v ? q : -1;
    int i = (p + q) / 2;
    if (a[i] == v)
        return i;
    else if (a[i] > v)
        return Binary_Search(a, p, i, v);
    else
        return Binary_Search(a, i, q, v);
}

/*
2.3-6 将插入排序中的插入查找位置改为二分查找
是否可将其时间复杂由n^2改善为nlgn
*/

