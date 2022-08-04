#include <iostream>
#include <cstring>
using namespace std;

// 两次BFS，一次求从起点到电脑的距离，一次求电脑到终点的距离... 

const int N = 510;
struct Pos {
	int x, y, step;
	Pos(int x, int y, int step) : x(x), y(y), step(step) {};
	Pos() {};
};
char graph[N][N];
int n, m;
int sx, sy, ex, ey, cx, cy;
Pos que[N * N];
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[N][N];
int bfs(int bsx, int bsy, int bex, int bey) {
	memset(visited, 0, sizeof visited);
	int qtop = 0, qback = 0;
	que[qtop] = Pos(bsx, bsy, 0);
	while (qtop <= qback) {
		Pos now = que[qtop++];
		if (now.x == bex && now.y == bey) return now.step;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx > n || ny < 1 || ny > m || ny < 1) continue;
			// 考虑到地图会被用两次，这里就开了个visited标记访问 
			// 忘了写是否是墙壁，迷... 
			if (visited[nx][ny] || graph[nx][ny] == '#') continue;
			visited[nx][ny] = true;
			que[++qback] = Pos(nx, ny, now.step + 1);
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'S') sx = i, sy = j;
			if (graph[i][j] == 'C') cx = i, cy = j;
			if (graph[i][j] == 'G') ex = i, ey = j;
		}
	} 
	// 为了提升效率所以这两个bfs分开调用 
	int r1 = bfs(sx, sy, cx, cy);
	if (r1 == -1) {
		cout << -1 << endl;
		return 0;
	}
	int r2 = bfs(cx, cy, ex, ey);
	if (r2 == -1) {
		cout << -1 << endl;
		return 0;
	}
	cout << r1 + r2 << endl;
	return 0;
}
