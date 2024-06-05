#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Mendefinisikan ukuran maksimum queue dan matriks

// Definisi queue
struct Queue {
    int items[MAX];  // Array untuk menyimpan elemen queue
    int front;       // Indeks elemen depan queue
    int rear;        // Indeks elemen belakang queue
};

// Inisialisasi queue
void initQueue(struct Queue* q) {
    q->front = -1;  // Mengatur indeks depan ke -1 (queue kosong)
    q->rear = -1;   // Mengatur indeks belakang ke -1 (queue kosong)
}

// Cek apakah queue kosong
int isEmpty(struct Queue* q) {
    if (q->rear == -1) {  // Jika indeks belakang -1, queue kosong
        return 1;
    }
    return 0;
}

// Tambah elemen ke dalam queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {  // Jika indeks belakang mencapai maksimum, queue penuh
        printf("\nQueue penuh");
    } else {
        if (q->front == -1) {  // Jika queue kosong, set indeks depan ke 0
            q->front = 0;
        }
        q->rear++;  // Tambah indeks belakang
        q->items[q->rear] = value;  // Tambah elemen ke queue
    }
}

// Hapus elemen dari queue
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {  // Jika queue kosong, tidak ada elemen untuk dihapus
        printf("Queue kosong\n");
        item = -1;  // Mengembalikan -1 sebagai penanda queue kosong
    } else {
        item = q->items[q->front];  // Mengambil elemen depan
        q->front++;  // Geser indeks depan ke elemen berikutnya
        if (q->front > q->rear) {  // Jika semua elemen sudah dihapus, reset queue
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Fungsi BFS
void BFS(int adjacency_matrix[MAX][MAX], int visited[MAX], int start, int n) {
    struct Queue q;  // Membuat instance queue
    initQueue(&q);  // Inisialisasi queue

    visited[start] = 1;  // Tandai simpul awal sebagai dikunjungi
    enqueue(&q, start);  // Masukkan simpul awal ke queue

    while (!isEmpty(&q)) {  // Selama queue tidak kosong
        int current_node = dequeue(&q);  // Ambil elemen depan queue
        printf("%d ", current_node);  // Cetak elemen yang diambil

        for (int i = 0; i < n; ++i) {  // Iterasi melalui semua simpul
            // Jika ada hubungan dan simpul belum dikunjungi
            if (adjacency_matrix[current_node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;  // Tandai simpul sebagai dikunjungi
                enqueue(&q, i);  // Masukkan simpul ke queue
            }
        }
    }
}

int main() {
    int adjacency_matrix[MAX][MAX];  // Matriks ketetanggaan
    int visited[MAX];  // Array untuk melacak simpul yang dikunjungi
    int n, start;

    printf("Masukkan jumlah simpul: ");
    scanf("%d", &n);  // Baca jumlah simpul

    printf("Masukkan matriks ketetanggaan (0/1):\n");
    for (int i = 0; i < n; ++i) {
        visited[i] = 0;  // Inisialisasi semua simpul sebagai belum dikunjungi
        for (int j = 0; j < n; ++j) {
            scanf("%d", &adjacency_matrix[i][j]);  // Baca nilai matriks ketetanggaan
        }
    }

    printf("Masukkan simpul awal untuk BFS: ");
    scanf("%d", &start);  // Baca simpul awal

    printf("Hasil BFS traversal: ");
    BFS(adjacency_matrix, visited, start, n);  // Panggil fungsi BFS

    return 0;
}
