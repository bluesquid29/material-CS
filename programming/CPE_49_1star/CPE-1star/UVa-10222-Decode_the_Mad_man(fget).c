#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Define the keyboard layout
    char *keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    char *shifted = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    
    char line[1000];
    
    // Read input until EOF
    while (fgets(line, sizeof(line), stdin)) {
        int len = strlen(line);
        
        for (int i = 0; i < len; i++) {
            char c = line[i];
            int found = 0;
            
            // Check lowercase characters
            for (int j = 0; keyboard[j] != '\0'; j++) {
                if (c == keyboard[j]) {
                    // Shift 2 positions to the left
                    if (j >= 2) {
                        printf("%c", keyboard[j - 2]);
                    }
                    found = 1;
                    break;
                }
            }
            
            // Check uppercase characters
            if (!found) {
                for (int j = 0; shifted[j] != '\0'; j++) {
                    if (c == shifted[j]) {
                        // Shift 2 positions to the left
                        if (j >= 2) {
                            printf("%c", tolower(shifted[j - 2]));
                        }
                        found = 1;
                        break;
                    }
                }
            }
            
            // If space or newline, print as is
            if (!found && (c == ' ' || c == '\n')) {
                printf("%c", c);
            }
        }
    }
    
    return 0;
}