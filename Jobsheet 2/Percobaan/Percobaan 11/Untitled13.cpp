#include <stdio.h>

struct Distance {
    int feet;
    float inch;
} dist1, dist2, sum;

int main(void) { // Correct main function declaration
    printf("1st distance\n");
    printf("Enter feet: ");
    scanf("%d", &dist1.feet); // Corrected scanf to use & operator

    printf("Enter inch: ");
    scanf("%f", &dist1.inch); // Corrected scanf to read float

    printf("2nd distance\n");
    printf("Enter feet: ");
    scanf("%d", &dist2.feet); // Corrected scanf to use & operator

    printf("Enter inch: ");
    scanf("%f", &dist2.inch); // Corrected scanf to read float

    // Adding feet
    sum.feet = dist1.feet + dist2.feet;
    // Adding inches
    sum.inch = dist1.inch + dist2.inch;
    // Convert inches to feet if inch is greater than or equal to 12
    while (sum.inch >= 12) {
        ++sum.feet;
        sum.inch -= 12; // Corrected logic to subtract 12 from inches
    }

    printf("Sum of distances = %d'-%.1f\"\n", sum.feet, sum.inch); // Corrected format specifier for float

    return 0;
}

