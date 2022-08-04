#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	// __gcd(a, b);
	cout << gcd(10, 85);
	return 0;
}
