# 05 概率分析和随机算法

- 5.1-2

```C
/*
输入:函数R0以同等概率输出0/1
输出：函数Rx输出随机值为a-b
*/
int Rx(int a,int b)
{
    int r=a;
    while(a<=b)
    {
        r+=R0(0,1);
        a++;
    }
    return r;
}
```

- 5.1-3
  - 条件：函数R0,以概率p输出1,以概率1-p输出0
  - 求解：使用函数R0构建函数R1，以1/2概率输出0/1
> 分析：
当$x=R0()时,x取值$

| x   | 概率 |
| --- | ---- |
| 0   | 1-p  |
| 1   | p    |

当$y=R0()时,x+y取值$

| x+y | 概率                |
| --- | ------------------- |
| 0+0 | $(1-p) \cdot (1-p)$ |
| 1+0 | $p \cdot (1-P)$     |
| 0+1 | $(1-p) \cdot p$     |
| 1+1 | $p \cdot p$         |

由此可以看出，对于x+y=1时，出现两种情况即(1+0)和(0+1)两者的概率都是$p(1-p)$,利用这个两个情况输出的值两个值的概率是相同的，仅输出者两个值时，其概率都是1/2
> 算法：
```C
/*
输出：函数R0以概率p输出1，概率1-p输出0
输出：函数R1,以同等概率输出0/1
*/
int R1()
{
    int x0 =R0();
    int x1 =R0();
    if(x0+x1==1)
        return x;
    else
        return R1();
}
```

- 5.3-2

```
Permute=without-indentity(A)
    n = length(A)
    for i=1 to n-1
        do swap A[i],A[Random(i+1,n)]
```

> 并不能实现其意图，原因：只能产生所有元素不在原排列位置的随机排列，但是不能生成部分元素在原位置的随机排列<br>
> 全排列总数为:n!,非同一指定排列的总数应该是n!-1,但是该算法只能产生：(n-1)(n-2)...1种排列，即(n-1)!种<br>
> 其总数有：n!-(n-1)!=(n-1)!*(n-1)未生成，所以不能实现其目的

- 5.3-3

```
Permute-with-all(A)
    n=length(A)
    for i=1 to n
        do swap A[i],A[Random(1,n)]
```

> 不会产生均匀随机排列，原因：<br>
> 队列A的随机排列总数为：n!,但该算法可产生的随机排列总数为：$n^n$,因此有部分排列是重复的<br>
> 若$\frac{n^n}{n!}$是整数则可能出现每个队列的重复数量是相同的，从而可能是均匀随机排列<br>
> 但事实上当n>2时，$\frac{n^n}{n!}$其结果不可能为整数，意味着总会出现某些排列的重复次数较多，从而导致其出现概率较大，因此该算法的不能产生均匀随机排列

- 5.3-4
  - 证明：任意元素A[i]出现在B中任何特定位置的概率都是1/n,并证明该算法不能产生均匀随机排列

```
Permute-by-cyclic(A)
    n=length(A)
    offset=Random(1,n)
    for i=1 to n
        do dest = i+offset
            if dest>n
                then dest=dest-n
            B[dest]=A[i]
    return B
```

> 证明:令$X_i$表示元素A[i]出现在B中的位置i的事件，则$P_r\{X_i\}=\frac{1}{n}$<br>
> 对于某个特定的排列其出现的概率为：$P_r\{X_0 \cap X_1 \cap \cdots \cap X_n\} =\frac{1}{n} \cdot \frac{1}{n}\cdots \frac{1}{n} = \frac{1}{n^n}$,但对于n个元素的全排列总数为n!，且当n>2时，$\frac{n!}{n^n} < 1$，说明某些排列出现至少2次，但$\frac{n!}{n^n}不是整数$，<br>
> 所以肯定会出现某些排列出现的重复次数较少，因此该排序出现的概率较小，从而该算法并不能产生均匀随机排列

- 5.3-5 证明：算法Permute-by-sorting的数组P中，所有元素都唯一的概率至少为1-1/n

```
Permute-by-sorting(A)
    n=length(A)
    for i=1 to n
        do P[i]=Random(1,n*n*n)
    sort A,using P as sort key
    return A
```

> 证明：所有的可能出现的数组P总数为：$n^3 \cdot n^3 \cdot \cdots \cdot n^3=n^{3n}$<p>
> 出现数组P中所有元素都不重复的总数为：$n^3\cdot(n^3-1)\cdot \cdots \cdot (n^3-n+1)=\frac{n^3!}{(n^3-n)!}$<br>
> 因此其概率为：<br>
> $\frac{\frac{n^3!}{(N^3-n)!}}{n^{3n}}=\frac{n^3!}{n^{3n}(n^3-n)!}=\frac{n^3\cdot(n^3-1) \cdots (n^3-n+1)}{n^{3n}}=1\cdot(1-\frac{1}{n^3})\cdot(1-\frac{2}{n^3})\cdots (1-\frac{n-1}{n^3}) > 1\cdot (1-\frac{1}{n^3})\cdot (1 - \frac{1}{n^3}) \cdots (1-\frac{1}{n^3}) =1 \cdot (1-\frac{1}{n^3})^{n-1}$