//Created By M.Gilang Mulya Putra_23343073
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk data mobil
struct Car {
    char plate_no[20];
    char brand[50];
    char owner_name[100];
    struct Car *next;
    struct Car *prev;
};

// Fungsi untuk menambahkan mobil ke dalam Double Linked List
void addCar(struct Car **head, char *plate_no, char *brand, char *owner_name) {
    struct Car *newCar = (struct Car *)malloc(sizeof(struct Car));
    strcpy(newCar->plate_no, plate_no);
    strcpy(newCar->brand, brand);
    strcpy(newCar->owner_name, owner_name);
    newCar->next = NULL;

    if (*head == NULL) {
        newCar->prev = NULL;
        *head = newCar;
        return;
    }

    struct Car *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newCar;
    newCar->prev = last;
}

// Fungsi untuk menghapus mobil dari Double Linked List berdasarkan nomor plat
void removeCar(struct Car **head, char *plate_no) {
    if (*head == NULL) {
        printf("Antrian mobil kosong.\n");
        return;
    }

    struct Car *current = *head;
    while (current != NULL) {
        if (strcmp(current->plate_no, plate_no) == 0) {
            if (current->prev == NULL) {
                *head = current->next;
                if (current->next != NULL) {
                    current->next->prev = NULL;
                }
            } else {
                current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
            }
            free(current);
            printf("Mobil dengan nomor plat '%s' telah keluar dari antrian.\n", plate_no);
            return;
        }
        current = current->next;
    }
    printf("Mobil dengan nomor plat '%s' tidak ditemukan dalam antrian.\n", plate_no);
}

// Fungsi untuk mencetak data mobil dalam Double Linked List
void printCars(struct Car *head) {
    printf("Antrian Mobil:\n");
    while (head != NULL) {
        printf("Nomor Plat: %s, Merk: %s, Nama Pemilik: %s\n", head->plate_no, head->brand, head->owner_name);
        head = head->next;
    }
}

int main() {
    // Inisialisasi linked list untuk antrian mobil
    struct Car *carQueue = NULL;

    // Tambahkan beberapa data mobil
    addCar(&carQueue, "B 1234 ABC", "Toyota", "John Doe");
    addCar(&carQueue, "B 5678 DEF", "Honda", "Jane Smith");
    addCar(&carQueue, "B 91011 GHI", "Ford", "Michael Johnson");

    // Cetak antrian mobil
    printCars(carQueue);

    // Hapus beberapa mobil dari antrian
    removeCar(&carQueue, "B 5678 DEF");

    // Cetak antrian mobil setelah penghapusan
    printCars(carQueue);

    return 0;
}

