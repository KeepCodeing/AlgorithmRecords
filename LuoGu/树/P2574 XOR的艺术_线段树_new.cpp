#include <iostream>
#include <cstdio>
using namespace std;

// �߶�����ʮ��������ⲻ��ά������ͻ�����ֵʲô�ģ�����ά������01�ĸ����������뵽��ά���͵ķ�ʽͳ��������1�ĸ�����
// ��ȡ���������ǽ�01�ĸ�������������ǵ����þ������... 

// �ܽ᣺������������Ͱ���������������Ȼ�������׵���ȷÿ��Ҷ�ӽڵ��0��1��Ȼ������;���1�����������ǱȽ������뵽
// lazy_tag�������Լ������������0������������lazy_tag�����Ծ��Ǹ�����ĿҪ��ı�ģ�����Ǽӣ������XOR.. 

const int N = 2 * 1e5 + 10, M = N * 4;
int arr[N];
struct Node {
	int left, right, lazy_tag, sum;	
} root[M];
void pushdown(int now) {
	if (root[now].lazy_tag) {
		Node *l_node = &root[now << 1], *r_node = &root[now << 1 | 1];
		// �޸��������0,1�����������sum��ľ���1����������������С����right-left+1����ȥ������1������ʣ�µľ���0�������� 
		// ע�⵽������ֱ�Ӹ��ǣ������Ǽ���ȥ����Ϊ��Ŀ��Ҫ��ͬ.. 
		l_node->sum = (l_node->right - l_node->left + 1) - l_node->sum; 
		// ������ͬ��ͳ��1���������������С��ȥ0���������෴�ͼ�ȥ1����������Ӧ���������� 
		r_node->sum = (r_node->right - r_node->left + 1) - r_node->sum;
		// ���������򣬶�Ӧ�ľ�����Ŀ��Ĳ���1^0 = 1, 1^1 = 0 
		l_node->lazy_tag ^= 1, r_node->lazy_tag ^= 1;
		root[now].lazy_tag = 0; 
	}
}
void build(int now, int left, int right) {
	// ����仰д��returnǰ��Ϳ��Բ�����return�����ʼ��Ҷ�ӽڵ������������ 
	root[now].left = left, root[now].right = right;
	if (left == right) {
		root[now].sum = arr[left];
		return;
	}
	int mid = (left + right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	root[now].sum = root[l_node].sum + root[r_node].sum;
}
void update(int now, int L, int R) {
	if (L <= root[now].left && root[now].right <= R) {
		// ��ѯ��������������pushdown�������һ�¼���... 
		root[now].sum = (root[now].right - root[now].left + 1) - root[now].sum;
		root[now].lazy_tag ^= 1;
		return;
	}
	int mid = (root[now].left + root[now].right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	pushdown(now);
	if (L <= mid) update(l_node, L, R);
	if (R > mid) update(r_node, L, R);
	root[now].sum = root[l_node].sum + root[r_node].sum;
}
int query(int now, int L, int R) {
	// ��Ӧ����ķ��أ�����left��rightֱ����Ϊ�ṹ�������ʹ�ã���������Ϊ��������.. 
	if (L <= root[now].left && root[now].right <= R) return root[now].sum; // ����д�˸�<+����Ȼû����...����RE�� 
	if (L > root[now].right || R < root[now].left) return 0;
	int mid = (root[now].left + root[now].right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	// ע�����Ҫ�õ�pushdown���� 
	pushdown(now);
	// ����Ҫע�⴫�Ĳ���left����right����Ϊ���ǰ����ڽṹ������... 
	return query(l_node, L, R) + query(r_node, L, R);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	char c;
	for (int i = 1; i <= n; i++) cin >> c, arr[i] = c - '0';
	build(1, 1, n);
	int op, l, r;
	while (m--) {
		scanf("%d%d%d", &op, &l, &r);
		if (!op) update(1, l, r);
		else printf("%d\n", query(1, l, r));
	}
	return 0;
}
