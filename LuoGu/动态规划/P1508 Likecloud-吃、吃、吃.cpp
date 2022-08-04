#include <iostream>
#define endl '\n'
using namespace std;
const int N = 200;
int mp[N][N];
int mv[3][2] = {{-1, 0}, {-1, -1}, {-1, 1}};
int f[N][N];
int m, n;

// 和滑雪哪一题一样....唯一要注意的是它判断是否得到答案是通过是否到达边界来的... 

int dfs(int x, int y) {
	
	if (x < 0 || x >= m || y < 0 || y >= n) return 0;
	
	if (f[x][y]) return f[x][y];
	
	for (int i = 0; i < 3; i++) {
		int nx = x + mv[i][0], ny = y + mv[i][1];
		f[x][y] = max(f[x][y], dfs(nx, ny) + mp[x][y]);
	}
	
	return f[x][y];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> m >> n;
	int sx = m - 1, sy = n / 2;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];	
		}
	}
	int ans = max(dfs(sx, sy - 1), dfs(sx, sy));
	ans = max(ans, dfs(sx, sy + 1));
	cout << ans << endl;
	return 0;
}
