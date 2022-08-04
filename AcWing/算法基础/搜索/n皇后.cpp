#include <iostream>
#include <cstdio>
using namespace std;

// 八 王 子

// 比较难想的是怎么判断对角线和水平位置的皇后是否放过
// 画图可以看出其中一个对角线的截距为b = x + y，另一条
// 对角线的截距为b = y - x，但是这样下标会出界，所以
// 用偏移量（地图大小）减去截距即b = n - (y - x) = n + x - y  
 
const int N = 13;

char graph[N][N];
bool col[N], dg[N], udg[N];
int n;
void dfs(int y) {
	if (y == n) {
		// 输出技巧：用puts直接将char[][]当成字符串输出 
		for (int i = 0; i < n; i++) puts(graph[i]);
		puts("");
		return;	
	}
	for (int i = 0; i < n; i++) {
		if (!col[i] && !dg[y + i] && !udg[n - y + i]) {
			// 更新访问状态，这里的i就代表的横坐标x 
			col[i] = dg[i + y] = udg[n + i - y] = true;
			graph[y][i] = 'Q';
			dfs(y + 1);
			col[i] = dg[y + i] = udg[n - y + i] = false;
			graph[y][i] = '.';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = '.';
		}
	}
	dfs(0);
	return 0;
}
