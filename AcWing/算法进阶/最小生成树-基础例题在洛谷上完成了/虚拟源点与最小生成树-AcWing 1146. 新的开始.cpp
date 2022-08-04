#include <iostream>
#include <algorithm>
using namespace std;

// 写完了的总结：其实光看加边的操作比较难以理解，但是可以把到0的边想象成输入的图的一部分，然后这个部分
// 也参与到了最小生成树里（多了一条到0的边），后面就是套模板了... 

// 这个题有两个条件，条件一是要求建立一个发电站（选一个矿井），使得所有矿井与这个发电站直接或者间接的连通。
// 条件二是要求在所有矿井都能通电的情况下花费最小。

// 如果我们不考虑条件一的选矿井，可以发现这个题就是个最小生成树的应用。但是加上条件一后就和最小生成树模板
// 不同了，在最小生成树模板里我们只关心边权最小且未连通的点，但这个题要我们选一个点作为源点。那么考虑下，
// 如果有一个点与所有矿井相连且这个点就是发电厂，那么条件一就满足了，接下来就是跑一次最小生成树了。参考
// 多起点的最短路问题的思路，我们可以想到对每个点都建立一条能通往0点的边，且边权为0。于是0点就是发电站，
// 对这个图跑次最小生成树就行了。 

// 这个题给的个邻接矩阵，明显是用Prim做比较合适，但是其只会Kruskal，所以就用
// Kruskal做好了（无能） 

// 2020年8月1日12:22:33，一句话总结就是虚拟源点可以直接当成图里的某个点，而且这个点到其它所有点的距离都是最小的。

const int N = 300 * 10 + 10;
struct G {
	int u, v, w;
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	G () {};
	bool operator < (const G& g) const {
		return w < g.w;
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
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	int n, wt, cnt = 0;
	cin >> n;
	// 先输入的权值，因此不妨将输入顺序作为点的变化，然后用建立一条
	// 0~i的权值为wt的双向边 
	for (int i = 1; i <= n; i++) {
		cin >> wt;
		graph[cnt++] = G(0, i, wt);
	}
	// 然后输入一个邻接矩阵，邻接矩阵转邻接表只需要输入一半的数据
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> wt;
			if (j > i) graph[cnt++] = G(i, j, wt); 
		}
	} 
	sort(graph, graph + cnt);
	int res = 0;
	// 套板子，当建立发电站的边与0点相连后，就可以把加的边权也看成生成树的一部分了... 
	for (int i = 0; i < cnt; i++) {
		if (!u.ask(graph[i].u, graph[i].v)) {
			res += graph[i].w, u.uni(graph[i].u, graph[i].v); 
		}
	}
	cout << res;
	return 0;
}
/*
4
5
4
4
3
0 2 2 2
2 0 3 3
2 3 0 4
2 3 4 0

9
*/
