# Guideline

We read the definition in the PDF carefully:

>Elements of a matrix given in the input are $-2^{32} \leq M_{ij} \leq 2 ^{32}$

So we use `long long`

>Symmetric matrix is such a matrix that all elements of it are **non-negative** and symmetric with **relation to the center** of this matrix.

## Symmetric Matrix Example:

$$
A =
\begin{bmatrix}
5 & 1 & 3 \\
2 & 0 & 2 \\
3 & 1 & 5 \\
\end{bmatrix}
\quad
B =
\begin{bmatrix}
5 & 1 & 3 \\
2 & 0 & 2 \\
3 & 1 & \color{red}{6} \\
\end{bmatrix}
$$

A is symmetric, B is non-symmetric.

Here's a 4×4 matrix example showing symmetric pairs:

$$
\begin{bmatrix}
1 & 2 & 3 & 4 \\
5 & 6 & 7 & 8 \\
8 & 7 & 6 & 5 \\
4 & 3 & 2 & 1 \\
\end{bmatrix}
\implies \text{add color} \implies
\begin{bmatrix}
\color{red}{1} & \color{white}{2} & \color{green}{3} & \color{yellow}{4} \\
\color{magenta}{5} & \color{red}{6} & \color{blue}{7} & \color{cyan}{8} \\
\color{cyan}{8} & \color{blue}{7} & \color{red}{6} & \color{magenta}{5} \\
\color{yellow}{4} & \color{green}{3} & \color{white}{2} & \color{red}{1} \\
\end{bmatrix}
$$

## Mirror Pairs:

The algorithm checks these pairs:

$$ 
\begin{array}{c|c}
\text{Position } [i][j] & \text{Mirror } [n-1-i][n-1-j] \\ 
\hline 
[0][0] = 1 & [3][3] = 1 \quad \checkmark \\ 
[0][1] = 2 & [3][2] = 2 \quad \checkmark \\ 
[0][2] = 3 & [3][1] = 3 \quad \checkmark \\ 
[0][3] = 4 & [3][0] = 4 \quad \checkmark \\ 
[1][0] = 5 & [2][3] = 5 \quad \checkmark \\ 
[1][1] = 6 & [2][2] = 6 \quad \checkmark \\ 
[1][2] = 7 & [2][1] = 7 \quad \checkmark \\ 
[1][3] = 8 & [2][0] = 8 \quad \checkmark 
\end{array}
$$

## Non-Symmetric Example:

$$ \begin{bmatrix}
1 & 2 & 3 & 4 \\
5 & 6 & 7 & 8 \\
8 & 7 & 6 & 5 \\
4 & 3 & 2 & \color{red}{9} \\
\end{bmatrix} $$

This fails because `[0][0] = 1` but `[3][3] = 9` 

# Code
## C

### Solution 1

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, caseNum = 1;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        char temp;
        
        // Read "N = n" format
        scanf(" %c %c %d", &temp, &temp, &n);
        
        long long matrix[n][n];
        int isSymmetric = 1;
        
        // Read the matrix
        for (int i = 0; i < n; i++) { //
            for (int j = 0; j < n; j++) {
                scanf("%lld", &matrix[i][j]);
                
                // Check if value is negative
                if (matrix[i][j] < 0) {
                    isSymmetric = 0;
                }
            }
        }
        
        // Check symmetry
        if (isSymmetric) {
            for (int i = 0; i < n && isSymmetric; i++) {
                for (int j = 0; j < n && isSymmetric; j++) {
                    // Compare with mirror position
                    if (matrix[i][j] != matrix[n-1-i][n-1-j]) {
                        isSymmetric = 0;
                    }
                }
            }
        }
        
        // Print the result
        printf("Test #%d: ", caseNum++);
        if (isSymmetric) {
            printf("Symmetric.\n");
        } else {
            printf("Non-symmetric.\n");
        }
    }
    
    return 0;
}
```
