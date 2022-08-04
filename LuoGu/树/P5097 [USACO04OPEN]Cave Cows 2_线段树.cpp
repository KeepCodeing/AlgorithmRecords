#include <iostream>
#include <cstdio>
using namespace std;
const int N = 25000 * 4 + 10;
struct Node {
	int l, r, mn;
} root[N];
void pushup(int now) {
	root[now].mn = min(root[now << 1].mn, root[now << 1 | 1].mn);
}
void build(int now, int l, int r) {
	root[now].l = l, root[now].r = r;
	if (l == r) {
		// 本篇题解的核心内容：直接输入叶子节点的值以达到节省空间和减少码量的目的 
		scanf("%d", &root[now].mn);
		return;
	}	
	int mid = (l + r) >> 1;
	build(now << 1, l, mid);
	build(now << 1 | 1, mid + 1, r);
	pushup(now);
}
int query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].mn;
	if (L > root[now].r || R < root[now].l) return 1e9;
	int mid = (root[now].l + root[now].r) >> 1;
	return min(query(now << 1, L, R), query(now << 1 | 1, L, R));
}
int main() {
	int n, m, l, r;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while (m--) scanf("%d%d", &l, &r), printf("%d\n", query(1, l, r));
	return 0;
} 
