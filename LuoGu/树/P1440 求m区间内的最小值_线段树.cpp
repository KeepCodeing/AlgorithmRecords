#include <iostream>
#include <cstdio>
using namespace std;

// 标签是DP或者单调队列，然而这两个都不会，干脆用线段树好了.. 
// 不用写pushdown，update... 
// 开O2勉强能过.. 

const int N = 2 * 1e6 + 10, M = N * 4;
struct Node {
	int l, r, mx;
} root[M];
void pushup(int now) {
	// 之前写成最大值了w... 
	root[now].mx = min(root[now << 1].mx, root[now << 1 | 1].mx);
}
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		scanf("%d", &root[now].mx);
		return;
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	pushup(now);
}
int query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].mx;
	if (L > root[now].r || R < root[now].l) return 1e9;
	return min(query(now << 1, L, R), query(now << 1 | 1, L, R));
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	printf("0\n");
	for (int i = 2; i <= n; i++) {
		// i之前没有m个数，那么只用从1扫到i - 1就行 
		if (i - m <= 0) printf("%d\n", query(1, 1, i - 1));
		else printf("%d\n", query(1, i - m, i - 1));
	}
	return 0;
}
