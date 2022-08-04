#include <iostream>
#include <cstdio>
using namespace std;
const int N = 200000 + 10, M = N * 4;
int nums[N];
struct Node {
	// ����Ȿ�ʾ��ǵ����޸��߶�������˲���Ҫ
	// pushdown��lazy tag.. 
	int l, r, mx;
} root[M];
void pushup(int now) {
	root[now].mx = max(root[now << 1].mx, root[now << 1 | 1].mx);
}
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		// �������ֺ�����Ĳ���������ֱ���ڵ���Ҷ�ӽڵ��ʱ������Ҷ�ӽڵ��ֵ��������
		// ����������... 
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
		// ֻ��ֵ�����ʱ��Ÿ���.. 
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
	// û��pushdown��w��д��д��һ������w 
	return max(query(now << 1, L, R), query(now << 1 | 1, L, R));
}
int main() {
	int n, m, x, y;
	char c;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
	build(1, 1, n);
	while (m--) {
		// ����Ĵ�����Ϊǰ����������б�scanf��������˳����������bug..���о���HDU�ƺ���ά������֮�������ⲻ����... 
		// ���AC�ˣ���֤�������߶�����ȫ���Ա������߶���ȡ��... 
		cin >> c;
		scanf("%d%d", &x, &y);
		if (c == 'Q') printf("%d\n", query(1, x, y));
		else update(1, x, x, y);
	}
	return 0;
}
