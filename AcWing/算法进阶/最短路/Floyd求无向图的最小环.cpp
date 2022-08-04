#include <iostream>
#define endl '\n'
using namespace std;

// 所谓最小环就是i点至少经过一个点并回到它自身的路径的距离最短，对于无向图只用考虑i直接
// 相连的点k到j的距离，因为有对称性所以只用枚举i ~ k, i + 1 ~ k的边（此处不能枚举到k）  

// 注意这里INF的赋值，这里至少会有三条边相加所以不能用普通的0x3f 
const int N = 1e2 + 10, INF = 99999999;
int graph[N][N], dist[N][N];
int main() {
	int n, m, ut, vt, wt, ans = INF;
	while (cin >> n >> m) {
		// 初始化 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) graph[i][j] = 1;
				else graph[i][j] = INF;
			}
		}
		while (m--) {
			cin >> ut >> vt >> wt;
			// 去重边 
			graph[ut][vt] = graph[vt][ut] = dist[ut][vt] = dist[vt][ut] = min(graph[ut][vt], wt);
		}
		
		for (int k = 1; k <= n; k++) {
			// 枚举i ~ k, i + 1 ~ k的边，最小环的长度就是i到j的距离加上图中通过k的距离... 
			for (int i = 1; i < k; i++) {
				for (int j = i + 1; j < k; j++) {
					ans = min(ans, dist[i][j] + graph[i][k] + graph[k][j]);
				}
			}
			// 更新最短边的距离 
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					// 是直接从i到j短还是通过k更短 
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		if (ans == INF) cout << "It's impossible." << endl;
		else cout << ans << endl;	
	}
	return 0;
}

/*
Sample Input
3 3
1 2 1
2 3 1
1 3 1
3 3
1 2 1
1 2 3
2 3 1
 
Sample Output
3
It's impossible.
*/ 
