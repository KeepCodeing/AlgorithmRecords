#include <iostream>
#include <cstdio>
using namespace std;
int res = 0, n, m, k;
const int N = 60;
int graph[N][N];
void dfs(int x, int y, int step, int mx) {
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (graph[x][y] < mx || step > k) return;
	if (step == k && x == n - 1 && y == m - 1) {
		res++;
		return;
	}
	cout << x << ' ' << y << endl;
	mx = max(mx, graph[x][y]);
//	cout << mx << endl;
	dfs(x + 1, y, step + 1, mx);
	dfs(x + 1, y, step, graph[x][y]);
	dfs(x, y + 1, step + 1, mx);
	dfs(x, y + 1, step, graph[x][y]);
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) scanf("%d", &graph[i][j]);
	}
	dfs(0, 0, 0, -1);
	cout << res;
	return 0;
}
