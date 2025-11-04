- [d255. 11417 - GCD - 高中生程式解題系統](https://zerojudge.tw/ShowProblem?problemid=d255)

# Guideline of GCD

- [C Program to Find the Greatest Common Divisor (GCD)](https://coderscratchpad.com/c-program-to-find-the-greatest-common-divisor-gcd/)

We use the Euclidean Algorithm to find GCD. the code by C

```c
#include <stdio.h>

int main() {

    int num1, num2, a, b, gcd;

    printf("Enter two integers:\n");
    scanf("%d %d", &num1, &num2);

    a = num1;
    b = num2;

    while (b != 0) {
        int remainder = a % b;
        printf("%d div %d = quotient + %d\n",a ,b, remainder);
        a = b;
        b = remainder;
    }

    gcd = a;

    printf("The GCD of %d and %d is %d.\n", num1, num2, gcd);

    return 0;

}
```

For better code organization and reusability, you can write a **function** to calculate the GCD.

```c
#include <stdio.h>

int findGCD(int a, int b) {

    while (b != 0) {
        int remainder = a % b;
        printf("%d div %d = quotient + %d\n",a ,b, remainder);
        a = b;
        b = remainder;
    }

    return a;

}

int main() {

    int num1, num2;

    printf("Enter two integers:\n");
    scanf("%d %d", &num1, &num2);

    int gcd = findGCD(num1, num2);

    printf("The GCD of %d and %d is %d.\n", num1, num2, gcd);

    return 0;

}
```

#### output

```
Enter two integers: 86 48
86 div 48 = quotient + 38
48 div 38 = quotient + 10
38 div 10 = quotient + 8
10 div 8 = quotient + 2
8 div 2 = quotient + 0
The GCD of 86 and 48 is 2.
```

# Code

We focus back to the question
## C

### Solution 1

```c
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int remainder = b;
        b = a % b;
        a = remainder;
    }
    return a;
}

int main() {
    int N;
    
    while (scanf("%d", &N) == 1 && N != 0) {
        int G = 0;
        
        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j <= N; j++) {
                G += gcd(i, j);
            }
        }
        
        printf("%d\n", G);
    }
    
    return 0;
}
```


