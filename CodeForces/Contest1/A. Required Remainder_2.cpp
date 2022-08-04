#include <iostream>
using namespace std;
typedef unsigned long long ULL;
int main() {
	int T, y, n, x;
	cin >> T;
	while (T--) {
		cin >> x >> y >> n;
		for (int i = n / x; i >= 0; i--) {
			ULL k = x * i + y;
			if (k <= n) {
				cout << k << endl;
				break;
			}
		}
	}
	return 0;
}
