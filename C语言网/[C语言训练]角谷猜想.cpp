#include<iostream>
using namespace std;
int main() {
	int n, t;
	cin >> n;
	while (true) {
		if (!(n % 2)) cout << n << '/' << 2 << '=' << n / 2, n /= 2;
		else cout << n << '*' << 3 << "+1=" << n * 3 + 1, n = n * 3 + 1;
		cout << endl;
		if (n == 1) break;
	}
	return 0;
} 
