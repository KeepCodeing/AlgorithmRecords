#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// 初wg的题w，总之还是板子题..已经有边的点加0边.. 
// 事实上不是这样，而是直接连边，因为题目没要求输出已经建立的边的点对... 

// 空间开小RE了... 
const int N = 750 + 10, M = N * N;
struct Node {
	int x, y;
} poi[N];
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
struct g {
	int ut, vt;
	double wt;
	g (int ut, int vt, double wt) : ut(ut), vt(vt), wt(wt) {};
	g () {};
	bool operator<(const g& gg) const {
		return wt < gg.wt;
	}
} graph[M];
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2 + .0) + (y1 - y2) * (y1 - y2 + .0));
}
int main() {
	int ut, vt, n, m, cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &poi[i].x, &poi[i].y);
	// 下标坑w
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			graph[cnt++] = g(i, j, cpl(poi[i].x, poi[i].y, poi[j].x, poi[j].y));
		}
	} 
	unionFind uf;
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &ut, &vt);
		uf.uni(ut, vt);
//		graph[cnt++] = g(ut, vt, 0);
	}
	sort(graph, graph + cnt);
	
	for (int i = 0; i < cnt; i++) {
		if (!uf.ask(graph[i].ut, graph[i].vt)) {
			printf("%d %d\n", graph[i].ut, graph[i].vt);
			uf.uni(graph[i].ut, graph[i].vt); 
		}
	}
	return 0;
}
