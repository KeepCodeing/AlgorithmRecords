#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 题目给了三个条件
// 1.要求所有道路连通 2. 要改造的道路尽量少 3. 要求重建后的道路中的最大分值最小
// 对于1. 就是要求全联通，生成树的一个特点。对于2. 既然要全连通，那么根据生成树的性质
// 最后得到的图一定只有n-1条边。对于3. 也就是说要我们求最小生成树里最大边权，统计即可。 

const int N = 100000 * 5 + 10;
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
	for (int i = 0; i < m; i++) 
		scanf("%d%d%d", &g[i].u, &g[i].v, &g[i].w);
	sort(g, g + m);
	int res = -1, cnt = 0;;
	for (int i = 0; i < m; i++) {
		// 统计最小生成树里的最大边权以及边数 
		if (!u.ask(g[i].u, g[i].v)) 
			res = max(res, g[i].w), u.uni(g[i].u, g[i].v), cnt++;
	}
	printf("%d %d", cnt, res);
	return 0;
}
