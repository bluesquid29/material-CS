#include <stdio.h>
#include <string.h>

int main() {
    char num[1002];
    
    while (scanf("%s", num) == 1) {
        // Check if input is "0" (termination condition)
        if (strcmp(num, "0") == 0) {
            break;
        }
        
        int len = strlen(num);
        // printf("%d\n", len);
        int sum = 0;
        int sign = 1;
        
        // Calculate alternating sum from right to left
        for (int i = len - 1; i >= 0; i--) {
            sum += sign * (num[i] - '0');
            sign = -sign;
        	// printf("%d\n", sum);	
        }
        
        // Check if divisible by 11
        if (sum % 11 == 0) {
            printf("%s is a multiple of 11.\n", num);
        } else {
            printf("%s is not a multiple of 11.\n", num);
        }
    }
    
    return 0;
}