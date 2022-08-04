#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 这个题和之前在acwing上做的那个题是一样的...然而其根本没有看出来...
// 一句话总结就是虚拟源点可以直接当成图里的某个点，而且这个点到其它所有点的距离都是最小的。 

// 又想了想，觉得这样说不太对，正确的理解应该是用0点代表某个点要修水井，如果这个点到其它点的最小距离都比修水井的花费大，
// 那么根据排序后的数据，修水井一定会被先选。 

// RE了，由此可见就算把邻接矩阵当成邻接表输入，也要保证空间是N * N以上的... 
const int N = 1e5 + 10;
struct Node {
	int u, v, w;
	Node (int u, int v, int w) : u(u), v(v), w(w) {};
	Node () {};
	bool operator<(const Node& n) const {
		return w < n.w;
	}
} graph[N];
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
	int n, cnt = 0, wt;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &wt);
		graph[cnt++] = Node (0, i, wt);
	}
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &wt);
			if (j > i) graph[cnt++] = Node(i, j, wt);
		}
	}
	unionFind uf;
	sort(graph, graph + cnt);
	int res = 0;
	for (int i = 0; i < cnt; i++) {
		int ut = graph[i].u, vt = graph[i].v;
		if (!uf.ask(ut, vt)) {
			uf.uni(ut, vt);
			res += graph[i].w; 
		}
	}
	printf("%d", res);
	return 0;
}
