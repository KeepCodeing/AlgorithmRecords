#include <iostream>
using namespace std;
const int N = 100 + 10;
char graph[N][N];
int n, m;
void dfs(int x, int y) {
	if (x >= n || x < 0 || y >= m || y < 0) return;
	if (graph[x][y] == '*') return;
	graph[x][y] = '*';
	dfs(x + 1, y);
	dfs(x, y + 1);
	dfs(x - 1, y);
	dfs(x, y - 1);
	dfs(x + 1, y + 1);
	dfs(x + 1, y - 1);
	dfs(x - 1, y + 1);
	dfs(x - 1, y - 1);
}
int main() {
	while (cin >> n >> m, n, m) {
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) 
				cin >> graph[i][j];
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j] == '@') {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
