#include <iostream>
#include <cstdio>
using namespace std;

// 一道很巧妙的题，这个题不是和普通并查集一样给两个点然后把这两个点连边， 而是说给两个点，这两个点没有关系（即这两个
// 点不能连边）。那么能够想到的思路是用两个并查集，存这两个点与两个不同根节点连边的情况，不过画了下图发现完全不可行。
// 第二个思路是将这些点都连在一个和数据完全没有关系的点上，对应不能连边。然而这个想法还是太naive且不完善，正确的思路
// 是用一个并查集维护两个集合，用uni(a, b + n)表示a和b不在一个集合，因为b+n是个不存在的点，然后用(a + n, b)表示b和a
// 不在一个集合，原因同上，这样就能对应前面那个所谓两个并查集的想法了，即分情况讨论。那么这里怎么查询呢？我们可以用
// ask(a, b)询问a，b是否在一个集合里，然后用ask(a, b + n)询问a, b是不是不在一个集合里，那么除了这两种情况外其他情况
// 都可以认为a和b这两个点还没有被加到连通块里，即a，b的集合不确定。
// 另外这个题用cin会TLE，所以得用scanf.. 

// 注意这里的乘二，因为还要表示点不存在的情况 
const int N = (100000 + 10) * 2;
char op[5];
int bin[N];
struct unionFind {
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		// 注意这里得先判断下两个点在不在一个连通块，不然会爆栈MLE 
		int a = anc(x);
		int b = anc(y);
		if (a != b) bin[a] = b;
		
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
};
void init_bin () {
	for (int i = 0; i < N; i++) bin[i] = i;
}
int main() {
	int T;
	scanf("%d", &T);
	unionFind u;
	while (T--) {
		int n, m, x, y;
		scanf("%d%d", &n, &m);
		init_bin();
		for(int i = 0; i < m; i++) {
			scanf("%s%d%d", op, &x, &y);
			if (*op == 'A') {
				// 如果x，y在一个集合里 
				if (u.ask(x, y)) printf("In the same gang.\n");
				// 如果x，y不在一个集合里 
				else if (u.ask(x, y + n) || u.ask(x + n, y)) printf("In different gangs.\n");
				// x或者y还没有出现过，就是结果不确定 
				else printf("Not sure yet.\n");
			} else {
				// 将x与y放入不同集合
				u.uni(y + n, x);
				// 将y与x放入不同集合
				u.uni(x  + n, y);  
			}
		}
	}
	return 0;
}
