#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 似乎陷入了颓废的挣扎之中，现在大概是玩也玩不好，学也学不进的情况...那么这个题本质还是个
// 线段树的板子题，只不过其功能是修改区间为一个数，对于这种情况一般都是修改懒标记和pushup就行
// 根据题目的意思来，可能不需要考虑那么多东西罢... 

// 居然一次AC了（喜），那么前面那个题无限WA可能就是没有初始化和用的数据类型错误了... 

typedef long long LL;
const int N = 100000 + 10, M = N * 4;
struct Node {
	int l, r;
	LL sum, lz;
} root[M];
void pushup(int now) {
	root[now].sum = root[now << 1].sum + root[now << 1 | 1].sum;
}
void pushdown(int now) {
	if (root[now].lz) {
		// 注意类型 
		LL lz = root[now].lz, sum = root[now].sum;
		int ln = now << 1, rn = now << 1 | 1;
		// 注意下面三条语句，这表示了这个题的懒标记和求和题的不同
		// 即求和题为+=，而赋值题就是= 
		root[ln].lz = lz, root[rn].lz = lz;
		root[ln].sum = (root[ln].r - root[ln].l + 1) * lz;
		root[rn].sum = (root[rn].r - root[rn].l + 1) * lz;
		root[now].lz = 0;
	}
}
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		root[now].sum = 1;
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
		// 直接覆盖原区间的值，而不是加上，这里的加上是指懒标记和区间，而不是指下面的pushup，也就是说改了当前
		// 区间的值还是会影响到后续的区间的。这里区间和线段树不一样在于它更类似于当前节点修改为val，然后通过
		// pushdown将子节点也修改为val，而区间线段树是类似模拟将叶子节点修改为val，然后再传上来的过程... 
		root[now].sum = (root[now].r - root[now].l + 1) * val;
		root[now].lz = val;
		return;
	}
	int mid = (root[now].l + root[now].r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	pushdown(now);
	if (L <= mid) update(ln, L, R, val);
	if (mid < R) update(rn, L, R, val);
	pushup(now);
}
LL query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].sum;
	if (L > root[now].r || R < root[now].l) return 0;
	pushdown(now);
	return query(now << 1, L, R) + query(now << 1 | 1, L, R);
}
void init_root() {
	for (int i = 0; i < M; i++) root[i].sum = root[i].lz = root[i].l = root[i].r = 0;
}
int main() {
	int T, n, m, l, r, val;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		// 可能之前那个题WA是因为没有初始化？ 
		init_root();
		scanf("%d%d", &n, &m);
		// 差点忘了建树... 
		build(1, 1, n);
		// 将[l, r]区间的值更新为val 
		while (m--) {
			scanf("%d%d%d", &l, &r, &val);
			update(1, l, r, val);
		}
		// 毒瘤输出... 
		printf("Case %d: The total value of the hook is %d.\n", t, query(1, 1, n));
	}
	return 0;
} 
