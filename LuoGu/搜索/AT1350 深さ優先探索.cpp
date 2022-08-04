#include <iostream>
using namespace std;

// AtCoder上好像有很多水题的样子（安心感），线代前的水题w （摸完线代和迫真作业才开始..）
// 似乎BFS写了太多了，看到这个题第一眼还是想写BFS，然而考虑到代码量以及功能还是用DFS罢了 

const int N = 510;
char graph[N][N];
int sx, sy, ex, ey;
int n, m;
bool flag = false;
void dfs(int sx, int sy) {
	if (sx > n || sx < 1 || sy > m || sy < 1) return;
	if (graph[sx][sy] == '#') return;
	if (sx == ex && sy == ey) {
		flag = true;
		return;
	}
	// 只是找能不能到终点无需回溯，要统计走法数才需要回溯，原因是
	// 不管是DFS还是BFS都可以做到一次走完整个地图，所以只用判断有没有
	// 点能到终点就行 
	graph[sx][sy] = '#';
	dfs(sx + 1, sy);
	dfs(sx - 1, sy);
	dfs(sx, sy + 1);
	dfs(sx, sy - 1);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 's') sx = i, sy = j;
			if (graph[i][j] == 'g') ex = i, ey = j;
		}
	}
	dfs(sx, sy);
	if (flag) cout << "Yes";
	else cout << "No";
	cout << endl;
	return 0;
} 
