#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*
概念
树的重心也叫树的质心。对于一棵树n个节点的无根树，找到一个点，使得把树变成以该点为根的有根树时，最大子树的结
点数最小。换句话说，删除这个点后最大连通块（一定是树）的结点数最小。

性质
1.树中所有点到某个点的距离和中，到重心的距离和是最小的（实际应用中经常用到此性质）。
2.把两棵树通过一条边相连，新的树的重心在原来两棵树重心的连线上。
3.一棵树添加或者删除一个节点，树的重心最多只移动一条边的位置。
4.一棵树最多有两个重心，且相邻。
*/

const int N = 50000 + 10, M = N * 2, INF = 0x3fffffff;
int head[N], e[M], ex[M], idx = 0;
bool vis[N];
int sz[N];
// 重心的编号，最大子树的数量 
int ans = 0, maxn = INF;
int n, ut, vt;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void dfs(int ut, int nx) {
	sz[ut] = 1;
	// 最大子树的节点数 
	int mx = 0;
	for (int i = head[ut]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (vt == nx) continue;
		dfs(vt, ut);
		sz[ut] += sz[vt];
		mx = max(mx, sz[vt]);
	}
	mx = max(mx, n - sz[ut]);
//	if (mx < maxn) {
//		maxn = mx;
//		ans = ut;
//	}
	// 用来保证字典序最小 
	if (mx < maxn || (mx == maxn && ut < ans)) {
		maxn = mx;
		ans = ut;
	}
}
int main() {
	memset(head, -1, sizeof head);
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) scanf("%d%d", &ut, &vt), add(ut, vt), add(vt, ut);
	dfs(1, 0);
	cout << ans;
	return 0;
}
