#include <iostream>
#include <cstdio>
using namespace std; 

// 这个题本质上就是个模板题，只不过它加了个将“最近一次一次查询的数插入到末尾”的操作，看了题解发现这个操作意思是单点修改
// 一个没有值的区间，也就是写个update就行了，而不是每次都去建树... 

typedef long long LL;
const int N = 2 * 1e5 + 10, M = N * 4;
struct Node {
	int l, r;
	LL mx;
} root[M];
void pushup(int now) {
	root[now].mx = max(root[now << 1].mx, root[now << 1 | 1].mx);
}
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) return;
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	pushup(now);
}
void update(int now, int L, int R, int val) {
	if (L <= root[now].l && root[now].r <= R) {
		root[now].mx = val;
		return;
	}
	int mid = (root[now].l + root[now].r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	if (L <= mid) update(ln, L, R, val);
	if (R > mid) update(rn, L, R, val);
	pushup(now);
}
LL query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].mx;
	if (L > root[now].r || R < root[now].l) return -1e9;
	return max(query(now << 1, L, R), query(now << 1 | 1, L, R));
}
char op[5];
int main() {
	int m, d, pres = 0, now, last = 0;
	scanf("%d%d", &m, &d);
	build(1, 1, N);
	while (m--) {
		scanf("%s%d", op, &now);
		if (*op == 'A') {
			last++;
			update(1, last, last, (now + pres) % d);
			pres = now;
		} else {
			printf("%lld\n", query(1, last - now + 1, last));
		}
	}
	return 0;
}
