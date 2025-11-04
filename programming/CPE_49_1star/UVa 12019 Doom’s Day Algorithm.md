- [UVa 12019 - Doom’s Day Algorithm](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3170)
- [f709. 12019 - Doom's Day Algorithm - 高中生程式解題系統](https://zerojudge.tw/ShowProblem?problemid=f709)

## C

### Code 1

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int t, m, d;
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char day_names[][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    scanf("%d", &t);
    
    while (t--) {
    	scanf("%d %d", &m, &d);
        
        // Calculate total days from January 1, 2011
        int total_days = d;
        for (int i = 1; i < m; i++) {
            total_days += days_in_month[i];
        }
        
        // January 1, 2011 was a Saturday (day 6)
        // So we start from day 6 and add the days
        int day_of_week = (6 + total_days - 1) % 7;
        
        printf("%s\n", day_names[day_of_week]);
    }
    
    return 0;
}
```

#### Explain 1

- the compiler will automatically determine the size of array based on the number of elements you provide
- The alternative: array of pointers to strings

```c
char *day_names[]
```

- `while (t--)` means `while (t-- > 0)`, if `t = 5`

>runs the loop until `t` is `0` during checking it's value, since `0` is equally to `false` in a logical context.
>
>Because `t--` is the post decremental operator on `t`, the value of it will be modified after the `while` checks it, so it will be -1 in the end. Therefore, the values of `t` inside the loop will be: 4,3,2,1,0.

- The example of day count

```
For January 6, 2011: 
total_days = 6, day = (6 + 6 - 1) % 7 = 4 (Thursday)

For February 27, 2011: 
total_days = 31 + 27 = 58, day = (6 + 58 - 1) % 7 = 0 (Sunday)
```
