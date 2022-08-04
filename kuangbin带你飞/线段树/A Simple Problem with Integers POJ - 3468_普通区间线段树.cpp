#include <iostream>
#include <cstdio>
using namespace std;

// 普通的区间线段树，要开LL 
// 产生了线段树太自闭先去做别的专题吧的想法...然后突然瞥到了错误...自闭... 

typedef long long LL;
const int N = 100000 + 10, M = N * 4;
// LL nums[N];
struct Node {
	int l, r;
	LL lz, sum;
} root[M];
void pushup(int now) {
	root[now].sum = root[now << 1].sum + root[now << 1 | 1].sum;
}
void pushdown(int now) {
	if (root[now].lz) {
		// 在自闭的边缘徘徊...一度以为POJ太司马了，原来是自己脑瘫..这里之前为了方便写成int了，没想到这成了
		// 其怎么也找不出来来错误...lz和sum都可能是long long，而其强转成int...不得不说线段树的题都错了非常
		// 多遍...注意洛谷上的粪数据完全可以AC，导致其一直以为是POJ的问题... 
		LL lz = root[now].lz, sum = root[now].sum;
		int ln = now << 1, rn = now << 1 | 1;
		root[ln].lz += lz, root[rn].lz += lz;
		root[ln].sum += (root[ln].r - root[ln].l + 1) * lz;
		root[rn].sum += (root[rn].r - root[rn].l + 1) * lz;
		root[now].lz = 0;
	}
}
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		// 可以节省空间的做法，直接输入叶子节点的值就行了 
		scanf("%lld", &root[now].sum);
		// root[now].sum = nums[left];
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
	// 这里写成了R，L...好在上了个厕所一瞬发现了，看来上厕所真能刷新状态w... 
	if (L <= mid) update(ln, L, R, val);
	if (mid < R) update(rn, L, R, val);
	pushup(now); 
}
LL query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].sum;
	if (L > root[now].r || R < root[now].l) return 0;
	// 差点又忘了pushdown... 
	pushdown(now);
	return query(now << 1, L, R) + query(now << 1 | 1, L, R);
}
char op[5];
int main() {
	int n, m, x, y, tt;
	LL val;
	scanf("%d%d", &n, &m);
	// for (int i = 1; i <= n; i++) scanf("%lld", &nums[i]);
	build(1, 1, n);
	while (m--) {
		// 人写傻了w，这里偏用cin输入字符而不是直接用字符串... 
		scanf("%s%d%d", op, &x, &y);
		if (*op == 'Q') {
			printf("%lld\n", query(1, x, y));
		} else {
			scanf("%lld", &val);
			// cout << val << endl;
			update(1, x, y, val);
		}
	}
	return 0;
}
//	while (m--) {
//		scanf("%d", &tt);
//		if (tt == 1) {
//			scanf("%d%d%lld", &x, &y, &val);
//			update(1, x, y, val);
//		} else {
//			scanf("%d%d", &x, &y);
//			printf("%lld\n", query(1, x, y));
//		}
//	}
