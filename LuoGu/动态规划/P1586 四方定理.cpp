#include <iostream>
using namespace std;

// 原来有物品个数限制也是二维费用背包（无能）
// 这里就是个完全背包计数，但是多加了一个限制，最多只能用4次，所以可以把使用次数当成是多的一维费用，
// 那么依次枚举物品个数，可以使用多少次，物品价值就行了... 

typedef long long LL;
const int N = 32768 + 10, M = 10;
LL f[N][M];
int main() {
	f[0][0] = 1;
	// 依次枚举物品个数，物品个数限制，物品价值 
	for (int i = 1; i * i <= N; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = i * i; k <= N; k++) {
				// 当前选数方案由上一次状态转移而来 
				f[k][j] += f[k - i * i][j - 1];
			}
		}
	}
	int T;
	cin >> T;
	int num, ans = 0;
	while (T--) {
		ans = 0;
		cin >> num;
		// 答案就是选[1,4]个数的方案之和 
		for (int i = 1; i <= 4; i++) ans += f[num][i];
		cout << ans << endl;
	}
	return 0;
}
// 快速幂：if (p & 1) s *= q^(1~p) 
//#include <iostream>
//using namespace std;
//int main() {
//	int b, p, k, s = 1;
//	int b1, p1;
//	cin >> b >> p >> k;
//	b1 = b, p1 = p;
//	while(p1) {
//		if (p1 & 1) s = s * 1ll * b1 % k;
//		b1 = b1 * 1ll * b1 % k;
//		p1 >>= 1;
//	}
//	cout << b << "^" << p << " mod " << k << '=' << s % k; 
//	return 0;
//}
