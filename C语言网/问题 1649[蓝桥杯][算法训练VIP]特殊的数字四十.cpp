#include <iostream>
using namespace std;
bool getNum(int x) {
	int res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res == 10;
}
int main() {
	for (int i = 1000; i <= 9999; i++) {
		if (getNum(i)) cout << i << endl;
	}
	return 0;
}
