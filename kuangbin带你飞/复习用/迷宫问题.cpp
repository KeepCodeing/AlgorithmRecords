#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define x first
#define y second
const int N = 10, M = 5;
typedef pair<int, int > PII;
int graph[N][N];
PII dist[N][N];
PII que[N * N];
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void bfs(int x, int y) {
	memset(dist, -1, sizeof dist);
	int qtop = 0, qback = 0;
	que[qtop] = PII(x, y); 
	dist[x][y] = PII(0, 0);
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 0 || nx >= M || ny < 0 || ny >= M) continue;
			if (graph[nx][ny] || dist[nx][ny].x != -1) continue;
			dist[nx][ny] = PII(now.x, now.y);
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	bfs(4, 4);
	// 注意这里不能直接写dist[0][0]，这样起点不会输出... 
	PII now = PII(0, 0);
	while (true) {
		printf("(%d,%d)\n", now.x, now.y);
		if (now.x == M - 1 && now.y == M - 1) break;
		now = dist[now.x][now.y];
	}
	return 0;
}
