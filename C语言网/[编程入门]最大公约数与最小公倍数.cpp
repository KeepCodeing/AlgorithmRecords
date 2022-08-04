#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	int a, b;
	cin >> a >> b;
	if (a < b) swap(a, b);
	int g = gcd(a, b);
	// 最小公倍数就是两个数的乘积/最大公约数.. 
	cout << g << ' ' << (a * b) / g;
	return 0;
}
