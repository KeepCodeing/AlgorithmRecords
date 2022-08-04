#include <iostream>
#include <cstdio>
using namespace std;

// ��ͨ�������߶�����Ҫ��LL 
// �������߶���̫�Ա���ȥ�����ר��ɵ��뷨...Ȼ��ͻȻƳ���˴���...�Ա�... 

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
		// ���Այı�Ե�ǻ�...һ����ΪPOJ̫˾���ˣ�ԭ�����Լ���̱..����֮ǰΪ�˷���д��int�ˣ�û�뵽�����
		// ����ôҲ�Ҳ�����������...lz��sum��������long long������ǿת��int...���ò�˵�߶������ⶼ���˷ǳ�
		// ���...ע������ϵķ�������ȫ����AC��������һֱ��Ϊ��POJ������... 
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
		// ���Խ�ʡ�ռ��������ֱ������Ҷ�ӽڵ��ֵ������ 
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
	// ����д����R��L...�������˸�����һ˲�����ˣ������ϲ�������ˢ��״̬w... 
	if (L <= mid) update(ln, L, R, val);
	if (mid < R) update(rn, L, R, val);
	pushup(now); 
}
LL query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].sum;
	if (L > root[now].r || R < root[now].l) return 0;
	// ���������pushdown... 
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
		// ��дɵ��w������ƫ��cin�����ַ�������ֱ�����ַ���... 
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
