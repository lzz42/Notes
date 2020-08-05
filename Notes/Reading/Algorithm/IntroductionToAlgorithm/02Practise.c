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
        while (j > 0 && a[j] < key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
/*
2.1-3
*/