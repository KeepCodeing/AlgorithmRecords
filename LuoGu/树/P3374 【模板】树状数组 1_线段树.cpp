#include <iostream>
#include <cstdio>
using namespace std;

// �߶������ߵ�����ʵ������Ѿ�����״����д�ˣ�ֻ������fuxi���߶������жԱ������ߵ�Ч��... 

const int N = 5 * 1e5 + 10, M = 4 * N;
int arr[N], root[M];
void build(int now, int left, int right) {
	if (left == right) {
		root[now] = arr[left]; // �߶�����ԭ����ֻ�и�Ҷ�ӽڵ㸳ֵ��ʱ��ᱻ�õ����Ƚ��˷ѿռ������.. 
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2, r_node = now * 2 + 1; // �±��1��ʼ��������Ҳ�øĸ�
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	root[now] = root[l_node] + root[r_node]; 
}
void update(int now, int left, int right, int idx, int val) {
	if (left == right) {
		root[now] += val;
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2, r_node = now * 2 + 1;
	if (idx <= mid) update(l_node, left, mid, idx, val);
	else update(r_node, mid + 1, right, idx, val);
	root[now] = root[l_node] + root[r_node];
}
int query(int now, int left, int right, int L, int R) {
	if (L <= left && right <= R) return root[now];
	if (L > right || R < left) return 0;
	int mid = (left + right) / 2;
	int l_node = now * 2, r_node = now * 2 + 1;
	return query(l_node, left, mid, L, R) + query(r_node, mid + 1, right, L, R);
}
int main() {
	int n, m, op, l, r, k;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &l, &r, &k);
			update(1, l, r, k);
		} else {
			scanf("%d%d", &l, &r);
			printf("%lld\n", query(1, l, r));
		}
	}
	return 0;
}
