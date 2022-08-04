#include <iostream>
using namespace std;
int main() {
	int b, p, k, s = 1;
	int b1, p1;
	cin >> b >> p >> k;
	b1 = b, p1 = p;
	while(p1) {
		// 注意*1ll的顺序，不对就会溢出导致答案错误 
		if (p1 & 1) s = s * 1ll * b1 % k;
		b1 = b1 * 1ll * b1 % k;
		p1 >>= 1;
	}
	// 特判当p等于0的情况，还以为洛谷没有这个数据.. 
	cout << b << "^" << p << " mod " << k << '=' << s % k; 
	return 0;
}
