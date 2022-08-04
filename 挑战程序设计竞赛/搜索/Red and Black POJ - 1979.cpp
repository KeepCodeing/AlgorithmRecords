#include <iostream>
#include <cstdio>
using namespace std;

// ����Ҳ��������⣬������Ȼ����ϰ���������ˣ����Ǳ���... 

int n, m;
const int N = 30;
char graph[N][N];
int cnt = 0;
void dfs(int sx, int sy) {
	if (sx < 1 || sx > n || sy < 1 || sy > m) return;
	if (graph[sx][sy] != '.') return;
	graph[sx][sy] = '#';
	cnt++;
	dfs(sx + 1, sy);
	dfs(sx, sy + 1);
	dfs(sx - 1, sy);
	dfs(sx, sy - 1);
}
int main() {
	int sx, sy;
	do {
		cnt = 0;
		// ����˳�����ͨ���Ƿ������� 
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> graph[i][j];
				if (graph[i][j] == '@') sx = i, sy = j, graph[i][j] = '.';
			}
		}
		dfs(sx, sy);
		if (n && m) printf("%d\n", cnt);
	} while (n && m);
	return 0;
}
