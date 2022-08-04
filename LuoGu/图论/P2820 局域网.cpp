#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 首先考虑这个题的两个要求：1. 不存在环  2. 总花费最小
// 对于1.而言，生成树是一定不存在环的，也就是说我们进行生成
// 树的过程就是把整个图重构了一遍，同时删去了一些边，而这些
// 边就是权值较大的边，也就是说最后的生成树也一定满足2. 

// 然而上面并没有看清楚题目，题目的要求是去掉的边权和最大。那么我们想一下，如果留下来的边权和最小，
// 用总边权减去留下来的边权和，即可保证去掉的边权和最大。

// 总的来说这个题考查了最小生成树的无环，边权和最小的性质，还在原来的基础上换了个说法，让我们求去掉边
// 的边权最大...

// 另外要注意边权为0的情况，这意味着两个顶点不相连，那判断下边权是否为0用来决定是否加边就行 

// 最后对比下最短路和最小生成树，最短路要求的是一个或者多个起点到某个终点（可能会有多个终点，这需要虚拟源点来做）
// 的最短距离，而最小生成树一般是要我们去掉某些边，使得最后的图无环全连通且边权和最小 

const int N = 100 * 10 + 10;
struct net {
	int u, v, w;
	bool operator<(const net& n) {
		return w < n.w;
	}
} nt[N];
struct unionFind {
	int bin[N];
	unionFind() {
		for (int i = 0; i < N; i++) bin[i] = i;
	};
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
	int n, k, ut, vt, wt, cnt = 0, tot = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		// 边权为0不存在边，跳过加边 
		if (!wt) continue;
		nt[cnt].u = ut, nt[cnt].v = vt, nt[cnt].w = wt, tot += wt, cnt++;
	}
	sort(nt, nt + k);
	int res = 0;
	// 利用最小生成树算法得到的极小连通分量一定是无环且全连通并且边权和最小的 
	for (int i = 0; i < k; i++) {
		if (!u.ask(nt[i].u, nt[i].v)) {
			u.uni(nt[i].u, nt[i].v);
			res += nt[i].w;
		}
	}
	// 最后总边权减去剩下的最小边权和就是最大的去掉的边权和 
	printf("%d", tot - res);
	return 0;
}
