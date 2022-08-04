#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// 感觉是一道很有意思的题，这个题给的桩的坐标可以看成是点，然后给的两个桩有连接就是说这两个点之间有边，边的长度就是
// 这两个点的距离...手玩了下发现给的图可能是个森林，然后每个连通块其实就代表里面有猫，要使得花费的圣水最小其实就是说
// 要去掉这个连通块里的一条最小边..那么存在连通块或者说整个图形成了环路的前提就是两个点的公共祖先相同，因此一个可能的
// 思路是在连边的过程中判断当前两个点是否成环了， 然后统计最短边，如果出现了环就加上之前统计的最短边长度并重置最短边... 

// 坠毁w，对于一种特殊的图，类似一个圆被中间切开，这张图有两个环，左边一个右边一个，这时可能可以统计出左边图的最短边
// 和右边图的最短边，但是我们不一定就只能去除这两个最短边，而是可以选择把中间那条边去掉，然后再去掉左右的最短边... 
// 那这种算法对于森林，或者只有一个连通块的图都是可行的，但是对于上面所说的这种图无法作用...

// 对每个连通块来说，都一定存在一条最短边，多个连通块可以看成是去掉最后连接边或者最短边，有几个连通块就要去几个最短边
// 看起来还是不太行，这样对森林情况就又不适用了... 
// 用一种神奇的方式过了样例，然而还是坠毁了ww 

const int N = 10000 + 10, M = N * 2, INF = 1e9 + .0;
vector<double > vec;
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
		if (!ask(x, y)) bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	int getCnt(int n) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (bin[i] == i) cnt++;
		}
		return cnt;
	}
};
double cpl(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2 + .0) + (y1 - y2) * (y1 - y2 + .0));
}
unionFind uf;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &pos[i].x, &pos[i].y);
	int u, v;
	double res = 0, mDist = INF;
	int cnt = 0;
	while (m--) {
		scanf("%d%d", &u, &v);
		if (!uf.ask(u, v)) {
			uf.uni(u, v); 
			// printf("%.3lf\n", cpl(pos[u].x, pos[u].y, pos[v].x, pos[v].y));
			mDist = min(mDist, cpl(pos[u].x, pos[u].y, pos[v].x, pos[v].y));
		} else {
			cnt++;
			// printf("%.3lf    %.3lf\n", mDist, cpl(pos[u].x, pos[u].y, pos[v].x, pos[v].y));
			vec.push_back(mDist);
			vec.push_back(cpl(pos[u].x, pos[u].y, pos[v].x, pos[v].y));
			res += mDist;
			mDist = INF;
		}
		// uf.uni(u, v);
		// printf("%.3lf\n", cpl(pos[u].x, pos[u].y, pos[v].x, pos[v].y));
		// mDist = min(mDist, cpl(pos[u].x, pos[u].y, pos[v].x, pos[v].y));
	}
	int vLen = vec.size();
	sort(vec.begin(), vec.end());
	if (uf.getCnt(n) == 1) {
		res = .0;
		for (int i = 0; i < cnt; i++) res += vec[i];
	}
	printf("%.3lf", res);
	return 0;
}
