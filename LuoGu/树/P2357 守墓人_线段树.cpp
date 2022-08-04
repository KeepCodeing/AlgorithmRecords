#include <iostream>
#include <cstdio>
using namespace std;

// 线段树第七弹，这个题要用到区间修改线段树... 
// 写完了感觉还是存在些问题
// 首先还是赋值，这里下意识的把一些更新值直接写成了赋值，不过及时发现了
// 然后是更新和查询时的左右区间的问题，这里写成了单点修改线段树的left，right，mid，但是正如其前面说的
// 区间线段树除了建树要指定left和right，其它情况都是直接用结构体来的，所以这里应该直接传L，R，因为left，right
// 会随着层次的递进而缩减，还有mid，一定要明确这里是判断区间，而不是判断点
// 最后得提下这个题的主墓碑修改，这其实就是个单点修改的操作，对应的话就是区间为[1, 1]，这也说明了区间修改线段树
// 可以进行单点修改，不过一般单点修改区间查询还是用树状数组好... 

typedef long long LL;
const int N = 2 * 1e5 + 100, M = N * 4;
int arr[N];
struct Node {
	LL tot, lazy_tag;
	int left, right;
	Node (int left, int right, LL tot, LL lazy_tag) : left(left), right(right), tot(tot), lazy_tag(lazy_tag) {};
	Node () {};
} root[M];
void pushdown(int now) {
	Node *l_node = &root[now << 1], *r_node = &root[now << 1 | 1];
	int lazy_tag = root[now].lazy_tag;
	if (lazy_tag) {
		l_node->lazy_tag += lazy_tag, l_node->tot += (LL)(l_node->right - l_node->left + 1) * lazy_tag;
		r_node->lazy_tag += lazy_tag, r_node->tot += (LL)(r_node->right - r_node->left + 1) * lazy_tag;
		root[now].lazy_tag = 0;
	}
}
void build(int now, int left, int right) {
	if (left == right) {
		root[now] = Node(left, right, arr[left], 0);
		return;
	}
	int mid = (left + right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	root[now].left = left, root[now].right = right;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	root[now].tot = root[l_node].tot + root[r_node].tot;
}
void update(int now, int L, int R, int val) {
	if (L <= root[now].left && root[now].right <= R) {
		root[now].tot += (LL)(root[now].right - root[now].left + 1) * val;
		root[now].lazy_tag += val;
		return;
	}
	int mid = (root[now].left + root[now].right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	pushdown(now);
	if (L <= mid) update(l_node, L, R, val);
	if (R > mid) update(r_node, L, R, val);
	root[now].tot = root[l_node].tot + root[r_node].tot;
}
LL query(int now, int L, int R) {
	if (L <= root[now].left && root[now].right <= R) return root[now].tot;
	if (L > root[now].right || R < root[now].left) return 0;
	// int mid = (root[now].left + root[now].right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	pushdown(now);
	return query(l_node, L, R) + query(r_node, L, R);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	build(1, 1, n);
	int op, left, right, val;
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &left, &right, &val);
			update(1, left, right, val);
		} else if (op == 2 || op == 3) {
			scanf("%d", &val);
			if (op == 3) val = -val;
			update(1, 1, 1, val);
		} else if (op == 4) {
			scanf("%d%d", &left, &right);
			printf("%lld\n", query(1, left, right));
		} else {
			// 求主墓碑的风水值
			printf("%lld\n", query(1, 1, 1));
		}
	}
	return 0;
}
