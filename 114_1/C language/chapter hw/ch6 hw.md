### 7 code

```c
int main(void) 
{
    int a, b, c;
    printf("Enter three side lengths: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a) 
    {
        printf("The lengths can form a triangle.\n");
    } 
    else 
    {
        printf("The lengths cannot form a triangle.\n");
    }

	return 0;
}
```

#### 7 Output

```
Enter three side lengths: 5
5
8
The lengths can form a triangle.
```

```
Enter three side lengths: 6
7
1
The lengths cannot form a triangle.
```

### 8 code

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int a, b, c;
    printf("Enter three side lengths: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a) 
    {
        if (a * a == b * b + c * c || 
            b * b == a * a + c * c || 
            c * c == a * a + b * b) 
        {
            printf("%d, %d, %d form a right triangle.\n", a, b, c);
        } 
        else if (a * a > b * b + c * c || 
                 b * b > a * a + c * c || 
                 c * c > a * a + b * b) 
        {
            printf("%d, %d, %d form a obtuse triangle.\n", a, b, c);
        } 
        else
        {
            printf("%d, %d, %d form a acute triangle.\n", a, b, c);
        }
    } 
    else 
    {
        printf("%d, %d, %d cannot form a triangle.\n", a, b, c);
    }

    return 0;
}
```

#### 8 output

```
Enter three side lengths: 7 7 21
7, 7, 21 cannot form a triangle.
```

```
Enter three side lengths: 5 12 13
5, 12, 13 form a right triangle.
```

```
Enter three side lengths: 2 2 3
2, 2, 3 form a obtuse triangle.
```

```
Enter three side lengths: 1 1 1 
1, 1, 1 form a acute triangle.
```

### 11 code

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int a;
    printf("輸入工讀生的該月工讀時數：");
    scanf("%d", &a);

    if (a <= 60) {
        printf("該月工讀薪資為：%d 元\n", a * 75);
    } 
    else if (a >= 61 && a <= 75) {
        printf("該月工讀薪資為：%.2f 元\n", (60 * 75) + ((a - 60) * 75 * 1.25));
    } 
    else {
        printf("該月工讀薪資為：%.2f 元\n", (60 * 75) + (15 * 75 * 1.25) + ((a - 75) * 75 * 1.75));
    }

    return 0;
}
```

#### 11 output

```
輸入工讀生的該月工讀時數：62
該月工讀薪資為：4687.50 元
```

```
輸入工讀生的該月工讀時數：80
該月工讀薪資為：6562.50 元
```

```
輸入工讀生的該月工讀時數：81
該月工讀薪資為：6693.75 元
```

### 15 code

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int a;
    int pay, realpay, repay;
    int m1000 = 0, m500 = 0, m100 = 0, m50 = 0, m10 = 0, m5 = 0, m1 = 0;
    printf("輸入應付金額: ");
    scanf("%d", &pay);
    printf("輸入實付金額: ");
    scanf("%d", &realpay);

    if (realpay < pay) {
        printf("金額不夠");
    }    
    else {
        repay = realpay - pay;
        printf("找你 %d 元\n", repay);
        m1000 = repay / 1000;

        repay = repay - (1000 * m1000);
        m500 = repay / 500;

        repay = repay - (500 * m500);
        m100 = repay / 100; 
        
        repay = repay - (100 * m100);
        m50 = repay / 50;

        repay = repay - (50 * m50);
        m10 = repay / 10;

        repay = repay - (10 * m10);
        m5 = repay / 5;     
        
        repay = repay - (5 * m5);
        m1 = repay / 1;  

        printf("%d 張1000元、 %d 張500元、 %d 張100元、 %d 個50元、 %d 個10元、 %d 個5元、 %d 個1元。\n", m1000, m500, m100, m50, m10, m5, m1);
    }

    return 0;
}
```

#### 15 output

```
輸入應付金額: 1302
輸入實付金額: 3000
找你 1698 元
1 張1000元、 1 張500元、 1 張100元、 1 個50元、 4 個10元、 1 個5元、 3 個1元。
```

### 21 code

```c
#include <stdio.h>
#include <stdlib.h>

int main(void){

    char ch;
    
    printf("輸入一個字元 a 或 b 或其他: ");
    scanf("%c", &ch);
    
    switch(ch)
    {
        case 'a':
            printf("您輸入的是 %c\n", ch);
            break;
        case 'b':
            printf("您輸入的是 %c\n", ch);
            break;
        default:
            printf("您輸入的不是 a 也不是 b。\n");
    }
    
    return 0;

}
```
#### 21 output

```
輸入一個字元 a 或 b 或其他: d
您輸入的不是 a 也不是 b。
```

```
輸入一個字元 a 或 b 或其他: a
您輸入的是 a
```

```
輸入一個字元 a 或 b 或其他: b 
您輸入的是 b
```