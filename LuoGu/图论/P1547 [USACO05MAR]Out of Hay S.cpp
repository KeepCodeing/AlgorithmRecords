#include <iostream>
#include <cstdio> 
#include <algorithm>
using namespace std;

// 裸题呢...就是求最小生成树里最长边的值..对比下就完了... 

const int N = 1e5 * 5 + 10; 
struct G {
	int u, v, w;
	bool operator<(const G& g) {
		return w < g.w;
	}
} g[N];
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
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) scanf("%d%d%d", &g[i].u, &g[i].v, &g[i].w);
	sort(g, g + m);
	int res = -1;
	for (int i = 0; i < m; i++) {
		if (!u.ask(g[i].u, g[i].v)) {
			res = max(res, g[i].w), u.uni(g[i].u, g[i].v);
		}
	}
	printf("%d", res);
	return 0;
}
