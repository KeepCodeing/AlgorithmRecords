#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	cout << n << '=';
	bool flag = true;
	for (int i = 2; i <= n / i; i++) {
		while (!(n % i)) {
			if (flag) cout << i, flag = !flag;
			else cout << '*' << i;
			n /= i;
		}
	}
	if (n > 1) {
		if (!flag) cout << '*';
		cout << n;
	}
	return 0;
}
