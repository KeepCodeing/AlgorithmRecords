#include <iostream>
#include <algorithm>
using namespace std;
// 辗转相除法可用来求最大公约数
int gcd(int m, int n) {
	if (m < n) swap(m, n);
	if (m % n == 0) return n;
	gcd(n, m % n);
} 
int main() {
	cout << gcd(114, 514);
	return 0;
}
