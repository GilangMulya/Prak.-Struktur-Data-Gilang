#include <stdio.h>

struct complex
{
    float imag;
    float real;
};

struct number
{
    int integers[5];
    struct complex comp;
};

int main()
{
    // Buatlah nested struct sampai dengan 5 tingkat
    struct number num1;
    num1.integers[0] = 42;
    num1.comp.imag = 3.14;
    num1.comp.real = 2.71;

    printf("Integers[0]: %d\n", num1.integers[0]);
    printf("Complex Imaginary: %.2f\n", num1.comp.imag);
    printf("Complex Real: %.2f\n", num1.comp.real);

    return 0;
}

