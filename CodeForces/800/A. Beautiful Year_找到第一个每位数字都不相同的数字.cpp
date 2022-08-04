#include <iostream>
using namespace std;

// 第20道水题，接下来是迫真复习...后面就做难一点的水题了w.. 

bool checker(int n) {
	int a, b, c, d;
	a = n / 1000, b = n / 100 % 10, c = n / 10 % 10, d = n % 10;
	return a != b && a != c && a != d && b != c && b != d && c != d;
}
int main() {
	int n;
	cin >> n;
	while (true) {
		// 严格大于 
		n += 1;
		if (checker(n)) {
			cout << n << endl;
			break;
		}
	}
	return 0;
}
