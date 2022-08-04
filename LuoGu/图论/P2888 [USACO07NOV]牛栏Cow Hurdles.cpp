#include <iostream>
using namespace std;

// n的范围很小，尝试Floyd求全源最短路，而且这里要求很多次最短路 
// 如果每次都新求一个估计会炸 

// floyd因为太简单所以还会考点别的 

const int INF = 0x3FFFFFFF;
int n, m, t;
int graph[310][310];
int main() {
	cin >> n >> m >> t;
	// 初始化邻接矩阵，邻接表不用，因为它不用装去不了的点 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) graph[i][j] = INF;
			else graph[i][j] = 0;
		}
	}
	int u, v, w;
	while(m--) {
		cin >> u >> v >> w;
		// 题目细节说是有向图
		graph[u][v] = w;
		// graph[v][u] = w;
	} 
	// Floyd
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				// 再用佛洛依德进行新状态转移时，因为是以i作为中间点，所以牛跨过的最高高度是
				//max(d[i][j],d[j][k])，但是在j->k的整条路径上，跨过的最高高度应该最小，所以
				// 最后要取一个MIN，即graph[j][k] = min(max(graph[j][i], graph[i][k]), graph[j][k]);
				graph[j][k] = min(max(graph[j][i], graph[i][k]), graph[j][k]);
			}
		}
	}
	int x, y;
	while(t--) {
		cin >> x >> y;
		cout << (graph[x][y] != INF ? graph[x][y] : -1) << endl;
	}
	return 0;
}
