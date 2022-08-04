#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

// ���������С������ר������һ����w��������ȰѾ����������Ȼ��ѷ�Χ�ڵĵ����Ϊ�������ߵ�
// ������С������������ж����ǲ���n-1���߶������˾���... 

const int N = 100 + 10, M = N * N;
struct P {
	int x, y;
} pos[N];
struct G {
	int u, v;
	double w;
	G () {};
	// ����д����G (int u, int, int w)��Ȼ����ͨ����w...������WA������... 
	G (int u, int v, double w) : u(u), v(v), w(w) {};
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
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2 + .0) + (y1 - y2) * (y1 - y2 + .0));
}
int main() {
	int T, n, cnt = 0, pcnt = 0;
	double temp, res;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		// �±��w 
		for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
		cnt = pcnt = res = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				temp = cpl(pos[i].x, pos[i].y, pos[j].x, pos[j].y);
				// �Ƿ����벻�ӵ�ͼ�� 
				if (temp < 10.0 || temp > 1000.0) continue;
				graph[cnt++] = G(i, j, temp);
			}
		}
		unionFind uf;
		sort(graph, graph + cnt);
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].u, graph[i].v)) {
				uf.uni(graph[i].u, graph[i].v);
				res += graph[i].w;
				pcnt++; 
			}
		}
		if (pcnt != n - 1) printf("oh!\n");
		// �������ŵļ۸�100 
		else printf("%.1lf\n", res * 100); 
	}
	return 0;
}
