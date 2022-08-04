#include <iostream>
#define endl '\n'
using namespace std;
const int N = 25;
char graph[N][N];
bool vx[N], vy[N];
int n, m;
void dfs(int x, int y) {
	// 炸过的点（访问到了）就变成无法爆炸的状态 
	graph[x][y] = '0';
	// 如果这一行没有访问过，就遍历这一行的所有点，找到
	// 其中一个炸弹，然后从它开始向列扩展 
	if (!vx[x]) {
		vx[x] = true;
		for (int i = 0; i < m; i++) {
			if (graph[x][i] == '1') {
				dfs(x, i);
			}
		}
	}
	// 同理，从行扩展 
	if (!vy[y]) {
		vy[y] = true;
		for (int i = 0; i < n; i++) {
			if (graph[i][y] == '1') {
				dfs(i, y);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	int ans = 0;
	// 类似连通块的操作，这里考虑的不是引爆那个炸弹能连锁爆炸
	// 最少几个炸弹，而是判断引爆那个炸弹形成的连通块最少 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == '1') {
				ans++;
				dfs(i, j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
