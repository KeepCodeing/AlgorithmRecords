#include <iostream>
using namespace std;

// 喜闻乐见的数论 
// 对于a^b来说，如果把b看成二进制形式，比如13，为1001，
// 于是3 号位 、2号位、0号位就都是1，那么就可以得到13 = 2^3 + 2^2 + 2^1 = 8 + 4 + 1。
// 所以a ^13 = a^8 * a^4 * a^1。 

int main() {
	int a, b, q;
	cin >> a >> b >> q;
	// 坑数据：a=1234 b = 0 q = 1 
	int res = 1 % q;
	while (b) {
		// 乘以a的倍数 
		// 注意是res先乘的1LL，否则先乘a会越界 
		if (b & 1) res = res * 1ll * a % q;
		// a倍增 
		a = a * 1ll * a % q; 
		// 往右推，相当于/2 
		b >>= 1;
	}
	cout << res;
	return 0;
} 
