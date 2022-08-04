#include <iostream>
#include <cstdio>
using namespace std;

// 复习题..
// 首先考虑下一颗最小生成树或者说使得一个节点数为n的图最少需要几条边，根据数据结构的知识（迫真），可以知道前者最多有n-1条边
// 后者最少也需要n-1条边，那么再看题目，这个题要使得所有边连通，但是却没有给出所有边的信息，要我们求最少要加多少条边才能使得
// 这个图每个点都能到达，而且这个图存在重边，那么自然可以想到用个最小生成树统计下现在有多少个边连接，然后再用n-1条边做差，但是
// 再思考下最小生成树是干嘛的，最小生成树是用来使得顶点全连通且边最少而且边权最小，那这个题其实只用到了第一个和第二个特性，而
// Kruskal算法里实现这个两个特性的方法是利用并查集，因此这个题其实是个并查集连边的题（一转） 

// 这个题因为没给边数所以一开始叫的完全RE爆零（爆笑），所以下面连边的操作其实是可以不用一个结构体数组来做的... 

const int N = 1010 * 10 + 10, M = 1e6 * 5 + 10;
struct G {
	int u, v;
	G (int u, int v) : u(u), v(v) {};
	G () {};
} graph[M];
int bin[N];
struct unionFind {
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
	int n, m;
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) scanf("%d%d", &graph[i].u, &graph[i].v);
		// 因为题目会多次用到并查集连边所有这里bin数组的位置以及初始化得改改 
		for (int i = 0; i <= n; i++) bin[i] = i;
		int cnt = 0;
		// 注意这里的连边，用了个结构体数组，因为其还不是很熟练，然后因为没给边数爆零了...，直接连边也是可以的... 
		for (int i = 1; i <= m; i++) {
			// 开始连边
			if (!u.ask(graph[i].u, graph[i].v)) {
				u.uni(graph[i].u, graph[i].v);
				cnt++; 
			} 
		}
		// 最后输出连了的边的数量以及全连通该图所需边的数量的差
		printf("%d\n", n - 1 - cnt); 
	}
	return 0;
}
