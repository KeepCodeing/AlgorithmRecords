#include <iostream>
using namespace std;
const int N = 23;
char graph[N][N];
int sx, sy;
int n, m;
void dfs(int sx, int sy, int& cnt) {
	if (sx > n || sx < 1 || sy > m || sy < 1) return;
	if (graph[sx][sy] != '.') return;
	graph[sx][sy] = '#';
	cnt++;
	dfs(sx + 1, sy, cnt);
	dfs(sx - 1, sy, cnt);
	dfs(sx, sy + 1, cnt);
	dfs(sx, sy - 1, cnt);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	do {
		cin >> m >> n;
		if (!m && !n) break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> graph[i][j];
				if (graph[i][j] == '@') {
					sx = i, sy = j; 	
					graph[i][j] = '.';
				}
			}
		}
		int cnt = 0;
		dfs(sx, sy, cnt);
		cout << cnt << endl;
	} while (n && m);
	
	return 0;
}
/*
6 9 
....#. 
.....# 
...... 
...... 
...... 
...... 
...... 
#@...# 
.#..#. 
0 0

45
*/
