#include <iostream>
#include <queue>
#include <cstring>
#define endl '\n'
#define x first
#define y second
using namespace std;

// https://www.luogu.com.cn/problem/P1332

const int N = 500 + 10;
int n, m, a, b;
int mv[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
typedef pair<int, int > PII;
queue<PII > que;
int dist[N][N];
void bfs() {
	while (que.size()) {
		PII now = que.front(); que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx > n || nx < 1 || ny > m || ny < 1) continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[now.x][now.y] + 1;
			que.push(PII(nx, ny)); 
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int x, y;
	cin >> n >> m >> a >> b;
	memset(dist, -1, sizeof dist);
	while (a--) {
		cin >> x >> y;
		dist[x][y] = 0;
		que.push(PII(x, y)); 
	}	
	bfs();
	while (b--) {
		cin >> x >> y;
		cout << dist[x][y] << endl;
	}
	return 0;
}
