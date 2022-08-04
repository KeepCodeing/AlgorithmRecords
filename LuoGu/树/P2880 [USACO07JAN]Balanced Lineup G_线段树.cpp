#include <iostream>
#include <cstdio>
using namespace std;

// 线段树第⑨弹，这几天高强度刷线段树，不知道普及题刷完了会不会继续进阶（大概率不会w），刷完估计回去LeetCode刷
// 树了...还有就是离散数学做业..得加把劲了呢.. 
// 说起来这个题也是静态区间，可能用ST表或者树状数组好些呢.. 

// 依然犯了蜜汁错误.. 

const int N = 50000 + 10, M = N * 4;
int arr[N];
// 这个题一样要维护两个最值 
struct Node {
	int maxNum, minNum;
	Node (int maxNum, int minNum) : maxNum(maxNum), minNum(minNum) {};
	Node () {};
} root[M];
void build(int now, int left, int right) {
	if (left == right) {
		root[now].maxNum = root[now].minNum = arr[left];
		return;
	}
	int mid = (left + right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	root[now].maxNum = max(root[l_node].maxNum, root[r_node].maxNum);
	root[now].minNum = min(root[l_node].minNum, root[r_node].minNum);
}
Node query(int now, int left, int right, int L, int R) {
	if (L <= left && right <= R) return root[now];
	if (L > right || R < left) return Node(-1e9, 1e9);
	int mid = (left + right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	// 这里企图直接返回个Node对象，结果却忘了调用query...
	// 另外要注意这种多最值查询的线段树是不能直接返回结果的，必须借助结构体才能返回，那么返回的结构体
	// 就是左子树与右子树的最值... 
	Node lres = query(l_node, left, mid , L, R), rres = query(r_node, mid + 1, right, L, R);
	return Node(max(lres.maxNum, rres.maxNum), min(lres.minNum, rres.minNum));
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	int x, y;
	build(1, 1, n);
	while (m--) {
		scanf("%d%d", &x, &y);
		Node res = query(1, 1, n, x, y);
		printf("%d\n", res.maxNum - res.minNum);
	}
	return 0;
} 
