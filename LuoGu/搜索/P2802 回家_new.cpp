#include <iostream>
#include <cstdio>
using namespace std;

// 之前用DFS写的不知道为什么WA了一个点，现在回头来看发现这个题用
// BFS写应该更合理，因为要求的是最短路... 
// 坠毁w... 

const int N = 15;
int graph[N][N];
struct Node {
	int x, y, step, life;
	Node (int x, int y, int step, int life) : x(x), y(y), step(step), life(life) {};
	Node () {};
} que[N * N];
int n, m;
int sx, sy, ex, ey;
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	que[qtop] = Node(sx, sy, 0, 6);
	while (qtop <= qback) {
		Node now = que[qtop++];
		// 这里不能写成graph[now.x][now.y] == 3之类的判断，因为走过的点就会置零... 
		if (now.x == ex && now.y == ey && now.life > 0) return now.step;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (graph[nx][ny] == 0) continue;
			if (graph[nx][ny] == 4 && now.life > 0) que[++qback] = Node(nx, ny, now.step + 1, 6);
			else que[++qback] = Node(nx, ny, now.step + 1, now.life - 1);
//			graph[nx][ny] = 0;
		}		
	}
	return -1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 2) sx = i, sy = j;
			if (graph[i][j] == 3) ex = i, ey = j;
		}
	}
	printf("%d", bfs(sx, sy));
	return 0;
}
/*
7 6
2 0 0 0 0 0 
1 0 0 0 0 0 
1 1 4 0 0 0 
1 0 0 0 0 0 
1 1 1 1 1 3
4 0 1 0 4 0 
0 0 4 0 0 0
*/
