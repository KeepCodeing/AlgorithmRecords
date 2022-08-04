#include <iostream>
using namespace std;

// 这个算法就是借用另一个顶点来使路径更短，但是效率很低，只有O(n^3)，不过好在容易
// 实现 ，但是Floyd算法不能用来求“有负权边的图，也就是类似1->2->3->1->2->3...这种
// 相互连通的图 

int graph[1000][1000]; 

int main() {
	// 初始化图 
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) graph[i][j] = -1;
			else graph[i][j] = 0;
		}
	} 
	int x, y, w;
	while(m--) {
		cin >> x >> y >> w;
		graph[x][y] = w;
	}
	// Floyd核心代码：三行循环
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// 如果中间点k到j或者i到k合法，判断直接从i到j是否大于借用中间点k，如果大于，更
				// 更新最短距离 
				// 这里还可以简化，如果标记不能到达用的不是-1而是inf，可以用min()来代替这个 
				// if
				if (graph[i][k] != -1 && graph[k][j] != -1 && graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	} 
	return 0;
}
