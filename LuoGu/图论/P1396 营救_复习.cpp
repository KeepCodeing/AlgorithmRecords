#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 做完了这个题才知道是个最小生成树的题，原因是这个题没有提到全连通，也没有很直接的说要使总边权最小...
// 那么要求的就是最小生成树里最长边的长度（错），又看了眼题目才想起来，不是求最长边的长度，是求
// 第一条能到终点的边的长度...，另外因为课设也要开始了，所以得加把劲了w... 

const int M = 1e5 * 5 + 10, N = 1e4 * 2 + 10;
struct G {
	int u, v, w;
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	G () {};
	bool operator<(const G& g) {
		return w < g.w;
	}
} graph[M];
struct unionFind {
	int bin[N];
	unionFind () {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &graph[i].u, &graph[i].v, &graph[i].w);
	}
	sort(graph, graph + m);
	for (int i = 0; i < m; i++) {
		if (!u.ask(graph[i].u, graph[i].v)) u.uni(graph[i].u, graph[i].v); 
		// s点与t点第一次连的边一定是所有边中最短的，也就是在当前生成树里最长边最小的那个边... 
		if (u.ask(s, t)) {
			printf("%d", graph[i].w);
			return 0;
		}
	}
	return 0;
}
