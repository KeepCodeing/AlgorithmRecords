#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// ������Ŀ���Ĳ����Ǻ����ף���ŵ���˼Ӧ���Ǹ��˼��Ե����Ѿ����ߵģ��⼸�������˵�ǲ��û��ѵģ��������㶼Ҫ
// �������ľ���Ȼ������С���������������Ҫ���ÿ����Ļ������ӵıߣ��������껹Ҫ�����²��鼯ʲô��...
// ��֮��дд���ˣ����˿����w 

// д���Ȼ������ʵ������������ν�������ٲ�����֮��Ĳ�������Ϊ�������������㷢�������鵽��ȫ��8����ڵ�
// Ȼ����������ͼ�����ݣ�����������һ�µ�ʱ������ʵ�����Ҫ���ľ��������ߵ�ͬʱ��������������������..
// ����Ϊʲô��������Ϊʲô����������û��һ��ʼ�����õ��Ǽ����ߣ���ž�����Ϊ�������˲���������ԭ���... 

const int N = 750 + 10, M = N * N;
struct Pos {
	int x, y;
} pos[N];
struct G {
	int u, v;
	double w;
	bool operator<(const G& g) const {
		return w < g.w;
	}
	G (int u, int v, double w) : u(u), v(v), w(w) {};
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
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2 + .0) + (y1 - y2) * (y1 - y2 + .0));
}
int main() {
	int n, m, tx, ty, cnt = 0, temp;
	unionFind uf;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &tx, &ty);
		uf.uni(tx, ty); 
	}
	// �±��w 
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			graph[cnt++] = G(i, j, cpl(pos[i].x, pos[i].y, pos[j].x, pos[j].y));
		}
	}
	sort(graph, graph + cnt);
//	for (int i = 0; i < cnt; i++) {
//		 printf("%d %d %.2lf\n", graph[i].u, graph[i].v, graph[i].w);
//	}
	for (int i = 0; i < cnt; i++) {
		if (!uf.ask(graph[i].u, graph[i].v)) {
			uf.uni(graph[i].u, graph[i].v); 
			printf("%d %d\n", graph[i].u, graph[i].v);
		}
	}
	return 0;
}
