#include <iostream>
#include <cstdio>
using namespace std;

// 洛谷做过的题，思路就是记录两个最值就行了... 

typedef pair<int, int > PII;
const int N = 50000 + 10, M = N * 4;
struct Node {
	// 不用开long long 
	int l, r, hei, low;
} root[M];
void pushup(int now) {
	// 记录最高的和最矮的牛的高度 
	root[now].hei = max(root[now << 1].hei, root[now << 1 | 1].hei);
	root[now].low = min(root[now << 1].low, root[now << 1 | 1].low);
}
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		// 直接输入叶子节点的值，很方便，而且省空间 
		scanf("%d", &root[now].hei);
		// 默认叶子节点的牛既是最高的，也是最矮的 
		root[now].low = root[now].hei;
		// 忘了return ww
		return; 
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	pushup(now);
}
// 甚至不用写update和pushdown...
PII query(int now, int L, int R) {
	// 找到了要的区间返回这个区间的最大值和最小值，用来和后面的区间进行对比 
	if (L <= root[now].l && root[now].r <= R) return PII(root[now].hei, root[now].low);
	// 规定first为最大值，second为最小值，那么没找到就返回一个极端值就行了 
	if (L > root[now].r || R < root[now].l) return PII(-1e9, 1e9);
	// 不用pushdown
	// 找到左右子树的最大值和最小值对，然后对比 
	PII nhei = query(now << 1, L, R);
	PII nlow = query(now << 1 | 1, L ,R); 
	// 对比左区间的最大值和右区间的最大值，左区间的最小值和右区间的最小值... 
	return PII(max(nhei.first, nlow.first), min(nhei.second, nlow.second));
}
int main() {
	int n, m, l ,r;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while (m--) {
		scanf("%d%d", &l, &r);
		PII res = query(1, l, r);
		printf("%d\n", res.first - res.second);
	}
	return 0;
}
