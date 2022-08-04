#include <iostream>
#include <cstdio>
using namespace std;
const int N = 30 + 10;
char graph[N][N][N];
int sx, sy, sz, ex, ey, ez;
int l, r, c;
struct Node {
	int x, y, z, step;
	Node (int x, int y, int z, int step) : x(x), y(y), z(z), step(step) {};
	Node () {};
} que[N * N * N];
int mv[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
int bfs() {
	int qtop = 0, qback = 0;
	que[qtop] = Node(sx, sy, sz, 0);
	while (qtop <= qback) {
		Node now = que[qtop++];
		if (now.x == ex && now.y == ey && now.z == ez) return now.step;
		for (int i = 0; i < 6; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1], nz = now.z + mv[i][2];
			if (nx >= l || nx < 0 || ny >= r || ny < 0 || nz >= c || nz < 0) continue;
			if (graph[nx][ny][nz] == '#') continue;
			graph[nx][ny][nz] = '#';
			que[++qback] = Node(nx, ny, nz, now.step + 1);
		}
	}
	return -1;
}
int main() {
	while (scanf("%d%d%d", &l, &r, &c)) {
		if (l == 0 && r == 0 && c == 0) break;
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
		if (res == -1) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n", res);
	}
	return 0;
}
/*
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
*/
