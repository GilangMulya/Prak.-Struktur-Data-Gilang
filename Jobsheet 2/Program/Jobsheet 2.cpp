//Created By M.Gilang Mulya Putra_23343073
#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur untuk tipe data mahasiswa
struct Mahasiswa {
    int NIM;
    char Nama[50];
    char TanggalLahir[15]; // Misalnya "DD-MM-YYYY"
    float IPK;
};

// Fungsi untuk input data mahasiswa
void inputMahasiswa(struct Mahasiswa *mhs) {
    printf("Masukkan Nama: ");
    scanf("%[^\n]s", &mhs->Nama);
    printf("Masukkan NIM: ");
    scanf(" %d", mhs->NIM);
    printf("Masukkan Tanggal Lahir (DD-MM-YYYY): ");
    scanf("%s", mhs->TanggalLahir);
    printf("Masukkan IPK: ");
    scanf("%f", &mhs->IPK);
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanMahasiswa(struct Mahasiswa mhs) {
    printf("\nData Mahasiswa:\n");
    printf("Nama: %s\n", mhs.Nama);
    printf("NIM: %d\n", mhs.NIM);
    printf("Nama: %s\n", mhs.Nama);
    printf("Tanggal Lahir: %s\n", mhs.TanggalLahir);
    printf("IPK: %.2f\n", mhs.IPK);
}

int main() {
    struct Mahasiswa mhs; // Deklarasi variabel mahasiswa

    // Memanggil fungsi inputMahasiswa untuk mengisi data mahasiswa
    printf("Masukkan Data Mahasiswa:\n");
    inputMahasiswa(&mhs);

    // Memanggil fungsi tampilkanMahasiswa untuk menampilkan data mahasiswa
    tampilkanMahasiswa(mhs);

    return 0;
}

