//Created By M.gilang Mulya Putra_23343073
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk data buku
struct Book {
    char title[100];
    char author[100];
    int year;
    struct Book *next;
    struct Book *prev;
};

// Fungsi untuk menambahkan buku ke dalam Double Linked List
void addBook(struct Book **head, char *title, char *author, int year) {
    struct Book *newBook = (struct Book *)malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->year = year;
    newBook->next = NULL;

    if (*head == NULL) {
        newBook->prev = NULL;
        *head = newBook;
        return;
    }

    struct Book *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newBook;
    newBook->prev = last;
}

// Fungsi untuk menghapus buku dari Double Linked List berdasarkan judul
void removeBook(struct Book **head, char *title) {
    if (*head == NULL) {
        printf("List buku kosong.\n");
        return;
    }

    struct Book *current = *head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
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
            printf("Buku dengan judul '%s' telah dihapus.\n", title);
            return;
        }
        current = current->next;
    }
    printf("Buku dengan judul '%s' tidak ditemukan.\n", title);
}

// Fungsi untuk mencetak data buku dalam Double Linked List
void printBooks(struct Book *head) {
    printf("Daftar Buku:\n");
    while (head != NULL) {
        printf("Judul: %s, Pengarang: %s, Tahun: %d\n", head->title, head->author, head->year);
        head = head->next;
    }
}

int main() {
    // Inisialisasi linked list untuk buku
    struct Book *bookList = NULL;

    // Tambahkan beberapa data buku
    addBook(&bookList, "The Great Gatsby", "F. Scott Fitzgerald", 1925);
    addBook(&bookList, "To Kill a Mockingbird", "Harper Lee", 1960);
    addBook(&bookList, "1984", "George Orwell", 1949);

    // Cetak daftar buku
    printBooks(bookList);

    // Hapus beberapa buku
    removeBook(&bookList, "To Kill a Mockingbird");

    // Cetak daftar buku setelah penghapusan
    printBooks(bookList);

    return 0;
}

