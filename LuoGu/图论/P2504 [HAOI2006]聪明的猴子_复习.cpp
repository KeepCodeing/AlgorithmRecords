#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

// 复习题第二弹，很像当时模拟考的题..，这个题的坑点某过于下标和题意了...
// 首先是下标，这里计算边权时下标一定要从1开始，否则会出现很奇怪的错误...然后是题意，题目问的是能在所有
// 树上觅食的猴子的数量，而不是能在任意树上觅食的猴子的数量...

// 那么因为做过这个题所以就直接说思路了：将每棵树看为一个顶点，这棵树到其它所有点的距离就是边权，我们要使得一只猴子
// 能在任意的树上觅食，其实就是使得树与树之间的距离（边权）最大值最小，这里也要求每棵树是连通的，因为一只猴子只能从
// 一个树到另一个树..，那么思路就是建图，跑最小生成树，记录最长边的值，最后判断下有多少个猴子的跳跃能力大于等于这个值
// 即可... 

// 犯了三个神必的错误，导致其一道做过的题WA三次，可能和状态有点关系，完全没想到点子上... 

const int M = 500 * 10 + 10, N = 100000 * 5 + 1000;
int monkeys[M]; 
struct pos {
	int x, y;
} ps[N];
struct G {
	int u, v;
	double w;
	G (int u, int v, double w) : u(u), v(v), w(w) {};
	G () {};
	bool operator<(const G& g) {
		return w < g.w;
	}
} graph[N];
double gd(int x1, int y1, int x2, int y2) {
	return sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2));
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
	int m, n, cnt = 0;
	scanf("%d", &m);
	// 下标没统一，下面两层循环从1开始，那么这里的几个循环最好也从1开始，唯一要注意的其实是graph这个数组
	// 因为它要排序，所以如果下标从1开始很容易排序错误... 
	for (int i = 1; i <= m; i++) scanf("%d", &monkeys[i]);
	scanf("%d", &n);
	// 最离谱的错误：这里居然只写了一个%d，而且还能过两个点... 
	for (int i = 1; i <= n; i++) scanf("%d%d", &ps[i].x, &ps[i].y);
	// 坑点：这里下标一定要从1开始...
	// 计算当前点到其后点的边权 
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			// 整个代码就这里的循环要注意下标，其它地方都无所谓，只要统一就行... 
			graph[cnt++] = G(i, j, gd(ps[i].x, ps[i].y, ps[j].x, ps[j].y));
		}
	}
	double lst = 0;
	// 最小生成树不排序... 
	sort(graph, graph + cnt);
	for (int i = 0; i < cnt; i++) {
		// 连边+统计最长边... 
		if (!u.ask(graph[i].u, graph[i].v)) {
			u.uni(graph[i].u, graph[i].v);
			lst = max(lst, graph[i].w); 
		}
	}
	int res = 0;
	for (int i = 1; i <= m; i++) res += ((double)monkeys[i] >= lst);
	printf("%d", res);
	return 0;
}
