#include <iostream>
#include <cstdio>
using namespace std;

// 首先要说下边权并查集怎么写，之前看教程写过一个带边权并查集的题，设置边权很简单，就是将dist[x] += dist[bin[x]]即当前节点
// 的边权就是其到父节点的边权， 依次类推类似前缀和，最后就能算出来任意一个节点到根节点的距离。那么如何加边权呢，其做的那个
// 题中是用个sz数组记录当前树的大小，这样应该只适用边权全是1的树（虚心），适用面更广的方式是dist[root] = -dist[x] + dist[y] + s
// 这里root就是x的根节点，y就是要合并到的节点，s就是新边权。那么为什么可以这样写呢，我们想下将x合并到y上首先得加一条边权为s
// 的边，然后加上y的边权，即dist[y] + s，但是这样做x的根节点的边权没有变化。因为图里是x->root，而合并后就是root->x，所以root到
// x的边权就是-dist[x]，把这些加起来就是上面那个式子了... 

// 这个题从代码上来看就是个裸的带权并查集，但是还是有些思考难度的。首先考虑怎么用并查集表示一段区间，这里并查集表示区间和线段树
// 完全不同，毕竟并查集用边权，线段树用节点...假如给定一个区间[a, b]其和为v，我们不妨规定a->b有一条长度为v的边，即边长代表区间和
// 两个节点代表区间大小，那么询问操作对应的就是查询一段区间，且这段区间是已经存在的，那么a，b一定有个共同祖先，于是查询[a,b]的区间
// 和就是用dist[roota] - dist[rootb]..（蒙古） 

const int N = 200000 + 10;
int bin[N], dist[N];
struct unionFind {
	void _init(int n) {
		for (int i = 1; i <= n; i++) bin[i] = i, dist[i] = 0;
	}
	int anc(int x) {
		if (x != bin[x]) {
			int pre = dist[x];
			bin[x] = anc(bin[x]), dist[x] += dist[pre];
		}
		return bin[x];
	}
	void uni(int x, int y, int s) {
		int ax = anc(x), by = anc(y);
		if (ax == by) return;
		dist[ax] = -dist[x] + dist[y] + s;
		bin[ax] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	bool check(int l, int r, int v) {
		return dist[l] - dist[r] == v;
	}
};
unionFind uf;
int main() {
	int n, m, l, r, v;
	while (~scanf("%d%d", &n, &m)) {
		uf._init(n);
		int ans = 0;
		while (m--) {
			scanf("%d%d%d", &l, &r, &v);
			l--;
			// int ra = uf.anc(l), rb = uf.anc(r);
			if (uf.ask(l, r)) {
				if (!uf.check(l, r, v)) ans++;
			} else {
				uf.uni(l, r, v);
			}
		}
		printf("%d\n", ans);
		
	}
	return 0;
}
