#include <iostream>
#include <cstdio>
using namespace std;

// 树状数组第一弹，其实之前已经写过了，这里再写一遍fuxi，顺便对比下和线段树的效率差距... 
// 似乎没有快多少，不过代码和内存确实比线段树少很多... 

const int N = 5 * 1e5 + 100;
int n, m;
int root[N];
int lowbit(int x) {
	return x & (-x);
}
void add(int idx, int val) {
	for (int i = idx; i <= n; i += lowbit(i)) root[i] += val;
}
int query(int end) {
	int ans = 0;
	for (int i = end; i; i -= lowbit(i)) ans += root[i];
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	int val;
	for (int i = 1; i <= n; i++) cin >> val, add(i, val);
	int op, x, y;
	while (m--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) add(x, y);
		// 注意这里左区间要-1... 
		else printf("%d\n", query(y) - query(x - 1));
	}
	return 0;
}
