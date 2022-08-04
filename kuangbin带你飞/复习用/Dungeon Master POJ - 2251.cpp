#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 3维BFS， 惯例的复习，其不想学习新算法或者说不知道学什么新算法，究其原因，本five局的是“没必要学”这种想法导致的...
// 这自然也与蓝桥杯水平有关系，其目标也只是简单的拿个省一什么的...故此颓废与迷茫都是必然的，或许真的只有运气才能让其
// 继续前行了... 

const int N = 30 + 10;
char graph[N][N][N];
int sx, sy, sz, ex, ey, ez;
int l, r, c;
int mv[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
struct Node {
	int x, y, z, step;
	Node (int x, int y, int z, int step) : x(x), y(y), z(z), step(step) {};
	Node () {};
} que[N * N * N];
int bfs() {
	int qtop = 0, qback = 0;
	que[qtop] = Node(sx, sy, sz, 0);
	while (qtop <= qback) {
		Node now = que[qtop++];
		// cout << now.x << ' ' << now.y << ' ' << now.z << endl;
		if (now.x == ex && now.y == ey && now.z == ez) return now.step;
		for (int i = 0; i < 6; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1], nz = now.z + mv[i][2]; // 这里写成了now.z + mv[i][1]半天看不了出来.. 
			if (nx >= l || nx < 0 || ny >= r || ny < 0 || nz >= c || nz < 0) continue;
			if (graph[nx][ny][nz] == '#') continue;
			//visited[nx][ny][nz] = true; 看了之前的代码才想起来可以直接改地图，不得不说有点倒车的感觉了... 
			graph[nx][ny][nz] = '#';
			que[++qback] = Node(nx, ny, nz, now.step + 1);
		}
	}
	return -1;
}
int main() {
	while (true) {
		scanf("%d%d%d", &l, &r, &c);
		if (!l && !r && !c) break;
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
