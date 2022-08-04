#include <iostream>
using namespace std;
int main() {
	int temp, t;
	for (int i = 1000; i <= 9999; i++) {
		t = i, temp = 0;
		while(t) {
			temp = temp * 10 + t % 10;
			t /= 10;
		}
		if (temp == i) cout << i << endl;
	}
	return 0;
}
