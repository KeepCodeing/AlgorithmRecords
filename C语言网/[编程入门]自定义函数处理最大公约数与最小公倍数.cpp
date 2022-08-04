#include <iostream>
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	int a, b;
	cin >> a >> b;
	int res = gcd(a, b);
	cout << res << ' ' << (a * b) / res;
	return 0;
}
