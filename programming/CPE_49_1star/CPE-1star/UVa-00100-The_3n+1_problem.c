#include <stdio.h>

int main() {
    int i, j, n;
    long long num, max;
    
    // Read number of test cases
    while (scanf("%d %d", &i, &j) != EOF) {
        int cycle_length, max_cycle = 0;
        int start = i, end = j;
        
        // Ensure start <= end
        if (i > j) {
            start = j;
            end = i;
        }
        
        // Calculate cycle length for each number in range
        for (n = start; n <= end; n++) {
            num = n;
            cycle_length = 1;
            
            // Apply 3n+1 algorithm
            while (num != 1) {
                if (num % 2 == 0) {
                    num = num / 2;
                } else {
                    num = 3 * num + 1;
                }
                cycle_length++;
            }
            
            // Track maximum cycle length
            if (cycle_length > max_cycle) {
                max_cycle = cycle_length;
            }
        }
        
        // Output: original i and j values, then max cycle length
        printf("%d %d %d\n", i, j, max_cycle);
    }
    
    return 0;
}
