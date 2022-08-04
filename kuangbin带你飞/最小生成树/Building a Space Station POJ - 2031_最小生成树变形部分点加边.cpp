#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// 这个题应该是个最小生成树变形题，因为它允许部分点不用加边。在题目的描述里就是相交/相切的球体不需要花费魔法
// 来进行相连。那么分几种情况讨论：所有点都是相加或者相切的，我们就不需要花钱，部分点是相交相切的，那么这些
// 点就不用花钱，但是因为要把所有点连接起来，所以还要算不用花钱的点到要花钱的点的最小距离，即枚举所有不花钱的
// 点，然后用这些点给每个要花钱的点加边，边权就是距离再用最小生成树拆边...
// 想了下上面的方法似乎很麻烦，又是判断是否相交，又是加边的..这里想到了一个可能更简便的方式，首先因为每个点都能
// 互相到达，因此不妨将每个点都加上一条到其它所有点的边，边权即为两个点的距离，然后排序跑最小生成树，在进行重构
// 树的过程中判断当前两个点是否相交或者相切，如果相交或相切，则花费记为0，否则花费就是他们的距离...看起来是可行
// 的，思路整合了聪明的猴子和一道要求边权大于D的题。
// 然后发现其不会知道怎么求球体是否相交或者相切w，职高生的末路么w..看了别人的博客，求球体相交相切和求圆相交相切
// 似乎是一样的，只不过球体是三个坐标，圆是两个坐标。计算方法就是sqrt((x1 - x2) * (x1 - x2)...) - r1 + r1，意思
// 就是先算出两个球体的中心距离，然后减去它们的半径和，如果半径和小于等于0，就说明是相交或者相切的，相反它们就是
// 相离的，那么这里加的边权应该就是距离 - 半径和，为什么是这样呢，因为我们可以认为连接两个球体不是从中心开始的，
// 而是从球面开始的...看起来圆心距离和圆的距离似乎有所区别w，一直不知道w... 

const int N = 100 + 10, M = 1e5 * 5 + 50;
struct Ball {
	double x, y, z, r;
} ball[N];
struct G {
	int ut, vt;
	double wt;
	G () {};
	G (int ut, int vt, double wt) : ut(ut), vt(vt), wt(wt) {};
	bool operator<(const G& g) const {
		return wt < g.wt;
	}
} graph[M];
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
		if (ask(x, y)) return;
		bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
int main() {
	int n, cnt;
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		cnt = 0;
		for (int i = 1; i <= n; i++) scanf("%lf%lf%lf%lf", &ball[i].x, &ball[i].y, &ball[i].z, &ball[i].r);
		// 被下标坑过w 
		double tx, ty, tz, tr, dist;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				tx = ball[i].x - ball[j].x, ty = ball[i].y - ball[j].y, tz = ball[i].z - ball[j].z, tr = ball[i].r + ball[j].r;
				// 计算圆心距离 
				dist = sqrt(tx * tx + ty * ty + tz * tz);
				// 如果两个圆是相离的，边权就是距离减去半径和 
				if (dist > tr) graph[cnt++] = G(i, j, dist - tr);
				// 如果相交或者相切，直接处理边权为0就行了，在生成树过程中判断比较麻烦... 
				else graph[cnt++] = G(i, j, .0); 
			}
		}
		unionFind uf;
		double res = .0;
		sort(graph, graph + cnt);
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].ut, graph[i].vt)) {
				uf.uni(graph[i].ut, graph[i].vt);
				res += graph[i].wt; 
			}
		}
		// 注意评测语言选C++，G++不支持%lf... 
		printf("%.3lf\n", res);
	}
	return 0;
}
