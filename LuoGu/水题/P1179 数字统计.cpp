#include <iostream>
using namespace std;
int main() {
	int l, r;
	cin >> l >> r;
	int cnt = 0;
	int temp;
	for (int i = l; i <= r; i++) {
		temp = i;
		while (temp) {
			if (temp % 10 == 2) cnt++;
			temp /= 10;
		}
	}
	cout << cnt;
	return 0;
}
