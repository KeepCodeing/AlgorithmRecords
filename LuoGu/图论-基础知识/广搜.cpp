#include <iostream>
#include <queue>
using namespace std;
int n;
int g[1000][1000], visited[1000];
queue<int > que;
int main() {
	int m;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) g[i][j] = 0;
			else g[i][j] = -1;
		}
	}
	int x, y;
	for (int i =1; i <= m; i++) {
		cin >> x >> y;
		g[x][y] = 1;
		g[y][x] = 1;
	}
	// 入队第一个元素 
	visited[1] = 1;
	que.push(1); 
	int cur;
	while (!que.empty()) {
		// 取出当前元素 
		cur = que.front();
		que.pop();
		cout << cur << endl;
		// 对每个节点进行遍历 
		for (int i = 1; i <= n; i++) {
			// 如果当前节点没有被访问过且有通路 
			if (!visited[i] && g[cur][i] != -1) {
				// 入队该节点，并对其进行标记 
				que.push(i);
				visited[i] = 1; 
			}
		}
	}
	return 0;
}
