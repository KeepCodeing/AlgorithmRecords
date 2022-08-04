#include <iostream>
#include <cstdio>
using namespace std;

// ���ѣ�����Ҫ������ͨ�飬ʵ����ֻ�ö�ÿ���㶼����DFS�������ƻ�����۽ۣ����Ӿͱ������������� 
// ����Ҫ�ڱ������¼��ǰ�ַ�����Ϊ��������ͨ��... 

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
		// ���д��ط�WA�ˣ�����ò�ƾ�һ�����Ե㣿 
		if (n && m) printf("%d\n", res);
	} while (n && m);
	return 0;
}
