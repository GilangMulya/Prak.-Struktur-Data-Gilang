#include <stdio.h>

typedef struct employee_st {
    char name[40];
    int id;
} Employee; // Corrected the type name

int main() {
    int myInt;
    Employee john;

    printf("Size of int is %zu\n", sizeof(myInt));
    printf("Size of char is %zu\n", sizeof(char));
    printf("Size of short is %zu\n", sizeof(short));
    printf("Size of long is %zu\n", sizeof(long));
    printf("Size of float is %zu\n", sizeof(float));
    printf("Size of double is %zu\n", sizeof(double));
    printf("Size of Employee is %zu\n", sizeof(Employee)); // Corrected type name

    return 0;
}

