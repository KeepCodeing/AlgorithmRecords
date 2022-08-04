#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n > 10) {
		int tn = n, c = 1;
		while (tn) {
			if (tn % 10) c *= tn % 10;
			tn /= 10;
		}
		n = c;
	}
	cout << n;
	return 0;
}
