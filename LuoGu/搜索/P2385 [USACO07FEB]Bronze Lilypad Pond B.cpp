#include <iostream>
#include <cstdio>
using namespace std;
struct Node {
	int x, y, step;
	Node(int x, int y, int step) : x(x), y(y), step(step) {}
	Node() {}
};
const int N = 100;
int m, n, m1, m2;
bool graph[N][N];
int sx, sy, ex, ey;
int move[8][2];
Node que[N * N];
int bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	que[qtop] = Node(sx, sy, 0);
	while (qtop <= qback) {
		Node now = que[qtop++];
		if (now.x == ex && now.y == ey) return now.step;
		for (int i = 0; i < 8; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx > n || nx < 1 || ny > m || ny < 1) continue;
			if (!graph[nx][ny]) continue;
			// 草生，之前把这里写成了true，结果就RE了几个点w，迷
			// 标记为走过，不然会有重复访问 
			graph[nx][ny] = false;
			que[++qback] = Node(nx, ny, now.step + 1);
		}
	}
	return 0;
}
void initMove() {
	move[0][0] = m1, move[0][1] = m2;
	move[1][0] = m2, move[1][1] = m1;
	move[2][0] = -m1, move[2][1] = m2;
	move[3][0] = -m2, move[3][1] = m1;
	move[4][0] = m1, move[4][1] = -m2;
	move[5][0] = m2, move[5][1] = -m1;
	move[6][0] = -m1, move[6][1] = -m2;
	move[7][0] = -m2, move[7][1] = -m1;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &m1, &m2);
	int t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &t);
			if (t == 3) sx = i, sy = j;
			else if (t == 4) ex = i, ey = j;
			else if (t != 1) t = 0;
			graph[i][j] = t;
		}
	}
	initMove();
	cout << bfs(sx, sy);
	return 0;
}

