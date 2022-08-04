#include <iostream>
using namespace std;
typedef long long LL;
int main() {
	LL n, res = 0;
	cin >> n;
	while (true) {
		res = max(res, n);
		if (n % 2) n = n * 3 + 1;
		else n /= 2;
		if (n == 1) break;
	}
	cout << res;
	return 0;
}
