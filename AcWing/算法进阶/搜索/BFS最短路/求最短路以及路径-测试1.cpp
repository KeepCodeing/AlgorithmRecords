#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define x first
#define y second
typedef pair<int, int > PII;
const int N = 1010, M = N * N;
int graph[N][N];
int n;
PII que[M], pre[N][N];
int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	memset(pre, -1, sizeof pre);
	que[qtop] = PII(sx, sy);
	pre[sx][sy] = PII(0, 0);
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if (pre[nx][ny].x != -1) continue;
			pre[nx][ny] = now;
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	bfs(n, n);
	PII end(1, 1);
	while (true) {
		printf("%d %d\n", end.x - 1, end.y - 1);
		if (end.x == n && end.y == n) break;
		end = pre[end.x][end.y];
	}
	return 0;
}
/*
5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
*/
