#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 这个题要求花费最小，可以将问题转化为最小生成树，不过题目描述实在是迷。一般来说最小生成树做到的是边权和最小，而不是
// 边权和最大，所以这里要么给边权取反，要么排序从大到小就行了... 
// 做完了才发现理解错了w，这个题所谓的维护两个并查集其实不是之前做的那个帮派题的意思，而是说x和y虽然值相同，但是却是
// 完全不一样的东西，x表示男兵，y表示女兵，它们的编号都是从0开始，但我们连边的时候可能会出现0号男兵和0号女兵相连，这
// 在其一开始看起来以为是自环，但是写注释的时候才发现这两个东西其实是完全不一样的...那么为了使得x和y完全不同，还要保证
// 数据的正确性，最好让y加上n，或者x加上m，也就是让他们完全不想交，连边就变成了x->y+n，这样的形式...那么就要注意并查集
// 范围了，一般来说是扩大两倍... 

// 总结：很有意思的一个题，一开始做完全不明白题目要干什么，因为给了x，y，但是他们的值却是相同的，不过可以看出来这个题要用
// 最小生成树做，因为要求花费最小，而花费最小的前提就是关系连边所带来的利益（边权）最大..果然英文题目容易误解... 

typedef long long LL;
// 注意这里的*2，因为男兵女兵要分开维护，也就是说这个题和查帮派那个题一样，本质上维护的两个并查集... 
const int N = 10000 * 2 + 10, M = 50000 + 10;
struct Node {
	int u, v, w;
	// 这里要使得生成树边权最大，所以是降序排序.. 
	// 注意这里的const，必须要加，不然会CE... 
	bool operator<(const Node& n) const {
		return w > n.w;
	}
	Node (int u, int v, int w) : u(u), v(v), w(w) {};
	Node () {};
} node[M];
struct unionFind {
	int bin[N];
	void init_bin(int n) {
		// 点的编号从0开始，而且要多次初始化并查集 
		for (int i = 0; i < n; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		if (!ask(x, y)) bin[anc(x)] = y; // 似乎并查集不加这个if很容易爆栈，所以最好加上前面的if 
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		unionFind u; 
		// 男兵，女兵的数量，还有边数，不知道这个给男兵女兵数量是干什么，可能是点数，也可能是算最大总花费.. 
		int n, m, r;
		scanf("%d%d%d", &n, &m, &r);
		// 注意这里对并查集初始化的设置，这个题实质上维护了两个并查集，所以得扩大范围 
		u.init_bin(n + m);
		for (int i = 0; i < r; i++) {
			// 这里不像那种要算坐标的题，可能会有很多边，这题给多少边就是多少边... 
			scanf("%d%d%d", &node[i].u, &node[i].v, &node[i].w);
			// 将女兵的顶点+n，表示将女兵与男兵集合区分开来，因为男兵是x~n，女兵是y~m，草，恍然大悟ww 
			node[i].v += n;
		}
		// 按边权从大到小排序.. 
		sort(node, node + r);
		// Kruskal求最大边权树
		LL res = 0;
		for (int i = 0; i < r; i++) {
			if (!u.ask(node[i].u, node[i].v)) {
				u.uni(node[i].u, node[i].v);
				res += node[i].w;
			}
		} 
		printf("%lld\n", (n + m + 0ll) * 10000 - res);
	}
	
	return 0;
}

