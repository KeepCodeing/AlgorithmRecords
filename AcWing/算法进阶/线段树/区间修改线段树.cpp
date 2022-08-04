#include <iostream>
#include <cstdio>
using namespace std;

// �߶����ڶ���.new�����˽̳̺�ŷ��������޸ĺ�������Ĳ�̫һ�����������￪�����ļ�д... 
// д���˷��ֻ�����Щ���⣬��������ǵĸ��º͵�ǰ�ڵ��ֵ�ĸ��£���һ���䶼д����ֱ�Ӹ�ֵ�������Ļ�ԭ���Ľڵ��
// ֵ�ͻᱻ���ǵ�
// ���о��Ǹ��²��������������߻������������ߵ����⣬�������������������ֵ�жϣ������ǵ����޸��߶�����ķ���
// ����
// ���������͵����⣬�����ȫ��Ҫ��longlong����.. 

typedef long long LL;
const int N = 1e5 + 10, M = N * 4;
LL arr[N];
struct Node {
	int left, right;
	LL tot, lazy_tag;
	Node (int left, int right, int tot, int lazy_tag) : left(left), right(right), tot(tot), lazy_tag(lazy_tag) {};
	Node () {};
} root[M];
void pushdown(int now) {
	int left = now * 2, right = now * 2 + 1;
	// �������㱻����������ǣ���˵��Ҫ�����³�����������������������Ҳ��������ǣ�Ȼ��ģ����½ڵ�ֵ 
	int lazy_tag = root[now].lazy_tag;
	// ����Ϊ�˼�ֱ����ָ����.. 
	Node* l_node = &root[left], *r_node = &root[right];
	if (root[now].lazy_tag) {
		// ����ǰ�ڵ������������������ǣ�Ȼ��������ǵ�����ֵ 
		l_node->lazy_tag += lazy_tag, l_node->tot += (LL)(l_node->right - l_node->left + 1) * lazy_tag;
		r_node->lazy_tag += lazy_tag, r_node->tot += (LL)(r_node->right - r_node->left + 1) * lazy_tag;
		// ע������ȥ�������.. 
		root[now].lazy_tag = 0;
	}
}
void build(int now ,int left, int right) {
	if (left == right) {
		// ע������ĳ�ʼ�����Ƕ������ṹ����г�ʼ�������������Ĭ��Ϊ0����������.. 
		root[now] = Node(left, right, arr[left], 0);
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2, r_node = now * 2 + 1;
	// ע��������ֶ�������������ֵ��˼���¾��ܵó�ֻ���ڽ���ʱ��Ҫָ����������ֵ�Ľ���... 
	root[now].left = left, root[now].right = right;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	root[now].tot = root[l_node].tot + root[r_node].tot;
}
// ע�������޸��߶�������Ҫ�ٴ����������䷶Χ����Ϊ�ṹ�����Ѿ����� 
void update(int now, int L, int R, int val) {
	// �����ǰ�޸������Ѿ��������ˣ���ģ���޸ĵ�ǰ�ڵ��ֵ��Ȼ�������������� 
	if (L <= root[now].left && root[now].right <= R) {
		// ע�����ﲻ��ֱ�Ӹ�ֵ�����Ǽ�����������ֵ����Ϊֱ�Ӹ�ֵ������ȥ�˸ýڵ�ԭ����ֵ...������ǿת
		// ��Ϊ��������ݷ�Χ�ܴ�.. 
		root[now].tot += (LL)(root[now].right - root[now].left + 1) * val;
		// �����Ҳ����ֱ�Ӹ�ֵ�������ۼӵ�... 
		root[now].lazy_tag += val;
		return;
	}
	int mid = (root[now].left + root[now].right) / 2;
	int l_node = now * 2, r_node = now * 2 + 1;
	// pushdown�����������ݵ�ʱ��ִ�У�û������ʱ�ǲ���ִ�е� 
	pushdown(now);
	// ע�����ﲻ��д��if else�����ˣ������޸��߶�����������ΪҶ�ӽڵ��ֵ��ȷ���ģ��������޸��߶���
	// ��Ҫ�������������λ�����жϵģ�Ҳ����˵��һ�������䲻�ڷ�Χ����������ڷ�Χ��... 
	if (L <= mid) update(l_node, L, R, val);
	if (R > mid) update(r_node, L, R, val);
	root[now].tot = root[l_node].tot + root[r_node].tot;
}
// query��������ˣ����Ƕ��˸�pushdown��ע�ⷵ��ֵ�������ᱬint 
LL query(int now, int L, int R) {
	if (L <= root[now].left && root[now].right <= R) return root[now].tot;
	if (L > root[now].right || R < root[now].left) return 0;
	int mid = (root[now].left + root[now].right) / 2;
	int l_node = now * 2, r_node = now * 2 + 1;
	// ���ؽ��ǰִ��pushdown 
	pushdown(now);
	return query(l_node, L, R) + query(r_node, L, R);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	// ע���������ͣ������ǳ������� 
	for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]); 
	int op, x, y, k;
	// ��Ȼ���˽���... 
	build(1, 1, n);
	while (m--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			scanf("%d", &k);
			// ��[x, y]�����ڵ�������k 
			update(1, x, y, k);
		} else {
			// ��ѯ[x, y]����ĺ�.. 
			printf("%lld\n", query(1, x, y));
		}
	}
	return 0; 
}
