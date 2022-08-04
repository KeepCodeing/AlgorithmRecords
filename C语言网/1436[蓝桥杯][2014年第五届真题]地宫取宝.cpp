#include <iostream>
using namespace std;
int graph[55][55];
int n, m, k;
int cnt = 0;
void dfs(int sx, int sy, int k, int maxVal) {
	if (k < 0) return;
	if (sx < 1 || sx > n || sy < 1 || sy > m) return;
	if (graph[sx][sy] < 0 || graph[sx][sy] < maxVal) return;
	if (sx == n && sy == m && k == 0) {
		cnt = (cnt + 1) % 1000000007;
		return;
	}
	int temp = graph[sx][sy];
	graph[sx][sy] = -1;
//	int maxSx = graph[sx + 1][sy];
//	int maxSy = graph[sx][sy + 1];
	if (graph[sx][sy] > maxVal) {
		dfs(sx, sy + 1, k - 1, graph[sx][sy]);
		dfs(sx, sy + 1, k, maxVal);
		
		dfs(sx + 1, sy, k - 1, graph[sx][sy]);
		dfs(sx + 1, sy, k, maxVal);
	}
//	if (graph[sx][sy] > maxVal) {
//		
//	}
	graph[sx][sy] = temp;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
		}
	}
	dfs(1, 1, k, -1);
	cout << cnt;
	return 0;
}
