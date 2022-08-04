#include <iostream>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n = 10;
	// 求质因数 
	for (int i = 2; i <= n / i; i++) {
		if (!(n % i)) {
			while (!(n % i)) {
				cout << i << ' ';
				n /= i;
			}
		}
	}
	if (n > 1) cout << n;
	n = 11;
	// 判断是否是质数
	for (int i = 2; i <= n / i; i++) {
		if (!(n % i)) {
			cout << "不是质数" << endl;
			return 0;
		}
	} 
	return 0;
}
