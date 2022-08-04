#include <iostream>
#include <cstdio>
using namespace std;

// ��������Թ����⣬�����ƺ����Թ���DFS�������֣�һ�������ܲ����ߵ��յ㣬һ�������ж������߷�
// ���ڵ�һ�����⣬�ƺ�����Ҫд�����ݣ����ڶ����������Ҫ�û���ö�������߷��� 

const int N = 110;
char graph[N][N];
int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// ��̫��̳����д�������԰�flag����˸����ò��� 
void dfs(int sx, int sy, int ex, int ey, int n, bool& flag) {
	if (sx == ex && sy == ey) {
		flag = true;
		return;	
	}
	if (sx < 0 || sx >= n || sy < 0 || sy >= n) return;
	if (graph[sx][sy] != '.') return;
	// ��Ǳ����ʣ����������Բ�Ū���������飬Ҳ����ÿ�ζ�ȥ��ʼ�� 
	graph[sx][sy] = '#';
	for (int i = 0; i < 4; i++) {
		dfs(sx + move[i][0], sy + move[i][1], ex, ey, n, flag);
	}
}
int main() {
	int k;
	scanf("%d", &k);
	while (k--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// scanfʵ�ڲ�֪����ô�ã����ܣ� 
				cin >> graph[i][j];
			}
		}
		int sx, sy, ex, ey;
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		// sx -= 1, sy -= 1, ex -= 1, ey -= 1;
		if (graph[ex][ey] == '#') {
			printf("NO\n");
			continue;
		}
		bool flag = false;
		dfs(sx, sy, ex, ey, n, flag);
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
/*
2
3
.##
..#
#..
0 0 2 2
5
.....
###.#
..#..
###..
...#.
0 0 4 0
*/
