#include <iostream>
#include <cstdio>
using namespace std;

// Ӧ���Ǹ�����߶���������ƶ��ǰ���Ҳ����˵���ڵ�ȫΪ0��Ȼ�󿪵���ʵ�������0��1,1��0
// �������¸��ڵ��Ƿ���Ҫ���������ܵ����߶�������Ҫ�����������߶���Ҫͨ����¼��¼�������䣬����
// ����Ҫ����... 

// ������˵ûʲô�����⣬�����ٶ��ƺ�Ҳ������ߣ���������û������������...6�µ�һ��AC����������˵���vjudge... 
// ���Ľ��ͣ�1^1=0,1^0=1,0^0=1������˵������ϴβ�����ͬ���Ͳ����иı䣬�����ͬ����0��1,1��0��... 

const int N = 100000 + 10, M = N * 4;
struct Node {
	int l, r, lz, tot;
} root[M];
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		root[now].lz = root[now].tot = 0;
		return;
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	root[now].tot = root[ln].tot + root[rn].tot;
}
void pushdown(int now) {
	if (root[now].lz) {
		int ln = now << 1, rn = now << 1 | 1;
		// ע���������������1���������lazy_tag����Ϊlz�Ǹ�������ֵ��������Ҫ�����ǽ�����01����������
		// Ӧ�����1�����������totӦ��������Ŀǰ��С��ȥ����Ŀǰ�ͣ��Ϳ�������ͳ��1�ĺ�->ͳ��0�ĺͣ�������ͬ.. 
		root[ln].lz ^= 1, root[ln].tot = (root[ln].r - root[ln].l + 1) - root[ln].tot;
		root[rn].lz ^= 1, root[rn].tot = (root[rn].r - root[rn].l + 1) - root[rn].tot;
		root[now].lz = 0;
	}
}
// 43 55
void update(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) {
		// ���1...�������޸�Ҳ�����޸ĳ�ĳ��ֵ�ˣ�����ֱ��ȡ��... 
		root[now].lz ^= 1;
		// Ӧ���Ǹ�ֵ�����Ǽӷ�... 
		root[now].tot = (root[now].r - root[now].l + 1) - root[now].tot;
		return;
	}
	int mid = (root[now].l + root[now].r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	// ע��ݹ�ǰpushdown 
	pushdown(now);
	if (L <= mid) update(ln, L, R);
	if (R > mid) update(rn, L, R);
	root[now].tot = root[ln].tot + root[rn].tot;
}
int query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].tot;
	if (L > root[now].r || R < root[now].l) return 0;
	int ln = now << 1, rn = now << 1 | 1;
	pushdown(now);
	return query(ln, L, R) + query(rn, L, R);
}
int main() {
	int n, m, op, l, r;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while (m--) {
		scanf("%d%d%d", &op, &l, &r);
		if (!op) update(1, l, r);
		else printf("%d\n", query(1, l, r));
	}
	return 0;
}
