#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    int top, north, west, east, south, bottom;
    char command[10];
    
    while (scanf("%d", &n) == 1 && n != 0) {
        // Initialize die position
        top = 1;
        north = 2;
        west = 3;
        east = 4;
        south = 5;
        bottom = 6;
        
        for (int i = 0; i < n; i++) {
            scanf("%s", command);
            
            int new_top, new_north, new_west, new_east, new_south, new_bottom;
            
            if (strcmp(command, "north") == 0) {
                // Roll north: top->north, north->bottom, bottom->south, south->top
                new_top = south;
                new_north = top;
                new_south = bottom;
                new_bottom = north;
                new_west = west;
                new_east = east;
            }
            else if (strcmp(command, "south") == 0) {
                // Roll south: top->south, south->bottom, bottom->north, north->top
                new_top = north;
                new_south = top;
                new_bottom = south;
                new_north = bottom;
                new_west = west;
                new_east = east;
            }
            else if (strcmp(command, "west") == 0) {
                // Roll west: top->west, west->bottom, bottom->east, east->top
                new_top = east;
                new_west = top;
                new_bottom = west;
                new_east = bottom;
                new_north = north;
                new_south = south;
            }
            else if (strcmp(command, "east") == 0) {
                // Roll east: top->east, east->bottom, bottom->west, west->top
                new_top = west;
                new_east = top;
                new_bottom = east;
                new_west = bottom;
                new_north = north;
                new_south = south;
            }
            
            // Update die state
            top = new_top;
            north = new_north;
            west = new_west;
            east = new_east;
            south = new_south;
            bottom = new_bottom;
        }
        
        printf("%d\n", top);
    }
    
    return 0;
}