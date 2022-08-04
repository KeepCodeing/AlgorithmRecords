#include <iostream>
#define endl '\n'
using namespace std;

const int N = 100 + 10;

int mp[N][N], f[N][N];
int mv[3][2] = {{-1, 1}, {0, 1}, {1, 1}};
int r, c;

int dfs(int x, int y) {
	
	if (f[x][y]) return f[x][y];
	
	if (x == r && y == c) return mp[r][c];
	
	for (int i = 0; i < 3; i++) {
		int nx = x + mv[i][0], ny = y + mv[i][1];
		if (nx <= 0 || nx > r || ny <= 0 || ny > c) continue;
		f[x][y] = max(f[x][y], dfs(nx, ny) + mp[x][y]);
	}
	
	return f[x][y];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> mp[i][j];
		}
	}
	cout << dfs(1, 1) << endl;
	return 0;
}
/*
7 12
21 12 1 25 10 10 10 17 1 23 23 1
1 11 24 12 17 25 5 15 16 16 22 9
17 15 10 24 23 8 18 8 10 6 9 9
2 23 8 13 14 22 21 22 11 22 3 22
18 22 22 5 18 1 11 23 23 16 5 15
24 10 21 11 2 2 15 19 7 1 4 9
7 20 8 22 23 8 23 24 20 3 2 1

*/
