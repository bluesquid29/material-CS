# Reference

- [e555. 10170 - The Hotel with Infinite Rooms - 高中生程式解題系統](https://zerojudge.tw/ShowProblem?problemid=e555)
- [UVa 10170-The Hotel with Infinite Rooms - Online Judge](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1111)
# Guideline

## In-output

```
1 6
3 10
3 14
```

```
3
5
6
```

## Summary 

題目很冗長，直接看輸入，S與D：

- S：第一批入住的人數(第一天)
	- 入住人數 = 入住幾天
- D：尋找第D天的入住人數
	- EX1: $\{ 1, 2, 2, 3, 3, 3  \}$
	- EX2: $\{ 3, 3, 3, 4, 4, 4, 4, 5, 5, 5 \}$
	- EX2: $\{ 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6  \}$

## Hints

- $1 + 2 + 3 \geq 6$
- $3 + 4 + 5 \geq 10$
- $3 + 4 + 5 + 6 \geq 14$
# Code
## C
### Solution 1

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    long long s, d;
    
    while (scanf("%lld %lld", &s, &d) == 2) {
        long long sum = 0;
        long long group = s;
        
        while(sum < d) {
            sum += group;
            group++;
        }
        
        printf("%lld\n", group - 1);
    }
    
    return 0;
}
```


