
# 氣泡搜尋法 Bubble Sort

## Reference

- [【Day21】[演算法]-排序Sort & 氣泡排序法Bubble Sort - iT 邦幫忙::一起幫忙解決難題，拯救 IT 人的一天](https://ithelp.ithome.com.tw/articles/10276184)

## Summary

 - 讓數值最大的數字慢慢往右移，就像在水裡的氣泡上浮一樣
 - 每一次搜索都能找出，**其搜索範圍內**的最大值，並排在**其搜索範圍內**最右
	 - 第一次搜索，找出最大值 $A_1$
	 - 第二次搜索，找出次最大值 $A_2$
	 - 第 $n - 1$ 次搜索，找出 $A_{n-1}$ ，即可停止搜索

### C

```c
#include <stdio.h>
 // Function to perform Bubble Sort
void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap adjacent elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int arr[100], n, i;
    scanf("%d", & n);
    for (i = 0; i < n; i++) {
        scanf("%d", & arr[i]);
    }
    bubble_sort(arr, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

#### In-Output

```
5
4 6 7 8 9
```

```
Sorted array:
4 6 7 8 9
```

```
6
9 8 7 8 2 1
```

```
Sorted array:
1 2 7 8 8 9
```