#include <iostream>
using namespace std;
const int infinite = 114514;
int sumNum = 0, n;
int g[1000][1000], visited[1000];
void dfs(int cur) {
	cout << cur << endl;
	// 统计有哪些节点被访问了 
	sumNum++;
	// 如果每个节点都被访问了就结束遍历 
	if (sumNum == n) return;
	// 对每个节点进行遍历 
	for (int i = 1; i <= n; i++) {
		// 如果当前节点到另一个节点有路且该节点未被访问 
		if (g[cur][i] == 1 && !visited[i]) {
			visited[i] = infinite;
			dfs(i);
		}
	}
	return;
}
int main() {
	int m;
	cin >> m >> n;
	// 初始化图 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				// 自己到自己的距离为0 
				g[i][j] = 0;
			} else {
				// 否则先初始化为无穷 
				g[i][j] = infinite;	
			}
		}
	}
	int x, y;
	// 读入边 
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		// 标记有通路 
		g[x][y] = 1;
		// 因为是无向图，所以x可以到y，y也可以到x
		g[y][x] = 1;
	}
	visited[1] = 1;
	dfs(1);
	return 0;
}
/*
5 5
1 2
1 3
1 5
2 4
3 5
*/
