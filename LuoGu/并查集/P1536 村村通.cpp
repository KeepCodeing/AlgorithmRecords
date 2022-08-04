#include <iostream>
#include <cstdio>
using namespace std; 

// 这个题就是问给定一个无向图，求有多少个点无法到达其它点。 
// 思路是用并查集，对每个点进行连边，如果有点连得边是自己，就说明它没办法到别的点，最后答案
// 要减一，因为三个点两条边连就行。 
// 另外想起来个题要求输入的点是否成环，那个题也可以用并查集来做，思路就是如果两个点有共同祖先，那么他们相连
// 必定成环。
// 还有就是其在看到最小生成树的标签后想了下怎么用生成树做。生成树有个特点，就是要求所有点都连通，和这个题就
// 很类似，它的思想就是如果当前添加的点不在生成树集合里，就把它连到生成树上，然后生成树上的顶点数加1，如果
// 最后所有点都在生成树上，即生成树上的点的数量等于给出的点的数量，那么这个生成树就是合法的，否则就是非法的。
// 于是乎我们可以把这个过程用到这个题里，最后不连通的点的数量应该就是给出的顶点数减去生成树上的顶点数。 

const int N = 1010;
struct unionFind {
	int bin[N];
	void initU() {
		for (int i = 0; i < N; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		// 并查集板子这里经常写成bin[anc(y)]，不过其实也不影响什么，因为祖宗的祖宗就是它自己 
		bin[anc(x)] = anc(y);
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
unionFind u;
int main() {
	int n, m, cnt, x, y;
	while (true) {
		cnt = 0;
		scanf("%d", &n);
		if (!n) return 0;
		scanf("%d", &m);
		u.initU();
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &x, &y);
			if (!u.ask(x, y)) {
				// 连边，统计生成树上的点数 
				cnt++, u.uni(x, y); 
			}
		}
		// 最后要-1，因为三个点两条边就能连通 
		printf("%d\n", n - cnt - 1);
	}
	return 0;
}
