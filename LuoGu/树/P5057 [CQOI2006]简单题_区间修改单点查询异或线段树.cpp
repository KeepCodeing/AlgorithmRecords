#include <iostream>
#include <cstdio>
using namespace std;

// 比较奇妙的一个题，这个题是区间修改，单点查询..本质上还是个异或线段树，只不过要改下查询.. 
// 说是这样说，不过真写成单点查询还是TLE，而且不知道为什么RE了w，除了把query改成带点查询以外，这个题几乎和
// 异或线段树没有差别... 

// 交了三发，50w 

// 49 00

// 这里不知道为什么RE了，所以M无脑开大... 
const int N = 1e5 + 10, M = 1e6 * 5 + 10;
struct Node {
	int l, r, lz, val;
} root[M];
void pushup(int now) {
	root[now].val = root[now << 1].val + root[now << 1 | 1].val;
}
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		root[now].lz = 0;
		root[now].val = 1;
		return;
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	// 这里甚至不用pushup，因为就只有查询单点值，然而其发现其程序还是需要w，因为其做的就是单点查询
	// 而如果没一个值标记单点值的话就没办法查答案了... 
	pushup(now);
}

void pushdown(int now) {
	if (root[now].lz) {
		int ln = now << 1, rn = now << 1 | 1;
		root[ln].lz ^= 1, root[rn].lz ^= 1;
		root[ln].val = (root[ln].r - root[ln].l + 1) - root[ln].val;
		root[rn].val = (root[rn].r - root[rn].l + 1) - root[rn].val;
		root[now].lz = 0;
	}
}
void update(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) {
		root[now].lz ^= 1;
		root[now].val = (root[now].r - root[now].l + 1) - root[now].val;
		return;
	}
	int mid = (root[now].l + root[now].r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	pushdown(now);
	if (L <= mid) update(ln, L, R);
	if (R > mid) update(rn, L, R); 
	pushup(now);
}
int ans;
void query(int now, int L, int R, int idx) {
	if (L > root[now].r || R < root[now].l) return;
	// 单点查询，这里一定会走到idx这个叶子节点，于是O2也TLE了w，应该可以优化呢... 
	if (root[now].l == root[now].r && root[now].l == idx) {
		ans = root[now].val;
		return;	
	}
	int ln = now << 1, rn = now << 1 | 1;
	pushdown(now);
	query(ln, L, R, idx), query(rn, L, R, idx);
}
int main() {
	int n, m, op, l, r;
	scanf("%d%d", &n, &m);
	build (1, 1, n);
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &l, &r);
			update(1, l, r);
		} else {
			scanf("%d", &l);
			query(1, 1, n, l);
			// 注意答案要取反，因为pushdown执行不到叶子节点上.. 
			printf("%d\n", !ans);
		}
	}
	return 0;
}
