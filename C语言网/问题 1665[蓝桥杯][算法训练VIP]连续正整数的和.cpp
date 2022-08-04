#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			float t = (i + j) * (j - i + 1) / 2;
			if (t > n) break;
			if ((int)t == t && t == n) {
				cout << i << ' ' << j << endl;
				break;
			}
		}
	}
	return 0;
}
