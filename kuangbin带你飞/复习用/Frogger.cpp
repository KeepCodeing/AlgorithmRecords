#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// ��С����������ߣ���Ȼ�����������������̱ߣ�������Ŀ���ɶ����ֶ��ִ𰸵ĸо���Ȼ���䲢����д����w������ķ�������Kruskal
// �����������Ȼ��ͳ��...���ַ����ƺ�����ͨ�Զ��ִ𰸵�ͼ����.. 

const int N = 200 + 10;
struct Node {
	int x, y;
} pos[N];
struct gp {
	int ut, vt;
	double wt;
	gp (int ut, int vt, double wt) : ut(ut), vt(vt), wt(wt) {};
	gp () {};
	bool operator<(const gp& g) const {
		return wt < g.wt;
	}
} graph[N * N]; 
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2 + .0) + (y1 - y2) * (y1 - y2 + .0));
}
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
		int a = anc(x), b = anc(y);
		if (a != b) bin[a] = b;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
int main() {
	int n, cnt, pcnt;
	for (int T = 1;; T++) {
		scanf("%d", &n);
		if (!n) break;
		cnt = 0;
		for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
		// �±��w
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				graph[cnt++] = gp(i, j, cpl(pos[i].x, pos[i].y, pos[j].x, pos[j].y));
			}
		} 
		unionFind uf;
		// ����sort... 
		sort(graph, graph + cnt);
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].ut, graph[i].vt)) {
				uf.uni(graph[i].ut, graph[i].vt); 
				// �����������Ķ��壬��һ��ֻ��n - 1���ߣ�n�����㣬����MST������ӵ��Ǹ���һ�������... 
				// ���������ɣ������Ҫ�����1->2����ߣ����������������������... 
				if (uf.ask(1, 2)) {
					printf("Scenario #%d\n", T);
					printf("Frog Distance = %.3lf\n\n", graph[i].wt);
					// ����break 
					break;
				}
			}
		}
	}
	return 0;
}
