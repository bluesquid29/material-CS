# Reference

- [d226. 10071 - Back to High School Physics - 高中生程式解題系統](https://zerojudge.tw/ShowProblem?problemid=d226)
- [UVa 10071-Back to High School Physics - Online Judge](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=1012)
# Guideline
## In-output
## Summary 

- displacement 位移

加速度、位移公式，(v-t圖)：

$$
\begin{align}
&v = v_{0} + at \\
&\Delta x = v_{0}t + \frac{1}{2} at^{2}
\end{align}
$$
## Hints

求在 2t 秒後經過的位移，消掉未知 $v_{0}$

$$
\begin{align}
\Delta x_{2} = v_{0} (2t) + \frac{1}{2}a (2t)^{2} &= 2vt - 2at^{2} + 2at^{2} \\
&= 2vt
\end{align}
$$

# Code
## C
### Solution 1

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int v, t;
    
    while (scanf("%d %d", &v, &t) == 2) {
        printf("%d\n", 2 * v * t);
    }
    
    return 0;
}
```