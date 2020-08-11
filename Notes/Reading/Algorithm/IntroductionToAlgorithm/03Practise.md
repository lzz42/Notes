# 03.函数的增长

- 3.1-1 条件：f(n),g(n)为渐进非负函数 证明：$max(f(n),g(n))=\Theta(f(n)+g(n))$
> 证明：
$$
\begin{aligned}
&令F(n) = max(f(n),g(n)),G(x)=f(n)+g(n)\\
&由于f(n),g(n)为渐进非负函数,所以F(n)同样为渐进非负函数\\
&且f(n) \geq 0,g(n) \geq 0,所以0 < F(n) \leq G(n)\\
&假设存在常量c_1,c_2，以及n_0,使得当n>n_0时，\\
&c_1G(n) \leq F(n) \leq c_2 G(n) \qquad \text{(1)}\\
&不等式除以G(n)后\\
&c_1 \leq \frac{F(n)}{G(n)} \leq c_2\\
&且 F(n) \leq G(n),所以\frac{F(n)}{G(n)} \leq 1 ,此时取n_0 = [\frac{F(n)}{G(n)}]\\
&当n>n_0时,f(n),f(n)为具体函数时，存在常量的c_1,c_2,令等式(1)成立\\
&所以：max(f(n),g(n))=\Theta(f(n)+g(n)) \\
\end{aligned}
$$

- 3.1-2 证明：$对任意实数常数a,b,且b>0都有：(n+a)^b = \Theta(n^b)$
> 证明：
$$
\begin{aligned}
&假设存在常量c_1,c_2,以及n_0,当n>n_0时,\\
&c_1n^b \leq (n+a)^b \leq c_2n^b\\
&由于n>0,b>0,等式除以n^b后\\
&c_1 \leq \frac{(n+a)^b}{n^b} \leq c_2\\
&c_1 \leq (1+\frac{a}{n})^b \leq c_2\\
...
\end{aligned}
$$

- 3.1-3 
