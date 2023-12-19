// DFS
#if 0
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

void init(GraphType* g) {
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++) {
        for (c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "Graph: The number of vertices is greater than given Max_Vertices");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "Graph: Vertex index error");
        return;
    }

    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void dfs_mat(GraphType* g, int v)
{
    int w;
    visited[v] = TRUE;
    printf("Visited Vertex %d -> ", v);
    for (w = 0; w < g->n; w++)
    {
        if (g->adj_mat[v][w] && !visited[w])
        {
            dfs_mat(g, w);
        }
    }
}


int main() {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for (int i = 0; i < 4; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    printf("Implement DFS \n");
    dfs_nat(g, 0);
    printf("\n");
    free(g);
    return 0;

}

#endif

// BFS
#if 0
#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
#define MAX_QUEUE_SIZE 10
#define MAX_VERTICES 50

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;
int visited[MAX_VERTICES];

void graph_init(GraphType* g) {
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++) {
        for (c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}
typedef int element;

typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void insert_vertex(GraphType* g, int v) {
    if ((g->n + 1) > MAX_VERTICES) {
        printf("Graph: the number of vertex exceeds the given limit! \n");
        return;
    }
    g->n++;
}
void insert_edge(GraphType* g, int start, int end) {
    if (start >= g->n || end >= g->n){
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
    if (is_full(q)){
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

// Prim Algolithm
#if 0
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L //L은 long int

typedef struct GraphType {
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

//최소 dist[v] 값을 갖는 정점을 변환
int get_min_vertex(int n) {
    int v, i;
    for (int i = 0; i < n; i++) {
        if (!selected[i]) {
            v = i;
            break;
        }
    }
    for (i = 0; i < n; i++) {
        if (!selected[i] && (distance[i] < distance[v])) {
            v = i;
        }
    }
    return v;
}


void prim(GraphType* g, int s) {
    int i, u, v;
    for (u = 0; u < g->n; u++) {
        distance[u] = INF;
    }
    distance[s] = 0;
    for (int i = 0; i < g->n; i++) {
        u = get_min_vertex(g->n);
        selected[u] = TRUE;
        if (distance[u] == INF) return;
        printf("Vertex %d Added\n", u);
        for (v = 0; v < g->n; v++) {
            if (g->weight[u][v] != INF)
                if (!selected[v] && g->weight[u][v] < distance[v])
                    distance[v] = g->weight[u][v];
        }
    }
}

int main() {
    GraphType g = { 7,
        {{0,29,INF,INF,INF,10,INF},
        {29,0,16,INF,INF,INF,15},
        {INF,16,0,12,INF,INF,INF},
        {INF,INF,12,0,22,INF,18},
        {INF,INF,INF,22,0,27,25},
        {10,INF,INF,INF,27,0,INF},
        {INF,15,INF,18,25,INF,0}}
    };
    printf("PRIM MST Algorithm \n");
    prim(&g, 0);

    return 0;
}
#endif