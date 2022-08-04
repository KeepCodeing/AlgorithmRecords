#include <iostream>
#include <cstdio>
using namespace std;

// 经典的走迷宫问题，另外似乎走迷宫在DFS里有两种，一种是问能不能走到终点，一种是问有多少种走法
// 对于第一种问题，似乎不需要写个回溯，而第二种问题就需要用回溯枚举所有走法了 

const int N = 110;
char graph[N][N];
int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// 不太会教程里的写法，所以把flag搞成了个引用参数 
void dfs(int sx, int sy, int ex, int ey, int n, bool& flag) {
	if (sx == ex && sy == ey) {
		flag = true;
		return;	
	}
	if (sx < 0 || sx >= n || sy < 0 || sy >= n) return;
	if (graph[sx][sy] != '.') return;
	// 标记被访问，这样还可以不弄个访问数组，也不用每次都去初始化 
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
				// scanf实在不知道怎么用（无能） 
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
