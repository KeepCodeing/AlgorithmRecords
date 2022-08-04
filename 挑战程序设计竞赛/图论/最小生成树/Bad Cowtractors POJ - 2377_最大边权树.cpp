#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 这个题应该就是个最小生成树求最大边权和的裸题呢，排个序就完事了...今天本来是enjoy(your)lifetime的，但是没有题刷怎么能行... 
// 做完了发现确实是这样，不过忘了输出没答案的情况了... 

const int N =  1000 + 10, M =  20000 + 10;
struct G {
	int u, v, w;
	// 注意这里的const，POJ的评测机没这个的话会CE 
	bool operator<(const G& g) const {
		// 边权从大到小排序.. 
		return w > g.w;
	}
} graph[M];
struct unionFind {
	int bin[N];
	unionFind () {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (bin[x] != x) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		if (!ask(x, y)) bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &graph[i].u, &graph[i].v, &graph[i].w);
	}
	// 套板子... 
	sort(graph, graph + m);
	long long ans = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (!u.ask(graph[i].u, graph[i].v)) {
			u.uni(graph[i].u, graph[i].v);
			ans += graph[i].w; 
			cnt++;
		}
	}
	// 忘了题目要求没答案输出-1w 
	if (cnt != n - 1) ans = -1;
	printf("%lld", ans);
	return 0;
}
