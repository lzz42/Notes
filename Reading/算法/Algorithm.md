# 算法

## 基础知识

### 一.算法在计算中的应用

* 什么是算法

> 任何良计算的过程
> NP完全问题：

* 作为一种技术的算法

> 效率：
> 插入排序cN^2,归并排序cNlgN

* 分析算法

> 通用的单处理器计算模型-RAM random-access machine
> 1.包含计算机内常见的指令：算术指令，数据移动指令，控制指令
> 2.每条指令的所需时间为常亮
> 3.不对内存层次进行建模

* 最坏情况和平均情况分析

> 增长量级

* 插入排序伪代码

```伪代码
    //Insortion-sort(A)
    for j=2 to A.length
        key = A[j]
        //Insert A[j] to sequence A[1...j-1]
        i = j-1
        while i > 0 && A[i] > key
            A[i+1] = A[i]
            i = i-1
        A[i+1] = key
```

* 分治法 - 归并排序

> 将原问题分解为几个规模较小但类似原问题的子问题，递归求解子问题，然后合并子问题的解建立原问题的解
> 1.分解：原问题分解为子问题
> 2.解决：解决子问题
> 3.合并：合并子问题的结果
> 归并排序：
> 关键：合并

```伪代码
    //合并已经排序好的数组A[p,q] A[q+1,r] p<=q<r
    //定义哨兵infine
    merge(A,p,q,r)
    n1 = q - p + 1
    n2 = r -q
    let L[1..n1+1] and R[1..n2+1] be new arrays
    for i = 1 to n1
        L[i] = A[p+i-1]
    for j = 1 to n2
        R[j] = A[q+j]
    L[n1+1]=infine
    R[n2+1]=infine
    i=1
    j=1
    for k=p to r
        if L[i]<=R[j]
            A[k]=L[i]
            i=i+1
        else A[k]=R[j]
            j=j+1
```

> merge-sort

```伪代码
    merge-sort(A,p,r)
    if p<=r
        q=(p+r)/2
        merge-sort(A,p,q)
        merge-sort(A,q+1,r)
        merge(A,p,q,r)
```
