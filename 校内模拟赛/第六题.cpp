#include <iostream>
using namespace std;
bool check(int x) {
	int pre = x % 10;
	x /= 10;
	while (x) {
		if (x % 10 > pre) return false;
		pre = x % 10;
		x /= 10;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (check(i)) cnt++;
	}
	cout << cnt;
	return 0;
}
