#include <iostream>
using namespace std;
bool m[25][25];
int cnt = 0;
void dfs(int x, int y, int ex, int ey) {
	if (x < 1 || x > ex || y < 1 || y > ex) return;
	if (x == ex && y == ey) {
		cnt++;
		return;
	}
	if(!m[x][y+1]) dfs(x, y + 1, ex, ey);
    if(!m[x+1][y]) dfs(x + 1, y, ex, ey);
}
int main() {
	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	int nx, ny;
	for (int i = 0; i < n; i++) {
		cin >> nx >> ny;
		m[nx][ny] = true;
	}
	dfs(1, 1, a, b);
	cout << cnt;
	return 0;
}
