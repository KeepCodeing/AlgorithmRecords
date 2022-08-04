#include <iostream>
#include <cstdio>
using namespace std;

// LeetCode上写滑动窗口的时候发现单点修改线段树差不多都忘了w，来复习下应用面更广的区间修改 
// fuxi了遍没有问题，感觉以后都想把pushup和pushdown写完再说后面的，不然总是想到了才写...
// 还有就是query里的pushdown很容易忘记... 

typedef long long LL;
const int N = 1e5 + 10, M = N * 4;
LL nums[N];
struct Node {
	int l, r;
	LL sum, lz;	
} root[M];
void pushup(int now) {
	root[now].sum = root[now << 1].sum + root[now << 1 | 1].sum;
}
void pushdown(int now) {
	if (root[now].lz) {
		int ln = now << 1, rn = now << 1 | 1;
		root[ln].lz += root[now].lz, root[rn].lz += root[now].lz;
		root[ln].sum += (root[ln].r - root[ln].l + 1) * root[now].lz;
		root[rn].sum += (root[rn].r - root[rn].l + 1) * root[now].lz;
		root[now].lz = 0;
	}
}
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		root[now].sum = nums[left];
		root[now].lz = 0;
		return;
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	pushup(now);
}
void update(int now, int L, int R, int val) {
	if (L <= root[now].l && root[now].r <= R) {
		root[now].sum += (root[now].r - root[now].l + 1) * val;
		root[now].lz += val;
		return;
	}
	int mid = (root[now].r + root[now].l) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	pushdown(now);
	if (L <= mid) update(ln, L, R, val);
	if (mid < R) update(rn, L, R, val);
	pushup(now);
}
LL query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].sum;
	if (L > root[now].r || R < root[now].l) return 0;
	int ln = now << 1, rn = now << 1 | 1;
	// query里很容易忘记pushdown... 
	pushdown(now);
	return query(ln, L, R) + query(rn, L, R);
}
int main() {
	int n, m, op, l, r, k;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	build(1, 1, n);
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &l, &r, &k);
			update(1, l, r, k);
		} else {
			scanf("%d%d", &l, &r);
			printf("%lld\n", query(1, l, r));
		}
	}
	return 0;
}
/*
9 6
7 9 8 4 4 5 4 2 7
0 7 9
1 4 9
0 3 6
2 9 -6
2 3 -3
1 1 9
*/
