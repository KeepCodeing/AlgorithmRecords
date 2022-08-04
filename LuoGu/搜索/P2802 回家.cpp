#include <iostream>
using namespace std;

// 深搜，外加一些判断 
int n, m;
int graph[15][15];
int minTime = 0x3FFFFFFF;
void dfs(int x, int y, int step, int life) {
	// 剪枝，虽然数据比较小 
	if (step >= minTime || life <= 0) return;
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (!graph[x][y]) return;
	cout << life << endl;
	if (graph[x][y] == 3/* && life > 0*/) {
		
		minTime = min(minTime, step);
		return;
	}
	int temp = graph[x][y];
	// 还活着才能回血 
	if (temp == 4 /*&& life > 0*/) life = 6;
	graph[x][y] = 0;
	dfs(x - 1, y, step + 1, life - 1);
	dfs(x + 1, y, step + 1, life - 1);
	dfs(x, y - 1, step + 1, life - 1);
	dfs(x, y + 1, step + 1, life - 1);
	graph[x][y] = temp;
}
int main() {
	cin >> n >> m;
	int start_x, start_y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 2) start_x = i, start_y = j;
		}
	}
	dfs(start_x, start_y, 0, 6);
	cout << (minTime != 0x3FFFFFFF ? minTime : -1);
	return 0;
	/*
	7 6
	2 0 0 0 0 0
	1 0 0 0 0 0
	1 1 4 0 0 0
	1 0 0 0 0 0
	1 1 1 1 1 3
	4 0 1 0 4 0
	0 0 4 0 0 0
	*/
}
