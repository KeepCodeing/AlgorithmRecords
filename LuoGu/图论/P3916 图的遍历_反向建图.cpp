#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 自己果然还是太naivew，这个题以前看洛谷的教程时听过了，不过那时候没想着写正解，就写了个暴力...
// 正解是反向建图，然后从编号大的点开始DFS，所有当前编号能到的点，也就是能到当前点的点...说起来最短路里反向建图跑多起点单终点的题倒是挺多，
// 不过这个题却想不起来..果然没有模型是难以解决的呢... 

const int N = 1e5 + 10;
int head[N], e[N], ex[N], idx = 0;
int dist[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
void dfs(int ut, int pos) {
	// 注意当ut == pos时，这种情况就是这个点能到的最大点就是它自己，按照递减顺序来看这里可以直接这样写，
	// 下面那个赋值就可以直接去掉了... 
	dist[ut] = pos;
	for (int i = head[ut]; i != -1; i = ex[i]) {
		int vt = e[i];
		// 用顶点编号表示访问否 
		if (dist[vt] != -1) continue;
//		dist[vt] = pos;
		dfs(vt, pos);
	}
}
int main() {
	memset(head, -1, sizeof head);
	memset(dist, -1, sizeof dist);
	int n, m, ut, vt;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &ut, &vt);
		// 单向边反向建图 
		add(vt, ut);
	}
	for (int i = n; i >= 1; i--) {
		if (dist[i] != -1) continue;
		dfs(i, i);
	}
	for (int i = 1; i <= n; i++) printf("%d ", dist[i]);
	return 0;
}
