#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// �������ύ��¼�ƺ���������ǰ���������ĥ�˺ܶ�Σ���ʱ��Ӧ����ˢ��սû״̬��д...Ȼ����ξ�ȻҲ��..
// ���Ժ�����д�꽻��WA�ˣ����ⷢ�ֶ������룬����֮���ֽ���PE�ˣ��ŷ��ֶ����������û����...����⽻��
// ʮ�������Ŵ�...û״̬��Ȼ�Ƚϳ�����..����һ��ģ�����˵... 

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
