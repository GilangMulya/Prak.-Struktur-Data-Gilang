#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk mengecek apakah suatu bilangan adalah prima
int isPrime(int num) {
    if (num <= 1) {
        return 0; // Bukan bilangan prima
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0; // Bukan bilangan prima
        }
    }
    return 1; // Bilangan prima
}

int main() {
    int n; // Input dari user: batas bilangan prima yang ingin ditampilkan
    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    // Alokasi memori untuk menyimpan bilangan prima
    int* primes = (int*)malloc(n * sizeof(int));
    if (primes == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1;
    }

    int count = 0; // Jumlah bilangan prima yang sudah ditemukan
    for (int i = 2; count < n; ++i) {
        if (isPrime(i)) {
            primes[count] = i;
            ++count;
        }
    }

    // Tampilkan bilangan prima
    printf("Bilangan prima pertama %d:\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Bebaskan memori yang dialokasikan
    free(primes);

    return 0;
}

