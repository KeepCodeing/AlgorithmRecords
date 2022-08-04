#include <iostream>
using namespace std;

char m[201][201];
int cnt = 0;
void dfs(int x, int y, int line, int col) {
	if (x < 1 || x > line || y < 1 || y > col) return;
	if (m[x][y] != '.') return;
	cnt++;
	m[x][y] = '#';
	dfs(x + 1, y, line, col);
	dfs(x - 1, y, line, col);
	dfs(x, y + 1, line, col);
	dfs(x, y - 1, line, col);
}

int main() {
	int h, n;
	int start_x, start_y;
	cin >> n >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> m[i][j];
			if (m[i][j] == '@') {
				start_x = i, start_y = j;
				m[i][j] = '.';
			}
		}
	}
	dfs(start_x, start_y, h, n); 
	cout << cnt;
	return 0;
}
