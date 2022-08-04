#include <iostream>
#include <cstdio>
using namespace std;
// 48 58
const int N = 1e5 + 10, M = 1e5 * 4;
typedef long long LL;
struct Node {
	int l, r;
	LL lz, sum;
} root[M];
void pushup(int now) {
	root[now].sum = root[now << 1].sum + root[now << 1 | 1].sum;
}
void pushdown(int now) {
	if (root[now].lz) {
		int ln = now << 1, rn = now << 1 | 1;
		// 注意类型w 
		LL lz = root[now].lz;
		root[ln].lz += lz, root[rn].lz += lz;
		root[ln].sum += (root[ln].r - root[ln].l + 1) * lz;
		root[rn].sum += (root[rn].r - root[rn].l + 1) * lz;
		root[now].lz = 0;
	}
}
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		root[now].lz = 0;
		scanf("%d", &root[now].sum);
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
		root[now].lz += val;
		root[now].sum += (root[now].r - root[now].l + 1) * val;
		return;
	}
	int mid = (root[now].l + root[now].r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	pushdown(now);
	if (L <= mid) update(ln, L, R, val);
	if (R > mid) update(rn, L, R, val);
	pushup(now);
}
LL query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].sum;
	if (L > root[now].r || R < root[now].l) return 0;
	// 注意pushdown w
	pushdown(now);
	return query(now << 1, L, R) + query(now << 1 | 1, L, R); 
}
int main() {
	int n, m, l, r, k, op;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while (m--) {
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1) {
			scanf("%d", &k);
			update(1, l, r, k);
		} else {
			printf("%lld\n", query(1, l, r));
		}
	}
	return 0;
}
