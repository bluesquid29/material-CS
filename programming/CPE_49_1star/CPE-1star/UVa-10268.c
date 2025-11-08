#include <stdio.h>

int main() {
    int x;
    int a[10005];
    char line[100005];
    
    while (scanf("%d", &x) == 1) {
        // Clear the newline after x
        fgets(line, sizeof(line), stdin);
        
        // Read the actual coefficient line
        fgets(line, sizeof(line), stdin);
        
        // Parse coefficients
        int n = 0;
        char *ptr = line;
        int num;
        while (sscanf(ptr, "%d", &num) == 1) {
            a[n++] = num;
            // Skip the number we just read
            while (*ptr == ' ' || *ptr == '\t' || *ptr == '-' || *ptr == '+') ptr++;
            while (*ptr >= '0' && *ptr <= '9') ptr++;
            // Skip whitespace
            while (*ptr == ' ' || *ptr == '\t') ptr++;
        }
        
        // Remove last coefficient (constant term, derivative is 0)
        n--;
        
        // Reverse the array
        for (int i = 0; i < n / 2; i++) {
            int temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }
        
        // Calculate derivative: each a[i] has power (i+1) after reversal
        long long ans = 0;
        long long mul = 1;
        for (int i = 0; i < n; i++) {
            ans += (long long)a[i] * (i + 1) * mul;
            mul *= x;
        }
        
        printf("%lld\n", ans);
    }
    
    return 0;
}