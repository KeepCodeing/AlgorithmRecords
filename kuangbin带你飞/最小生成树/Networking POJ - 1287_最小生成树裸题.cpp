#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// 纯粹的裸题了... 

const int N = 500;
struct G {
	int ut, vt, wt;
	G () {};
	G (int ut, int vt, int wt) : ut(ut), vt(vt), wt(wt) {};
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
	int n, m, ut, vt, wt, cnt;
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		scanf("%d", &m);
		cnt = 0;
		while (m--) {
			scanf("%d%d%d", &ut, &vt, &wt);
			graph[cnt++] = G(ut, vt, wt);
		}
		sort(graph, graph + cnt);
		unionFind uf;
		int res = 0;
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].ut, graph[i].vt)) {
				res += graph[i].wt;
				// 加边加成ut->wt了ww 
				uf.uni(graph[i].ut, graph[i].vt); 
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
