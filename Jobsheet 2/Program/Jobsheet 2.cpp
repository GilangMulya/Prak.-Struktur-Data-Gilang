//Created By M.Gilang Mulya Putra_23343073
#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur untuk tipe data mahasiswa
struct Mahasiswa { //Variable struct dengan nama Mahasiswa
    int NIM; //Variable NIM
    char Nama[50]; //Variable char Nama Mahasiswa
    char TanggalLahir[15]; // Misalnya "DD-MM-YYYY"
    float IPK; //Variable untuk IPK
};

// Fungsi untuk input data mahasiswa
void inputMahasiswa(struct Mahasiswa *mhs) {
    printf("Masukkan Nama: "); //Output Nama
    scanf("%[^\n]s", &mhs->Nama); //Input nama Mahasiswa
    printf("Masukkan NIM: "); //Output Masukkan NIM
    scanf(" %d", mhs->NIM); //Input memasukkan NIM
    printf("Masukkan Tanggal Lahir (DD-MM-YYYY): ");  //Output meminta memasukkan Tanggal lahir
    scanf("%s", mhs->TanggalLahir); //Input memasukkan tanggal lahir mahasiswa
    printf("Masukkan IPK: "); //Output meminta memasukkan IPK
    scanf("%f", &mhs->IPK); //Input memasukkan IPK
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanMahasiswa(struct Mahasiswa mhs) {
    printf("\nData Mahasiswa:\n"); //Menampilkan data mahasiswa
    printf("Nama: %s\n", mhs.Nama); //Menampilkan nama mahasiswa
    printf("NIM: %d\n", mhs.NIM); //menampilkan NIM mahasiswa
    printf("Nama: %s\n", mhs.Nama); //
    printf("Tanggal Lahir: %s\n", mhs.TanggalLahir); //Menampilakan Tanggal Lahir
    printf("IPK: %.2f\n", mhs.IPK); //Menampilkan IPK
}

int main() { //Fungsi Utama Program
    struct Mahasiswa mhs; // Deklarasi variabel mahasiswa

    // Memanggil fungsi inputMahasiswa untuk mengisi data mahasiswa
    printf("Masukkan Data Mahasiswa:\n");
    inputMahasiswa(&mhs);

    // Memanggil fungsi tampilkanMahasiswa untuk menampilkan data mahasiswa
    tampilkanMahasiswa(mhs);

    return 0;
}

