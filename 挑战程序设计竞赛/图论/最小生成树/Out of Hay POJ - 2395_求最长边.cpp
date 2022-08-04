#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// �������������...ԭ����Ŀ���Ǻ����׿������Ǹ���С���������������ֱ�Ӹ�����Ҫ�����...��ô����С������
// Ȼ���¼��߾�����... 

const int N = 2000 + 10, M = 1e4 + 10;
struct G {
	int u, v, w;
	bool operator<(const G& g) const {
		return w < g.w;
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
		if (ask(x, y)) return;
		bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) scanf("%d%d%d", &graph[i].u, &graph[i].v, &graph[i].w);
	sort(graph, graph + m);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (!u.ask(graph[i].u, graph[i].v)) {
			u.uni(graph[i].u, graph[i].v);
			ans = max(ans, graph[i].w);
		}
	}
	printf("%d", ans);
	return 0;
}
