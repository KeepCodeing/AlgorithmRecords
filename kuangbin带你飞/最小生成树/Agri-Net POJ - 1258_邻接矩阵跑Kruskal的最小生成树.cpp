#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 看了下提交记录似乎两个星期前被这个题折磨了很多次，那时候应该是刷挑战没状态乱写...然后这次居然也是..
// 迷迷糊糊的写完交了WA了，看题发现多组输入，改了之后又交又PE了，才发现多组输入输出没换行...这个题交了
// 十次甚至九次...没状态果然比较吃力呢..明明一个模板题的说... 

const int N = 100 + 10, M = N * N;
struct G {
	int u, v, w;
	bool operator<(const G& g) const {
		return w < g.w;
	}
	G (int u, int v, int w) : u(u), v(v), w(w) {};
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
int main() {
	int n, wt, cnt, res;
	while (~scanf("%d", &n)) {
		cnt = res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &wt);
				if (j > i) {
					graph[cnt++] = G(i, j, wt);
				}
			}
		}
		unionFind uf;
		sort(graph, graph + cnt);
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].u, graph[i].v)) {
				res += graph[i].w;
				uf.uni(graph[i].u, graph[i].v);
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
