//Dijkstra
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<limits.h> // Maximum value for integer Value type of INT_MAX

#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType {
	int n; // ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int distance[MAX_VERTICES]; // ���� �������κ����� �ִ� ��ΰŸ�
int found[MAX_VERTICES]; // �湮�� ���� ǥ��

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
// �� step������ ���� ��� ���� ����ϴ� �Լ�
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

	found[start] = true; // ���� ���� �湮 ǥ��
	distance[start] = 0;

	for (i = 0; i < g->n; i++) { // ��� ������ S�� ���Ե� ������ ����
		print_status(g);// ���� Step�� distance �迭 �߷�

		u = choose(distance, g->n, found);// S�� ���Ե��� ���� ������ �߿��� distance�� ���� ���� ���� u�� ã��

		found[u] = true;// �߰ߵ� u�� S���տ� ���Խ�Ŵ

		//s�� ���Ե��� ���� ��� ���� w�� ���ؼ�
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