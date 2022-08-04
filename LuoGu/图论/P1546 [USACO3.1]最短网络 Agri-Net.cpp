#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// 裸的最小生成树，不过要注意输入的是一个邻接矩阵，而且是双向图，因此只需要读一半的数据就行 

const int N = 210 * 210;
struct web {
	int u, v, w;
//	web (int u, int v, int w) : u(u), v(v), w(w) {};
//	web () {};
	bool operator<(const web& wb) const {
		return w < wb.w;
	}
	
} wweb[N];
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
//int bin[N];
//int findU(int x) {
//	if (x != bin[x]) bin[x] = findU(bin[x]);
//	return bin[x];
//}
//void uni(int x, int y) {
//	int a = findU(x), b = findU(y);
//	bin[a] = b;
//}
//bool cmp(web a, web b) {
//    return a.w < b.w;
//}
unionFind u;
int main() {
	int n, wt, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &wt);
			if (j > i) {
				wweb[cnt].u = i;
				// 因为压行连了两次u边没管v边，随后一直在查错，一瞬成为最幸福的人，主要还是题解就在眼前
				// 没心思管自己的实现呢... 
				wweb[cnt].v = j;
				wweb[cnt].w = wt;
				cnt++;
			}
		}
	}
	sort(wweb, wweb + cnt);
	int res = 0;
	for (int i = 0; i < cnt; i++) {
		if (!u.ask(wweb[i].u, wweb[i].v)) {
			res += wweb[i].w;
			u.uni(wweb[i].u, wweb[i].v);

		}
	}
	cout << res;
	return 0;
}
