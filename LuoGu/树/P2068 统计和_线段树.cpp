#include <iostream>
using namespace std;

// 线段树第四弹，这个题差不多就是模板题... 
// 还是犯了些小错误...，不过感觉线段树无脑重复代码也挺多的...大概不会忘的很严重，毕竟每个函数都有求中间位置
// 左子树下标，右子树下标的操作， 联想下教程和图片应该能够继续写下去呢... 

const int N = 100000 + 10, M = N * 4;
// 初始全为0，作为全局变量就不用初始化了... 
int root[M];
void build(int now, int left, int right) {
	if (left == right) {
		root[now] = 0;
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
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
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	// 注意我们判断要修改的叶子节点是在左区间还是右区间是根据中间的下标来的，而不是idx <= left，这样想的话
	// 根节点的left一定是0，那么idx不管怎么样都会先从右子树开始... 
	if (idx <= mid) update(l_node, left, mid, idx, val);
	else update(r_node, mid + 1, right, idx, val);
	root[now] = root[l_node] + root[r_node];
}
int query(int now, int left, int right, int L, int R) {
	if (L <= left && right <= R) return root[now];
	if (L > right || R < left) return 0;
	int mid = (left + right) / 2;
	// 这里右节点的修改写成了now * 2 + 1... 
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	return query(l_node, left, mid, L, R) + query(r_node, mid + 1, right, L, R);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	char c;
	int x, y;
	// 感觉这里不用建树，因为建树就是求的区间和，而数组默认全为0，因此
	// 应该只用提供查询和修改就行了... 
	// build(0, 0, n - 1);
	while (m--) {
		cin >> c >> x >> y;
		// 注意区间起点和要加的值的区别，如果是更新，x表示位置，y表示要加的值 
		// 否则x，y都表示的是区间范围... 
		if (c == 'x') update(0, 0, n - 1, x - 1, y);
		else cout << query(0, 0, n - 1, x - 1, y - 1) << endl;
	}
	return 0;
}
