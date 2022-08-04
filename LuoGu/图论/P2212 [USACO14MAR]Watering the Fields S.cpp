#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 颓废到现在，不妙的样子...这个题是个最小生成树的题，看起来有点像模板题，加了个条件是要求所有边权都大于C，那么一样是
// 排序，连边，最后统计是不是所有点都连上了就行（应该） 

// 又因为空间小了RE了，这种题的坑点就是给了顶点数，但是不给边数，一般来说开1e6*5是没问题的... 

// 话说回来这个题有普及+/提高的难度，可能是本five第一道完全自己写出来的这个难度的题w，不过总体来看还是个模板题，和
// 聪明的猴子那个题类似，不过那个题坑点更多就是了..（指WA了很多次） 

const int N = 2010, M = 1e6 * 5;
struct G {
	int u, v, w;
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	G() {};
	bool operator<(const G& g) {
		return w < g.w;
	}
} graph[M];
struct POS {
	int x, y;
} pos[N];
int getdist(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
struct unionFind {
	int bin[N];
	unionFind() {
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
	int n, c, cnt = 0;
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
	// 计算边权，注意为了统一下标pos这个数组的下标也从1开始，总之不排序下标无所谓，至于这里循环的下标为0就会出坑... 
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			graph[cnt++] = G(i, j, getdist(pos[i].x ,pos[i].y, pos[j].x, pos[j].y));
		}
	}
	sort(graph, graph + cnt);
	// printf("%d %d %d\n", graph[i].u, graph[i].v, graph[i].w);
	int flag = 0, res = 0;
	for (int i = 0; i < cnt; i++) {
		if (graph[i].w < c) continue;
		if (!u.ask(graph[i].u, graph[i].v)) {
			u.uni(graph[i].u, graph[i].v);
			res += graph[i].w, flag++;
			
		}
	} 
	// 最少要用n-1条边连通这个无向图，那么统计下加了多少条边就行了... 
	if (flag != n - 1) res = -1;
	printf("%d", res);
	return 0;
}
