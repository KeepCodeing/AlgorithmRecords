#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

// 其实已经在vjudge上做过这个题了，但是洛谷上的题目让其半天都理解不能w，倒不如说自己到底做完了理解没w...
// 那么题目就是说可以安装无线电的哨站不用花钱，不能安装的要花钱，然后求最小的花钱数量。可以发现装无线
// 电的两个点肯定是越远越划得来，那么问题就变成了去掉S条最长边，问剩下的边里最长边的长度。 

// 一道做过的题，然而不知道为什么摸了半天... 

// 直接N^2防止爆炸 
const int N = 500 + 10, M = N * N;
struct Pos {
	int x, y;
} pos[N];
struct Node {
	int u, v;
	double w;
	Node (int u, int v, double w) : u(u), v(v), w(w) {};
	Node () {};
	bool operator<(const Node& n) const {
		return w < n.w;
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
		int a = anc(x), b = anc(y);
		if (a != b) bin[a] = b;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2 + .0) * (x1 - x2) + (y1 - y2 + .0) * (y1 - y2));
}
int main() {
	int s, n, cnt = 0;
	scanf("%d%d", &s, &n);
	s = n - s;
	for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
	// 下标坑w
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			graph[cnt++] = Node(i, j, cpl(pos[i].x, pos[i].y, pos[j].x, pos[j].y));
		}
	} 
	sort(graph, graph + cnt);
	unionFind uf;
	double res = 0.0;
	for (int i = 0; i < cnt; i++) {
		int ut = graph[i].u, vt = graph[i].v;
		if (!uf.ask(ut, vt)) {
			uf.uni(ut, vt);
			// 关于这里，其一开始的想法是加0边，然后发现这样会破坏原来的图，所以还是直接少连边，那么一共要连多少条边呢，试几个值就知道了，
			// 当n == 4, s == 2时，可以发现这个图的最小生成树有3条边，而s == 2意味着可以去掉一条边，所以就只用连n - s条边。当s == 1时，
			// 也就是不能省边，要连的边也是n - s条...再进一步，一个n个点的图要连n - 1条边，而可以少连 s - 1条边，就可以得到一共要连
			// n - 1 - (s - 1)也就是 n - s条边.. 
			if (--s == 0) {
				res = graph[i].w;
				break;
			}
		}
	}
	printf("%.2lf", res);
	return 0;
}
