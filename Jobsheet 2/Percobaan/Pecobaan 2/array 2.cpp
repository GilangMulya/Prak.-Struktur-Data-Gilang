#include <stdio.h>

int main() {
    int n[10];
    int i, j;
    
    // Initialize elements of array n to i + 100
    for (i = 0; i < 10; i++) {
        n[i] = i + 100;
    }
    
    // Print each element of the array
    for (j = 0; j < 10; j++) {
        printf("Element[%d] = %d\n", j, n[j]);
    }
    
    return 0;
}

