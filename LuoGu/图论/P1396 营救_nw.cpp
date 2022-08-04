#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 这个题主要用的是最小生成树的思想，当起点和终点第一次连通时，当前这个边的边权一定是最小最大值，当然这个
// 做法并不适用于最短路，因为这个做法只是在判断连通否的基础上使得连边的顺序从小到大开始而已。 

// 看起来是最小生成树，最短路，二分都可以做的题，因为太池沼只会最小生成树写法所以这里搞个最小生成树算了...
// 思路是当所有点都连通时，最后连通的那个点就是拥挤度最小最大的点。和普通生成树有点不一样，普通生成树是
// 把所有边都连起来，这个题只要形成了环就可以得到答案了。 

const int N = 1e6 * 10 + 1;
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
	int n, m, s, e, cnt = 0, ut, vt, wt;
	scanf("%d%d%d%d", &n, &m, &s, &e);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		graph[cnt++] = G(ut, vt, wt);
	}
	sort(graph, graph + cnt);
	for (int i = 0; i < cnt; i++) {
		u.uni(graph[i].u, graph[i].v);
		if (u.ask(s, e)) {
			printf("%d", graph[i].w);
			return 0;
		}  
		
	}
	return 0;
}
