#include <stdio.h>
#include <string.h>

int sumDigits(char *num) {
    int sum = 0;
    int len = strlen(num);
    
    for (int i = 0; i < len; i++) {
        sum += num[i] - '0';  // Convert char to int, ASCII '0' = 48
        // printf("%d\n", num[i]);	
    }
    
    return sum;
}

int main() {
    char num[1005];
    
    while (scanf("%s", num) == 1) {
        if (strcmp(num, "0") == 0) {
            break;
        }
        
        int result = sumDigits(num);
        // printf("%d\n", result);	
        
        // Keep summing until we get a single digit
        while (result >= 10) {
            int temp = result;
            result = 0;
            
            while (temp > 0) {
                result += temp % 10;
                temp /= 10;
            }
        }
        
        printf("%d\n", result);
    }
    
    return 0;
}