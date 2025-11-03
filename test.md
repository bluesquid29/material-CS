## 導數 Derivative

> [!summary] Definition
> $f(x)$ 在 $x_{0}$ 的某領域內有定義，如果極限
>
> $$
> \lim_{ h \to 0 } \frac{f(x_{0} + h) - f(x_{0})}{h}
> $$
>
> 存在，則稱 $f(x)$ 在 $x_{0}$ 處**可導 (derivable)**
>
> 並稱上述極限值為 $f(x)$ 在 $x_{0}$ 處的**導數 (derivative)**，記作
>
> $$
> f'(x_{0})
> $$
>
> 根據定義，也可以稱作 $f(x)$ 在 $x_{0}$ 處的**變化率 (rate of change)**、**切線斜率 (the slope of tangent line)**
>
> ---
>
> 若函數 $f$ 在其定義域內的每一點都有導數，
> 則稱此新函數為 $f$ 的**導函數 (derivative of f)**，記作 $f'$ **(the derivative function)**
>
> $$
> f'(x) = \lim_{ h \to 0 } \frac{f(x + h) - f(x)}{h}
> $$
>
> 尋找已知的函數在某點的導數、或其導函數的過程稱為**求導 (differentiation)**，動詞 **(differentiate)**

## 微分 differential

> [!summary] Definition
> 若 $f$ 在點 $x$ 之導數存在，則稱 $f$ 在點 $x$ **可微 (differentiable)**
>
> ---
>
> 設函數 $y = f(x)$ 在 $x_{0}$ 處連續，若存在實數 $A$ ，使得
>
> $$
> \Delta y =  f (x_{0} + \Delta x) - f(x_{0}) = A \Delta x + o(\Delta x)
> $$
>
> 其中 $\Delta x \rightarrow 0$ ，則稱 $f(x)$ 在 $x_{0}$ 處**可微 (differentiable)**
>
> 並稱線性部分 $A\Delta x$ 為 $f(x)$ 在 $x_{0}$ 處的**微分 (differential)** ，記作 $dy$

## 連續 Continuous

> [!abstract] Definition
> 定義
>
> $$
> \lim_{ x \to c } f(x) = f(c)
> $$
>
> 為 $f(x)$ 在 $x = c$ 連續
>
> ---
>
> 連續性判定法 (Continuity Test)
>
> $$
> f(x) \text{在 } x = c \text{ 連續 } \iff\left \{
> \begin{align}
> &f(c) \quad \exists \\[4pt]
> &\lim_{ x \to c } f(c) \quad \exists \\[4pt]
> &\lim_{ x \to c } f(x) = f(c)  \\[4pt]
> \end{align}\right.
> $$

---

## 關係1

微分和導數是兩個不同的概念。
導數的幾何意義是「變化率」，而微分的幾何意義是「線性替代」
對一元函數來說，可微與可導是完全等價的

$$
\begin{align}
&\text{可導} \iff \text{可微} \implies \text{連續} \\[4pt]
&\text{連續} \centernot\implies \text{可微} \iff \text{可導}
\end{align}
$$

> [!info] Theorem
> 若 $f$ 在 $x = c$ 可導，則 $f$ 在 $x = c$ 連續

連續不一定可導 (EX1, 2, 3)
不可導，即極限不存在
EX:

1. corner 轉角點 (左導數 $\neq$ 右導數)
$$
\left.\frac{d}{dx} (|x|) \right|_{x=0}
$$
2. cusp 尖點 (導數(斜率)不存在)
   $$
   \left.\frac{d}{dx} (x ^{2/3})\right|_{x=0}
   $$
3. Point with vertical tangent 垂直切線點 (導數(斜率)不存在)
   $$
   \left.\frac{d}{dx}\sqrt{x}\right |_{x=0}
   $$
4. Discontinuity 不連續點 (不連續必不可導)
5. sdsds
sdsd
sdsdsd
    sdsdsd
    sdsd
2. sdsds
sd  sdsd

![[Thomas Calculus Early Transcendentals, 15ed.pdf#page=148&rect=99,91,584,487|Thomas Calculus Early Transcendentals, 15ed, p.146]]


To find the derivative of \(a^x\) (where \(a > 0\) and \(a \neq 1\)) using the **definition of the derivative**, we start with the limit definition:

