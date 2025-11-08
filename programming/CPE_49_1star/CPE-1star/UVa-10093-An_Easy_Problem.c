// Pass in Online judge and zerojudge

#include <stdio.h>
#include <string.h>

int charToDigit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 36;
    return 0;
}

int main() {
    char num[1005];
    
    while (scanf("%s", num) != EOF) {
        int len = strlen(num);
        int maxDigit = 1;
        long long digitSum = 0;
        
        // Find maximum digit and sum of all digits
        for (int i = 0; i < len; i++) {
            int digit = charToDigit(num[i]);
            if (digit > maxDigit) maxDigit = digit;
            digitSum += digit;
        }
        
        // Minimum possible base is maxDigit + 1
        int minBase = maxDigit + 1;
        
        // Special case: if number is "0", any base works
        if (len == 1 && num[0] == '0') {
            printf("2\n");
            continue;
        }
        
        int found = 0;
        
        // Try bases from minBase to 62
        for (int base = minBase; base <= 62; base++) {
            // A number in base B is divisible by (B-1) if and only if
            // the sum of its digits is divisible by (B-1)
            if (digitSum % (base - 1) == 0) {
                printf("%d\n", base);
                found = 1;
                break;
            }
        }
        
        if (!found) {
            printf("such number is impossible!\n");
        }
    }
    
    return 0;
}