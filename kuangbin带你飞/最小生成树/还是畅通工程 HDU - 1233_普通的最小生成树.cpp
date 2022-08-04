#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;

// ģ����w���ոտ���һ����С���������⣬�о���ȫ����������w��give up�����и���Ҳ�ǿ���������ô�ȰѺ�������˰�... 

// �ռ俪С�ˣ���Ҫ����������n * (n - 1) / 2���ߣ�����ֱ��ֻ����100 www�������ռ�
// ��С�˾�Ȼ��TLE... 
const int N = 6000;
struct G {
	int u, v, w;
	bool operator<(const G& g) const {
		return w < g.w;
	}
} graph[N];
struct unionFind {
	int bin[N];
	unionFind() {
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
	int n, m, res;
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		res = 0, m = n * (n - 1) / 2;
		for (int i = 0; i < m; i++) scanf("%d%d%d", &graph[i].u, &graph[i].v, &graph[i].w);
		sort(graph, graph + m);
		unionFind uf;
		for (int i = 0; i < m; i++) {
			if (!uf.ask(graph[i].u, graph[i].v)) {
				uf.uni(graph[i].u, graph[i].v);
				res += graph[i].w;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
