#include <iostream>
#include <cstdio>
using namespace std;

// 线段树第二弹.new，看了教程后才发现区间修改和其想象的不太一样，所以这里开个新文件写... 
// 写完了发现还是有些问题，比如懒标记的更新和当前节点的值的更新，第一次其都写成了直接赋值，这样的话原来的节点的
// 值就会被覆盖掉
// 还有就是更新操作的往左子树走还是往右子树走的问题，这里必须根据左右区间的值判断，而不是单点修改线段树里的非左
// 即右
// 最后就是类型的问题，这个题全程要用longlong才行.. 

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
	// 如果这个点被打上了懒标记，就说明要进行下沉操作，即给他的左右子树也打上懒标记，然后模拟更新节点值 
	int lazy_tag = root[now].lazy_tag;
	// 这里为了简化直接用指针了.. 
	Node* l_node = &root[left], *r_node = &root[right];
	if (root[now].lazy_tag) {
		// 给当前节点的左右子树打上懒标记，然后更新它们的区间值 
		l_node->lazy_tag += lazy_tag, l_node->tot += (LL)(l_node->right - l_node->left + 1) * lazy_tag;
		r_node->lazy_tag += lazy_tag, r_node->tot += (LL)(r_node->right - r_node->left + 1) * lazy_tag;
		// 注意这里去掉懒标记.. 
		root[now].lazy_tag = 0;
	}
}
void build(int now ,int left, int right) {
	if (left == right) {
		// 注意这里的初始化，是对整个结构体进行初始化，另外懒标记默认为0，即不存在.. 
		root[now] = Node(left, right, arr[left], 0);
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2, r_node = now * 2 + 1;
	// 注意这里的手动建立左右区间值，思考下就能得出只有在建树时需要指定左右区间值的结论... 
	root[now].left = left, root[now].right = right;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	root[now].tot = root[l_node].tot + root[r_node].tot;
}
// 注意区间修改线段树不需要再传入左右区间范围，因为结构体里已经存了 
void update(int now, int L, int R, int val) {
	// 如果当前修改区间已经被包括了，就模拟修改当前节点的值，然后给它打上懒标记 
	if (L <= root[now].left && root[now].right <= R) {
		// 注意这里不是直接赋值，而是加上这块区域的值，因为直接赋值就是舍去了该节点原来的值...，还有强转
		// 因为这个题数据范围很大.. 
		root[now].tot += (LL)(root[now].right - root[now].left + 1) * val;
		// 懒标记也不是直接赋值，而是累加的... 
		root[now].lazy_tag += val;
		return;
	}
	int mid = (root[now].left + root[now].right) / 2;
	int l_node = now * 2, r_node = now * 2 + 1;
	// pushdown操作会做回溯的时候执行，没到回溯时是不会执行的 
	pushdown(now);
	// 注意这里不是写个if else就行了，单点修改线段树可以是因为叶子节点的值是确定的，而区间修改线段树
	// 是要根据左右区间的位置来判断的，也就是说不一定左区间不在范围内又区间就在范围内... 
	if (L <= mid) update(l_node, L, R, val);
	if (R > mid) update(r_node, L, R, val);
	root[now].tot = root[l_node].tot + root[r_node].tot;
}
// query几乎差不多了，就是多了个pushdown，注意返回值，这个题会爆int 
LL query(int now, int L, int R) {
	if (L <= root[now].left && root[now].right <= R) return root[now].tot;
	if (L > root[now].right || R < root[now].left) return 0;
	int mid = (root[now].left + root[now].right) / 2;
	int l_node = now * 2, r_node = now * 2 + 1;
	// 返回结果前执行pushdown 
	pushdown(now);
	return query(l_node, L, R) + query(r_node, L, R);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	// 注意数据类型，这里是长长整形 
	for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]); 
	int op, x, y, k;
	// 居然忘了建树... 
	build(1, 1, n);
	while (m--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			scanf("%d", &k);
			// 将[x, y]区间内的数加上k 
			update(1, x, y, k);
		} else {
			// 查询[x, y]区间的和.. 
			printf("%lld\n", query(1, x, y));
		}
	}
	return 0; 
}
