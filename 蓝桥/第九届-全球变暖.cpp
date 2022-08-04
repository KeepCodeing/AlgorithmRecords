#include <iostream>
using namespace std;

// 主要是判断上下点是否相同，和蓝桥杯一题很类似
// 坑输入，应该把输入的数据看成字符，如果是数字就会连在一起.. 
// 草（辱骂），题目没看懂写成蓝桥杯那个题了 

int m, n;
char graph[101][101];
bool visited[101][101];
int cnt = 0;
void dfs(int x, int y) {
	if (x < 0 || x > n || y < 0 || y > n) return;
	if (!visited[x][y]) {
		int a, b, c, d;
		a = x + 1, b = x - 1, c = y + 1, d = y - 1;
		if (a < n && b >= 0 && c < n && d >= 0) {
			// cout << graph[x][y] << endl;
			if (graph[x][y] == graph[x][d] && graph[x][y] == graph[x][c] && graph[x][y] == graph[a][y] && graph[x][y] == graph[b][y]  && graph[x][y] != '.') {
				cnt++;
			}
		}
		visited[x][y] = true;
		dfs(x + 1, y);
		dfs(x - 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
		// visited[x][y] = false;
	}
}
int main() {
	// cin >> m >> n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	dfs(0, 0);
	cout << cnt;
	return 0;
}
