#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// 被题意绕进去变成池沼了w，就算在最小生成树专题下也完全没有联想到这个题和最小生成树有什么关系...
// 抽象下模型可以得到这么些信息：新的图里没有环，要使得剩下来的边边权和最小。说白了就是要做这个
// 图的最大边权树，因为拆去的边的权值和越大，剩下来的图的边的权值和就越小，其一直纠结于一个连通块
// 去掉最小边，事实上画图也确实如此...而且类似的题也做过，那个题和这个题要求的是反着的，那个题要使得
// 去掉的边的和最大，那也就是留下来的边的和最小，注意这里和这个题的区别，那个题要求的是去掉的最大边权和
// 而这个题要求的是去掉的边权和最小，也就是反过来了..
// 这么看最小生成树的题不止一种类型了，常见的最小生成树的题都是使得边权和最小，而这个题虽然也是要求边权和
// 最小，但却不是求整棵树的边权和，准确来说是去掉环，还要保证去掉的边边权最大.. 

// 总结：最小生成树题型还是没搞的很透彻，而且被题意误导了..现在接触到的最小生成树题目类型有：裸题，就是求
// 最短边权和，变形题，要使得被去掉的边和最大，这个是要使得被去掉的边和最小，然后还有在裸题的基础上要求加边
// 长度的题，聪明的猴子那个题是先把边算出来，然后算最小生成树最长边，最后对比有多少值大于等于最长边.. 

// M最好开大点... 
const int N = 10000 + 10, M = N * 5;
struct Pos {
	int x, y;
} pos[N];
struct G {
	int u, v;
	// 这里居然写成了int... 
	double w;
	G (int u, int v, double w) : u(u), v(v), w(w) {};
	G () {};
	bool operator<(const G& g) const {
		return w > g.w;
	}
} graph[M];
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2 + .0) + (y1 - y2) * (y1 - y2 + .0));
}
struct unionFind {
	int bin[N];
	unionFind () {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (bin[x] != x) bin[x] = anc(bin[x]);
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
unionFind u;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
	int cnt = 0, ut, vt;
	double temp, sum = 0, tot = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &ut, &vt);
		temp = cpl(pos[ut].x, pos[ut].y, pos[vt].x, pos[vt].y);
		// 统计整个图的边权和... 
		sum += temp;
		graph[cnt++] = G(ut, vt, temp);
	}
	sort(graph, graph + cnt);
	// 建最大边权树 
	for (int i = 0; i < cnt; i++) {
		if (!u.ask(graph[i].u, graph[i].v)) {
			u.uni(graph[i].u, graph[i].v);
			tot += graph[i].w; 
		}
	}
	// 最后要拆的最短边的和就是整个的和减去保留下来的最长边的和... 
	printf("%.3lf", sum - tot);
	return 0;
}
