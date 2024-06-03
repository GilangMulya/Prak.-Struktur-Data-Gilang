//Created by M.Gilang Mulya Putra_23343073
#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        // Mencari elemen terkecil dalam array yang tidak terurut
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Menukar elemen terkecil dengan elemen pertama
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Fungsi untuk menggabungkan dua subarray untuk Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Membuat array sementara
    int L[n1], R[n2];

    // Menyalin data ke array sementara L[] dan R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Menggabungkan array sementara kembali ke arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Menyalin elemen yang tersisa dari L[], jika ada
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Menyalin elemen yang tersisa dari R[], jika ada
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi untuk Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Menemukan titik tengah
        int m = l + (r - l) / 2;

        // Mengurutkan pertama dan kedua bagian
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Menggabungkan bagian yang diurutkan
        merge(arr, l, m, r);
    }
}

// Fungsi untuk mencetak array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int arr2[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    printf("Array sebelum sorting:\n");
    printArray(arr1, n1);

    // Menggunakan Selection Sort
    selectionSort(arr1, n1);
    printf("\nArray setelah Selection Sort:\n");
    printArray(arr1, n1);

    // Menggunakan Merge Sort
    mergeSort(arr2, 0, n2 - 1);
    printf("\nArray setelah Merge Sort:\n");
    printArray(arr2, n2);

    return 0;
}

