#include <stdio.h>

int main() {
	
    int i, j;
    int n, a;
    int f[40] = {0, 1};
    
    for (i = 2; i < 40; i++)
        f[i] = f[i-1] + f[i-2];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        
        printf("%d = ", a);
        
        int check = 0;
        int base[41] = {};
        
        for (j = 39; j >= 2; j--) {
            if (a - f[j] >= 0) {
                check = 1;
                
                if (base[j+1] != 1) {
                    base[j] = 1;
                    a = a - f[j];
                }
            }
            
            if (check == 1)
                printf("%d", base[j]);
        }
        
        printf(" (fib)\n");
    }
    
    return 0;
}