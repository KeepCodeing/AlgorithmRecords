#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2* 1e5 + 10;
int nums[N], root[N];
int cnt = 0;
struct Node {
	int l, r, sum;
} T[N * 40];
vector<int > vec;
int getid(int x) {
	return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
}
void update(int l, int r, int &x, int y, int pos) {
	// 错误一：这里应该写成T[cnt].sum++;，另外没有设置递归终止的条件... 
	T[++cnt] = T[y], T[x].sum++, x = cnt;
	int mid = (l + r) >> 1;
	// 这里和普通线段树几乎一致，先x，再y，先左，再右... 
	if (pos <= mid) update(l, mid, T[x].l, T[y].l, pos);
	else update(mid + 1, r, T[x].r, T[y].r, pos);
}
int query(int l, int r, int x, int y, int k) {
	int mid = (l + r) >> 1;
	// 错误二：这里应该写成T[T[y].l].sum - T[T[x].l].sum，这是通过左子树的节点上的元素个数和来判断该往那边走，
	// 而不是两个子树都拿来判断...另外这里也忘了递归终止条件w.. 
	int sum = T[T[x].l].sum - T[T[y].r].sum;
	if (sum <= mid) return query(l, mid, T[x].l, T[y].r, k);
	else return query(mid + 1, r, T[x].r, T[y].r, k - sum);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]), vec.push_back(nums[i]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 1; i <= n; i++) update(1, n, root[i], root[i - 1], getid(nums[i]));
	return 0;
}
