#include <iostream>
#include <algorithm>
using namespace std;

// 带权并查集太难搞不会ww，跑来刷最小生成树了...这个题就是普通最小生成树，只不过点用字母形式给出了..
// 看起来用邻接矩阵存会比较方便，但是这样大概得写个Prim... 

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
	int n, m, wt, cnt;
	char ut, vt;
	while (true) {
		cin >> n;
		if (!n) break;
		n--, cnt = 0;
		// 难点全在输入上w，输入是n-1，不是n... 
		while (n--) {
			cin >> ut >> m;
			while (m--) {
				cin >> vt >> wt;
				graph[cnt++] = G(ut, vt, wt);
			}
		}
		unionFind uf;
		sort(graph, graph + cnt);
		int res = 0;
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].ut, graph[i].vt)) {
				uf.uni(graph[i].ut, graph[i].vt);
				res += graph[i].wt; 
			}
		}
		cout << res << endl;
	}
	return 0;
}
