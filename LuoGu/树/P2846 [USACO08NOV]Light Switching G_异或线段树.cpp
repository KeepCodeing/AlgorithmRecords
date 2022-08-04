#include <iostream>
#include <cstdio>
using namespace std;

// 应该是个异或线段树，起初灯都是暗的也就是说根节点全为0，然后开灯其实就是异或0变1,1边0
// 考虑了下根节点是否需要建树，可能单点线段树不需要，但是区间线段树要通过记录记录左右区间，所以
// 还是要建树... 

// 总体来说没什么大问题，编码速度似乎也有所提高，不够还是没搞清楚异或哪里...6月第一发AC，最近更多光顾的是vjudge... 
// 异或的解释：1^1=0,1^0=1,0^0=1，就是说如果和上次操作不同，就不进行改变，如果相同就是0变1,1变0了... 

const int N = 100000 + 10, M = N * 4;
struct Node {
	int l, r, lz, tot;
} root[M];
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		root[now].lz = root[now].tot = 0;
		return;
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	root[now].tot = root[ln].tot + root[rn].tot;
}
void pushdown(int now) {
	if (root[now].lz) {
		int ln = now << 1, rn = now << 1 | 1;
		// 注意这里的异或，是异或1，不是异或lazy_tag，因为lz是个不定的值，而我们要做的是将区间01互换，所以
		// 应该异或1，另外这里的tot应该是区间目前大小减去区间目前和，就可以做到统计1的和->统计0的和，后者相同.. 
		root[ln].lz ^= 1, root[ln].tot = (root[ln].r - root[ln].l + 1) - root[ln].tot;
		root[rn].lz ^= 1, root[rn].tot = (root[rn].r - root[rn].l + 1) - root[rn].tot;
		root[now].lz = 0;
	}
}
// 43 55
void update(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) {
		// 异或1...，这里修改也不是修改成某个值了，而是直接取反... 
		root[now].lz ^= 1;
		// 应该是赋值，不是加法... 
		root[now].tot = (root[now].r - root[now].l + 1) - root[now].tot;
		return;
	}
	int mid = (root[now].l + root[now].r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	// 注意递归前pushdown 
	pushdown(now);
	if (L <= mid) update(ln, L, R);
	if (R > mid) update(rn, L, R);
	root[now].tot = root[ln].tot + root[rn].tot;
}
int query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].tot;
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
