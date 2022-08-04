#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// 没有看懂题目w，看了别人的博客才发现这个题求得其实是两点之间的最长边，那么这种题就可以用最小生成树来做。因为这种
// 题不要求走的顺序什么的，只要求走的路径中的最长边。而所谓走的路径就是当1点和2点产生环的那些边，即当1点和2点相连
// 成环了就说明1点到了2点，如果根据Kruskal的思路来看，当1点和2点成环的时候的那条边就一定是最长边... 
// 这种题其实也做过了，不过题面都比较难想到最小生成树求最长边... 

const int N = 200 + 10;
struct Pos {
	int x, y;
} pos[N];
struct G {
	int u, v;
	double w;
	G (int u, int v, double w) : u(u), v(v), w(w) {};
	G () {};
	// 注意const... 
	bool operator<(const G& g) const {
		return w < g.w;
	}
} graph[N * N]; // 这里大小应该只用开一半，因为下面的循环大概是个等差数列，不过为了保险开大点... 
struct unionFind {
	int bin[N];
	void _init() {
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
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2 + .0) + (y1 - y2) * (y1 - y2 + .0));
}
unionFind u;
int main() {
	int n, cnt;
	for (int T = 1;; T++) {
		scanf("%d", &n);
		if (!n) break;
		for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				graph[cnt++] = G(i, j, cpl(pos[i].x, pos[i].y, pos[j].x, pos[j].y));
			}
		}
		u._init();
		sort(graph, graph + cnt);
		for (int i = 0; i < cnt; i++) {
			if (!u.ask(graph[i].u, graph[i].v)) {
				u.uni(graph[i].u, graph[i].v);
				if (u.ask(1, 2)) {
					printf("Scenario #%d\n", T);
					printf("Frog Distance = %.3lf\n\n", graph[i].w);
					// 出现了解就要退出，不然会输出多个答案，从而WA... 
					break;
				} 
			}
		}
	}
	return 0;
}
