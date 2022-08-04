#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	float t;
	for (int i = 1; i <= 10000000; i++) {
		t = i;
		for (int j = 1; j < n; j++) {
			t -= t / 2.0 + 1;
			// cout << t << ' ';
		}
		if (t == 1) {
			cout << i;
			break;
		}
		// cout << endl;
	}
	return 0;
}
