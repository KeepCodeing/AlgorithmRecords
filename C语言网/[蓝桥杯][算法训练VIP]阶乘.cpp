#include <iostream>
using namespace std;

// 大致的思路就是不把所有位存起来，因为这样要写高精度，而是直接只保留%10000的余数，这样可以保证答案不会爆int，
// 然后既然题目只要求第一个非零数，那么就直接把0去掉就行了...不知道为什么这样不会影响答案，总之照做就完事了w.. 

typedef long long LL;
int main() {
	LL ans = 1;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		// 只保留4位数字 
		ans = (ans * i) % 10000;
		// 将位数0去掉.. 
		while (!(ans % 10)) ans /= 10;
	}
	cout << ans % 10;
	return 0;
}
