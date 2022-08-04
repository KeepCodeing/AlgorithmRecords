#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// Kruskal算法思想非常简单，是贪心的经典应用。为了保证生成树的边权和最小，我们让每次添加到树里的节点的边权最小即可，也
// 就是对输入的数据进行一次排序，然后从小到大添加顶点就行。当然，为了保证一个顶点只被添加一次，可以用并查集维护整个生成
// 树，并查集提供合并操作，对于不连通的两个顶点，统计权值，如果最后不是所有点都连通，就说明不存在最小生成树（即添加点的
// 个数不等于输入点的个数） 

// 出了大锅w，首先是数组下标与排序范围，其设置的下标是从1开始，但是排序的时候从0开始了，所以为了方便干脆就从0开始
// 然后是并查集w，感觉是最不应该的，板子都写错了（无能）
// 最后是并查集结构体初始化，这里为了少几个循环选择的输入数据范围后初始化bin数组，然后发现这样搞似乎每次查询都是得到
// u的祖宗和v的祖宗相同，然后发现并查集数结构体是在读入数据前就进行了初始化w，这也就意味着n的值不确定，自然初始化就出
// 了问题w 

// 另外最小生成树的图大部分都是无向图，可以通过这一点区分最短路 

// 看了下各种最小生成树的题，大部分都是要去掉一些东西（对应到图里就是边），而最小生成树做的就是每次都把前n-1小的边连
// 起来 

const int N = 1e5 * 2 + 10;
int n, m;
struct unionFind {
	int bin[N];
	unionFind() {
		for (int i = 0; i <= n; i++) bin[i] = i;
	};
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
struct Graph {
	int u, v, w;
	bool operator<(const Graph g) const {
		return w < g.w;
	}
} G[N];

int main() {
	scanf("%d%d", &n, &m);
	unionFind u;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &G[i].u, &G[i].v, &G[i].w);
	}
	sort(G, G + m);
	int res = 0, cnt = 0;
	for (int i = 0; i < m; i++) {
		if (!u.ask(G[i].u, G[i].v)) {
			res += G[i].w;cnt++;u.uni(G[i].u, G[i].v); 
		}	
	}
	if (cnt < n - 1) printf("Impossible!\n");
	else printf("%d\n", res);
	return 0;
}
