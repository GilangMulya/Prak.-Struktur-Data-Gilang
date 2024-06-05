// Created By M.gilang Mulya Putra_23343073
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk data buku
struct Book {
    char title[100];  // Menyimpan judul buku
    char author[100]; // Menyimpan pengarang buku
    int year;         // Menyimpan tahun terbit buku
    struct Book *next; // Pointer ke buku berikutnya dalam daftar
    struct Book *prev; // Pointer ke buku sebelumnya dalam daftar
};

// Fungsi untuk menambahkan buku ke dalam Double Linked List
void addBook(struct Book **head, char *title, char *author, int year) {
    struct Book *newBook = (struct Book *)malloc(sizeof(struct Book)); // Alokasi memori untuk buku baru
    strcpy(newBook->title, title); // Menyalin judul buku ke dalam struktur buku baru
    strcpy(newBook->author, author); // Menyalin pengarang buku ke dalam struktur buku baru
    newBook->year = year; // Menetapkan tahun terbit buku ke dalam struktur buku baru
    newBook->next = NULL; // Pointer 'next' dari buku baru diatur ke NULL

    if (*head == NULL) { // Jika daftar buku kosong
        newBook->prev = NULL; // Pointer 'prev' dari buku baru diatur ke NULL
        *head = newBook; // Buku baru menjadi head dari daftar buku
        return; // Keluar dari fungsi
    }

    struct Book *last = *head; // Pointer untuk traversal dimulai dari head
    while (last->next != NULL) { // Traversal ke buku terakhir
        last = last->next;
    }
    last->next = newBook; // Buku terakhir sekarang menunjuk ke buku baru
    newBook->prev = last; // Buku baru menunjuk kembali ke buku terakhir
}

// Fungsi untuk menghapus buku dari Double Linked List berdasarkan judul
void removeBook(struct Book **head, char *title) {
    if (*head == NULL) { // Jika daftar buku kosong
        printf("List buku kosong.\n"); // Tampilkan pesan bahwa daftar buku kosong
        return; // Keluar dari fungsi
    }

    struct Book *current = *head; // Pointer untuk traversal dimulai dari head
    while (current != NULL) { // Traversal melalui daftar buku
        if (strcmp(current->title, title) == 0) { // Jika judul buku ditemukan
            if (current->prev == NULL) { // Jika buku yang akan dihapus adalah head
                *head = current->next; // Head diatur ke buku berikutnya
                if (current->next != NULL) { // Jika ada buku berikutnya
                    current->next->prev = NULL; // Pointer 'prev' dari buku berikutnya diatur ke NULL
                }
            } else { // Jika buku yang akan dihapus bukan head
                current->prev->next = current->next; // Buku sebelumnya menunjuk ke buku berikutnya
                if (current->next != NULL) { // Jika ada buku berikutnya
                    current->next->prev = current->prev; // Buku berikutnya menunjuk kembali ke buku sebelumnya
                }
            }
            free(current); // Hapus memori yang dialokasikan untuk buku
            printf("Buku dengan judul '%s' telah dihapus.\n", title); // Tampilkan pesan bahwa buku telah dihapus
            return; // Keluar dari fungsi
        }
        current = current->next; // Lanjutkan traversal ke buku berikutnya
    }
    printf("Buku dengan judul '%s' tidak ditemukan.\n", title); // Tampilkan pesan jika buku tidak ditemukan
}

// Fungsi untuk mencetak data buku dalam Double Linked List
void printBooks(struct Book *head) {
    printf("Daftar Buku:\n"); // Tampilkan header daftar buku
    while (head != NULL) { // Traversal melalui daftar buku
        printf("Judul: %s, Pengarang: %s, Tahun: %d\n", head->title, head->author, head->year); // Tampilkan detail buku
        head = head->next; // Lanjutkan traversal ke buku berikutnya
    }
}

int main() {
    // Inisialisasi linked list untuk buku
    struct Book *bookList = NULL; // Pointer head untuk daftar buku diatur ke NULL

    // Tambahkan beberapa data buku
    addBook(&bookList, "The Great Gatsby", "F. Scott Fitzgerald", 1925); // Tambahkan buku pertama
    addBook(&bookList, "To Kill a Mockingbird", "Harper Lee", 1960); // Tambahkan buku kedua
    addBook(&bookList, "1984", "George Orwell", 1949); // Tambahkan buku ketiga

    // Cetak daftar buku
    printBooks(bookList); // Cetak semua buku dalam daftar

    // Hapus beberapa buku
    removeBook(&bookList, "To Kill a Mockingbird"); // Hapus buku kedua berdasarkan judul

    // Cetak daftar buku setelah penghapusan
    printBooks(bookList); // Cetak semua buku yang tersisa dalam daftar

    return 0; // Kembalikan nilai 0 untuk menandakan bahwa program berakhir dengan sukses
}
