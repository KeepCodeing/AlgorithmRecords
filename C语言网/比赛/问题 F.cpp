#include <iostream>
using namespace std;
bool check(int n) {
	while (n) {
		int t = n % 10;
		if (t == 1 || t == 0 || t == 2 || t == 9) return true;
		n /= 10;
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (check(i)) res += i;
	}
	cout << res;
	return 0;
}
