#include <iostream>
#include <cstdio>
using namespace std;

// 和刚刚做的那个题一样w，就当复习罢w 
// 一瞬切完w，不过忘了初始化区间值w... 

const int N = 1e5 + 10, M = N * 4;
struct Node {
	int l, r, lz, sum;
} root[M];
// 33 42
void pushup(int now) {
	root[now].sum = root[now << 1].sum + root[now << 1 | 1].sum;
}
void build(int now, int left, int right ) {
	// 指定左右区间，我忘记了啊ww，不指定左右区间就会RE... 
	root[now].l = left, root[now].r = right;
	if (left == right) {
		root[now].lz = root[now].sum = 0;
		return;
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	pushup(now);
}
void pushdown(int now) {
	if (root[now].lz) {
		int ln = now << 1, rn = now << 1 | 1;
		root[ln].lz ^= 1, root[ln].sum = (root[ln].r - root[ln].l + 1) - root[ln].sum;
		root[rn].lz ^= 1, root[rn].sum = (root[rn].r - root[rn].l + 1) - root[rn].sum;
		root[now].lz = 0;
	}
}
void update(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) {
		root[now].lz ^= 1;
		root[now].sum = (root[now].r - root[now].l + 1) - root[now].sum;
		return;
	}
	int mid = (root[now].l + root[now].r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	pushdown(now);
	if (L <= mid) update(ln, L, R);
	if (R > mid) update(rn, L, R);
	pushup(now);	
}
int query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].sum;
	if (L > root[now].r || R < root[now].l) return 0;
	int ln = now << 1, rn = now << 1 | 1;
	pushdown(now);
	return query(ln, L, R) + query(rn, L, R);
}
int main() {
	int n, m, op, l, r;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while (m--) {
		scanf("%d%d%d", &op, &l, &r);
		if (!op) update(1, l, r);
		else printf("%d\n", query(1, l, r));
	}
	return 0;
}
