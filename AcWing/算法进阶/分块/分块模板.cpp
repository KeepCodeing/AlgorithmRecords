#include <iostream>
#include <cmath>
#define endl '\n' 
using namespace std;

// 分块：用来“暴力”的对序列进行操作，它可以完成线段树/树状数组的功能，使用简单通用，但效率低。
// 它的核心思想就是将整个序列分成sqrt(n)块，每块的左右边界（大小）根据公式确定。在进行操作前首先
// 预处理每一块内的数据，比如块内元素和，块内元素位置。
// 在这个题中，分块主要提供两个操作，1. 指定一段区间每个数加上d 2. 查询一段区间的和。因为我们处理
// 数据的单位是块，所以要分情况讨论，一般是当区间被一个块所包含时直接处理数据，当区间被包含在多个
// 块中时，针对这多个区间进行处理... 

typedef long long LL;
const int N = 1e5 + 10;
// 存序列元素/每一块内元素和/每一块的增量标记 
LL nums[N], sum[N], add[N];
// 存每一块左右端点，元素在那一块里 
int L[N], R[N], pos[N];
// 计算每一块的大小 
int t;

// 对当前区域的元素进行加数操作 
void change (int l, int r, LL d) {
	int p = pos[l], q = pos[r];
	// 如果当前操作在一个块内，那么就直接将这个区间里的元素进行修改；相反不在一个块内就进行分类讨论 
	if (p == q) {
		for (int i = l; i <= r; i++) nums[i] += d;
		// 将这个块的元素和进行改变，注意这里p == q，也就是不用考虑是左边那块的元素和还是右边那块的元素和 
		sum[p] += d * (r - l + 1);
	} else {
		// 首先注意区间是开区间（为了保证只当前这个块的），其次这里算增量标记的目的就是为了避免直接
		// 对这多个块包含的序列进行修改，而是在进行ask操作后才进行修改（类似懒标记），另外这种情况只
		// 用于多个块，单个块内直接修改就行 
		// 这里是算出[l, r]之类所有块的增量标记 
		for (int i = p + 1; i <= q - 1; i++) add[i] += d;
		// 将左边那个块包含的区域[l, R[p]]进行修改（因为是多个块进行相交所以要分开算） 
		for (int i = l; i <= R[p]; i++) nums[i] += d;
		// 算左边块的总和 
		sum[p] += d * (R[p] - l + 1);
		// 同上，对右边那个块进行修改，算右边那个块的总和 
		for (int i = L[q]; i <= r; i++) nums[i] += d;
		sum[q] += d * (r - L[q] + 1);
	}
}

LL ask(int l, int r) {
	int p = pos[l], q = pos[r];
	LL ans = 0;
	if (p == q) {
		// 在一个块内直接算序列总和 
		for (int i = l; i <= r; i++) ans += nums[i];
		// 这里算的是当前块外的和，也就是这个块和别的块的交集区域的和 
		ans += add[p] * (r - l + 1);
	} else {
		// 依然是先算出当前这个块的和，这里的p, q可能包含了多个块，所以块内和/增量和区域大小都可能有多个
		// 算出[l, r]区间内所有块的和与增量和 
		for (int i = p + 1; i <= q - 1; i++) ans += sum[i] + add[i] * (R[i] - L[i] + 1);
		// 下面两个操作同上，不过注意这里变成了增加增量标记（收回懒标记） 
		for (int i = l; i <= R[p]; i++) ans += nums[i];
		ans += add[p] * (R[p] - l + 1);
		for (int i = L[q]; i <= r; i++) ans += nums[i];
		ans += add[q] * (r - L[q] + 1);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, q, l, r, d;
	char op;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	// 算出一共有多少块 
	t = sqrt(n);
	// 算出每一块左右端点的位置 
	for (int i = 1; i <= t; i++) {
		L[i] = (i - 1) * t + 1;
		R[i] = i * t;
	}
	// 如果不能完全包含整个序列，再加一块 
	if (R[t] < n) t++, L[t] = R[t - 1] + 1, R[t] = n;
	// 将每一块内包含的元素进行预处理，填充它们在那一个块内，计算这一块内元素之和 
	for (int i = 1; i <= t; i++) {
		for (int j = L[i]; j <= R[i]; j++) {
			pos[j] = i;
			sum[i] += nums[j];
		}
	}
	while (q--) {
		cin >> op >> l >> r;
		if (op == 'C') cin >> d, change(l, r, d);
		else cout << ask(l, r) << endl;
	}
	return 0;
}
/*
http://poj.org/problem?id=3468

10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4

4
55
9
15
*/
