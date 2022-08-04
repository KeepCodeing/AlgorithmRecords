#include <iostream>
using namespace std;

// 树的时间戳：其实就是每个节点出现的顺序... 

const int N = 1e5 + 10, M = N * 2;
bool vis[N];
int dfn[M], now = 0;
int head[N], e[M], ex[M], idx = 0;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void dfs(int x) {
	vis[x] = true;
	// 在普通DFS的基础上记录的当前节点是第几个在DFS的过程中出现的... 
	dfn[x] = now++;
	for (int i = head[x]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (vis[vt]) continue;
		dfs(vt);
	}
}
int main() {
	
	return 0;
} 
