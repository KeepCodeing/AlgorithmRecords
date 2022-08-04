#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// �ƺ��������Ƿϵ�����֮�У����ڴ������Ҳ�治�ã�ѧҲѧ���������...��ô����Ȿ�ʻ��Ǹ�
// �߶����İ����⣬ֻ�����书�����޸�����Ϊһ�����������������һ�㶼���޸�����Ǻ�pushup����
// ������Ŀ����˼�������ܲ���Ҫ������ô�ණ����... 

// ��Ȼһ��AC�ˣ�ϲ������ôǰ���Ǹ�������WA���ܾ���û�г�ʼ�����õ��������ʹ�����... 

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
		// ע������ 
		LL lz = root[now].lz, sum = root[now].sum;
		int ln = now << 1, rn = now << 1 | 1;
		// ע������������䣬���ʾ������������Ǻ������Ĳ�ͬ
		// �������Ϊ+=������ֵ�����= 
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
		// ֱ�Ӹ���ԭ�����ֵ�������Ǽ��ϣ�����ļ�����ָ����Ǻ����䣬������ָ�����pushup��Ҳ����˵���˵�ǰ
		// �����ֵ���ǻ�Ӱ�쵽����������ġ�����������߶�����һ���������������ڵ�ǰ�ڵ��޸�Ϊval��Ȼ��ͨ��
		// pushdown���ӽڵ�Ҳ�޸�Ϊval���������߶���������ģ�⽫Ҷ�ӽڵ��޸�Ϊval��Ȼ���ٴ������Ĺ���... 
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
		// ����֮ǰ�Ǹ���WA����Ϊû�г�ʼ���� 
		init_root();
		scanf("%d%d", &n, &m);
		// ������˽���... 
		build(1, 1, n);
		// ��[l, r]�����ֵ����Ϊval 
		while (m--) {
			scanf("%d%d%d", &l, &r, &val);
			update(1, l, r, val);
		}
		// �������... 
		printf("Case %d: The total value of the hook is %d.\n", t, query(1, 1, n));
	}
	return 0;
} 
