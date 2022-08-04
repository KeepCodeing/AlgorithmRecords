#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 做过的题，这个题输入的邻接矩阵，所以用prim做比较好呢... 
// 我困困，基本没什么思考能力了w 

// 太巩布了，就算程序打过了也搞了很长时间，主要是没看题目，POJ的测试数据很强，有很多组，然后就一直卡在这上面...
// 还有就是换行..，总体来说没什么问题w，不过POJ还是没有我想象的那么简单呢.. 

// 洛谷空间开小了RE了两次，其实这个题最多可能有5k个点，因为sum(1~100)... 
const int N = 5000;
struct g {
	int u, v, w;
	bool operator<(const g& gg) const {
		return w < gg.w;
	}
} graph[N];
struct unionFind {
	int bin[N];
	void initBin () {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (bin[x] != x) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		if (!ask(x, y)) bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	int n, w, cnt;
	// POJ上的数据有很多组，而洛谷只有一组... 
	while (~scanf("%d", &n)) {
		u.initBin();
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &w);
				// 连边的里技，看了下就是自不能和自己连，然后又是双向边，所以
				// 只用连一半，就是自己之后的边... 
				if (j > i) {
					graph[cnt].u = i, graph[cnt].v = j, graph[cnt].w = w;
					cnt++;
				}
			}
		}
		// 排序才想起来图存的方式错了... 
		sort(graph, graph + cnt);
		int res = 0;
		for (int i = 0; i < cnt; i++) {
			if (!u.ask(graph[i].u, graph[i].v)) {
				u.uni(graph[i].u, graph[i].v); 
				res += graph[i].w;
			}
		}
		// 注意多组数据换行.. 
		printf("%d\n", res);
	}
	return 0;
}
