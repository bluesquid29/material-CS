# Guideline

## Median

-  [The median minimizes the sum of absolute deviations (the ℓ1 norm)](https://math.stackexchange.com/questions/113270/the-median-minimizes-the-sum-of-absolute-deviations-the-ell-1-norm)
- [三分搜尋法 - HackMD](https://hackmd.io/@ShanC/ternary-search#%E6%80%A7%E8%B3%AA-%E4%B8%AD%E4%BD%8D%E6%95%B8%E6%9C%80%E5%B0%8F%E5%8C%96%E7%B5%95%E5%B0%8D%E5%81%8F%E5%B7%AE%E7%9A%84%E5%92%8C%20%E8%A3%A1%E9%9D%A2%E5%8C%85%E5%90%AB%E4%BA%86%E5%85%A9%E7%A8%AE%E8%A7%A3%E6%B3%95%E7%9A%84%20code)

絕對值離中位數差之和
$$
\sum_{k=1}^{n} \lvert x_{k} - \text{ Median} \rvert  \leq \sum_{k=1}^{n} \lvert x_{k} - \alpha \rvert, \quad \alpha \in \mathbb{R} 
$$

---

如果對高中題目有印象，曾出現過這種題：
$$
\text{Find the Min. of } f(x) = \lvert x-1 \rvert +\lvert x-2 \rvert  + \lvert x-6 \rvert + \lvert x-9 \rvert 
$$
解為：
$$
2 \leq x \leq 6
$$

---

事實上，解此題的知識點即是：
$$
\text{Find the Min. of } f(x) = \lvert x-a_{1} \rvert +\lvert x-a_{2} \rvert  + \dots + \lvert x-a_{n-1} \rvert + \lvert x-a_{n} \rvert 
$$


# Code
## C
### Solution 1

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, r, i, j;
    int streets[500];
    int median, sum, temp;
    
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &r);
        
        for (i = 0; i < r; i++) {
            scanf("%d", &streets[i]);
        }
        
        // Bubble sort - sort the street numbers
        for (i = 0; i < r - 1; i++) {
            for (j = 0; j < r - i - 1; j++) {
                if (streets[j] > streets[j + 1]) {
                    // Swap
                    temp = streets[j];
                    streets[j] = streets[j + 1];
                    streets[j + 1] = temp;
                }
            }
        }
        
        // Find median (middle element)
        median = streets[r / 2];
        
        // Calculate sum of distances
        sum = 0;
        for (i = 0; i < r; i++) {
            if (streets[i] > median) {
                sum += streets[i] - median;
            } else {
                sum += median - streets[i];
            }
        }
        
        printf("%d\n", sum);
    }
```