// Created By M.Gilang Mulya Putra_23343073
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk data mobil
struct Car {
    char plate_no[20];     // Menyimpan nomor plat mobil
    char brand[50];        // Menyimpan merek mobil
    char owner_name[100];  // Menyimpan nama pemilik mobil
    struct Car *next;      // Pointer ke mobil berikutnya dalam daftar
    struct Car *prev;      // Pointer ke mobil sebelumnya dalam daftar
};

// Fungsi untuk menambahkan mobil ke dalam Double Linked List
void addCar(struct Car **head, char *plate_no, char *brand, char *owner_name) {
    struct Car *newCar = (struct Car *)malloc(sizeof(struct Car)); // Alokasi memori untuk mobil baru
    strcpy(newCar->plate_no, plate_no);    // Menyalin nomor plat ke dalam struktur mobil baru
    strcpy(newCar->brand, brand);          // Menyalin merek mobil ke dalam struktur mobil baru
    strcpy(newCar->owner_name, owner_name);// Menyalin nama pemilik ke dalam struktur mobil baru
    newCar->next = NULL;                   // Pointer 'next' dari mobil baru diatur ke NULL

    if (*head == NULL) {                   // Jika daftar mobil kosong
        newCar->prev = NULL;               // Pointer 'prev' dari mobil baru diatur ke NULL
        *head = newCar;                    // Mobil baru menjadi head dari daftar mobil
        return;                            // Keluar dari fungsi
    }

    struct Car *last = *head;              // Pointer untuk traversal dimulai dari head
    while (last->next != NULL) {           // Traversal ke mobil terakhir
        last = last->next;
    }
    last->next = newCar;                   // Mobil terakhir sekarang menunjuk ke mobil baru
    newCar->prev = last;                   // Mobil baru menunjuk kembali ke mobil terakhir
}

// Fungsi untuk menghapus mobil dari Double Linked List berdasarkan nomor plat
void removeCar(struct Car **head, char *plate_no) {
    if (*head == NULL) {                   // Jika daftar mobil kosong
        printf("Antrian mobil kosong.\n"); // Tampilkan pesan bahwa antrian mobil kosong
        return;                            // Keluar dari fungsi
    }

    struct Car *current = *head;           // Pointer untuk traversal dimulai dari head
    while (current != NULL) {              // Traversal melalui daftar mobil
        if (strcmp(current->plate_no, plate_no) == 0) { // Jika nomor plat mobil ditemukan
            if (current->prev == NULL) {   // Jika mobil yang akan dihapus adalah head
                *head = current->next;     // Head diatur ke mobil berikutnya
                if (current->next != NULL) { // Jika ada mobil berikutnya
                    current->next->prev = NULL; // Pointer 'prev' dari mobil berikutnya diatur ke NULL
                }
            } else {                       // Jika mobil yang akan dihapus bukan head
                current->prev->next = current->next; // Mobil sebelumnya menunjuk ke mobil berikutnya
                if (current->next != NULL) { // Jika ada mobil berikutnya
                    current->next->prev = current->prev; // Mobil berikutnya menunjuk kembali ke mobil sebelumnya
                }
            }
            free(current);                 // Hapus memori yang dialokasikan untuk mobil
            printf("Mobil dengan nomor plat '%s' telah keluar dari antrian.\n", plate_no); // Tampilkan pesan bahwa mobil telah dihapus
            return;                        // Keluar dari fungsi
        }
        current = current->next;           // Lanjutkan traversal ke mobil berikutnya
    }
    printf("Mobil dengan nomor plat '%s' tidak ditemukan dalam antrian.\n", plate_no); // Tampilkan pesan jika mobil tidak ditemukan
}

// Fungsi untuk mencetak data mobil dalam Double Linked List
void printCars(struct Car *head) {
    printf("Antrian Mobil:\n");            // Tampilkan header antrian mobil
    while (head != NULL) {                 // Traversal melalui daftar mobil
        printf("Nomor Plat: %s, Merk: %s, Nama Pemilik: %s\n", head->plate_no, head->brand, head->owner_name); // Tampilkan detail mobil
        head = head->next;                 // Lanjutkan traversal ke mobil berikutnya
    }
}

int main() {
    // Inisialisasi linked list untuk antrian mobil
    struct Car *carQueue = NULL;           // Pointer head untuk daftar mobil diatur ke NULL

    // Tambahkan beberapa data mobil
    addCar(&carQueue, "B 1234 ABC", "Toyota", "John Doe");         // Tambahkan mobil pertama
    addCar(&carQueue, "B 5678 DEF", "Honda", "Jane Smith");        // Tambahkan mobil kedua
    addCar(&carQueue, "B 91011 GHI", "Ford", "Michael Johnson");   // Tambahkan mobil ketiga

    // Cetak antrian mobil
    printCars(carQueue);                   // Cetak semua mobil dalam antrian

    // Hapus beberapa mobil dari antrian
    removeCar(&carQueue, "B 5678 DEF");    // Hapus mobil kedua berdasarkan nomor plat

    // Cetak antrian mobil setelah penghapusan
    printCars(carQueue);                   // Cetak semua mobil yang tersisa dalam antrian

    return 0;                              // Kembalikan nilai 0 untuk menandakan bahwa program berakhir dengan sukses
}
