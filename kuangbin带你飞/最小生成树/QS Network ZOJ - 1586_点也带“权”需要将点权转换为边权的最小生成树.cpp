#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 这个题给了个“点权”，就是说两个点相连边权其实是两点之间的边权+两个点的花费，这样的话不妨在连边的过程中
// 将“点权”加到边权里，因为题目给的意思是“如果一个点A和B连边了，那么A->B的花费是A的花费+B的花费+A到B的边权
// 而如果C也要和A连边，同理 A->C的花费是A的花费+C的花费+A到C的边权” ...

const int N = 1000 + 10, M = N * 5 + 10;
// 神坑OJ，用const定义数组大小会报Segmentation Fault错误w，得用#define才行... 
#define MAXN 1010*1010/2
struct G {
	int u, v, w;
	G () {};
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	bool operator<(const G& g) const {
		return w < g.w;
	}
} graph[MAXN];
struct unionFind {
	int bin[MAXN];
	unionFind () {
		for (int i = 0; i < M; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		if (ask(x, y)) return;
		bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
int cost[MAXN];
int main() {
	int T, n, wt, cnt;
	scanf("%d", &T);
	while (T--) {
		cnt = 0; 
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &cost[i]);
		// 输入的是一个矩阵，可能prim会更好..，注意这里ij同样从1开始.. 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &wt);
				if (j > i) {
					// 加上边权的同时加上两个点自己的花费 
					graph[cnt++] = G(i, j, wt + cost[i] + cost[j]);
				}
			}
		}
		int res = 0;
		sort(graph, graph + cnt);
		unionFind uf;
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].u, graph[i].v)) {
				uf.uni(graph[i].u, graph[i].v);
				res += graph[i].w; 
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
