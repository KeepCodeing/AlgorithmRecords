#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// �����Ӧ�þ��Ǹ���С������������Ȩ�͵������أ��Ÿ����������...���챾����enjoy(your)lifetime�ģ�����û����ˢ��ô����... 
// �����˷���ȷʵ�������������������û�𰸵������... 

const int N =  1000 + 10, M =  20000 + 10;
struct G {
	int u, v, w;
	// ע�������const��POJ�������û����Ļ���CE 
	bool operator<(const G& g) const {
		// ��Ȩ�Ӵ�С����.. 
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
	// �װ���... 
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
	// ������ĿҪ��û�����-1w 
	if (cnt != n - 1) ans = -1;
	printf("%lld", ans);
	return 0;
}
