#include <iostream>
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	int n, m;
	cin >> n >> m;
	cout << (n * m) / gcd(n, m);
	return 0;
}
