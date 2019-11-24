#include <stdio.h>

#define N 5

// �߰��� ������ ���
#define NIL 99

#define FALSE 0
#define TRUE 1

#define UNVISITED 0
#define VISITED 1

int W[N][N]; //�ʱ� N*N ��� ���¿� �׷����� �Էµ˴ϴ�.
int F[N * 4][2]; // �̾��� �ִ� ���� ��µǴ� �Լ� �Դϴ�.

int _getmin(int data[], int set[]) {
	int min_idx = 0;
	int flag = FALSE;

	for (int i = 0; i < N; i++) {
		if (set[i] == UNVISITED) {
			if (flag == FALSE) {
				min_idx = i;
				flag = TRUE;
			}
			if (data[min_idx] > data[i]) {
				min_idx = i;
			}
		}
	}
	return min_idx;
}

int _empty(int data[]) {
	for (int i = 0; i < N; i++) {
		if (data[i] == UNVISITED)
			return FALSE;
	}
	return TRUE;
}


void dijkstra(int n, const int W[][N], int F[][2]) {
	int set[N] = { UNVISITED, UNVISITED, UNVISITED, UNVISITED, UNVISITED };
	int dist[N] = { 0, NIL, NIL, NIL, NIL };

	int path[N] = { NIL, NIL, NIL, NIL, NIL }; //F[][2] �ǵ��� ���� �̰ŷ� ��ü

	while (_empty(set) == FALSE) {
		int u = _getmin(dist, set);
		set[u] = VISITED;
		for (int v = 0; v < N; v++) {
			if (dist[v] > dist[u] + W[u][v] && W[u][v] != NIL) {
				dist[v] = dist[u] + W[u][v];
				path[v] = u;
			}	
		}
	}

	printf("������ ���� F�� ��� \n");
	printf("(v%d-v%d) \n", path[4] + 1, 4 + 1);
	printf("(v%d-v%d) \n", path[3] + 1, 3 + 1);
	printf("(v%d-v%d) \n", path[2] + 1, 2 + 1);
	printf("(v%d-v%d) \n", path[1] + 1, 1 + 1);
}

int main()
{
	int i, j;
	int W[N][N];
	printf("����ġ �׷����� ���ҵ��� �Է��ϼ��� : \n");
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			scanf("%d", &W[i][j]);
		}
	printf("\n");
	dijkstra(N, W, F);
	return 0;
}
