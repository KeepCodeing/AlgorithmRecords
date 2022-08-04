#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 并查集坠毁... 

const int N = 10000 + 10, M = 20000 + 10;
struct Node {
	int u, v, w, d;
	Node (int u, int v, int w, int d) : u(u), v(v), w(w), d(d) {};
	Node () {};
	bool operator<(const Node& n) {
		if (w != n.w) return w < n.w;
		return d < n.d;
	}
} nodes[M];
struct unionFind {
	int bin[N];
	void initBin(int n) {
		for (int i = 1; i <= n; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
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
	while (true) {
		scanf("%d%d", &n, &m);	
		if (!n && !m) break;
		u.initBin(n); 
		for (int i = 0; i < m; i++) scanf("%d%d%d%d", &nodes[i].u, &nodes[i].v, &nodes[i].w, &nodes[i].d);
		cout << endl;
		sort(nodes, nodes + m);
		for (int i = 0; i < m; i++) printf("%d %d %d %d\n", nodes[i].u, nodes[i].v, nodes[i].w, nodes[i].d);
		int ans = 0, cnt = 0;
		for (int i = 0; i < m; i++) {
			if (!u.ask(nodes[i].u, nodes[i].v)) {
				u.uni(nodes[i].u, nodes[i].v);
				ans += nodes[i].d; 
				cnt++;
				// 改了下似乎能过一点样例了，不过因为是重构路径所以连边顺序是乱的，这就不符合最短路从1出发的要求了... 
				if (u.ask(1, n) && cnt == n - 1) break;
			}
		}
		printf("%d\n", ans);
	}
	
	
	return 0;
}
