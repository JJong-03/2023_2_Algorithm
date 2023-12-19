#if 0
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX_VERTICES   100   
#define INF   1000000   /* 무한대 (연결이 없는 경우) */

typedef struct GraphType {
    int n;   // 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

//=========================================================
int A[MAX_VERTICES][MAX_VERTICES];

void print_array_A(GraphType* g)
{
    int i, j;
    printf("===============================\n");
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->n; j++) {
            if (A[i][j] == INF)
                printf("  * ");          // * 전에 두칸이 빈칸, * 후에 한칸이 빈칸
            else printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    printf("===============================\n");
}

void floyd(GraphType* g) {
    int i, j, k;
    for (i = 0; i < g->n; i++) {
        for (j = 0; j < g->n; j++) {
            A[i][j] = g->weight[i][j];
        }
    }  //End outer 배열 A에 weight값 할당
    print_array_A(g);    //프린트 초기 배열값  A
    for (k = 0; k < g->n; k++) {
        for (i = 0; i < g->n; i++)
            for (j = 0; j < g->n; j++)
                if (A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
        print_array_A(g); //각 정점을 거쳐서 가는 경로와 비교하여 최단 경로를 수정한 후, 배열 A 프린트 
    } //End outer for
}

int main(void)
{
    GraphType g = { 10,
       {{ 0,  5, 6, INF,   INF,  INF,  INF,  INF, 7, 14 },
       { 5,  0,    5,  4,  INF,   INF, INF,  INF,  INF,  INF },
       { 6,  5,    0,   3, 10, 11, INF, INF, INF, 5 },
       { INF, 4,  3,   0,  6,  INF,    INF, INF, INF,INF },
       { INF, INF,  10,   6,  0,  8,    INF, INF, INF,INF },
       { INF,  INF,  11,  INF,   8, 0, 7,  INF, INF, 6 },
       {  INF,  INF,   INF,  INF,  INF, 7, 0, 3,  INF, 4 },
       { INF, INF, INF,   INF,   INF,  INF, 3, 0, 8, INF },
       { 7, INF, INF,   INF,   INF,  INF, INF, 8, 0, 15 },
       { 14, INF, 5,   INF,   INF,  6, 4, INF, 15, 0 }, }
    };
    floyd(&g);
    return 0;
}
#endif