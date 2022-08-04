#include <iostream>
#include <cstdio>
using namespace std;

// 啊这...，题目没看清，原来是个求连通块的题（半恼），0不是细胞，只有1~9才是细胞 
// 奇妙，用输入字符的方式初始化地图答案不正确，不过也算学到了一次只读一位数字的里技 

int m, n; 
int graph[101][101];
void dfs(int x, int y) {
	if (x > m || x < 0 || y > n || y < 0) return;
	if (graph[x][y]) {
		graph[x][y] = 0;
		dfs(x + 1, y);
		dfs(x - 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
	}	
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
