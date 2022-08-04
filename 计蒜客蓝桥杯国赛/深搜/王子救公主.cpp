#include <iostream>
#define endl '\n'
using namespace std;
const int N = 110;
char graph[N][N];
bool vis[N][N][2];
int wx, wy, gx, gy;
int n, m;
void dfs(int x, int y, int d) {
	if (x >= n || x < 0 || y >= m || y < 0) return;
	if (vis[x][y][d - 1]) return;
	vis[x][y][d - 1] = true;
	
	dfs(x + d, y, d);
	dfs(x - d, y, d);
	dfs(x, y + d, d);
	dfs(x, y - d, d);
}
int main () {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	cin >> n >> m;
	bool ans = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'w') wx = i, wy = j;
			if (graph[i][j] == 'g') gx = i, gy = j;
		}
	}
	dfs(wx, wy, 2);
	dfs(gx, gy, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j][0] && vis[i][j][1]) {
				ans = true;
				break;
			}
		}
	}
	if (ans) cout << "yes";
	else cout << "no";
	return 0;
}
