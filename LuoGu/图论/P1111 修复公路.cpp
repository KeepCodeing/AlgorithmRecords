#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 第一眼看这个题有点蒙，因为题意里有“根据t来加边”的感觉，但是事实上花了下图就看出来了，“按t加边”其实是个互不
// 干扰的过程，也就是一个边的t在减少时其它所有边的t也在减少。那么这里第一想法就是个最小生成树，按t排序（t就是边权）
// 然后统计下最大的t，最后的生成树一定满足全联通，无环且边权最大最小。

// 然后看了下标签，并没有生成树，疑惑，跑到题解看了下，原来也可以用并查集来写。其实考虑了并查集，也就是有个题要求
// 什么时候出现环路那个思想，但是太蠢没想出来具体实现。
// 并查集的实现：对边权进行排序，然后按边权从小到大连边，每连上一个边总边数就-1，如果所有点连通就一定有n-1条边，然后
// 连边过程中统计下最大边权。这个思路和最小生成树的思路其实一模一样，只不过换了写法或者说法，不过思路还是很具有参考
// 性的。

// 这里用最小生成树写算了，因为都差不多的... 

// 值得一提的是空间开小了又RE了，这么看来N = 1k， M = 10w的时候N最好开500倍（50w），M最好开5倍（50w）
// 另外加register在循环上好像也没什么效果.. 

const int N = 1000 * 100 * 5 + 10, M = 100000 * 5;
struct G {
	int u, v, w;
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	G () {};
	bool operator<(const G& g) {
		return w < g.w;
	}
} graph[N];
struct unionFind {
	int bin[N];
	unionFind () {
		for (register int i = 0; i < N; i++) bin[i] = i;
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
	int n, m, ut, vt, wt, cnt = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		graph[cnt++] = G(ut, vt, wt);
	}
	sort(graph, graph + cnt);
	int res = -1, pcnt = 0;
	for (register int i = 0; i < cnt; i++) {
		if (!u.ask(graph[i].u, graph[i].v)) res = max(res, graph[i].w), pcnt++, u.uni(graph[i].u, graph[i].v); 
	}
	if (pcnt != n - 1) printf("%d", -1);
	else printf("%d", res);
	return 0;
}
