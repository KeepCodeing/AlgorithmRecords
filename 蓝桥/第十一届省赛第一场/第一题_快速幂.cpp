#include <iostream>
using namespace std;
int ksm(int p, int q, int md) {
	int res = 1;
	while (q) {
		if (q & 1) res = res * p % md;
		q >>= 1;
		p = p * 1ll * p % md;
	}
	return res;
}
int main() {
	int p, q, md;
	cin >> p >> q >> md;
	cout << ksm(p, q, md);
	return 0;
}
