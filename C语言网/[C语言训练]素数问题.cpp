#include <iostream>
using namespace std;
int ksm(int p, int q) {
	int res = 1;
	while (q) {
		if (q & 1) res = res *1ll * p;
		q >>= 1;
		p = p * 1ll * p;
	}
	return res;
}
int main() {
	int n;
	while (cin >> n) {
		cout << ksm(n,2) << endl;
	}
	cin >> n;
	for (int i = 2; i <= n / i; i++) {
		if (!(n % i)) {
			cout << 0;
			return 0;	
		}
	}
	cout << 1;
	return 0;
}
