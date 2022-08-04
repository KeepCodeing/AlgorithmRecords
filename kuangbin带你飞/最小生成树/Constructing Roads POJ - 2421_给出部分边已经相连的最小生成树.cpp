#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 这个题差不多也会是裸题了，给出的对角矩阵，那么用Prim会比较合理，题目给出了一些边已经相连，不是说这些边在进行最小生成
// 树之前就连好了，而是说这些边边权为0，即不需要任何花费。那么其又想到了在洛谷上的一个题，大概就是给出一些边已经相连，
// 然后部分边没有相连，要求最短路，这个题如果真的按照题意来建一个不完整的图是绝对会错的，这样甚至不能保证存在最短路，正确
// 的做法是先不管所谓的已经相连，直接跑次最短路，这个最短路的值就是所谓的修好后的花费，然后对被修好的点对加0边，再跑最短路
// 这就是所谓的修复前的花费，然后两者做差就能得到所谓的修好哪些未相连的边的花费了。（一瞬搞成最短路的题的感觉了ww），这个
// 题也是同理，我们对已经修好的点加0边就行了...，其一开始想的是直接连边，但是加0边然后在最小生成树里做的话似乎更方便... 

const int N = 1e5 * 5 + 10;
struct G {
	int ut, vt, wt;
	G (int ut, int vt, int wt) : ut(ut), vt(vt), wt(wt) {};
	G () {};
	bool operator<(const G& g) const {
		return wt < g.wt;
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
		if (ask(x, y)) return;
		bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
int main() {
	int n, cnt = 0, wt, m, ut, vt;
	scanf("%d", &n);
	// 注意这里，其一开始写的i = 0, j = 0，那就是意味着题目给的点从0开始编号，但实际上题目给的点从1开始编号
	// 所以最好这里i，j也从1开始.. 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &wt);
			if (j > i) {
				graph[cnt++] = G(i, j, wt);
			}
		}
	}
	scanf("%d", &m);
	while (m--) {
		// 这里想了下出了问题，发现ut，vt可能是0... 
		scanf("%d%d", &ut, &vt);
		graph[cnt++] = G(ut, vt, 0);
	}
	sort(graph, graph + cnt);
	unionFind uf;
	int res = 0;
	for (int i = 0; i < cnt; i++) {
		if (!uf.ask(graph[i].ut, graph[i].vt)) {
			uf.uni(graph[i].ut, graph[i].vt);
			res += graph[i].wt;
		}
	}
	printf("%d", res);
	return 0;
} 
