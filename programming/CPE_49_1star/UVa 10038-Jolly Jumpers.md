# Reference

- [UVa 10038-Jolly Jumpers - Online Judge](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=979&mosmsg=Submission+received+with+ID+30787951)
- [d097. 10038 - Jolly Jumpers - 高中生程式解題系統](https://www.zerojudge.tw/ShowProblem?problemid=d097)
# Guideline
## In-output
## Summary 
## Hints
# Code
## C
### Solution 1

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        int arr[3000];
        int check[3000] = {0};  // check[i] = 1 if difference i exists
        
        // Read the sequence
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        // Calculate absolute differences and mark them
        for (int i = 0; i < n - 1; i++) {
            int diff = abs(arr[i + 1] - arr[i]);
            if (diff < n) {
                check[diff] = 1;
            }
        }
        
        // Check if all values from 1 to n-1 are present
        int jolly = 1;
        for (int i = 1; i < n; i++) {
            if (check[i] == 0) {
                jolly = 0;
                break;
            }
        }
        
        if (jolly) {
            printf("Jolly\n");
        } else {
            printf("Not jolly\n");
        }
    }
    
    return 0;
}
```