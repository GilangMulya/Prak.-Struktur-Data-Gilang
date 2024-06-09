#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Fungsi untuk menambahkan node di awal linked list
void push(struct Node** head_ref, int new_data) {
    // Alokasi node baru
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Gagal mengalokasikan memori untuk node baru\n");
        return;
    }

    // Inisialisasi data dan pointer
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    // Update prev dari head lama jika ada
    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }

    // Pindahkan head untuk menunjuk ke node baru
    (*head_ref) = new_node;
}

// Fungsi untuk menambahkan node sebelum node tertentu
void insertBefore(struct Node** head_ref, struct Node* next_node, int new_data) {
    if (next_node == NULL) {
        printf("Node berikutnya tidak boleh NULL\n");
        return;
    }

    // Alokasi node baru
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Gagal mengalokasikan memori untuk node baru\n");
        return;
    }

    // Inisialisasi data dan pointer
    new_node->data = new_data;
    new_node->prev = next_node->prev;
    new_node->next = next_node;

    // Update prev dari next_node
    next_node->prev = new_node;

    // Update next dari prev_node, atau update head jika prev adalah NULL
    if (new_node->prev != NULL) {
        new_node->prev->next = new_node;
    } else {
        (*head_ref) = new_node;
    }
}

// Fungsi untuk mencetak linked list dari awal ke akhir dan sebaliknya
void printList(struct Node* node) {
    struct Node* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

// Program utama untuk menguji fungsi-fungsi di atas
int main() {
    struct Node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 4);
    insertBefore(&head, head->next, 8);

    printf("Created DLL is: ");
    printList(head);

    // Tambahkan kode untuk membebaskan memori di sini

    getchar();
    return 0;
}

