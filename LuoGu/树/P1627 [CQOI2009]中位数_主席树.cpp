#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

// 双倍经验... 
// 然而发现并不是..这个题是所有连续子序列都可以，上个题是从1开始的序列.. 

const int N = 1e5 + 10;
int nums[N], root[N], cnt = 0;
struct Node {
	int l, r, sum;
} T[N * 40];
vector<int > vec;
int getid(int x) {
	return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
}
void update(int l, int r, int& x, int y, int pos) {
	T[++cnt] = T[y], T[cnt].sum++, x = cnt;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (pos <= mid) update(l, mid, T[x].l, T[y].l, pos);
	else update(mid + 1, r, T[x].r, T[y].r, pos);
}
int query(int l, int r, int x, int y, int k) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	int sum = T[T[y].l].sum - T[T[x].l].sum;
	if (k <= sum) return query(l, mid, T[x].l, T[y].l, k);
	else return query(mid + 1, r, T[x].r, T[y].r, k - sum);
}
int main() {
	int n, m, res = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]), vec.push_back(nums[i]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end()); 
	for (int i = 0; i < vec.size(); i++) cout << vec[i] << ' ';
	cout << endl;
	for (int i = 1; i <= n; i++) update(1, n, root[i], root[i - 1], getid(nums[i]));
	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			cout << vec[query(1, n, root[0], root[i], (1 + i) / 2) - 1] << endl;
//			if (vec[query(1, n, root[0], root[i], (1 + i) / 2) - 1] == m) cout << res++;
		}
	}
	return 0;
}
