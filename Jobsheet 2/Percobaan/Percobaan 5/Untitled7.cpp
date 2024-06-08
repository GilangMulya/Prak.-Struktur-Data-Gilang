#include <stdio.h>
#include <string.h>

// Define the struct
struct Mahasiswa {
    char nama[50];
    char jurusan[50];
    int nilai;
};

int main(void) {
    struct Mahasiswa mhs01;

    // Initialize the struct members
    strcpy(mhs01.nama, "M.Gilang Mulya Putra");
    strcpy(mhs01.jurusan, "Informatika");
    mhs01.nilai = 100;

    // Print the details of the struct
    printf("%s adalah mahasiswa jurusan %s ", mhs01.nama, mhs01.jurusan);
    printf("memperoleh nilai UAS %i \n", mhs01.nilai);

    return 0;
}

