#include <iostream>
#include <cstring>
using namespace std;

// 看起来比以前写的简洁多了，难的的开正车w，之前写的主要是用queue，四个方向用的是循环，两个起点用的数组，明明把终点
// 都存起来了却还是把两个起点都变成了障碍物... 

#define x first
#define y second
const int N = 210;
typedef pair<int, int > PII;
char graph[N][N];
PII s1, s2;
int _dist[N][N], __dist[N][N];
PII que[N * N];
PII mouse[N * N];
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;
void bfs(PII st, int dist[N][N]) {
	int qtop = 0, qback = 0;
	que[qtop] = st;
	dist[st.x][st.y] = 0;
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (graph[nx][ny] == '#') continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[now.x][now.y] + 1;
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	int cnt;
	while (cin >> n >> m) {
		cnt = 0;
		memset(_dist, -1, sizeof _dist);
		memset(__dist, -1, sizeof __dist);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> graph[i][j];
				if (graph[i][j] == 'Y') s1 = PII(i, j);
				if (graph[i][j] == 'M') s2 = PII(i, j);	
				if (graph[i][j] == '@') mouse[cnt++] = PII(i, j);
			}
		}
		bfs(s1, _dist);
		bfs(s2, __dist);
		int res = 0x3fffffff;
		for (int i = 0; i < cnt; i++) {
			int d1 = _dist[mouse[i].x][mouse[i].y], d2 = __dist[mouse[i].x][mouse[i].y];
			if (d1 == -1 || d2 == -1) continue;
			res = min(res, d1 * 11 + d2 * 11);
		}
		cout << res << endl;
	}
	return 0;
}
