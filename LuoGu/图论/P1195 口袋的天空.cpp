#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// 最小生成树，因为要求花费最少，我们将两朵云的一条边看成是最小生成树里的边
// 题目要求只用k个云朵，就是说只允许最小生成树存在k个边，那么连边的时候这样
// 判断下就行了

// 总结：这个题相对模板题而言改了下连边的过程，也就是对于模板题而言还有所变化w
// 但是不知道为什么评级是普及-... 
 
const int N = 1000 * 10 + 10, M = 10000 * 5 + 10;
struct G {
	int u, v, w;
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	G () {};
	bool operator<(const G& g) {
		return w < g.w;
	}
} graph[M];
struct unionFind {
	int *bin;
	unionFind(int n) {
		bin = new int[n + 10];
		for (int i = 0; i < n + 10; i ++) bin[i] = i;
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
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	// 注意这里，给了n个点，但是这n个点不一定都有边，所以并查集初始化的时候要这样做 
	unionFind u(n);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &graph[i].u, &graph[i].v, &graph[i].w);
	}
	sort(graph, graph + m);
	int cnt = 0, ans = 0;
	for (int i = 0; i < m; i++) {
		if (!u.ask(graph[i].u, graph[i].v)) {
			u.uni(graph[i].u, graph[i].v);
			ans += graph[i].w;
			cnt++;
		}
		// 要连k个棉花糖，也就是存在n-k条边就行，这似乎是图论的基本内容，不过
		// 数据结构白上了所以不太记得了w 
		if (cnt == n - k) {
			printf("%d", ans);
			return 0;
		}
	}
	printf("No Answer");
	return 0;
}
