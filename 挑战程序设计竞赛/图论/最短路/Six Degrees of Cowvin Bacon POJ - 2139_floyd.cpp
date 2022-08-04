#include <iostream>
#include <cstdio>
using namespace std;
const int N = 310, INF = 0x3fffffff;
int graph[N][N];
int pos[N];
void init_graph(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}
}
int main() {
	int n, m, cnt;
	scanf("%d%d", &n, &m);
	init_graph(n);
	// 建图 
	while (m--) {
		scanf("%d", &cnt);
		for (int i = 1; i <= cnt; i++) scanf("%d", &pos[i]);
		// 连边 
		for (int i = 1; i <= cnt; i++) {
			for (int j = i + 1; j <= cnt; j++) {
				// 双向边，枚举所有可以连边的点，距离都为1，题目给的团体其实就是说那些点有边，而
				// 不同团体距离递增指的就是两个没有直接相连的点的边距为1+1+..+1.. 
				graph[pos[i]][pos[j]] = 1;
				graph[pos[j]][pos[i]] = 1;
			}
		}
	}

	// floyd板子，这里n就是所有顶点的数量，不一定每个点都有边.. 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	} 
	// 统计答案，注意这里求平均值要直接用int取整，否则可能出错
	int ans = INF;
	for (int i = 1; i <= n; i++) {
		int tot = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j && graph[i][j] != INF) tot += graph[i][j];
		}
		// 这里应该先乘上100再除去点数，因为距离都很小，如果用1/100就会得到0 
		ans = min(ans, (tot * 100 / (n - 1)));
	} 
	printf("%d", ans);
	return 0;
}
