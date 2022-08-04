#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;

// 模板题w，刚刚看了一个次小生成树的题，感觉完全不懂的样子w，give up，还有个题也是看不懂，那么先把后面的做了吧... 

// 空间开小了，主要是其输入有n * (n - 1) / 2条边，而其直接只开了100 www，不过空间
// 开小了居然是TLE... 
const int N = 6000;
struct G {
	int u, v, w;
	bool operator<(const G& g) const {
		return w < g.w;
	}
} graph[N];
struct unionFind {
	int bin[N];
	unionFind() {
		for (int i = 0; i < N; i++) bin[i] = i;
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
int main() {
	int n, m, res;
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		res = 0, m = n * (n - 1) / 2;
		for (int i = 0; i < m; i++) scanf("%d%d%d", &graph[i].u, &graph[i].v, &graph[i].w);
		sort(graph, graph + m);
		unionFind uf;
		for (int i = 0; i < m; i++) {
			if (!uf.ask(graph[i].u, graph[i].v)) {
				uf.uni(graph[i].u, graph[i].v);
				res += graph[i].w;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
