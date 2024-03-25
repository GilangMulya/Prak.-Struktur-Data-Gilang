//Created By M.Gilang Mulya Putra_23343073
#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n) {
    int *fib = (int *)malloc(n * sizeof(int));
    if (fib == NULL) {
        printf("Error: Unable to allocate memory.");
        return;
    }

    *fib = 0;
    *(fib + 1) = 1;

    printf("Fibonacci sequence up to %d terms:\n", n);
    printf("%d, %d, ", *fib, *(fib + 1));

    for (int i = 2; i < n; i++) {
        *(fib + i) = *(fib + i - 1) + *(fib + i - 2);
        printf("%d", *(fib + i));
        if (i != n - 1)
            printf(", ");
    }

    free(fib);
}

int main() {
    int n;
    printf("Masukkan nomor ketentuan Fibonaci: ");
    scanf("%d", &n);
    
    fibonacci(n);

    return 0;
}

