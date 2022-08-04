#include <iostream>
#include <cstdio>
using namespace std;

// 线段树第十弹，这个题不是维护区间和或者最值什么的，而是维护区间01的个数，可以想到用维护和的方式统计区间中1的个数，
// 而取反操作就是将01的个数互换，懒标记的设置就是异或... 

// 总结：这个题和区间求和板子题有所区别，虽然可以容易的明确每个叶子节点非0即1，然后区间和就是1的数量，但是比较难以想到
// lazy_tag的作用以及如何求区间中0的数量，或者lazy_tag的属性就是跟随题目要求改变的，求和是加，异或是XOR.. 

const int N = 2 * 1e5 + 10, M = N * 4;
int arr[N];
struct Node {
	int left, right, lazy_tag, sum;	
} root[M];
void pushdown(int now) {
	if (root[now].lazy_tag) {
		Node *l_node = &root[now << 1], *r_node = &root[now << 1 | 1];
		// 修改左区间的0,1数量，这里的sum存的就是1的数量，这个区间大小就是right-left+1，减去区间里1的数量剩下的就是0的数量了 
		// 注意到这里是直接覆盖，而不是加上去，因为题目的要求不同.. 
		l_node->sum = (l_node->right - l_node->left + 1) - l_node->sum; 
		// 右区间同理，统计1的数量就用区间大小减去0的数量，相反就减去1的数量，对应下面的懒标记 
		r_node->sum = (r_node->right - r_node->left + 1) - r_node->sum;
		// 将懒标记异或，对应的就是题目里的操作1^0 = 1, 1^1 = 0 
		l_node->lazy_tag ^= 1, r_node->lazy_tag ^= 1;
		root[now].lazy_tag = 0; 
	}
}
void build(int now, int left, int right) {
	// 将这句话写在return前面就可以不用在return里面初始化叶子节点的左右区间了 
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
		// 查询的区间包含情况和pushdown操作里的一致即可... 
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
	// 对应下面的返回，这里left和right直接作为结构体的属性使用，而不是作为参数传递.. 
	if (L <= root[now].left && root[now].right <= R) return root[now].sum; // 这里写了个<+，居然没报错...但是RE了 
	if (L > root[now].right || R < root[now].left) return 0;
	int mid = (root[now].left + root[now].right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	// 注意回溯要用到pushdown操作 
	pushdown(now);
	// 这里要注意传的不是left或者right，因为他们包含在结构体里了... 
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
