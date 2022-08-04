#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// 复习第三弹，被聪明的猴子那题血虐（绝望），本来打算最短路和最小生成树都只刷两题的，现在看来要加班了...
// 这个题的思路：要使得去掉的连线值最大，就要保证在所有电脑能进行连线的情况，连线用的消费最小，显而易见
// 这就是个最小生成树的题目，最后的答案就是总边权值减最小生成树的边权，这里得注意一个点，边权为0代表没有
// 连接，这里是题目为了迷惑我们所加的一个条件，试想下最小生成树的边权排序，越小的边权越靠前，那么我们可以
// 发现边权为0的边永远会被先选，但是这又是无连接的，所以就自相矛盾了，解决方案就是既然加进来排序会出错，
// 而且这两个点本来就没边，干脆就不加这个边，也就是判断下边权然后决定是否加边... 

// 永远不要相信题目给的边数的范围，很多情况边数数组不开很大就会RE.. 
const int N = 100 * 10 + 10;
struct G {
	int u, v, w;
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	G () {};
	bool operator<(const G& g) {
		return w < g.w;
	}
} graph[N];
struct unionFind {
	int bin[N];
	unionFind() {
		for (int i = 0; i < N; i++) bin[i] = i;
	};
	int anc(int x) {
		if (bin[x] != x) bin[x] = anc(bin[x]);
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
	int n, m, cnt = 0, tot = 0, mnum = 0;
	scanf("%d%d", &n, &m);
	int ut, vt, wt;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &ut, &vt, &wt);
		if (!wt) continue;
		graph[cnt++] = G(ut, vt, wt), tot += wt;
	}
	// 上个题这里写成了graph + n，不过其实现在的思维也不是很活跃了，有点打模板的嫌疑，明天接着搞这玩意... 
	sort(graph, graph + cnt);
	for (int i = 0; i < cnt; i++) {
		// 去掉一些线还有形成回路之类的都可能是在暗示这个题是最小生成树，因为去的线按理来说一定是更高花费的线，而
		// 回路则意味着去掉线不能有回路，最小生成树就保证没有回路... 
		if (!u.ask(graph[i].u, graph[i].v)) {
			u.uni(graph[i].u, graph[i].v);
			mnum += graph[i].w;
		}
	} 
	printf("%d", tot - mnum);
	return 0;
}
