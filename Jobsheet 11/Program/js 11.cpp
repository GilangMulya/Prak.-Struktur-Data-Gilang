#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur data Mahasiswa
typedef struct {
    int nim;
    char nama[50];
    char ttl[50];
    float ipk;
} Mahasiswa;

// Fungsi untuk melakukan sequential search
Mahasiswa* sequential_search(Mahasiswa arr[], int size, int nim) {
    for (int i = 0; i < size; i++) {  // Loop melalui array mahasiswa
        if (arr[i].nim == nim) {  // Jika NIM sesuai dengan yang dicari
            return &arr[i];  // Kembalikan alamat mahasiswa tersebut
        }
    }
    return NULL;  // Kembalikan NULL jika tidak ditemukan
}

// Fungsi untuk melakukan binary search
Mahasiswa* binary_search(Mahasiswa arr[], int size, int nim) {
    int low = 0;  // Indeks awal
    int high = size - 1;  // Indeks akhir

    while (low <= high) {  // Selama masih ada elemen yang belum diperiksa
        int mid = (low + high) / 2;  // Tentukan indeks tengah
        if (arr[mid].nim == nim) {  // Jika NIM pada posisi tengah sama dengan NIM yang dicari
            return &arr[mid];  // Kembalikan alamat mahasiswa tersebut
        } else if (arr[mid].nim < nim) {  // Jika NIM pada posisi tengah lebih kecil dari NIM yang dicari
            low = mid + 1;  // Geser batas bawah ke posisi setelah posisi tengah
        } else {  // Jika NIM pada posisi tengah lebih besar dari NIM yang dicari
            high = mid - 1;  // Geser batas atas ke posisi sebelum posisi tengah
        }
    }
    return NULL;  // Kembalikan NULL jika tidak ditemukan
}

int main() {
    // Data mahasiswa
    Mahasiswa mahasiswa[] = {
        {1001, "Alice", "01-01-2000", 3.5},
        {1002, "Bob", "02-02-2001", 3.6},
        {1003, "Charlie", "03-03-2002", 3.7},
        {1004, "David", "04-04-2003", 3.8},
        {1005, "Eve", "05-05-2004", 3.9}
    };
    int size = sizeof(mahasiswa) / sizeof(mahasiswa[0]);  // Hitung jumlah elemen dalam array

    int nim_to_search = 1003;  // NIM yang akan dicari

    // Sequential search
    Mahasiswa *result_seq = sequential_search(mahasiswa, size, nim_to_search);  // Cari mahasiswa dengan sequential search
    if (result_seq != NULL) {  // Jika mahasiswa ditemukan
        printf("Sequential Search:\n");
        printf("NIM: %d, Nama: %s, TTL: %s, IPK: %.2f\n", result_seq->nim, result_seq->nama, result_seq->ttl, result_seq->ipk);  // Cetak informasi mahasiswa
    } else {  // Jika mahasiswa tidak ditemukan
        printf("Sequential Search: Mahasiswa dengan NIM %d tidak ditemukan.\n", nim_to_search);  // Cetak pesan bahwa mahasiswa tidak ditemukan
    }

    // Binary search
    Mahasiswa *result_bin = binary_search(mahasiswa, size, nim_to_search);  // Cari mahasiswa dengan binary search
    if (result_bin != NULL) {  // Jika mahasiswa ditemukan
        printf("Binary Search:\n");
        printf("NIM: %d, Nama: %s, TTL: %s, IPK: %.2f\n", result_bin->nim, result_bin->nama, result_bin->ttl, result_bin->ipk);  // Cetak informasi mahasiswa
    } else {  // Jika mahasiswa tidak ditemukan
        printf("Binary Search: Mahasiswa dengan NIM %d tidak ditemukan.\n", nim_to_search);  // Cetak pesan bahwa mahasiswa tidak ditemukan
    }

    return 0;  // Akhiri program
}

