#include <iostream>
using namespace std;

// 不久刚做的一个三维最短路的题，洛谷上有个一模一样的题...拿来fuxi，顺便刷下题量... 
// 7m写完，感觉编码还是要追求速度呢... 

const int N = 35, M = 6;
int l, r, c;
char graph[N][N][N];
int sx, sy, sz, ex, ey, ez;
int x[M] = {1, -1, 0, 0, 0, 0}, y[M] = {0, 0, 1, -1, 0, 0}, z[M] = {0, 0, 0, 0, 1, -1};
struct Node {
	int x, y, z, step;
	Node (int x, int y, int z, int step) : x(x), y(y), z(z), step(step) {};
	Node () {};
} que[N * N * N + 10];
int bfs() {
	int qtop = 0, qback = 0;
	que[qtop] = Node(sx, sy, sz, 0);
	while(qtop <= qback) {
		Node now = que[qtop++];
		if (now.x == ex && now.y == ey && now.z == ez) return now.step;
		for (int i = 0; i < 6; i++) {
			int nx = now.x + x[i], ny = now.y + y[i], nz = now.z + z[i];
			if (nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || ny >= c) continue;
			if (graph[nx][ny][nz] == '#') continue;
			graph[nx][ny][nz] = '#';
			que[++qback] = Node(nx, ny, nz, now.step + 1);
		}
	}
	return -1;
}
int main() {
	cin >> l >> r >> c;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				cin >> graph[i][j][k];
				if (graph[i][j][k] == 'S') sx = i, sy = j, sz = k;
				if (graph[i][j][k] == 'E') ex = i, ey = j, ez = k;
			}
		}
	}
	int res = bfs();
	if (res == -1) cout << "Trapped!";
	else cout << "Escaped in " << res << " minute(s).";
	return 0;
}
