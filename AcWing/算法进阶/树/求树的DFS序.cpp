#include <iostream>
using namespace std;

// DFS序：即在回溯前后对当前节点的访问顺序进行记录。
// DFS序的特点是:每个节点x的编号在序列中恰好出现两次。设这两次出现的位置为L[x]与 R[x]，
// 那么闭区间[L[x],R[x]]就是以x为根的子树的DFS序。这使我们在很多与树相关的问题中，可以
// 通过DFS序把子树统计转化为序列上的区间统计。

const int N = 1e5 + 10, M = N * 2;
bool vis[N];
int s[M], now = 0;
int head[N], e[M], ex[M], idx = 0;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void dfs(int x) {
	vis[x] = true;
	// 相对于普通DFS遍历求DFS序就是在回溯前后加了一行这个，即标记当前元素是第几个出现的... 
	s[now++] = x;
	for (int i = head[x]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (vis[vt]) continue;
		dfs(vt);
	}
	s[now++] = x;
}
int main() {
	
	return 0;
} 
