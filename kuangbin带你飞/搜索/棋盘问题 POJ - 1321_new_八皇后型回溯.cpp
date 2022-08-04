#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 硬套八皇后的思想做不出来w，这个题可以不用记录那一行被用了，只要我们
// 每次都直接往下走就行了，也就是只用记录那一列被用了，那么代码改成两层
// 循环就行了... 
// 调到心态爆炸，最后发现是题目没看明白.. 

const int N = 10;
int n, m;
long long cnt;
bool graph[N][N];
bool visited[N];
void dfs(int y, int m) {
	if (!m) {
		cnt++;
		return;
	}
	// 直接从下一行开始... 
	for (int i = y + 1; i <= n; i++) {
		// 枚举这一行的这一列的所有放法 
		for (int j = 1; j <= n; j++) {
			// 如果当前格子能放棋子并且这一列没有放棋子，就继续往下走.. 
			if (graph[i][j] && !visited[j]) {
				visited[j] = true;
				dfs(i, m - 1);
				visited[j] = false;
			} 
		}
	}
}
int main() {
	char temp;
	while (true) {
		scanf("%d%d", &n, &m);
		if (n == -1 && m == -1) break;
		memset(visited, 0, sizeof visited);
		memset(graph, 0, sizeof graph);
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> temp;
				// 题目里#才是可以放棋子的地方... 
				graph[i][j] = (temp == '#');
			}
		}
		// 回溯里直接从第一行开始，所以这里起点得设置为第0行.. 
		dfs(0, m);
		printf("%lld\n", cnt);
	}
	return 0;
}
