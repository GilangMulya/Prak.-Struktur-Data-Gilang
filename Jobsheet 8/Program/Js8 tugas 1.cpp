//Created by M.Gilang Mulya Putra_23343073
#include <stdio.h>

// Fungsi untuk Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
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
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Pindahkan elemen arr[0..i-1], yang lebih besar dari key
        // ke satu posisi ke depan dari posisi saat ini
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr1)/sizeof(arr1[0]);

    printf("Array sebelum sorting:\n");
    printArray(arr1, n);

    // Menggunakan Bubble Sort
    bubbleSort(arr1, n);
    printf("\nArray setelah Bubble Sort:\n");
    printArray(arr1, n);

    // Menggunakan Insertion Sort
    insertionSort(arr2, n);
    printf("\nArray setelah Insertion Sort:\n");
    printArray(arr2, n);

    return 0;
}

