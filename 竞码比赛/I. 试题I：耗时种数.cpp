#include <iostream>
#include <set>
using namespace std;

// 两个问题，而且是以前从未碰到的 

const int N = 1500, INF = 0x3fffffff;
int graph[N][N];
set<int > res;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}
	int u, v, w;
	while (q--) {
		cin >> u >> v >> w;
		// 首先，u，v都是从0开始的，而其设置的顶点编号是从1开始的 
		u++, v++;
		// 其次，顶点间存在重边，所以不能每次读入边权时都无脑更新，
		// 而是判断下新的边权是否更小 
		graph[u][v] = min(graph[u][v], w);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				if (graph[i][j] != INF) res.insert(graph[i][j]); 
			}
		}
	}
	cout << res.size();
	return 0;
}
