#include <iostream>
#include <cstdio>
using namespace std;

// �߶������ߵ��������Ҫ�õ������޸��߶���... 
// д���˸о����Ǵ���Щ����
// ���Ȼ��Ǹ�ֵ����������ʶ�İ�һЩ����ֱֵ��д���˸�ֵ��������ʱ������
// Ȼ���Ǹ��ºͲ�ѯʱ��������������⣬����д���˵����޸��߶�����left��right��mid������������ǰ��˵��
// �����߶������˽���Ҫָ��left��right�������������ֱ���ýṹ�����ģ���������Ӧ��ֱ�Ӵ�L��R����Ϊleft��right
// �����Ų�εĵݽ�������������mid��һ��Ҫ��ȷ�������ж����䣬�������жϵ�
// ����������������Ĺ���޸ģ�����ʵ���Ǹ������޸ĵĲ�������Ӧ�Ļ���������Ϊ[1, 1]����Ҳ˵���������޸��߶���
// ���Խ��е����޸ģ�����һ�㵥���޸������ѯ��������״�����... 

typedef long long LL;
const int N = 2 * 1e5 + 100, M = N * 4;
int arr[N];
struct Node {
	LL tot, lazy_tag;
	int left, right;
	Node (int left, int right, LL tot, LL lazy_tag) : left(left), right(right), tot(tot), lazy_tag(lazy_tag) {};
	Node () {};
} root[M];
void pushdown(int now) {
	Node *l_node = &root[now << 1], *r_node = &root[now << 1 | 1];
	int lazy_tag = root[now].lazy_tag;
	if (lazy_tag) {
		l_node->lazy_tag += lazy_tag, l_node->tot += (LL)(l_node->right - l_node->left + 1) * lazy_tag;
		r_node->lazy_tag += lazy_tag, r_node->tot += (LL)(r_node->right - r_node->left + 1) * lazy_tag;
		root[now].lazy_tag = 0;
	}
}
void build(int now, int left, int right) {
	if (left == right) {
		root[now] = Node(left, right, arr[left], 0);
		return;
	}
	int mid = (left + right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	root[now].left = left, root[now].right = right;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	root[now].tot = root[l_node].tot + root[r_node].tot;
}
void update(int now, int L, int R, int val) {
	if (L <= root[now].left && root[now].right <= R) {
		root[now].tot += (LL)(root[now].right - root[now].left + 1) * val;
		root[now].lazy_tag += val;
		return;
	}
	int mid = (root[now].left + root[now].right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	pushdown(now);
	if (L <= mid) update(l_node, L, R, val);
	if (R > mid) update(r_node, L, R, val);
	root[now].tot = root[l_node].tot + root[r_node].tot;
}
LL query(int now, int L, int R) {
	if (L <= root[now].left && root[now].right <= R) return root[now].tot;
	if (L > root[now].right || R < root[now].left) return 0;
	// int mid = (root[now].left + root[now].right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	pushdown(now);
	return query(l_node, L, R) + query(r_node, L, R);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	build(1, 1, n);
	int op, left, right, val;
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &left, &right, &val);
			update(1, left, right, val);
		} else if (op == 2 || op == 3) {
			scanf("%d", &val);
			if (op == 3) val = -val;
			update(1, 1, 1, val);
		} else if (op == 4) {
			scanf("%d%d", &left, &right);
			printf("%lld\n", query(1, left, right));
		} else {
			// ����Ĺ���ķ�ˮֵ
			printf("%lld\n", query(1, 1, 1));
		}
	}
	return 0;
}
