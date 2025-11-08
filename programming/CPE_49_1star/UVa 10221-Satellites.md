# Reference
# Guideline
## In-output
## Summary 
## Hints
# Code
## C
### Solution 1

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793
#define EARTH_RADIUS 6440.0

int main() {
    double s, a;
    char unit[10];
    
    while (scanf("%lf %lf %s", &s, &a, unit) == 3) {
        // Convert angle to degrees if given in minutes
        if (unit[0] == 'm') {
            a = a / 60.0;
        }
        
        // Normalize angle to [0, 360)
        while (a > 360.0) {
            a -= 360.0;
        }
        
        // Use the smaller angle (<=180 degrees)
        if (a > 180.0) {
            a = 360.0 - a;
        }
        
        // Calculate orbital radius
        double r = EARTH_RADIUS + s;
        
        // Convert angle to radians
        double angle_rad = a * PI / 180.0;
        
        // Calculate arc length
        double arc_length = r * angle_rad;
        
        // Calculate chord length using the formula: 2 * r * sin(angle/2)
        double chord_length = 2.0 * r * sin(angle_rad / 2.0);
        
        printf("%.6lf %.6lf\n", arc_length, chord_length);
    }
    
    return 0;
}
```