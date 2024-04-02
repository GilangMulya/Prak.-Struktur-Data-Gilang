//Created By M.Gilang Mulya Putra_23343073
#include <stdio.h>
#include <stdlib.h>
#define BENAR 1
#define SALAH 0
#define PENUH 10

// Definisi struktur node
struct node
{
    int data;
    struct node *next;
};

// Definisi struktur queue
struct queue
{
    int count;
    struct node *front;
    struct node *rear;
};

typedef struct queue queue;

// Fungsi untuk inisialisasi queue
void inisialisasi(queue *q)
{
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

// Fungsi untuk memeriksa apakah queue kosong
int isempty(queue *q)
{
    return (q->rear == NULL);
}

// Fungsi untuk menambahkan elemen ke dalam queue
void enqueue(queue *q, int value)
{
    if (q->count < PENUH)
    {
        struct node *tmp;
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = value;
        tmp->next = NULL;
        if (!isempty(q))
        {
            q->rear->next = tmp;
            q->rear = tmp;
        }
        else
        {
            q->front = q->rear = tmp;
        }
        q->count++;
    }
    else
    {
        printf("Antrian penuh\n");
    }
}

// Fungsi untuk menghapus elemen dari queue
int dequeue(queue *q)
{
    struct node *tmp;
    int n = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return (n);
}

// Fungsi untuk menampilkan isi queue
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n", head->data);
        display(head->next);
    }
}

int main()
{
    queue *q;
    q = (queue *)malloc(sizeof(queue));
    inisialisasi(q);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("Queue sebelum proses dequeue\n");
    display(q->front);
    dequeue(q);
    printf("Queue setelah proses dequeue\n");
    display(q->front);
    return 0;
}

