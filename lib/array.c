#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

// Define a struct with a function pointer
typedef struct s_point{
    int x, y;
    void (*printCoordinates)(void);  // Function pointer
} t_point;

// Define a function that matches the signature of the function pointer
void printPoint(void) {
    extern t_point p;  // Use an external reference to the point object
    printf("Point: (%d, %d)\n", p.x, p.y);
}

int main() {
    // Create an instance of Point
    t_point p = {3, 4, printPoint};  // Initialize with values and the function pointer

    // Call the function via the function pointer in the struct (without parameters)
    p.printCoordinates();

    return 0;
}