#include <iostream>
#define endl '\n'
using namespace std;

// https://www.luogu.com.cn/problem/P3372

typedef long long LL;
const int N = 1e5 * 4 + 10;
struct Node {
	int l, r;
	LL val, lz;
} root[N];

void pushup(int now) {
	root[now].val = root[now << 1].val + root[now << 1 | 1].val;
}

void build(int now, int l, int r) {
	root[now].l = l, root[now].r = r;
	if (l == r) {
		cin >> root[now].val;
		return;
	}
	int mid = (l + r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, l, mid);
	build(rn, mid + 1, r);
	pushup(now);
}

void pushdown(int now) {
	if (root[now].lz) {
		int ln = now << 1, rn = now << 1 | 1;
		LL lz = root[now].lz;
		root[ln].lz += lz, root[rn].lz += lz;
		root[ln].val += (root[ln].r - root[ln].l + 1) * lz;
		root[rn].val += (root[rn].r - root[rn].l + 1) * lz;
		root[now].lz = 0;
	}
}

void update(int now, int L, int R, int val) {
	if (L <= root[now].l && root[now].r <= R) {
		root[now].lz += val;
		root[now].val += (root[now].r - root[now].l + 1) * val;
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
	if (L <= root[now].l && root[now].r <= R) return root[now].val;
	if (L > root[now].r || R < root[now].l) return 0;
	pushdown(now);
	return query(now << 1, L, R) + query(now << 1 | 1, L, R);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, op, x, y, k;
	cin >> n >> m;
	build(1, 1, n);
	while (m--) {
		cin >> op >> x >> y;
		if (op == 1) cin >> k, update(1, x, y, k);
		else cout << query(1, x, y) << endl;
	}
	return 0;
}
