#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int main() {
	int x0, y0, cnt = 0;
	cin >> x0 >> y0;
	int mn = x0 < y0 ? y0 : x0;
	for (int i = 1; i <= mn; i++) {
		if (x0 * y0 % i != 0) continue;
		if (gcd(x0 * y0 / i, i) == x0) cnt++;
	}
	cout << cnt;
	return 0;
}
