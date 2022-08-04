#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 100 + 10, M = N * N;
struct Node {
	double x, y, z, r;
} balls[N];
struct G {
	int ut, vt;
	double wt;
	G (int ut, int vt, double wt) : ut(ut), vt(vt), wt(wt) {};
	G () {};
	bool operator<(const G& g) const {
		return wt < g.wt;
	}
} graph[M];
struct unionFind {
	int bin[M];
	unionFind() {
		for (int i = 0; i < M; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		int a = anc(x), b = anc(y);
		// 注意这里，似乎用bin[a] = y是不可行的，因为这样只是把x连到y了.. 
		if (a != b) bin[a] = b;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
double cpl(Node a, Node b) {
	double x1 = a.x, y1 = a.y, z1 = a.z;
	double x2 = b.x, y2 = b.y, z2 = b.z;
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}
int main() {
	int n, cnt;
	while (scanf("%d", &n), n != 0) {
		cnt = 0;
		// 输入了两个z..最幸福的人.. 
		for (int i = 1; i <= n; i++) scanf("%lf%lf%lf%lf", &balls[i].x, &balls[i].y, &balls[i].z, &balls[i].r);
		// 惯例的下标坑w
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				// 这里有个小技巧，既然相交的两个球不用花费，那么它们连边的价格就为0，否则就是r1到r2的距离-r1+r2
				double dist = cpl(balls[i], balls[j]);
				if (balls[i].r + balls[j].r >= dist) graph[cnt++] = G(i, j, .0);
				else graph[cnt++] = G(i, j, dist - (balls[i].r + balls[j].r));
			}
		} 
		unionFind uf;
		double res = .0;
		sort(graph, graph + cnt);
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].ut, graph[i].vt)) {
				res += graph[i].wt;
				uf.uni(graph[i].ut, graph[i].vt); 
			}
		}
		printf("%.3lf\n", res);
	}
	return 0;
}
