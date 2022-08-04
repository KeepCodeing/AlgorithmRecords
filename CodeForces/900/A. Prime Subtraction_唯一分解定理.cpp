#include <iostream>
using namespace std;

// 数论的定理：任意一个大于1的数要么其自身是个素数，要么其可以被表示为若干个素数的乘积...故而这个题判断下差是否小于等于一就完事了... 

typedef long long LL;
int main() {
	int T;
	LL x, y;
	cin >> T;
	while (T--) {
		cin >> x >> y;
		if (x - y <= 1) cout << "NO";
		else cout << "YES";
		cout << endl;
	}
	return 0;
}
