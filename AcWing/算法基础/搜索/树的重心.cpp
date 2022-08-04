#include <iostream>
using namespace std;

// 首先分析下题目，题目的意思就是说去掉任意节点，然后对比
// 所有连通块中最多节点的节点数，答案即是最少的节点数。

// 所以我们要记录的就是每次去掉一个点，剩下的连通块中
// 节点数最多的点，然后对比出最小的那个值即可 

const int N = 100010, M = N * 2;

int head[N], e[M], ex[M], idx = 0;
bool visited[N];
void add(int k, int val) {
	e[idx] = val;
	ex[idx] = head[k];
	head[k] = idx;
	idx++;
}
int ans = N;
int n;
// 记录cur有多少个子树 
int dfs(int cur) {
	visited[cur] = true;
	// tot表示当前子树数量，res表示最大的子树数量 
	int tot = 1, res = 0;
	for (int i = head[cur]; i != -1; i = ex[i]) {
		int j = e[i];
		if (!visited[j]) {
			int s = dfs(j);
			// 对比子树数量，存放最大子树数量 
			res = max(s, res);
			// 统计当前子树有多少个节点 
			tot += s;
		}
	}
	// 用顶点数减去当前子树的节点数即可得到除了当前节点以外的
	// 连通图的节点数之和 
	res = max(res, n - tot);
	// 更新答案 
	ans = min(ans, res);
	return tot;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	// 一共有n - 1条边 
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		// 题目给出的是无向边 
		add(a, b), add(b, a);
	} 
	return 0;
}
/*
输入样例
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6

输出样例
4
*/
