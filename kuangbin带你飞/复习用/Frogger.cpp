#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// 最小生成树的最长边，当然还有最大生成树的最短边，这类题目无疑都有种二分答案的感觉，然而其并不会写二分w，代替的方案是用Kruskal
// 搞个生成树，然后统计...这种方法似乎可以通吃二分答案的图论题.. 

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
		// 下标坑w
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				graph[cnt++] = gp(i, j, cpl(pos[i].x, pos[i].y, pos[j].x, pos[j].y));
			}
		} 
		unionFind uf;
		// 忘了sort... 
		sort(graph, graph + cnt);
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].ut, graph[i].vt)) {
				uf.uni(graph[i].ut, graph[i].vt); 
				// 根据生成树的定义，其一定只有n - 1条边，n个顶点，并且MST最后连接的那个边一定是最长边... 
				// 不是这样吧？这个题要求的是1->2的最长边，而不是整个生成树的最长边... 
				if (uf.ask(1, 2)) {
					printf("Scenario #%d\n", T);
					printf("Frog Distance = %.3lf\n\n", graph[i].wt);
					// 忘了break 
					break;
				}
			}
		}
	}
	return 0;
}
