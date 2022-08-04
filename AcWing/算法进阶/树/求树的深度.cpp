#include <iostream>
using namespace std;

// 树的深度也就是当前节点在树里的层次，当前节点的层次一定是由父节点的层次递推而来 

// 关于BFS的写法：BFS可以用两种写法，一种是每个节点入队不从父节点递推，用一个变量
// 去记录深度，然后用pair之类的元组记录它的深度，另一种就是这样的将当前节点的所有子节点入队，用数组记录... 

const int N = 1e5 + 10, M = N * 2;
bool vis[N];
int dep[M];
int head[N], e[M], ex[M], idx = 0;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void dfs(int x) {
	for (int i = head[x]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (vis[vt]) continue;
		dfs(vt);
		// 从父节点的层次来推导当前节点的层次 
		dep[vt] = dep[x] + 1;	
	}
}
int main() {
	
	return 0;
} 
