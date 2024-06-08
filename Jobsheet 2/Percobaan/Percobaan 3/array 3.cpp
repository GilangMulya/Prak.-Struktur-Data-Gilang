#include <stdio.h>

int main() {
    int n;

    // Prompt the user for the number of elements
    printf("Masukkan banyak bilangan: ");
    scanf("%d", &n);

    int angka[n]; // Declare an array to hold the numbers

    // Input the numbers
    for (int i = 0; i < n; i++) {
        printf("Masukkan angka ke-%d: ", i + 1);
        scanf("%d", &angka[i]); // Store the input in the correct index
    }

    // Print the numbers
    for (int i = 0; i < n; i++) {
        printf("Angka ke-%d: %d\n", i + 1, angka[i]); // Print the correct index
    }

    return 0;
}

