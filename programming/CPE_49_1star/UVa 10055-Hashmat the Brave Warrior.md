# Reference

- [a012. 10055 - Hashmat the Brave Warrior - 高中生程式解題系統](https://zerojudge.tw/ShowProblem?problemid=a012)
- [UVa 10055 Hashmat the Brave Warrior - Online Judge](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=996&mosmsg=Submission+received+with+ID+30781473)

# Guideline

## Hint

- use `long long int`, `%lld`

$$
\text{abs}(n) = |n| = 
\begin{cases}
n, & \text{if } n \geq 0 \\
-n, & \text{if } n < 0
\end{cases}
$$

# Code
## In-output

```input
10 12
10 14
```

```output
2
4
```
## C
### Solution 1

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

    while (scanf("%lld %lld", &a, &b) == 2) {
	    printf("%lld\n", llabs(a - b));
	}


    return 0;
}
```


