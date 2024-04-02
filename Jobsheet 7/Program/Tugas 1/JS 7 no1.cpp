//Created By M.Gilang Mulya putra_23343073
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Definisi queue
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Inisialisasi queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Cek apakah queue kosong
int isEmpty(struct Queue* q) {
    if (q->rear == -1) {
        return 1;
    }
    return 0;
}

// Tambah elemen ke dalam queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("\nQueue penuh");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Hapus elemen dari queue
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue kosong\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Fungsi BFS
void BFS(int adjacency_matrix[MAX][MAX], int visited[MAX], int start, int n) {
    struct Queue q;
    initQueue(&q);

    visited[start] = 1;
    enqueue(&q, start);

    while (!isEmpty(&q)) {
        int current_node = dequeue(&q);
        printf("%d ", current_node);

        for (int i = 0; i < n; ++i) {
            if (adjacency_matrix[current_node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    int adjacency_matrix[MAX][MAX];
    int visited[MAX];
    int n, start;

    printf("Masukkan jumlah simpul: ");
    scanf("%d", &n);

    printf("Masukkan matriks ketetanggaan (0/1):\n");
    for (int i = 0; i < n; ++i) {
        visited[i] = 0;
        for (int j = 0; j < n; ++j) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    printf("Masukkan simpul awal untuk BFS: ");
    scanf("%d", &start);

    printf("Hasil BFS traversal: ");
    BFS(adjacency_matrix, visited, start, n);

    return 0;
}

