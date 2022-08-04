#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100011;
struct unionFind {
	int bin[N], sz[N], mx;
	unionFind () {
		mx = 0;
		for (int i = 0; i < N; i++) bin[i] = i, sz[i] = 1;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		int a = anc(x), b = anc(y);
		if (a != b) {
			sz[b] += sz[a];
			mx = max(mx, sz[b]);
			bin[a] = b;
		}
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	int getmax() {
		return mx;
	}
};
int main() {
	int n, x, y;
	while (scanf("%d", &n) != EOF) {
		unionFind uf;
		for (int i = 1; i <= n; i++) scanf("%d%d", &x, &y), uf.uni(x, y);
		printf("%d\n", uf.getmax());
	}
	return 0;
}
