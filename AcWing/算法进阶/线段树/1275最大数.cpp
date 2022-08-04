#include <iostream>
#include <cstdio>
using namespace std;

// 单点修改线段树：核心操作是pushup，该操作可以从两个子区间获得父区间的值
// 实现
// 0. 存储
// 用结构体存放L,R,以及[l, R]的最大值 
// 1. 建树 
// 用递归方式建树，建好父节点u再分别递归左右子节点。 
// 左节点：u << 1 == 2 * u，右节点 u << 1 | 1 == 2 * u + 1 
// 2. 查询
// 设当前树大小为n，则分三种情况递归查询，在区间内，在区间左，在区间右 
// 当前树已被包含在查询区间，就返回当前树的最大值，否则就
// 查询左右节点 
// 3. 添加
// 如果当前节点是要添加的位置，就赋值当前点，否则就递归左右节点，并且
// 更新当前节点的最大值

const int N = 2e5 + 10;
// 线段树一般要开四倍大小的数组防止越界 
struct Node {
	int l, r, v;
	Node(int l, int r) : l(l), r(r) {};
	Node () {};
} tr[N * 4];

// 更新区间最大值
void pushup(int root) {
	// 由左右子节点的值推出父节点的值 
	tr[root].v = max(tr[root << 1].v, tr[root << 1 | 1].v);
} 

// 建树，先把这棵树要用到的所有区间准备好 
void build(int root, int l, int r) {
	tr[root] = Node(l, r);
	// 如果已经到了叶子节点，就没必要继续扩展了 
	if (l == r) return;
	int mid = l + r << 1;
	// root << 1代表左子树的父节点，root << 1 | 1代表右子树的父节点，两个节点没有交集 
	build(root << 1, l, mid), build(root << 1 | 1, mid + 1, r);
}

// 查询区间最大值，分多钟情况 
int query(int root, int l, int r) {
	// 情况一：如果查询区间在当前区间[l, r]内，查询区间的最大值就是当前区间的最大值，直接返回即可 
	if (tr[root].l <= l && tr[root].r >= r) return tr[root].v;
	int v = 0;
	int mid = tr[root].l + tr[root].r >> 1;
	// 情况二：查询区间的左边与当前区间的右边有交集，去左子树找 
	if (l <= mid) v = max(query(root << 1, l, r), v);
	// 情况三：查询区间的右边与当前区间的左边有交集，去右子树找 
	if (mid < r) v = max(query(root << 1 | 1, l, r), v); 
	return v;
}

// 修改操作，把x这个节点上的值修改为v
void modify(int root, int x, int v) {
	// 如果找到了这个个点（即找到了这个点所在的叶子节点），将其值修改 
	if (tr[root].l == x && tr[root].r == x) {
		tr[root].v = v;
	} else {
		// 如果没找到这个叶子节点，判断下是去左子树找这个节点还是右子树找
		int mid = tr[root].l + tr[root].r >> 1;
		// 去左子树找 
		if (x <= mid) modify(root << 1, x, v);  
		else modify(root << 1 | 1, x, v); // 去又子树找
		// 最后在回溯的过程中更新父节点的区间最大值，因为子节点发生了变化
		// 父节点也要相应变化
		pushup(root); 
	}
	
} 
int main() {
	int m, p;
	scanf("%d%d", &m, &p);
	build(1, 1, m);
	char op[2];
	int last = 0, n = 0;
	int x;
	while (m--) {
		scanf("%s%d", &op, &x);
		if (*op == 'Q') {
			last = query(1, n - x + 1, n);
			printf("%d\n", last);
		} else {
			modify(1, n + 1, (last + x) % p);
			n++;
		} 
	}
	return 0; 
}
