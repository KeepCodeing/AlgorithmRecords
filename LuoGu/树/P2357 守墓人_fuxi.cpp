#include <cstdio>
#include <iostream>
using namespace std;

// д��һ��vjudge�ϵ��ⵥ������ר�⣬д������⣬�о��Ƚ��м�ֵ...�м���ûд�߶����ˣ�fuxi�£�Խfuxi��Խfuxiw 
// �ܽ᣺���������������������˼�return�����˼�¼���������С���ܹ�����18���ӲŰѴ���д�꣨���л���2��3����IDE����w��
// ���о���д����Ĵ�����̫��w��дһ���ִ�һ��..���о�fuxi���Ǻ��б�Ҫ�ģ���ȻҲ������״̬���У����ģ� 
// �����˴��㣬��֮�߶�����������ϻ��ˣ��������ǲ����ڶ�ʱ������ȫû�д����д��������ȻӦ���Ѿ�д�˺ܶ����w 

typedef long long LL;
const int N = 2 * 1e5 + 10, M = N * 4;
int arr[N];
struct Node {
	int l, r;
	LL lz, tot;
} root[M];
// 43 01
void build(int now, int left, int right) {
	// ���˼�¼���������С 
	root[now].l = left, root[now].r = right;
	if (left == right) {
		root[now].tot = arr[left];
		root[now].lz = 0;
		return;
	}
	int mid = (left + right) >> 1;
	int l = now << 1, r = now << 1 | 1;
	build(l, left, mid);
	build(r, mid + 1, right);
	root[now].tot = root[l].tot + 0ll + root[r].tot;
}
void pushdown(int now) {
	if (root[now].lz) {
		int l = now << 1, r = now << 1 | 1;
		root[l].lz += root[now].lz, root[l].tot += (root[l].r - root[l].l + 1) * root[now].lz;
		root[r].lz += root[now].lz, root[r].tot += (root[r].r - root[r].l + 1) * root[now].lz;
		root[now].lz = 0;
	}
}
void update(int now, int L, int R, int val) {
	if (L <= root[now].l && root[now].r <= R) {
		// д����д����root[now].r - root[now].r... 
		root[now].tot += (root[now].r - root[now].l + 1 + 0ll) * val;
		root[now].lz += val;
		// ���˼�return 
		return;
	}
	int mid = (root[now].l + root[now].r) >> 1;
	int l = now << 1, r = now << 1 | 1;
	pushdown(now);
	if (L <= mid) update(l, L, R, val);
	if (R > mid) update(r, L, R, val);
	root[now].tot = root[l].tot + 0ll + root[r].tot;
}
LL query(int now, int L, int R) {
	if (L <= root[now].l && root[now].r <= R) return root[now].tot;
	if (L > root[now].r || R < root[now].l) return 0;
	int l = now << 1, r = now << 1 | 1;
	pushdown(now);
	return query(l, L, R) + query(r, L, R);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	build(1, 1, n);
	int op, l, r, k;
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &l, &r, &k);
			update(1, l, r, k);
		} else if (op == 2 || op == 3) {
			scanf("%d", &k);
			if (op == 3) k = -k;
			update(1, 1, 1, k);
		} else if (op == 4) {
			scanf("%d%d", &l, &r);
			printf("%lld\n", query(1, l, r));
		} else {
			printf("%lld\n", query(1, 1, 1));
		}
	}
	return 0;
}
