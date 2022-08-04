#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
int main() {
	unsigned long long n;
	cin >> n;
	n %= mod;
	cout << ((1 + n) * n / 2);
	return 0;
}
// 1000000000000000000
// 1000000007
