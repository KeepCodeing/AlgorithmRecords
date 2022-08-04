#include <iostream>
#include <cstring>
using namespace std;

// BFS模拟，长草的题目... 

#define x first
#define y second
typedef pair<int, int > PII;
int n, m;
int sx, sy;
const int N = 110;
char graph[N][N];
int dist[N][N];
PII que[N * N];
int move[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
void bfs(int sx, int sy) {
	memset(dist, -1, sizeof dist);
	int qtop = 0, qback = 0;
	que[qtop] = PII(sx, sy);
	dist[sx][sy] = 0;
	while (qtop <= qback) {
		PII now = que[qtop++];
		for (int i = 0; i < 8; i++) {
			int nx = now.x + move[i][0], ny = now.y + move[i][1];
			if (nx > n || nx < 1 || ny > m || ny < 1) continue;
			if (dist[nx][ny] != -1 || graph[nx][ny] == '*') continue;
			dist[nx][ny] = dist[now.x][now.y] + 1;
			que[++qback] = PII(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);  
	// 先输入列，再输入行 
	cin >> m >> n >> sx >> sy;
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
		}
	}
	bfs(sy, sx);
	int res = 0;
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			cout << dist[i][j] << ' ';
			//res = max(res, dist[i][j]);
		}
		cout << endl;
	}
	cout << res;
	return 0;
}
/*

4 3 1 1
....
..*.
.**.


10 15 2 10
*.........
..........
..........
......*...
..........
......*...
..........
.......*..
..........
..........
..........
....*.....
..........
..........
..........

*/
