#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 看不懂题目w，看了题解发现意思就是使得最长边最短，那么跑个最小生成树就行了...
// 注意结果不用小数点，还有就是它的边权计算不是普通欧几里得距离，而是去掉sqrt的...（发现去掉sqrt就没必要
// 用小数了..） 

const int N = 1010;
typedef pair<int, int > PII;
struct g {
	int u, v, w;
	g (int u, int v, int w) : u(u), v(v), w(w) {};
	g () {};
	bool operator<(const g& gg) const {
		return w < gg.w;
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
PII poi[N];
int cpl(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &poi[i].first, &poi[i].second);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			graph[cnt++] = g(i, j, cpl(poi[i].first, poi[i].second, poi[j].first, poi[j].second));
		}
	}
	sort(graph, graph + cnt);
	unionFind uf;
	int res = 0;
	for (int i = 0; i < cnt; i++) {
		int u = graph[i].u, v = graph[i].v;
		if (!uf.ask(u, v)) {
			uf.uni(u, v);
			res = graph[i].w; 
		}
	}
	printf("%d", res);
	return 0;
}
