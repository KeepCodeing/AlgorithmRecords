#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// 机翻题目看的并不是很明白，大概的意思应该是给了几对点是已经连边的，这几个点可以说是不用花费的，而其它点都要
// 算出互相的距离然后跑最小生成树，但是最后还要输出每个点的互相连接的边，可能跑完还要遍历下并查集什么的...
// 总之先写写好了，大不了看题解w 

// 写完恍然大悟，其实根本不存在所谓的跑完再查祖宗之类的操作，因为其跑完了这样搞发现样例查到的全是8这个节点
// 然后惯例的输出图的数据，正打算手玩一下的时候发现其实这个题要做的就是在连边的同时输出连的那两个点就行了..
// 至于为什么可以想下为什么测试样例里没有一开始就连好的那几条边，大概就是因为先连好了不会再连的原因罢... 

const int N = 750 + 10, M = N * N;
struct Pos {
	int x, y;
} pos[N];
struct G {
	int u, v;
	double w;
	bool operator<(const G& g) const {
		return w < g.w;
	}
	G (int u, int v, double w) : u(u), v(v), w(w) {};
	G () {};
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
int main() {
	int n, m, tx, ty, cnt = 0, temp;
	unionFind uf;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &tx, &ty);
		uf.uni(tx, ty); 
	}
	// 下标坑w 
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			graph[cnt++] = G(i, j, cpl(pos[i].x, pos[i].y, pos[j].x, pos[j].y));
		}
	}
	sort(graph, graph + cnt);
//	for (int i = 0; i < cnt; i++) {
//		 printf("%d %d %.2lf\n", graph[i].u, graph[i].v, graph[i].w);
//	}
	for (int i = 0; i < cnt; i++) {
		if (!uf.ask(graph[i].u, graph[i].v)) {
			uf.uni(graph[i].u, graph[i].v); 
			printf("%d %d\n", graph[i].u, graph[i].v);
		}
	}
	return 0;
}
