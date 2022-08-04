#include <iostream>
using namespace std;

// 还是太池沼，因为其只会用对比左侧元素的单调栈，而不会对比右侧元素的单调栈，所以花了很长时间改
// 模板，但是无果。后来终于想到可以把输入反过来，这样就可以套模板了，但是输出又出了问题，因为
// 输入倒过来的，所以输出也要倒过来，但是其只改了符合要求的输出，没改不符合要求的输出，结果一直
// 卡在多了一个0这里... 

const int N = 3 * 1000010;
typedef pair<int, int > PII;
PII nums[N], stk[N];
int res[N];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int tt = 0;
	int cnt = 0;
	for (int i = n; i >= 1; i--) {
		cin >> nums[i].first;
		nums[i].second = n - i + 1;
	}
	for (int i = 1; i <= n; i++) {
		while (tt && stk[tt].first <= nums[i].first) tt--;
		if (tt) res[++cnt] = stk[tt].second; 
		else res[++cnt] = 0;
		tt++;
		stk[tt].second = nums[i].second, stk[tt].first = nums[i].first;
		
	}
	for (int i = cnt; i >= 1; i--) {
		cout << res[i];
		if (i != 0) cout << ' ';
	}
	return 0;
}
