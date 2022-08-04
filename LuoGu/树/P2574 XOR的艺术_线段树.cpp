#include <iostream>
using namespace std;

// 线段树第六弹，这个题乍看起来好像不是模板题，因为它说要统计的是一个区间内字符1的个数，那么我们思考下怎么
// 样用线段树统计这个字符区间个数。首先字符串只存在0和1，思考下线段是的区间是怎么得到的就可以发现，这个字符串
// 一定是被映射到了线段树的叶子节点上，即叶子节点的值只有0和1，那么如果我们将这个0,1看成是数字，不难发现，叶子
// 节点的父节点的区间值就是这两个子节点的和，然后依次类推..所以硬要说这个题和模板题有什么不同的话，大概就是原
// 数组只有0和1，而且是以所谓的字符串形式给出的... 

// 写完了发现不是单点修改...最后还是把query补齐了，就当复习算了... 

const int N = 2 * 1e5, M = N * 4;
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
	root[now] = root[l_node] + root[r_node];
}
void update(int now, int left, int right, int idx) {
	if (left == right) {
		// 这个题只有0变1，1变0的操作，所以只需要要修改的叶子节点的下标，至于变值可以看出来就是个取反操作.. 
		root[now] = !root[now];
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	// 这里还是得强调下，判断左右子树是通过mid来的.. 
	if (idx <= mid) update(l_node, left, mid, idx);
	else update(r_node, mid + 1, right, idx);
	root[now] = root[l_node] + root[r_node];
}
int query(int now, int left, int right, int L, int R) {
	if (L <= left && right <= R) return root[now];
	if (L > right || R < left) return 0;
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	return query(l_node, left, mid, L, R) + query(r_node, mid + 1, right, L, R);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	char c;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> c, arr[i] = c - '0';
	int op, x, y;
	build(0, 0, n - 1);
	while (m--) {
		cin >> op >> x >> y;
		x--, y--; // 喜闻乐见的下标陷阱..
		// 不是单点修改（绝望） 
//		if (!op) update(0, 0, n - 1, )
	}
	return 0;
}
