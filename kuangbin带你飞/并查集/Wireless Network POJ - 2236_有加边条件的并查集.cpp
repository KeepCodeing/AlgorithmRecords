#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

// 最短路做了十二题痿了w，来试试并查集，这个题十天前做过，留下了很不好的印象ww，其自己做的时候是直接把所有能连的
// 边算出来，然后修复时直接连起来了，但是看别人代码好像是每次都判断...那这里就用后者了w 

// 这个题不能连接还没修好的电脑，其之前写的似乎没有考虑，现在写的这个也没有考虑ww... 

// TLEw，交了别人的代码就AC了..或许函数比结构体快... 

const int N = 1001 + 10;
struct Pos {
	int x, y;
} pos[N];
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
		int xt = anc(x), yt = anc(y);
		if (xt != yt) bin[xt] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
bool cpl(int x1, int y1, int x2, int y2, double d) {
	// printf("%.3lf\n", sqrt((x1 - x2 + .0) * (x1 - x2) + (y1 - y2 + .0) * (y1 - y2)));
	return (x1 - x2 + .0) * (x1 - x2) + (y1 - y2 + .0) * (y1 - y2) <= d * d;
}
unionFind uf;
bool vis[N];
int fix[N];
int main() {
	int n, u, v, cnt = 1;
	double d;
	scanf("%d%lf", &n, &d);
	for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
	char op[5];
	while (~scanf("%s", &op)) {
		if (*op == 'O') {
			cin >> u;
			// 标记已经修好的电脑 
			if (vis[u]) continue;
			vis[u] = true;
			// 将已经修好的电脑存起来，不然每次修都去枚举会TLE 
			fix[cnt++] = u;
			for (int i = 1; i < cnt; i++) 
				// 如果在范围内就进行合并 
				if (fix[i] != u && cpl(pos[u].x, pos[u].y, pos[fix[i]].x, pos[fix[i]].y, d)) uf.uni(u, fix[i]);
		} else {
			cin >> u >> v;
			printf("%s\n", uf.ask(u, v) ? "SUCCESS" : "FAIL");
		}
	}
	return 0;
}
