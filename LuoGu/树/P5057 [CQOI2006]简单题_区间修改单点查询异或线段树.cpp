#include <iostream>
#include <cstdio>
using namespace std;

// �Ƚ������һ���⣬������������޸ģ������ѯ..�����ϻ��Ǹ�����߶�����ֻ����Ҫ���²�ѯ.. 
// ˵������˵��������д�ɵ����ѯ����TLE�����Ҳ�֪��ΪʲôRE��w�����˰�query�ĳɴ����ѯ���⣬����⼸����
// ����߶���û�в��... 

// ����������50w 

// 49 00

// ���ﲻ֪��ΪʲôRE�ˣ�����M���Կ���... 
const int N = 1e5 + 10, M = 1e6 * 5 + 10;
struct Node {
	int l, r, lz, val;
} root[M];
void pushup(int now) {
	root[now].val = root[now << 1].val + root[now << 1 | 1].val;
}
void build(int now, int left, int right) {
	root[now].l = left, root[now].r = right;
	if (left == right) {
		root[now].lz = 0;
		root[now].val = 1;
		return;
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	// ������������pushup����Ϊ��ֻ�в�ѯ����ֵ��Ȼ���䷢�����������Ҫw����Ϊ�����ľ��ǵ����ѯ
	// �����ûһ��ֵ��ǵ���ֵ�Ļ���û�취�����... 
	pushup(now);
}

void pushdown(int now) {
	if (root[now].lz) {
		int ln = now << 1, rn = now << 1 | 1;
		root[ln].lz ^= 1, root[rn].lz ^= 1;
		root[ln].val = (root[ln].r - root[ln].l + 1) - root[ln].val;
		root[rn].val = (root[rn].r - root[rn].l + 1) - root[rn].val;
		root[now].lz = 0;
	}
}
void update(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) {
		root[now].lz ^= 1;
		root[now].val = (root[now].r - root[now].l + 1) - root[now].val;
		return;
	}
	int mid = (root[now].l + root[now].r) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	pushdown(now);
	if (L <= mid) update(ln, L, R);
	if (R > mid) update(rn, L, R); 
	pushup(now);
}
int ans;
void query(int now, int L, int R, int idx) {
	if (L > root[now].r || R < root[now].l) return;
	// �����ѯ������һ�����ߵ�idx���Ҷ�ӽڵ㣬����O2ҲTLE��w��Ӧ�ÿ����Ż���... 
	if (root[now].l == root[now].r && root[now].l == idx) {
		ans = root[now].val;
		return;	
	}
	int ln = now << 1, rn = now << 1 | 1;
	pushdown(now);
	query(ln, L, R, idx), query(rn, L, R, idx);
}
int main() {
	int n, m, op, l, r;
	scanf("%d%d", &n, &m);
	build (1, 1, n);
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &l, &r);
			update(1, l, r);
		} else {
			scanf("%d", &l);
			query(1, 1, n, l);
			// ע���Ҫȡ������Ϊpushdownִ�в���Ҷ�ӽڵ���.. 
			printf("%d\n", !ans);
		}
	}
	return 0;
}
