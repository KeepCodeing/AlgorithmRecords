#include <iostream>
#include <cstdio>
using namespace std;

// 线段树复习，没有说很长时间没打，甚至说只是今天没打而已ww，总之线段树还是很有意思的，多打几遍应该没有坏处w 

typedef long long LL;
const int N = 1e5 + 10, M = N * 4;
int arr[N];
struct Node {
	// 保险开LL 
	LL tot, lazy_tag;
	int left, right; 
	Node (int tot, int lazy_tag) : tot(tot), lazy_tag(lazy_tag) {};
	Node () {};
} root[M];
void pushdown(int now) {
	if (root[now].lazy_tag) {
		int lz = root[now].lazy_tag;
		Node *lf = &root[now << 1], *rt = &root[now << 1 | 1];
		// 又忘了加等于，好在一瞬发现了.. 
		lf->lazy_tag += lz, lf->tot += (lf->right - lf->left + 1) * lz;
		rt->lazy_tag += lz, rt->tot += (rt->right - rt->left + 1) * lz; 
		root[now].lazy_tag = 0;
	}
}
void build(int now, int left, int right) {
	// 这样写return就不用写left，right赋值了.. 
	root[now].left = left, root[now].right = right;
	if (left == right) {
		root[now].tot = arr[left], root[now].lazy_tag = 0;
		return;
	}
	int mid = (left + right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	root[now].tot = root[l_node].tot + root[r_node].tot;
}
void update(int now, int L, int R, int val) {
	if (L <= root[now].left && root[now].right <= R) {
		root[now].lazy_tag += val;
		// 看起来这里很容易写成赋值..，其一开始理解可能就有些问题，现在得改成将当前节点的值加上模拟修改的值的理解才行.. 
		root[now].tot += (root[now].right - root[now].left + 1) * val;
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
	int mid = (root[now].left + root[now].right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	pushdown(now);
	return query(l_node, L, R) + query(r_node, L, R);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	build(1, 1, n);
	int op, x, y, k;
	while (m--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			scanf("%d", &k);
			update(1, x, y, k);
		} else {
			printf("%lld\n", query(1, x, y));
		}
	}
	return 0;
}
