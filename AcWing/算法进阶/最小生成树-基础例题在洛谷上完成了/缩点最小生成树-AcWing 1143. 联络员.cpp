#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// 题目给出的若干个点存在可选可不选的情况。一般的最小生成树的题只要求全联通，无环，边权最小。 
// 那么我们考虑下，有的点必须选，那干脆就先把这种边连起来，不管这些点组成的子图是否成环，都
// 一定存在若干个祖宗节点。这里利用缩点的思想，将这些连通块看成一个点，也就是他们的祖宗节点， 
// 然后对非必选点按边权排序，在连边的过程中判断下当前非必选点所在的连通块的祖宗点是否与要连边
// 的点的祖宗点连通，如果连通，不加边，否则当前加的边一定最短且能使这两个连通块连通。（这里
// 的生成树其实是可能有环的，但是如果把连通块看成一个点那就是无环的） 

// 总结就是这种题在普通的连通块题目上做了一点修改，我们要将必选点组成的连通块看成一个点，然后
// 用非必选点将这些连通块连边。相对于普通题而言就是在输入的过程中就将必选点连起来，然后将非必选
// 点存起来，后面的操作就和普通题一样了。（啊啊，语言能力极差） 

const int N = 2000 * 10 + 10;
struct G {
	int ut, vt, wt;
	bool operator< (const G& g) {
		return wt < g.wt;
	}
	G (int ut, int vt, int wt) : ut(ut), vt(vt), wt(wt) {};
	G () {};
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
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	// 奇妙，循环加register可以加快速度，下面这个循环不加register跑了2s，加了只用跑0.5s 
	// for (register int i = 0; i < 999999999; ++i);
	int n, m, ut, vt, wt, p, cnt = 0, res = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%d", &p, &ut, &vt, &wt);
		// 必选直接连边且统计边权和，非必选边先存着，后面再进行连边 
		if (p == 1) res += wt, u.uni(ut, vt);
		else graph[cnt++] = G(ut, vt, wt);
	}
	sort(graph, graph + cnt);
	// 后面套板子，对非可选边进行连边，直到所有点连通 
	for (int i = 0; i < cnt; i++) {
		if (!u.ask(graph[i].ut, graph[i].vt)) {
			u.uni(graph[i].ut, graph[i].vt);
			res += graph[i].wt; 
		}
	}
	printf("%d", res);
	return 0;
}

/*
5 6
1 1 2 1
1 2 3 1
1 3 4 1
1 4 1 1
2 2 5 10
2 2 5 5

9
*/
