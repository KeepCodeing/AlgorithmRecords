#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

// 终于把线代复习完了w，从星期一到星期五，中间有两天是电工..做一个题放松下？感觉不太可能w，毕竟其智商有限w
// 这个题思路比较模糊，不过既然给了坐标还有距离，那么大概就是先把两个点之间的距离算出来，然后这个题D不仅是
// 两个点之间的距离，而且要求D是统一的，也就是说有几个点要连D就乘上多少倍，然后还有个卫星，可以可以让有卫星
// 的点不花费资金...这里既然要求所有点都能相连，那么其实就是保证最长边最短，而有卫星不用花钱应该就是意味着
// 可以少几条边的钱，如果设卫星的个数为n，那么就可以省去n-1条边的钱，先假定这里省去的边的钱花费最大...

// 试了小好像是的，首先还是套板子，先算出来每个点的距离，然后连边，但是注意这里的连边不是都连，也就是最后的
// 生成树可能是个森林。我们首先想下一个普通最小生成树有多少个边，如果有p个点，那就是p-1条边，而这里加入了所
// 谓的卫星，如果有s个卫星，那就是说有s个点不用进行连边，也就是生成树可以少s-1条边，如果我们按照Kruskal算法
// 的思路来的话，能连边权少的边就连边权少的边，于是乎这里我们连p-1-(s-1)条边就行了，也就是只用连p-s条边就行了 
 
const int N = 500 + 10, M = N * N;
struct Pos {
	int x, y;
} pos[N];
struct G {
	int u, v;
	double w;
	G (int u, int v, double w) : u(u), v(v), w(w) {};
	G () {};
	bool operator<(const G& g) const {
		return w < g.w;
	}
} graph[M];
struct unionFind {
	int bin[M];
	unionFind() {
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
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2 + .0) * (x1 - x2) + (y1 - y2 + .0) * (y1 - y2));
}
int main() {
	int T, s, p, cnt;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &s, &p);
		// 喜闻乐见的下标坑，基本每用到一个就会说下，可见聪明的猴子那个题对其造成的阴影w 
		for (int i = 1; i <= p; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
		cnt = 0;
		for (int i = 1; i <= p; i++) {
			for (int j = i + 1; j <= p; j++) {
				graph[cnt++] = G(i, j, cpl(pos[i].x, pos[i].y, pos[j].x, pos[j].y));
			}
		}
		double maxDist = .0;
		int bcnt = 0;
		unionFind uf;
		sort(graph, graph + cnt);
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].u, graph[i].v)) {
				uf.uni(graph[i].u, graph[i].v);
				bcnt++;
				maxDist = max(maxDist, graph[i].w);
				if (bcnt == p - s) break;
			}
			// printf("%d %d %.2lf\n", graph[i].u, graph[i].v, graph[i].w);
		}
		printf("%.2lf\n", maxDist);
	}
	return 0;
}
