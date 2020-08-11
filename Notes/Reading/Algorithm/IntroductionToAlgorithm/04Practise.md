# 04 递归式

- 4.3-1 
> 解：
$$
\begin{aligned}
&a.T(n)=4T(n/2)+n \\
&\qquad f(n)=n,n^{\log_b{a}}=n^{\log_2{4}}=n^2,\epsilon=1,f(n)=O(n^{\log_2{4}-\epsilon}),情况1\\
&\qquad 因此T(n)=\Theta(n^2)\\
&b.T(n)=4T(n/2)+n^2 \\
&\qquad n^{\log_b{a}}=n^2,f(n)=n^2=\Theta(n^2),情况2\\
&\qquad 因此T(n)=\Theta(n^2\cdot \lg{n})\\
&c.T(n)=4T(n/2)+n^3 \\
&\qquad n^{\log_b{a}}=n^2,f(n)=n^3=\Omega(n^{2+\epsilon})\\
&\qquad af(n/b)=4(n/2)^3=\frac{n^3}{2} \leq cf(n)=cn^3,取1>c>\frac{1}{2},即可满足情况3\\
&\qquad 因此T(n)=\Theta(n^3)\\
\end{aligned}
$$

- 4.3-2 算法A:$T(n)=7T(n/2)+n^2$,算法B:$T(n)=aT(n/4)+n^2$
> 解：
$$
\begin{aligned}
&算法A的紧确界：n^2 =\Omega(n^{\log_2{7}-\epsilon})成立，T(n)=\Theta(n^{\log_2{7}})\\
&算法B的紧确界分析：n^{\log_4{a}} 与n^2\\
&\qquad 若a>16,则满足n^2=\Omega(n^{\log_4{a}-\epsilon}),则T(n)=\Theta(n^{\log_4{a}})\\
&\qquad 若a=16,则满足n^2=\Theta(n^2),则T(n)=\Theta(n^{\log_4{a}}\cdot \lg{n})\\
&\qquad 若a<16, \\
\end{aligned}
$$ 