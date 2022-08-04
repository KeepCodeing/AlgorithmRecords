#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// �������˸�����Ȩ��������˵������������Ȩ��ʵ������֮��ı�Ȩ+������Ļ��ѣ������Ļ����������ߵĹ�����
// ������Ȩ���ӵ���Ȩ���Ϊ��Ŀ������˼�ǡ����һ����A��B�����ˣ���ôA->B�Ļ�����A�Ļ���+B�Ļ���+A��B�ı�Ȩ
// �����CҲҪ��A���ߣ�ͬ�� A->C�Ļ�����A�Ļ���+C�Ļ���+A��C�ı�Ȩ�� ...

const int N = 1000 + 10, M = N * 5 + 10;
// ���OJ����const���������С�ᱨSegmentation Fault����w������#define����... 
#define MAXN 1010*1010/2
struct G {
	int u, v, w;
	G () {};
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	bool operator<(const G& g) const {
		return w < g.w;
	}
} graph[MAXN];
struct unionFind {
	int bin[MAXN];
	unionFind () {
		for (int i = 0; i < M; i++) bin[i] = i;
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
int cost[MAXN];
int main() {
	int T, n, wt, cnt;
	scanf("%d", &T);
	while (T--) {
		cnt = 0; 
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &cost[i]);
		// �������һ�����󣬿���prim�����..��ע������ijͬ����1��ʼ.. 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &wt);
				if (j > i) {
					// ���ϱ�Ȩ��ͬʱ�����������Լ��Ļ��� 
					graph[cnt++] = G(i, j, wt + cost[i] + cost[j]);
				}
			}
		}
		int res = 0;
		sort(graph, graph + cnt);
		unionFind uf;
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].u, graph[i].v)) {
				uf.uni(graph[i].u, graph[i].v);
				res += graph[i].w; 
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
