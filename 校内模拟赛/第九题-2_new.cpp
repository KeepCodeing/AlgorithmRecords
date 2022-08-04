#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// 比赛的时候以为是最短路，然而却不知道边权怎么算（无能），后来开始刷最短路的时候碰到了同样给的坐标的题
// 于是就知道了边权不一定要给出来。另外这个题其实是最小生成树，关键词是花费最低且全连通... 

const int N = 1000 * 10 + 10;
struct pos {
	int x, y, h;	
} ps[N];
struct Graph {
	int u, v;
	double w;
	Graph(int u, int v, double w) : u(u), v(v), w(w) {};
	Graph() {};
	bool operator < (const Graph& g) {
		return w < g.w;
	}
} G[N];
double getDist(int x1, int y1, int x2, int y2, int h1, int h2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) + (h1 - h2) * (h1 - h2);
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
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &ps[i].x, &ps[i].y, &ps[i].h);
	}
	int cnt = 0;
	// 加边权，因为是无向图所以一个点到另一个点的边权算一次就行，用j = i + 1保证点i到点j的边权能被算到且只算一次 
	// 注意这里： i，j应该统一从1开始，同样的也就变成了<=n，这是个巨坑（绝望），可能这个题过了样例，但是依然会因为
	// 下标爆0（为了起警示作用就不改了） 
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			G[cnt++] = Graph(i, j, getDist(ps[i].x, ps[i].y, ps[j].x, ps[j].y, ps[i].h, ps[j].h));
		}
	}
	sort(G, G + cnt);
	double res = 0;
	for (int i = 0; i < cnt; i++) {
		if (!u.ask(G[i].u, G[i].v)) {
			res += G[i].w;
			u.uni(G[i].u, G[i].v); 
		}
	}
	printf("%.2lf", res);
	return 0;
}
/*
4
1 1 3
9 9 7
8 8 6
4 5 4
*/
