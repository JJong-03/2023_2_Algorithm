//TSP 알고리즘 구현
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

#define INF 1000000 // 무한대(연결이 없는 경우)
#define MAX_VERTICES 110

int N;  // 총 노드 수
int W[MAX_VERTICES][MAX_VERTICES]; // 베열 W 방문한 노드 표시를 위해

int dp[MAX_VERTICES][MAX_VERTICES];
// 배열 dp ==> 결과값 Distance 포함

int min(int a, int b) {
    return (a < b) ? a : b;
}

int BacktrackTSP(int current, int visited) {
    //현재 도시가 current이고, current을  포함해서 방문했었던 도시들을 표현한 것이 visited일때, 앞으로 가야할 길 중에 최소를 구함
    int result;
    int bestsolution = dp[current][visited];
    if (bestsolution != 0) {
        return bestsolution;
        // 앞으로 다 돌기까지 남은 길 중에 최솟값을 미리 구해놨다면, 그 경로가 최소임이 자명하므로, 저장된 값 불러옴.
    }// end if
    // 다 돌고 처음 도시로 돌아가는 경우
    if (visited == ((1 << N) - 1)) {
        if (W[current][0] != 0)
            return W[current][0];
        return INF;
    } // endif
    bestsolution = INF;
    for (int i = 0; i < N; i++) {
        if (W[current][i] == 0 || (visited & (1 << i))) {
            // 1. 길이 없거나, 2. 한 번 방문한 도시(i)를 다시 방문하려고 한다면 -->
               // 건너뛰어야함
            continue;
        }
        bestsolution = min(bestsolution, W[current][i] + BacktrackTSP(i, visited | 1 << i));
        //current --> i 로 간 다음에 i에서 나머지 도시들 순회 한 거 중 최소 or 지금 값 2개 중 최소를 가림
    } // end for loop
    dp[current][visited] = bestsolution; // 최소화 된 값을 dp 배열에 저장
    return bestsolution;
} //end BacktrackTSP

int main() {

    int i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &W[i][j]);
        }
    }
    int result = BacktrackTSP(0, 1);
    printf("\n The total distance of Tsp = %d \n", result);
    return 0;
}
#endif