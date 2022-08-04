#include <cstdio>
#include <iostream>
using namespace std;

// 写了一天vjudge上的题单的搜索专题，写了五个题，感觉比较有价值...有几天没写线段树了，fuxi下，越fuxi，越fuxiw 
// 总结：还是有所遗忘，比如忘了加return，忘了记录左右区间大小，总共花了18分钟才把代码写完（其中还有2，3分钟IDE挂了w）
// 还有就是写代码的错误率太高w，写一个字错一个..，感觉fuxi还是很有必要的，当然也可能是状态不行（虚心） 
// 还爆了次零，总之线段树代码大体上会了，不过还是不能在短时间内完全没有错误的写出来，虽然应该已经写了很多次了w 

typedef long long LL;
const int N = 2 * 1e5 + 10, M = N * 4;
int arr[N];
struct Node {
	int l, r;
	LL lz, tot;
} root[M];
// 43 01
void build(int now, int left, int right) {
	// 忘了记录左右区间大小 
	root[now].l = left, root[now].r = right;
	if (left == right) {
		root[now].tot = arr[left];
		root[now].lz = 0;
		return;
	}
	int mid = (left + right) >> 1;
	int l = now << 1, r = now << 1 | 1;
	build(l, left, mid);
	build(r, mid + 1, right);
	root[now].tot = root[l].tot + 0ll + root[r].tot;
}
void pushdown(int now) {
	if (root[now].lz) {
		int l = now << 1, r = now << 1 | 1;
		root[l].lz += root[now].lz, root[l].tot += (root[l].r - root[l].l + 1) * root[now].lz;
		root[r].lz += root[now].lz, root[r].tot += (root[r].r - root[r].l + 1) * root[now].lz;
		root[now].lz = 0;
	}
}
void update(int now, int L, int R, int val) {
	if (L <= root[now].l && root[now].r <= R) {
		// 写快了写成了root[now].r - root[now].r... 
		root[now].tot += (root[now].r - root[now].l + 1 + 0ll) * val;
		root[now].lz += val;
		// 忘了加return 
		return;
	}
	int mid = (root[now].l + root[now].r) >> 1;
	int l = now << 1, r = now << 1 | 1;
	pushdown(now);
	if (L <= mid) update(l, L, R, val);
	if (R > mid) update(r, L, R, val);
	root[now].tot = root[l].tot + 0ll + root[r].tot;
}
LL query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].tot;
	if (L > root[now].r || R < root[now].l) return 0;
	int l = now << 1, r = now << 1 | 1;
	pushdown(now);
	return query(l, L, R) + query(r, L, R);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	build(1, 1, n);
	int op, l, r, k;
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &l, &r, &k);
			update(1, l, r, k);
		} else if (op == 2 || op == 3) {
			scanf("%d", &k);
			if (op == 3) k = -k;
			update(1, 1, 1, k);
		} else if (op == 4) {
			scanf("%d%d", &l, &r);
			printf("%lld\n", query(1, l, r));
		} else {
			printf("%lld\n", query(1, 1, 1));
		}
	}
	return 0;
}
