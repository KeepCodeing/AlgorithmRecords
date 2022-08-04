#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// 昨天一眼看上去比较蒙w，现在一看就能看出题目要问的就是求有多少个猴子
// 的跳跃距离比最小生成树的n - 1条边大。因为最小生成树可以保证所有顶点
// 连通无环且最长边值最小。
// 建图，跑遍生成树，顺便记录下每条边的长度（应该是最短边的长度，如果对猴子跳跃距离进行排序，容易得到
// 第一个跳跃距离大于最短边的猴子及其后面的猴子都是可以在这个最小生成树的若干个边上觅食的）就行了... 
// 然而排序复杂度比直接枚举还要高，所以下面就写了个O(n)的对比.. 

// 我谔谔，又没看题目，是在所有树冠上觅食，不是能在一个任意一个上面觅食就行（过样例然后爆0，有时候真得
// 细心看题（绝望）），然后这里的对比规则就变成了>=
// 另外后面好多点全RE了.... 

// 开50w空间怼过去了，并不会算到底要开多大的数组...之前开5w坠毁了，这东西太玄学了... 

const int N = 100000 * 5 + 1000, M = 510 * 10;
int monkeys[M];
struct POS {
	int x, y;
} p[N];
struct GRAPH {
	int u, v;
	double w;
	GRAPH(int u, int v, double w) : u(u), v(v), w(w) {};
	GRAPH() {};
	bool operator<(const GRAPH& g) {
		return w < g.w;
	}
} g[N];
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
// 之前做了一个题也是坐标距离，保险点强转成double，不然可能会有精度问题 
double getDist(int x1, int y1, int x2, int y2) {return (double)sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2));}
unionFind u;
int main() {
	int n, m, cnt = 0;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) scanf("%d", &monkeys[i]);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
	// 啊啊，这里的下标坑一定要注意.. 
	for (int i = 1; i <= n; i++) 
		for (int j = i + 1; j <= n; j++) 
			g[cnt++] = GRAPH(i, j, getDist(p[i].x, p[i].y, p[j].x, p[j].y));
	sort(g, g + cnt);
	double maxDist = -1.0;
	// 接下来就是找最长边的值了 
	for (int i = 0; i < cnt; i++) 
		if (!u.ask(g[i].u, g[i].v)) 
			maxDist = max(maxDist, g[i].w), u.uni(g[i].u, g[i].v); 
	int res = 0;
	//printf("%.2lf", maxDist);
	// 对比每个猴子的跳跃距离是否大于等于最长边 
	for (int i = 1; i <= m; i++) 
		if (monkeys[i] >= maxDist) res++;
	printf("%d", res);
	return 0;
}
