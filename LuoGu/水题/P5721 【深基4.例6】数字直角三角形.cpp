#include <iostream>
using namespace std;

// 水题第五弹，只有水题了你看可以吗 

int main() {
	int n, cnt = 1;
	cin >> n;
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			if (cnt < 10) cout << 0;
			cout << cnt++;
		}
		cout << endl;
	}
	return 0;
}
