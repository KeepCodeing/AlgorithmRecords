#include <iostream>
using namespace std; 
int main() {
	int temp, t, tt;
	for (int i = 100; i <= 999; i++) {
		temp = 0, t = i;
		while (t) {
			tt = t % 10;
			temp += tt * tt * tt;
			t /= 10;
		}
		if (temp == i) cout << i << endl;
	}
	return 0;
}
