#include <iostream>
#include <queue>
#include <cstring>
#define endl '\n'
#define x first
#define y second
using namespace std;
typedef pair<int, int > PII;
const int N = 550;
char mp[N][N];
bool vis[N][N];
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int T, sx, sy, ex, ey, n, m;
string bfs(int sx, int sy, int ex, int ey) {
	queue<PII > que;
	que.push(PII(sx, sy));
	vis[sx][sy] = true;
	while (que.size()) {
		PII now = que.front(); que.pop();
		if (now.x == ex && now.y == ey) return "YES";
		for (int i = 0; i < 4; i++) {
			int nx = now.x + mv[i][0], ny = now.y + mv[i][1];
			if (nx <= 0 || nx > n || ny <= 0 || ny >= m) continue;
			if (vis[nx][ny]) continue;
			if (mp[nx][ny] == 'x') continue;
			vis[nx][ny] = true;
			que.push(PII(nx, ny)); 
		}
	} 
	return "NO";
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		memset(vis, 0, sizeof vis);
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m ; j++) {
				cin >> mp[i][j];	
				if (mp[i][j] == 's') sx = i, sy = j;
				if (mp[i][j] == 't') ex = i, ey = j;
			}
		}
		cout << bfs(sx, sy, ex, ey) << endl;
	}
	return 0;
}
