#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int x, y;
	cin >> x >> y;
	if (x > y) swap(x, y);
	for (int i = x; i <= y; i++) {
		
	}
	return 0;
}
