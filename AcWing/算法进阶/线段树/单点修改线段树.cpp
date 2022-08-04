#include <iostream>
using namespace std;

// 线段树，主要用来处理区间操作，比较常见的有求[l,r]之间的数的和，还有将某个位置的数加上x
// 如果我们仅仅是求区间和，可以用前缀和来做到O(1)的复杂度，不过这里加了个加数的操作，也就是我们
// 如果用前缀和就必须在加数后更新整个数组，也就是复杂度变成了O(n)
// 但是用线段树可以均分下这两个操作的复杂度，使得他们的复杂度都为O(logn)...
// 首先考虑下怎么做区间和
// 如果我们将区间划分为[l, r / 2], [r / 2 + 1, r]，并直到l == r，然后对这若干个区间进行求和，能够发现[l, r]的区间和
// 就是[l, r / 2] + [r / 2 + 1, r]，依次类推，直到区间为1。如果我们将这些区间的值看成一个树，将总的区间和作为根节点
// 的值，[l, r / 2]的值作为根的左子树的值，[r / 2 + 1, r]作为右子树的值，然后对于上面所说的每个区间和进行映射，即可
// 发现左子树的每个节点都是[l, r / 2]的区间和，同理右子树也是[r / 2 + 1, r]的和..
// 啰嗦了半天似乎也没有讲清楚，还是用xmind算了... 

const int N = 1000, M = 6; // 这里N是线段树数组的大小，一般要开很大才不会意外RE..，M是数据数组的大小 
int arr[M] = {1, 3, 5, 7, 9 , 11};
int root[N];
// 建立线段树 
void build(int now, int left, int right) {
	// 如果到了叶子节点，即区间大小为一（区间起点和终点相同），那么当前这个叶子节点要存的值其实就是原
	// 数组里这个位置的值，至于当前叶子节点的位置，可以想象成是从左往右编号的，最左边的叶子节点编号为0，
	// 依次类推...即叶子节点的值为arr[0..sz] 
	if (left == right) {
		// 注意这里，之前写的root[left]=arr[left]，先明确下now的意思和left，right的意思，now代表的是当前节点的编号，
		// left和right则代表的是区间的大小。这两个量是完全不同的，叶子节点的left，right一定是从0开始，从左往右依次递增的， 
		// 即0..1..2..但是now不是，now是全体节点的编号值，即它从根节点就开始计数了... 
		root[now] = arr[left];
		return;
	}
	// 算出左右子树的节点编号 
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	// 划分区间 
	int mid = (left + right) / 2;
	// 建左子树，右子树，当前点就是编号值 
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	// 当前节点的区间和由左右子树的区间和组成，注意叶子节点没有左右子树，因此终止条件也要写最前面... 
	root[now] = root[l_node] + root[r_node];
}
// 单点更新线段树
void update(int now, int left, int right, int idx, int val) {
	// 如果找到了这个叶子节点，那么就更新它的值 
	if (left == right) {
		root[now] = val, arr[idx] = val;
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	// 注意这里的范围判断，不能就写个idx <= mid，因为left不一定永远是0，或者应该说left是在逐渐缩小的... 
	if (left <= idx && idx <= mid) {
		update(l_node, left, mid, idx, val);
	} else {
		update(r_node, mid + 1, right, idx, val);
	}
	root[now] = root[l_node] + root[r_node];
} 
// 查询区间值
int query(int now, int left, int right, int L, int R) {
	// 前两种情况：区间完全不相关，则直接返回0 
	if (R < left || L > right) {
		return 0;
	} else if (L <= left && right <= R) {
		// 区间被包括则直接返回已有的区间和 
		return root[now];
	} else if (left == right) {
		// 如果上述几种情况都不符合，则说明这部分区间和查询区间只是部分相交，那么就得求出这个区间内的所有叶子节点的和了 
		// 另外这个判断可以和第二个判断合并，不过这里为了直观不做合并，那为了方便理解可以认为除了区间不想交的情况，区间
		// 覆盖或者部分覆盖都可以直接返回当前节点的区间和... 
		return root[now];
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	// 算出左右子树的区间和，注意这里是直接赋值，因为每一层返回的就是左/右子树的区间和 
	int l_sum = query(l_node, left, mid, L, R);
	int r_sum = query(r_node, mid + 1, right, L, R);
	return l_sum + r_sum;
} 
int main() {
	build(0, 0, M - 1);
	for (int i = 0; i < 15; i++) cout << "root[" << i << "]"  << " = " << root[i] << endl; 
	cout << endl;
	update(0, 0, M - 1, 4, 6);
	for (int i = 0; i < 15; i++) cout << "root[" << i << "]"  << " = " << root[i] << endl; 
	cout << endl;
	cout << query(0, 0, M - 1, 2, 5); // 当前节点编号，起点，终点，查询区间 
	return 0;
}
