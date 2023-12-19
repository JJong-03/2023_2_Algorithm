// BFS
#if 0
#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
#define MAX_QUEUE_SIZE 10
#define MAX_VERTICES 50
typedef int element;

typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;
int visited[MAX_VERTICES];

void enqueue(QueueType* q, element item);
int is_empty(QueueType* q);
element dequeue(QueueType* q);
void queue_init(QueueType* q);
int is_empty(QueueType* q);

void graph_init(GraphType* g) {
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++) {
        for (c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

void insert_vertex(GraphType* g, int v) {
    if ((g->n + 1) > MAX_VERTICES) {
        printf("Graph: the number of vertex exceeds the given limit! \n");
        return;
    }
    g->n++;
}
void insert_edge(GraphType* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        printf("Graph the index of vertice is wront !");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void Bfs_mat(GraphType* g, int v) {
    int w;
    QueueType q;

    queue_init(&q);
    visited[v] = true;
    printf("%d visited -> ", v);

    enqueue(&q, v);

    while (!is_empty(&q)) {
        v = dequeue(&q);
        for (w = 0; w < g->n; w++) {
            if (g->adj_mat[v][w] && !visited[w]) {
                visited[w] = true;
                printf("%d visited -> ", w);
                enqueue(&q, w);
            }
        }
    }
}

void queue_init(QueueType* q) {
    q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
    return (q->front == q->rear);
}
int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, element item) {
    if (is_full(q)) {
        printf("Queue is Full\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType* q) {
    if (is_empty(q)) {
        printf("Queue is empty");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

int main() {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));

    graph_init(g);
    for (int i = 0; i < 6; i++) {
        insert_vertex(g, i);
    }
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 0, 4);
    insert_edge(g, 4, 5);
    insert_edge(g, 1, 5);

    printf("BFS Implementation \n");
    Bfs_mat(g, 0);
    free(g);
    return 0;
}
#endif