#include <iostream>
using namespace std;

// 这个题和前面的题比似乎简单了些，而且也是其做过的w，用DFS八向搜求连通块就行... 

const int N = 110;
int n, m;
char graph[N][N];
// DFS似乎有点忘了w 
void dfs(int sx, int sy) {
	if (sx >= n || sx < 0 || sy >= m || sy < 0) return;
	if (graph[sx][sy] != '@') return;
	graph[sx][sy] = '*';
	// 八向搜的里技 
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i != 0 || j != 0) {
				dfs(sx + i, sy + j);
			}
		}
	}
}
int main() {
	// 四向搜，不能有相反数和相同的情况 
//	for (int i = -1; i <= 1; i++) {
//		for (int j = -1; j <= 1; j++) {
//			if ((i != 0 || j != 0) && i != j && i != -j) cout << i << ' ' << j << endl;
//		}
//	}
	while (true) {
		cin >> n >> m;
		if (!n && !m) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> graph[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j] != '*') {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
