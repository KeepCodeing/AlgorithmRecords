#include <iostream>
#include <cstdio>
using namespace std;

// �߶�����ϰ��û��˵�ܳ�ʱ��û������˵ֻ�ǽ���û�����ww����֮�߶������Ǻ�����˼�ģ���򼸱�Ӧ��û�л���w 

typedef long long LL;
const int N = 1e5 + 10, M = N * 4;
int arr[N];
struct Node {
	// ���տ�LL 
	LL tot, lazy_tag;
	int left, right; 
	Node (int tot, int lazy_tag) : tot(tot), lazy_tag(lazy_tag) {};
	Node () {};
} root[M];
void pushdown(int now) {
	if (root[now].lazy_tag) {
		int lz = root[now].lazy_tag;
		Node *lf = &root[now << 1], *rt = &root[now << 1 | 1];
		// �����˼ӵ��ڣ�����һ˲������.. 
		lf->lazy_tag += lz, lf->tot += (lf->right - lf->left + 1) * lz;
		rt->lazy_tag += lz, rt->tot += (rt->right - rt->left + 1) * lz; 
		root[now].lazy_tag = 0;
	}
}
void build(int now, int left, int right) {
	// ����дreturn�Ͳ���дleft��right��ֵ��.. 
	root[now].left = left, root[now].right = right;
	if (left == right) {
		root[now].tot = arr[left], root[now].lazy_tag = 0;
		return;
	}
	int mid = (left + right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	root[now].tot = root[l_node].tot + root[r_node].tot;
}
void update(int now, int L, int R, int val) {
	if (L <= root[now].left && root[now].right <= R) {
		root[now].lazy_tag += val;
		// ���������������д�ɸ�ֵ..����һ��ʼ�����ܾ���Щ���⣬���ڵøĳɽ���ǰ�ڵ��ֵ����ģ���޸ĵ�ֵ��������.. 
		root[now].tot += (root[now].right - root[now].left + 1) * val;
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
	int mid = (root[now].left + root[now].right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	pushdown(now);
	return query(l_node, L, R) + query(r_node, L, R);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	build(1, 1, n);
	int op, x, y, k;
	while (m--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			scanf("%d", &k);
			update(1, x, y, k);
		} else {
			printf("%lld\n", query(1, x, y));
		}
	}
	return 0;
}
