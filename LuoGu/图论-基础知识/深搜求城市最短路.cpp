#include <iostream>
using namespace std;
int n, minDis = 114514;
int city[1000][1000], visited[1000];
// 当前位置和已走距离 
void dfs(int cur, int dis) {
	// 剪枝，如果当前已走距离已经大于了最小距离，就不用继续走了 
	if (dis >= minDis) return;
	// 如果到达了目的地，就更新最短距离 
	if (cur == n) {
		minDis = min(dis, minDis);
		return;
	}
	// 对每个节点进行遍历 
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && city[cur][i] != -1) {
			visited[i] = 1;
			// 继续走并且更新距离 
			dfs(i, dis + city[cur][i]);
			visited[i] = 0;
		}
	}
	return;
}
int main() {
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) city[i][j] = -1;
			else city[i][j] = 0;
		}
	}
	int x, y, w;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> w;
		// 因为是有向图，所以一个点只能单方向的到另一个点
		city[x][y] = w; 
	}
	visited[1] = 1;
	dfs(1, 0);
	cout << minDis << endl;
	return 0;
}
/*
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
*/
