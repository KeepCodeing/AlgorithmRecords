#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL nums[N], sum[N], add[N];
int L[N], R[N], pos[N];
void change(int l, int r, LL d) {
	int p = pos[l], q = pos[r];
	if (p == q) {
		for (int i = l; i <= r; i++) nums[i] += d;
		sum[p] += (r - l + 1) * d;
	} else {
		// 给p, q之间的每一块（也就是p, q作为单独的两块直接计算）打上增量标记 
		for (int i = p + 1; i <= q - 1; i++) add[i] += d;
		// 算出p, q的增加 
		for (int i = l; i <= R[p]; i++) nums[i] += d;
		sum[p] += (R[p] - l + 1) * d;
		for (int i = L[q]; i <= r; i++) nums[i] += d;
		sum[q] += (r - L[q] + 1) * d;
	}
}
LL ask(int l, int r) {
	int p = pos[l], q = pos[r];
	LL ans = 0;
	if (p == q) {
		for (int i = l; i <= r; i++) ans += nums[i];
		ans += add[p] * (r - l + 1);
	} else {
		// 直接算出p, q之间的若干块的和，这里p, q之前的若干块一定是完整包含一段序列的，所以直接用sum[i]算出这
		// 段序列的和，再加上这个范围内的增量 
		for (int i = p + 1; i <= q - 1; i++) ans += sum[i] + (R[i] - L[i] + 1) * add[i];
		// 算出p, q这两块的和，注意这里有个细节是没用sum，因为sum存的是一整块的和，而p, q可能只有部分求和 
		for (int i = l; i <= R[p]; i++) ans += nums[i];
		// 注意这里的区间范围，不是r - l + 1，而是R[p] - l + 1，下面同理，这是因为这里单独对p, q这两块进行处理，他们区间
		// 大小由这两块的左右端点决定 
		ans += add[p] * (R[p] - l + 1);
		for (int i = L[q]; i <= r; i++) ans += nums[i];
		ans += add[q] * (r - L[q] + 1);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, l, r, d;
	char op;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	// 注意这里有个强转，可能有的编译器的sqrt参数不接受int，不加可能CE... 
	int t = sqrt((float)n);
	for (int i = 1; i <= t; i++) {
		L[i] = (i - 1) * t + 1;
		R[i] = t * i;
	}
	// 注意这句话的位置，它必须放在初始化每块节点之后，这样才能保证分的块能把整个序列包含，另外注意L[t] = R[t - 1] + 1，
	// 这里的+1用来防止新加的这一块的左区间和之前那一块的右区间重合 
	if (R[t] < n) t++, L[t] = R[t - 1] + 1, R[t] = n;
	for (int i = 1; i <= t; i++) {
		for (int j = L[i]; j <= R[i]; j++) {
			pos[j] = i;
			sum[i] += nums[j];
		}
	}
	while (m--) {
		cin >> op >> l >> r;
		if (op == 'C') cin >> d, change(l ,r, d);
		else cout << ask(l, r) << endl;
	}
	return 0;
}
