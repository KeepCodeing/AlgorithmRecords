#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 《挑战》刷不动了（实际上是有点不想刷w），来试试这个题单...
// 这个题本质上就是个八皇后问题...只不过少了判断对角线的要求，那么可以尝试将每个棋子放在每一列上，然后判断是否被访问就行了 

const int N = 10;
int n, m, cnt;
char graph[N][N];
bool visited[N][N];
bool col[N], line[N];
void dfs(int y, int m) {
	if (y >= n) return;
	if (m <= 0) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (graph[y][i] != '#' && !visited[y][i]) {
			if (!col[i] && !line[y + i]) {
				col[i] = line[y + i] = visited[y][i] = true;
				dfs(y + 1, m - 1);
				col[i] = line[y + i] = visited[y][i] = false;
			}
		}
	}
}
int main() {
	while (true) {
		scanf("%d%d", &n, &m);
		if (n == -1 && m == -1) break;
		cnt = 0;
		memset(col, 0, sizeof col);
		memset(line, 0, sizeof line);
		memset(visited, 0, sizeof visited);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> graph[i][j];
			}
		}
		dfs(0, m);
		printf("%d\n", cnt);
	}
	return 0;
}
