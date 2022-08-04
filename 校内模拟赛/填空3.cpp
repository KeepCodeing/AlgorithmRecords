#include <iostream>
using namespace std;
bool check(int x) {
	while (x) {
		if (x % 10 == 9) return true;
		x /= 10;
	}
	return false;
}
int main() {
	int cnt = 0;
	for (int i = 1; i <= 2019; i++) {
		if (check(i)) cout << i << endl, cnt++;
	}
	cout << cnt;
	return 0;
}
