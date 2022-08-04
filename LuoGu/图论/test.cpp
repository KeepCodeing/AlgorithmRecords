#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10, M = N * 4;
struct Node {
	int l, r;
	LL lz, sum;
} root[M];
void pushup(int now) {
	int ln = now << 1, rn = now << 1 | 1;
	root[now].sum = root[ln].sum + root[rn].sum;
}
void pushdown(int now) {
	if (root[now].lz) {
		int ln = now << 1, rn = now << 1 | 1;
		LL lz = root[now].lz, sum = root[now].sum;
		root[ln].lz += lz, root[rn].lz += lz;
		root[ln].sum += (root[ln].r - root[ln].l + 1) * lz;
		root[rn].sum += (root[rn].r - root[rn].l + 1) * lz;
		root[now].lz = 0;
	}
}
void build(int now, int left, int right) {
	root[now].l =left, root[now].r = right;
	if (left == right) {
		scanf("%d", &root[now].sum);
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
	pushdown(now);
	return query(now << 1, L, R) + query(now << 1 | 1, L, R);
}
int main() {
	return 0;
}
