#include <iostream>
#include <cstring>
using namespace std;

// 要点是如何判断某个点能走遍全图，其它都和普通DFS相似 

const int N = 15;
int n, m, sx, sy;
int ans = 0;
bool graph[N][N];
int move[8][2] = {{1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
void dfs(int sx, int sy, int cnt) {
	if (sx > n || sx < 1 || sy > m || sy < 1) return;
	if (graph[sx][sy]) return;
	graph[sx][sy] = true;
	// 如果当前每个点都走过了，就说明这个方向是可行 
	// 注意这里没有return，加了return第一次走到终点就不会继续往后走了 
	if (cnt == n * m - 1) ans++;
	for (int i = 0; i < 8; i++) {
		int nx = sx + move[i][0], ny = sy + move[i][1];
		dfs(nx, ny, cnt + 1);
	}
	graph[sx][sy] = false;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> sx >> sy;
		ans = 0;
		memset(graph, false, sizeof graph);
		dfs(sx + 1, sy + 1, 0);
		cout << ans << endl;
	}
	return 0;
}
/*
1
5 4 0 0

32
*/
