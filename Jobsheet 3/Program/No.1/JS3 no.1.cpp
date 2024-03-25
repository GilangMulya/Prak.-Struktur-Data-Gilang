//Created By M.Gilang Mulya Putra_23343073
#include <stdio.h> //Library standar input-output
#include <stdlib.h> //Library standar alokasi memori

void fibonacci(int n) {
    int *fib = (int *)malloc(n * sizeof(int)); // Mengalokasikan memori untuk menyimpan deret Fibonacci
    if (fib == NULL) { // Memeriksa apakah alokasi memori berhasil
        printf("Error: Unable to allocate memory."); // Cetak pesan kesalahan jika alokasi memori gagal
        return; // Keluar dari fungsi jika alokasi memori gagal
    }

    *fib = 0; // Menginisialisasi anggota pertama deret Fibonacci
    *(fib + 1) = 1; // Menginisialisasi anggota kedua deret Fibonacci

    printf("Fibonacci sequence up to %d terms:\n", n); // Cetak pesan awal untuk deret Fibonacci
    printf("%d, %d, ", *fib, *(fib + 1)); // Cetak dua anggota pertama deret Fibonacci

    // Menghitung dan mencetak anggota-anggota deret Fibonacci selanjutnya
    for (int i = 2; i < n; i++) {
        *(fib + i) = *(fib + i - 1) + *(fib + i - 2); // Menghitung anggota deret Fibonacci ke-i
        printf("%d", *(fib + i)); // Cetak anggota deret Fibonacci ke-i
        if (i != n - 1)
            printf(", "); // Cetak koma jika bukan anggota terakhir dalam deret
    }

    free(fib); // Membebaskan memori yang dialokasikan untuk deret Fibonacci
}

int main() {
    int n;
    printf("Masukkan nomor ketentuan Fibonaci: ");
    scanf("%d", &n); // Menerima input dari pengguna
    
    fibonacci(n); // Memanggil fungsi untuk menghasilkan deret Fibonacci hingga n anggota

    return 0;
}
