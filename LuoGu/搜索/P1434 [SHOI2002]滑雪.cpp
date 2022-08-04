#include <iostream>
using namespace std;
const int N = 110;
int graph[N][N];
bool visited[N][N];
int n, m;
int sx, sy;
int cnt = 0;
bool checker(int x, int y) {
	return x < 1 || x > n || y < 1 || y > m || visited[x][y];
}
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int x, int y, int mx, int path) {
	//cout << mx << endl;
	// if (path > cnt) return;
	if (checker(x, y)) return;
	visited[x][y] = true;
	int nx, ny, mNum = 0x3fffffff;
	for (int i = 0; i < 4; i++) {
		int tx = x + move[i][0], ty = y + move[i][1];
		if (checker(tx, ty)) continue;
		if (mx - graph[tx][ty] < mNum) {
			mNum = mx - graph[tx][ty];
			nx = tx, ny = ty;
		}
	}
	//cout << nx << ' ' << ny << endl;
	cnt++;
	if (checker(nx, ny)) return;
	dfs(nx, ny, graph[nx][ny], path + 1);

}
int main() {
	cin >> n >> m;
	int maxNum = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
			if (maxNum < graph[i][j]) maxNum = graph[i][j], sx = i, sy = j;
		}
	}
	dfs(sx, sy, maxNum, 0);
	cout << cnt;
	return 0;
} 
