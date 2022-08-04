#include <iostream>
using namespace std;

// 线段树第三弹（准确来说是第二弹），这个题甚至没有更新操作，因此建树+查询就完事了... 
// 不过说起来这个题用nth_element这个函数做过，爆了两次零w，真是有够好笑了呢...
// 另外感觉又有新的理解了.. 
// 总体感觉和最短路之类的题差不多，主要是多打，码农题... 

const int N = 100000 + 10, M = N * 4 + 10;
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
	root[now] = min(root[l_node], root[r_node]);
}
int query(int now, int left, int right, int L, int R) {
	// 这个地方之前理解的是当前节点的区间包括了查询区间就直接返回，但是实际上这里的意思是如果
	// 当前节点的区间被查询区间包含，就直接返回.. 
	if (L <= left && right <= R) return root[now];
	if (L > right || R < left) return 1e9;
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	return min(query(l_node, left, mid, L, R), query(r_node, mid + 1, right, L, R));
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int x, y;
	build(0, 0, n - 1);
	while (m--) {
		cin >> x >> y;
		x--, y--;
		cout << query(0, 0, n - 1, x, y) << ' ';
	}
	return 0;
}
