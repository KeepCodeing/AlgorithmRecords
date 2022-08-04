#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
int main() {
	int n, a1, a2;
	cin >> n >> a1 >> a2;
	int a3;
	for (int i = 3; i <= n; i++) {
		a3 = 3 * a2 % mod + 4 * a1 % mod;
		a1 = a2, a2 = a3;
	}
	cout << a3;
	return 0;
}
