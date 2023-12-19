//TSP �˰��� ����
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

#define INF 1000000 // ���Ѵ�(������ ���� ���)
#define MAX_VERTICES 110

int N;  // �� ��� ��
int W[MAX_VERTICES][MAX_VERTICES]; // ���� W �湮�� ��� ǥ�ø� ����

int dp[MAX_VERTICES][MAX_VERTICES];
// �迭 dp ==> ����� Distance ����

int min(int a, int b) {
    return (a < b) ? a : b;
}

int BacktrackTSP(int current, int visited) {
    //���� ���ð� current�̰�, current��  �����ؼ� �湮�߾��� ���õ��� ǥ���� ���� visited�϶�, ������ ������ �� �߿� �ּҸ� ����
    int result;
    int bestsolution = dp[current][visited];
    if (bestsolution != 0) {
        return bestsolution;
        // ������ �� ������� ���� �� �߿� �ּڰ��� �̸� ���س��ٸ�, �� ��ΰ� �ּ����� �ڸ��ϹǷ�, ����� �� �ҷ���.
    }// end if
    // �� ���� ó�� ���÷� ���ư��� ���
    if (visited == ((1 << N) - 1)) {
        if (W[current][0] != 0)
            return W[current][0];
        return INF;
    } // endif
    bestsolution = INF;
    for (int i = 0; i < N; i++) {
        if (W[current][i] == 0 || (visited & (1 << i))) {
            // 1. ���� ���ų�, 2. �� �� �湮�� ����(i)�� �ٽ� �湮�Ϸ��� �Ѵٸ� -->
               // �ǳʶپ����
            continue;
        }
        bestsolution = min(bestsolution, W[current][i] + BacktrackTSP(i, visited | 1 << i));
        //current --> i �� �� ������ i���� ������ ���õ� ��ȸ �� �� �� �ּ� or ���� �� 2�� �� �ּҸ� ����
    } // end for loop
    dp[current][visited] = bestsolution; // �ּ�ȭ �� ���� dp �迭�� ����
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