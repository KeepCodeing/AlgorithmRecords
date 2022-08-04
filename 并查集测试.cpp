#include <iostream>
#include <cstdio>
using namespace std;

// 本来想试下在查祖宗的过程中输入路径上的节点的，结果发下自己写的路径压缩，
// 要是想这样写就不能写路径压缩，也就是每次都是n的复杂度，那这样就是暴力了..
// 也想不到那个题的正解是什么，总之和做过的板子题都不怎么一样... 

const int N = 5000 + 10;
struct unionFind {
	int bin[N];
	unionFind() {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x, bool f) {
		if (x != bin[x]) bin[x] = anc(bin[x], f);
		if (f) printf("%d\n", bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		int a = anc(x, false), b = anc(y, false);
		if (a != b) bin[a] = b;
	}
	bool ask(int x, int y) {
		return anc(x, true) == anc(y, true);
	}
};
int main() {
	int n, m, p, ut, vt;
	scanf("%d%d%d", &n, &m, &p);
	unionFind uf;
	while (m--) {
		scanf("%d%d", &ut, &vt);
		uf.uni(ut, vt); 
	}
	while (p--) {
		scanf("%d%d", &ut, &vt);
		if (uf.ask(ut, vt)) puts("Yes");
		else puts("No");
		break;
	}
	return 0;
}
