#include <stdio.h>

// Fungsi untuk Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {  // Menetapkan nilai awal gap dan menguranginya setiap iterasi
        for (int i = gap; i < n; i++) {  // Loop melalui semua elemen array dimulai dari gap
            int temp = arr[i];  // Simpan nilai elemen saat ini dalam variabel sementara
            int j;  // Deklarasi variabel loop
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {  // Loop untuk membandingkan dan menukar elemen
                arr[j] = arr[j - gap];  // Geser elemen ke kanan
            }
            arr[j] = temp;  // Tempatkan elemen di posisi yang benar
        }
    }
}

// Fungsi untuk pertukaran elemen
void swap(int* a, int* b) {
    int t = *a;  // Simpan nilai a dalam variabel sementara
    *a = *b;  // Ganti nilai a dengan nilai b
    *b = t;  // Ganti nilai b dengan nilai sementara
}

// Fungsi untuk partisi dalam Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pilih elemen terakhir sebagai pivot
    int i = (low - 1);  // Indeks elemen yang lebih kecil dari pivot
    for (int j = low; j < high; j++) {  // Loop melalui subarray
        if (arr[j] < pivot) {  // Jika elemen saat ini lebih kecil dari pivot
            i++;  // Tambahkan indeks elemen yang lebih kecil dari pivot
            swap(&arr[i], &arr[j]);  // Tukar elemen
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Tukar elemen pivot dengan elemen di posisi yang benar
    return (i + 1);  // Kembalikan indeks pivot
}

// Fungsi untuk Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {  // Jika subarray memiliki lebih dari satu elemen
        int pi = partition(arr, low, high);  // Dapatkan indeks pivot
        quickSort(arr, low, pi - 1);  // Urutkan bagian sebelum pivot
        quickSort(arr, pi + 1, high);  // Urutkan bagian setelah pivot
    }
}

// Fungsi untuk mencetak array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {  // Loop melalui elemen array
        printf("%d ", arr[i]);  // Cetak elemen array
    }
    printf("\n");  // Pindah ke baris baru
}

int main() {
    int arr1[] = {12, 34, 54, 2, 3};  // Inisialisasi array pertama
    int arr2[] = {12, 34, 54, 2, 3};  // Inisialisasi array kedua
    int n1 = sizeof(arr1)/sizeof(arr1[0]);  // Hitung jumlah elemen dalam array pertama
    int n2 = sizeof(arr2)/sizeof(arr2[0]);  // Hitung jumlah elemen dalam array kedua

    printf("Array sebelum sorting:\n");
    printArray(arr1, n1);  // Cetak array sebelum sorting

    // Menggunakan Shell Sort
    shellSort(arr1, n1);  // Urutkan array pertama dengan Shell Sort
    printf("\nArray setelah Shell Sort:\n");
    printArray(arr1, n1);  // Cetak array setelah Shell Sort

    // Menggunakan Quick Sort
    quickSort(arr2, 0, n2 - 1);  // Urutkan array kedua dengan Quick Sort
    printf("\nArray setelah Quick Sort:\n");
    printArray(arr2, n2);  // Cetak array setelah Quick Sort

    return 0;  // Akhiri program
}
