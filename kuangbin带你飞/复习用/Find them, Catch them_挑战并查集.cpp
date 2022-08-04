#include <iostream>
#include <cstdio>
using namespace std;

// 不做会忘w，啊啊，算法对本five而言真的不是一个很好的出路呢... 

// 扩大空间，用来表示两个集合 
const int N = 100000 * 2 + 10;
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
		int a = anc(x), b = anc(y);
		if (a != b) bin[a] = b;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
char op[5];
int main() {
	int T, n, m, x, y;
	scanf("%d", &T);
	while (T--) {
		unionFind uf;
		scanf("%d%d", &n, &m);
		while (m--) {
			scanf("%s%d%d", &op, &x, &y);
			if (*op == 'D') {
				// 表示x，y不在一个集合 
				uf.uni(x + n, y);
				uf.uni(x, y + n); 
			} else {
				// 三种情况，在一个集合，不在一个集合和不确定... 
				if (uf.ask(x, y)) printf("In the same gang.\n");
				else if (uf.ask(x, y + n)) printf("In different gangs.\n");
				else printf("Not sure yet.\n");
			}
		}
	}
	return 0;
}
