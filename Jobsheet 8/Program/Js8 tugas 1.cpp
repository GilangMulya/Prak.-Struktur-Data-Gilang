#include <stdio.h>

// Fungsi untuk Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {  // Loop melalui elemen array
        for (j = 0; j < n-i-1; j++) {  // Loop untuk membandingkan dan menukar elemen
            if (arr[j] > arr[j+1]) {  // Jika elemen saat ini lebih besar dari elemen berikutnya
                // Tukar arr[j] dan arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Fungsi untuk Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {  // Loop melalui elemen array mulai dari elemen kedua
        key = arr[i];  // Simpan elemen saat ini sebagai key
        j = i - 1;

        // Pindahkan elemen arr[0..i-1], yang lebih besar dari key
        // ke satu posisi ke depan dari posisi saat ini
        while (j >= 0 && arr[j] > key) {  // Selama ada elemen yang lebih besar dari key
            arr[j + 1] = arr[j];  // Geser elemen ke kanan
            j = j - 1;
        }
        arr[j + 1] = key;  // Tempatkan key di posisi yang benar
    }
}

// Fungsi untuk mencetak array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {  // Loop melalui elemen array
        printf("%d ", arr[i]);  // Cetak elemen array
    }
    printf("\n");  // Pindah ke baris baru
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};  // Inisialisasi array pertama
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};  // Inisialisasi array kedua
    int n = sizeof(arr1)/sizeof(arr1[0]);  // Hitung jumlah elemen dalam array

    printf("Array sebelum sorting:\n");
    printArray(arr1, n);  // Cetak array sebelum sorting

    // Menggunakan Bubble Sort
    bubbleSort(arr1, n);  // Sort array pertama dengan Bubble Sort
    printf("\nArray setelah Bubble Sort:\n");
    printArray(arr1, n);  // Cetak array setelah Bubble Sort

    // Menggunakan Insertion Sort
    insertionSort(arr2, n);  // Sort array kedua dengan Insertion Sort
    printf("\nArray setelah Insertion Sort:\n");
    printArray(arr2, n);  // Cetak array setelah Insertion Sort

    return 0;  // Akhiri program
}
