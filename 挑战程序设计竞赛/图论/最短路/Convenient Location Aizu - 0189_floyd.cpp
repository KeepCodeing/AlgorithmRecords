#include <iostream>
#include <cstdio>
using namespace std;

// floyd模板题，因为数据很小，而且题目要求的是从哪个点到其它点的最短路之和最小，所以
// 可以直接用floyd算遍全源最短路，然后枚举哪个点的最短路之和最小即可... 

const int N = 15, INF = 0x3fffffff;
int graph[N][N];
// 初始化邻接矩阵，这个题没给有多少个点，所以只能一次性把整个图初始了.. 
void init_graph() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}
}
int main() {
	int n;
	int ut, vt, wt;
	while (true) {
		// 这里n是边数，顶点最多十个... 
		scanf("%d", &n);
		if (!n) break;
		init_graph();
		// 建立邻接矩阵图，注意是双向边 
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &ut, &vt, &wt);
			// 不知道存不存在重边，为了保险还是判断下好了.. 
			graph[ut][vt] = min(graph[ut][vt], wt);
			graph[vt][ut] = min(graph[vt][ut], wt);
		}
		// floyd板子，i是中间点，j是当前点，k是j的一条边上的点
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
				}
			}
		} 
		int idx, mPath = INF, totPath;
		bool flag;
		for (int i = 0; i < N; i++) {
			totPath = 0, flag = false;
			for (int j = 0; j < N; j++) {
				// 算最短路 
				// 没有通路或者自己到自己就跳过，因为可能有的路径根本就没有点，所以得这个判断 
				if (graph[i][j] == INF || i == j) continue; 
				// 因为这里直接计算了整个图的最短路，但是输入可能没有那么多点，所有这里得判断下当前路径是否有效 
				flag = true; 
				// 计算i这个点能到的所有点的边权之和 
				totPath += graph[i][j]; 
			}
			// 更新结果，题目要求记录最先出现的最短路 
			if (mPath > totPath && flag) idx = i, mPath = totPath;
		}
		printf("%d %d\n", idx, mPath);
	}
	return 0;
}
