#include <iostream>
#include <vector>
using namespace std;
int graph[10001][10001];
// vector<int > graph[100001];
bool visited[10001];
int m, n;
int tot = 0;
vector<int > res;
void dfs(int cur) {
	res.push_back(cur); 
	if (tot == n) return;
	for (int i = 1; i <= n; i++) {
		if (graph[cur][i] != -1 && !visited[i]) {
			visited[i] = true;
			tot++;
			dfs(i);
		}
	}
}
// 暴力法，枚举每个点并寻找其最大值，只能应付数据较小的情况
// 草，交了次是MLE，因为其数组没办法开那么大 

// 正确是思路应该是反向建图，从后往前开始搜，如果当前节点能访问到它之前的任意节点
// 那么被访问的节点的最大距离就是当前节点 

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) graph[i][j] = -1;
			else graph[i][j]= 0;
		}
	}
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		graph[x][y] = 1;
	}
	int maxLen;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) visited[k] = false;
		visited[i] = true;
		dfs(i);
		maxLen = -1;
		for (int j = 0; j < res.size(); j++) {
			maxLen = max(res[j], maxLen);
		}
		cout << maxLen << ' ';
		res.clear();
	}
	return 0;
}
