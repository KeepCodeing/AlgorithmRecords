#include <iostream>
using namespace std;
int main() {
	int n, t;
	long cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		t = i;
		while(t) {
			if (t % 10 == 1) cnt++;
			t /= 10;
		}
	}
	cout << cnt;
	return 0;
}
