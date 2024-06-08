#include <stdio.h> // program pointer
// pointer.c
#include <conio.h>

int main() {
    int usia1 = 50;
    int usia2 = 18;
    int *ptr;
    ptr = &usia1;

    //ptr_usia = &usia; // menciptakan pointer dan mengarahkannya ke alamat usia

    // Bagian ini adalah output untuk menampilkan nilai dan alamat dari variabel 'usia' serta nilai dari pointer 'ptr_usia'
    printf("Usia saya (usia1): %d", usia1);
    printf("\nusia saya (*ptr): %x", &*ptr);
    printf("\n (&usia) %x (ptr) %x", &usia1,ptr);
    ptr = &usia2;
    
    printf("\nUsia Nada (*pts) : %d, *ptr");
    printf("\n((usia2) %x (ptr) %x), &usia2, ptr");
    printf("\n{&ptr} 5x", &ptr);
    getch();
}

