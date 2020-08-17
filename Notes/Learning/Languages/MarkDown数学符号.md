# MarkDown数学符号

## 参考资料

- https://www.zybuluo.com/codeep/note/163962
- https://math.meta.stackexchange.com/questions/5020/mathjax-basic-tutorial-and-quick-reference?page=1&tab=votes#tab-top
- https://math.meta.stackexchange.com/questions/5020/mathjax-basic-tutorial-and-quick-reference?page=2&tab=votes#tab-top
- http://docs.mathjax.org/en/latest/tex.html#supported-latex-commands
- https://www.matheretter.de/rechner/latex/
- https://blog.csdn.net/qq_39422642/article/details/78276002#2-9-%E6%9D%A1%E4%BB%B6%E5%81%8F%E5%AF%BC
- [LaTex](https://www.latex-project.org/)

## 基本语法

- 正文：`$...$`
- 正文居中：`$$...$$`

## 希腊字母表

| 显示       | 命令     | 显示     | 命令   |
| ---------- | -------- | -------- | ------ |
| $\alpha$   | \alpha   | $\beta$  | \beta  |
| $\gamma$   | \gamma   | $\delta$ | \delta |
| $\epsilon$ | \epsilon | $\zeta$  | \zeta  |
| $\eta$     | \eta     | $\theta$ | \theta |
| $\iota$    | \iota    | $\kappa$ | \kappa |
| $\lambda$  | \lambda  | $\mu$    | \mu    |
| $\xi$      | \xi      | $\nu$    | \nu    |
| $\pi$      | \pi      | $\rho$   | \rho   |
| $\sigma$   | \sigma   | $\tau$   | \tau   |
| $\phi$     | \phi     | $\chi$   | \chi   |
| $\psi$     | \psi     | $\omega$ | \omega |

- 大写：$\Omega$ - `$\Omega$`
- 斜体：$\varOmega$ - `$\varOmega$`

## 常见数学符号

- 上标：$\Omega^\Pi$ - `$\Omega^\Pi$`
- 下标：$\Omega_0$ - `$\Omega_0$`
- 上下标：$\Omega^\Pi_0$ \ $\Omega_0^\Pi$
- 矢量：$\vec a$ $\vec{a}$ - `$\vec a$ $\vec{a}$`
  - $\overrightarrow{ab}$ $\overleftarrow{ab}$ - `$\overrightarrow{ab}$ $\overleftarrow{ab}$`
- 分组：
  - $\omega^{4\pi} + \omega^4\pi$
- 括号：
  - 小括号：$\alpha*(\beta+\gamma)$
  - 中括号：$\alpha[\beta+\gamma]$
  - 尖括号：$\alpha\langle\beta+\gamma\rangle$
  - 大括号：$\alpha\{\beta+\gamma\}$
- 求和：$\sum_0^{10}$ -`\sum_0^{10}`
- 极限：$\lim_{x \to 0}{f(x)}$ - `\lim_{x \to 0}{f(x)}`
- 积分：$\int_0^\infty{f(x)dx} \quad \iint \quad \oint \quad \nabla$ - `\int_0^\infty{f(x)dx} \quad \iint \quad \oint \quad \nabla`
- 分式：$\frac{f(x)}{g(x)}$ - `\frac{f(x)}{g(x)}`
- 根式：$\sqrt[x]{f(x)}$ - `\sqrt[x]{f(x)}`
- 函数：$\lim_{x \to 0}{\frac{x}{\sin x}}=1$
- 运算符号：$a+b|a-b|a \times b|a \div b| a\pm b$
- 比较符号：$a=b|a\neq b|a\approx b|a\leq b|a\geq b$
- 条件：$\forall \epsilon >0,\exists \delta >0$
- 省略号:$\dots \quad \cdots$
- 等价无穷小：$\sim$ `\sim`
- 关系运算符：
- 偏导：\partial $\partial$
- 上取整：`\lceil x \rceil `-$\lceil x \rceil$
- 下取整：`\lfloor x \rfloor `-$\lfloor x \rfloor$
- 连乘：`\prod (a+b)`-$\prod (a+b)$
- 连分数：`x1+\cfrac{a}{x2+\cfrac{x3}{\cdots}}` - $x1+\cfrac{a}{x2+\cfrac{x3}{x4+\cdots}}$
- 模运算：`\mod` - $x \equiv a \pmod z$

## 格式

$$

f(x)=ax+b \qquad \quad \text{注释文字}  换行  \\
f(x)=ax+b \qquad \quad \text{注释文字}  换行 \\
\tag{行标}

$$

## 集合运算符

$$
∅：\emptyset \\
∈：\in \\
∉：\notin \\
⊂：\subset \\
⊃ ：\supset \\
⊆ ：\subseteq \\
⊇ ：\supseteq \\
⋂ ：\bigcap \cap\\
⋃ ：\bigcup \cup\\
⋁ ：\bigvee \\
⋀ ：\bigwedge \\
⨄ ：\biguplus \\
⨆：\bigsqcup \\
$$

## 带帽符号

- $\hat{ab}$    - `\hat{ab}`
- $\tilde{ab}$  - `\tilde{ab}`
- $\check{ab}$  - `\check{ab}`
- $\grave{ab}$  - `\grave{ab}`

## 分段函数

$$
f(n)=
\begin{cases}
n/2,  & \text {if $n$ is even} \\[2ex]
3n+1, & \text {if $n$ is odd} \\[4ex]
\end{cases} \\
$$

## 方程组

$$
\left \{
  \begin{array}{c}
    ax+by=z\\
    ax+by=z\\
    ax+by=z\\
  \end{array}
\right.
$$

## 其他字符

| 显示              | 命令            | 显示             | 命令           | 显示              | 命令            |
| ----------------- | --------------- | ---------------- | -------------- | ----------------- | --------------- |
| $\pm$             | \pm             | $\times$         | \times         | $\div$            | \div            |
| $\mid$            | \mid            | $\nmid$          | \nmid          |
| $\circ$           | \circ           | $\ast$           | \ast           | $\cdot$           | \cdot           |
| $\bigotimes$      | \bigotimes      | $\bigoplus$      | \bigoplus      | $\bigodot$        | \bigodot        |
| $\leq$            | \leq            | $\geq$           | \geq           | $\neq$            | \neq            |
| $\uparrow$        | \uparrow        | $\downarrow$     | \downarrow     | $\leftrightarrow$ | \leftrightarrow |
| $\rightarrow$     | \rightarrow     | $\leftarrow$     | \leftarrow     | $\Leftrightarrow$ | \Leftrightarrow |
| $\longrightarrow$ | \longrightarrow | $\longleftarrow$ | \longleftarrow |

## 字体

- `\字体 {需要转换字体的内容}`
- `\字体列表`：
  - 罗马体 \rm
  - 粗体 \bf
  - 等线体 \sf
  - 花体 \cal
  - 数学斜体 \mit

$$
正常：f(x)dx =\alpha x^3 + bx^2 + cx + d \\
罗马体: {\rm {f(x)dx=\alpha x^3 + bx^2 + cx + d}}\\
粗体: {\bf  {f(x)dx=\alpha x^3 + bx^2 + cx + d}}\\
花体: {\cal {f(x)dx=\alpha x^3 + bx^2 + cx + d}}\\
等线体:{\sf {f(x)dx=\alpha x^3 + bx^2 + cx + d}}\\
数学斜体: {\mit {f(x)dx=\alpha x^3 + bx^2 + cx + d}}\\
$$

### MarkDown转HTML

- JS库：
  - [JS实现的Markdown解析器](https://github.com/markedjs/marked)：将md文件解析为对应的html文件；
  - [evilstreak/markdown-js](https://github.com/evilstreak/markdown-js)
  - [markedjs/marked](https://github.com/markedjs/marked)
- Python库：
  - [html2text](https://pypi.org/project/html2text/)
- .Net库：
  - [marddig](https://github.com/lunet-io/markdig)

### 如何根据Markdown生成静态html网页

- https://walkccc.github.io/CLRS/
- https://www.mkdocs.org/
- https://squidfunk.github.io/mkdocs-material/