# 基础ABC

## A 求和

- 级数的发散与收敛
  - 线性性质

$$
\sum_{k=1}^{\infty}{(ca_k+b_k)}=c\sum_{k=1}^{\infty}{a_k}+\sum_{k=1}^{\infty}{b_k} \\
\sum_{k=1}^{n}{\Theta(f(k))}=\Theta(\sum_{k=1}^{n}{f(k)})\\
$$

$$
\begin{aligned}
    &等差级数\\
        &\qquad \sum_{k=1}^{n}{k}=\frac{n(n+1)}{2}=\Theta(n^2)\\
        &\qquad \sum_{k=0}^{n}{k^2}=\frac{n(n+1)(2n+1)}{6}\\
        &\qquad \sum_{k=0}^{n}{k^3}=\frac{n^2(n+1)^2}{4}\\
    &几何级数\\
        &\qquad \sum_{k=0}^{n}{x^k}=\frac{x^{n+1}-1}{x-1},{x \in R,x \neq 1}\\
        &\qquad \sum_{k=0}^{n}{x^k}=\frac{1}{n},|x|<1\\
    &调和级数\\
        &\qquad H_n=\sum_{k=1}^{n}{\frac{1}{k}}=\ln{n}+\Omicron(1)\\
    &级数的积分和微分\\
        &\qquad \sum_{k=1}^{\infty}{kx^k}=\frac{x}{(1-x)^2}\\
    &套迭级数\\
        &\qquad \sum_{k=1}^{n}{a_k-a_{k-1}}=a_n-a_0\\
        &\qquad \sum_{k=1}^{n}{\frac{1}{k(k+1)}}=1-\frac{1}{n}\\
\end{aligned}
$$

- 有限乘积
$$
\prod_{k=1}^{n}{a_k}\\
通过转换将连乘转变为求和：\lg{(\prod_{k=1}^{n}{a_k})}=\sum_{k=1}^{n}{\lg{a_k}}\\
$$