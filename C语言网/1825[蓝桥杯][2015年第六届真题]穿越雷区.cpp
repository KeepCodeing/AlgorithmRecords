#include <iostream>
using namespace std;
char graph[105][105];
bool visited[105][105];
int sx, sy, ex, ey;
int n;
int minStep = 0x3FFFFFFF;
void dfs(int x, int y, int cnt, char pre) {
	if (cnt >= minStep) return;
	if (x < 0 || x >= n || y < 0 || y >= n) return;
	if (visited[x][y]) return;
	// �ж��ǲ��Ǻ���һ���ַ���ͬ���� 
	if (graph[x][y] != pre) {
		visited[x][y] = true;
		if (x == ex && y == ey) {
			minStep = min(minStep, cnt);
			return;
		}
		dfs(x + 1, y, cnt + 1, graph[x][y]);
		dfs(x - 1, y, cnt + 1, graph[x][y]);
		dfs(x, y + 1, cnt + 1, graph[x][y]);
		dfs(x, y - 1, cnt + 1, graph[x][y]);
		visited[x][y] = false;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'A') sx = i, sy = j;
			if (graph[i][j] == 'B') ex = i, ey = j;
		}
	}
	dfs(sx, sy, 0, 'T');
	if (minStep != 0x3FFFFFFF) {
		// ���ܰ������յ�ľ���Ҳ�ӽ�ȥ�ˣ����������ȥ2 
		cout << minStep - 2;
	} else {
		cout << -1;
	}
	return 0;
}
/*
5
A + - + -
- + - - +
- + + + -
+ - + - +
B + - + -
*/
