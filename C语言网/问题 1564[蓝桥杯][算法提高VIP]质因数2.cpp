#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 2; i <= n / i; i++) {
		while (!(n % i)) {
			cout << i << ' ';
			n /= i;
			cnt++;
		}
	}
	if (n > 1) cout << n, cnt++;
	cout << endl << cnt;
	return 0;
} 
