#include <iostream>
using namespace std;

// 树状数组是一个利用位运算加区间加减法进行区间操作的数据结构，它支持单点修改，区间查询和区间修改，单点查询，
// 感觉后者不是很常用所以不搞了w
// 前者和不加懒标记的线段树是一样的，但是树状数组做这个操作比线段树强十倍甚至九倍，首先就是空间，树状数组不需要
// 4倍空间，其次就是时间，虽然线段树的复杂度也是logn，但是总体来说用递归比迭代慢一点（虚心），最后就是代码了，
// 线段树的代码比较多，虽然大部分都是差不多的，树状数组代码很少，而且绝大部分代码几乎一样... 

const int N = 5 * 1e5 + 100;
int n, m;
int root[N];
int lowbit(int x) {
	return x & (-x); // 玄学操作，以前好像听过原理，不过忘了..这行代码就可以求出x的二进制形式结尾有多少个0 
}
void add(int idx, int val) {
	// 算出父节点编号，然后统计区间和..，注意这里当前节点的编号是i，idx只是用来赋初值的.. 
	for (int i = idx; i <= n; i += lowbit(i)) root[i] += val;
}
int query(int end) {
	int tot = 0;
	// 查询，算出所有子节点的区间和，i会一直算到0为止.. 
	for (int i = end; i; i -= lowbit(i)) tot += root[i];
	return tot;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int val;
	for (int i = 1; i <= n; i++) cin >> val, add(i, val); // 建树，其实就是不断的调用更新操作.. 
	int op, x, y;
	while (m--) {
		cin >> op >> x >> y;
		if (op == 1) add(x, y); // 更新，将x位置的数加上y，其实就是重新计算区间和.. 
		else cout << query(y) - query(x - 1) << endl; // 查询，满足区间加减法，代码上就是反着的修改操作 
	}
	return 0;
}
