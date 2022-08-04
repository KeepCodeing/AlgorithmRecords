#include <iostream>
using namespace std;

// 线段树第一弹-新，上一个代码爆了两次零，因为教程的代码有些问题...对着答案的代码改了3个小时，现在虽然不敢说
// 有新的理解，但是感觉也没什么逻辑上的错误了.. 

const int N = 200000 + 10, M = N * 4 + 10; // 注意线段树的数组空间，不是无脑开大就行了，而是要根据有多少个数据来，一般开4倍空间.. 
// arr数组就在更新叶子节点的时候用到了，不过很可惜叶子节点的编号虽然是从0递增的，但是在树里的编号不是，即不能省这个数组.. 
int arr[N], root[M];
void build(int now, int left, int right) {
	if (left == right) {
		root[now] = arr[left];
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	// 这里和教程其实没什么区别，不过这个取max的操作可能会多次用到，因此可以写成一个函数 
	root[now] = max(root[l_node], root[r_node]);
}
void update(int now, int left, int right, int idx, int val) {
	if (left == right) {
		// 题目说原分数更高就不更改，另外这里没有像教程中更新原数组，似乎是因为用不到... 
		root[now] = max(root[now], val);
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	// 这里也和教程里的left <= idx <= mid不同，这里判断左右区间只需要根据mid来就行了，不过感觉写成教程那样比较好 
	if (left <= idx && idx <= mid) update(l_node, left, mid, idx, val);
	else update(r_node, mid + 1, right, idx, val);
	// 更新这条路径及其子树 
	root[now] = max(root[l_node], root[r_node]);
}
int query(int now, int left, int right, int L, int R) {
	// 这里和教程完全不一样，教程中也可能是这里有错误，我们只要判断下当前区间是否被包含即可，不需要剪枝
	// 或者left == right，因为后者被包括了，后者通过判断编号进行 
	if (L <= left && right <= R) return root[now];
	// 剪枝，如果当前区间完全用不到直接剪掉 
	if (left > R || right < L) return -1e9;
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
//	int ans = -1e9;
	// 这里和教程不同，教程里应该对应的是两个区间完全不相交的剪枝，那么这里对应的就是左区间被包含
	// 和右区间被包含，感觉这样写太麻烦所以换成教程的剪枝了 
//	if (L <= mid) ans = max(ans, query(l_node, left, mid, L, R));
//	if (R > mid) ans = max(ans, query(r_node, mid + 1, right, L, R));
	// 对比左右子树的最大值 
	return max(query(l_node, left, mid, L, R), query(r_node, mid + 1, right, L, R));;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i]; // 注意这里其区间从0开始，题目区间从1开始，因此下面还要减去1 
	build(0, 0, n - 1);
	char op;
	int x, y;
	while (m--) {
		cin >> op >> x >> y;
		if (op == 'Q') cout << query(0, 0, n - 1, x - 1, y - 1) << endl;
		else update(0, 0, n - 1, x - 1, y);
	}
	return 0;
}
