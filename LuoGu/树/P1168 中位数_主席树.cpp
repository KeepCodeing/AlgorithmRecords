#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// 一开始想的是保持区间元素有序，然后就想到了优先队列，但是实现上似乎不太现实，然后又想到了中位数不就是区间K小之类的么，
// 所以就想到了主席树... 
// 权当复习主席树，不过不知道为什么几天没打就又要思考下了w... 

const int N = 100000 + 10;
vector<int > vec;
int nums[N], root[N], cnt = 0;
struct Node {
	int l, r, sum;	
} T[N * 40];
int getid(int x) {
	return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
}
void update(int l, int r, int& x, int y, int pos) {
	T[++cnt] = T[y], T[cnt].sum++, x = cnt;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (pos <= mid) update(l, mid, T[x].l, T[y].l,  pos);
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
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &nums[i]), vec.push_back(nums[i]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end()); 
	for (int i = 1; i <= n; i++) update(1, n, root[i], root[i - 1], getid(nums[i]));
	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			// 要查询的区间应该是从1到i，那么把1看成x，i看成y，就有这个表达式了，后面第k小其实就是找中位数，也就是区间
			// 长度/2，这里第k小或者第k大应该都没区别... 
			printf("%d\n", vec[query(1, n, root[1 - 1], root[i], (1 + i) / 2) - 1]);
		}
	}
	return 0;
}
