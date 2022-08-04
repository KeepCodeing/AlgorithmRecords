#include <iostream>
#include <cstdio>
using namespace std;
const int M = 1e5 * 4 + 10;
struct Node {
	int l, r, mm;
} root[M];
void pushup(int now) {
	root[now].mm = min(root[now << 1].mm, root[now << 1 | 1].mm);
}
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		// 这个地方迟疑了下，想了下是now还是left或者right，但是想到普通输入
		// 的线段树也是root[now] = arr[left]之类的就想明白了.. 
		scanf("%d", &root[now].mm);
		return;
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	pushup(now);
}
// 没有懒标记，没有pushdown.. 
int query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].mm;
	// 注意应该返回一个极大值 
	if (L > root[now].r || R < root[now].l) return 1e9;
	return min(query(now << 1, L, R), query(now << 1 | 1, L, R));
}
int main() {
	int n, m, l, r;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	// 区间从1开始，输入从0开始.. 
	while (m--) scanf("%d%d", &l, &r), printf("%d\n", query(1, l + 1, r + 1));
	return 0;
}
