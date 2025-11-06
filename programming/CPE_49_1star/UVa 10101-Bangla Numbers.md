# Reference

- [a741. 10101 - Bangla Numbers - 高中生程式解題系統](https://zerojudge.tw/ShowProblem?problemid=a741)
- [UVa 10101-Bangla Numbers - Online Judge](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1042&mosmsg=Submission+received+with+ID+30781504)
# Guideline
## 
# Code
## In-output

```
23764
45897458973958
```

```
   1. 23 hajar 7 shata 64
   2. 45 lakh 89 hajar 7 shata 45 kuti 89 lakh 73 hajar 9 shata 58
   3. 2 kuti 34 lakh 56 hajar 7 shata 89
```

## C
### Solution 1

```c
#include <stdio.h>
#include <stdlib.h>

void printBangla(long long n) {
    if (n == 0) {
        return;
    }
    
    long long kuti = 10000000;
    long long lakh = 100000;
    long long hajar = 1000;
    long long shata = 100;
    
    if (n >= kuti) {
        printBangla(n / kuti);
        printf(" kuti");
        n %= kuti;
    }
    
    if (n >= lakh) {
        printBangla(n / lakh);
        printf(" lakh");
        n %= lakh;
    }
    
    if (n >= hajar) {
        printBangla(n / hajar);
        printf(" hajar");
        n %= hajar;
    }
    
    if (n >= shata) {
        printBangla(n / shata);
        printf(" shata");
        n %= shata;
    }
    
    if (n > 0) {
        printf(" %lld", n);
    }
}

int main() {
    long long n;
    int caseNum = 1;
    
    while (scanf("%lld", &n) != EOF) {
        printf("%4d.", caseNum++);
        
        if (n == 0) {
            printf(" 0");
        } else {
            printBangla(n);
        }
        
        printf("\n");
    }
    
    return 0;
}
```