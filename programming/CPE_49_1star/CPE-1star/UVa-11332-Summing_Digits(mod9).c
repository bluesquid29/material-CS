#include <stdio.h>
#include <string.h>

int main() {
    char num[1005];
    
    while (scanf("%s", num) == 1) {
        if (strcmp(num, "0") == 0) {
            break;
        }
        
        int sum = 0;
        int len = strlen(num);
        
        for (int i = 0; i < len; i++) {
            sum += num[i] - '0';
        }
        
        // Digital root formula: if sum % 9 == 0 and sum != 0, answer is 9
        int result = sum % 9;
        if (result == 0 && sum != 0) {
            result = 9;
        }
        
        printf("%d\n", result);
    }
    
    return 0;
}