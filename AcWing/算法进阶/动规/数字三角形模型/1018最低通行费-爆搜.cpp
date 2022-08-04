#include <iostream>
using namespace std;

// 爆搜版：当成走迷宫问题，加一个超时剪枝，到终点更新最小花费 
// 两个错误：没加上终点的花费，还有就是标记访问直接改了地图，可能
// 地图上某个要重复用的情况不能这样标记

// 这个爆搜版也可以改成记忆化搜索，但是其不会www 

const int N = 110;
int graph[N][N];
bool visited[N][N];
int n;
int ans = 0x3fffffff;
void dfs(int sx, int sy, int t, int money) {
	if (t < 0) return;
	if (sx > n || sx < 1 || sy > n || sy < 1) return;
	if (visited[sx][sy]) return;
	if (sx == n && sy == n) {
		//cout << money << endl;
		// 忘了加上终点的钱数，其实这样看来起点和终点的钱是必须交的 
		ans = min(ans, money + graph[sx][sy]);
		return;
	}
	// 原本这里是通过改地图的方式来标记访问的，但是不知道为什么
	// 出现了负的非法答案 
	visited[sx][sy] = true;
	dfs(sx + 1, sy, t - 1, money + graph[sx][sy]);
	dfs(sx - 1, sy, t - 1, money + graph[sx][sy]);
	dfs(sx, sy + 1, t - 1, money + graph[sx][sy]);
	dfs(sx, sy - 1, t - 1, money + graph[sx][sy]);
	visited[sx][sy] = false;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}
	dfs(1, 1, 2 * n - 1, 0);
	cout << ans << endl;
	return 0;
}
