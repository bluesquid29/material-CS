
## Absolute Value

$$
\text{abs}(n) = |n| = 
\begin{cases}
n, & \text{if } n \geq 0 \\[4pt]
-n, & \text{if } n < 0
\end{cases}
$$

```c
int abs(int n) {
    if (n < 0) {
        return -n;
    }
    else {
        return n;
    }
}
```

