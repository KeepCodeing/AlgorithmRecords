#include <iostream>
#include <cstdio>
using namespace std;
const int N = 200000 + 10, M = N * 4;
int nums[N];
struct Node {
	// 这个题本质就是单点修改线段树，因此不需要
	// pushdown和lazy tag.. 
	int l, r, mx;
} root[M];
void pushup(int now) {
	root[now].mx = max(root[now << 1].mx, root[now << 1 | 1].mx);
}
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		// 这里有种很神奇的操作，可以直接在到达叶子节点的时候输入叶子节点的值，而不是
		// 搞个数组存着... 
		root[now].mx = nums[left];
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
		// 只有值更大的时候才更新.. 
		root[now].mx = max(root[now].mx, val);
		return;
	}
	int mid = (root[now].l + root[now].r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	if (L <= mid) update(ln, L, R, val);
	if (mid < R) update(rn, L, R, val);
	pushup(now);
}
int query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].mx;
	if (L > root[now].r || R < root[now].l) return -1e9;
	// 没有pushdown了w，写着写着一个机灵w 
	return max(query(now << 1, L, R), query(now << 1 | 1, L, R));
}
int main() {
	int n, m, x, y;
	char c;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	build(1, 1, n);
	while (m--) {
		// 神奇的错误，因为前面输入带换行被scanf读到了因此出现了奇妙的bug..还有就是HDU似乎在维护，总之暂且评测不了了... 
		// 洛谷AC了，这证明单点线段树完全可以被区间线段树取代... 
		cin >> c;
		scanf("%d%d", &x, &y);
		if (c == 'Q') printf("%d\n", query(1, x, y));
		else update(1, x, x, y);
	}
	return 0;
}
