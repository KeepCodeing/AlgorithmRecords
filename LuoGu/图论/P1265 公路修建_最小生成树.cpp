#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

// 这个题和普通最小生成树的区别在于题目里给了个条件，要求三个城市成环的时候去掉一个最短边，然而我们
// 想下，MST是不允许出现环的，因此这个规则可以直接省去... 

const int N = 5e3 + 10;
struct Poi {
	int x, y;
} poi[N];
struct Node {
	int u, v;
	double w;
	Node (int u, int v, double w) : u(u), v(v), w(w) {};
	Node () {};
	bool operator<(const Node& n) const {
		return w < n.w;
	}
} graph[N * N];
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
vector<Node > vec;
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2 + .0) + (y1 - y2) * (y1 - y2 + .0));
}
int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> poi[i].x >> poi[i].y;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
//			vec.push_back(Node(i, j, cpl(poi[i].x, poi[i].y, poi[j].x, poi[j].y)));
			// printf("%d %d %.2lf\n", i, j, cpl(poi[i].x, poi[i].y, poi[j].x, poi[j].y));
			graph[cnt++] = Node(i, j, cpl(poi[i].x, poi[i].y, poi[j].x, poi[j].y));
		}
	}
//	sort(vec.begin(), vec.end());
	sort(graph, graph + cnt);
	// for (int i = 0; i < cnt; i++) printf("%d %d %.2lf\n", graph[i].u, graph[i].v, graph[i].w);
	double res = .0;
	unionFind uf;
	for (int i = 0; i < cnt; i++) {
		int ut = graph[i].u, vt = graph[i].v;
		if (!uf.ask(ut, vt)) {
			res += graph[i].w;
			uf.uni(ut, vt); 
		}
	}
	printf("%.2lf", res);
	return 0;
}
