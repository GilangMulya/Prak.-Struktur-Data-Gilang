//created by M.Gilang Mulya Putra_23343073
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
};

void initGraph(struct Graph *G, int numVertices);
void addEdge(struct Graph *G, int src, int dest);
void BFS(struct Graph *G, int startVertex);
void enqueue(struct Queue *queue, int value);
int dequeue(struct Queue *queue);
int isEmpty(struct Queue *queue);

void initGraph(struct Graph *G, int numVertices) {
    G->numVertices = numVertices;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            G->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph *G, int src, int dest) {
    G->adjMatrix[src][dest] = 1;
    //G->adjMatrix[dest][src] = 1; // Tidak diaktifkan untuk graf berarah
}

void BFS(struct Graph *G, int startVertex) {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;

    int visited[MAX_VERTICES] = {0};
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < G->numVertices; ++i) {
            if (G->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }

    free(queue);
}

void enqueue(struct Queue *queue, int value) {
    if (queue->rear == MAX_VERTICES - 1)
        printf("\nQueue is Full!!");
    else {
        if (queue->front == -1) queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(struct Queue *queue) {
    int item;
    if (queue->front == -1)
        printf("\nQueue is Empty!!");
    else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return item;
    }
}

int isEmpty(struct Queue *queue) {
    if (queue->front == -1)
        return 1;
    else
        return 0;
}

int main() {
    struct Graph G;
    int numVertices = 6;

    initGraph(&G, numVertices);

    addEdge(&G, 0, 1);
    addEdge(&G, 0, 2);
    addEdge(&G, 1, 3);
    addEdge(&G, 1, 4);
    addEdge(&G, 2, 4);
    addEdge(&G, 3, 4);
    addEdge(&G, 3, 5);
    addEdge(&G, 4, 5);

    printf("Breadth First Search starting from vertex 0: ");
    BFS(&G, 0);

    return 0;
}

