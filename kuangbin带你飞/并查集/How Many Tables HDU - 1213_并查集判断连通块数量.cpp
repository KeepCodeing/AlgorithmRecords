#include <iostream>
#include <cstdio>
using namespace std;

// 并查集判断连通块数量，一般可以通过bin[i] == i的方式来判断有多少个根节点，有多少个根节点就意味着有多少颗
// 树，即多少个连通块...但是我们也可以用类似网格图的方式来统计，假设一开始给了N个点，那就是有N个连通块，每
// 连通两个未连通的点连通块数量就-1，最后剩下的值就是所需的桌子数量了，不过其也不太确定，好像这样有问题，
// 先用普通方法好了...另外这个题DFS染色也可以，而且更简单... 

const int N = 1000 + 10;
struct unionFind {
	int bin[N];
	void _init() {
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
	int getcnt(int n) {
		int cnt = 0;
		// 这里写成bin[i] == i和这种形式都AC了，实在太奇妙了，上一个题过不了，这两种方法似乎没有区别，那就统一成这样好了... 
		for (int i = 1; i <= n; i++) cnt += anc(i) == i;
		return cnt;
	}
};
unionFind uf;
int main() {
	int T, n, m, ut, vt;
	scanf("%d", &T);
	while (T--) {
		uf._init();
		scanf("%d%d", &n, &m);
		while (m--) {
			scanf("%d%d", &ut, &vt);
			uf.uni(ut, vt); 
		}
		printf("%d\n", uf.getcnt(n));
	}
	return 0;
}
