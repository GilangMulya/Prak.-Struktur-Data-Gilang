//Created By M.Gilang Mulya Putra_23343073
#include <stdio.h> // Library standar input-output
#include <stdlib.h> // Library standar alokasi memori

// Fungsi untuk mengecek apakah suatu bilangan adalah prima
int isPrime(int num) {
    if (num <= 1) {
        return 0; // Mengembalikan 0 jika bilangan kurang dari atau sama dengan 1 (bukan bilangan prima)
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0; // Mengembalikan 0 jika bilangan memiliki faktor selain 1 dan dirinya sendiri (bukan bilangan prima)
        }
    }
    return 1; // Mengembalikan 1 jika bilangan merupakan bilangan prima
}

int main() {
    int n; // Variabel untuk menyimpan input dari pengguna: batas bilangan prima yang ingin ditampilkan
    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    // Alokasi memori untuk menyimpan bilangan prima
    int* primes = (int*)malloc(n * sizeof(int)); // Mengalokasikan memori untuk array yang akan menyimpan bilangan prima
    if (primes == NULL) { // Memeriksa apakah alokasi memori berhasil
        printf("Gagal mengalokasikan memori.\n"); // Cetak pesan kesalahan jika alokasi memori gagal
        return 1; // Keluar dari program dengan kode error 1
    }

    int count = 0; // Variabel untuk menyimpan jumlah bilangan prima yang sudah ditemukan
    for (int i = 2; count < n; ++i) {
        if (isPrime(i)) { // Memanggil fungsi isPrime untuk mengecek apakah bilangan i merupakan bilangan prima
            primes[count] = i; // Menyimpan bilangan prima ke dalam array primes
            ++count; // Menambah jumlah bilangan prima yang sudah ditemukan
        }
    }

    // Menampilkan bilangan prima yang sudah ditemukan
    printf("Bilangan prima pertama %d:\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", primes[i]); // Cetak bilangan prima ke layar
    }
    printf("\n");

    // Membebaskan memori yang sudah dialokasikan untuk array primes
    free(primes);

    return 0; // Keluar dari program dengan kode 0 (berhasil)
}
