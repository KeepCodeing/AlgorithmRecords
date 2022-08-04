#include <iostream>
#include <cstdio>
using namespace std;

// 爆搜，但是要求多个连通块，实际上只用对每个点都进行DFS，如果是苹果，蜜桔，梨子就遍历，否则跳过 
// 另外要在爆搜里记录当前字符，因为有三种连通块... 

const int N = 110;
char graph[N][N];
int n, m;
int res = 0;
void dfs(int sx, int sy, char c) {
	if (sx < 1 || sx > n || sy < 1 || sy > m) return;
	if (graph[sx][sy] != c) return;
	graph[sx][sy] = '?';
	dfs(sx + 1, sy, c);
	dfs(sx, sy + 1, c);
	dfs(sx, sy - 1, c);
	dfs(sx - 1, sy, c);
}
int main() {
	do {
		res = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++) 
				cin >> graph[i][j];
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++) 
				if (graph[i][j] != '?') dfs(i, j, graph[i][j]), res++;
		// 输出写错地方WA了，不过貌似就一个测试点？ 
		if (n && m) printf("%d\n", res);
	} while (n && m);
	return 0;
}
