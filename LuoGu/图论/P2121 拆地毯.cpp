#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 洛谷交了几发全爆零了（恼），希望这个题能AC，看起来挺裸的题.. 

const int N = 100000 + 10;
struct Node {
	int u, v, w;
	bool operator<(const Node& n) const {
		// 最大生成树... 
		return w > n.w;
	}
} graph[N];
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
		int a = anc(x), b = anc(y);
		if (a != b) bin[a] = b;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
int main() {
	int n, m, k, res = 0;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) scanf("%d%d%d", &graph[i].u, &graph[i].v, &graph[i].w);
	sort(graph, graph + m);
	unionFind uf;
	for (int i = 0; i < m; i++) {
		if (!uf.ask(graph[i].u, graph[i].v)) {
			// 想了半天为什么自己的生成树会有环，然后一看代码发现忘了连边... 
			uf.uni(graph[i].u, graph[i].v); 
			res += graph[i].w;
			k--;
			if (!k) break;
		}
	}	
	printf("%d", res);
	return 0;
}
