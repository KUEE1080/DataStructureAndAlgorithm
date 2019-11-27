#include <stdio.h>

#define N 5

// 추가로 설정한 상수
#define NIL 99

#define FALSE 0
#define TRUE 1

#define UNVISITED 0
#define VISITED 1

int W[N][N]; //초기 N*N 행렬 형태에 그래프가 입력됩니다.
int F[N * 4][2]; // 이어져 있는 선이 출력되는 함수 입니다.

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

void _initSet(int set[]) { for (int i = 0; i < N; i++) { set[i] = UNVISITED; } }
void _initDist(int dist[]) { for (int i = 0; i < N; i++) { dist[i] = NIL; } }
void _initPath(int path[]) { for (int i = 0; i < N; i++) { path[i] = NIL; } }


void dijkstra(int n, const int W[][N], int F[][2]) {
	int set[N], dist[N], path[N];
	_initSet(set);
	_initDist(dist);
	_initPath(path); //F[][2] 의도를 몰라서 이거로 대체

	dist[0] = 0;

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

	printf("이음선 집합 F의 행렬 \n");
	for (int i = N - 1; i >= 1; i--) { printf("(v%d-v%d) \n", path[i] + 1, i + 1); }
}

int main()
{
	int i, j;
	int W[N][N];
	printf("가중치 그래프의 원소들을 입력하세요 : \n");
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			scanf("%d", &W[i][j]);
		}
	printf("\n");
	dijkstra(N, W, F);
	return 0;
}
