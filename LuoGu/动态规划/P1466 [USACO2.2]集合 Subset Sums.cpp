#include <iostream>
using namespace std;

// 昨天没看出来，这其实就是个裸的01背包求方案数 
// 把集合元素看成是元素个数，那么要凑的数就是所有元素之和，
// 套模板就行，但是要注意开long long，似乎很多求方案数的题目
// 最终结果都会很大，所以开long long没有坏处 

const int N = 2000;
long long f[N];
int main() {
	int n;
	cin >> n;
	int t = (n * (n + 1) / 2);
	// 只有集合可以被分为两半的情况才能有和，所以这里可以加个剪枝 
	if (t % 2) {
		cout << 0;
		return 0;
	}
	t >>= 1;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = t; j >= i; j--) {
			f[j] += f[j - i];
		}
	}
	cout << (f[t] >> 1);
	return 0;
}
