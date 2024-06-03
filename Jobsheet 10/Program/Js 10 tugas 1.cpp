//Created by M.Gilang Mulya Putra_23343073
#include <stdio.h>

// Fungsi untuk Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Fungsi untuk pertukaran elemen
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Fungsi untuk partisi dalam Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fungsi untuk Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk mencetak array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {12, 34, 54, 2, 3};
    int arr2[] = {12, 34, 54, 2, 3};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    printf("Array sebelum sorting:\n");
    printArray(arr1, n1);

    // Menggunakan Shell Sort
    shellSort(arr1, n1);
    printf("\nArray setelah Shell Sort:\n");
    printArray(arr1, n1);

    // Menggunakan Quick Sort
    quickSort(arr2, 0, n2 - 1);
    printf("\nArray setelah Quick Sort:\n");
    printArray(arr2, n2);

    return 0;
}

