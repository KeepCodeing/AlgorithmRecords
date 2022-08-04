#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 洛谷上有一道完全一样的题，当时想到了跑遍BFS求下起点到所有点的时间，但是没想到怎么判断走到了安全的地方...
// 正确的做法就先将地图更新成流星坠落的最小时间形式的地图，然后跑最短路，能走到-1点（没被标记的点）就算走到
// 了安全的地方，即可返回步数，否则返回无法到达即可... 

// 一次AC，最幸福的人w 

const int N = 310;
int graph[N][N];
int mv[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct pos {
	int x, y, step;
	pos (int x, int y, int step) : x(x), y(y), step(step) {};
	pos () {};
} que[N * N + 10];
bool visited[N][N];
bool checker(int x, int y) {
	return (x < 0 || x >= N || y < 0 || y >= N);
}
int bfs(int sx, int sy) {
	int qtop = 0, qback = 0;
	que[qtop] = pos(sx, sy, 0);
	while (qtop <= qback) {
		pos now = que[qtop++];
		// 如果到了安全点，返回答案 
		if (graph[now.x][now.y] == -1) return now.step;
		for (int i = 1; i < 5; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (checker(nx, ny)) continue;
			// 判断是否访问以及当前走的步数是否超过了流星坠落的时间 
			if (visited[nx][ny] || graph[now.x][now.y] <= now.step) continue;
			visited[nx][ny] = true;
			que[++qback] = pos(nx, ny, now.step + 1);
		}
	}
	// 洛谷的题面好像没给出不能到达返回-1... 
	return -1;
}
int main() {
	int n, x, y, t;
	scanf("%d", &n);
	memset(graph, -1, sizeof graph);
	while (n--) {
		scanf("%d%d%d", &x, &y, &t);
		for (int i = 0; i < 5; i++) {
			// 将地图被流星袭击的时间更新为最短时间，注意这里移动方式有5种，因为一开始的点也可能被更新 
			int nx = x + mv[i][0], ny = y + mv[i][1];
			// 更新地图，这是这个题的关键之处之一... 
			if (checker(nx, ny)) continue;
			if (graph[nx][ny] == -1) graph[nx][ny] = t;
			else graph[nx][ny] = min(graph[nx][ny], t);
		}
	}
	// 跑最短路
	printf("%d", bfs(0, 0));
	return 0;
}
