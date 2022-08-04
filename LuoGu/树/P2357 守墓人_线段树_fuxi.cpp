#include <iostream>
#include <cstdio>
using namespace std;

// �����߶�����ϰ������û���е�������w������13����д�������...��Щ�ط�����Ҫ���²���д����... 
// ��Ϊû����query��ִ��pushdown������ww�����м�֦����д���ƺ�����ǰ��̫һ��... 

typedef long long LL;
const int N = 2 * 1e5 + 10, M = N * 4;
int arr[N];
struct Node {
	int l, r;
	LL lz, sum;
} root[M];
void pushup(int now) {
	root[now].sum = root[now << 1].sum + 0ll + root[now << 1 | 1].sum;
}
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		root[now].lz = 0, root[now].sum = arr[left];
		return;
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	pushup(now);
}
void pushdown(int now) {
	if (root[now].lz) {
		int ln = now << 1, rn = now << 1 | 1;
		int lz = root[now].lz;
		root[ln].lz += lz, root[rn].lz += lz;
		// ����Ϊʲô��*lz������update������val��ֵ�أ���Ϊ��update���ȡ����һ�������ֵ������Խ����
		// �Ľڵ�Ҫģ�����ӵ�ֵ��Խ��... 
		root[ln].sum += (root[ln].r - root[ln].l + 1) * lz;
		root[rn].sum += (root[rn].r - root[rn].l + 1) * lz;
		root[now].lz = 0;
	}
}
void update(int now, int L, int R, int val) {
	if (L <= root[now].l && root[now].r <= R) {
		root[now].sum += (root[now].r - root[now].l + 1 + 0ll) * val;
		root[now].lz += val;
		return;
	}
	int mid = (root[now].l + root[now].r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	pushdown(now);
	if (L <= mid) update(ln, L, R, val);
	if (R > mid) update(rn, L, R, val);
	pushup(now);
}
LL query(int now, int L, int R) {
	// if (root[now].l > R || root[now].r < L) return 0;
	if (L <= root[now].l && root[now].r <= R) return root[now].sum;
	if (L > root[now].r || R < root[now].l) return 0;
	int ln = now << 1, rn = now << 1 | 1;
	pushdown(now);
	return query(ln, L, R) + query(rn, L ,R);
}
int main() {
	int n, m, op, l, r, x;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	build(1, 1, n);
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &l, &r, &x);
			update(1, l, r, x);
		} else if (op == 2 || op == 3) {
			scanf("%d", &x);
			if (op == 3) x = -x;
			update(1, 1, 1, x);
		} else if (op == 4) {
			scanf("%d%d", &l, &r);
			printf("%lld\n", query(1, l, r));
		} else {
			printf("%lld\n", query(1, 1, 1));
		}
		
	}
	return 0;
}
