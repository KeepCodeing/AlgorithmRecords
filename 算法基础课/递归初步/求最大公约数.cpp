#include <iostream>
using namespace std;
// 辗转相除法：m % n == 0，说明n就是最大公约数，m % n == k,说明还没有得到最大公约数
// 继续用n % k，直到最后得到0为止 
int gcd(int m, int n) {
	return m % n ? gcd(n, m % n) : n;
}
// 扩展：最小公倍数，为m*n/最大公约数
int lcm(int m, int n, int d) {
	return m * n / d;
} 
int main() {
	cout << gcd(60, 25) << endl;
	cout << lcm(60, 25, gcd(60, 25));
	return 0;
}
