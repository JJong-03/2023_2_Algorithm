//Dijkstra
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<limits.h> // Maximum value for integer Value type of INT_MAX

#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType {
	int n; // 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int distance[MAX_VERTICES]; // 시작 정점으로부터의 최단 경로거리
int found[MAX_VERTICES]; // 방문한 정점 표시

int choose(int distance[], int n, int found[]) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;

	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}
// 각 step에서의 최종 경로 정보 출력하는 함수
void print_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF) printf(" * ");
		else printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("     found: ");
	for (int i = 0; i < g->n; i++) {
		printf("%2d ", found[i]);
	}
	printf("\n\n");
}

void shortest_path(GraphType* g, int start) {
	int i, u, w;

	for (i = 0; i < g->n; i++) {
		distance[i] = g->weight[start][i];
		found[i] = false;
	}

	found[start] = true; // 시작 정점 방문 표시
	distance[start] = 0;

	for (i = 0; i < g->n; i++) { // 모든 정점이 S에 포함될 때까지 실행
		print_status(g);// 현재 Step과 distance 배열 추력

		u = choose(distance, g->n, found);// S에 포함되지 않은 정점들 중에서 distance가 가장 작은 정점 u를 찾음

		found[u] = true;// 발견된 u를 S집합에 포함시킴

		//s에 포함되지 않은 모든 정점 w에 대해서
		for (w = 0; w < g->n; w++) {
			if(found[w] == false){
				if (distance[u] + g->weight[u][w] < distance[w]) {
					distance[w] = distance[u] + g->weight[u][w];
				}
			}
		}
	}


}
int main() {
	GraphType g = { 7,
		{{0,7,INF,INF,3,10,INF},
		{7,0,4,10,2,6,INF},
		{INF,4,0,2,INF,INF,INF},
		{INF,10,2,0,11,9,4},
		{3,2,INF,11,0,INF,5},
		{10,6,INF,9,INF,0,INF},
		{INF,INF,INF,4,5,INF,0}}
	};

	shortest_path(&g, 0);

	return 0;
}
#endif
// Floyd
#if 0
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
#define INF 10000000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int A[MAX_VERTICES][MAX_VERTICES];


void print_array_A(GraphType* g) {
	int i, j;
	printf("=======================\n");
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++) {
			if (A[i][j] == INF) printf(" * ");
			else printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("=======================\n");
}

void floyd(GraphType* g) {
	int i, j, k;
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++) {
			A[i][j] = g->weight[i][j];
		}
	}
	print_array_A(g);
	for (k = 0; k < g->n; k++) {
		for (i = 0; i < g->n; i++) {
			for (j = 0; j < g->n; j++) {
				if (A[i][k] + A[k][j] < A[i][j]) {
					A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
	}
	print_array_A(g);
}

int main() {
	GraphType g = { 7,
		{{0,7,INF,INF,3,10,INF},
		{7,0,4,10,2,6,INF},
		{INF,4,0,2,INF,INF,INF},
		{INF,10,2,0,11,9,4},
		{3,2,INF,11,0,INF,5},
		{10,6,INF,9,INF,0,INF},
		{INF,INF,INF,4,5,INF,0}}
	};

	floyd(&g);

	return 0;
}
#endif