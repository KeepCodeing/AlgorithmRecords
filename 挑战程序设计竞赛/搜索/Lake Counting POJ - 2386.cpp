#include <iostream>
#include <cstdio>
using namespace std;

// 其实在洛谷上做过类似的题（原题w），只不过那时候对dfs的理解还是不深，甚至没搞明白为什么不回溯w
// 这里用DFS再搞一遍... 

const int N = 110;
int n, m;
char graph[N][N];
void dfs(int sx, int sy) {
	if (sx < 1 || sx > n || sy < 1 || sy > m) return;
	if (graph[sx][sy] != 'W') return;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (i != 0 || j != 0) graph[sx][sy] = '.', dfs(sx + i, sy + j);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (graph[i][j] == 'W') dfs(i, j), res++;
		}
	}
	printf("%d", res);
	return 0;
}
