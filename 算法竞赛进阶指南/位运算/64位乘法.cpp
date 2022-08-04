#include <iostream>
using namespace std;

// 和快速幂差不多，给两个整数，0<=a,b<=10^16，如果用高精度实现就比较麻烦，这题
// 同样可以用快速幂的思想做

typedef unsigned long long ULL; 

int main() {
	// 坑爹的数据类型 
	ULL a, b, q;
	cin >> a >> b >> q;
	ULL res = 0;
	while (b) {
		if (b & 1) res = (res + a) % q;
		b >>= 1;
		// a+a就等于a*2，和快速幂基本差不多，就是把乘改为了加 
		a = a * 2 % q; 
	}
	cout << res;
	return 0;
} 
