[a012. 10055 - Hashmat the Brave Warrior - 高中生程式解題系統](https://zerojudge.tw/ShowProblem?problemid=a012)

```c
#include <stdio.h>
#include <stdlib.h>

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    else {
        return n;
    }
}

int main() {
    long long int a, b;

    while (scanf("%lld", &a) == 1 && scanf("%lld", &b) == 1) {
        printf("%lld\n", abs(a - b));
    }

    return 0;
}
```

$$
\begin{array}{rcl}
dd \\
dddd
\end{array}
$$

$$
\text{abs}(n) = |n| = 
\begin{cases}
n, & \text{if } n \geq 0 \\
-n, & \text{if } n < 0
\end{cases}
$$