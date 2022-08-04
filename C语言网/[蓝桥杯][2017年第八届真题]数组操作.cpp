#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const int N = 4e5 + 10;
struct Node {
	int l, r;
	LL lz, sum;
} root[N];
void pushup(int now) {
	root[now].sum = root[now << 1].sum + root[now << 1 | 1].sum;
}
void pushdown(int now) {
	if (root[now].lz) {
		LL lz = root[now].lz, sum = root[now].sum;
		int ln = now << 1, rn = now << 1 | 1;
		root[ln].lz += lz, root[rn].lz += lz;
		root[ln].sum += (root[ln].r - root[ln].l + 1) * lz;
		root[rn].sum += (root[rn].r - root[rn].l + 1) * lz;
		root[now].lz = 0;
	}
}
void build(int now, int l, int r) {
	root[now].l = l, root[now].r = r;
	if (l == r) {
		scanf("%lld", &root[now].sum);
		return;
	}
	int mid = (l + r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, l, mid);
	build(rn, mid + 1, r);
	pushup(now);
}
void update(int now, int L, int R, int val) {
	if (L <= root[now].l && root[now].r <= R) {
		root[now].sum += (root[now].r - root[now].l + 1) * val;
		root[now].lz += val; 
		return;
	}
	pushdown(now);
	int mid = (root[now].l + root[now].r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	if (L <= mid) update(ln, L, R, val);
	if (R > mid) update(rn, L, R, val);
	pushup(now);
}
LL query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].sum;
	if (L > root[now].r || R < root[now].l) return 0;
	pushdown(now);
	return query(now << 1, L, R) + query(now <<  1 | 1, L, R);
}
int main() {
	int ce, op, l, r, d, l1, l2, r1, r2;
	scanf("%d", &ce);
	int n, m;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &l, &r, &d);
			update(1, l, r, d);
		} else if (op == 2) {
			scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
			
		} else {
			scanf("%d%d", &l, &r);
			printf("%lld", query(1, l, r));
		}
		puts("");
	}
	return 0;
}
