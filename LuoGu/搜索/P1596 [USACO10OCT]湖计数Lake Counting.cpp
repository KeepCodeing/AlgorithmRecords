#include <iostream>
using namespace std;
int h, w;
char m[105][105];
int path[8][2] ={{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

// 写了半天卡在出界上了，感觉是变量名的问题，太拘泥于x，y了 

void dfs(int x, int y) {
	// m[x][y] = '.';
//	for (int i = 0; i < 8; i++) {
//		int next_x, next_y;
//		next_x = x + path[i][0], next_y = y + path[i][1];
//		if (next_x > h || next_x < 1 || next_y > w || next_y < 1 || m[next_x][next_y] == '.') continue;
//		m[next_x][next_y] = '.';
//		dfs(next_x, next_y);
//	}
	if (x > h || x < 1 || y > w || y < 1) return;
	if (m[x][y] == '.') return;
	m[x][y] = '.';
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
	dfs(x + 1, y + 1);
	dfs(x - 1, y - 1);
	dfs(x + 1, y - 1);
	dfs(x - 1, y + 1);
}
int main() {
	cin >> h >> w;
	char temp;
	int cnt = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> m[i][j];
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (m[i][j] == 'W') {
				cnt++;
				dfs(i, j);
			}
		}
	}
	cout << cnt;
	return 0;
}
