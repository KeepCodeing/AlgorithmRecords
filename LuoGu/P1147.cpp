#include <iostream>
using namespace std;
int main() {
	long n;
	cin >> n;
	// 自然数包括0 
	// 之前写的i < n / 2,没考虑完全，i可以等于n/2，如21，它的一种可能就是10,11, 
	for (int i = 0; i < n; i++) {
		long sn = i;
		// 这里同样 
		for (int k = i + 1; k < n; k++) {
			sn += k;
			if (sn > n) break;
			if (sn == n) {
				cout << i << ' ' << k << endl;
				break;
			}
		}
	}
	return 0;
}
