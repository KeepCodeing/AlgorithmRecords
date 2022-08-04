#include <iostream>
#include <cstdio>
using namespace std;

// 一道并查集求反集的题目，和其昨天在vjudge做的一个题一样，不过这个题要求有多少个团伙，普通并查集统计连通块的
// 数量就是判断有多少个元素的根是它自己，这个题也可以这样做，虽然不是很明白为什么...，另外这个题还加了个直接
// 合并，也就是不求反集.. 

const int N = 1000 * 2 + 10;
char op[5];
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
		// 这里必须这样写，否则会爆栈 
		if (anc(x) != anc(y)) bin[anc(x)] = y;
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	int getAns(int n) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) cnt += bin[i] == i;
		return cnt;
	}
};
unionFind u;
int main() {
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%s%d%d", &op, &x, &y);
		// 求反集，注意这里和vjudge上的写法不同，是将可能的集合内元素统一连边到集合外，而vjudge上正好相反，
		// 但是这个题那样写就会WA，而其改了下vjudge的写法也能过，所以统一用这个写法好了... 
		if (*op == 'E') u.uni(y + n, x), u.uni(x + n, y); 
		// 合并队友
		else u.uni(x, y); 
	}
	printf("%d", u.getAns(n));
	return 0;
}
